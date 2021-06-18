//
// Created by ybc on 2021/5/27.
//

#include "CodeGenVisitor.h"


antlrcpp::Any CodeGenVisitor::visitCompilationUnit(CParser::CompilationUnitContext *ctx) {
    _data << ".data\n";
    _code << ".text\n"
          << ".globl main\n";
    visitChildren(ctx);
    return _data.str() + _code.str();
}

antlrcpp::Any CodeGenVisitor::visitGlobalDeclaration(CParser::GlobalDeclarationContext *ctx) {
    auto initDeclarators = ctx->declaration()->initDeclaratorList()->initDeclarator();
    if (!initDeclarators.empty()) {
        for (auto initDeclarator : initDeclarators) {
            auto id = initDeclarator->declarator()->directDeclarator()->identifier();
            auto name = id->getText();
            // must be constant
            auto initValue = 0;
            auto entry = SymTab::getInstance().get(name);
            auto initCtx = entry.initValue;
            if (entry.type.getTypeTree()->getNodeType() == BaseType::Array) {
                globalArray(name, entry.type.getSize());
            } else {
                if (initCtx != nullptr) {
                    initValue = atoi(initCtx->getText().c_str());
                    globalVar(name, initValue);
                } else {
                    globalVar(name);
                }
            }
        }
    }
    return ExpType();
}

antlrcpp::Any CodeGenVisitor::visitFunctionDefinition(CParser::FunctionDefinitionContext *ctx) {
    curFunc = ctx->declarator()->directDeclarator()->identifier()->getText();
    // prologue: allocate an frame
    label(curFunc);
    pushReg("ra");
    pushReg("s8");
    mov("s8", "sp");

    // TODO: Calling convection: a0-a3, more on stack
    // now: all paramNames are on stack
    auto paramNames = SymTab::getInstance().getParamNames(curFunc);
    size_t argOffset = 1;
    for (auto &paramName : paramNames) {
        auto entry = SymTab::getInstance().get(paramName);
        auto size = entry.type.getTypeTree()->getSize();
        argOffset++;
        auto paramOffset = -(int) entry.offset;
        // arg -> param
        comment("param " + paramName + "(" + to_string(entry.line) + "," + to_string(entry.column) + ")" +
                ": fp+(" + to_string(WORD_BYTES * argOffset) +
                ") to fp+(" + to_string(paramOffset) + ")");
        memType("lw", "t0", "s8", WORD_BYTES * (int) argOffset);
        memType(storeOp(size), "t0", "s8", paramOffset);
    }

    // allocate local vars on stack
    size_t offsets = SymTab::getInstance().getTotalOffset(curFunc);
    comment("offset:" + to_string(offsets));
    iType("addiu", "sp", "s8", -(int) offsets);

    pushReg("s0");
    // TODO: dynamic decide saved registers
    visit(ctx->compoundStatement());

    // main default: return 0
    if (curFunc == "main") {
        mov("v0", "0");
        popReg("s0");
        mov("sp", "s8");
        popReg("s8");
        popReg("ra");
        ret();
    }
    blockOrderStack.clear();
    blockOrder = 0;
    curFunc = "";
    return ExpType();
}

antlrcpp::Any CodeGenVisitor::visitCompoundStatement(CParser::CompoundStatementContext *ctx) {
    comment("block " + to_string(blockOrder) + " begin:");
    blockOrderStack.push_back(blockOrder);
    blockOrder = 0;
    for (auto item : ctx->blockItem()) {
        visit(item);
    }
    blockOrder = blockOrderStack.back() + 1;
    blockOrderStack.pop_back();
    comment("block " + to_string(blockOrder - 1) + " end");
    return ExpType();
}

antlrcpp::Any CodeGenVisitor::visitReturnStmt(CParser::ReturnStmtContext *ctx) {
    // epilogue
    _code << "\t#return\n";
    auto expType = visit(ctx->expression()).as<ExpType>();
    if (expType.type == ExpType::Type::LEFT) {
        load(expType.size);
    }
    popReg("v0");

    // restore saved registers
    // TODO: dynamic decide saved registers
    popReg("s0");

    // epilogue: deallocate an frame
    size_t offsets = SymTab::getInstance().getTotalOffset(curFunc);
    comment("deallocate:" + to_string(offsets));

    mov("sp", "s8");
    popReg("s8");
    popReg("ra");
    ret();
    return ExpType();
}

antlrcpp::Any CodeGenVisitor::visitIfStmt(CParser::IfStmtContext *ctx) {
    auto expType = visit(ctx->expression()).as<ExpType>();
    if (expType.type == ExpType::Type::LEFT) {
        load(expType.size);
    }
    // TODO: branched return statement can be optimized
    if (ctx->Else()) {
        size_t elseBranch = labelCount++;
        size_t endBranch = labelCount++;
        beqz("else_" + to_string(elseBranch));
        visit(ctx->statement(0));
        j("end_" + to_string(endBranch));
        label("else_" + to_string(elseBranch));
        visit(ctx->statement(1));
        label("end_" + to_string(endBranch));
    } else {
        size_t endBranch = labelCount++;
        beqz("end_" + to_string(endBranch));
        visit(ctx->statement(0));
        label("end_" + to_string(endBranch));
    }
    return ExpType();
}

antlrcpp::Any CodeGenVisitor::visitWhileLoop(CParser::WhileLoopContext *ctx) {
    blockOrderStack.push_back(blockOrder);
    blockOrder = 0;
    comment("while loop begin:");
    auto loopBegin = "loop_" + to_string(labelCount++);
    auto breakPoint = "break_" + to_string(labelCount++);
    auto continuePoint = "continue_" + to_string(labelCount++);
    breakStack.push_back(breakPoint);
    continueStack.push_back(continuePoint);
    label(loopBegin);
    comment("cond:");
    auto expType = visit(ctx->expression()).as<ExpType>();
    if (expType.type == ExpType::Type::LEFT) {
        load(expType.size);
    }
    beqz(breakPoint);
    comment("body:");
    visit(ctx->statement());
    label(continuePoint);
    j(loopBegin);
    label(breakPoint);
    comment("while loop end");
    blockOrder = blockOrderStack.back() + 1;
    blockOrderStack.pop_back();
    return ExpType();
}

antlrcpp::Any CodeGenVisitor::visitDoWhile(CParser::DoWhileContext *ctx) {
    blockOrderStack.push_back(blockOrder);
    blockOrder = 0;
    comment("do while loop begin:");
    auto breakPoint = "break_" + to_string(labelCount++);
    auto continuePoint = "continue_" + to_string(labelCount++);
    auto loopBegin = "loop_" + to_string(labelCount++);
    breakStack.push_back(breakPoint);
    continueStack.push_back(continuePoint);
    label(loopBegin);
    // body
    visit(ctx->statement());
    // cond
    auto expType = visit(ctx->expression()).as<ExpType>();
    if (expType.type == ExpType::Type::LEFT) {
        load(expType.size);
    }
    beqz(breakPoint);
    label(continuePoint);
    j(loopBegin);
    label(breakPoint);
    breakStack.pop_back();
    continueStack.pop_back();
    comment("do while loop end");
    blockOrder = blockOrderStack.back() + 1;
    blockOrderStack.pop_back();
    return ExpType();
}

antlrcpp::Any CodeGenVisitor::visitForLoop(CParser::ForLoopContext *ctx) {
    blockOrderStack.push_back(blockOrder);
    blockOrder = 0;
    comment("for loop begin:");
    auto breakPoint = "break_" + to_string(labelCount++);
    auto continuePoint = "continue_" + to_string(labelCount++);
    auto loopBegin = "loop_" + to_string(labelCount++);
    breakStack.push_back(breakPoint);
    continueStack.push_back(continuePoint);
    if (auto exp = ctx->forCondition()->forInit()->expression()) {
        visit(exp);
        comment("unused expr value at the top of stack, destroy it");
        pop();
    } else if (auto dec = ctx->forCondition()->forInit()->declaration()) {
        visit(dec);
    }
    label(loopBegin);
    // cond
    if (auto cond = ctx->forCondition()->forCondExpression()) {
        auto expType = visit(cond->expression()).as<ExpType>();
        if (expType.type == ExpType::Type::LEFT) {
            load(expType.size);
        }
        beqz(breakPoint);
    }
    // body
    visit(ctx->statement());
    label(continuePoint);
    if (auto final = ctx->forCondition()->forFinalExpression()) {
        visit(final);
        comment("unused expr value at the top of stack, destroy it");
        pop();
    }
    j(loopBegin);
    label(breakPoint);
    breakStack.pop_back();
    continueStack.pop_back();
    comment("for loop end");
    blockOrder = blockOrderStack.back() + 1;
    blockOrderStack.pop_back();
    return ExpType();
}

antlrcpp::Any CodeGenVisitor::visitContinueStmt(CParser::ContinueStmtContext *ctx) {
    if (continueStack.empty()) {
        throw InvalidContinue();
    } else
        j(continueStack.back());
    return ExpType();
}

antlrcpp::Any CodeGenVisitor::visitBreakStmt(CParser::BreakStmtContext *ctx) {
    if (continueStack.empty()) {
        throw InvalidBreak();
    } else
        j(breakStack.back());
    return ExpType();
}

antlrcpp::Any CodeGenVisitor::visitIntConst(CParser::IntConstContext *ctx) {
    comment("constant");
    li("v0", atoi(ctx->IntegerConstant()->getText().c_str()));
    pushReg("v0");
    return ExpType(ExpType::Type::RIGHT, 4);
}

antlrcpp::Any CodeGenVisitor::visitCharConst(CParser::CharConstContext *ctx) {
    comment("constant");
    string rawChar = ctx->CharacterConstant()->getText(); // getText(): 'c' -- [0] = '\''
    string unescapeChar = unescape(rawChar.substr(1, rawChar.size() - 2));
    if (unescapeChar.size() != 1)
        throw InvalidCharSequence(rawChar);
    li("v0", (int) unescapeChar[0]);
    pushReg("v0");
    return ExpType(ExpType::Type::RIGHT, 1);
}

antlrcpp::Any CodeGenVisitor::visitIdentifier(CParser::IdentifierContext *ctx) {
    auto symbol = getCompoundContext() + ctx->getText();
    auto entry = SymTab::getInstance().get(symbol, ctx->getStart()->getLine(),
                                           ctx->getStart()->getCharPositionInLine());
    if (entry.name.find_last_of('@') == string::npos) {// globalVar var
        comment("push symbol addr: " + symbol + "(" + to_string(entry.line) + ", " + to_string(entry.column) + ")");
        la("t0", entry.name);
        pushReg("t0");
    } else {
        comment("push symbol addr: " + symbol + "(" + to_string(entry.line) + ", " + to_string(entry.column) + ")");
        pushFrameAddr(entry.offset);
    }
    if (entry.type.getTypeTree()->getNodeType() == BaseType::Array)
        return ExpType(ExpType::Type::ARR, 4);
    else
        return ExpType(ExpType::Type::LEFT, entry.type.getSize());
}

antlrcpp::Any CodeGenVisitor::visitPostfixExpression(CParser::PostfixExpressionContext *ctx) {
    auto argExpList = ctx->argumentExpressionList();
    if (!ctx->LeftBracket().empty()) {  // array
        comment("index operator []:");
        auto exps = ctx->expression();
        auto id = ctx->primaryExpression()->identifier();
        auto arrayEntry = SymTab::getInstance().get(getCompoundContext() + id->getText());
        auto resultType = arrayEntry.type.getTypeTree();
        visit(id);
        if (resultType->getNodeType() == BaseType::Pointer) {
            comment("use symbol " + id->getText() +
                    "(" + to_string(arrayEntry.line) + ", " + to_string(arrayEntry.column) + ")" +
                    " as array, load pointer first");
            load(WORD_BYTES);
        }
        for (auto exp : exps) {
            auto expType = visit(exp).as<ExpType>();
            if (expType.type == ExpType::Type::LEFT) { // index
                load(expType.size);
            }
            if (resultType->getNodeType() == BaseType::Array || resultType->getNodeType() == BaseType::Pointer) {
                resultType = resultType->getChild();
            } else {// to many brackets
                assert(false);
            }
            popReg("t3");                               // array index
            comment("push array size: " + to_string(resultType->getSize()));
            li("t2", (int) resultType->getSize());      // size
            rType2("mult", "t2", "t3");           // index * size
            rType1("mflo", "t2");
            popReg("t3");                               // base address
            rType3("add", "t2", "t3", "t2");   // base address + index * size ( base[index] )
            pushReg("t2");                              // address of base[index]
        }
        if (resultType->getNodeType() != BaseType::Array) // it's left value only when it gets the base type of array
            return ExpType(ExpType::Type::LEFT, resultType->getSize());
        else
            return ExpType(ExpType::Type::RIGHT, 4);
    } else if (!ctx->LeftParen().empty()) {
        if (auto id = ctx->primaryExpression()->identifier()) {
            auto funcName = id->getText();
            if (isBuildIn(funcName)) {
                size_t offsets = 0;
                if (!argExpList.empty()) {
                    auto exps = argExpList[0]->assignmentExpression();
                    for (int i = (int) exps.size() - 1; i >= 0; --i) {
                        auto expType = visit(exps[i]).as<ExpType>();
                        if (expType.type == ExpType::Type::LEFT) {
                            load(expType.size);
                        }
                        offsets++;
                    }
                }
                callBuiltIn(funcName, offsets);
                pushReg("0"); // return 0
                return ExpType(ExpType::Type::RIGHT, WORD_BYTES);
            } else {
                auto funcEntry = SymTab::getInstance().get(funcName);
                size_t offsets = 0;
                if (!argExpList.empty()) {
                    auto exps = argExpList[0]->assignmentExpression();
                    for (int i = (int) exps.size() - 1; i >= 0; --i) {
                        auto expType = visit(exps[i]).as<ExpType>();
                        if (expType.type == ExpType::Type::LEFT) {
                            load(expType.size);
                        }
                        // TODO: Calling convection: a0-a3, more on stack
                        offsets++;
                    }
                }
                call(funcName, offsets);
                pushReg("v0"); // return value
                if (funcEntry.type.getTypeTree()->getNodeType() == BaseType::Pointer)
                    return ExpType(ExpType::Type::LEFT, WORD_BYTES);
                else
                    return ExpType(ExpType::Type::RIGHT, dynamic_pointer_cast<FunctionTypeNode>(
                            funcEntry.type.getTypeTree())->getChild()->getSize());
            }
        } else
            throw InvalidFuncCall();
    } else { // neither func call nor array
        return visit(ctx->primaryExpression());
    }
    return ExpType();
}

antlrcpp::Any CodeGenVisitor::visitPrimaryExpression(CParser::PrimaryExpressionContext *ctx) {
    if (auto id = ctx->identifier()) {
        return visit(id);
    } else if (auto c = ctx->constant()) {
        return visit(c);
    } else if (auto exp = ctx->expression()) {
        return visit(exp);
//    } else if(auto s = ctx->StringLiteral())   {
    }
    return ExpType();
}

antlrcpp::Any CodeGenVisitor::visitAssignmentExpression(CParser::AssignmentExpressionContext *ctx) {
    if (auto condExp = ctx->conditionalExpression()) {
        return visit(condExp);
    } else {
        comment("assignment exp:");
        ExpType rType = visit(ctx->assignmentExpression()).as<ExpType>();
        if (rType.type == ExpType::Type::LEFT) {
            load(rType.size);
        }
        ExpType lType = visit(ctx->unaryExpression()).as<ExpType>();
        assert(lType.type == ExpType::Type::LEFT);
        if (ctx->assignmentOperator()->Assign()) {
            store(lType.size);
        } else
            throw NotImplement(ctx->assignmentOperator()->getText());
        return ExpType(ExpType::Type::RIGHT, lType.size);
    }
    return ExpType();
}

antlrcpp::Any CodeGenVisitor::visitInitDeclarator(CParser::InitDeclaratorContext *ctx) {
    auto id = ctx->declarator()->directDeclarator()->identifier();
    comment("define: " + id->getText());
    if (auto init = ctx->initializer()) {
        comment("initialize symbol: " + id->getText());
        auto expType = visit(init).as<ExpType>();
        if (expType.type == ExpType::Type::LEFT) {
            load(expType.size);
        }
        expType = visit(id).as<ExpType>();
        if (expType.type == ExpType::Type::LEFT) {
            store(expType.size);
            pop();
        } else {
            throw InvalidLvalue(ctx->declarator()->getText());
        }
        comment("end of initialization: " + id->getText());
    }
    return ExpType();
}

antlrcpp::Any CodeGenVisitor::visitConditionalExpression(CParser::ConditionalExpressionContext *ctx) {
    if (ctx->Question()) {
        auto expType = visit(ctx->logicalOrExpression()).as<ExpType>();
        if (expType.type == ExpType::Type::LEFT) {
            load(expType.size);
        }
        size_t elseBranch = labelCount++;
        size_t endBranch = labelCount++;
        beqz("else_" + to_string(elseBranch));
        expType = visit(ctx->expression()).as<ExpType>();
        if (expType.type == ExpType::Type::LEFT) {
            load(expType.size);
        }
        j("end_" + to_string(endBranch));
        label("else_" + to_string(elseBranch));
        expType = visit(ctx->conditionalExpression()).as<ExpType>();
        if (expType.type == ExpType::Type::LEFT) {
            load(expType.size);
        }
        label("end_" + to_string(endBranch));
        return ExpType(ExpType::Type::RIGHT);
    } else
        return visit(ctx->logicalOrExpression());
}

antlrcpp::Any CodeGenVisitor::visitUnaryExpression(CParser::UnaryExpressionContext *ctx) {
    if (auto postExp = ctx->postfixExpression()) {
        return visit(postExp);
    } else {
        if (auto op = ctx->unaryOperator()) {
            comment("unary exp");
            ExpType expType = visit(ctx->unaryExpression()).as<ExpType>();
            if (op->And()) {     // &x
                return ExpType(ExpType::Type::RIGHT);
            }
            popReg("t0");

            if (expType.type == ExpType::Type::LEFT) {
                memType(loadOp(expType.size), "t0", "t0", 0);
            }

            if (op->Minus()) {      // -x
                rType3("sub", "v0", "0", "t0");
                pushReg("v0");
                return ExpType(ExpType::Type::RIGHT);
            } else if (op->Not()) { // !x, 0->1, non-0 ->0
                iType("sltiu", "v0", "t0", 1);
                pushReg("v0");
                return ExpType(ExpType::Type::RIGHT);
            } else if (op->Tilde()) {// ~x, bit-wise not x
                rType3("nor", "v0", "t0", "0");
                rType2("not", "v0", "t0");
                pushReg("v0");
                return ExpType(ExpType::Type::RIGHT);
            } else if (op->Plus()) {    // +x,  x
                // TODO: int promotion
                pushReg("t0");
                return ExpType(ExpType::Type::RIGHT);
            } else if (op->Star()) {    // *x
                pushReg("t0");
                return ExpType(ExpType::Type::LEFT, expType.size);
            }
        } else
            return visit(ctx->unaryExpression());
    }
    return ExpType();
}

template<class T1, typename T2>
antlrcpp::Any CodeGenVisitor::genBinaryExpression(vector<T1 *> exps, vector<T2 *> ops) {
    auto exp0Type = visit(exps[0]).template as<ExpType>();
    if (!ops.empty()) {
        comment("binary expression:");
        if (exp0Type.type == ExpType::Type::LEFT) {
            load(exp0Type.size);
        }
        popReg("t0");
        pushReg("s0");// save $s0, and use it as accumulator in the following binary expressions
        mov("s0", "t0");
        for (int i = 0; i < ops.size(); i++) {
            auto expType = visit(exps[i + 1]).template as<ExpType>();
            if (expType.type == ExpType::Type::LEFT) {
                load(expType.size);
            }
            popReg("t0");
            genBinaryExpressionAsm(
                    dynamic_cast<tree::TerminalNode *>(ops[i]->children.front())->getSymbol()->getType());
        }
        mov("v0", "s0");
        popReg("s0");
        pushReg("v0");
        return ExpType(ExpType::Type::RIGHT);
    }
    return exp0Type;
}

antlrcpp::Any CodeGenVisitor::visitAdditiveExpression(CParser::AdditiveExpressionContext *ctx) {
    auto exps = ctx->multiplicativeExpression();
    auto ops = ctx->additiveOperator();
    auto exp0Type = visit(exps[0]).as<ExpType>();
    if (!ops.empty()) {
        comment("binary expression:");
        auto lType = SymTab::getInstance().getTypeFromQueue();
        if (exp0Type.type == ExpType::Type::LEFT) {
            load(exp0Type.size);
        }
        popReg("t0");
        pushReg("s0");// save $s0, and use it as accumulator in the following binary expressions
        mov("s0", "t0");
        for (int i = 0; i < ops.size(); i++) {
            auto rType = SymTab::getInstance().getTypeFromQueue();
            auto expType = visit(exps[i + 1]).as<ExpType>();
            if (expType.type == ExpType::Type::LEFT) {
                load(expType.size);
            }
            popReg("t0");
            bool ptrSub = false;
            if ((lType->getNodeType() == BaseType::Pointer || lType->getNodeType() == BaseType::Array) &&
                rType->getNodeType() == BaseType::SInt) { // ptr + int
                comment("ptr + int");
                iType("sll", "t0", "t0", 2);        // ptr + int * size
            } else if (lType->getNodeType() == BaseType::SInt &&
                       (rType->getNodeType() == BaseType::Pointer ||
                        rType->getNodeType() == BaseType::Array)) { // int + ptr
                comment("int + ptr");
                iType("sll", "s0", "s0", 2);
            } else if (lType->getNodeType() == BaseType::Pointer &&
                       rType->getNodeType() == BaseType::Pointer) { // ptr - ptr
                comment("ptr - ptr");
                ptrSub = true;
            }
            genBinaryExpressionAsm(
                    dynamic_cast<tree::TerminalNode *>(ops[i]->children.front())->getSymbol()->getType());
            if (ptrSub) { // ptr - ptr
                iType("srl", "s0", "s0", 2);    // should be type size/4
            }
            lType = getRetType(lType, rType,
                               dynamic_cast<tree::TerminalNode *>(ops[i]->children.front())->getSymbol()->getType());
        }
        mov("v0", "s0");
        popReg("s0");
        pushReg("v0");
        return ExpType(ExpType::Type::RIGHT);
    }
    return exp0Type;
}

void CodeGenVisitor::genBinaryExpressionAsm(size_t tokenType) {
    switch (tokenType) {
        case CLexer::Plus:
            rType3("add", "s0", "s0", "t0");
            break;
        case CLexer::Minus:
            rType3("sub", "s0", "s0", "t0");
            break;
        case CLexer::Star:
            rType2("mult", "s0", "t0");
            rType1("mflo", "s0");
            break;
        case CLexer::Div:
            rType2("div", "s0", "t0");
            rType1("mflo", "s0");
            break;
        case CLexer::Mod:
            rType2("div", "s0", "t0");
            rType1("mfhi", "s0");
            break;
        case CLexer::LeftShift:
            rType3("sllv", "s0", "s0", "t0");
            break;
        case CLexer::RightShift:
            rType3("srlv", "s0", "s0", "t0");
            break;
        case CLexer::Less:
            rType3("slt", "s0", "s0", "t0");
            break;
        case CLexer::Greater:
            rType3("sgt", "s0", "s0", "t0");
            break;
        case CLexer::LessEqual:
            rType3("sle", "s0", "s0", "t0");
            break;
        case CLexer::GreaterEqual:
            rType3("sge", "s0", "s0", "t0");
            break;
        case CLexer::Equal:
            rType3("seq", "s0", "t0", "s0");
            break;
        case CLexer::NotEqual:
            rType3("sne", "s0", "t0", "s0");
            break;
        case CLexer::And:       // &
            rType3("and", "s0", "s0", "t0");
            break;
        case CLexer::Or:        // |
            rType3("or", "s0", "s0", "t0");
            break;
        case CLexer::Caret:     // ^
            rType3("xor", "s0", "s0", "t0");
            break;
        case CLexer::OrOr:      // ||
            rType3("or", "s0", "s0", "t0");
            iType("sne", "s0", "s0", 0);
            break;
        case CLexer::AndAnd:    // &&
            iType("sne", "t0", "t0", 0);
            iType("sne", "s0", "s0", 0);
            rType3("and", "s0", "s0", "t0");
            break;
        default:
            std::cerr << "undefined symbol for binary expression" << std::endl;
            assert(false);
    }
}

antlrcpp::Any CodeGenVisitor::visitMultiplicativeExpression(CParser::MultiplicativeExpressionContext *ctx) {
    return genBinaryExpression(ctx->castExpression(), ctx->multiplicativeOperator());
}

antlrcpp::Any CodeGenVisitor::visitShiftExpression(CParser::ShiftExpressionContext *ctx) {
    return genBinaryExpression(ctx->additiveExpression(), ctx->shiftOperator());
}

antlrcpp::Any CodeGenVisitor::visitRelationalExpression(CParser::RelationalExpressionContext *ctx) {
    return genBinaryExpression(ctx->shiftExpression(), ctx->relationalOperator());
}

antlrcpp::Any CodeGenVisitor::visitEqualityExpression(CParser::EqualityExpressionContext *ctx) {
    return genBinaryExpression(ctx->relationalExpression(), ctx->equalityOperator());
}

antlrcpp::Any CodeGenVisitor::visitAndExpression(CParser::AndExpressionContext *ctx) {
    return genBinaryExpression(ctx->equalityExpression(), ctx->andOperator());
}

antlrcpp::Any CodeGenVisitor::visitExclusiveOrExpression(CParser::ExclusiveOrExpressionContext *ctx) {
    return genBinaryExpression(ctx->andExpression(), ctx->exclusiveOrOperator());
}

antlrcpp::Any CodeGenVisitor::visitInclusiveOrExpression(CParser::InclusiveOrExpressionContext *ctx) {
    return genBinaryExpression(ctx->exclusiveOrExpression(), ctx->inclusiveOrOperator());
}

antlrcpp::Any CodeGenVisitor::visitLogicalAndExpression(CParser::LogicalAndExpressionContext *ctx) {
    return genBinaryExpression(ctx->inclusiveOrExpression(), ctx->logicalAndOperator());
}

antlrcpp::Any CodeGenVisitor::visitLogicalOrExpression(CParser::LogicalOrExpressionContext *ctx) {
    return genBinaryExpression(ctx->logicalAndExpression(), ctx->logicalOrOperator());
}

antlrcpp::Any CodeGenVisitor::visitBlockItem(CParser::BlockItemContext *ctx) {
    if (auto stmt = ctx->statement()) {
        return visit(stmt);
    } else if (auto decl = ctx->declaration()) {
        visit(decl);
    }
    return ExpType();
}

antlrcpp::Any CodeGenVisitor::visitExpStmt(CParser::ExpStmtContext *ctx) {
    if (auto exp = ctx->expression()) {
        visit(exp);
        comment("unused expr value at the top of stack, destroy it");
        pop();
    }
    return ExpType();
}

string CodeGenVisitor::unescape(const string &rawString) {
    string res;
    string::const_iterator it = rawString.begin();
    while (it != rawString.end()) {
        char c = *it++;
        if (c == '\\' && it != rawString.end()) {
            switch (*it++) {
                case '\\':
                    c = '\\';
                    break;
                case 'n':
                    c = '\n';
                    break;
                case 't':
                    c = '\t';
                    break;
                default:
                    throw InvalidCharSequence(rawString);
            }
        }
        res += c;
    }
    return res;
}



