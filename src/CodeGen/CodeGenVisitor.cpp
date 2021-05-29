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

antlrcpp::Any CodeGenVisitor::visitAdditiveExpression(CParser::AdditiveExpressionContext *ctx) {
    comment("====add====");
    auto mulExps = ctx->multiplicativeExpression();
    auto addOps = ctx->additiveOperator();
    visit(mulExps[0]);
    if (!addOps.empty()) {
        popReg("t0");
        pushReg("s0");
        mov("s0", "t0");
        for (int i = 0; i < addOps.size(); i++) {
            if (addOps[i]->Plus()) {
                visit(mulExps[i + 1]);
                popReg("t0");
                rType3("add", "s0", "s0", "t0");
            } else if (addOps[i]->Minus()) {
                visit(mulExps[i + 1]);
                popReg("t0");
                rType3("sub", "s0", "s0", "t0");
            } else {
                assert(false);
            }
        }
        mov("v0", "s0");
        popReg("s0");
        pushReg("v0");
        comment("===end add===");
        return ExpType::INT;
    }
    comment("===end add===");
    return ExpType::UNDEF;
}

//antlrcpp::Any CodeGenVisitor::visitMultiplicativeExpression(CParser::MultiplicativeExpressionContext *ctx) {
//    return CBaseVisitor::visitMultiplicativeExpression(ctx);
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
