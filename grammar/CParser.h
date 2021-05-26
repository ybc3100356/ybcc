
// Generated from C.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"




class  CParser : public antlr4::Parser {
public:
  enum {
    Auto = 1, Break = 2, Case = 3, Char = 4, Const = 5, Continue = 6, Default = 7, 
    Do = 8, Double = 9, Else = 10, Enum = 11, Extern = 12, Float = 13, For = 14, 
    Goto = 15, If = 16, Inline = 17, Int = 18, Long = 19, Register = 20, 
    Restrict = 21, Return = 22, Short = 23, Signed = 24, Sizeof = 25, Static = 26, 
    Struct = 27, Switch = 28, Typedef = 29, Union = 30, Unsigned = 31, Void = 32, 
    Volatile = 33, While = 34, Alignas = 35, Alignof = 36, Atomic = 37, 
    Bool = 38, Complex = 39, Generic = 40, Imaginary = 41, Noreturn = 42, 
    StaticAssert = 43, ThreadLocal = 44, LeftParen = 45, RightParen = 46, 
    LeftBracket = 47, RightBracket = 48, LeftBrace = 49, RightBrace = 50, 
    Less = 51, LessEqual = 52, Greater = 53, GreaterEqual = 54, LeftShift = 55, 
    RightShift = 56, Plus = 57, PlusPlus = 58, Minus = 59, MinusMinus = 60, 
    Star = 61, Div = 62, Mod = 63, And = 64, Or = 65, AndAnd = 66, OrOr = 67, 
    Caret = 68, Not = 69, Tilde = 70, Question = 71, Colon = 72, Semi = 73, 
    Comma = 74, Assign = 75, StarAssign = 76, DivAssign = 77, ModAssign = 78, 
    PlusAssign = 79, MinusAssign = 80, LeftShiftAssign = 81, RightShiftAssign = 82, 
    AndAssign = 83, XorAssign = 84, OrAssign = 85, Equal = 86, NotEqual = 87, 
    Arrow = 88, Dot = 89, Ellipsis = 90, Identifier = 91, Constant = 92, 
    DigitSequence = 93, StringLiteral = 94, ComplexDefine = 95, IncludeDirective = 96, 
    AsmBlock = 97, LineAfterPreprocessing = 98, LineDirective = 99, PragmaDirective = 100, 
    Whitespace = 101, Newline = 102, BlockComment = 103, LineComment = 104
  };

  enum {
    RulePrimaryExpression = 0, RulePostfixExpression = 1, RuleArgumentExpressionList = 2, 
    RuleUnaryExpression = 3, RuleUnaryOperator = 4, RuleCastExpression = 5, 
    RuleMultiplicativeExpression = 6, RuleAdditiveExpression = 7, RuleShiftExpression = 8, 
    RuleRelationalExpression = 9, RuleEqualityExpression = 10, RuleAndExpression = 11, 
    RuleExclusiveOrExpression = 12, RuleInclusiveOrExpression = 13, RuleLogicalAndExpression = 14, 
    RuleLogicalOrExpression = 15, RuleConditionalExpression = 16, RuleAssignmentExpression = 17, 
    RuleAssignmentOperator = 18, RuleExpression = 19, RuleConstantExpression = 20, 
    RuleDeclaration = 21, RuleDeclarationSpecifiers = 22, RuleDeclarationSpecifierList = 23, 
    RuleDeclarationSpecifier = 24, RuleInitDeclaratorList = 25, RuleInitDeclarator = 26, 
    RuleTypedefSpecifier = 27, RuleStorageClassSpecifier = 28, RuleTypeSpecifier = 29, 
    RuleSimpleTypeSpecifier = 30, RuleStructOrUnionSpecifier = 31, RuleStructOrUnion = 32, 
    RuleStructDeclarationList = 33, RuleStructDeclaration = 34, RuleSpecifierQualifierList = 35, 
    RuleStructDeclaratorList = 36, RuleStructDeclarator = 37, RuleEnumSpecifier = 38, 
    RuleEnumeratorList = 39, RuleEnumerator = 40, RuleEnumerationConstant = 41, 
    RuleFunctionSpecifier = 42, RuleDeclarator = 43, RuleDirectDeclarator = 44, 
    RuleParameterTypeList = 45, RuleParameterList = 46, RuleParameterDeclaration = 47, 
    RuleIdentifierList = 48, RuleTypeName = 49, RuleAbstractDeclarator = 50, 
    RuleDirectAbstractDeclarators = 51, RuleDirectAbstractDeclarator = 52, 
    RuleTypedefName = 53, RuleInitializer = 54, RuleInitializerList = 55, 
    RuleDesignation = 56, RuleDesignatorList = 57, RuleDesignator = 58, 
    RuleStaticAssertDeclaration = 59, RuleStatement = 60, RuleLabeledStatement = 61, 
    RuleCompoundStatement = 62, RuleBlockItem = 63, RuleExpressionStatement = 64, 
    RuleSelectionStatement = 65, RuleIterationStatement = 66, RuleForCondition = 67, 
    RuleForExpression = 68, RuleJumpStatement = 69, RuleCompilationUnit = 70, 
    RuleTranslationUnit = 71, RuleExternalDeclaration = 72, RuleFunctionDefinition = 73, 
    RuleDeclarationList = 74
  };

  explicit CParser(antlr4::TokenStream *input);
  ~CParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class PrimaryExpressionContext;
  class PostfixExpressionContext;
  class ArgumentExpressionListContext;
  class UnaryExpressionContext;
  class UnaryOperatorContext;
  class CastExpressionContext;
  class MultiplicativeExpressionContext;
  class AdditiveExpressionContext;
  class ShiftExpressionContext;
  class RelationalExpressionContext;
  class EqualityExpressionContext;
  class AndExpressionContext;
  class ExclusiveOrExpressionContext;
  class InclusiveOrExpressionContext;
  class LogicalAndExpressionContext;
  class LogicalOrExpressionContext;
  class ConditionalExpressionContext;
  class AssignmentExpressionContext;
  class AssignmentOperatorContext;
  class ExpressionContext;
  class ConstantExpressionContext;
  class DeclarationContext;
  class DeclarationSpecifiersContext;
  class DeclarationSpecifierListContext;
  class DeclarationSpecifierContext;
  class InitDeclaratorListContext;
  class InitDeclaratorContext;
  class TypedefSpecifierContext;
  class StorageClassSpecifierContext;
  class TypeSpecifierContext;
  class SimpleTypeSpecifierContext;
  class StructOrUnionSpecifierContext;
  class StructOrUnionContext;
  class StructDeclarationListContext;
  class StructDeclarationContext;
  class SpecifierQualifierListContext;
  class StructDeclaratorListContext;
  class StructDeclaratorContext;
  class EnumSpecifierContext;
  class EnumeratorListContext;
  class EnumeratorContext;
  class EnumerationConstantContext;
  class FunctionSpecifierContext;
  class DeclaratorContext;
  class DirectDeclaratorContext;
  class ParameterTypeListContext;
  class ParameterListContext;
  class ParameterDeclarationContext;
  class IdentifierListContext;
  class TypeNameContext;
  class AbstractDeclaratorContext;
  class DirectAbstractDeclaratorsContext;
  class DirectAbstractDeclaratorContext;
  class TypedefNameContext;
  class InitializerContext;
  class InitializerListContext;
  class DesignationContext;
  class DesignatorListContext;
  class DesignatorContext;
  class StaticAssertDeclarationContext;
  class StatementContext;
  class LabeledStatementContext;
  class CompoundStatementContext;
  class BlockItemContext;
  class ExpressionStatementContext;
  class SelectionStatementContext;
  class IterationStatementContext;
  class ForConditionContext;
  class ForExpressionContext;
  class JumpStatementContext;
  class CompilationUnitContext;
  class TranslationUnitContext;
  class ExternalDeclarationContext;
  class FunctionDefinitionContext;
  class DeclarationListContext; 

  class  PrimaryExpressionContext : public antlr4::ParserRuleContext {
  public:
    PrimaryExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *Constant();
    std::vector<antlr4::tree::TerminalNode *> StringLiteral();
    antlr4::tree::TerminalNode* StringLiteral(size_t i);
    antlr4::tree::TerminalNode *LeftParen();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RightParen();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PrimaryExpressionContext* primaryExpression();

  class  PostfixExpressionContext : public antlr4::ParserRuleContext {
  public:
    PostfixExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PrimaryExpressionContext *primaryExpression();
    std::vector<antlr4::tree::TerminalNode *> LeftParen();
    antlr4::tree::TerminalNode* LeftParen(size_t i);
    TypeNameContext *typeName();
    std::vector<antlr4::tree::TerminalNode *> RightParen();
    antlr4::tree::TerminalNode* RightParen(size_t i);
    antlr4::tree::TerminalNode *LeftBrace();
    InitializerListContext *initializerList();
    antlr4::tree::TerminalNode *RightBrace();
    std::vector<antlr4::tree::TerminalNode *> LeftBracket();
    antlr4::tree::TerminalNode* LeftBracket(size_t i);
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RightBracket();
    antlr4::tree::TerminalNode* RightBracket(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Identifier();
    antlr4::tree::TerminalNode* Identifier(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Dot();
    antlr4::tree::TerminalNode* Dot(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Arrow();
    antlr4::tree::TerminalNode* Arrow(size_t i);
    std::vector<antlr4::tree::TerminalNode *> PlusPlus();
    antlr4::tree::TerminalNode* PlusPlus(size_t i);
    std::vector<antlr4::tree::TerminalNode *> MinusMinus();
    antlr4::tree::TerminalNode* MinusMinus(size_t i);
    antlr4::tree::TerminalNode *Comma();
    std::vector<ArgumentExpressionListContext *> argumentExpressionList();
    ArgumentExpressionListContext* argumentExpressionList(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PostfixExpressionContext* postfixExpression();

  class  ArgumentExpressionListContext : public antlr4::ParserRuleContext {
  public:
    ArgumentExpressionListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<AssignmentExpressionContext *> assignmentExpression();
    AssignmentExpressionContext* assignmentExpression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArgumentExpressionListContext* argumentExpressionList();

  class  UnaryExpressionContext : public antlr4::ParserRuleContext {
  public:
    UnaryExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PostfixExpressionContext *postfixExpression();
    UnaryOperatorContext *unaryOperator();
    CastExpressionContext *castExpression();
    std::vector<antlr4::tree::TerminalNode *> Sizeof();
    antlr4::tree::TerminalNode* Sizeof(size_t i);
    antlr4::tree::TerminalNode *LeftParen();
    TypeNameContext *typeName();
    antlr4::tree::TerminalNode *RightParen();
    std::vector<antlr4::tree::TerminalNode *> PlusPlus();
    antlr4::tree::TerminalNode* PlusPlus(size_t i);
    std::vector<antlr4::tree::TerminalNode *> MinusMinus();
    antlr4::tree::TerminalNode* MinusMinus(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UnaryExpressionContext* unaryExpression();

  class  UnaryOperatorContext : public antlr4::ParserRuleContext {
  public:
    UnaryOperatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *And();
    antlr4::tree::TerminalNode *Star();
    antlr4::tree::TerminalNode *Plus();
    antlr4::tree::TerminalNode *Minus();
    antlr4::tree::TerminalNode *Tilde();
    antlr4::tree::TerminalNode *Not();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UnaryOperatorContext* unaryOperator();

  class  CastExpressionContext : public antlr4::ParserRuleContext {
  public:
    CastExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LeftParen();
    TypeNameContext *typeName();
    antlr4::tree::TerminalNode *RightParen();
    CastExpressionContext *castExpression();
    UnaryExpressionContext *unaryExpression();
    antlr4::tree::TerminalNode *DigitSequence();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CastExpressionContext* castExpression();

  class  MultiplicativeExpressionContext : public antlr4::ParserRuleContext {
  public:
    MultiplicativeExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<CastExpressionContext *> castExpression();
    CastExpressionContext* castExpression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Star();
    antlr4::tree::TerminalNode* Star(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Div();
    antlr4::tree::TerminalNode* Div(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Mod();
    antlr4::tree::TerminalNode* Mod(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MultiplicativeExpressionContext* multiplicativeExpression();

  class  AdditiveExpressionContext : public antlr4::ParserRuleContext {
  public:
    AdditiveExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<MultiplicativeExpressionContext *> multiplicativeExpression();
    MultiplicativeExpressionContext* multiplicativeExpression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Plus();
    antlr4::tree::TerminalNode* Plus(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Minus();
    antlr4::tree::TerminalNode* Minus(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AdditiveExpressionContext* additiveExpression();

  class  ShiftExpressionContext : public antlr4::ParserRuleContext {
  public:
    ShiftExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<AdditiveExpressionContext *> additiveExpression();
    AdditiveExpressionContext* additiveExpression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> LeftShift();
    antlr4::tree::TerminalNode* LeftShift(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RightShift();
    antlr4::tree::TerminalNode* RightShift(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ShiftExpressionContext* shiftExpression();

  class  RelationalExpressionContext : public antlr4::ParserRuleContext {
  public:
    RelationalExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ShiftExpressionContext *> shiftExpression();
    ShiftExpressionContext* shiftExpression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Less();
    antlr4::tree::TerminalNode* Less(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Greater();
    antlr4::tree::TerminalNode* Greater(size_t i);
    std::vector<antlr4::tree::TerminalNode *> LessEqual();
    antlr4::tree::TerminalNode* LessEqual(size_t i);
    std::vector<antlr4::tree::TerminalNode *> GreaterEqual();
    antlr4::tree::TerminalNode* GreaterEqual(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RelationalExpressionContext* relationalExpression();

  class  EqualityExpressionContext : public antlr4::ParserRuleContext {
  public:
    EqualityExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<RelationalExpressionContext *> relationalExpression();
    RelationalExpressionContext* relationalExpression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Equal();
    antlr4::tree::TerminalNode* Equal(size_t i);
    std::vector<antlr4::tree::TerminalNode *> NotEqual();
    antlr4::tree::TerminalNode* NotEqual(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EqualityExpressionContext* equalityExpression();

  class  AndExpressionContext : public antlr4::ParserRuleContext {
  public:
    AndExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<EqualityExpressionContext *> equalityExpression();
    EqualityExpressionContext* equalityExpression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> And();
    antlr4::tree::TerminalNode* And(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AndExpressionContext* andExpression();

  class  ExclusiveOrExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExclusiveOrExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<AndExpressionContext *> andExpression();
    AndExpressionContext* andExpression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Caret();
    antlr4::tree::TerminalNode* Caret(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExclusiveOrExpressionContext* exclusiveOrExpression();

  class  InclusiveOrExpressionContext : public antlr4::ParserRuleContext {
  public:
    InclusiveOrExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExclusiveOrExpressionContext *> exclusiveOrExpression();
    ExclusiveOrExpressionContext* exclusiveOrExpression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Or();
    antlr4::tree::TerminalNode* Or(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InclusiveOrExpressionContext* inclusiveOrExpression();

  class  LogicalAndExpressionContext : public antlr4::ParserRuleContext {
  public:
    LogicalAndExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<InclusiveOrExpressionContext *> inclusiveOrExpression();
    InclusiveOrExpressionContext* inclusiveOrExpression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> AndAnd();
    antlr4::tree::TerminalNode* AndAnd(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LogicalAndExpressionContext* logicalAndExpression();

  class  LogicalOrExpressionContext : public antlr4::ParserRuleContext {
  public:
    LogicalOrExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<LogicalAndExpressionContext *> logicalAndExpression();
    LogicalAndExpressionContext* logicalAndExpression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> OrOr();
    antlr4::tree::TerminalNode* OrOr(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LogicalOrExpressionContext* logicalOrExpression();

  class  ConditionalExpressionContext : public antlr4::ParserRuleContext {
  public:
    ConditionalExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LogicalOrExpressionContext *logicalOrExpression();
    antlr4::tree::TerminalNode *Question();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *Colon();
    ConditionalExpressionContext *conditionalExpression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConditionalExpressionContext* conditionalExpression();

  class  AssignmentExpressionContext : public antlr4::ParserRuleContext {
  public:
    AssignmentExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ConditionalExpressionContext *conditionalExpression();
    UnaryExpressionContext *unaryExpression();
    AssignmentOperatorContext *assignmentOperator();
    AssignmentExpressionContext *assignmentExpression();
    antlr4::tree::TerminalNode *DigitSequence();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AssignmentExpressionContext* assignmentExpression();

  class  AssignmentOperatorContext : public antlr4::ParserRuleContext {
  public:
    AssignmentOperatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Assign();
    antlr4::tree::TerminalNode *StarAssign();
    antlr4::tree::TerminalNode *DivAssign();
    antlr4::tree::TerminalNode *ModAssign();
    antlr4::tree::TerminalNode *PlusAssign();
    antlr4::tree::TerminalNode *MinusAssign();
    antlr4::tree::TerminalNode *LeftShiftAssign();
    antlr4::tree::TerminalNode *RightShiftAssign();
    antlr4::tree::TerminalNode *AndAssign();
    antlr4::tree::TerminalNode *XorAssign();
    antlr4::tree::TerminalNode *OrAssign();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AssignmentOperatorContext* assignmentOperator();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<AssignmentExpressionContext *> assignmentExpression();
    AssignmentExpressionContext* assignmentExpression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpressionContext* expression();

  class  ConstantExpressionContext : public antlr4::ParserRuleContext {
  public:
    ConstantExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ConditionalExpressionContext *conditionalExpression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConstantExpressionContext* constantExpression();

  class  DeclarationContext : public antlr4::ParserRuleContext {
  public:
    DeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DeclarationSpecifiersContext *declarationSpecifiers();
    antlr4::tree::TerminalNode *Semi();
    InitDeclaratorListContext *initDeclaratorList();
    StaticAssertDeclarationContext *staticAssertDeclaration();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DeclarationContext* declaration();

  class  DeclarationSpecifiersContext : public antlr4::ParserRuleContext {
  public:
    DeclarationSpecifiersContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DeclarationSpecifierListContext *declarationSpecifierList();
    TypedefSpecifierContext *typedefSpecifier();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DeclarationSpecifiersContext* declarationSpecifiers();

  class  DeclarationSpecifierListContext : public antlr4::ParserRuleContext {
  public:
    DeclarationSpecifierListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<DeclarationSpecifierContext *> declarationSpecifier();
    DeclarationSpecifierContext* declarationSpecifier(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DeclarationSpecifierListContext* declarationSpecifierList();

  class  DeclarationSpecifierContext : public antlr4::ParserRuleContext {
  public:
    DeclarationSpecifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeSpecifierContext *typeSpecifier();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DeclarationSpecifierContext* declarationSpecifier();

  class  InitDeclaratorListContext : public antlr4::ParserRuleContext {
  public:
    InitDeclaratorListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<InitDeclaratorContext *> initDeclarator();
    InitDeclaratorContext* initDeclarator(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InitDeclaratorListContext* initDeclaratorList();

  class  InitDeclaratorContext : public antlr4::ParserRuleContext {
  public:
    InitDeclaratorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DeclaratorContext *declarator();
    antlr4::tree::TerminalNode *Assign();
    InitializerContext *initializer();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InitDeclaratorContext* initDeclarator();

  class  TypedefSpecifierContext : public antlr4::ParserRuleContext {
  public:
    TypedefSpecifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Typedef();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypedefSpecifierContext* typedefSpecifier();

  class  StorageClassSpecifierContext : public antlr4::ParserRuleContext {
  public:
    StorageClassSpecifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Extern();
    antlr4::tree::TerminalNode *Static();
    antlr4::tree::TerminalNode *Auto();
    antlr4::tree::TerminalNode *Register();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StorageClassSpecifierContext* storageClassSpecifier();

  class  TypeSpecifierContext : public antlr4::ParserRuleContext {
  public:
    TypeSpecifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SimpleTypeSpecifierContext *simpleTypeSpecifier();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeSpecifierContext* typeSpecifier();

  class  SimpleTypeSpecifierContext : public antlr4::ParserRuleContext {
  public:
    SimpleTypeSpecifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Void();
    antlr4::tree::TerminalNode *Char();
    antlr4::tree::TerminalNode *Short();
    antlr4::tree::TerminalNode *Int();
    antlr4::tree::TerminalNode *Long();
    antlr4::tree::TerminalNode *Float();
    antlr4::tree::TerminalNode *Double();
    antlr4::tree::TerminalNode *Signed();
    antlr4::tree::TerminalNode *Unsigned();
    antlr4::tree::TerminalNode *Bool();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SimpleTypeSpecifierContext* simpleTypeSpecifier();

  class  StructOrUnionSpecifierContext : public antlr4::ParserRuleContext {
  public:
    StructOrUnionSpecifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    StructOrUnionContext *structOrUnion();
    antlr4::tree::TerminalNode *LeftBrace();
    StructDeclarationListContext *structDeclarationList();
    antlr4::tree::TerminalNode *RightBrace();
    antlr4::tree::TerminalNode *Identifier();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StructOrUnionSpecifierContext* structOrUnionSpecifier();

  class  StructOrUnionContext : public antlr4::ParserRuleContext {
  public:
    StructOrUnionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Struct();
    antlr4::tree::TerminalNode *Union();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StructOrUnionContext* structOrUnion();

  class  StructDeclarationListContext : public antlr4::ParserRuleContext {
  public:
    StructDeclarationListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<StructDeclarationContext *> structDeclaration();
    StructDeclarationContext* structDeclaration(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StructDeclarationListContext* structDeclarationList();

  class  StructDeclarationContext : public antlr4::ParserRuleContext {
  public:
    StructDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SpecifierQualifierListContext *specifierQualifierList();
    antlr4::tree::TerminalNode *Semi();
    StructDeclaratorListContext *structDeclaratorList();
    StaticAssertDeclarationContext *staticAssertDeclaration();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StructDeclarationContext* structDeclaration();

  class  SpecifierQualifierListContext : public antlr4::ParserRuleContext {
  public:
    SpecifierQualifierListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TypeSpecifierContext *> typeSpecifier();
    TypeSpecifierContext* typeSpecifier(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SpecifierQualifierListContext* specifierQualifierList();

  class  StructDeclaratorListContext : public antlr4::ParserRuleContext {
  public:
    StructDeclaratorListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<StructDeclaratorContext *> structDeclarator();
    StructDeclaratorContext* structDeclarator(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StructDeclaratorListContext* structDeclaratorList();

  class  StructDeclaratorContext : public antlr4::ParserRuleContext {
  public:
    StructDeclaratorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DeclaratorContext *declarator();
    antlr4::tree::TerminalNode *Colon();
    ConstantExpressionContext *constantExpression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StructDeclaratorContext* structDeclarator();

  class  EnumSpecifierContext : public antlr4::ParserRuleContext {
  public:
    EnumSpecifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Enum();
    antlr4::tree::TerminalNode *LeftBrace();
    EnumeratorListContext *enumeratorList();
    antlr4::tree::TerminalNode *RightBrace();
    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *Comma();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EnumSpecifierContext* enumSpecifier();

  class  EnumeratorListContext : public antlr4::ParserRuleContext {
  public:
    EnumeratorListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<EnumeratorContext *> enumerator();
    EnumeratorContext* enumerator(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EnumeratorListContext* enumeratorList();

  class  EnumeratorContext : public antlr4::ParserRuleContext {
  public:
    EnumeratorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    EnumerationConstantContext *enumerationConstant();
    antlr4::tree::TerminalNode *Assign();
    ConstantExpressionContext *constantExpression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EnumeratorContext* enumerator();

  class  EnumerationConstantContext : public antlr4::ParserRuleContext {
  public:
    EnumerationConstantContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EnumerationConstantContext* enumerationConstant();

  class  FunctionSpecifierContext : public antlr4::ParserRuleContext {
  public:
    FunctionSpecifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Inline();
    antlr4::tree::TerminalNode *Noreturn();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionSpecifierContext* functionSpecifier();

  class  DeclaratorContext : public antlr4::ParserRuleContext {
  public:
    DeclaratorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DirectDeclaratorContext *directDeclarator();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DeclaratorContext* declarator();

  class  DirectDeclaratorContext : public antlr4::ParserRuleContext {
  public:
    DirectDeclaratorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *LeftParen();
    DeclaratorContext *declarator();
    antlr4::tree::TerminalNode *RightParen();
    DirectDeclaratorContext *directDeclarator();
    ParameterTypeListContext *parameterTypeList();
    IdentifierListContext *identifierList();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DirectDeclaratorContext* directDeclarator();
  DirectDeclaratorContext* directDeclarator(int precedence);
  class  ParameterTypeListContext : public antlr4::ParserRuleContext {
  public:
    ParameterTypeListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ParameterListContext *parameterList();
    antlr4::tree::TerminalNode *Comma();
    antlr4::tree::TerminalNode *Ellipsis();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParameterTypeListContext* parameterTypeList();

  class  ParameterListContext : public antlr4::ParserRuleContext {
  public:
    ParameterListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ParameterDeclarationContext *> parameterDeclaration();
    ParameterDeclarationContext* parameterDeclaration(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParameterListContext* parameterList();

  class  ParameterDeclarationContext : public antlr4::ParserRuleContext {
  public:
    ParameterDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DeclarationSpecifiersContext *declarationSpecifiers();
    DeclaratorContext *declarator();
    AbstractDeclaratorContext *abstractDeclarator();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParameterDeclarationContext* parameterDeclaration();

  class  IdentifierListContext : public antlr4::ParserRuleContext {
  public:
    IdentifierListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> Identifier();
    antlr4::tree::TerminalNode* Identifier(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IdentifierListContext* identifierList();

  class  TypeNameContext : public antlr4::ParserRuleContext {
  public:
    TypeNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SpecifierQualifierListContext *specifierQualifierList();
    AbstractDeclaratorContext *abstractDeclarator();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeNameContext* typeName();

  class  AbstractDeclaratorContext : public antlr4::ParserRuleContext {
  public:
    AbstractDeclaratorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DirectAbstractDeclaratorsContext *directAbstractDeclarators();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AbstractDeclaratorContext* abstractDeclarator();

  class  DirectAbstractDeclaratorsContext : public antlr4::ParserRuleContext {
  public:
    DirectAbstractDeclaratorsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<DirectAbstractDeclaratorContext *> directAbstractDeclarator();
    DirectAbstractDeclaratorContext* directAbstractDeclarator(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DirectAbstractDeclaratorsContext* directAbstractDeclarators();

  class  DirectAbstractDeclaratorContext : public antlr4::ParserRuleContext {
  public:
    DirectAbstractDeclaratorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LeftParen();
    AbstractDeclaratorContext *abstractDeclarator();
    antlr4::tree::TerminalNode *RightParen();
    antlr4::tree::TerminalNode *LeftBracket();
    antlr4::tree::TerminalNode *Star();
    antlr4::tree::TerminalNode *RightBracket();
    ParameterTypeListContext *parameterTypeList();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DirectAbstractDeclaratorContext* directAbstractDeclarator();

  class  TypedefNameContext : public antlr4::ParserRuleContext {
  public:
    TypedefNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypedefNameContext* typedefName();

  class  InitializerContext : public antlr4::ParserRuleContext {
  public:
    InitializerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AssignmentExpressionContext *assignmentExpression();
    antlr4::tree::TerminalNode *LeftBrace();
    InitializerListContext *initializerList();
    antlr4::tree::TerminalNode *RightBrace();
    antlr4::tree::TerminalNode *Comma();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InitializerContext* initializer();

  class  InitializerListContext : public antlr4::ParserRuleContext {
  public:
    InitializerListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<InitializerContext *> initializer();
    InitializerContext* initializer(size_t i);
    std::vector<DesignationContext *> designation();
    DesignationContext* designation(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InitializerListContext* initializerList();

  class  DesignationContext : public antlr4::ParserRuleContext {
  public:
    DesignationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DesignatorListContext *designatorList();
    antlr4::tree::TerminalNode *Assign();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DesignationContext* designation();

  class  DesignatorListContext : public antlr4::ParserRuleContext {
  public:
    DesignatorListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<DesignatorContext *> designator();
    DesignatorContext* designator(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DesignatorListContext* designatorList();

  class  DesignatorContext : public antlr4::ParserRuleContext {
  public:
    DesignatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LeftBracket();
    ConstantExpressionContext *constantExpression();
    antlr4::tree::TerminalNode *RightBracket();
    antlr4::tree::TerminalNode *Dot();
    antlr4::tree::TerminalNode *Identifier();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DesignatorContext* designator();

  class  StaticAssertDeclarationContext : public antlr4::ParserRuleContext {
  public:
    StaticAssertDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *StaticAssert();
    antlr4::tree::TerminalNode *LeftParen();
    ConstantExpressionContext *constantExpression();
    antlr4::tree::TerminalNode *Comma();
    antlr4::tree::TerminalNode *RightParen();
    antlr4::tree::TerminalNode *Semi();
    std::vector<antlr4::tree::TerminalNode *> StringLiteral();
    antlr4::tree::TerminalNode* StringLiteral(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StaticAssertDeclarationContext* staticAssertDeclaration();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LabeledStatementContext *labeledStatement();
    CompoundStatementContext *compoundStatement();
    ExpressionStatementContext *expressionStatement();
    SelectionStatementContext *selectionStatement();
    IterationStatementContext *iterationStatement();
    JumpStatementContext *jumpStatement();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementContext* statement();

  class  LabeledStatementContext : public antlr4::ParserRuleContext {
  public:
    LabeledStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *Colon();
    StatementContext *statement();
    antlr4::tree::TerminalNode *Case();
    ConstantExpressionContext *constantExpression();
    antlr4::tree::TerminalNode *Default();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LabeledStatementContext* labeledStatement();

  class  CompoundStatementContext : public antlr4::ParserRuleContext {
  public:
    CompoundStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LeftBrace();
    antlr4::tree::TerminalNode *RightBrace();
    std::vector<BlockItemContext *> blockItem();
    BlockItemContext* blockItem(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CompoundStatementContext* compoundStatement();

  class  BlockItemContext : public antlr4::ParserRuleContext {
  public:
    BlockItemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    StatementContext *statement();
    DeclarationContext *declaration();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BlockItemContext* blockItem();

  class  ExpressionStatementContext : public antlr4::ParserRuleContext {
  public:
    ExpressionStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Semi();
    ExpressionContext *expression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpressionStatementContext* expressionStatement();

  class  SelectionStatementContext : public antlr4::ParserRuleContext {
  public:
    SelectionStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *If();
    antlr4::tree::TerminalNode *LeftParen();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RightParen();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);
    antlr4::tree::TerminalNode *Else();
    antlr4::tree::TerminalNode *Switch();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SelectionStatementContext* selectionStatement();

  class  IterationStatementContext : public antlr4::ParserRuleContext {
  public:
    IterationStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *While();
    antlr4::tree::TerminalNode *LeftParen();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RightParen();
    StatementContext *statement();
    antlr4::tree::TerminalNode *Do();
    antlr4::tree::TerminalNode *Semi();
    antlr4::tree::TerminalNode *For();
    ForConditionContext *forCondition();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IterationStatementContext* iterationStatement();

  class  ForConditionContext : public antlr4::ParserRuleContext {
  public:
    ForConditionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> Semi();
    antlr4::tree::TerminalNode* Semi(size_t i);
    DeclarationContext *declaration();
    std::vector<ForExpressionContext *> forExpression();
    ForExpressionContext* forExpression(size_t i);
    ExpressionContext *expression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ForConditionContext* forCondition();

  class  ForExpressionContext : public antlr4::ParserRuleContext {
  public:
    ForExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<AssignmentExpressionContext *> assignmentExpression();
    AssignmentExpressionContext* assignmentExpression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ForExpressionContext* forExpression();

  class  JumpStatementContext : public antlr4::ParserRuleContext {
  public:
    JumpStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Semi();
    antlr4::tree::TerminalNode *Goto();
    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *Continue();
    antlr4::tree::TerminalNode *Break();
    antlr4::tree::TerminalNode *Return();
    ExpressionContext *expression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  JumpStatementContext* jumpStatement();

  class  CompilationUnitContext : public antlr4::ParserRuleContext {
  public:
    CompilationUnitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    TranslationUnitContext *translationUnit();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CompilationUnitContext* compilationUnit();

  class  TranslationUnitContext : public antlr4::ParserRuleContext {
  public:
    TranslationUnitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExternalDeclarationContext *> externalDeclaration();
    ExternalDeclarationContext* externalDeclaration(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TranslationUnitContext* translationUnit();

  class  ExternalDeclarationContext : public antlr4::ParserRuleContext {
  public:
    ExternalDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FunctionDefinitionContext *functionDefinition();
    DeclarationContext *declaration();
    antlr4::tree::TerminalNode *Semi();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExternalDeclarationContext* externalDeclaration();

  class  FunctionDefinitionContext : public antlr4::ParserRuleContext {
  public:
    FunctionDefinitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DeclaratorContext *declarator();
    CompoundStatementContext *compoundStatement();
    DeclarationSpecifiersContext *declarationSpecifiers();
    DeclarationListContext *declarationList();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionDefinitionContext* functionDefinition();

  class  DeclarationListContext : public antlr4::ParserRuleContext {
  public:
    DeclarationListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<DeclarationContext *> declaration();
    DeclarationContext* declaration(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DeclarationListContext* declarationList();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool directDeclaratorSempred(DirectDeclaratorContext *_localctx, size_t predicateIndex);

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

