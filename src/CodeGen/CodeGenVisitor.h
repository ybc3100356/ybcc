//
// Created by ybc on 2021/5/27.
//

#ifndef MYCC_CODEGENVISITOR_H
#define MYCC_CODEGENVISITOR_H

#include "antlr4-runtime.h"
#include "CLexer.h"
#include "CParser.h"

#include "CBaseVisitor.h"
#include "SymTab.h"
#include "utilities.h"
#include <sstream>

using namespace antlrcpp;
using namespace antlr4;
using strings = vector<string>;
using std::ostringstream;

class CodeGenVisitor : public CBaseVisitor {
    ostringstream _code;
    ostringstream _data;
    string curFunc;
    size_t blockDep;
    size_t labelCount;

public:
    CodeGenVisitor() : blockDep(0), labelCount(0), curFunc(), _code(), _data() {}

    // expression
    antlrcpp::Any visitPrimaryExpression(CParser::PrimaryExpressionContext *ctx) override;

    antlrcpp::Any visitAssignmentExpression(CParser::AssignmentExpressionContext *ctx) override;

    antlrcpp::Any visitConstant(CParser::ConstantContext *ctx) override;

    antlrcpp::Any visitIdentifier(CParser::IdentifierContext *ctx) override;

    antlrcpp::Any visitMultiplicativeExpression(CParser::MultiplicativeExpressionContext *ctx) override;

    antlrcpp::Any visitAdditiveExpression(CParser::AdditiveExpressionContext *ctx) override;

    antlrcpp::Any visitUnaryExpression(CParser::UnaryExpressionContext *ctx) override;

    antlrcpp::Any visitShiftExpression(CParser::ShiftExpressionContext *ctx) override;

    antlrcpp::Any visitRelationalExpression(CParser::RelationalExpressionContext *ctx) override;

    antlrcpp::Any visitEqualityExpression(CParser::EqualityExpressionContext *ctx) override;

    antlrcpp::Any visitAndExpression(CParser::AndExpressionContext *ctx) override;

    antlrcpp::Any visitExclusiveOrExpression(CParser::ExclusiveOrExpressionContext *ctx) override;

    antlrcpp::Any visitInclusiveOrExpression(CParser::InclusiveOrExpressionContext *ctx) override;

    antlrcpp::Any visitLogicalAndExpression(CParser::LogicalAndExpressionContext *ctx) override;

    antlrcpp::Any visitLogicalOrExpression(CParser::LogicalOrExpressionContext *ctx) override;

    // init declaration
    antlrcpp::Any visitInitDeclarator(CParser::InitDeclaratorContext *ctx) override;

    // statement
    antlrcpp::Any visitReturnStmt(CParser::ReturnStmtContext *ctx) override;

    antlrcpp::Any visitCompoundStatement(CParser::CompoundStatementContext *ctx) override;

    antlrcpp::Any visitIfStmt(CParser::IfStmtContext *ctx) override;

    // program file
    antlrcpp::Any visitCompilationUnit(CParser::CompilationUnitContext *ctx) override;

    antlrcpp::Any visitFunctionDefinition(CParser::FunctionDefinitionContext *ctx) override;


private:
    // mips instructions
    inline void li(const string &reg, int imm) { _code << "\tli $" + reg + ", " + to_string(imm) + "\n"; }

    inline void mov(const string &reg0, const string &reg1) { iType("addiu", reg0, reg1, 0); }

    inline void memType(const string &op, const string &rs, const string &rt, int offset) {
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

    inline void rType1(const string &op, const string &reg) {
        _code << "\t" + op + " $" + reg + "\n";
    }

    inline void beq(const string &rs, const string &rt, const string &target) {
        _code << "\tbeq $" + rs + ", $" + rt + ", " + target + "\n";
    }

    inline void bne(const string &rs, const string &rt, const string &target) {
        _code << "\tbne $" + rs + ", $" + rt + ", " + target + "\n";
    }

    inline void j(const string &target) {
        _code << "\tj " + target + "\n";
    }

    // IR
    inline void pushReg(const string &reg) {
        comment("push(" + reg + ")[2 lines]");
        iType("addiu", "sp", "sp", -4);
        memType("sw", reg, "sp", 0);
    }

    inline void popReg(const string &reg) {
        comment("pop(" + reg + ")[2 lines]");
        memType("lw", reg, "sp", 0);
        iType("addiu", "sp", "sp", 4);
    }

    inline void popReg(const string &reg0, const string &reg1) {
        comment("pop2(" + reg0 + "," + reg1 + ")");
        memType("lw", reg0, "sp", 4);
        memType("lw", reg1, "sp", 0);
        iType("addiu", "sp", "sp", 8);
    }

    inline void pushFrameAddr(size_t k) {
        comment("push symbol addr[3 lines]");
        iType("addiu", "sp", "sp", -4);
        iType("addiu", "t1", "fp", -4 - 4 * (int) k);
        memType("sw", "t1", "sp", 0);
    }

    inline void load() {
        comment("load symbol to stack[3 lines]");
        memType("lw", "t1", "sp", 0);    // addr
        memType("lw", "t1", "t1", 0);    // value
        memType("sw", "t1", "sp", 0);    // load(to stack)
    }

    inline void store() {
        comment("store symbol to mem[4 lines]");
        memType("lw", "t1", "sp", 4);    // value
        memType("lw", "t2", "sp", 0);    // addr
        iType("addiu", "sp", "sp", 4);    //
        memType("sw", "t1", "t2", 0);    // store(to addr)
    }


    inline void pop() {
        comment("pop");
        iType("addiu", "sp", "sp", 4);
    }

    inline void label(const string &name) { _code << name + ":"; }

    inline void beqz(const string &target) {
        popReg("t1");
        beq("t1", "0", target);
    }

    inline void bnez(const string &target) {
        popReg("t1");
        bne("t1", "0", target);
    }

    inline void br() { j(to_string(labelCount++)); }

    inline void comment(const string &comment) { _code << "\t#" + comment + "\n"; }

//    inline void frameAddrLocal(size_t k) {
//        iType("addiu", "v0", "fp", -12 - 4 * (int) k);
//    }
//
//    inline void loadLocal(int k) {
//        memType("lw", "a0", "fp", -12 - 4 * k);
//    }
//
//    inline void storeLocal(int k) {
//        memType("sw", "a0", "fp", -12 - 4 * k);
//    }


    void genBinaryExpressionAsm(size_t tokenType);

    template<typename T1, typename T2>
    antlrcpp::Any genBinaryExpression(vector<T1 *> exps, vector<T2 *> ops);

    enum class ExpType {
        INT, LEFT, RIGHT, PTR, ARR, UNDEF
    };
};


#endif //MYCC_CODEGENVISITOR_H
