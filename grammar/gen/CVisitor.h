
// Generated from C.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"
#include "CParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by CParser.
 */
class  CVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by CParser.
   */
    virtual antlrcpp::Any visitPrimaryExpression(CParser::PrimaryExpressionContext *context) = 0;

    virtual antlrcpp::Any visitIdentifier(CParser::IdentifierContext *context) = 0;

    virtual antlrcpp::Any visitIntConst(CParser::IntConstContext *context) = 0;

    virtual antlrcpp::Any visitCharConst(CParser::CharConstContext *context) = 0;

    virtual antlrcpp::Any visitStrConst(CParser::StrConstContext *context) = 0;

    virtual antlrcpp::Any visitPostfixExpression(CParser::PostfixExpressionContext *context) = 0;

    virtual antlrcpp::Any visitArgumentExpressionList(CParser::ArgumentExpressionListContext *context) = 0;

    virtual antlrcpp::Any visitUnaryExpression(CParser::UnaryExpressionContext *context) = 0;

    virtual antlrcpp::Any visitPrefixOperator(CParser::PrefixOperatorContext *context) = 0;

    virtual antlrcpp::Any visitUnaryOperator(CParser::UnaryOperatorContext *context) = 0;

    virtual antlrcpp::Any visitCastExpression(CParser::CastExpressionContext *context) = 0;

    virtual antlrcpp::Any visitMultiplicativeExpression(CParser::MultiplicativeExpressionContext *context) = 0;

    virtual antlrcpp::Any visitMultiplicativeOperator(CParser::MultiplicativeOperatorContext *context) = 0;

    virtual antlrcpp::Any visitAdditiveExpression(CParser::AdditiveExpressionContext *context) = 0;

    virtual antlrcpp::Any visitAdditiveOperator(CParser::AdditiveOperatorContext *context) = 0;

    virtual antlrcpp::Any visitShiftExpression(CParser::ShiftExpressionContext *context) = 0;

    virtual antlrcpp::Any visitShiftOperator(CParser::ShiftOperatorContext *context) = 0;

    virtual antlrcpp::Any visitRelationalExpression(CParser::RelationalExpressionContext *context) = 0;

    virtual antlrcpp::Any visitRelationalOperator(CParser::RelationalOperatorContext *context) = 0;

    virtual antlrcpp::Any visitEqualityExpression(CParser::EqualityExpressionContext *context) = 0;

    virtual antlrcpp::Any visitEqualityOperator(CParser::EqualityOperatorContext *context) = 0;

    virtual antlrcpp::Any visitAndExpression(CParser::AndExpressionContext *context) = 0;

    virtual antlrcpp::Any visitAndOperator(CParser::AndOperatorContext *context) = 0;

    virtual antlrcpp::Any visitExclusiveOrExpression(CParser::ExclusiveOrExpressionContext *context) = 0;

    virtual antlrcpp::Any visitExclusiveOrOperator(CParser::ExclusiveOrOperatorContext *context) = 0;

    virtual antlrcpp::Any visitInclusiveOrExpression(CParser::InclusiveOrExpressionContext *context) = 0;

    virtual antlrcpp::Any visitInclusiveOrOperator(CParser::InclusiveOrOperatorContext *context) = 0;

    virtual antlrcpp::Any visitLogicalAndExpression(CParser::LogicalAndExpressionContext *context) = 0;

    virtual antlrcpp::Any visitLogicalAndOperator(CParser::LogicalAndOperatorContext *context) = 0;

    virtual antlrcpp::Any visitLogicalOrExpression(CParser::LogicalOrExpressionContext *context) = 0;

    virtual antlrcpp::Any visitLogicalOrOperator(CParser::LogicalOrOperatorContext *context) = 0;

    virtual antlrcpp::Any visitConditionalExpression(CParser::ConditionalExpressionContext *context) = 0;

    virtual antlrcpp::Any visitAssignmentExpression(CParser::AssignmentExpressionContext *context) = 0;

    virtual antlrcpp::Any visitAssignmentOperator(CParser::AssignmentOperatorContext *context) = 0;

    virtual antlrcpp::Any visitExpression(CParser::ExpressionContext *context) = 0;

    virtual antlrcpp::Any visitDeclaration(CParser::DeclarationContext *context) = 0;

    virtual antlrcpp::Any visitDeclarationSpecifiers(CParser::DeclarationSpecifiersContext *context) = 0;

    virtual antlrcpp::Any visitTypeName(CParser::TypeNameContext *context) = 0;

    virtual antlrcpp::Any visitDeclarationSpecifier(CParser::DeclarationSpecifierContext *context) = 0;

    virtual antlrcpp::Any visitInitDeclaratorList(CParser::InitDeclaratorListContext *context) = 0;

    virtual antlrcpp::Any visitInitDeclarator(CParser::InitDeclaratorContext *context) = 0;

    virtual antlrcpp::Any visitTypedefSpecifier(CParser::TypedefSpecifierContext *context) = 0;

    virtual antlrcpp::Any visitTypeSpecifier(CParser::TypeSpecifierContext *context) = 0;

    virtual antlrcpp::Any visitSimpleTypeSpecifier(CParser::SimpleTypeSpecifierContext *context) = 0;

    virtual antlrcpp::Any visitDeclarator(CParser::DeclaratorContext *context) = 0;

    virtual antlrcpp::Any visitArray(CParser::ArrayContext *context) = 0;

    virtual antlrcpp::Any visitPointer(CParser::PointerContext *context) = 0;

    virtual antlrcpp::Any visitDirectDeclarator(CParser::DirectDeclaratorContext *context) = 0;

    virtual antlrcpp::Any visitParameterTypeList(CParser::ParameterTypeListContext *context) = 0;

    virtual antlrcpp::Any visitParameterList(CParser::ParameterListContext *context) = 0;

    virtual antlrcpp::Any visitParameterDeclaration(CParser::ParameterDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitInitializer(CParser::InitializerContext *context) = 0;

    virtual antlrcpp::Any visitBlock(CParser::BlockContext *context) = 0;

    virtual antlrcpp::Any visitExpStmt(CParser::ExpStmtContext *context) = 0;

    virtual antlrcpp::Any visitIfStmt(CParser::IfStmtContext *context) = 0;

    virtual antlrcpp::Any visitWhileLoop(CParser::WhileLoopContext *context) = 0;

    virtual antlrcpp::Any visitDoWhile(CParser::DoWhileContext *context) = 0;

    virtual antlrcpp::Any visitForLoop(CParser::ForLoopContext *context) = 0;

    virtual antlrcpp::Any visitContinueStmt(CParser::ContinueStmtContext *context) = 0;

    virtual antlrcpp::Any visitBreakStmt(CParser::BreakStmtContext *context) = 0;

    virtual antlrcpp::Any visitReturnStmt(CParser::ReturnStmtContext *context) = 0;

    virtual antlrcpp::Any visitCompoundStatement(CParser::CompoundStatementContext *context) = 0;

    virtual antlrcpp::Any visitBlockItem(CParser::BlockItemContext *context) = 0;

    virtual antlrcpp::Any visitForCondition(CParser::ForConditionContext *context) = 0;

    virtual antlrcpp::Any visitForInit(CParser::ForInitContext *context) = 0;

    virtual antlrcpp::Any visitForFinalExpression(CParser::ForFinalExpressionContext *context) = 0;

    virtual antlrcpp::Any visitForCondExpression(CParser::ForCondExpressionContext *context) = 0;

    virtual antlrcpp::Any visitCompilationUnit(CParser::CompilationUnitContext *context) = 0;

    virtual antlrcpp::Any visitTranslationUnit(CParser::TranslationUnitContext *context) = 0;

    virtual antlrcpp::Any visitExternalDeclaration(CParser::ExternalDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitGlobalDeclaration(CParser::GlobalDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitFunctionDefinition(CParser::FunctionDefinitionContext *context) = 0;


};

