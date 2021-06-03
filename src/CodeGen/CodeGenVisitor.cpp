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
            auto initCtx = SymTab::getInstance().get(name).initValue;
            if (initCtx != nullptr)
                initValue = atoi(initCtx->getText().c_str());
            globalVar(name, initValue);
        }
    }
    return ExpType::UNDEF;
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
    for (auto &paramName : paramNames) {
        auto entry = SymTab::getInstance().get(paramName);
        auto argOffset = WORD_BYTES * (2 + (int) entry.offset);
        auto paramOffset = -WORD_BYTES - WORD_BYTES * (int) entry.offset;
        comment("param " + paramName + "(" + to_string(entry.line) + "," + to_string(entry.column) + ")" +
                ": fp+(" + to_string(argOffset) +
                ") to fp+(" + to_string(paramOffset) + ")");
        memType("lw", "t0", "s8", argOffset);
        memType("sw", "t0", "s8", paramOffset);
    }

    // allocate local vars on stack
    size_t offsets = SymTab::getInstance().getTotalOffset(curFunc);
    comment("offsets:" + to_string(offsets));
    iType("addiu", "sp", "s8", -4 * (int) offsets);

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
    return ExpType::UNDEF;
}

antlrcpp::Any CodeGenVisitor::visitCompoundStatement(CParser::CompoundStatementContext *ctx) {
    comment("block " + to_string(blockOrder) + " begin:");
    blockOrderStack.push_back(blockOrder);
    blockOrder = 0;
    for (auto item : ctx->blockItem()) {
        if (visit(item).as<ExpType>() != ExpType::UNDEF) {
            comment("unused expr value, destroy it");
            pop();
        }
    }
    blockOrder = blockOrderStack.back() + 1;
    blockOrderStack.pop_back();
    comment("block " + to_string(blockOrder - 1) + " end");
    return ExpType::UNDEF;
}

antlrcpp::Any CodeGenVisitor::visitReturnStmt(CParser::ReturnStmtContext *ctx) {
    // epilogue
    _code << "\t#return\n";
    if (visit(ctx->expression()).as<ExpType>() == ExpType::LEFT) {
        load();
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
    return ExpType::UNDEF;
}

antlrcpp::Any CodeGenVisitor::visitIfStmt(CParser::IfStmtContext *ctx) {
    if (visit(ctx->expression()).as<ExpType>() == ExpType::LEFT) {
        load();
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
    return ExpType::UNDEF;
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
    if (visit(ctx->expression()).as<ExpType>() == ExpType::LEFT) {
        load();
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
    return ExpType::UNDEF;
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
    if (visit(ctx->expression()).as<ExpType>() == ExpType::LEFT) {
        load();
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
    return ExpType::UNDEF;
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
    if (auto exp = ctx->forCondition()->expression()) {
        visit(exp);
    } else if (auto dec = ctx->forCondition()->declaration()) {
        visit(dec);
    }
    label(loopBegin);
    // cond
    if (auto cond = ctx->forCondition()->forCondExpression()) {
        if (visit(cond->expression()).as<ExpType>() == ExpType::LEFT) {
            load();
        }
        beqz(breakPoint);
    } else {
        // do nothing
    }
    // body
    visit(ctx->statement());
    label(continuePoint);
    if (auto final = ctx->forCondition()->forFinalExpression()) {
        visit(final);
    }
    j(loopBegin);
    label(breakPoint);
    breakStack.pop_back();
    continueStack.pop_back();
    comment("for loop end");
    blockOrder = blockOrderStack.back() + 1;
    blockOrderStack.pop_back();
    return ExpType::UNDEF;
}

antlrcpp::Any CodeGenVisitor::visitContinueStmt(CParser::ContinueStmtContext *ctx) {
    if (continueStack.empty()) {
        throw InvalidContinue();
    } else
        j(continueStack.back());
    return ExpType::UNDEF;
}

antlrcpp::Any CodeGenVisitor::visitBreakStmt(CParser::BreakStmtContext *ctx) {
    if (continueStack.empty()) {
        throw InvalidBreak();
    } else
        j(breakStack.back());
    return ExpType::UNDEF;
}

antlrcpp::Any CodeGenVisitor::visitConstant(CParser::ConstantContext *ctx) {
    comment("constant");
    li("v0", atoi(ctx->IntegerConstant()->getText().c_str()));
    pushReg("v0");
    return ExpType::INT;
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
    return ExpType::LEFT;
}

antlrcpp::Any CodeGenVisitor::visitPostfixExpression(CParser::PostfixExpressionContext *ctx) {
    auto argExpList = ctx->argumentExpressionList();
    auto parens = ctx->LeftParen();
    if (parens.empty()) {
        return visit(ctx->primaryExpression());
    } else { // if '(' argumentExpressionList? ')'
        if (auto id = ctx->primaryExpression()->identifier()) {
            auto funcName = id->getText();
            SymTab::getInstance().get(funcName);
            size_t offsets = 0;
            if (!argExpList.empty()) {
                auto exps = argExpList[0]->assignmentExpression();
                for (int i = (int) exps.size() - 1; i >= 0; --i) {
                    if (visit(exps[i]).as<ExpType>() == ExpType::LEFT) {
                        load();
                    }
                    // TODO: Calling convection: a0-a3, more on stack
                }
                for (auto &param : SymTab::getInstance().getParamNames(funcName)) {
                    offsets += SymTab::getInstance().getOffset(param);
                }
            }
            call(funcName, offsets);
            pushReg("v0");
            // TODO: load if function return a lvalue
        } else
            throw InvalidFuncCall();
    }
    return ExpType::UNDEF;
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
    return ExpType::UNDEF;
}

antlrcpp::Any CodeGenVisitor::visitAssignmentExpression(CParser::AssignmentExpressionContext *ctx) {
    if (auto condExp = ctx->conditionalExpression()) {
        return visit(condExp);
    } else {
        visit(ctx->assignmentExpression());
        if (visit(ctx->unaryExpression()).as<ExpType>() == ExpType::LEFT) {
            comment("assignment exp:");
            if (ctx->assignmentOperator()->Assign()) {
                store();
                // top: value
                pop();
                pushReg("v0");
            }
            return ExpType::INT;
        } else {
            throw InvalidLvalue(ctx->unaryExpression()->getText());
        }
    }
    return ExpType::UNDEF;
}

antlrcpp::Any CodeGenVisitor::visitInitDeclarator(CParser::InitDeclaratorContext *ctx) {
    auto id = ctx->declarator()->directDeclarator()->identifier();
    comment("define: " + id->getText());
    if (auto init = ctx->initializer()) {
        comment("initialize symbol: " + id->getText());
        if (visit(init).as<ExpType>() == ExpType::LEFT) {
            load();
        }
        if (visit(id).as<ExpType>() == ExpType::LEFT) {
            store();
            pop();
        } else {
            throw InvalidLvalue(ctx->declarator()->getText());
        }
        comment("end of initialization: " + id->getText());
    }
    return ExpType::UNDEF;
}

antlrcpp::Any CodeGenVisitor::visitConditionalExpression(CParser::ConditionalExpressionContext *ctx) {
    if (ctx->Question()) {
        if (visit(ctx->logicalOrExpression()).as<ExpType>() == ExpType::LEFT) {
            load();
        }
        size_t elseBranch = labelCount++;
        size_t endBranch = labelCount++;
        beqz("else_" + to_string(elseBranch));
        if (visit(ctx->expression()).as<ExpType>() == ExpType::LEFT) {
            load();
        }
        j("end_" + to_string(endBranch));
        label("else_" + to_string(elseBranch));
        if (visit(ctx->conditionalExpression()).as<ExpType>() == ExpType::LEFT) {
            load();
        }
        label("end_" + to_string(endBranch));
        return ExpType::INT;
    } else
        return visit(ctx->logicalOrExpression());
}

antlrcpp::Any CodeGenVisitor::visitUnaryExpression(CParser::UnaryExpressionContext *ctx) {
    if (auto postExp = ctx->postfixExpression()) {
        return visit(postExp);
    } else {
        if (auto op = ctx->unaryOperator()) {
            comment("unary exp");
            if (visit(ctx->unaryExpression()).as<ExpType>() == ExpType::LEFT) {
                load();
            }
            if (op->Minus()) {      // -x
                popReg("t0");
                rType3("sub", "v0", "0", "t0");
                pushReg("v0");
                return ExpType::INT;
            } else if (op->Not()) { // !x, 0->1, non-0 ->0
                popReg("t0");
                iType("sltiu", "v0", "t0", 1);
                pushReg("v0");
                return ExpType::INT;
            } else if (op->Tilde()) // ~x, bit-wise not x
            {
                popReg("t0");
                rType3("nor", "v0", "t0", "0");
                rType2("not", "v0", "t0");
                pushReg("v0");
                return ExpType::INT;
            } else if (op->Plus()) {    // +x,  x
                // TODO: int promotion
            } else if (op->Star()) {    // *x
                throw NotImplement("*p");
            } else if (op->And()) {     // &x
                throw NotImplement("&x");
            }
        } else
            return visit(ctx->unaryExpression());
    }
    return ExpType::UNDEF;
}

template<typename T1, typename T2>
antlrcpp::Any CodeGenVisitor::genBinaryExpression(vector<T1 *> exps, vector<T2 *> ops) {
    if (visit(exps[0]).template as<ExpType>() == ExpType::LEFT) {
        comment("load symbol");
        load();
    }
    if (!ops.empty()) {
        popReg("t0");
        pushReg("s0");// save $s0, and use it as accumulator in the following binary expressions
        mov("s0", "t0");
        for (int i = 0; i < ops.size(); i++) {
            if (visit(exps[i + 1]).template as<ExpType>() == ExpType::LEFT) {
                comment("load symbol");
                load();
            }
            popReg("t0");
            genBinaryExpressionAsm(
                    dynamic_cast<tree::TerminalNode *>(ops[i]->children.front())->getSymbol()->getType());
        }
        mov("v0", "s0");
        popReg("s0");
        pushReg("v0");
        return ExpType::INT;
    }
    return ExpType::UNDEF;
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
};

antlrcpp::Any CodeGenVisitor::visitAdditiveExpression(CParser::AdditiveExpressionContext *ctx) {
    genBinaryExpression(ctx->multiplicativeExpression(), ctx->additiveOperator());
    return ExpType::UNDEF;
}

antlrcpp::Any CodeGenVisitor::visitMultiplicativeExpression(CParser::MultiplicativeExpressionContext *ctx) {
    genBinaryExpression(ctx->castExpression(), ctx->multiplicativeOperator());
    return ExpType::UNDEF;
}

antlrcpp::Any CodeGenVisitor::visitShiftExpression(CParser::ShiftExpressionContext *ctx) {
    genBinaryExpression(ctx->additiveExpression(), ctx->shiftOperator());
    return ExpType::UNDEF;
}

antlrcpp::Any CodeGenVisitor::visitRelationalExpression(CParser::RelationalExpressionContext *ctx) {
    genBinaryExpression(ctx->shiftExpression(), ctx->relationalOperator());
    return ExpType::UNDEF;
}

antlrcpp::Any CodeGenVisitor::visitEqualityExpression(CParser::EqualityExpressionContext *ctx) {
    genBinaryExpression(ctx->relationalExpression(), ctx->equalityOperator());
    return ExpType::UNDEF;
}

antlrcpp::Any CodeGenVisitor::visitAndExpression(CParser::AndExpressionContext *ctx) {
    genBinaryExpression(ctx->equalityExpression(), ctx->andOperator());
    return ExpType::UNDEF;
}

antlrcpp::Any CodeGenVisitor::visitExclusiveOrExpression(CParser::ExclusiveOrExpressionContext *ctx) {
    genBinaryExpression(ctx->andExpression(), ctx->exclusiveOrOperator());
    return ExpType::UNDEF;
}

antlrcpp::Any CodeGenVisitor::visitInclusiveOrExpression(CParser::InclusiveOrExpressionContext *ctx) {
    genBinaryExpression(ctx->exclusiveOrExpression(), ctx->inclusiveOrOperator());
    return ExpType::UNDEF;
}

antlrcpp::Any CodeGenVisitor::visitLogicalAndExpression(CParser::LogicalAndExpressionContext *ctx) {
    genBinaryExpression(ctx->inclusiveOrExpression(), ctx->logicalAndOperator());
    return ExpType::UNDEF;
}

antlrcpp::Any CodeGenVisitor::visitLogicalOrExpression(CParser::LogicalOrExpressionContext *ctx) {
    genBinaryExpression(ctx->logicalAndExpression(), ctx->logicalOrOperator());
    return ExpType::UNDEF;
}

antlrcpp::Any CodeGenVisitor::visitBlockItem(CParser::BlockItemContext *ctx) {
    if (auto stmt = ctx->statement()) {
        return visit(stmt);
    } else if (auto decl = ctx->declaration()) {
        visit(decl);
    }
    return ExpType::UNDEF;
}

antlrcpp::Any CodeGenVisitor::visitExpStmt(CParser::ExpStmtContext *ctx) {
    if (auto exp = ctx->expression()) {
        return visit(exp);
    }
    return ExpType::UNDEF;
}

