
// Generated from C.g4 by ANTLR 4.9.2


#include "CVisitor.h"

#include "CParser.h"


using namespace antlrcpp;
using namespace antlr4;

CParser::CParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

CParser::~CParser() {
  delete _interpreter;
}

std::string CParser::getGrammarFileName() const {
  return "C.g4";
}

const std::vector<std::string>& CParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& CParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- PrimaryExpressionContext ------------------------------------------------------------------

CParser::PrimaryExpressionContext::PrimaryExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::IdentifierContext* CParser::PrimaryExpressionContext::identifier() {
  return getRuleContext<CParser::IdentifierContext>(0);
}

CParser::ConstantContext* CParser::PrimaryExpressionContext::constant() {
  return getRuleContext<CParser::ConstantContext>(0);
}

tree::TerminalNode* CParser::PrimaryExpressionContext::LeftParen() {
  return getToken(CParser::LeftParen, 0);
}

CParser::ExpressionContext* CParser::PrimaryExpressionContext::expression() {
  return getRuleContext<CParser::ExpressionContext>(0);
}

tree::TerminalNode* CParser::PrimaryExpressionContext::RightParen() {
  return getToken(CParser::RightParen, 0);
}


size_t CParser::PrimaryExpressionContext::getRuleIndex() const {
  return CParser::RulePrimaryExpression;
}


antlrcpp::Any CParser::PrimaryExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitPrimaryExpression(this);
  else
    return visitor->visitChildren(this);
}

CParser::PrimaryExpressionContext* CParser::primaryExpression() {
  PrimaryExpressionContext *_localctx = _tracker.createInstance<PrimaryExpressionContext>(_ctx, getState());
  enterRule(_localctx, 0, CParser::RulePrimaryExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(130);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(124);
        identifier();
        break;
      }

      case CParser::IntegerConstant:
      case CParser::CharacterConstant:
      case CParser::StringLiteral: {
        enterOuterAlt(_localctx, 2);
        setState(125);
        constant();
        break;
      }

      case CParser::LeftParen: {
        enterOuterAlt(_localctx, 3);
        setState(126);
        match(CParser::LeftParen);
        setState(127);
        expression();
        setState(128);
        match(CParser::RightParen);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdentifierContext ------------------------------------------------------------------

CParser::IdentifierContext::IdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::IdentifierContext::Identifier() {
  return getToken(CParser::Identifier, 0);
}


size_t CParser::IdentifierContext::getRuleIndex() const {
  return CParser::RuleIdentifier;
}


antlrcpp::Any CParser::IdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitIdentifier(this);
  else
    return visitor->visitChildren(this);
}

CParser::IdentifierContext* CParser::identifier() {
  IdentifierContext *_localctx = _tracker.createInstance<IdentifierContext>(_ctx, getState());
  enterRule(_localctx, 2, CParser::RuleIdentifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(132);
    match(CParser::Identifier);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstantContext ------------------------------------------------------------------

CParser::ConstantContext::ConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CParser::ConstantContext::getRuleIndex() const {
  return CParser::RuleConstant;
}

void CParser::ConstantContext::copyFrom(ConstantContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- StrConstContext ------------------------------------------------------------------

std::vector<tree::TerminalNode *> CParser::StrConstContext::StringLiteral() {
  return getTokens(CParser::StringLiteral);
}

tree::TerminalNode* CParser::StrConstContext::StringLiteral(size_t i) {
  return getToken(CParser::StringLiteral, i);
}

CParser::StrConstContext::StrConstContext(ConstantContext *ctx) { copyFrom(ctx); }


antlrcpp::Any CParser::StrConstContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitStrConst(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CharConstContext ------------------------------------------------------------------

tree::TerminalNode* CParser::CharConstContext::CharacterConstant() {
  return getToken(CParser::CharacterConstant, 0);
}

CParser::CharConstContext::CharConstContext(ConstantContext *ctx) { copyFrom(ctx); }


antlrcpp::Any CParser::CharConstContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitCharConst(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IntConstContext ------------------------------------------------------------------

tree::TerminalNode* CParser::IntConstContext::IntegerConstant() {
  return getToken(CParser::IntegerConstant, 0);
}

CParser::IntConstContext::IntConstContext(ConstantContext *ctx) { copyFrom(ctx); }


antlrcpp::Any CParser::IntConstContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitIntConst(this);
  else
    return visitor->visitChildren(this);
}
CParser::ConstantContext* CParser::constant() {
  ConstantContext *_localctx = _tracker.createInstance<ConstantContext>(_ctx, getState());
  enterRule(_localctx, 4, CParser::RuleConstant);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(141);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::IntegerConstant: {
        _localctx = dynamic_cast<ConstantContext *>(_tracker.createInstance<CParser::IntConstContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(134);
        match(CParser::IntegerConstant);
        break;
      }

      case CParser::CharacterConstant: {
        _localctx = dynamic_cast<ConstantContext *>(_tracker.createInstance<CParser::CharConstContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(135);
        match(CParser::CharacterConstant);
        break;
      }

      case CParser::StringLiteral: {
        _localctx = dynamic_cast<ConstantContext *>(_tracker.createInstance<CParser::StrConstContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(137); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(136);
          match(CParser::StringLiteral);
          setState(139); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while (_la == CParser::StringLiteral);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PostfixExpressionContext ------------------------------------------------------------------

CParser::PostfixExpressionContext::PostfixExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::PrimaryExpressionContext* CParser::PostfixExpressionContext::primaryExpression() {
  return getRuleContext<CParser::PrimaryExpressionContext>(0);
}

std::vector<tree::TerminalNode *> CParser::PostfixExpressionContext::LeftBracket() {
  return getTokens(CParser::LeftBracket);
}

tree::TerminalNode* CParser::PostfixExpressionContext::LeftBracket(size_t i) {
  return getToken(CParser::LeftBracket, i);
}

std::vector<CParser::ExpressionContext *> CParser::PostfixExpressionContext::expression() {
  return getRuleContexts<CParser::ExpressionContext>();
}

CParser::ExpressionContext* CParser::PostfixExpressionContext::expression(size_t i) {
  return getRuleContext<CParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> CParser::PostfixExpressionContext::RightBracket() {
  return getTokens(CParser::RightBracket);
}

tree::TerminalNode* CParser::PostfixExpressionContext::RightBracket(size_t i) {
  return getToken(CParser::RightBracket, i);
}

std::vector<tree::TerminalNode *> CParser::PostfixExpressionContext::LeftParen() {
  return getTokens(CParser::LeftParen);
}

tree::TerminalNode* CParser::PostfixExpressionContext::LeftParen(size_t i) {
  return getToken(CParser::LeftParen, i);
}

std::vector<tree::TerminalNode *> CParser::PostfixExpressionContext::RightParen() {
  return getTokens(CParser::RightParen);
}

tree::TerminalNode* CParser::PostfixExpressionContext::RightParen(size_t i) {
  return getToken(CParser::RightParen, i);
}

std::vector<CParser::ArgumentExpressionListContext *> CParser::PostfixExpressionContext::argumentExpressionList() {
  return getRuleContexts<CParser::ArgumentExpressionListContext>();
}

CParser::ArgumentExpressionListContext* CParser::PostfixExpressionContext::argumentExpressionList(size_t i) {
  return getRuleContext<CParser::ArgumentExpressionListContext>(i);
}


size_t CParser::PostfixExpressionContext::getRuleIndex() const {
  return CParser::RulePostfixExpression;
}


antlrcpp::Any CParser::PostfixExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitPostfixExpression(this);
  else
    return visitor->visitChildren(this);
}

CParser::PostfixExpressionContext* CParser::postfixExpression() {
  PostfixExpressionContext *_localctx = _tracker.createInstance<PostfixExpressionContext>(_ctx, getState());
  enterRule(_localctx, 6, CParser::RulePostfixExpression);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(143);
    primaryExpression();
    setState(155);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CParser::LeftParen

    || _la == CParser::LeftBracket) {
      setState(153);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case CParser::LeftBracket: {
          setState(144);
          match(CParser::LeftBracket);
          setState(145);
          expression();
          setState(146);
          match(CParser::RightBracket);
          break;
        }

        case CParser::LeftParen: {
          setState(148);
          match(CParser::LeftParen);
          setState(150);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << CParser::Sizeof)
            | (1ULL << CParser::LeftParen)
            | (1ULL << CParser::Plus)
            | (1ULL << CParser::PlusPlus)
            | (1ULL << CParser::Minus)
            | (1ULL << CParser::MinusMinus)
            | (1ULL << CParser::Star))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 64)) & ((1ULL << (CParser::And - 64))
            | (1ULL << (CParser::Not - 64))
            | (1ULL << (CParser::Tilde - 64))
            | (1ULL << (CParser::Identifier - 64))
            | (1ULL << (CParser::IntegerConstant - 64))
            | (1ULL << (CParser::CharacterConstant - 64))
            | (1ULL << (CParser::StringLiteral - 64)))) != 0)) {
            setState(149);
            argumentExpressionList();
          }
          setState(152);
          match(CParser::RightParen);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(157);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentExpressionListContext ------------------------------------------------------------------

CParser::ArgumentExpressionListContext::ArgumentExpressionListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CParser::AssignmentExpressionContext *> CParser::ArgumentExpressionListContext::assignmentExpression() {
  return getRuleContexts<CParser::AssignmentExpressionContext>();
}

CParser::AssignmentExpressionContext* CParser::ArgumentExpressionListContext::assignmentExpression(size_t i) {
  return getRuleContext<CParser::AssignmentExpressionContext>(i);
}

std::vector<tree::TerminalNode *> CParser::ArgumentExpressionListContext::Comma() {
  return getTokens(CParser::Comma);
}

tree::TerminalNode* CParser::ArgumentExpressionListContext::Comma(size_t i) {
  return getToken(CParser::Comma, i);
}


size_t CParser::ArgumentExpressionListContext::getRuleIndex() const {
  return CParser::RuleArgumentExpressionList;
}


antlrcpp::Any CParser::ArgumentExpressionListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitArgumentExpressionList(this);
  else
    return visitor->visitChildren(this);
}

CParser::ArgumentExpressionListContext* CParser::argumentExpressionList() {
  ArgumentExpressionListContext *_localctx = _tracker.createInstance<ArgumentExpressionListContext>(_ctx, getState());
  enterRule(_localctx, 8, CParser::RuleArgumentExpressionList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(158);
    assignmentExpression();
    setState(163);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CParser::Comma) {
      setState(159);
      match(CParser::Comma);
      setState(160);
      assignmentExpression();
      setState(165);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnaryExpressionContext ------------------------------------------------------------------

CParser::UnaryExpressionContext::UnaryExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::PostfixExpressionContext* CParser::UnaryExpressionContext::postfixExpression() {
  return getRuleContext<CParser::PostfixExpressionContext>(0);
}

CParser::UnaryOperatorContext* CParser::UnaryExpressionContext::unaryOperator() {
  return getRuleContext<CParser::UnaryOperatorContext>(0);
}

CParser::UnaryExpressionContext* CParser::UnaryExpressionContext::unaryExpression() {
  return getRuleContext<CParser::UnaryExpressionContext>(0);
}

std::vector<CParser::PrefixOperatorContext *> CParser::UnaryExpressionContext::prefixOperator() {
  return getRuleContexts<CParser::PrefixOperatorContext>();
}

CParser::PrefixOperatorContext* CParser::UnaryExpressionContext::prefixOperator(size_t i) {
  return getRuleContext<CParser::PrefixOperatorContext>(i);
}


size_t CParser::UnaryExpressionContext::getRuleIndex() const {
  return CParser::RuleUnaryExpression;
}


antlrcpp::Any CParser::UnaryExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitUnaryExpression(this);
  else
    return visitor->visitChildren(this);
}

CParser::UnaryExpressionContext* CParser::unaryExpression() {
  UnaryExpressionContext *_localctx = _tracker.createInstance<UnaryExpressionContext>(_ctx, getState());
  enterRule(_localctx, 10, CParser::RuleUnaryExpression);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(169);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CParser::Sizeof)
      | (1ULL << CParser::PlusPlus)
      | (1ULL << CParser::MinusMinus))) != 0)) {
      setState(166);
      prefixOperator();
      setState(171);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(176);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::LeftParen:
      case CParser::Identifier:
      case CParser::IntegerConstant:
      case CParser::CharacterConstant:
      case CParser::StringLiteral: {
        setState(172);
        postfixExpression();
        break;
      }

      case CParser::Plus:
      case CParser::Minus:
      case CParser::Star:
      case CParser::And:
      case CParser::Not:
      case CParser::Tilde: {
        setState(173);
        unaryOperator();
        setState(174);
        unaryExpression();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrefixOperatorContext ------------------------------------------------------------------

CParser::PrefixOperatorContext::PrefixOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::PrefixOperatorContext::PlusPlus() {
  return getToken(CParser::PlusPlus, 0);
}

tree::TerminalNode* CParser::PrefixOperatorContext::MinusMinus() {
  return getToken(CParser::MinusMinus, 0);
}

tree::TerminalNode* CParser::PrefixOperatorContext::Sizeof() {
  return getToken(CParser::Sizeof, 0);
}


size_t CParser::PrefixOperatorContext::getRuleIndex() const {
  return CParser::RulePrefixOperator;
}


antlrcpp::Any CParser::PrefixOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitPrefixOperator(this);
  else
    return visitor->visitChildren(this);
}

CParser::PrefixOperatorContext* CParser::prefixOperator() {
  PrefixOperatorContext *_localctx = _tracker.createInstance<PrefixOperatorContext>(_ctx, getState());
  enterRule(_localctx, 12, CParser::RulePrefixOperator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(178);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CParser::Sizeof)
      | (1ULL << CParser::PlusPlus)
      | (1ULL << CParser::MinusMinus))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnaryOperatorContext ------------------------------------------------------------------

CParser::UnaryOperatorContext::UnaryOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::UnaryOperatorContext::And() {
  return getToken(CParser::And, 0);
}

tree::TerminalNode* CParser::UnaryOperatorContext::Star() {
  return getToken(CParser::Star, 0);
}

tree::TerminalNode* CParser::UnaryOperatorContext::Plus() {
  return getToken(CParser::Plus, 0);
}

tree::TerminalNode* CParser::UnaryOperatorContext::Minus() {
  return getToken(CParser::Minus, 0);
}

tree::TerminalNode* CParser::UnaryOperatorContext::Tilde() {
  return getToken(CParser::Tilde, 0);
}

tree::TerminalNode* CParser::UnaryOperatorContext::Not() {
  return getToken(CParser::Not, 0);
}


size_t CParser::UnaryOperatorContext::getRuleIndex() const {
  return CParser::RuleUnaryOperator;
}


antlrcpp::Any CParser::UnaryOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitUnaryOperator(this);
  else
    return visitor->visitChildren(this);
}

CParser::UnaryOperatorContext* CParser::unaryOperator() {
  UnaryOperatorContext *_localctx = _tracker.createInstance<UnaryOperatorContext>(_ctx, getState());
  enterRule(_localctx, 14, CParser::RuleUnaryOperator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(180);
    _la = _input->LA(1);
    if (!(((((_la - 57) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 57)) & ((1ULL << (CParser::Plus - 57))
      | (1ULL << (CParser::Minus - 57))
      | (1ULL << (CParser::Star - 57))
      | (1ULL << (CParser::And - 57))
      | (1ULL << (CParser::Not - 57))
      | (1ULL << (CParser::Tilde - 57)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CastExpressionContext ------------------------------------------------------------------

CParser::CastExpressionContext::CastExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::UnaryExpressionContext* CParser::CastExpressionContext::unaryExpression() {
  return getRuleContext<CParser::UnaryExpressionContext>(0);
}

tree::TerminalNode* CParser::CastExpressionContext::LeftParen() {
  return getToken(CParser::LeftParen, 0);
}

CParser::TypeNameContext* CParser::CastExpressionContext::typeName() {
  return getRuleContext<CParser::TypeNameContext>(0);
}

tree::TerminalNode* CParser::CastExpressionContext::RightParen() {
  return getToken(CParser::RightParen, 0);
}

CParser::CastExpressionContext* CParser::CastExpressionContext::castExpression() {
  return getRuleContext<CParser::CastExpressionContext>(0);
}

std::vector<CParser::PointerContext *> CParser::CastExpressionContext::pointer() {
  return getRuleContexts<CParser::PointerContext>();
}

CParser::PointerContext* CParser::CastExpressionContext::pointer(size_t i) {
  return getRuleContext<CParser::PointerContext>(i);
}


size_t CParser::CastExpressionContext::getRuleIndex() const {
  return CParser::RuleCastExpression;
}


antlrcpp::Any CParser::CastExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitCastExpression(this);
  else
    return visitor->visitChildren(this);
}

CParser::CastExpressionContext* CParser::castExpression() {
  CastExpressionContext *_localctx = _tracker.createInstance<CastExpressionContext>(_ctx, getState());
  enterRule(_localctx, 16, CParser::RuleCastExpression);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(194);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(182);
      unaryExpression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(183);
      match(CParser::LeftParen);
      setState(184);
      typeName();
      setState(188);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == CParser::Star) {
        setState(185);
        pointer();
        setState(190);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(191);
      match(CParser::RightParen);
      setState(192);
      castExpression();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MultiplicativeExpressionContext ------------------------------------------------------------------

CParser::MultiplicativeExpressionContext::MultiplicativeExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CParser::CastExpressionContext *> CParser::MultiplicativeExpressionContext::castExpression() {
  return getRuleContexts<CParser::CastExpressionContext>();
}

CParser::CastExpressionContext* CParser::MultiplicativeExpressionContext::castExpression(size_t i) {
  return getRuleContext<CParser::CastExpressionContext>(i);
}

std::vector<CParser::MultiplicativeOperatorContext *> CParser::MultiplicativeExpressionContext::multiplicativeOperator() {
  return getRuleContexts<CParser::MultiplicativeOperatorContext>();
}

CParser::MultiplicativeOperatorContext* CParser::MultiplicativeExpressionContext::multiplicativeOperator(size_t i) {
  return getRuleContext<CParser::MultiplicativeOperatorContext>(i);
}


size_t CParser::MultiplicativeExpressionContext::getRuleIndex() const {
  return CParser::RuleMultiplicativeExpression;
}


antlrcpp::Any CParser::MultiplicativeExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitMultiplicativeExpression(this);
  else
    return visitor->visitChildren(this);
}

CParser::MultiplicativeExpressionContext* CParser::multiplicativeExpression() {
  MultiplicativeExpressionContext *_localctx = _tracker.createInstance<MultiplicativeExpressionContext>(_ctx, getState());
  enterRule(_localctx, 18, CParser::RuleMultiplicativeExpression);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(196);
    castExpression();
    setState(202);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CParser::Star)
      | (1ULL << CParser::Div)
      | (1ULL << CParser::Mod))) != 0)) {
      setState(197);
      multiplicativeOperator();
      setState(198);
      castExpression();
      setState(204);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MultiplicativeOperatorContext ------------------------------------------------------------------

CParser::MultiplicativeOperatorContext::MultiplicativeOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::MultiplicativeOperatorContext::Star() {
  return getToken(CParser::Star, 0);
}

tree::TerminalNode* CParser::MultiplicativeOperatorContext::Div() {
  return getToken(CParser::Div, 0);
}

tree::TerminalNode* CParser::MultiplicativeOperatorContext::Mod() {
  return getToken(CParser::Mod, 0);
}


size_t CParser::MultiplicativeOperatorContext::getRuleIndex() const {
  return CParser::RuleMultiplicativeOperator;
}


antlrcpp::Any CParser::MultiplicativeOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitMultiplicativeOperator(this);
  else
    return visitor->visitChildren(this);
}

CParser::MultiplicativeOperatorContext* CParser::multiplicativeOperator() {
  MultiplicativeOperatorContext *_localctx = _tracker.createInstance<MultiplicativeOperatorContext>(_ctx, getState());
  enterRule(_localctx, 20, CParser::RuleMultiplicativeOperator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(205);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CParser::Star)
      | (1ULL << CParser::Div)
      | (1ULL << CParser::Mod))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AdditiveExpressionContext ------------------------------------------------------------------

CParser::AdditiveExpressionContext::AdditiveExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CParser::MultiplicativeExpressionContext *> CParser::AdditiveExpressionContext::multiplicativeExpression() {
  return getRuleContexts<CParser::MultiplicativeExpressionContext>();
}

CParser::MultiplicativeExpressionContext* CParser::AdditiveExpressionContext::multiplicativeExpression(size_t i) {
  return getRuleContext<CParser::MultiplicativeExpressionContext>(i);
}

std::vector<CParser::AdditiveOperatorContext *> CParser::AdditiveExpressionContext::additiveOperator() {
  return getRuleContexts<CParser::AdditiveOperatorContext>();
}

CParser::AdditiveOperatorContext* CParser::AdditiveExpressionContext::additiveOperator(size_t i) {
  return getRuleContext<CParser::AdditiveOperatorContext>(i);
}


size_t CParser::AdditiveExpressionContext::getRuleIndex() const {
  return CParser::RuleAdditiveExpression;
}


antlrcpp::Any CParser::AdditiveExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitAdditiveExpression(this);
  else
    return visitor->visitChildren(this);
}

CParser::AdditiveExpressionContext* CParser::additiveExpression() {
  AdditiveExpressionContext *_localctx = _tracker.createInstance<AdditiveExpressionContext>(_ctx, getState());
  enterRule(_localctx, 22, CParser::RuleAdditiveExpression);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(207);
    multiplicativeExpression();
    setState(213);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CParser::Plus

    || _la == CParser::Minus) {
      setState(208);
      additiveOperator();
      setState(209);
      multiplicativeExpression();
      setState(215);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AdditiveOperatorContext ------------------------------------------------------------------

CParser::AdditiveOperatorContext::AdditiveOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::AdditiveOperatorContext::Plus() {
  return getToken(CParser::Plus, 0);
}

tree::TerminalNode* CParser::AdditiveOperatorContext::Minus() {
  return getToken(CParser::Minus, 0);
}


size_t CParser::AdditiveOperatorContext::getRuleIndex() const {
  return CParser::RuleAdditiveOperator;
}


antlrcpp::Any CParser::AdditiveOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitAdditiveOperator(this);
  else
    return visitor->visitChildren(this);
}

CParser::AdditiveOperatorContext* CParser::additiveOperator() {
  AdditiveOperatorContext *_localctx = _tracker.createInstance<AdditiveOperatorContext>(_ctx, getState());
  enterRule(_localctx, 24, CParser::RuleAdditiveOperator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(216);
    _la = _input->LA(1);
    if (!(_la == CParser::Plus

    || _la == CParser::Minus)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ShiftExpressionContext ------------------------------------------------------------------

CParser::ShiftExpressionContext::ShiftExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CParser::AdditiveExpressionContext *> CParser::ShiftExpressionContext::additiveExpression() {
  return getRuleContexts<CParser::AdditiveExpressionContext>();
}

CParser::AdditiveExpressionContext* CParser::ShiftExpressionContext::additiveExpression(size_t i) {
  return getRuleContext<CParser::AdditiveExpressionContext>(i);
}

std::vector<CParser::ShiftOperatorContext *> CParser::ShiftExpressionContext::shiftOperator() {
  return getRuleContexts<CParser::ShiftOperatorContext>();
}

CParser::ShiftOperatorContext* CParser::ShiftExpressionContext::shiftOperator(size_t i) {
  return getRuleContext<CParser::ShiftOperatorContext>(i);
}


size_t CParser::ShiftExpressionContext::getRuleIndex() const {
  return CParser::RuleShiftExpression;
}


antlrcpp::Any CParser::ShiftExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitShiftExpression(this);
  else
    return visitor->visitChildren(this);
}

CParser::ShiftExpressionContext* CParser::shiftExpression() {
  ShiftExpressionContext *_localctx = _tracker.createInstance<ShiftExpressionContext>(_ctx, getState());
  enterRule(_localctx, 26, CParser::RuleShiftExpression);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(218);
    additiveExpression();
    setState(224);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CParser::LeftShift

    || _la == CParser::RightShift) {
      setState(219);
      shiftOperator();
      setState(220);
      additiveExpression();
      setState(226);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ShiftOperatorContext ------------------------------------------------------------------

CParser::ShiftOperatorContext::ShiftOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::ShiftOperatorContext::LeftShift() {
  return getToken(CParser::LeftShift, 0);
}

tree::TerminalNode* CParser::ShiftOperatorContext::RightShift() {
  return getToken(CParser::RightShift, 0);
}


size_t CParser::ShiftOperatorContext::getRuleIndex() const {
  return CParser::RuleShiftOperator;
}


antlrcpp::Any CParser::ShiftOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitShiftOperator(this);
  else
    return visitor->visitChildren(this);
}

CParser::ShiftOperatorContext* CParser::shiftOperator() {
  ShiftOperatorContext *_localctx = _tracker.createInstance<ShiftOperatorContext>(_ctx, getState());
  enterRule(_localctx, 28, CParser::RuleShiftOperator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(227);
    _la = _input->LA(1);
    if (!(_la == CParser::LeftShift

    || _la == CParser::RightShift)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelationalExpressionContext ------------------------------------------------------------------

CParser::RelationalExpressionContext::RelationalExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CParser::ShiftExpressionContext *> CParser::RelationalExpressionContext::shiftExpression() {
  return getRuleContexts<CParser::ShiftExpressionContext>();
}

CParser::ShiftExpressionContext* CParser::RelationalExpressionContext::shiftExpression(size_t i) {
  return getRuleContext<CParser::ShiftExpressionContext>(i);
}

std::vector<CParser::RelationalOperatorContext *> CParser::RelationalExpressionContext::relationalOperator() {
  return getRuleContexts<CParser::RelationalOperatorContext>();
}

CParser::RelationalOperatorContext* CParser::RelationalExpressionContext::relationalOperator(size_t i) {
  return getRuleContext<CParser::RelationalOperatorContext>(i);
}


size_t CParser::RelationalExpressionContext::getRuleIndex() const {
  return CParser::RuleRelationalExpression;
}


antlrcpp::Any CParser::RelationalExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitRelationalExpression(this);
  else
    return visitor->visitChildren(this);
}

CParser::RelationalExpressionContext* CParser::relationalExpression() {
  RelationalExpressionContext *_localctx = _tracker.createInstance<RelationalExpressionContext>(_ctx, getState());
  enterRule(_localctx, 30, CParser::RuleRelationalExpression);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(229);
    shiftExpression();
    setState(235);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CParser::Less)
      | (1ULL << CParser::LessEqual)
      | (1ULL << CParser::Greater)
      | (1ULL << CParser::GreaterEqual))) != 0)) {
      setState(230);
      relationalOperator();
      setState(231);
      shiftExpression();
      setState(237);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelationalOperatorContext ------------------------------------------------------------------

CParser::RelationalOperatorContext::RelationalOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::RelationalOperatorContext::Less() {
  return getToken(CParser::Less, 0);
}

tree::TerminalNode* CParser::RelationalOperatorContext::Greater() {
  return getToken(CParser::Greater, 0);
}

tree::TerminalNode* CParser::RelationalOperatorContext::LessEqual() {
  return getToken(CParser::LessEqual, 0);
}

tree::TerminalNode* CParser::RelationalOperatorContext::GreaterEqual() {
  return getToken(CParser::GreaterEqual, 0);
}


size_t CParser::RelationalOperatorContext::getRuleIndex() const {
  return CParser::RuleRelationalOperator;
}


antlrcpp::Any CParser::RelationalOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitRelationalOperator(this);
  else
    return visitor->visitChildren(this);
}

CParser::RelationalOperatorContext* CParser::relationalOperator() {
  RelationalOperatorContext *_localctx = _tracker.createInstance<RelationalOperatorContext>(_ctx, getState());
  enterRule(_localctx, 32, CParser::RuleRelationalOperator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(238);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CParser::Less)
      | (1ULL << CParser::LessEqual)
      | (1ULL << CParser::Greater)
      | (1ULL << CParser::GreaterEqual))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EqualityExpressionContext ------------------------------------------------------------------

CParser::EqualityExpressionContext::EqualityExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CParser::RelationalExpressionContext *> CParser::EqualityExpressionContext::relationalExpression() {
  return getRuleContexts<CParser::RelationalExpressionContext>();
}

CParser::RelationalExpressionContext* CParser::EqualityExpressionContext::relationalExpression(size_t i) {
  return getRuleContext<CParser::RelationalExpressionContext>(i);
}

std::vector<CParser::EqualityOperatorContext *> CParser::EqualityExpressionContext::equalityOperator() {
  return getRuleContexts<CParser::EqualityOperatorContext>();
}

CParser::EqualityOperatorContext* CParser::EqualityExpressionContext::equalityOperator(size_t i) {
  return getRuleContext<CParser::EqualityOperatorContext>(i);
}


size_t CParser::EqualityExpressionContext::getRuleIndex() const {
  return CParser::RuleEqualityExpression;
}


antlrcpp::Any CParser::EqualityExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitEqualityExpression(this);
  else
    return visitor->visitChildren(this);
}

CParser::EqualityExpressionContext* CParser::equalityExpression() {
  EqualityExpressionContext *_localctx = _tracker.createInstance<EqualityExpressionContext>(_ctx, getState());
  enterRule(_localctx, 34, CParser::RuleEqualityExpression);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(240);
    relationalExpression();
    setState(246);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CParser::Equal

    || _la == CParser::NotEqual) {
      setState(241);
      equalityOperator();
      setState(242);
      relationalExpression();
      setState(248);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EqualityOperatorContext ------------------------------------------------------------------

CParser::EqualityOperatorContext::EqualityOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::EqualityOperatorContext::Equal() {
  return getToken(CParser::Equal, 0);
}

tree::TerminalNode* CParser::EqualityOperatorContext::NotEqual() {
  return getToken(CParser::NotEqual, 0);
}


size_t CParser::EqualityOperatorContext::getRuleIndex() const {
  return CParser::RuleEqualityOperator;
}


antlrcpp::Any CParser::EqualityOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitEqualityOperator(this);
  else
    return visitor->visitChildren(this);
}

CParser::EqualityOperatorContext* CParser::equalityOperator() {
  EqualityOperatorContext *_localctx = _tracker.createInstance<EqualityOperatorContext>(_ctx, getState());
  enterRule(_localctx, 36, CParser::RuleEqualityOperator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(249);
    _la = _input->LA(1);
    if (!(_la == CParser::Equal

    || _la == CParser::NotEqual)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AndExpressionContext ------------------------------------------------------------------

CParser::AndExpressionContext::AndExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CParser::EqualityExpressionContext *> CParser::AndExpressionContext::equalityExpression() {
  return getRuleContexts<CParser::EqualityExpressionContext>();
}

CParser::EqualityExpressionContext* CParser::AndExpressionContext::equalityExpression(size_t i) {
  return getRuleContext<CParser::EqualityExpressionContext>(i);
}

std::vector<CParser::AndOperatorContext *> CParser::AndExpressionContext::andOperator() {
  return getRuleContexts<CParser::AndOperatorContext>();
}

CParser::AndOperatorContext* CParser::AndExpressionContext::andOperator(size_t i) {
  return getRuleContext<CParser::AndOperatorContext>(i);
}


size_t CParser::AndExpressionContext::getRuleIndex() const {
  return CParser::RuleAndExpression;
}


antlrcpp::Any CParser::AndExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitAndExpression(this);
  else
    return visitor->visitChildren(this);
}

CParser::AndExpressionContext* CParser::andExpression() {
  AndExpressionContext *_localctx = _tracker.createInstance<AndExpressionContext>(_ctx, getState());
  enterRule(_localctx, 38, CParser::RuleAndExpression);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(251);
    equalityExpression();
    setState(257);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CParser::And) {
      setState(252);
      andOperator();
      setState(253);
      equalityExpression();
      setState(259);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AndOperatorContext ------------------------------------------------------------------

CParser::AndOperatorContext::AndOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::AndOperatorContext::And() {
  return getToken(CParser::And, 0);
}


size_t CParser::AndOperatorContext::getRuleIndex() const {
  return CParser::RuleAndOperator;
}


antlrcpp::Any CParser::AndOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitAndOperator(this);
  else
    return visitor->visitChildren(this);
}

CParser::AndOperatorContext* CParser::andOperator() {
  AndOperatorContext *_localctx = _tracker.createInstance<AndOperatorContext>(_ctx, getState());
  enterRule(_localctx, 40, CParser::RuleAndOperator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(260);
    match(CParser::And);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExclusiveOrExpressionContext ------------------------------------------------------------------

CParser::ExclusiveOrExpressionContext::ExclusiveOrExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CParser::AndExpressionContext *> CParser::ExclusiveOrExpressionContext::andExpression() {
  return getRuleContexts<CParser::AndExpressionContext>();
}

CParser::AndExpressionContext* CParser::ExclusiveOrExpressionContext::andExpression(size_t i) {
  return getRuleContext<CParser::AndExpressionContext>(i);
}

std::vector<CParser::ExclusiveOrOperatorContext *> CParser::ExclusiveOrExpressionContext::exclusiveOrOperator() {
  return getRuleContexts<CParser::ExclusiveOrOperatorContext>();
}

CParser::ExclusiveOrOperatorContext* CParser::ExclusiveOrExpressionContext::exclusiveOrOperator(size_t i) {
  return getRuleContext<CParser::ExclusiveOrOperatorContext>(i);
}


size_t CParser::ExclusiveOrExpressionContext::getRuleIndex() const {
  return CParser::RuleExclusiveOrExpression;
}


antlrcpp::Any CParser::ExclusiveOrExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitExclusiveOrExpression(this);
  else
    return visitor->visitChildren(this);
}

CParser::ExclusiveOrExpressionContext* CParser::exclusiveOrExpression() {
  ExclusiveOrExpressionContext *_localctx = _tracker.createInstance<ExclusiveOrExpressionContext>(_ctx, getState());
  enterRule(_localctx, 42, CParser::RuleExclusiveOrExpression);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(262);
    andExpression();
    setState(268);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CParser::Caret) {
      setState(263);
      exclusiveOrOperator();
      setState(264);
      andExpression();
      setState(270);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExclusiveOrOperatorContext ------------------------------------------------------------------

CParser::ExclusiveOrOperatorContext::ExclusiveOrOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::ExclusiveOrOperatorContext::Caret() {
  return getToken(CParser::Caret, 0);
}


size_t CParser::ExclusiveOrOperatorContext::getRuleIndex() const {
  return CParser::RuleExclusiveOrOperator;
}


antlrcpp::Any CParser::ExclusiveOrOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitExclusiveOrOperator(this);
  else
    return visitor->visitChildren(this);
}

CParser::ExclusiveOrOperatorContext* CParser::exclusiveOrOperator() {
  ExclusiveOrOperatorContext *_localctx = _tracker.createInstance<ExclusiveOrOperatorContext>(_ctx, getState());
  enterRule(_localctx, 44, CParser::RuleExclusiveOrOperator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(271);
    match(CParser::Caret);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InclusiveOrExpressionContext ------------------------------------------------------------------

CParser::InclusiveOrExpressionContext::InclusiveOrExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CParser::ExclusiveOrExpressionContext *> CParser::InclusiveOrExpressionContext::exclusiveOrExpression() {
  return getRuleContexts<CParser::ExclusiveOrExpressionContext>();
}

CParser::ExclusiveOrExpressionContext* CParser::InclusiveOrExpressionContext::exclusiveOrExpression(size_t i) {
  return getRuleContext<CParser::ExclusiveOrExpressionContext>(i);
}

std::vector<CParser::InclusiveOrOperatorContext *> CParser::InclusiveOrExpressionContext::inclusiveOrOperator() {
  return getRuleContexts<CParser::InclusiveOrOperatorContext>();
}

CParser::InclusiveOrOperatorContext* CParser::InclusiveOrExpressionContext::inclusiveOrOperator(size_t i) {
  return getRuleContext<CParser::InclusiveOrOperatorContext>(i);
}


size_t CParser::InclusiveOrExpressionContext::getRuleIndex() const {
  return CParser::RuleInclusiveOrExpression;
}


antlrcpp::Any CParser::InclusiveOrExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitInclusiveOrExpression(this);
  else
    return visitor->visitChildren(this);
}

CParser::InclusiveOrExpressionContext* CParser::inclusiveOrExpression() {
  InclusiveOrExpressionContext *_localctx = _tracker.createInstance<InclusiveOrExpressionContext>(_ctx, getState());
  enterRule(_localctx, 46, CParser::RuleInclusiveOrExpression);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(273);
    exclusiveOrExpression();
    setState(279);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CParser::Or) {
      setState(274);
      inclusiveOrOperator();
      setState(275);
      exclusiveOrExpression();
      setState(281);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InclusiveOrOperatorContext ------------------------------------------------------------------

CParser::InclusiveOrOperatorContext::InclusiveOrOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::InclusiveOrOperatorContext::Or() {
  return getToken(CParser::Or, 0);
}


size_t CParser::InclusiveOrOperatorContext::getRuleIndex() const {
  return CParser::RuleInclusiveOrOperator;
}


antlrcpp::Any CParser::InclusiveOrOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitInclusiveOrOperator(this);
  else
    return visitor->visitChildren(this);
}

CParser::InclusiveOrOperatorContext* CParser::inclusiveOrOperator() {
  InclusiveOrOperatorContext *_localctx = _tracker.createInstance<InclusiveOrOperatorContext>(_ctx, getState());
  enterRule(_localctx, 48, CParser::RuleInclusiveOrOperator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(282);
    match(CParser::Or);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LogicalAndExpressionContext ------------------------------------------------------------------

CParser::LogicalAndExpressionContext::LogicalAndExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CParser::InclusiveOrExpressionContext *> CParser::LogicalAndExpressionContext::inclusiveOrExpression() {
  return getRuleContexts<CParser::InclusiveOrExpressionContext>();
}

CParser::InclusiveOrExpressionContext* CParser::LogicalAndExpressionContext::inclusiveOrExpression(size_t i) {
  return getRuleContext<CParser::InclusiveOrExpressionContext>(i);
}

std::vector<CParser::LogicalAndOperatorContext *> CParser::LogicalAndExpressionContext::logicalAndOperator() {
  return getRuleContexts<CParser::LogicalAndOperatorContext>();
}

CParser::LogicalAndOperatorContext* CParser::LogicalAndExpressionContext::logicalAndOperator(size_t i) {
  return getRuleContext<CParser::LogicalAndOperatorContext>(i);
}


size_t CParser::LogicalAndExpressionContext::getRuleIndex() const {
  return CParser::RuleLogicalAndExpression;
}


antlrcpp::Any CParser::LogicalAndExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitLogicalAndExpression(this);
  else
    return visitor->visitChildren(this);
}

CParser::LogicalAndExpressionContext* CParser::logicalAndExpression() {
  LogicalAndExpressionContext *_localctx = _tracker.createInstance<LogicalAndExpressionContext>(_ctx, getState());
  enterRule(_localctx, 50, CParser::RuleLogicalAndExpression);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(284);
    inclusiveOrExpression();
    setState(290);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CParser::AndAnd) {
      setState(285);
      logicalAndOperator();
      setState(286);
      inclusiveOrExpression();
      setState(292);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LogicalAndOperatorContext ------------------------------------------------------------------

CParser::LogicalAndOperatorContext::LogicalAndOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::LogicalAndOperatorContext::AndAnd() {
  return getToken(CParser::AndAnd, 0);
}


size_t CParser::LogicalAndOperatorContext::getRuleIndex() const {
  return CParser::RuleLogicalAndOperator;
}


antlrcpp::Any CParser::LogicalAndOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitLogicalAndOperator(this);
  else
    return visitor->visitChildren(this);
}

CParser::LogicalAndOperatorContext* CParser::logicalAndOperator() {
  LogicalAndOperatorContext *_localctx = _tracker.createInstance<LogicalAndOperatorContext>(_ctx, getState());
  enterRule(_localctx, 52, CParser::RuleLogicalAndOperator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(293);
    match(CParser::AndAnd);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LogicalOrExpressionContext ------------------------------------------------------------------

CParser::LogicalOrExpressionContext::LogicalOrExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CParser::LogicalAndExpressionContext *> CParser::LogicalOrExpressionContext::logicalAndExpression() {
  return getRuleContexts<CParser::LogicalAndExpressionContext>();
}

CParser::LogicalAndExpressionContext* CParser::LogicalOrExpressionContext::logicalAndExpression(size_t i) {
  return getRuleContext<CParser::LogicalAndExpressionContext>(i);
}

std::vector<CParser::LogicalOrOperatorContext *> CParser::LogicalOrExpressionContext::logicalOrOperator() {
  return getRuleContexts<CParser::LogicalOrOperatorContext>();
}

CParser::LogicalOrOperatorContext* CParser::LogicalOrExpressionContext::logicalOrOperator(size_t i) {
  return getRuleContext<CParser::LogicalOrOperatorContext>(i);
}


size_t CParser::LogicalOrExpressionContext::getRuleIndex() const {
  return CParser::RuleLogicalOrExpression;
}


antlrcpp::Any CParser::LogicalOrExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitLogicalOrExpression(this);
  else
    return visitor->visitChildren(this);
}

CParser::LogicalOrExpressionContext* CParser::logicalOrExpression() {
  LogicalOrExpressionContext *_localctx = _tracker.createInstance<LogicalOrExpressionContext>(_ctx, getState());
  enterRule(_localctx, 54, CParser::RuleLogicalOrExpression);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(295);
    logicalAndExpression();
    setState(301);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CParser::OrOr) {
      setState(296);
      logicalOrOperator();
      setState(297);
      logicalAndExpression();
      setState(303);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LogicalOrOperatorContext ------------------------------------------------------------------

CParser::LogicalOrOperatorContext::LogicalOrOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::LogicalOrOperatorContext::OrOr() {
  return getToken(CParser::OrOr, 0);
}


size_t CParser::LogicalOrOperatorContext::getRuleIndex() const {
  return CParser::RuleLogicalOrOperator;
}


antlrcpp::Any CParser::LogicalOrOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitLogicalOrOperator(this);
  else
    return visitor->visitChildren(this);
}

CParser::LogicalOrOperatorContext* CParser::logicalOrOperator() {
  LogicalOrOperatorContext *_localctx = _tracker.createInstance<LogicalOrOperatorContext>(_ctx, getState());
  enterRule(_localctx, 56, CParser::RuleLogicalOrOperator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(304);
    match(CParser::OrOr);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConditionalExpressionContext ------------------------------------------------------------------

CParser::ConditionalExpressionContext::ConditionalExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::LogicalOrExpressionContext* CParser::ConditionalExpressionContext::logicalOrExpression() {
  return getRuleContext<CParser::LogicalOrExpressionContext>(0);
}

tree::TerminalNode* CParser::ConditionalExpressionContext::Question() {
  return getToken(CParser::Question, 0);
}

CParser::ExpressionContext* CParser::ConditionalExpressionContext::expression() {
  return getRuleContext<CParser::ExpressionContext>(0);
}

tree::TerminalNode* CParser::ConditionalExpressionContext::Colon() {
  return getToken(CParser::Colon, 0);
}

CParser::ConditionalExpressionContext* CParser::ConditionalExpressionContext::conditionalExpression() {
  return getRuleContext<CParser::ConditionalExpressionContext>(0);
}


size_t CParser::ConditionalExpressionContext::getRuleIndex() const {
  return CParser::RuleConditionalExpression;
}


antlrcpp::Any CParser::ConditionalExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitConditionalExpression(this);
  else
    return visitor->visitChildren(this);
}

CParser::ConditionalExpressionContext* CParser::conditionalExpression() {
  ConditionalExpressionContext *_localctx = _tracker.createInstance<ConditionalExpressionContext>(_ctx, getState());
  enterRule(_localctx, 58, CParser::RuleConditionalExpression);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(306);
    logicalOrExpression();
    setState(312);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CParser::Question) {
      setState(307);
      match(CParser::Question);
      setState(308);
      expression();
      setState(309);
      match(CParser::Colon);
      setState(310);
      conditionalExpression();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentExpressionContext ------------------------------------------------------------------

CParser::AssignmentExpressionContext::AssignmentExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::UnaryExpressionContext* CParser::AssignmentExpressionContext::unaryExpression() {
  return getRuleContext<CParser::UnaryExpressionContext>(0);
}

CParser::AssignmentOperatorContext* CParser::AssignmentExpressionContext::assignmentOperator() {
  return getRuleContext<CParser::AssignmentOperatorContext>(0);
}

CParser::AssignmentExpressionContext* CParser::AssignmentExpressionContext::assignmentExpression() {
  return getRuleContext<CParser::AssignmentExpressionContext>(0);
}

CParser::ConditionalExpressionContext* CParser::AssignmentExpressionContext::conditionalExpression() {
  return getRuleContext<CParser::ConditionalExpressionContext>(0);
}


size_t CParser::AssignmentExpressionContext::getRuleIndex() const {
  return CParser::RuleAssignmentExpression;
}


antlrcpp::Any CParser::AssignmentExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitAssignmentExpression(this);
  else
    return visitor->visitChildren(this);
}

CParser::AssignmentExpressionContext* CParser::assignmentExpression() {
  AssignmentExpressionContext *_localctx = _tracker.createInstance<AssignmentExpressionContext>(_ctx, getState());
  enterRule(_localctx, 60, CParser::RuleAssignmentExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(319);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(314);
      unaryExpression();
      setState(315);
      assignmentOperator();
      setState(316);
      assignmentExpression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(318);
      conditionalExpression();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentOperatorContext ------------------------------------------------------------------

CParser::AssignmentOperatorContext::AssignmentOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::AssignmentOperatorContext::Assign() {
  return getToken(CParser::Assign, 0);
}

tree::TerminalNode* CParser::AssignmentOperatorContext::StarAssign() {
  return getToken(CParser::StarAssign, 0);
}

tree::TerminalNode* CParser::AssignmentOperatorContext::DivAssign() {
  return getToken(CParser::DivAssign, 0);
}

tree::TerminalNode* CParser::AssignmentOperatorContext::ModAssign() {
  return getToken(CParser::ModAssign, 0);
}

tree::TerminalNode* CParser::AssignmentOperatorContext::PlusAssign() {
  return getToken(CParser::PlusAssign, 0);
}

tree::TerminalNode* CParser::AssignmentOperatorContext::MinusAssign() {
  return getToken(CParser::MinusAssign, 0);
}

tree::TerminalNode* CParser::AssignmentOperatorContext::LeftShiftAssign() {
  return getToken(CParser::LeftShiftAssign, 0);
}

tree::TerminalNode* CParser::AssignmentOperatorContext::RightShiftAssign() {
  return getToken(CParser::RightShiftAssign, 0);
}

tree::TerminalNode* CParser::AssignmentOperatorContext::AndAssign() {
  return getToken(CParser::AndAssign, 0);
}

tree::TerminalNode* CParser::AssignmentOperatorContext::XorAssign() {
  return getToken(CParser::XorAssign, 0);
}

tree::TerminalNode* CParser::AssignmentOperatorContext::OrAssign() {
  return getToken(CParser::OrAssign, 0);
}


size_t CParser::AssignmentOperatorContext::getRuleIndex() const {
  return CParser::RuleAssignmentOperator;
}


antlrcpp::Any CParser::AssignmentOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitAssignmentOperator(this);
  else
    return visitor->visitChildren(this);
}

CParser::AssignmentOperatorContext* CParser::assignmentOperator() {
  AssignmentOperatorContext *_localctx = _tracker.createInstance<AssignmentOperatorContext>(_ctx, getState());
  enterRule(_localctx, 62, CParser::RuleAssignmentOperator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(321);
    _la = _input->LA(1);
    if (!(((((_la - 75) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 75)) & ((1ULL << (CParser::Assign - 75))
      | (1ULL << (CParser::StarAssign - 75))
      | (1ULL << (CParser::DivAssign - 75))
      | (1ULL << (CParser::ModAssign - 75))
      | (1ULL << (CParser::PlusAssign - 75))
      | (1ULL << (CParser::MinusAssign - 75))
      | (1ULL << (CParser::LeftShiftAssign - 75))
      | (1ULL << (CParser::RightShiftAssign - 75))
      | (1ULL << (CParser::AndAssign - 75))
      | (1ULL << (CParser::XorAssign - 75))
      | (1ULL << (CParser::OrAssign - 75)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

CParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CParser::AssignmentExpressionContext *> CParser::ExpressionContext::assignmentExpression() {
  return getRuleContexts<CParser::AssignmentExpressionContext>();
}

CParser::AssignmentExpressionContext* CParser::ExpressionContext::assignmentExpression(size_t i) {
  return getRuleContext<CParser::AssignmentExpressionContext>(i);
}

std::vector<tree::TerminalNode *> CParser::ExpressionContext::Comma() {
  return getTokens(CParser::Comma);
}

tree::TerminalNode* CParser::ExpressionContext::Comma(size_t i) {
  return getToken(CParser::Comma, i);
}


size_t CParser::ExpressionContext::getRuleIndex() const {
  return CParser::RuleExpression;
}


antlrcpp::Any CParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}

CParser::ExpressionContext* CParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 64, CParser::RuleExpression);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(323);
    assignmentExpression();
    setState(328);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CParser::Comma) {
      setState(324);
      match(CParser::Comma);
      setState(325);
      assignmentExpression();
      setState(330);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationContext ------------------------------------------------------------------

CParser::DeclarationContext::DeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::DeclarationSpecifiersContext* CParser::DeclarationContext::declarationSpecifiers() {
  return getRuleContext<CParser::DeclarationSpecifiersContext>(0);
}

tree::TerminalNode* CParser::DeclarationContext::Semi() {
  return getToken(CParser::Semi, 0);
}

CParser::InitDeclaratorListContext* CParser::DeclarationContext::initDeclaratorList() {
  return getRuleContext<CParser::InitDeclaratorListContext>(0);
}


size_t CParser::DeclarationContext::getRuleIndex() const {
  return CParser::RuleDeclaration;
}


antlrcpp::Any CParser::DeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitDeclaration(this);
  else
    return visitor->visitChildren(this);
}

CParser::DeclarationContext* CParser::declaration() {
  DeclarationContext *_localctx = _tracker.createInstance<DeclarationContext>(_ctx, getState());
  enterRule(_localctx, 66, CParser::RuleDeclaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(331);
    declarationSpecifiers();
    setState(333);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CParser::Star

    || _la == CParser::Identifier) {
      setState(332);
      initDeclaratorList();
    }
    setState(335);
    match(CParser::Semi);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationSpecifiersContext ------------------------------------------------------------------

CParser::DeclarationSpecifiersContext::DeclarationSpecifiersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::TypeNameContext* CParser::DeclarationSpecifiersContext::typeName() {
  return getRuleContext<CParser::TypeNameContext>(0);
}

CParser::TypedefSpecifierContext* CParser::DeclarationSpecifiersContext::typedefSpecifier() {
  return getRuleContext<CParser::TypedefSpecifierContext>(0);
}


size_t CParser::DeclarationSpecifiersContext::getRuleIndex() const {
  return CParser::RuleDeclarationSpecifiers;
}


antlrcpp::Any CParser::DeclarationSpecifiersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitDeclarationSpecifiers(this);
  else
    return visitor->visitChildren(this);
}

CParser::DeclarationSpecifiersContext* CParser::declarationSpecifiers() {
  DeclarationSpecifiersContext *_localctx = _tracker.createInstance<DeclarationSpecifiersContext>(_ctx, getState());
  enterRule(_localctx, 68, CParser::RuleDeclarationSpecifiers);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(338);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CParser::Typedef) {
      setState(337);
      typedefSpecifier();
    }
    setState(340);
    typeName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeNameContext ------------------------------------------------------------------

CParser::TypeNameContext::TypeNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CParser::DeclarationSpecifierContext *> CParser::TypeNameContext::declarationSpecifier() {
  return getRuleContexts<CParser::DeclarationSpecifierContext>();
}

CParser::DeclarationSpecifierContext* CParser::TypeNameContext::declarationSpecifier(size_t i) {
  return getRuleContext<CParser::DeclarationSpecifierContext>(i);
}

CParser::IdentifierContext* CParser::TypeNameContext::identifier() {
  return getRuleContext<CParser::IdentifierContext>(0);
}


size_t CParser::TypeNameContext::getRuleIndex() const {
  return CParser::RuleTypeName;
}


antlrcpp::Any CParser::TypeNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitTypeName(this);
  else
    return visitor->visitChildren(this);
}

CParser::TypeNameContext* CParser::typeName() {
  TypeNameContext *_localctx = _tracker.createInstance<TypeNameContext>(_ctx, getState());
  enterRule(_localctx, 70, CParser::RuleTypeName);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(348);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::Char:
      case CParser::Double:
      case CParser::Float:
      case CParser::Int:
      case CParser::Long:
      case CParser::Short:
      case CParser::Signed:
      case CParser::Unsigned:
      case CParser::Void:
      case CParser::Bool: {
        enterOuterAlt(_localctx, 1);
        setState(343); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(342);
          declarationSpecifier();
          setState(345); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << CParser::Char)
          | (1ULL << CParser::Double)
          | (1ULL << CParser::Float)
          | (1ULL << CParser::Int)
          | (1ULL << CParser::Long)
          | (1ULL << CParser::Short)
          | (1ULL << CParser::Signed)
          | (1ULL << CParser::Unsigned)
          | (1ULL << CParser::Void)
          | (1ULL << CParser::Bool))) != 0));
        break;
      }

      case CParser::Identifier: {
        enterOuterAlt(_localctx, 2);
        setState(347);
        identifier();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationSpecifierContext ------------------------------------------------------------------

CParser::DeclarationSpecifierContext::DeclarationSpecifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::TypeSpecifierContext* CParser::DeclarationSpecifierContext::typeSpecifier() {
  return getRuleContext<CParser::TypeSpecifierContext>(0);
}


size_t CParser::DeclarationSpecifierContext::getRuleIndex() const {
  return CParser::RuleDeclarationSpecifier;
}


antlrcpp::Any CParser::DeclarationSpecifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitDeclarationSpecifier(this);
  else
    return visitor->visitChildren(this);
}

CParser::DeclarationSpecifierContext* CParser::declarationSpecifier() {
  DeclarationSpecifierContext *_localctx = _tracker.createInstance<DeclarationSpecifierContext>(_ctx, getState());
  enterRule(_localctx, 72, CParser::RuleDeclarationSpecifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(350);
    typeSpecifier();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InitDeclaratorListContext ------------------------------------------------------------------

CParser::InitDeclaratorListContext::InitDeclaratorListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CParser::InitDeclaratorContext *> CParser::InitDeclaratorListContext::initDeclarator() {
  return getRuleContexts<CParser::InitDeclaratorContext>();
}

CParser::InitDeclaratorContext* CParser::InitDeclaratorListContext::initDeclarator(size_t i) {
  return getRuleContext<CParser::InitDeclaratorContext>(i);
}

std::vector<tree::TerminalNode *> CParser::InitDeclaratorListContext::Comma() {
  return getTokens(CParser::Comma);
}

tree::TerminalNode* CParser::InitDeclaratorListContext::Comma(size_t i) {
  return getToken(CParser::Comma, i);
}


size_t CParser::InitDeclaratorListContext::getRuleIndex() const {
  return CParser::RuleInitDeclaratorList;
}


antlrcpp::Any CParser::InitDeclaratorListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitInitDeclaratorList(this);
  else
    return visitor->visitChildren(this);
}

CParser::InitDeclaratorListContext* CParser::initDeclaratorList() {
  InitDeclaratorListContext *_localctx = _tracker.createInstance<InitDeclaratorListContext>(_ctx, getState());
  enterRule(_localctx, 74, CParser::RuleInitDeclaratorList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(352);
    initDeclarator();
    setState(357);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CParser::Comma) {
      setState(353);
      match(CParser::Comma);
      setState(354);
      initDeclarator();
      setState(359);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InitDeclaratorContext ------------------------------------------------------------------

CParser::InitDeclaratorContext::InitDeclaratorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::DeclaratorContext* CParser::InitDeclaratorContext::declarator() {
  return getRuleContext<CParser::DeclaratorContext>(0);
}

tree::TerminalNode* CParser::InitDeclaratorContext::Assign() {
  return getToken(CParser::Assign, 0);
}

CParser::InitializerContext* CParser::InitDeclaratorContext::initializer() {
  return getRuleContext<CParser::InitializerContext>(0);
}


size_t CParser::InitDeclaratorContext::getRuleIndex() const {
  return CParser::RuleInitDeclarator;
}


antlrcpp::Any CParser::InitDeclaratorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitInitDeclarator(this);
  else
    return visitor->visitChildren(this);
}

CParser::InitDeclaratorContext* CParser::initDeclarator() {
  InitDeclaratorContext *_localctx = _tracker.createInstance<InitDeclaratorContext>(_ctx, getState());
  enterRule(_localctx, 76, CParser::RuleInitDeclarator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(360);
    declarator();
    setState(363);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CParser::Assign) {
      setState(361);
      match(CParser::Assign);
      setState(362);
      initializer();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypedefSpecifierContext ------------------------------------------------------------------

CParser::TypedefSpecifierContext::TypedefSpecifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::TypedefSpecifierContext::Typedef() {
  return getToken(CParser::Typedef, 0);
}


size_t CParser::TypedefSpecifierContext::getRuleIndex() const {
  return CParser::RuleTypedefSpecifier;
}


antlrcpp::Any CParser::TypedefSpecifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitTypedefSpecifier(this);
  else
    return visitor->visitChildren(this);
}

CParser::TypedefSpecifierContext* CParser::typedefSpecifier() {
  TypedefSpecifierContext *_localctx = _tracker.createInstance<TypedefSpecifierContext>(_ctx, getState());
  enterRule(_localctx, 78, CParser::RuleTypedefSpecifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(365);
    match(CParser::Typedef);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeSpecifierContext ------------------------------------------------------------------

CParser::TypeSpecifierContext::TypeSpecifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::SimpleTypeSpecifierContext* CParser::TypeSpecifierContext::simpleTypeSpecifier() {
  return getRuleContext<CParser::SimpleTypeSpecifierContext>(0);
}


size_t CParser::TypeSpecifierContext::getRuleIndex() const {
  return CParser::RuleTypeSpecifier;
}


antlrcpp::Any CParser::TypeSpecifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitTypeSpecifier(this);
  else
    return visitor->visitChildren(this);
}

CParser::TypeSpecifierContext* CParser::typeSpecifier() {
  TypeSpecifierContext *_localctx = _tracker.createInstance<TypeSpecifierContext>(_ctx, getState());
  enterRule(_localctx, 80, CParser::RuleTypeSpecifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(367);
    simpleTypeSpecifier();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SimpleTypeSpecifierContext ------------------------------------------------------------------

CParser::SimpleTypeSpecifierContext::SimpleTypeSpecifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::SimpleTypeSpecifierContext::Void() {
  return getToken(CParser::Void, 0);
}

tree::TerminalNode* CParser::SimpleTypeSpecifierContext::Char() {
  return getToken(CParser::Char, 0);
}

tree::TerminalNode* CParser::SimpleTypeSpecifierContext::Short() {
  return getToken(CParser::Short, 0);
}

tree::TerminalNode* CParser::SimpleTypeSpecifierContext::Int() {
  return getToken(CParser::Int, 0);
}

tree::TerminalNode* CParser::SimpleTypeSpecifierContext::Long() {
  return getToken(CParser::Long, 0);
}

tree::TerminalNode* CParser::SimpleTypeSpecifierContext::Float() {
  return getToken(CParser::Float, 0);
}

tree::TerminalNode* CParser::SimpleTypeSpecifierContext::Double() {
  return getToken(CParser::Double, 0);
}

tree::TerminalNode* CParser::SimpleTypeSpecifierContext::Signed() {
  return getToken(CParser::Signed, 0);
}

tree::TerminalNode* CParser::SimpleTypeSpecifierContext::Unsigned() {
  return getToken(CParser::Unsigned, 0);
}

tree::TerminalNode* CParser::SimpleTypeSpecifierContext::Bool() {
  return getToken(CParser::Bool, 0);
}


size_t CParser::SimpleTypeSpecifierContext::getRuleIndex() const {
  return CParser::RuleSimpleTypeSpecifier;
}


antlrcpp::Any CParser::SimpleTypeSpecifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitSimpleTypeSpecifier(this);
  else
    return visitor->visitChildren(this);
}

CParser::SimpleTypeSpecifierContext* CParser::simpleTypeSpecifier() {
  SimpleTypeSpecifierContext *_localctx = _tracker.createInstance<SimpleTypeSpecifierContext>(_ctx, getState());
  enterRule(_localctx, 82, CParser::RuleSimpleTypeSpecifier);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(369);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CParser::Char)
      | (1ULL << CParser::Double)
      | (1ULL << CParser::Float)
      | (1ULL << CParser::Int)
      | (1ULL << CParser::Long)
      | (1ULL << CParser::Short)
      | (1ULL << CParser::Signed)
      | (1ULL << CParser::Unsigned)
      | (1ULL << CParser::Void)
      | (1ULL << CParser::Bool))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclaratorContext ------------------------------------------------------------------

CParser::DeclaratorContext::DeclaratorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::DirectDeclaratorContext* CParser::DeclaratorContext::directDeclarator() {
  return getRuleContext<CParser::DirectDeclaratorContext>(0);
}

std::vector<CParser::PointerContext *> CParser::DeclaratorContext::pointer() {
  return getRuleContexts<CParser::PointerContext>();
}

CParser::PointerContext* CParser::DeclaratorContext::pointer(size_t i) {
  return getRuleContext<CParser::PointerContext>(i);
}

std::vector<CParser::ArrayContext *> CParser::DeclaratorContext::array() {
  return getRuleContexts<CParser::ArrayContext>();
}

CParser::ArrayContext* CParser::DeclaratorContext::array(size_t i) {
  return getRuleContext<CParser::ArrayContext>(i);
}


size_t CParser::DeclaratorContext::getRuleIndex() const {
  return CParser::RuleDeclarator;
}


antlrcpp::Any CParser::DeclaratorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitDeclarator(this);
  else
    return visitor->visitChildren(this);
}

CParser::DeclaratorContext* CParser::declarator() {
  DeclaratorContext *_localctx = _tracker.createInstance<DeclaratorContext>(_ctx, getState());
  enterRule(_localctx, 84, CParser::RuleDeclarator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(374);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CParser::Star) {
      setState(371);
      pointer();
      setState(376);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(377);
    directDeclarator();
    setState(381);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CParser::LeftBracket) {
      setState(378);
      array();
      setState(383);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayContext ------------------------------------------------------------------

CParser::ArrayContext::ArrayContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::ArrayContext::LeftBracket() {
  return getToken(CParser::LeftBracket, 0);
}

tree::TerminalNode* CParser::ArrayContext::IntegerConstant() {
  return getToken(CParser::IntegerConstant, 0);
}

tree::TerminalNode* CParser::ArrayContext::RightBracket() {
  return getToken(CParser::RightBracket, 0);
}


size_t CParser::ArrayContext::getRuleIndex() const {
  return CParser::RuleArray;
}


antlrcpp::Any CParser::ArrayContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitArray(this);
  else
    return visitor->visitChildren(this);
}

CParser::ArrayContext* CParser::array() {
  ArrayContext *_localctx = _tracker.createInstance<ArrayContext>(_ctx, getState());
  enterRule(_localctx, 86, CParser::RuleArray);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(384);
    match(CParser::LeftBracket);
    setState(385);
    match(CParser::IntegerConstant);
    setState(386);
    match(CParser::RightBracket);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PointerContext ------------------------------------------------------------------

CParser::PointerContext::PointerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::PointerContext::Star() {
  return getToken(CParser::Star, 0);
}


size_t CParser::PointerContext::getRuleIndex() const {
  return CParser::RulePointer;
}


antlrcpp::Any CParser::PointerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitPointer(this);
  else
    return visitor->visitChildren(this);
}

CParser::PointerContext* CParser::pointer() {
  PointerContext *_localctx = _tracker.createInstance<PointerContext>(_ctx, getState());
  enterRule(_localctx, 88, CParser::RulePointer);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(388);
    match(CParser::Star);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DirectDeclaratorContext ------------------------------------------------------------------

CParser::DirectDeclaratorContext::DirectDeclaratorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::IdentifierContext* CParser::DirectDeclaratorContext::identifier() {
  return getRuleContext<CParser::IdentifierContext>(0);
}


size_t CParser::DirectDeclaratorContext::getRuleIndex() const {
  return CParser::RuleDirectDeclarator;
}


antlrcpp::Any CParser::DirectDeclaratorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitDirectDeclarator(this);
  else
    return visitor->visitChildren(this);
}

CParser::DirectDeclaratorContext* CParser::directDeclarator() {
  DirectDeclaratorContext *_localctx = _tracker.createInstance<DirectDeclaratorContext>(_ctx, getState());
  enterRule(_localctx, 90, CParser::RuleDirectDeclarator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(390);
    identifier();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterTypeListContext ------------------------------------------------------------------

CParser::ParameterTypeListContext::ParameterTypeListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::ParameterListContext* CParser::ParameterTypeListContext::parameterList() {
  return getRuleContext<CParser::ParameterListContext>(0);
}


size_t CParser::ParameterTypeListContext::getRuleIndex() const {
  return CParser::RuleParameterTypeList;
}


antlrcpp::Any CParser::ParameterTypeListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitParameterTypeList(this);
  else
    return visitor->visitChildren(this);
}

CParser::ParameterTypeListContext* CParser::parameterTypeList() {
  ParameterTypeListContext *_localctx = _tracker.createInstance<ParameterTypeListContext>(_ctx, getState());
  enterRule(_localctx, 92, CParser::RuleParameterTypeList);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(392);
    parameterList();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterListContext ------------------------------------------------------------------

CParser::ParameterListContext::ParameterListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CParser::ParameterDeclarationContext *> CParser::ParameterListContext::parameterDeclaration() {
  return getRuleContexts<CParser::ParameterDeclarationContext>();
}

CParser::ParameterDeclarationContext* CParser::ParameterListContext::parameterDeclaration(size_t i) {
  return getRuleContext<CParser::ParameterDeclarationContext>(i);
}

std::vector<tree::TerminalNode *> CParser::ParameterListContext::Comma() {
  return getTokens(CParser::Comma);
}

tree::TerminalNode* CParser::ParameterListContext::Comma(size_t i) {
  return getToken(CParser::Comma, i);
}


size_t CParser::ParameterListContext::getRuleIndex() const {
  return CParser::RuleParameterList;
}


antlrcpp::Any CParser::ParameterListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitParameterList(this);
  else
    return visitor->visitChildren(this);
}

CParser::ParameterListContext* CParser::parameterList() {
  ParameterListContext *_localctx = _tracker.createInstance<ParameterListContext>(_ctx, getState());
  enterRule(_localctx, 94, CParser::RuleParameterList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(394);
    parameterDeclaration();
    setState(399);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CParser::Comma) {
      setState(395);
      match(CParser::Comma);
      setState(396);
      parameterDeclaration();
      setState(401);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterDeclarationContext ------------------------------------------------------------------

CParser::ParameterDeclarationContext::ParameterDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::TypeNameContext* CParser::ParameterDeclarationContext::typeName() {
  return getRuleContext<CParser::TypeNameContext>(0);
}

CParser::DeclaratorContext* CParser::ParameterDeclarationContext::declarator() {
  return getRuleContext<CParser::DeclaratorContext>(0);
}


size_t CParser::ParameterDeclarationContext::getRuleIndex() const {
  return CParser::RuleParameterDeclaration;
}


antlrcpp::Any CParser::ParameterDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitParameterDeclaration(this);
  else
    return visitor->visitChildren(this);
}

CParser::ParameterDeclarationContext* CParser::parameterDeclaration() {
  ParameterDeclarationContext *_localctx = _tracker.createInstance<ParameterDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 96, CParser::RuleParameterDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(402);
    typeName();
    setState(403);
    declarator();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InitializerContext ------------------------------------------------------------------

CParser::InitializerContext::InitializerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::AssignmentExpressionContext* CParser::InitializerContext::assignmentExpression() {
  return getRuleContext<CParser::AssignmentExpressionContext>(0);
}


size_t CParser::InitializerContext::getRuleIndex() const {
  return CParser::RuleInitializer;
}


antlrcpp::Any CParser::InitializerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitInitializer(this);
  else
    return visitor->visitChildren(this);
}

CParser::InitializerContext* CParser::initializer() {
  InitializerContext *_localctx = _tracker.createInstance<InitializerContext>(_ctx, getState());
  enterRule(_localctx, 98, CParser::RuleInitializer);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(405);
    assignmentExpression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

CParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CParser::StatementContext::getRuleIndex() const {
  return CParser::RuleStatement;
}

void CParser::StatementContext::copyFrom(StatementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- WhileLoopContext ------------------------------------------------------------------

tree::TerminalNode* CParser::WhileLoopContext::While() {
  return getToken(CParser::While, 0);
}

tree::TerminalNode* CParser::WhileLoopContext::LeftParen() {
  return getToken(CParser::LeftParen, 0);
}

CParser::ExpressionContext* CParser::WhileLoopContext::expression() {
  return getRuleContext<CParser::ExpressionContext>(0);
}

tree::TerminalNode* CParser::WhileLoopContext::RightParen() {
  return getToken(CParser::RightParen, 0);
}

CParser::StatementContext* CParser::WhileLoopContext::statement() {
  return getRuleContext<CParser::StatementContext>(0);
}

CParser::WhileLoopContext::WhileLoopContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any CParser::WhileLoopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitWhileLoop(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IfStmtContext ------------------------------------------------------------------

tree::TerminalNode* CParser::IfStmtContext::If() {
  return getToken(CParser::If, 0);
}

tree::TerminalNode* CParser::IfStmtContext::LeftParen() {
  return getToken(CParser::LeftParen, 0);
}

CParser::ExpressionContext* CParser::IfStmtContext::expression() {
  return getRuleContext<CParser::ExpressionContext>(0);
}

tree::TerminalNode* CParser::IfStmtContext::RightParen() {
  return getToken(CParser::RightParen, 0);
}

std::vector<CParser::StatementContext *> CParser::IfStmtContext::statement() {
  return getRuleContexts<CParser::StatementContext>();
}

CParser::StatementContext* CParser::IfStmtContext::statement(size_t i) {
  return getRuleContext<CParser::StatementContext>(i);
}

tree::TerminalNode* CParser::IfStmtContext::Else() {
  return getToken(CParser::Else, 0);
}

CParser::IfStmtContext::IfStmtContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any CParser::IfStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitIfStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DoWhileContext ------------------------------------------------------------------

tree::TerminalNode* CParser::DoWhileContext::Do() {
  return getToken(CParser::Do, 0);
}

CParser::StatementContext* CParser::DoWhileContext::statement() {
  return getRuleContext<CParser::StatementContext>(0);
}

tree::TerminalNode* CParser::DoWhileContext::While() {
  return getToken(CParser::While, 0);
}

tree::TerminalNode* CParser::DoWhileContext::LeftParen() {
  return getToken(CParser::LeftParen, 0);
}

CParser::ExpressionContext* CParser::DoWhileContext::expression() {
  return getRuleContext<CParser::ExpressionContext>(0);
}

tree::TerminalNode* CParser::DoWhileContext::RightParen() {
  return getToken(CParser::RightParen, 0);
}

tree::TerminalNode* CParser::DoWhileContext::Semi() {
  return getToken(CParser::Semi, 0);
}

CParser::DoWhileContext::DoWhileContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any CParser::DoWhileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitDoWhile(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BreakStmtContext ------------------------------------------------------------------

tree::TerminalNode* CParser::BreakStmtContext::Break() {
  return getToken(CParser::Break, 0);
}

tree::TerminalNode* CParser::BreakStmtContext::Semi() {
  return getToken(CParser::Semi, 0);
}

CParser::BreakStmtContext::BreakStmtContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any CParser::BreakStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitBreakStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExpStmtContext ------------------------------------------------------------------

tree::TerminalNode* CParser::ExpStmtContext::Semi() {
  return getToken(CParser::Semi, 0);
}

CParser::ExpressionContext* CParser::ExpStmtContext::expression() {
  return getRuleContext<CParser::ExpressionContext>(0);
}

CParser::ExpStmtContext::ExpStmtContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any CParser::ExpStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitExpStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BlockContext ------------------------------------------------------------------

CParser::CompoundStatementContext* CParser::BlockContext::compoundStatement() {
  return getRuleContext<CParser::CompoundStatementContext>(0);
}

CParser::BlockContext::BlockContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any CParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ReturnStmtContext ------------------------------------------------------------------

tree::TerminalNode* CParser::ReturnStmtContext::Return() {
  return getToken(CParser::Return, 0);
}

tree::TerminalNode* CParser::ReturnStmtContext::Semi() {
  return getToken(CParser::Semi, 0);
}

CParser::ExpressionContext* CParser::ReturnStmtContext::expression() {
  return getRuleContext<CParser::ExpressionContext>(0);
}

CParser::ReturnStmtContext::ReturnStmtContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any CParser::ReturnStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitReturnStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ContinueStmtContext ------------------------------------------------------------------

tree::TerminalNode* CParser::ContinueStmtContext::Continue() {
  return getToken(CParser::Continue, 0);
}

tree::TerminalNode* CParser::ContinueStmtContext::Semi() {
  return getToken(CParser::Semi, 0);
}

CParser::ContinueStmtContext::ContinueStmtContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any CParser::ContinueStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitContinueStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ForLoopContext ------------------------------------------------------------------

tree::TerminalNode* CParser::ForLoopContext::For() {
  return getToken(CParser::For, 0);
}

tree::TerminalNode* CParser::ForLoopContext::LeftParen() {
  return getToken(CParser::LeftParen, 0);
}

CParser::ForConditionContext* CParser::ForLoopContext::forCondition() {
  return getRuleContext<CParser::ForConditionContext>(0);
}

tree::TerminalNode* CParser::ForLoopContext::RightParen() {
  return getToken(CParser::RightParen, 0);
}

CParser::StatementContext* CParser::ForLoopContext::statement() {
  return getRuleContext<CParser::StatementContext>(0);
}

CParser::ForLoopContext::ForLoopContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any CParser::ForLoopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitForLoop(this);
  else
    return visitor->visitChildren(this);
}
CParser::StatementContext* CParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 100, CParser::RuleStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(450);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::LeftBrace: {
        _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<CParser::BlockContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(407);
        compoundStatement();
        break;
      }

      case CParser::Sizeof:
      case CParser::LeftParen:
      case CParser::Plus:
      case CParser::PlusPlus:
      case CParser::Minus:
      case CParser::MinusMinus:
      case CParser::Star:
      case CParser::And:
      case CParser::Not:
      case CParser::Tilde:
      case CParser::Semi:
      case CParser::Identifier:
      case CParser::IntegerConstant:
      case CParser::CharacterConstant:
      case CParser::StringLiteral: {
        _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<CParser::ExpStmtContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(409);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << CParser::Sizeof)
          | (1ULL << CParser::LeftParen)
          | (1ULL << CParser::Plus)
          | (1ULL << CParser::PlusPlus)
          | (1ULL << CParser::Minus)
          | (1ULL << CParser::MinusMinus)
          | (1ULL << CParser::Star))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 64)) & ((1ULL << (CParser::And - 64))
          | (1ULL << (CParser::Not - 64))
          | (1ULL << (CParser::Tilde - 64))
          | (1ULL << (CParser::Identifier - 64))
          | (1ULL << (CParser::IntegerConstant - 64))
          | (1ULL << (CParser::CharacterConstant - 64))
          | (1ULL << (CParser::StringLiteral - 64)))) != 0)) {
          setState(408);
          expression();
        }
        setState(411);
        match(CParser::Semi);
        break;
      }

      case CParser::If: {
        _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<CParser::IfStmtContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(412);
        match(CParser::If);
        setState(413);
        match(CParser::LeftParen);
        setState(414);
        expression();
        setState(415);
        match(CParser::RightParen);
        setState(416);
        statement();
        setState(419);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx)) {
        case 1: {
          setState(417);
          match(CParser::Else);
          setState(418);
          statement();
          break;
        }

        default:
          break;
        }
        break;
      }

      case CParser::While: {
        _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<CParser::WhileLoopContext>(_localctx));
        enterOuterAlt(_localctx, 4);
        setState(421);
        match(CParser::While);
        setState(422);
        match(CParser::LeftParen);
        setState(423);
        expression();
        setState(424);
        match(CParser::RightParen);
        setState(425);
        statement();
        break;
      }

      case CParser::Do: {
        _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<CParser::DoWhileContext>(_localctx));
        enterOuterAlt(_localctx, 5);
        setState(427);
        match(CParser::Do);
        setState(428);
        statement();
        setState(429);
        match(CParser::While);
        setState(430);
        match(CParser::LeftParen);
        setState(431);
        expression();
        setState(432);
        match(CParser::RightParen);
        setState(433);
        match(CParser::Semi);
        break;
      }

      case CParser::For: {
        _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<CParser::ForLoopContext>(_localctx));
        enterOuterAlt(_localctx, 6);
        setState(435);
        match(CParser::For);
        setState(436);
        match(CParser::LeftParen);
        setState(437);
        forCondition();
        setState(438);
        match(CParser::RightParen);
        setState(439);
        statement();
        break;
      }

      case CParser::Continue: {
        _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<CParser::ContinueStmtContext>(_localctx));
        enterOuterAlt(_localctx, 7);
        setState(441);
        match(CParser::Continue);
        setState(442);
        match(CParser::Semi);
        break;
      }

      case CParser::Break: {
        _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<CParser::BreakStmtContext>(_localctx));
        enterOuterAlt(_localctx, 8);
        setState(443);
        match(CParser::Break);
        setState(444);
        match(CParser::Semi);
        break;
      }

      case CParser::Return: {
        _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<CParser::ReturnStmtContext>(_localctx));
        enterOuterAlt(_localctx, 9);
        setState(445);
        match(CParser::Return);
        setState(447);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << CParser::Sizeof)
          | (1ULL << CParser::LeftParen)
          | (1ULL << CParser::Plus)
          | (1ULL << CParser::PlusPlus)
          | (1ULL << CParser::Minus)
          | (1ULL << CParser::MinusMinus)
          | (1ULL << CParser::Star))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 64)) & ((1ULL << (CParser::And - 64))
          | (1ULL << (CParser::Not - 64))
          | (1ULL << (CParser::Tilde - 64))
          | (1ULL << (CParser::Identifier - 64))
          | (1ULL << (CParser::IntegerConstant - 64))
          | (1ULL << (CParser::CharacterConstant - 64))
          | (1ULL << (CParser::StringLiteral - 64)))) != 0)) {
          setState(446);
          expression();
        }
        setState(449);
        match(CParser::Semi);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CompoundStatementContext ------------------------------------------------------------------

CParser::CompoundStatementContext::CompoundStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::CompoundStatementContext::LeftBrace() {
  return getToken(CParser::LeftBrace, 0);
}

tree::TerminalNode* CParser::CompoundStatementContext::RightBrace() {
  return getToken(CParser::RightBrace, 0);
}

std::vector<CParser::BlockItemContext *> CParser::CompoundStatementContext::blockItem() {
  return getRuleContexts<CParser::BlockItemContext>();
}

CParser::BlockItemContext* CParser::CompoundStatementContext::blockItem(size_t i) {
  return getRuleContext<CParser::BlockItemContext>(i);
}


size_t CParser::CompoundStatementContext::getRuleIndex() const {
  return CParser::RuleCompoundStatement;
}


antlrcpp::Any CParser::CompoundStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitCompoundStatement(this);
  else
    return visitor->visitChildren(this);
}

CParser::CompoundStatementContext* CParser::compoundStatement() {
  CompoundStatementContext *_localctx = _tracker.createInstance<CompoundStatementContext>(_ctx, getState());
  enterRule(_localctx, 102, CParser::RuleCompoundStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(452);
    match(CParser::LeftBrace);
    setState(456);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CParser::Break)
      | (1ULL << CParser::Char)
      | (1ULL << CParser::Continue)
      | (1ULL << CParser::Do)
      | (1ULL << CParser::Double)
      | (1ULL << CParser::Float)
      | (1ULL << CParser::For)
      | (1ULL << CParser::If)
      | (1ULL << CParser::Int)
      | (1ULL << CParser::Long)
      | (1ULL << CParser::Return)
      | (1ULL << CParser::Short)
      | (1ULL << CParser::Signed)
      | (1ULL << CParser::Sizeof)
      | (1ULL << CParser::Typedef)
      | (1ULL << CParser::Unsigned)
      | (1ULL << CParser::Void)
      | (1ULL << CParser::While)
      | (1ULL << CParser::Bool)
      | (1ULL << CParser::LeftParen)
      | (1ULL << CParser::LeftBrace)
      | (1ULL << CParser::Plus)
      | (1ULL << CParser::PlusPlus)
      | (1ULL << CParser::Minus)
      | (1ULL << CParser::MinusMinus)
      | (1ULL << CParser::Star))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (CParser::And - 64))
      | (1ULL << (CParser::Not - 64))
      | (1ULL << (CParser::Tilde - 64))
      | (1ULL << (CParser::Semi - 64))
      | (1ULL << (CParser::Identifier - 64))
      | (1ULL << (CParser::IntegerConstant - 64))
      | (1ULL << (CParser::CharacterConstant - 64))
      | (1ULL << (CParser::StringLiteral - 64)))) != 0)) {
      setState(453);
      blockItem();
      setState(458);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(459);
    match(CParser::RightBrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockItemContext ------------------------------------------------------------------

CParser::BlockItemContext::BlockItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::StatementContext* CParser::BlockItemContext::statement() {
  return getRuleContext<CParser::StatementContext>(0);
}

CParser::DeclarationContext* CParser::BlockItemContext::declaration() {
  return getRuleContext<CParser::DeclarationContext>(0);
}


size_t CParser::BlockItemContext::getRuleIndex() const {
  return CParser::RuleBlockItem;
}


antlrcpp::Any CParser::BlockItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitBlockItem(this);
  else
    return visitor->visitChildren(this);
}

CParser::BlockItemContext* CParser::blockItem() {
  BlockItemContext *_localctx = _tracker.createInstance<BlockItemContext>(_ctx, getState());
  enterRule(_localctx, 104, CParser::RuleBlockItem);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(463);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(461);
      statement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(462);
      declaration();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForConditionContext ------------------------------------------------------------------

CParser::ForConditionContext::ForConditionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::ForInitContext* CParser::ForConditionContext::forInit() {
  return getRuleContext<CParser::ForInitContext>(0);
}

tree::TerminalNode* CParser::ForConditionContext::Semi() {
  return getToken(CParser::Semi, 0);
}

CParser::ForCondExpressionContext* CParser::ForConditionContext::forCondExpression() {
  return getRuleContext<CParser::ForCondExpressionContext>(0);
}

CParser::ForFinalExpressionContext* CParser::ForConditionContext::forFinalExpression() {
  return getRuleContext<CParser::ForFinalExpressionContext>(0);
}


size_t CParser::ForConditionContext::getRuleIndex() const {
  return CParser::RuleForCondition;
}


antlrcpp::Any CParser::ForConditionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitForCondition(this);
  else
    return visitor->visitChildren(this);
}

CParser::ForConditionContext* CParser::forCondition() {
  ForConditionContext *_localctx = _tracker.createInstance<ForConditionContext>(_ctx, getState());
  enterRule(_localctx, 106, CParser::RuleForCondition);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(465);
    forInit();
    setState(467);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CParser::Sizeof)
      | (1ULL << CParser::LeftParen)
      | (1ULL << CParser::Plus)
      | (1ULL << CParser::PlusPlus)
      | (1ULL << CParser::Minus)
      | (1ULL << CParser::MinusMinus)
      | (1ULL << CParser::Star))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (CParser::And - 64))
      | (1ULL << (CParser::Not - 64))
      | (1ULL << (CParser::Tilde - 64))
      | (1ULL << (CParser::Identifier - 64))
      | (1ULL << (CParser::IntegerConstant - 64))
      | (1ULL << (CParser::CharacterConstant - 64))
      | (1ULL << (CParser::StringLiteral - 64)))) != 0)) {
      setState(466);
      forCondExpression();
    }
    setState(469);
    match(CParser::Semi);
    setState(471);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CParser::Sizeof)
      | (1ULL << CParser::LeftParen)
      | (1ULL << CParser::Plus)
      | (1ULL << CParser::PlusPlus)
      | (1ULL << CParser::Minus)
      | (1ULL << CParser::MinusMinus)
      | (1ULL << CParser::Star))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (CParser::And - 64))
      | (1ULL << (CParser::Not - 64))
      | (1ULL << (CParser::Tilde - 64))
      | (1ULL << (CParser::Identifier - 64))
      | (1ULL << (CParser::IntegerConstant - 64))
      | (1ULL << (CParser::CharacterConstant - 64))
      | (1ULL << (CParser::StringLiteral - 64)))) != 0)) {
      setState(470);
      forFinalExpression();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForInitContext ------------------------------------------------------------------

CParser::ForInitContext::ForInitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::ForInitContext::Semi() {
  return getToken(CParser::Semi, 0);
}

CParser::ExpressionContext* CParser::ForInitContext::expression() {
  return getRuleContext<CParser::ExpressionContext>(0);
}

CParser::DeclarationContext* CParser::ForInitContext::declaration() {
  return getRuleContext<CParser::DeclarationContext>(0);
}


size_t CParser::ForInitContext::getRuleIndex() const {
  return CParser::RuleForInit;
}


antlrcpp::Any CParser::ForInitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitForInit(this);
  else
    return visitor->visitChildren(this);
}

CParser::ForInitContext* CParser::forInit() {
  ForInitContext *_localctx = _tracker.createInstance<ForInitContext>(_ctx, getState());
  enterRule(_localctx, 108, CParser::RuleForInit);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(478);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(474);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CParser::Sizeof)
        | (1ULL << CParser::LeftParen)
        | (1ULL << CParser::Plus)
        | (1ULL << CParser::PlusPlus)
        | (1ULL << CParser::Minus)
        | (1ULL << CParser::MinusMinus)
        | (1ULL << CParser::Star))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 64)) & ((1ULL << (CParser::And - 64))
        | (1ULL << (CParser::Not - 64))
        | (1ULL << (CParser::Tilde - 64))
        | (1ULL << (CParser::Identifier - 64))
        | (1ULL << (CParser::IntegerConstant - 64))
        | (1ULL << (CParser::CharacterConstant - 64))
        | (1ULL << (CParser::StringLiteral - 64)))) != 0)) {
        setState(473);
        expression();
      }
      setState(476);
      match(CParser::Semi);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(477);
      declaration();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForFinalExpressionContext ------------------------------------------------------------------

CParser::ForFinalExpressionContext::ForFinalExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::ExpressionContext* CParser::ForFinalExpressionContext::expression() {
  return getRuleContext<CParser::ExpressionContext>(0);
}


size_t CParser::ForFinalExpressionContext::getRuleIndex() const {
  return CParser::RuleForFinalExpression;
}


antlrcpp::Any CParser::ForFinalExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitForFinalExpression(this);
  else
    return visitor->visitChildren(this);
}

CParser::ForFinalExpressionContext* CParser::forFinalExpression() {
  ForFinalExpressionContext *_localctx = _tracker.createInstance<ForFinalExpressionContext>(_ctx, getState());
  enterRule(_localctx, 110, CParser::RuleForFinalExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(480);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForCondExpressionContext ------------------------------------------------------------------

CParser::ForCondExpressionContext::ForCondExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::ExpressionContext* CParser::ForCondExpressionContext::expression() {
  return getRuleContext<CParser::ExpressionContext>(0);
}


size_t CParser::ForCondExpressionContext::getRuleIndex() const {
  return CParser::RuleForCondExpression;
}


antlrcpp::Any CParser::ForCondExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitForCondExpression(this);
  else
    return visitor->visitChildren(this);
}

CParser::ForCondExpressionContext* CParser::forCondExpression() {
  ForCondExpressionContext *_localctx = _tracker.createInstance<ForCondExpressionContext>(_ctx, getState());
  enterRule(_localctx, 112, CParser::RuleForCondExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(482);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CompilationUnitContext ------------------------------------------------------------------

CParser::CompilationUnitContext::CompilationUnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::CompilationUnitContext::EOF() {
  return getToken(CParser::EOF, 0);
}

CParser::TranslationUnitContext* CParser::CompilationUnitContext::translationUnit() {
  return getRuleContext<CParser::TranslationUnitContext>(0);
}


size_t CParser::CompilationUnitContext::getRuleIndex() const {
  return CParser::RuleCompilationUnit;
}


antlrcpp::Any CParser::CompilationUnitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitCompilationUnit(this);
  else
    return visitor->visitChildren(this);
}

CParser::CompilationUnitContext* CParser::compilationUnit() {
  CompilationUnitContext *_localctx = _tracker.createInstance<CompilationUnitContext>(_ctx, getState());
  enterRule(_localctx, 114, CParser::RuleCompilationUnit);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(485);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CParser::Char)
      | (1ULL << CParser::Double)
      | (1ULL << CParser::Float)
      | (1ULL << CParser::Int)
      | (1ULL << CParser::Long)
      | (1ULL << CParser::Short)
      | (1ULL << CParser::Signed)
      | (1ULL << CParser::Typedef)
      | (1ULL << CParser::Unsigned)
      | (1ULL << CParser::Void)
      | (1ULL << CParser::Bool)
      | (1ULL << CParser::Star))) != 0) || _la == CParser::Semi

    || _la == CParser::Identifier) {
      setState(484);
      translationUnit();
    }
    setState(487);
    match(CParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TranslationUnitContext ------------------------------------------------------------------

CParser::TranslationUnitContext::TranslationUnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CParser::ExternalDeclarationContext *> CParser::TranslationUnitContext::externalDeclaration() {
  return getRuleContexts<CParser::ExternalDeclarationContext>();
}

CParser::ExternalDeclarationContext* CParser::TranslationUnitContext::externalDeclaration(size_t i) {
  return getRuleContext<CParser::ExternalDeclarationContext>(i);
}


size_t CParser::TranslationUnitContext::getRuleIndex() const {
  return CParser::RuleTranslationUnit;
}


antlrcpp::Any CParser::TranslationUnitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitTranslationUnit(this);
  else
    return visitor->visitChildren(this);
}

CParser::TranslationUnitContext* CParser::translationUnit() {
  TranslationUnitContext *_localctx = _tracker.createInstance<TranslationUnitContext>(_ctx, getState());
  enterRule(_localctx, 116, CParser::RuleTranslationUnit);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(490); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(489);
      externalDeclaration();
      setState(492); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CParser::Char)
      | (1ULL << CParser::Double)
      | (1ULL << CParser::Float)
      | (1ULL << CParser::Int)
      | (1ULL << CParser::Long)
      | (1ULL << CParser::Short)
      | (1ULL << CParser::Signed)
      | (1ULL << CParser::Typedef)
      | (1ULL << CParser::Unsigned)
      | (1ULL << CParser::Void)
      | (1ULL << CParser::Bool)
      | (1ULL << CParser::Star))) != 0) || _la == CParser::Semi

    || _la == CParser::Identifier);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExternalDeclarationContext ------------------------------------------------------------------

CParser::ExternalDeclarationContext::ExternalDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::FunctionDefinitionContext* CParser::ExternalDeclarationContext::functionDefinition() {
  return getRuleContext<CParser::FunctionDefinitionContext>(0);
}

CParser::GlobalDeclarationContext* CParser::ExternalDeclarationContext::globalDeclaration() {
  return getRuleContext<CParser::GlobalDeclarationContext>(0);
}

tree::TerminalNode* CParser::ExternalDeclarationContext::Semi() {
  return getToken(CParser::Semi, 0);
}


size_t CParser::ExternalDeclarationContext::getRuleIndex() const {
  return CParser::RuleExternalDeclaration;
}


antlrcpp::Any CParser::ExternalDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitExternalDeclaration(this);
  else
    return visitor->visitChildren(this);
}

CParser::ExternalDeclarationContext* CParser::externalDeclaration() {
  ExternalDeclarationContext *_localctx = _tracker.createInstance<ExternalDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 118, CParser::RuleExternalDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(497);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 45, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(494);
      functionDefinition();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(495);
      globalDeclaration();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(496);
      match(CParser::Semi);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GlobalDeclarationContext ------------------------------------------------------------------

CParser::GlobalDeclarationContext::GlobalDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::DeclarationContext* CParser::GlobalDeclarationContext::declaration() {
  return getRuleContext<CParser::DeclarationContext>(0);
}


size_t CParser::GlobalDeclarationContext::getRuleIndex() const {
  return CParser::RuleGlobalDeclaration;
}


antlrcpp::Any CParser::GlobalDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitGlobalDeclaration(this);
  else
    return visitor->visitChildren(this);
}

CParser::GlobalDeclarationContext* CParser::globalDeclaration() {
  GlobalDeclarationContext *_localctx = _tracker.createInstance<GlobalDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 120, CParser::RuleGlobalDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(499);
    declaration();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionDefinitionContext ------------------------------------------------------------------

CParser::FunctionDefinitionContext::FunctionDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::DeclaratorContext* CParser::FunctionDefinitionContext::declarator() {
  return getRuleContext<CParser::DeclaratorContext>(0);
}

tree::TerminalNode* CParser::FunctionDefinitionContext::LeftParen() {
  return getToken(CParser::LeftParen, 0);
}

tree::TerminalNode* CParser::FunctionDefinitionContext::RightParen() {
  return getToken(CParser::RightParen, 0);
}

CParser::CompoundStatementContext* CParser::FunctionDefinitionContext::compoundStatement() {
  return getRuleContext<CParser::CompoundStatementContext>(0);
}

CParser::DeclarationSpecifiersContext* CParser::FunctionDefinitionContext::declarationSpecifiers() {
  return getRuleContext<CParser::DeclarationSpecifiersContext>(0);
}

CParser::ParameterTypeListContext* CParser::FunctionDefinitionContext::parameterTypeList() {
  return getRuleContext<CParser::ParameterTypeListContext>(0);
}


size_t CParser::FunctionDefinitionContext::getRuleIndex() const {
  return CParser::RuleFunctionDefinition;
}


antlrcpp::Any CParser::FunctionDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitFunctionDefinition(this);
  else
    return visitor->visitChildren(this);
}

CParser::FunctionDefinitionContext* CParser::functionDefinition() {
  FunctionDefinitionContext *_localctx = _tracker.createInstance<FunctionDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 122, CParser::RuleFunctionDefinition);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(502);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 46, _ctx)) {
    case 1: {
      setState(501);
      declarationSpecifiers();
      break;
    }

    default:
      break;
    }
    setState(504);
    declarator();
    setState(505);
    match(CParser::LeftParen);
    setState(507);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CParser::Char)
      | (1ULL << CParser::Double)
      | (1ULL << CParser::Float)
      | (1ULL << CParser::Int)
      | (1ULL << CParser::Long)
      | (1ULL << CParser::Short)
      | (1ULL << CParser::Signed)
      | (1ULL << CParser::Unsigned)
      | (1ULL << CParser::Void)
      | (1ULL << CParser::Bool))) != 0) || _la == CParser::Identifier) {
      setState(506);
      parameterTypeList();
    }
    setState(509);
    match(CParser::RightParen);
    setState(510);
    compoundStatement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> CParser::_decisionToDFA;
atn::PredictionContextCache CParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN CParser::_atn;
std::vector<uint16_t> CParser::_serializedATN;

std::vector<std::string> CParser::_ruleNames = {
  "primaryExpression", "identifier", "constant", "postfixExpression", "argumentExpressionList", 
  "unaryExpression", "prefixOperator", "unaryOperator", "castExpression", 
  "multiplicativeExpression", "multiplicativeOperator", "additiveExpression", 
  "additiveOperator", "shiftExpression", "shiftOperator", "relationalExpression", 
  "relationalOperator", "equalityExpression", "equalityOperator", "andExpression", 
  "andOperator", "exclusiveOrExpression", "exclusiveOrOperator", "inclusiveOrExpression", 
  "inclusiveOrOperator", "logicalAndExpression", "logicalAndOperator", "logicalOrExpression", 
  "logicalOrOperator", "conditionalExpression", "assignmentExpression", 
  "assignmentOperator", "expression", "declaration", "declarationSpecifiers", 
  "typeName", "declarationSpecifier", "initDeclaratorList", "initDeclarator", 
  "typedefSpecifier", "typeSpecifier", "simpleTypeSpecifier", "declarator", 
  "array", "pointer", "directDeclarator", "parameterTypeList", "parameterList", 
  "parameterDeclaration", "initializer", "statement", "compoundStatement", 
  "blockItem", "forCondition", "forInit", "forFinalExpression", "forCondExpression", 
  "compilationUnit", "translationUnit", "externalDeclaration", "globalDeclaration", 
  "functionDefinition"
};

std::vector<std::string> CParser::_literalNames = {
  "", "'auto'", "'break'", "'case'", "'char'", "'const'", "'continue'", 
  "'default'", "'do'", "'double'", "'else'", "'enum'", "'extern'", "'float'", 
  "'for'", "'goto'", "'if'", "'inline'", "'int'", "'long'", "'register'", 
  "'restrict'", "'return'", "'short'", "'signed'", "'sizeof'", "'static'", 
  "'struct'", "'switch'", "'typedef'", "'union'", "'unsigned'", "'void'", 
  "'volatile'", "'while'", "'_Alignas'", "'_Alignof'", "'_Atomic'", "'_Bool'", 
  "'_Complex'", "'_Generic'", "'_Imaginary'", "'_Noreturn'", "'_Static_assert'", 
  "'_Thread_local'", "'('", "')'", "'['", "']'", "'{'", "'}'", "'<'", "'<='", 
  "'>'", "'>='", "'<<'", "'>>'", "'+'", "'++'", "'-'", "'--'", "'*'", "'/'", 
  "'%'", "'&'", "'|'", "'&&'", "'||'", "'^'", "'!'", "'~'", "'\u003F'", 
  "':'", "';'", "','", "'='", "'*='", "'/='", "'%='", "'+='", "'-='", "'<<='", 
  "'>>='", "'&='", "'^='", "'|='", "'=='", "'!='", "'->'", "'.'", "'...'"
};

std::vector<std::string> CParser::_symbolicNames = {
  "", "Auto", "Break", "Case", "Char", "Const", "Continue", "Default", "Do", 
  "Double", "Else", "Enum", "Extern", "Float", "For", "Goto", "If", "Inline", 
  "Int", "Long", "Register", "Restrict", "Return", "Short", "Signed", "Sizeof", 
  "Static", "Struct", "Switch", "Typedef", "Union", "Unsigned", "Void", 
  "Volatile", "While", "Alignas", "Alignof", "Atomic", "Bool", "Complex", 
  "Generic", "Imaginary", "Noreturn", "StaticAssert", "ThreadLocal", "LeftParen", 
  "RightParen", "LeftBracket", "RightBracket", "LeftBrace", "RightBrace", 
  "Less", "LessEqual", "Greater", "GreaterEqual", "LeftShift", "RightShift", 
  "Plus", "PlusPlus", "Minus", "MinusMinus", "Star", "Div", "Mod", "And", 
  "Or", "AndAnd", "OrOr", "Caret", "Not", "Tilde", "Question", "Colon", 
  "Semi", "Comma", "Assign", "StarAssign", "DivAssign", "ModAssign", "PlusAssign", 
  "MinusAssign", "LeftShiftAssign", "RightShiftAssign", "AndAssign", "XorAssign", 
  "OrAssign", "Equal", "NotEqual", "Arrow", "Dot", "Ellipsis", "Identifier", 
  "IntegerConstant", "DigitSequence", "CharacterConstant", "StringLiteral", 
  "ComplexDefine", "IncludeDirective", "AsmBlock", "LineAfterPreprocessing", 
  "LineDirective", "PragmaDirective", "Whitespace", "Newline", "BlockComment", 
  "LineComment"
};

dfa::Vocabulary CParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> CParser::_tokenNames;

CParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  static const uint16_t serializedATNSegment0[] = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
       0x3, 0x6b, 0x203, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
       0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 
       0x7, 0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 
       0x4, 0xb, 0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 
       0xe, 0x9, 0xe, 0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 
       0x9, 0x11, 0x4, 0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 
       0x9, 0x14, 0x4, 0x15, 0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 
       0x9, 0x17, 0x4, 0x18, 0x9, 0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 
       0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 
       0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 0x1f, 0x9, 0x1f, 0x4, 0x20, 
       0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 0x9, 0x22, 0x4, 0x23, 
       0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 0x25, 0x4, 0x26, 
       0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 0x4, 0x29, 
       0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 0x2b, 0x4, 0x2c, 
       0x9, 0x2c, 0x4, 0x2d, 0x9, 0x2d, 0x4, 0x2e, 0x9, 0x2e, 0x4, 0x2f, 
       0x9, 0x2f, 0x4, 0x30, 0x9, 0x30, 0x4, 0x31, 0x9, 0x31, 0x4, 0x32, 
       0x9, 0x32, 0x4, 0x33, 0x9, 0x33, 0x4, 0x34, 0x9, 0x34, 0x4, 0x35, 
       0x9, 0x35, 0x4, 0x36, 0x9, 0x36, 0x4, 0x37, 0x9, 0x37, 0x4, 0x38, 
       0x9, 0x38, 0x4, 0x39, 0x9, 0x39, 0x4, 0x3a, 0x9, 0x3a, 0x4, 0x3b, 
       0x9, 0x3b, 0x4, 0x3c, 0x9, 0x3c, 0x4, 0x3d, 0x9, 0x3d, 0x4, 0x3e, 
       0x9, 0x3e, 0x4, 0x3f, 0x9, 0x3f, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
       0x2, 0x3, 0x2, 0x3, 0x2, 0x5, 0x2, 0x85, 0xa, 0x2, 0x3, 0x3, 0x3, 
       0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x6, 0x4, 0x8c, 0xa, 0x4, 0xd, 
       0x4, 0xe, 0x4, 0x8d, 0x5, 0x4, 0x90, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 
       0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x99, 
       0xa, 0x5, 0x3, 0x5, 0x7, 0x5, 0x9c, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 
       0x9f, 0xb, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 0xa4, 0xa, 
       0x6, 0xc, 0x6, 0xe, 0x6, 0xa7, 0xb, 0x6, 0x3, 0x7, 0x7, 0x7, 0xaa, 
       0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0xad, 0xb, 0x7, 0x3, 0x7, 0x3, 0x7, 
       0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0xb3, 0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 
       0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 
       0xa, 0xbd, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0xc0, 0xb, 0xa, 0x3, 0xa, 
       0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0xc5, 0xa, 0xa, 0x3, 0xb, 0x3, 0xb, 
       0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0xcb, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 
       0xce, 0xb, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
       0x3, 0xd, 0x7, 0xd, 0xd6, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0xd9, 0xb, 
       0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 
       0x7, 0xf, 0xe1, 0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0xe4, 0xb, 0xf, 0x3, 
       0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x7, 
       0x11, 0xec, 0xa, 0x11, 0xc, 0x11, 0xe, 0x11, 0xef, 0xb, 0x11, 0x3, 
       0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x7, 
       0x13, 0xf7, 0xa, 0x13, 0xc, 0x13, 0xe, 0x13, 0xfa, 0xb, 0x13, 0x3, 
       0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x7, 
       0x15, 0x102, 0xa, 0x15, 0xc, 0x15, 0xe, 0x15, 0x105, 0xb, 0x15, 0x3, 
       0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x7, 
       0x17, 0x10d, 0xa, 0x17, 0xc, 0x17, 0xe, 0x17, 0x110, 0xb, 0x17, 0x3, 
       0x18, 0x3, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x7, 
       0x19, 0x118, 0xa, 0x19, 0xc, 0x19, 0xe, 0x19, 0x11b, 0xb, 0x19, 0x3, 
       0x1a, 0x3, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x7, 
       0x1b, 0x123, 0xa, 0x1b, 0xc, 0x1b, 0xe, 0x1b, 0x126, 0xb, 0x1b, 0x3, 
       0x1c, 0x3, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x7, 
       0x1d, 0x12e, 0xa, 0x1d, 0xc, 0x1d, 0xe, 0x1d, 0x131, 0xb, 0x1d, 0x3, 
       0x1e, 0x3, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 
       0x1f, 0x3, 0x1f, 0x5, 0x1f, 0x13b, 0xa, 0x1f, 0x3, 0x20, 0x3, 0x20, 
       0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x5, 0x20, 0x142, 0xa, 0x20, 0x3, 
       0x21, 0x3, 0x21, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x7, 0x22, 0x149, 
       0xa, 0x22, 0xc, 0x22, 0xe, 0x22, 0x14c, 0xb, 0x22, 0x3, 0x23, 0x3, 
       0x23, 0x5, 0x23, 0x150, 0xa, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x24, 
       0x5, 0x24, 0x155, 0xa, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x25, 0x6, 
       0x25, 0x15a, 0xa, 0x25, 0xd, 0x25, 0xe, 0x25, 0x15b, 0x3, 0x25, 0x5, 
       0x25, 0x15f, 0xa, 0x25, 0x3, 0x26, 0x3, 0x26, 0x3, 0x27, 0x3, 0x27, 
       0x3, 0x27, 0x7, 0x27, 0x166, 0xa, 0x27, 0xc, 0x27, 0xe, 0x27, 0x169, 
       0xb, 0x27, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x5, 0x28, 0x16e, 0xa, 
       0x28, 0x3, 0x29, 0x3, 0x29, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2b, 0x3, 
       0x2b, 0x3, 0x2c, 0x7, 0x2c, 0x177, 0xa, 0x2c, 0xc, 0x2c, 0xe, 0x2c, 
       0x17a, 0xb, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x7, 0x2c, 0x17e, 0xa, 0x2c, 
       0xc, 0x2c, 0xe, 0x2c, 0x181, 0xb, 0x2c, 0x3, 0x2d, 0x3, 0x2d, 0x3, 
       0x2d, 0x3, 0x2d, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2f, 0x3, 0x2f, 0x3, 
       0x30, 0x3, 0x30, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x7, 0x31, 0x190, 
       0xa, 0x31, 0xc, 0x31, 0xe, 0x31, 0x193, 0xb, 0x31, 0x3, 0x32, 0x3, 
       0x32, 0x3, 0x32, 0x3, 0x33, 0x3, 0x33, 0x3, 0x34, 0x3, 0x34, 0x5, 
       0x34, 0x19c, 0xa, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 
       0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x5, 0x34, 0x1a6, 0xa, 
       0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 
       0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 
       0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 
       0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 
       0x34, 0x3, 0x34, 0x3, 0x34, 0x5, 0x34, 0x1c2, 0xa, 0x34, 0x3, 0x34, 
       0x5, 0x34, 0x1c5, 0xa, 0x34, 0x3, 0x35, 0x3, 0x35, 0x7, 0x35, 0x1c9, 
       0xa, 0x35, 0xc, 0x35, 0xe, 0x35, 0x1cc, 0xb, 0x35, 0x3, 0x35, 0x3, 
       0x35, 0x3, 0x36, 0x3, 0x36, 0x5, 0x36, 0x1d2, 0xa, 0x36, 0x3, 0x37, 
       0x3, 0x37, 0x5, 0x37, 0x1d6, 0xa, 0x37, 0x3, 0x37, 0x3, 0x37, 0x5, 
       0x37, 0x1da, 0xa, 0x37, 0x3, 0x38, 0x5, 0x38, 0x1dd, 0xa, 0x38, 0x3, 
       0x38, 0x3, 0x38, 0x5, 0x38, 0x1e1, 0xa, 0x38, 0x3, 0x39, 0x3, 0x39, 
       0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3b, 0x5, 0x3b, 0x1e8, 0xa, 0x3b, 0x3, 
       0x3b, 0x3, 0x3b, 0x3, 0x3c, 0x6, 0x3c, 0x1ed, 0xa, 0x3c, 0xd, 0x3c, 
       0xe, 0x3c, 0x1ee, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x5, 0x3d, 0x1f4, 
       0xa, 0x3d, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3f, 0x5, 0x3f, 0x1f9, 0xa, 
       0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x5, 0x3f, 0x1fe, 0xa, 0x3f, 
       0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x2, 0x2, 0x40, 0x2, 
       0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 
       0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 
       0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 
       0x48, 0x4a, 0x4c, 0x4e, 0x50, 0x52, 0x54, 0x56, 0x58, 0x5a, 0x5c, 
       0x5e, 0x60, 0x62, 0x64, 0x66, 0x68, 0x6a, 0x6c, 0x6e, 0x70, 0x72, 
       0x74, 0x76, 0x78, 0x7a, 0x7c, 0x2, 0xb, 0x5, 0x2, 0x1b, 0x1b, 0x3c, 
       0x3c, 0x3e, 0x3e, 0x7, 0x2, 0x3b, 0x3b, 0x3d, 0x3d, 0x3f, 0x3f, 0x42, 
       0x42, 0x47, 0x48, 0x3, 0x2, 0x3f, 0x41, 0x4, 0x2, 0x3b, 0x3b, 0x3d, 
       0x3d, 0x3, 0x2, 0x39, 0x3a, 0x3, 0x2, 0x35, 0x38, 0x3, 0x2, 0x58, 
       0x59, 0x3, 0x2, 0x4d, 0x57, 0x9, 0x2, 0x6, 0x6, 0xb, 0xb, 0xf, 0xf, 
       0x14, 0x15, 0x19, 0x1a, 0x21, 0x22, 0x28, 0x28, 0x2, 0x1fe, 0x2, 
       0x84, 0x3, 0x2, 0x2, 0x2, 0x4, 0x86, 0x3, 0x2, 0x2, 0x2, 0x6, 0x8f, 
       0x3, 0x2, 0x2, 0x2, 0x8, 0x91, 0x3, 0x2, 0x2, 0x2, 0xa, 0xa0, 0x3, 
       0x2, 0x2, 0x2, 0xc, 0xab, 0x3, 0x2, 0x2, 0x2, 0xe, 0xb4, 0x3, 0x2, 
       0x2, 0x2, 0x10, 0xb6, 0x3, 0x2, 0x2, 0x2, 0x12, 0xc4, 0x3, 0x2, 0x2, 
       0x2, 0x14, 0xc6, 0x3, 0x2, 0x2, 0x2, 0x16, 0xcf, 0x3, 0x2, 0x2, 0x2, 
       0x18, 0xd1, 0x3, 0x2, 0x2, 0x2, 0x1a, 0xda, 0x3, 0x2, 0x2, 0x2, 0x1c, 
       0xdc, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xe5, 0x3, 0x2, 0x2, 0x2, 0x20, 0xe7, 
       0x3, 0x2, 0x2, 0x2, 0x22, 0xf0, 0x3, 0x2, 0x2, 0x2, 0x24, 0xf2, 0x3, 
       0x2, 0x2, 0x2, 0x26, 0xfb, 0x3, 0x2, 0x2, 0x2, 0x28, 0xfd, 0x3, 0x2, 
       0x2, 0x2, 0x2a, 0x106, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x108, 0x3, 0x2, 
       0x2, 0x2, 0x2e, 0x111, 0x3, 0x2, 0x2, 0x2, 0x30, 0x113, 0x3, 0x2, 
       0x2, 0x2, 0x32, 0x11c, 0x3, 0x2, 0x2, 0x2, 0x34, 0x11e, 0x3, 0x2, 
       0x2, 0x2, 0x36, 0x127, 0x3, 0x2, 0x2, 0x2, 0x38, 0x129, 0x3, 0x2, 
       0x2, 0x2, 0x3a, 0x132, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x134, 0x3, 0x2, 
       0x2, 0x2, 0x3e, 0x141, 0x3, 0x2, 0x2, 0x2, 0x40, 0x143, 0x3, 0x2, 
       0x2, 0x2, 0x42, 0x145, 0x3, 0x2, 0x2, 0x2, 0x44, 0x14d, 0x3, 0x2, 
       0x2, 0x2, 0x46, 0x154, 0x3, 0x2, 0x2, 0x2, 0x48, 0x15e, 0x3, 0x2, 
       0x2, 0x2, 0x4a, 0x160, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x162, 0x3, 0x2, 
       0x2, 0x2, 0x4e, 0x16a, 0x3, 0x2, 0x2, 0x2, 0x50, 0x16f, 0x3, 0x2, 
       0x2, 0x2, 0x52, 0x171, 0x3, 0x2, 0x2, 0x2, 0x54, 0x173, 0x3, 0x2, 
       0x2, 0x2, 0x56, 0x178, 0x3, 0x2, 0x2, 0x2, 0x58, 0x182, 0x3, 0x2, 
       0x2, 0x2, 0x5a, 0x186, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x188, 0x3, 0x2, 
       0x2, 0x2, 0x5e, 0x18a, 0x3, 0x2, 0x2, 0x2, 0x60, 0x18c, 0x3, 0x2, 
       0x2, 0x2, 0x62, 0x194, 0x3, 0x2, 0x2, 0x2, 0x64, 0x197, 0x3, 0x2, 
       0x2, 0x2, 0x66, 0x1c4, 0x3, 0x2, 0x2, 0x2, 0x68, 0x1c6, 0x3, 0x2, 
       0x2, 0x2, 0x6a, 0x1d1, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x1d3, 0x3, 0x2, 
       0x2, 0x2, 0x6e, 0x1e0, 0x3, 0x2, 0x2, 0x2, 0x70, 0x1e2, 0x3, 0x2, 
       0x2, 0x2, 0x72, 0x1e4, 0x3, 0x2, 0x2, 0x2, 0x74, 0x1e7, 0x3, 0x2, 
       0x2, 0x2, 0x76, 0x1ec, 0x3, 0x2, 0x2, 0x2, 0x78, 0x1f3, 0x3, 0x2, 
       0x2, 0x2, 0x7a, 0x1f5, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x1f8, 0x3, 0x2, 
       0x2, 0x2, 0x7e, 0x85, 0x5, 0x4, 0x3, 0x2, 0x7f, 0x85, 0x5, 0x6, 0x4, 
       0x2, 0x80, 0x81, 0x7, 0x2f, 0x2, 0x2, 0x81, 0x82, 0x5, 0x42, 0x22, 
       0x2, 0x82, 0x83, 0x7, 0x30, 0x2, 0x2, 0x83, 0x85, 0x3, 0x2, 0x2, 
       0x2, 0x84, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x84, 0x7f, 0x3, 0x2, 0x2, 0x2, 
       0x84, 0x80, 0x3, 0x2, 0x2, 0x2, 0x85, 0x3, 0x3, 0x2, 0x2, 0x2, 0x86, 
       0x87, 0x7, 0x5d, 0x2, 0x2, 0x87, 0x5, 0x3, 0x2, 0x2, 0x2, 0x88, 0x90, 
       0x7, 0x5e, 0x2, 0x2, 0x89, 0x90, 0x7, 0x60, 0x2, 0x2, 0x8a, 0x8c, 
       0x7, 0x61, 0x2, 0x2, 0x8b, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x8d, 
       0x3, 0x2, 0x2, 0x2, 0x8d, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x8e, 0x3, 
       0x2, 0x2, 0x2, 0x8e, 0x90, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x88, 0x3, 0x2, 
       0x2, 0x2, 0x8f, 0x89, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x8b, 0x3, 0x2, 0x2, 
       0x2, 0x90, 0x7, 0x3, 0x2, 0x2, 0x2, 0x91, 0x9d, 0x5, 0x2, 0x2, 0x2, 
       0x92, 0x93, 0x7, 0x31, 0x2, 0x2, 0x93, 0x94, 0x5, 0x42, 0x22, 0x2, 
       0x94, 0x95, 0x7, 0x32, 0x2, 0x2, 0x95, 0x9c, 0x3, 0x2, 0x2, 0x2, 
       0x96, 0x98, 0x7, 0x2f, 0x2, 0x2, 0x97, 0x99, 0x5, 0xa, 0x6, 0x2, 
       0x98, 0x97, 0x3, 0x2, 0x2, 0x2, 0x98, 0x99, 0x3, 0x2, 0x2, 0x2, 0x99, 
       0x9a, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x9c, 0x7, 0x30, 0x2, 0x2, 0x9b, 
       0x92, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x96, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x9f, 
       0x3, 0x2, 0x2, 0x2, 0x9d, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x9d, 0x9e, 0x3, 
       0x2, 0x2, 0x2, 0x9e, 0x9, 0x3, 0x2, 0x2, 0x2, 0x9f, 0x9d, 0x3, 0x2, 
       0x2, 0x2, 0xa0, 0xa5, 0x5, 0x3e, 0x20, 0x2, 0xa1, 0xa2, 0x7, 0x4c, 
       0x2, 0x2, 0xa2, 0xa4, 0x5, 0x3e, 0x20, 0x2, 0xa3, 0xa1, 0x3, 0x2, 
       0x2, 0x2, 0xa4, 0xa7, 0x3, 0x2, 0x2, 0x2, 0xa5, 0xa3, 0x3, 0x2, 0x2, 
       0x2, 0xa5, 0xa6, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xb, 0x3, 0x2, 0x2, 0x2, 
       0xa7, 0xa5, 0x3, 0x2, 0x2, 0x2, 0xa8, 0xaa, 0x5, 0xe, 0x8, 0x2, 0xa9, 
       0xa8, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xad, 0x3, 0x2, 0x2, 0x2, 0xab, 0xa9, 
       0x3, 0x2, 0x2, 0x2, 0xab, 0xac, 0x3, 0x2, 0x2, 0x2, 0xac, 0xb2, 0x3, 
       0x2, 0x2, 0x2, 0xad, 0xab, 0x3, 0x2, 0x2, 0x2, 0xae, 0xb3, 0x5, 0x8, 
       0x5, 0x2, 0xaf, 0xb0, 0x5, 0x10, 0x9, 0x2, 0xb0, 0xb1, 0x5, 0xc, 
       0x7, 0x2, 0xb1, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xb2, 0xae, 0x3, 0x2, 0x2, 
       0x2, 0xb2, 0xaf, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xd, 0x3, 0x2, 0x2, 0x2, 
       0xb4, 0xb5, 0x9, 0x2, 0x2, 0x2, 0xb5, 0xf, 0x3, 0x2, 0x2, 0x2, 0xb6, 
       0xb7, 0x9, 0x3, 0x2, 0x2, 0xb7, 0x11, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xc5, 
       0x5, 0xc, 0x7, 0x2, 0xb9, 0xba, 0x7, 0x2f, 0x2, 0x2, 0xba, 0xbe, 
       0x5, 0x48, 0x25, 0x2, 0xbb, 0xbd, 0x5, 0x5a, 0x2e, 0x2, 0xbc, 0xbb, 
       0x3, 0x2, 0x2, 0x2, 0xbd, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xbc, 0x3, 
       0x2, 0x2, 0x2, 0xbe, 0xbf, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xc1, 0x3, 0x2, 
       0x2, 0x2, 0xc0, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xc2, 0x7, 0x30, 
       0x2, 0x2, 0xc2, 0xc3, 0x5, 0x12, 0xa, 0x2, 0xc3, 0xc5, 0x3, 0x2, 
       0x2, 0x2, 0xc4, 0xb8, 0x3, 0x2, 0x2, 0x2, 0xc4, 0xb9, 0x3, 0x2, 0x2, 
       0x2, 0xc5, 0x13, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xcc, 0x5, 0x12, 0xa, 
       0x2, 0xc7, 0xc8, 0x5, 0x16, 0xc, 0x2, 0xc8, 0xc9, 0x5, 0x12, 0xa, 
       0x2, 0xc9, 0xcb, 0x3, 0x2, 0x2, 0x2, 0xca, 0xc7, 0x3, 0x2, 0x2, 0x2, 
       0xcb, 0xce, 0x3, 0x2, 0x2, 0x2, 0xcc, 0xca, 0x3, 0x2, 0x2, 0x2, 0xcc, 
       0xcd, 0x3, 0x2, 0x2, 0x2, 0xcd, 0x15, 0x3, 0x2, 0x2, 0x2, 0xce, 0xcc, 
       0x3, 0x2, 0x2, 0x2, 0xcf, 0xd0, 0x9, 0x4, 0x2, 0x2, 0xd0, 0x17, 0x3, 
       0x2, 0x2, 0x2, 0xd1, 0xd7, 0x5, 0x14, 0xb, 0x2, 0xd2, 0xd3, 0x5, 
       0x1a, 0xe, 0x2, 0xd3, 0xd4, 0x5, 0x14, 0xb, 0x2, 0xd4, 0xd6, 0x3, 
       0x2, 0x2, 0x2, 0xd5, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xd9, 0x3, 0x2, 
       0x2, 0x2, 0xd7, 0xd5, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xd8, 0x3, 0x2, 0x2, 
       0x2, 0xd8, 0x19, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xd7, 0x3, 0x2, 0x2, 0x2, 
       0xda, 0xdb, 0x9, 0x5, 0x2, 0x2, 0xdb, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xdc, 
       0xe2, 0x5, 0x18, 0xd, 0x2, 0xdd, 0xde, 0x5, 0x1e, 0x10, 0x2, 0xde, 
       0xdf, 0x5, 0x18, 0xd, 0x2, 0xdf, 0xe1, 0x3, 0x2, 0x2, 0x2, 0xe0, 
       0xdd, 0x3, 0x2, 0x2, 0x2, 0xe1, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xe0, 
       0x3, 0x2, 0x2, 0x2, 0xe2, 0xe3, 0x3, 0x2, 0x2, 0x2, 0xe3, 0x1d, 0x3, 
       0x2, 0x2, 0x2, 0xe4, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xe6, 0x9, 0x6, 
       0x2, 0x2, 0xe6, 0x1f, 0x3, 0x2, 0x2, 0x2, 0xe7, 0xed, 0x5, 0x1c, 
       0xf, 0x2, 0xe8, 0xe9, 0x5, 0x22, 0x12, 0x2, 0xe9, 0xea, 0x5, 0x1c, 
       0xf, 0x2, 0xea, 0xec, 0x3, 0x2, 0x2, 0x2, 0xeb, 0xe8, 0x3, 0x2, 0x2, 
       0x2, 0xec, 0xef, 0x3, 0x2, 0x2, 0x2, 0xed, 0xeb, 0x3, 0x2, 0x2, 0x2, 
       0xed, 0xee, 0x3, 0x2, 0x2, 0x2, 0xee, 0x21, 0x3, 0x2, 0x2, 0x2, 0xef, 
       0xed, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xf1, 0x9, 0x7, 0x2, 0x2, 0xf1, 0x23, 
       0x3, 0x2, 0x2, 0x2, 0xf2, 0xf8, 0x5, 0x20, 0x11, 0x2, 0xf3, 0xf4, 
       0x5, 0x26, 0x14, 0x2, 0xf4, 0xf5, 0x5, 0x20, 0x11, 0x2, 0xf5, 0xf7, 
       0x3, 0x2, 0x2, 0x2, 0xf6, 0xf3, 0x3, 0x2, 0x2, 0x2, 0xf7, 0xfa, 0x3, 
       0x2, 0x2, 0x2, 0xf8, 0xf6, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xf9, 0x3, 0x2, 
       0x2, 0x2, 0xf9, 0x25, 0x3, 0x2, 0x2, 0x2, 0xfa, 0xf8, 0x3, 0x2, 0x2, 
       0x2, 0xfb, 0xfc, 0x9, 0x8, 0x2, 0x2, 0xfc, 0x27, 0x3, 0x2, 0x2, 0x2, 
       0xfd, 0x103, 0x5, 0x24, 0x13, 0x2, 0xfe, 0xff, 0x5, 0x2a, 0x16, 0x2, 
       0xff, 0x100, 0x5, 0x24, 0x13, 0x2, 0x100, 0x102, 0x3, 0x2, 0x2, 0x2, 
       0x101, 0xfe, 0x3, 0x2, 0x2, 0x2, 0x102, 0x105, 0x3, 0x2, 0x2, 0x2, 
       0x103, 0x101, 0x3, 0x2, 0x2, 0x2, 0x103, 0x104, 0x3, 0x2, 0x2, 0x2, 
       0x104, 0x29, 0x3, 0x2, 0x2, 0x2, 0x105, 0x103, 0x3, 0x2, 0x2, 0x2, 
       0x106, 0x107, 0x7, 0x42, 0x2, 0x2, 0x107, 0x2b, 0x3, 0x2, 0x2, 0x2, 
       0x108, 0x10e, 0x5, 0x28, 0x15, 0x2, 0x109, 0x10a, 0x5, 0x2e, 0x18, 
       0x2, 0x10a, 0x10b, 0x5, 0x28, 0x15, 0x2, 0x10b, 0x10d, 0x3, 0x2, 
       0x2, 0x2, 0x10c, 0x109, 0x3, 0x2, 0x2, 0x2, 0x10d, 0x110, 0x3, 0x2, 
       0x2, 0x2, 0x10e, 0x10c, 0x3, 0x2, 0x2, 0x2, 0x10e, 0x10f, 0x3, 0x2, 
       0x2, 0x2, 0x10f, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x110, 0x10e, 0x3, 0x2, 
       0x2, 0x2, 0x111, 0x112, 0x7, 0x46, 0x2, 0x2, 0x112, 0x2f, 0x3, 0x2, 
       0x2, 0x2, 0x113, 0x119, 0x5, 0x2c, 0x17, 0x2, 0x114, 0x115, 0x5, 
       0x32, 0x1a, 0x2, 0x115, 0x116, 0x5, 0x2c, 0x17, 0x2, 0x116, 0x118, 
       0x3, 0x2, 0x2, 0x2, 0x117, 0x114, 0x3, 0x2, 0x2, 0x2, 0x118, 0x11b, 
       0x3, 0x2, 0x2, 0x2, 0x119, 0x117, 0x3, 0x2, 0x2, 0x2, 0x119, 0x11a, 
       0x3, 0x2, 0x2, 0x2, 0x11a, 0x31, 0x3, 0x2, 0x2, 0x2, 0x11b, 0x119, 
       0x3, 0x2, 0x2, 0x2, 0x11c, 0x11d, 0x7, 0x43, 0x2, 0x2, 0x11d, 0x33, 
       0x3, 0x2, 0x2, 0x2, 0x11e, 0x124, 0x5, 0x30, 0x19, 0x2, 0x11f, 0x120, 
       0x5, 0x36, 0x1c, 0x2, 0x120, 0x121, 0x5, 0x30, 0x19, 0x2, 0x121, 
       0x123, 0x3, 0x2, 0x2, 0x2, 0x122, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x123, 
       0x126, 0x3, 0x2, 0x2, 0x2, 0x124, 0x122, 0x3, 0x2, 0x2, 0x2, 0x124, 
       0x125, 0x3, 0x2, 0x2, 0x2, 0x125, 0x35, 0x3, 0x2, 0x2, 0x2, 0x126, 
       0x124, 0x3, 0x2, 0x2, 0x2, 0x127, 0x128, 0x7, 0x44, 0x2, 0x2, 0x128, 
       0x37, 0x3, 0x2, 0x2, 0x2, 0x129, 0x12f, 0x5, 0x34, 0x1b, 0x2, 0x12a, 
       0x12b, 0x5, 0x3a, 0x1e, 0x2, 0x12b, 0x12c, 0x5, 0x34, 0x1b, 0x2, 
       0x12c, 0x12e, 0x3, 0x2, 0x2, 0x2, 0x12d, 0x12a, 0x3, 0x2, 0x2, 0x2, 
       0x12e, 0x131, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x12d, 0x3, 0x2, 0x2, 0x2, 
       0x12f, 0x130, 0x3, 0x2, 0x2, 0x2, 0x130, 0x39, 0x3, 0x2, 0x2, 0x2, 
       0x131, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x132, 0x133, 0x7, 0x45, 0x2, 0x2, 
       0x133, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x134, 0x13a, 0x5, 0x38, 0x1d, 0x2, 
       0x135, 0x136, 0x7, 0x49, 0x2, 0x2, 0x136, 0x137, 0x5, 0x42, 0x22, 
       0x2, 0x137, 0x138, 0x7, 0x4a, 0x2, 0x2, 0x138, 0x139, 0x5, 0x3c, 
       0x1f, 0x2, 0x139, 0x13b, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x135, 0x3, 0x2, 
       0x2, 0x2, 0x13a, 0x13b, 0x3, 0x2, 0x2, 0x2, 0x13b, 0x3d, 0x3, 0x2, 
       0x2, 0x2, 0x13c, 0x13d, 0x5, 0xc, 0x7, 0x2, 0x13d, 0x13e, 0x5, 0x40, 
       0x21, 0x2, 0x13e, 0x13f, 0x5, 0x3e, 0x20, 0x2, 0x13f, 0x142, 0x3, 
       0x2, 0x2, 0x2, 0x140, 0x142, 0x5, 0x3c, 0x1f, 0x2, 0x141, 0x13c, 
       0x3, 0x2, 0x2, 0x2, 0x141, 0x140, 0x3, 0x2, 0x2, 0x2, 0x142, 0x3f, 
       0x3, 0x2, 0x2, 0x2, 0x143, 0x144, 0x9, 0x9, 0x2, 0x2, 0x144, 0x41, 
       0x3, 0x2, 0x2, 0x2, 0x145, 0x14a, 0x5, 0x3e, 0x20, 0x2, 0x146, 0x147, 
       0x7, 0x4c, 0x2, 0x2, 0x147, 0x149, 0x5, 0x3e, 0x20, 0x2, 0x148, 0x146, 
       0x3, 0x2, 0x2, 0x2, 0x149, 0x14c, 0x3, 0x2, 0x2, 0x2, 0x14a, 0x148, 
       0x3, 0x2, 0x2, 0x2, 0x14a, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x14b, 0x43, 
       0x3, 0x2, 0x2, 0x2, 0x14c, 0x14a, 0x3, 0x2, 0x2, 0x2, 0x14d, 0x14f, 
       0x5, 0x46, 0x24, 0x2, 0x14e, 0x150, 0x5, 0x4c, 0x27, 0x2, 0x14f, 
       0x14e, 0x3, 0x2, 0x2, 0x2, 0x14f, 0x150, 0x3, 0x2, 0x2, 0x2, 0x150, 
       0x151, 0x3, 0x2, 0x2, 0x2, 0x151, 0x152, 0x7, 0x4b, 0x2, 0x2, 0x152, 
       0x45, 0x3, 0x2, 0x2, 0x2, 0x153, 0x155, 0x5, 0x50, 0x29, 0x2, 0x154, 
       0x153, 0x3, 0x2, 0x2, 0x2, 0x154, 0x155, 0x3, 0x2, 0x2, 0x2, 0x155, 
       0x156, 0x3, 0x2, 0x2, 0x2, 0x156, 0x157, 0x5, 0x48, 0x25, 0x2, 0x157, 
       0x47, 0x3, 0x2, 0x2, 0x2, 0x158, 0x15a, 0x5, 0x4a, 0x26, 0x2, 0x159, 
       0x158, 0x3, 0x2, 0x2, 0x2, 0x15a, 0x15b, 0x3, 0x2, 0x2, 0x2, 0x15b, 
       0x159, 0x3, 0x2, 0x2, 0x2, 0x15b, 0x15c, 0x3, 0x2, 0x2, 0x2, 0x15c, 
       0x15f, 0x3, 0x2, 0x2, 0x2, 0x15d, 0x15f, 0x5, 0x4, 0x3, 0x2, 0x15e, 
       0x159, 0x3, 0x2, 0x2, 0x2, 0x15e, 0x15d, 0x3, 0x2, 0x2, 0x2, 0x15f, 
       0x49, 0x3, 0x2, 0x2, 0x2, 0x160, 0x161, 0x5, 0x52, 0x2a, 0x2, 0x161, 
       0x4b, 0x3, 0x2, 0x2, 0x2, 0x162, 0x167, 0x5, 0x4e, 0x28, 0x2, 0x163, 
       0x164, 0x7, 0x4c, 0x2, 0x2, 0x164, 0x166, 0x5, 0x4e, 0x28, 0x2, 0x165, 
       0x163, 0x3, 0x2, 0x2, 0x2, 0x166, 0x169, 0x3, 0x2, 0x2, 0x2, 0x167, 
       0x165, 0x3, 0x2, 0x2, 0x2, 0x167, 0x168, 0x3, 0x2, 0x2, 0x2, 0x168, 
       0x4d, 0x3, 0x2, 0x2, 0x2, 0x169, 0x167, 0x3, 0x2, 0x2, 0x2, 0x16a, 
       0x16d, 0x5, 0x56, 0x2c, 0x2, 0x16b, 0x16c, 0x7, 0x4d, 0x2, 0x2, 0x16c, 
       0x16e, 0x5, 0x64, 0x33, 0x2, 0x16d, 0x16b, 0x3, 0x2, 0x2, 0x2, 0x16d, 
       0x16e, 0x3, 0x2, 0x2, 0x2, 0x16e, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x16f, 
       0x170, 0x7, 0x1f, 0x2, 0x2, 0x170, 0x51, 0x3, 0x2, 0x2, 0x2, 0x171, 
       0x172, 0x5, 0x54, 0x2b, 0x2, 0x172, 0x53, 0x3, 0x2, 0x2, 0x2, 0x173, 
       0x174, 0x9, 0xa, 0x2, 0x2, 0x174, 0x55, 0x3, 0x2, 0x2, 0x2, 0x175, 
       0x177, 0x5, 0x5a, 0x2e, 0x2, 0x176, 0x175, 0x3, 0x2, 0x2, 0x2, 0x177, 
       0x17a, 0x3, 0x2, 0x2, 0x2, 0x178, 0x176, 0x3, 0x2, 0x2, 0x2, 0x178, 
       0x179, 0x3, 0x2, 0x2, 0x2, 0x179, 0x17b, 0x3, 0x2, 0x2, 0x2, 0x17a, 
       0x178, 0x3, 0x2, 0x2, 0x2, 0x17b, 0x17f, 0x5, 0x5c, 0x2f, 0x2, 0x17c, 
       0x17e, 0x5, 0x58, 0x2d, 0x2, 0x17d, 0x17c, 0x3, 0x2, 0x2, 0x2, 0x17e, 
       0x181, 0x3, 0x2, 0x2, 0x2, 0x17f, 0x17d, 0x3, 0x2, 0x2, 0x2, 0x17f, 
       0x180, 0x3, 0x2, 0x2, 0x2, 0x180, 0x57, 0x3, 0x2, 0x2, 0x2, 0x181, 
       0x17f, 0x3, 0x2, 0x2, 0x2, 0x182, 0x183, 0x7, 0x31, 0x2, 0x2, 0x183, 
       0x184, 0x7, 0x5e, 0x2, 0x2, 0x184, 0x185, 0x7, 0x32, 0x2, 0x2, 0x185, 
       0x59, 0x3, 0x2, 0x2, 0x2, 0x186, 0x187, 0x7, 0x3f, 0x2, 0x2, 0x187, 
       0x5b, 0x3, 0x2, 0x2, 0x2, 0x188, 0x189, 0x5, 0x4, 0x3, 0x2, 0x189, 
       0x5d, 0x3, 0x2, 0x2, 0x2, 0x18a, 0x18b, 0x5, 0x60, 0x31, 0x2, 0x18b, 
       0x5f, 0x3, 0x2, 0x2, 0x2, 0x18c, 0x191, 0x5, 0x62, 0x32, 0x2, 0x18d, 
       0x18e, 0x7, 0x4c, 0x2, 0x2, 0x18e, 0x190, 0x5, 0x62, 0x32, 0x2, 0x18f, 
       0x18d, 0x3, 0x2, 0x2, 0x2, 0x190, 0x193, 0x3, 0x2, 0x2, 0x2, 0x191, 
       0x18f, 0x3, 0x2, 0x2, 0x2, 0x191, 0x192, 0x3, 0x2, 0x2, 0x2, 0x192, 
       0x61, 0x3, 0x2, 0x2, 0x2, 0x193, 0x191, 0x3, 0x2, 0x2, 0x2, 0x194, 
       0x195, 0x5, 0x48, 0x25, 0x2, 0x195, 0x196, 0x5, 0x56, 0x2c, 0x2, 
       0x196, 0x63, 0x3, 0x2, 0x2, 0x2, 0x197, 0x198, 0x5, 0x3e, 0x20, 0x2, 
       0x198, 0x65, 0x3, 0x2, 0x2, 0x2, 0x199, 0x1c5, 0x5, 0x68, 0x35, 0x2, 
       0x19a, 0x19c, 0x5, 0x42, 0x22, 0x2, 0x19b, 0x19a, 0x3, 0x2, 0x2, 
       0x2, 0x19b, 0x19c, 0x3, 0x2, 0x2, 0x2, 0x19c, 0x19d, 0x3, 0x2, 0x2, 
       0x2, 0x19d, 0x1c5, 0x7, 0x4b, 0x2, 0x2, 0x19e, 0x19f, 0x7, 0x12, 
       0x2, 0x2, 0x19f, 0x1a0, 0x7, 0x2f, 0x2, 0x2, 0x1a0, 0x1a1, 0x5, 0x42, 
       0x22, 0x2, 0x1a1, 0x1a2, 0x7, 0x30, 0x2, 0x2, 0x1a2, 0x1a5, 0x5, 
       0x66, 0x34, 0x2, 0x1a3, 0x1a4, 0x7, 0xc, 0x2, 0x2, 0x1a4, 0x1a6, 
       0x5, 0x66, 0x34, 0x2, 0x1a5, 0x1a3, 0x3, 0x2, 0x2, 0x2, 0x1a5, 0x1a6, 
       0x3, 0x2, 0x2, 0x2, 0x1a6, 0x1c5, 0x3, 0x2, 0x2, 0x2, 0x1a7, 0x1a8, 
       0x7, 0x24, 0x2, 0x2, 0x1a8, 0x1a9, 0x7, 0x2f, 0x2, 0x2, 0x1a9, 0x1aa, 
       0x5, 0x42, 0x22, 0x2, 0x1aa, 0x1ab, 0x7, 0x30, 0x2, 0x2, 0x1ab, 0x1ac, 
       0x5, 0x66, 0x34, 0x2, 0x1ac, 0x1c5, 0x3, 0x2, 0x2, 0x2, 0x1ad, 0x1ae, 
       0x7, 0xa, 0x2, 0x2, 0x1ae, 0x1af, 0x5, 0x66, 0x34, 0x2, 0x1af, 0x1b0, 
       0x7, 0x24, 0x2, 0x2, 0x1b0, 0x1b1, 0x7, 0x2f, 0x2, 0x2, 0x1b1, 0x1b2, 
       0x5, 0x42, 0x22, 0x2, 0x1b2, 0x1b3, 0x7, 0x30, 0x2, 0x2, 0x1b3, 0x1b4, 
       0x7, 0x4b, 0x2, 0x2, 0x1b4, 0x1c5, 0x3, 0x2, 0x2, 0x2, 0x1b5, 0x1b6, 
       0x7, 0x10, 0x2, 0x2, 0x1b6, 0x1b7, 0x7, 0x2f, 0x2, 0x2, 0x1b7, 0x1b8, 
       0x5, 0x6c, 0x37, 0x2, 0x1b8, 0x1b9, 0x7, 0x30, 0x2, 0x2, 0x1b9, 0x1ba, 
       0x5, 0x66, 0x34, 0x2, 0x1ba, 0x1c5, 0x3, 0x2, 0x2, 0x2, 0x1bb, 0x1bc, 
       0x7, 0x8, 0x2, 0x2, 0x1bc, 0x1c5, 0x7, 0x4b, 0x2, 0x2, 0x1bd, 0x1be, 
       0x7, 0x4, 0x2, 0x2, 0x1be, 0x1c5, 0x7, 0x4b, 0x2, 0x2, 0x1bf, 0x1c1, 
       0x7, 0x18, 0x2, 0x2, 0x1c0, 0x1c2, 0x5, 0x42, 0x22, 0x2, 0x1c1, 0x1c0, 
       0x3, 0x2, 0x2, 0x2, 0x1c1, 0x1c2, 0x3, 0x2, 0x2, 0x2, 0x1c2, 0x1c3, 
       0x3, 0x2, 0x2, 0x2, 0x1c3, 0x1c5, 0x7, 0x4b, 0x2, 0x2, 0x1c4, 0x199, 
       0x3, 0x2, 0x2, 0x2, 0x1c4, 0x19b, 0x3, 0x2, 0x2, 0x2, 0x1c4, 0x19e, 
       0x3, 0x2, 0x2, 0x2, 0x1c4, 0x1a7, 0x3, 0x2, 0x2, 0x2, 0x1c4, 0x1ad, 
       0x3, 0x2, 0x2, 0x2, 0x1c4, 0x1b5, 0x3, 0x2, 0x2, 0x2, 0x1c4, 0x1bb, 
       0x3, 0x2, 0x2, 0x2, 0x1c4, 0x1bd, 0x3, 0x2, 0x2, 0x2, 0x1c4, 0x1bf, 
       0x3, 0x2, 0x2, 0x2, 0x1c5, 0x67, 0x3, 0x2, 0x2, 0x2, 0x1c6, 0x1ca, 
       0x7, 0x33, 0x2, 0x2, 0x1c7, 0x1c9, 0x5, 0x6a, 0x36, 0x2, 0x1c8, 0x1c7, 
       0x3, 0x2, 0x2, 0x2, 0x1c9, 0x1cc, 0x3, 0x2, 0x2, 0x2, 0x1ca, 0x1c8, 
       0x3, 0x2, 0x2, 0x2, 0x1ca, 0x1cb, 0x3, 0x2, 0x2, 0x2, 0x1cb, 0x1cd, 
       0x3, 0x2, 0x2, 0x2, 0x1cc, 0x1ca, 0x3, 0x2, 0x2, 0x2, 0x1cd, 0x1ce, 
       0x7, 0x34, 0x2, 0x2, 0x1ce, 0x69, 0x3, 0x2, 0x2, 0x2, 0x1cf, 0x1d2, 
       0x5, 0x66, 0x34, 0x2, 0x1d0, 0x1d2, 0x5, 0x44, 0x23, 0x2, 0x1d1, 
       0x1cf, 0x3, 0x2, 0x2, 0x2, 0x1d1, 0x1d0, 0x3, 0x2, 0x2, 0x2, 0x1d2, 
       0x6b, 0x3, 0x2, 0x2, 0x2, 0x1d3, 0x1d5, 0x5, 0x6e, 0x38, 0x2, 0x1d4, 
       0x1d6, 0x5, 0x72, 0x3a, 0x2, 0x1d5, 0x1d4, 0x3, 0x2, 0x2, 0x2, 0x1d5, 
       0x1d6, 0x3, 0x2, 0x2, 0x2, 0x1d6, 0x1d7, 0x3, 0x2, 0x2, 0x2, 0x1d7, 
       0x1d9, 0x7, 0x4b, 0x2, 0x2, 0x1d8, 0x1da, 0x5, 0x70, 0x39, 0x2, 0x1d9, 
       0x1d8, 0x3, 0x2, 0x2, 0x2, 0x1d9, 0x1da, 0x3, 0x2, 0x2, 0x2, 0x1da, 
       0x6d, 0x3, 0x2, 0x2, 0x2, 0x1db, 0x1dd, 0x5, 0x42, 0x22, 0x2, 0x1dc, 
       0x1db, 0x3, 0x2, 0x2, 0x2, 0x1dc, 0x1dd, 0x3, 0x2, 0x2, 0x2, 0x1dd, 
       0x1de, 0x3, 0x2, 0x2, 0x2, 0x1de, 0x1e1, 0x7, 0x4b, 0x2, 0x2, 0x1df, 
       0x1e1, 0x5, 0x44, 0x23, 0x2, 0x1e0, 0x1dc, 0x3, 0x2, 0x2, 0x2, 0x1e0, 
       0x1df, 0x3, 0x2, 0x2, 0x2, 0x1e1, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x1e2, 
       0x1e3, 0x5, 0x42, 0x22, 0x2, 0x1e3, 0x71, 0x3, 0x2, 0x2, 0x2, 0x1e4, 
       0x1e5, 0x5, 0x42, 0x22, 0x2, 0x1e5, 0x73, 0x3, 0x2, 0x2, 0x2, 0x1e6, 
       0x1e8, 0x5, 0x76, 0x3c, 0x2, 0x1e7, 0x1e6, 0x3, 0x2, 0x2, 0x2, 0x1e7, 
       0x1e8, 0x3, 0x2, 0x2, 0x2, 0x1e8, 0x1e9, 0x3, 0x2, 0x2, 0x2, 0x1e9, 
       0x1ea, 0x7, 0x2, 0x2, 0x3, 0x1ea, 0x75, 0x3, 0x2, 0x2, 0x2, 0x1eb, 
       0x1ed, 0x5, 0x78, 0x3d, 0x2, 0x1ec, 0x1eb, 0x3, 0x2, 0x2, 0x2, 0x1ed, 
       0x1ee, 0x3, 0x2, 0x2, 0x2, 0x1ee, 0x1ec, 0x3, 0x2, 0x2, 0x2, 0x1ee, 
       0x1ef, 0x3, 0x2, 0x2, 0x2, 0x1ef, 0x77, 0x3, 0x2, 0x2, 0x2, 0x1f0, 
       0x1f4, 0x5, 0x7c, 0x3f, 0x2, 0x1f1, 0x1f4, 0x5, 0x7a, 0x3e, 0x2, 
       0x1f2, 0x1f4, 0x7, 0x4b, 0x2, 0x2, 0x1f3, 0x1f0, 0x3, 0x2, 0x2, 0x2, 
       0x1f3, 0x1f1, 0x3, 0x2, 0x2, 0x2, 0x1f3, 0x1f2, 0x3, 0x2, 0x2, 0x2, 
       0x1f4, 0x79, 0x3, 0x2, 0x2, 0x2, 0x1f5, 0x1f6, 0x5, 0x44, 0x23, 0x2, 
       0x1f6, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x1f7, 0x1f9, 0x5, 0x46, 0x24, 0x2, 
       0x1f8, 0x1f7, 0x3, 0x2, 0x2, 0x2, 0x1f8, 0x1f9, 0x3, 0x2, 0x2, 0x2, 
       0x1f9, 0x1fa, 0x3, 0x2, 0x2, 0x2, 0x1fa, 0x1fb, 0x5, 0x56, 0x2c, 
       0x2, 0x1fb, 0x1fd, 0x7, 0x2f, 0x2, 0x2, 0x1fc, 0x1fe, 0x5, 0x5e, 
       0x30, 0x2, 0x1fd, 0x1fc, 0x3, 0x2, 0x2, 0x2, 0x1fd, 0x1fe, 0x3, 0x2, 
       0x2, 0x2, 0x1fe, 0x1ff, 0x3, 0x2, 0x2, 0x2, 0x1ff, 0x200, 0x7, 0x30, 
       0x2, 0x2, 0x200, 0x201, 0x5, 0x68, 0x35, 0x2, 0x201, 0x7d, 0x3, 0x2, 
       0x2, 0x2, 0x32, 0x84, 0x8d, 0x8f, 0x98, 0x9b, 0x9d, 0xa5, 0xab, 0xb2, 
       0xbe, 0xc4, 0xcc, 0xd7, 0xe2, 0xed, 0xf8, 0x103, 0x10e, 0x119, 0x124, 
       0x12f, 0x13a, 0x141, 0x14a, 0x14f, 0x154, 0x15b, 0x15e, 0x167, 0x16d, 
       0x178, 0x17f, 0x191, 0x19b, 0x1a5, 0x1c1, 0x1c4, 0x1ca, 0x1d1, 0x1d5, 
       0x1d9, 0x1dc, 0x1e0, 0x1e7, 0x1ee, 0x1f3, 0x1f8, 0x1fd, 
  };

  _serializedATN.insert(_serializedATN.end(), serializedATNSegment0,
    serializedATNSegment0 + sizeof(serializedATNSegment0) / sizeof(serializedATNSegment0[0]));


  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

CParser::Initializer CParser::_init;
