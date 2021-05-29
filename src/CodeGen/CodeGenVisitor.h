//
// Created by ybc on 2021/5/27.
//

#ifndef MYCC_CODEGENVISITOR_H
#define MYCC_CODEGENVISITOR_H

#include "antlr4-runtime.h"
#include "CLexer.h"
#include "CParser.h"

#include "CBaseVisitor.h"
#include "utilities/SymTab.h"
#include <vector>
#include <sstream>

using namespace antlrcpp;
using namespace antlr4;
using std::vector;
using std::string;
using std::to_string;
using strings = vector<string>;
using std::ostringstream;

class CodeGenVisitor : public CBaseVisitor {
    ostringstream _code;
    ostringstream _data;
    string curFunc;
    size_t blockDep;
    size_t labelCount;

    inline void li(const string &reg, int imm) { _code << "\tli $" + reg + ", " + to_string(imm) + "\n"; }

    inline void mov(const string &reg0, const string &reg1) { iType("addiu", reg0, reg1, 0); }

    inline void memI(const string &op, const string &rs, const string &rt, int offset) {
        _code << "\t" + op + " $" + rs + ", " + to_string(offset) + "($" + rt + ")\n";
    }

    inline void iType(const string &op, const string &rs, const string &rt, int imm) {
        _code << "\t" + op + " $" + rs + ", $" + rt + ", " + to_string(imm) + "\n";
    }

    inline void rType3(const string &op, const string &rs, const string &rt, const string &rd) {
        _code << "\t" + op + " $" + rs + ", $" + rt + ", $" + rd + "\n";
    }

    inline void rType2(const string &op, const string &rs, const string &rt) {
        _code << "\t" + op + " $" + rs + ", $" + rt + "\n";
    }

    inline void pushReg(const string &reg) {
        comment("push(" + reg + ")");
        iType("addiu", "sp", "sp", -4);
        memI("sw", reg, "sp", 0);
    }

    inline void popReg(const string &reg) {
        comment("pop(" + reg + ")");
        memI("lw", reg, "sp", 0);
        iType("addiu", "sp", "sp", 4);
    }

    inline void popReg(const string &reg0, const string &reg1) {
        comment("pop2(" + reg0 + "," + reg1 + ")");
        memI("lw", reg0, "sp", 4);
        memI("lw", reg1, "sp", 0);
        iType("addiu", "sp", "sp", 8);
    }


    inline void comment(const string &comment) { _code << "\t#" + comment + "\n"; }

    enum class ExpType {
        INT, LEFT, RIGHT, PTR, ARR, UNDEF
    };

public:
    CodeGenVisitor() : blockDep(0), labelCount(0), curFunc(), _code(), _data() {}

    // expression
    antlrcpp::Any visitConstant(CParser::ConstantContext *ctx) override;

    antlrcpp::Any visitUnaryExpression(CParser::UnaryExpressionContext *ctx) override;


    // statement
    //    antlrcpp::Any visitExpStmt(CParser::ExpStmtContext *ctx) override;

    antlrcpp::Any visitReturnStmt(CParser::ReturnStmtContext *ctx) override;

    antlrcpp::Any visitCompoundStatement(CParser::CompoundStatementContext *ctx) override;

    // program file
    antlrcpp::Any visitCompilationUnit(CParser::CompilationUnitContext *ctx) override;

    antlrcpp::Any visitFunctionDefinition(CParser::FunctionDefinitionContext *ctx) override;

//    antlrcpp::Any visitMultiplicativeExpression(CParser::MultiplicativeExpressionContext *ctx);

    antlrcpp::Any visitAdditiveExpression(CParser::AdditiveExpressionContext *ctx) override;


};


#endif //MYCC_CODEGENVISITOR_H
