//
// Created by ybc on 2021/5/27.
//

#include "CodeGenVisitor.h"

antlrcpp::Any CodeGenVisitor::visitExpression(CParser::ExpressionContext *ctx) {
    _code << "\tli $v0, " << ctx->DigitSequence()->getText() << "\n"
          << pushReg("v0");
    return ExpType::INT;
}

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
    _code << curFunc << ":\n"
          << pushReg("ra")
          << pushReg("s8")
          << "\taddiu $s8, $sp, 0\n"    // new fp
          << "\taddiu $sp, $s8, ";

    // allocate local vars on stack
    size_t varSize = 0;
    for (auto &entry : entries) {
        if (entry.first.substr(0, curFunc.length()) == curFunc) {
            varSize += entry.second.type.getTypeTree()->getSize();
        }
    }
    std::cout << "varSize:" << -1 * (int) varSize << "\n";
    _code << -1 * (int) varSize << "\n";

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
    _code << popReg("v0");
    if (type == ExpType::LEFT) {
        _code << "\tlw $v0, 0($v0)\n";
    }
    _code << pushReg("v0")
          << "\taddiu $a0, $v0, 0\n"
          << "\tli $v0, 1 # syscall(1): print int\n" // print return value ($v0)
          << "\tsyscall\n"
          << popReg("v0");

    _code << popReg("s8")
          << popReg("ra")
          << "\tjr $ra\n";

    return ExpType::UNDEF;
}

std::string CodeGenVisitor::pushReg(const std::string &reg) {
    return "\t#push\n"
           "\taddiu $sp, $sp, -4\n"
           "\tsw $" + reg + ", 0($sp)\n";
}

std::string CodeGenVisitor::popReg(const std::string &reg) {
    return "\t#pop\n"
           "\tlw $" + reg + ", 0($sp)\n"
                            "\taddiu $sp, $sp, 4\n";
}

std::string CodeGenVisitor::popReg(const std::string &reg0, const std::string &reg1) {
    return "\t#pop2\n"
           "\tlw $" + reg0 + ", 4($sp)\n"
                             "\tlw $" + reg1 + ", 0($sp)\n"
                                               "\taddiu $sp, $sp, 8\n";
}

