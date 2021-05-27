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

using namespace antlrcpp;
using namespace antlr4;
using std::vector;
using std::string;
using strings = vector<string>;

class CodeGenVisitor : public CBaseVisitor {
    // expression
    antlrcpp::Any visitPrimaryExpression(CParser::PrimaryExpressionContext *ctx) override;

    antlrcpp::Any visitPostfixExpression(CParser::PostfixExpressionContext *ctx) override;

    antlrcpp::Any visitArgumentExpressionList(CParser::ArgumentExpressionListContext *ctx) override;

    antlrcpp::Any visitUnaryExpression(CParser::UnaryExpressionContext *ctx) override;

    antlrcpp::Any visitUnaryOperator(CParser::UnaryOperatorContext *ctx) override;

    antlrcpp::Any visitCastExpression(CParser::CastExpressionContext *ctx) override;

    antlrcpp::Any visitMultiplicativeExpression(CParser::MultiplicativeExpressionContext *ctx) override;

    antlrcpp::Any visitAdditiveExpression(CParser::AdditiveExpressionContext *ctx) override;

    antlrcpp::Any visitShiftExpression(CParser::ShiftExpressionContext *ctx) override;

    antlrcpp::Any visitRelationalExpression(CParser::RelationalExpressionContext *ctx) override;

    antlrcpp::Any visitEqualityExpression(CParser::EqualityExpressionContext *ctx) override;

    antlrcpp::Any visitAndExpression(CParser::AndExpressionContext *ctx) override;

    antlrcpp::Any visitExclusiveOrExpression(CParser::ExclusiveOrExpressionContext *ctx) override;

    antlrcpp::Any visitInclusiveOrExpression(CParser::InclusiveOrExpressionContext *ctx) override;

    antlrcpp::Any visitLogicalAndExpression(CParser::LogicalAndExpressionContext *ctx) override;

    antlrcpp::Any visitLogicalOrExpression(CParser::LogicalOrExpressionContext *ctx) override;

    antlrcpp::Any visitConditionalExpression(CParser::ConditionalExpressionContext *ctx) override;

    antlrcpp::Any visitAssignmentExpression(CParser::AssignmentExpressionContext *ctx) override;

    antlrcpp::Any visitAssignmentOperator(CParser::AssignmentOperatorContext *ctx) override;

    antlrcpp::Any visitExpression(CParser::ExpressionContext *ctx) override;

    antlrcpp::Any visitConstantExpression(CParser::ConstantExpressionContext *ctx) override;

    // statement
    antlrcpp::Any visitStatement(CParser::StatementContext *ctx) override;

    antlrcpp::Any visitLabeledStatement(CParser::LabeledStatementContext *ctx) override;

    antlrcpp::Any visitCompoundStatement(CParser::CompoundStatementContext *ctx) override;

    antlrcpp::Any visitBlockItem(CParser::BlockItemContext *ctx) override;

    antlrcpp::Any visitExpressionStatement(CParser::ExpressionStatementContext *ctx) override;

    antlrcpp::Any visitSelectionStatement(CParser::SelectionStatementContext *ctx) override;

    antlrcpp::Any visitIterationStatement(CParser::IterationStatementContext *ctx) override;

    antlrcpp::Any visitForCondition(CParser::ForConditionContext *ctx) override;

    antlrcpp::Any visitForExpression(CParser::ForExpressionContext *ctx) override;

    antlrcpp::Any visitJumpStatement(CParser::JumpStatementContext *ctx) override;

    antlrcpp::Any visitCompilationUnit(CParser::CompilationUnitContext *ctx) override;

    antlrcpp::Any visitTranslationUnit(CParser::TranslationUnitContext *ctx) override;

    antlrcpp::Any visitExternalDeclaration(CParser::ExternalDeclarationContext *ctx) override;

    antlrcpp::Any visitFunctionDefinition(CParser::FunctionDefinitionContext *ctx) override;

};


#endif //MYCC_CODEGENVISITOR_H
