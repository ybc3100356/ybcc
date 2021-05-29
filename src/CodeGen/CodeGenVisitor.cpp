//
// Created by ybc on 2021/5/27.
//

#include "CodeGenVisitor.h"

antlrcpp::Any CodeGenVisitor::visitConstant(CParser::ConstantContext *ctx) {
    comment("constant");
    li("v0", atoi(ctx->IntegerConstant()->getText().c_str()));
    pushReg("v0");
    return ExpType::INT;
}

antlrcpp::Any CodeGenVisitor::visitUnaryExpression(CParser::UnaryExpressionContext *ctx) {
    if (auto postExp = ctx->postfixExpression()) {
        visit(postExp);
    } else {
        visit(ctx->unaryExpression());
        if (auto op = ctx->unaryOperator()) {
            if (op->Minus()) {      // -
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
            }
        }
    }
    return ExpType::UNDEF;
}


template<typename T1, typename T2>
antlrcpp::Any CodeGenVisitor::genBinaryExpression(vector<T1 *> exps, vector<T2 *> ops) {
    visit(exps[0]);
    if (!ops.empty()) {
        popReg("t0");
        pushReg("s0");
        mov("s0", "t0");
        for (int i = 0; i < ops.size(); i++) {
            visit(exps[i + 1]);
            popReg("t0");
            if (!ops[i]->children.empty()) {
                genBinaryExpressionAsm(
                        dynamic_cast<tree::TerminalNode *>(ops[i]->children.front())->getSymbol()->getType()
                );
            } else {
                genBinaryExpressionAsm(
                        dynamic_cast<tree::TerminalNode *>(ops[i]->children.front())->getSymbol()->getType()
                );
            }
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
        case CLexer::And:   // &
            rType3("and", "s0", "s0", "t0");
            break;
        case CLexer::Or:    // |
            rType3("or", "s0", "s0", "t0");
            break;
        case CLexer::Caret: // ^
            rType3("xor", "s0", "s0", "t0");
            break;
//        case CLexer::OrOr:  // ||
//            rType3("sne", "s0", "s0", "$0");
//            rType3("sne", "s0", "s0", "t0");
//            break;
//        case CLexer::AndAnd:// &&
//            rType3("sne", "s0", "s0", "t0");
//            break;
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

//antlrcpp::Any CodeGenVisitor::visitLogicalAndExpression(CParser::LogicalAndExpressionContext *ctx) {
//    genBinaryExpression(ctx->inclusiveOrExpression(), ctx->logicalAndOperator());
//    return ExpType::UNDEF;
//}
//
//antlrcpp::Any CodeGenVisitor::visitLogicalOrExpression(CParser::LogicalOrExpressionContext *ctx) {
//    genBinaryExpression(ctx->logicalAndExpression(), ctx->logicalOrOperator());
//    return ExpType::UNDEF;
//}

antlrcpp::Any CodeGenVisitor::visitCompilationUnit(CParser::CompilationUnitContext *ctx) {
    _data << ".data\n";
    _code << ".text\n"
          << ".globl main\n";
    visitChildren(ctx);
    return _data.str() + _code.str();
}

antlrcpp::Any CodeGenVisitor::visitFunctionDefinition(CParser::FunctionDefinitionContext *ctx) {
    curFunc = ctx->declarator()->directDeclarator()->Identifier()->getText();
    auto entries = SymTab::getInstance().getEntries();
    auto curFuncEntry = entries.find(curFunc);
    if (curFuncEntry == entries.end()) {
        assert(false);
    }
    auto funcNode = dynamic_cast<FunctionTypeNode *> (curFuncEntry->second.type.getTypeTree().get());
    // allocate an frame
    _code << curFunc << ":\n";
    pushReg("ra");
    pushReg("s8");
    iType("addiu", "s8", "sp", 0); // new fp

    // allocate local vars on stack
    size_t varSize = 0;
    for (auto &entry : entries) {
        if (entry.first.substr(0, curFunc.length()) == curFunc) {
            varSize += entry.second.type.getTypeTree()->getSize();
        }
    }
    iType("addiu", "sp", "s8", -1 * (int) varSize);

    // Calling convection: a0-a3, more on stack
    // TODO: param passing
    visit(ctx->compoundStatement());

    if (curFunc == "main" && false) { // if there is no return in main
        _code << "\tli $v0, 0\n"            // return 0
              << "\taddiu $sp, $s8, 4\n"
              << "\tlw $ra, 0($sp)\n"       // ra
              << "\tlw $s8, -4($sp)\n"      // fp
              << "\tjr $ra\n";              // ret
    }
    return ExpType::UNDEF;
}

antlrcpp::Any CodeGenVisitor::visitCompoundStatement(CParser::CompoundStatementContext *ctx) {
    ++blockDep;
    curFunc += "@" + std::to_string(blockDep);
    for (auto item : ctx->blockItem()) {
        visit(item);
    }
    // When exiting a scope, update the block depth & block order(only top level)
    if (--blockDep == 0) { ;
    }
    size_t pos = curFunc.find_last_of('@');
    curFunc = curFunc.substr(0, pos);
    return ExpType::UNDEF;
}

antlrcpp::Any CodeGenVisitor::visitReturnStmt(CParser::ReturnStmtContext *ctx) {
    _code << "\t#return\n";
    ExpType type = visit(ctx->expression()).as<ExpType>();
    popReg("v0");
    if (type == ExpType::LEFT) {
        memI("lw", "v0", "$v0", 0);
    }
    pushReg("v0");
    iType("addiu", "a0", "v0", 0);
    _code << "\tli $v0, 1 # syscall(1): print int\n" // print return value ($v0)
          << "\tsyscall\n";
    popReg("v0");

    popReg("s8");
    popReg("ra");
    _code << "\tjr $ra\n";

    return ExpType::UNDEF;
}