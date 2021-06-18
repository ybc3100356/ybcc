//
// Created by 44190 on 5/26/2021.
//

#ifndef MYCC_DECLARATIONVISITOR_H
#define MYCC_DECLARATIONVISITOR_H

#include <utility>

#include "antlr4-runtime.h"
#include "CLexer.h"
#include "CParser.h"

#include "CBaseVisitor.h"
#include "SymTab.h"
#include "utilities.h"

using namespace antlrcpp;
using namespace antlr4;
using strings = vector<string>;

class InitDeclarator {
public:
    string name;
    size_t pointerNum;
    vector<size_t> arraySizes;
    InitValuePtr initValue;

    explicit InitDeclarator(string name, size_t pointers = 0, vector<size_t> arraySizes = {},
                            InitValuePtr initValue = InitValuePtr()) :
            name(std::move(name)), pointerNum(pointers), arraySizes(std::move(arraySizes)), initValue(initValue) {}
};


class DeclarationVisitor : public CBaseVisitor {
    using InitDeclarators = vector<InitDeclarator>;

    class RetType {
    public:
        CTypeBasePtr type;
        bool isLeftValue;

        explicit RetType(CTypeBasePtr type = NoneTypePtr(), bool isLeftValue = false) : type(std::move(type)),
                                                                                        isLeftValue(isLeftValue) {}
    };

    string curFunc;
    vector<size_t> blockOrderStack;
    size_t blockOrder = 0;
public:

    string getCompoundContext() {
        string compound_names;
        // TODO: make sure '@' not in any name
        for (const auto &order : blockOrderStack) {
            compound_names += to_string(order) + '@';
        }
        if (!curFunc.empty())
            return curFunc + '@' + compound_names;
        else
            return compound_names;
    }

    antlrcpp::Any visitCompilationUnit(CParser::CompilationUnitContext *ctx) override;

    antlrcpp::Any visitPrimaryExpression(CParser::PrimaryExpressionContext *ctx) override;

    antlrcpp::Any visitIntConst(CParser::IntConstContext *ctx) override;

    antlrcpp::Any visitCharConst(CParser::CharConstContext *ctx) override;

    antlrcpp::Any visitStrConst(CParser::StrConstContext *ctx) override;

    antlrcpp::Any visitIdentifier(CParser::IdentifierContext *ctx) override;

    antlrcpp::Any visitDeclaration(CParser::DeclarationContext *ctx) override;

    antlrcpp::Any visitDeclarationSpecifiers(CParser::DeclarationSpecifiersContext *ctx) override;

    antlrcpp::Any visitTypeName(CParser::TypeNameContext *ctx) override;

    antlrcpp::Any visitSimpleTypeSpecifier(CParser::SimpleTypeSpecifierContext *ctx) override;

    antlrcpp::Any visitInitDeclaratorList(CParser::InitDeclaratorListContext *ctx) override;

    antlrcpp::Any visitInitDeclarator(CParser::InitDeclaratorContext *ctx) override;

    antlrcpp::Any visitInitializer(CParser::InitializerContext *ctx) override;

    antlrcpp::Any visitTypeSpecifier(CParser::TypeSpecifierContext *ctx) override;

    antlrcpp::Any visitFunctionDefinition(CParser::FunctionDefinitionContext *ctx) override;

    antlrcpp::Any visitParameterList(CParser::ParameterListContext *ctx) override;

    antlrcpp::Any visitParameterDeclaration(CParser::ParameterDeclarationContext *ctx) override;

    antlrcpp::Any visitDirectDeclarator(CParser::DirectDeclaratorContext *ctx) override;

    antlrcpp::Any visitDeclarator(CParser::DeclaratorContext *ctx) override;

    antlrcpp::Any visitCompoundStatement(CParser::CompoundStatementContext *ctx) override;

    antlrcpp::Any visitReturnStmt(CParser::ReturnStmtContext *ctx) override;

    antlrcpp::Any visitWhileLoop(CParser::WhileLoopContext *ctx) override;

    antlrcpp::Any visitDoWhile(CParser::DoWhileContext *ctx) override;

    antlrcpp::Any visitForLoop(CParser::ForLoopContext *ctx) override;

    antlrcpp::Any visitBlockItem(CParser::BlockItemContext *ctx) override;

    antlrcpp::Any visitGeneralizedCompoundStatement(CParser::BlockContext::ParseTree *ctx);

    antlrcpp::Any visitAssignmentExpression(CParser::AssignmentExpressionContext *ctx) override;

    antlrcpp::Any visitUnaryExpression(CParser::UnaryExpressionContext *ctx) override;

    antlrcpp::Any visitPostfixExpression(CParser::PostfixExpressionContext *ctx) override;

    antlrcpp::Any visitConditionalExpression(CParser::ConditionalExpressionContext *ctx) override;

    antlrcpp::Any visitAdditiveExpression(CParser::AdditiveExpressionContext *ctx) override;

    antlrcpp::Any visitCastExpression(CParser::CastExpressionContext *ctx) override;
};


#endif //MYCC_DECLARATIONVISITOR_H
