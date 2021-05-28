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

    static string pushReg(const string &reg);

    static string popReg(const string &reg);

    static string popReg(const string &reg0, const string &reg1);

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

    static string memI(const string &op, const string &rs, const string &rt, int offset);

    static string iType(const string &op, const string &rs, const string &rt, int imm);

    static string rType3(const string &op, const string &rs, const string &rt, const string &rd);

    static string rType2(const string &op, const string &rs, const string &rt);
};


#endif //MYCC_CODEGENVISITOR_H
