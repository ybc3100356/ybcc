//
// Created by ybc on 2021/5/27.
//

#include "CodeGenVisitor.h"

antlrcpp::Any CodeGenVisitor::visitConstant(CParser::ConstantContext *ctx) {
    _code << "\tli $v0, " << ctx->IntegerConstant()->getText() << "\n"
          << pushReg("v0");
    return ExpType::INT;
}

antlrcpp::Any CodeGenVisitor::visitUnaryExpression(CParser::UnaryExpressionContext *ctx) {
    if (auto postExp = ctx->postfixExpression()) {
        visit(postExp);
    } else {
        visit(ctx->unaryExpression());
        if (auto op = ctx->unaryOperator()) {
            if (op->Minus()) {      // -
                _code << popReg("t0")
                      << rType3("sub", "v0", "0", "t0")
                      << pushReg("v0");
                return ExpType::INT;
            } else if (op->Not()) { // !x, 0->1, non-0 ->0
                _code << popReg("t0")
                      << iType("sltiu", "v0", "t0", 1)
                      << pushReg("v0");
                return ExpType::INT;
            } else if (op->Tilde()) // ~x, bit-wise not x
            {
                _code << popReg("t0")
                      << rType3("nor", "v0", "t0", "0")
                      << rType2("not", "v0", "t0")
                      << pushReg("v0");
                return ExpType::INT;
            }
        }
    }
    return ExpType::UNDEF;
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
        _code << memI("lw", "v0", "$v0", 0);
    }
    _code << pushReg("v0")
          << iType("addiu", "a0", "v0", 0)
          << "\tli $v0, 1 # syscall(1): print int\n" // print return value ($v0)
          << "\tsyscall\n"
          << popReg("v0");

    _code << popReg("s8")
          << popReg("ra")
          << "\tjr $ra\n";

    return ExpType::UNDEF;
}

inline
string CodeGenVisitor::pushReg(const string &reg) {
    return "\t#push(" + reg + ")\n" +
           iType("addiu", "sp", "sp", -4) +
           memI("sw", reg, "sp", 0);
}

inline
string CodeGenVisitor::popReg(const string &reg) {
    return "\t#pop(" + reg + ")\n" +
           memI("lw", reg, "sp", 0) +
           iType("addiu", "sp", "sp", 4);
}

inline
string CodeGenVisitor::popReg(const string &reg0, const string &reg1) {
    return "\t#pop2(" + reg0 + "," + reg1 + ")\n" +
           memI("lw", reg0, "sp", 4) +
           memI("lw", reg1, "sp", 0) +
           iType("addiu", "sp", "sp", 8);
}

inline
string CodeGenVisitor::memI(const string &op, const string &rs, const string &rt, int offset) {
    return "\t" + op + " $" + rs + ", " + to_string(offset) + "($" + rt + ")\n";
}

inline
string CodeGenVisitor::iType(const string &op, const string &rs, const string &rt, int imm) {
    return "\t" + op + " $" + rs + ", $" + rt + ", " + to_string(imm) + "\n";
}

inline
string CodeGenVisitor::rType3(const string &op, const string &rs, const string &rt, const string &rd) {
    return "\t" + op + " $" + rs + ", $" + rt + ", $" + rd + "\n";
}

inline
string CodeGenVisitor::rType2(const string &op, const string &rs, const string &rt) {
    return "\t" + op + " $" + rs + ", $" + rt + "\n";
}
