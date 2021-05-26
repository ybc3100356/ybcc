
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

tree::TerminalNode* CParser::PrimaryExpressionContext::Identifier() {
  return getToken(CParser::Identifier, 0);
}

tree::TerminalNode* CParser::PrimaryExpressionContext::Constant() {
  return getToken(CParser::Constant, 0);
}

std::vector<tree::TerminalNode *> CParser::PrimaryExpressionContext::StringLiteral() {
  return getTokens(CParser::StringLiteral);
}

tree::TerminalNode* CParser::PrimaryExpressionContext::StringLiteral(size_t i) {
  return getToken(CParser::StringLiteral, i);
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
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(161);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(150);
        match(CParser::Identifier);
        break;
      }

      case CParser::Constant: {
        enterOuterAlt(_localctx, 2);
        setState(151);
        match(CParser::Constant);
        break;
      }

      case CParser::StringLiteral: {
        enterOuterAlt(_localctx, 3);
        setState(153); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(152);
          match(CParser::StringLiteral);
          setState(155); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while (_la == CParser::StringLiteral);
        break;
      }

      case CParser::LeftParen: {
        enterOuterAlt(_localctx, 4);
        setState(157);
        match(CParser::LeftParen);
        setState(158);
        expression();
        setState(159);
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

//----------------- PostfixExpressionContext ------------------------------------------------------------------

CParser::PostfixExpressionContext::PostfixExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::PrimaryExpressionContext* CParser::PostfixExpressionContext::primaryExpression() {
  return getRuleContext<CParser::PrimaryExpressionContext>(0);
}

std::vector<tree::TerminalNode *> CParser::PostfixExpressionContext::LeftParen() {
  return getTokens(CParser::LeftParen);
}

tree::TerminalNode* CParser::PostfixExpressionContext::LeftParen(size_t i) {
  return getToken(CParser::LeftParen, i);
}

CParser::TypeNameContext* CParser::PostfixExpressionContext::typeName() {
  return getRuleContext<CParser::TypeNameContext>(0);
}

std::vector<tree::TerminalNode *> CParser::PostfixExpressionContext::RightParen() {
  return getTokens(CParser::RightParen);
}

tree::TerminalNode* CParser::PostfixExpressionContext::RightParen(size_t i) {
  return getToken(CParser::RightParen, i);
}

tree::TerminalNode* CParser::PostfixExpressionContext::LeftBrace() {
  return getToken(CParser::LeftBrace, 0);
}

CParser::InitializerListContext* CParser::PostfixExpressionContext::initializerList() {
  return getRuleContext<CParser::InitializerListContext>(0);
}

tree::TerminalNode* CParser::PostfixExpressionContext::RightBrace() {
  return getToken(CParser::RightBrace, 0);
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

std::vector<tree::TerminalNode *> CParser::PostfixExpressionContext::Identifier() {
  return getTokens(CParser::Identifier);
}

tree::TerminalNode* CParser::PostfixExpressionContext::Identifier(size_t i) {
  return getToken(CParser::Identifier, i);
}

std::vector<tree::TerminalNode *> CParser::PostfixExpressionContext::Dot() {
  return getTokens(CParser::Dot);
}

tree::TerminalNode* CParser::PostfixExpressionContext::Dot(size_t i) {
  return getToken(CParser::Dot, i);
}

std::vector<tree::TerminalNode *> CParser::PostfixExpressionContext::Arrow() {
  return getTokens(CParser::Arrow);
}

tree::TerminalNode* CParser::PostfixExpressionContext::Arrow(size_t i) {
  return getToken(CParser::Arrow, i);
}

std::vector<tree::TerminalNode *> CParser::PostfixExpressionContext::PlusPlus() {
  return getTokens(CParser::PlusPlus);
}

tree::TerminalNode* CParser::PostfixExpressionContext::PlusPlus(size_t i) {
  return getToken(CParser::PlusPlus, i);
}

std::vector<tree::TerminalNode *> CParser::PostfixExpressionContext::MinusMinus() {
  return getTokens(CParser::MinusMinus);
}

tree::TerminalNode* CParser::PostfixExpressionContext::MinusMinus(size_t i) {
  return getToken(CParser::MinusMinus, i);
}

tree::TerminalNode* CParser::PostfixExpressionContext::Comma() {
  return getToken(CParser::Comma, 0);
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
  enterRule(_localctx, 2, CParser::RulePostfixExpression);
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
    setState(174);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      setState(163);
      primaryExpression();
      break;
    }

    case 2: {
      setState(164);
      match(CParser::LeftParen);
      setState(165);
      typeName();
      setState(166);
      match(CParser::RightParen);
      setState(167);
      match(CParser::LeftBrace);
      setState(168);
      initializerList();
      setState(170);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CParser::Comma) {
        setState(169);
        match(CParser::Comma);
      }
      setState(172);
      match(CParser::RightBrace);
      break;
    }

    default:
      break;
    }
    setState(190);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 45) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 45)) & ((1ULL << (CParser::LeftParen - 45))
      | (1ULL << (CParser::LeftBracket - 45))
      | (1ULL << (CParser::PlusPlus - 45))
      | (1ULL << (CParser::MinusMinus - 45))
      | (1ULL << (CParser::Arrow - 45))
      | (1ULL << (CParser::Dot - 45)))) != 0)) {
      setState(188);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case CParser::LeftBracket: {
          setState(176);
          match(CParser::LeftBracket);
          setState(177);
          expression();
          setState(178);
          match(CParser::RightBracket);
          break;
        }

        case CParser::LeftParen: {
          setState(180);
          match(CParser::LeftParen);
          setState(182);
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
            | (1ULL << (CParser::Constant - 64))
            | (1ULL << (CParser::DigitSequence - 64))
            | (1ULL << (CParser::StringLiteral - 64)))) != 0)) {
            setState(181);
            argumentExpressionList();
          }
          setState(184);
          match(CParser::RightParen);
          break;
        }

        case CParser::Arrow:
        case CParser::Dot: {
          setState(185);
          _la = _input->LA(1);
          if (!(_la == CParser::Arrow

          || _la == CParser::Dot)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(186);
          match(CParser::Identifier);
          break;
        }

        case CParser::PlusPlus:
        case CParser::MinusMinus: {
          setState(187);
          _la = _input->LA(1);
          if (!(_la == CParser::PlusPlus

          || _la == CParser::MinusMinus)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(192);
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
  enterRule(_localctx, 4, CParser::RuleArgumentExpressionList);
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
    setState(193);
    assignmentExpression();
    setState(198);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CParser::Comma) {
      setState(194);
      match(CParser::Comma);
      setState(195);
      assignmentExpression();
      setState(200);
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

CParser::CastExpressionContext* CParser::UnaryExpressionContext::castExpression() {
  return getRuleContext<CParser::CastExpressionContext>(0);
}

std::vector<tree::TerminalNode *> CParser::UnaryExpressionContext::Sizeof() {
  return getTokens(CParser::Sizeof);
}

tree::TerminalNode* CParser::UnaryExpressionContext::Sizeof(size_t i) {
  return getToken(CParser::Sizeof, i);
}

tree::TerminalNode* CParser::UnaryExpressionContext::LeftParen() {
  return getToken(CParser::LeftParen, 0);
}

CParser::TypeNameContext* CParser::UnaryExpressionContext::typeName() {
  return getRuleContext<CParser::TypeNameContext>(0);
}

tree::TerminalNode* CParser::UnaryExpressionContext::RightParen() {
  return getToken(CParser::RightParen, 0);
}

std::vector<tree::TerminalNode *> CParser::UnaryExpressionContext::PlusPlus() {
  return getTokens(CParser::PlusPlus);
}

tree::TerminalNode* CParser::UnaryExpressionContext::PlusPlus(size_t i) {
  return getToken(CParser::PlusPlus, i);
}

std::vector<tree::TerminalNode *> CParser::UnaryExpressionContext::MinusMinus() {
  return getTokens(CParser::MinusMinus);
}

tree::TerminalNode* CParser::UnaryExpressionContext::MinusMinus(size_t i) {
  return getToken(CParser::MinusMinus, i);
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
  enterRule(_localctx, 6, CParser::RuleUnaryExpression);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(204);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(201);
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
      setState(206);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    }
    setState(216);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::LeftParen:
      case CParser::Identifier:
      case CParser::Constant:
      case CParser::StringLiteral: {
        setState(207);
        postfixExpression();
        break;
      }

      case CParser::Plus:
      case CParser::Minus:
      case CParser::Star:
      case CParser::And:
      case CParser::Not:
      case CParser::Tilde: {
        setState(208);
        unaryOperator();
        setState(209);
        castExpression();
        break;
      }

      case CParser::Sizeof: {
        setState(211);
        match(CParser::Sizeof);
        setState(212);
        match(CParser::LeftParen);
        setState(213);
        typeName();
        setState(214);
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
  enterRule(_localctx, 8, CParser::RuleUnaryOperator);
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

CParser::UnaryExpressionContext* CParser::CastExpressionContext::unaryExpression() {
  return getRuleContext<CParser::UnaryExpressionContext>(0);
}

tree::TerminalNode* CParser::CastExpressionContext::DigitSequence() {
  return getToken(CParser::DigitSequence, 0);
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
  enterRule(_localctx, 10, CParser::RuleCastExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(227);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(220);
      match(CParser::LeftParen);
      setState(221);
      typeName();
      setState(222);
      match(CParser::RightParen);
      setState(223);
      castExpression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(225);
      unaryExpression();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(226);
      match(CParser::DigitSequence);
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

std::vector<tree::TerminalNode *> CParser::MultiplicativeExpressionContext::Star() {
  return getTokens(CParser::Star);
}

tree::TerminalNode* CParser::MultiplicativeExpressionContext::Star(size_t i) {
  return getToken(CParser::Star, i);
}

std::vector<tree::TerminalNode *> CParser::MultiplicativeExpressionContext::Div() {
  return getTokens(CParser::Div);
}

tree::TerminalNode* CParser::MultiplicativeExpressionContext::Div(size_t i) {
  return getToken(CParser::Div, i);
}

std::vector<tree::TerminalNode *> CParser::MultiplicativeExpressionContext::Mod() {
  return getTokens(CParser::Mod);
}

tree::TerminalNode* CParser::MultiplicativeExpressionContext::Mod(size_t i) {
  return getToken(CParser::Mod, i);
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
  enterRule(_localctx, 12, CParser::RuleMultiplicativeExpression);
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
    castExpression();
    setState(234);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CParser::Star)
      | (1ULL << CParser::Div)
      | (1ULL << CParser::Mod))) != 0)) {
      setState(230);
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
      setState(231);
      castExpression();
      setState(236);
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

std::vector<tree::TerminalNode *> CParser::AdditiveExpressionContext::Plus() {
  return getTokens(CParser::Plus);
}

tree::TerminalNode* CParser::AdditiveExpressionContext::Plus(size_t i) {
  return getToken(CParser::Plus, i);
}

std::vector<tree::TerminalNode *> CParser::AdditiveExpressionContext::Minus() {
  return getTokens(CParser::Minus);
}

tree::TerminalNode* CParser::AdditiveExpressionContext::Minus(size_t i) {
  return getToken(CParser::Minus, i);
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
  enterRule(_localctx, 14, CParser::RuleAdditiveExpression);
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
    setState(237);
    multiplicativeExpression();
    setState(242);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CParser::Plus

    || _la == CParser::Minus) {
      setState(238);
      _la = _input->LA(1);
      if (!(_la == CParser::Plus

      || _la == CParser::Minus)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(239);
      multiplicativeExpression();
      setState(244);
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

std::vector<tree::TerminalNode *> CParser::ShiftExpressionContext::LeftShift() {
  return getTokens(CParser::LeftShift);
}

tree::TerminalNode* CParser::ShiftExpressionContext::LeftShift(size_t i) {
  return getToken(CParser::LeftShift, i);
}

std::vector<tree::TerminalNode *> CParser::ShiftExpressionContext::RightShift() {
  return getTokens(CParser::RightShift);
}

tree::TerminalNode* CParser::ShiftExpressionContext::RightShift(size_t i) {
  return getToken(CParser::RightShift, i);
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
  enterRule(_localctx, 16, CParser::RuleShiftExpression);
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
    setState(245);
    additiveExpression();
    setState(250);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CParser::LeftShift

    || _la == CParser::RightShift) {
      setState(246);
      _la = _input->LA(1);
      if (!(_la == CParser::LeftShift

      || _la == CParser::RightShift)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(247);
      additiveExpression();
      setState(252);
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

std::vector<tree::TerminalNode *> CParser::RelationalExpressionContext::Less() {
  return getTokens(CParser::Less);
}

tree::TerminalNode* CParser::RelationalExpressionContext::Less(size_t i) {
  return getToken(CParser::Less, i);
}

std::vector<tree::TerminalNode *> CParser::RelationalExpressionContext::Greater() {
  return getTokens(CParser::Greater);
}

tree::TerminalNode* CParser::RelationalExpressionContext::Greater(size_t i) {
  return getToken(CParser::Greater, i);
}

std::vector<tree::TerminalNode *> CParser::RelationalExpressionContext::LessEqual() {
  return getTokens(CParser::LessEqual);
}

tree::TerminalNode* CParser::RelationalExpressionContext::LessEqual(size_t i) {
  return getToken(CParser::LessEqual, i);
}

std::vector<tree::TerminalNode *> CParser::RelationalExpressionContext::GreaterEqual() {
  return getTokens(CParser::GreaterEqual);
}

tree::TerminalNode* CParser::RelationalExpressionContext::GreaterEqual(size_t i) {
  return getToken(CParser::GreaterEqual, i);
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
  enterRule(_localctx, 18, CParser::RuleRelationalExpression);
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
    setState(253);
    shiftExpression();
    setState(258);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CParser::Less)
      | (1ULL << CParser::LessEqual)
      | (1ULL << CParser::Greater)
      | (1ULL << CParser::GreaterEqual))) != 0)) {
      setState(254);
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
      setState(255);
      shiftExpression();
      setState(260);
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

std::vector<tree::TerminalNode *> CParser::EqualityExpressionContext::Equal() {
  return getTokens(CParser::Equal);
}

tree::TerminalNode* CParser::EqualityExpressionContext::Equal(size_t i) {
  return getToken(CParser::Equal, i);
}

std::vector<tree::TerminalNode *> CParser::EqualityExpressionContext::NotEqual() {
  return getTokens(CParser::NotEqual);
}

tree::TerminalNode* CParser::EqualityExpressionContext::NotEqual(size_t i) {
  return getToken(CParser::NotEqual, i);
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
  enterRule(_localctx, 20, CParser::RuleEqualityExpression);
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
    setState(261);
    relationalExpression();
    setState(266);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CParser::Equal

    || _la == CParser::NotEqual) {
      setState(262);
      _la = _input->LA(1);
      if (!(_la == CParser::Equal

      || _la == CParser::NotEqual)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(263);
      relationalExpression();
      setState(268);
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

std::vector<tree::TerminalNode *> CParser::AndExpressionContext::And() {
  return getTokens(CParser::And);
}

tree::TerminalNode* CParser::AndExpressionContext::And(size_t i) {
  return getToken(CParser::And, i);
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
  enterRule(_localctx, 22, CParser::RuleAndExpression);
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
    setState(269);
    equalityExpression();
    setState(274);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CParser::And) {
      setState(270);
      match(CParser::And);
      setState(271);
      equalityExpression();
      setState(276);
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

std::vector<tree::TerminalNode *> CParser::ExclusiveOrExpressionContext::Caret() {
  return getTokens(CParser::Caret);
}

tree::TerminalNode* CParser::ExclusiveOrExpressionContext::Caret(size_t i) {
  return getToken(CParser::Caret, i);
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
  enterRule(_localctx, 24, CParser::RuleExclusiveOrExpression);
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
    setState(277);
    andExpression();
    setState(282);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CParser::Caret) {
      setState(278);
      match(CParser::Caret);
      setState(279);
      andExpression();
      setState(284);
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

std::vector<tree::TerminalNode *> CParser::InclusiveOrExpressionContext::Or() {
  return getTokens(CParser::Or);
}

tree::TerminalNode* CParser::InclusiveOrExpressionContext::Or(size_t i) {
  return getToken(CParser::Or, i);
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
  enterRule(_localctx, 26, CParser::RuleInclusiveOrExpression);
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
    setState(285);
    exclusiveOrExpression();
    setState(290);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CParser::Or) {
      setState(286);
      match(CParser::Or);
      setState(287);
      exclusiveOrExpression();
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

std::vector<tree::TerminalNode *> CParser::LogicalAndExpressionContext::AndAnd() {
  return getTokens(CParser::AndAnd);
}

tree::TerminalNode* CParser::LogicalAndExpressionContext::AndAnd(size_t i) {
  return getToken(CParser::AndAnd, i);
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
  enterRule(_localctx, 28, CParser::RuleLogicalAndExpression);
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
    setState(293);
    inclusiveOrExpression();
    setState(298);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CParser::AndAnd) {
      setState(294);
      match(CParser::AndAnd);
      setState(295);
      inclusiveOrExpression();
      setState(300);
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

std::vector<tree::TerminalNode *> CParser::LogicalOrExpressionContext::OrOr() {
  return getTokens(CParser::OrOr);
}

tree::TerminalNode* CParser::LogicalOrExpressionContext::OrOr(size_t i) {
  return getToken(CParser::OrOr, i);
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
  enterRule(_localctx, 30, CParser::RuleLogicalOrExpression);
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
    setState(301);
    logicalAndExpression();
    setState(306);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CParser::OrOr) {
      setState(302);
      match(CParser::OrOr);
      setState(303);
      logicalAndExpression();
      setState(308);
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
  enterRule(_localctx, 32, CParser::RuleConditionalExpression);
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
    setState(309);
    logicalOrExpression();
    setState(315);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CParser::Question) {
      setState(310);
      match(CParser::Question);
      setState(311);
      expression();
      setState(312);
      match(CParser::Colon);
      setState(313);
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

CParser::ConditionalExpressionContext* CParser::AssignmentExpressionContext::conditionalExpression() {
  return getRuleContext<CParser::ConditionalExpressionContext>(0);
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

tree::TerminalNode* CParser::AssignmentExpressionContext::DigitSequence() {
  return getToken(CParser::DigitSequence, 0);
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
  enterRule(_localctx, 34, CParser::RuleAssignmentExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(323);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(317);
      conditionalExpression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(318);
      unaryExpression();
      setState(319);
      assignmentOperator();
      setState(320);
      assignmentExpression();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(322);
      match(CParser::DigitSequence);
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
  enterRule(_localctx, 36, CParser::RuleAssignmentOperator);
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
    setState(325);
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
  enterRule(_localctx, 38, CParser::RuleExpression);
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
    setState(327);
    assignmentExpression();
    setState(332);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CParser::Comma) {
      setState(328);
      match(CParser::Comma);
      setState(329);
      assignmentExpression();
      setState(334);
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

//----------------- ConstantExpressionContext ------------------------------------------------------------------

CParser::ConstantExpressionContext::ConstantExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::ConditionalExpressionContext* CParser::ConstantExpressionContext::conditionalExpression() {
  return getRuleContext<CParser::ConditionalExpressionContext>(0);
}


size_t CParser::ConstantExpressionContext::getRuleIndex() const {
  return CParser::RuleConstantExpression;
}


antlrcpp::Any CParser::ConstantExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitConstantExpression(this);
  else
    return visitor->visitChildren(this);
}

CParser::ConstantExpressionContext* CParser::constantExpression() {
  ConstantExpressionContext *_localctx = _tracker.createInstance<ConstantExpressionContext>(_ctx, getState());
  enterRule(_localctx, 40, CParser::RuleConstantExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(335);
    conditionalExpression();
   
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

CParser::StaticAssertDeclarationContext* CParser::DeclarationContext::staticAssertDeclaration() {
  return getRuleContext<CParser::StaticAssertDeclarationContext>(0);
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
  enterRule(_localctx, 42, CParser::RuleDeclaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(344);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::Char:
      case CParser::Double:
      case CParser::Float:
      case CParser::Int:
      case CParser::Long:
      case CParser::Short:
      case CParser::Signed:
      case CParser::Typedef:
      case CParser::Unsigned:
      case CParser::Void:
      case CParser::Bool: {
        enterOuterAlt(_localctx, 1);
        setState(337);
        declarationSpecifiers();
        setState(339);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == CParser::LeftParen

        || _la == CParser::Identifier) {
          setState(338);
          initDeclaratorList();
        }
        setState(341);
        match(CParser::Semi);
        break;
      }

      case CParser::StaticAssert: {
        enterOuterAlt(_localctx, 2);
        setState(343);
        staticAssertDeclaration();
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

//----------------- DeclarationSpecifiersContext ------------------------------------------------------------------

CParser::DeclarationSpecifiersContext::DeclarationSpecifiersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::DeclarationSpecifierListContext* CParser::DeclarationSpecifiersContext::declarationSpecifierList() {
  return getRuleContext<CParser::DeclarationSpecifierListContext>(0);
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
  enterRule(_localctx, 44, CParser::RuleDeclarationSpecifiers);
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
    setState(347);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CParser::Typedef) {
      setState(346);
      typedefSpecifier();
    }
    setState(349);
    declarationSpecifierList();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationSpecifierListContext ------------------------------------------------------------------

CParser::DeclarationSpecifierListContext::DeclarationSpecifierListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CParser::DeclarationSpecifierContext *> CParser::DeclarationSpecifierListContext::declarationSpecifier() {
  return getRuleContexts<CParser::DeclarationSpecifierContext>();
}

CParser::DeclarationSpecifierContext* CParser::DeclarationSpecifierListContext::declarationSpecifier(size_t i) {
  return getRuleContext<CParser::DeclarationSpecifierContext>(i);
}


size_t CParser::DeclarationSpecifierListContext::getRuleIndex() const {
  return CParser::RuleDeclarationSpecifierList;
}


antlrcpp::Any CParser::DeclarationSpecifierListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitDeclarationSpecifierList(this);
  else
    return visitor->visitChildren(this);
}

CParser::DeclarationSpecifierListContext* CParser::declarationSpecifierList() {
  DeclarationSpecifierListContext *_localctx = _tracker.createInstance<DeclarationSpecifierListContext>(_ctx, getState());
  enterRule(_localctx, 46, CParser::RuleDeclarationSpecifierList);
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
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(351);
      declarationSpecifier();
      setState(354); 
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
  enterRule(_localctx, 48, CParser::RuleDeclarationSpecifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(356);
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
  enterRule(_localctx, 50, CParser::RuleInitDeclaratorList);
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
    setState(358);
    initDeclarator();
    setState(363);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CParser::Comma) {
      setState(359);
      match(CParser::Comma);
      setState(360);
      initDeclarator();
      setState(365);
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
  enterRule(_localctx, 52, CParser::RuleInitDeclarator);
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
    setState(366);
    declarator();
    setState(369);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CParser::Assign) {
      setState(367);
      match(CParser::Assign);
      setState(368);
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
  enterRule(_localctx, 54, CParser::RuleTypedefSpecifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(371);
    match(CParser::Typedef);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StorageClassSpecifierContext ------------------------------------------------------------------

CParser::StorageClassSpecifierContext::StorageClassSpecifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::StorageClassSpecifierContext::Extern() {
  return getToken(CParser::Extern, 0);
}

tree::TerminalNode* CParser::StorageClassSpecifierContext::Static() {
  return getToken(CParser::Static, 0);
}

tree::TerminalNode* CParser::StorageClassSpecifierContext::Auto() {
  return getToken(CParser::Auto, 0);
}

tree::TerminalNode* CParser::StorageClassSpecifierContext::Register() {
  return getToken(CParser::Register, 0);
}


size_t CParser::StorageClassSpecifierContext::getRuleIndex() const {
  return CParser::RuleStorageClassSpecifier;
}


antlrcpp::Any CParser::StorageClassSpecifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitStorageClassSpecifier(this);
  else
    return visitor->visitChildren(this);
}

CParser::StorageClassSpecifierContext* CParser::storageClassSpecifier() {
  StorageClassSpecifierContext *_localctx = _tracker.createInstance<StorageClassSpecifierContext>(_ctx, getState());
  enterRule(_localctx, 56, CParser::RuleStorageClassSpecifier);
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
    setState(373);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CParser::Auto)
      | (1ULL << CParser::Extern)
      | (1ULL << CParser::Register)
      | (1ULL << CParser::Static))) != 0))) {
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
  enterRule(_localctx, 58, CParser::RuleTypeSpecifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(375);
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
  enterRule(_localctx, 60, CParser::RuleSimpleTypeSpecifier);
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
    setState(377);
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

//----------------- StructOrUnionSpecifierContext ------------------------------------------------------------------

CParser::StructOrUnionSpecifierContext::StructOrUnionSpecifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::StructOrUnionContext* CParser::StructOrUnionSpecifierContext::structOrUnion() {
  return getRuleContext<CParser::StructOrUnionContext>(0);
}

tree::TerminalNode* CParser::StructOrUnionSpecifierContext::LeftBrace() {
  return getToken(CParser::LeftBrace, 0);
}

CParser::StructDeclarationListContext* CParser::StructOrUnionSpecifierContext::structDeclarationList() {
  return getRuleContext<CParser::StructDeclarationListContext>(0);
}

tree::TerminalNode* CParser::StructOrUnionSpecifierContext::RightBrace() {
  return getToken(CParser::RightBrace, 0);
}

tree::TerminalNode* CParser::StructOrUnionSpecifierContext::Identifier() {
  return getToken(CParser::Identifier, 0);
}


size_t CParser::StructOrUnionSpecifierContext::getRuleIndex() const {
  return CParser::RuleStructOrUnionSpecifier;
}


antlrcpp::Any CParser::StructOrUnionSpecifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitStructOrUnionSpecifier(this);
  else
    return visitor->visitChildren(this);
}

CParser::StructOrUnionSpecifierContext* CParser::structOrUnionSpecifier() {
  StructOrUnionSpecifierContext *_localctx = _tracker.createInstance<StructOrUnionSpecifierContext>(_ctx, getState());
  enterRule(_localctx, 62, CParser::RuleStructOrUnionSpecifier);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(390);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(379);
      structOrUnion();
      setState(381);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CParser::Identifier) {
        setState(380);
        match(CParser::Identifier);
      }
      setState(383);
      match(CParser::LeftBrace);
      setState(384);
      structDeclarationList();
      setState(385);
      match(CParser::RightBrace);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(387);
      structOrUnion();
      setState(388);
      match(CParser::Identifier);
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

//----------------- StructOrUnionContext ------------------------------------------------------------------

CParser::StructOrUnionContext::StructOrUnionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::StructOrUnionContext::Struct() {
  return getToken(CParser::Struct, 0);
}

tree::TerminalNode* CParser::StructOrUnionContext::Union() {
  return getToken(CParser::Union, 0);
}


size_t CParser::StructOrUnionContext::getRuleIndex() const {
  return CParser::RuleStructOrUnion;
}


antlrcpp::Any CParser::StructOrUnionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitStructOrUnion(this);
  else
    return visitor->visitChildren(this);
}

CParser::StructOrUnionContext* CParser::structOrUnion() {
  StructOrUnionContext *_localctx = _tracker.createInstance<StructOrUnionContext>(_ctx, getState());
  enterRule(_localctx, 64, CParser::RuleStructOrUnion);
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
    setState(392);
    _la = _input->LA(1);
    if (!(_la == CParser::Struct

    || _la == CParser::Union)) {
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

//----------------- StructDeclarationListContext ------------------------------------------------------------------

CParser::StructDeclarationListContext::StructDeclarationListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CParser::StructDeclarationContext *> CParser::StructDeclarationListContext::structDeclaration() {
  return getRuleContexts<CParser::StructDeclarationContext>();
}

CParser::StructDeclarationContext* CParser::StructDeclarationListContext::structDeclaration(size_t i) {
  return getRuleContext<CParser::StructDeclarationContext>(i);
}


size_t CParser::StructDeclarationListContext::getRuleIndex() const {
  return CParser::RuleStructDeclarationList;
}


antlrcpp::Any CParser::StructDeclarationListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitStructDeclarationList(this);
  else
    return visitor->visitChildren(this);
}

CParser::StructDeclarationListContext* CParser::structDeclarationList() {
  StructDeclarationListContext *_localctx = _tracker.createInstance<StructDeclarationListContext>(_ctx, getState());
  enterRule(_localctx, 66, CParser::RuleStructDeclarationList);
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
    setState(395); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(394);
      structDeclaration();
      setState(397); 
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
      | (1ULL << CParser::Bool)
      | (1ULL << CParser::StaticAssert))) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StructDeclarationContext ------------------------------------------------------------------

CParser::StructDeclarationContext::StructDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::SpecifierQualifierListContext* CParser::StructDeclarationContext::specifierQualifierList() {
  return getRuleContext<CParser::SpecifierQualifierListContext>(0);
}

tree::TerminalNode* CParser::StructDeclarationContext::Semi() {
  return getToken(CParser::Semi, 0);
}

CParser::StructDeclaratorListContext* CParser::StructDeclarationContext::structDeclaratorList() {
  return getRuleContext<CParser::StructDeclaratorListContext>(0);
}

CParser::StaticAssertDeclarationContext* CParser::StructDeclarationContext::staticAssertDeclaration() {
  return getRuleContext<CParser::StaticAssertDeclarationContext>(0);
}


size_t CParser::StructDeclarationContext::getRuleIndex() const {
  return CParser::RuleStructDeclaration;
}


antlrcpp::Any CParser::StructDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitStructDeclaration(this);
  else
    return visitor->visitChildren(this);
}

CParser::StructDeclarationContext* CParser::structDeclaration() {
  StructDeclarationContext *_localctx = _tracker.createInstance<StructDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 68, CParser::RuleStructDeclaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(406);
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
        setState(399);
        specifierQualifierList();
        setState(401);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (((((_la - 45) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 45)) & ((1ULL << (CParser::LeftParen - 45))
          | (1ULL << (CParser::Colon - 45))
          | (1ULL << (CParser::Identifier - 45)))) != 0)) {
          setState(400);
          structDeclaratorList();
        }
        setState(403);
        match(CParser::Semi);
        break;
      }

      case CParser::StaticAssert: {
        enterOuterAlt(_localctx, 2);
        setState(405);
        staticAssertDeclaration();
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

//----------------- SpecifierQualifierListContext ------------------------------------------------------------------

CParser::SpecifierQualifierListContext::SpecifierQualifierListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CParser::TypeSpecifierContext *> CParser::SpecifierQualifierListContext::typeSpecifier() {
  return getRuleContexts<CParser::TypeSpecifierContext>();
}

CParser::TypeSpecifierContext* CParser::SpecifierQualifierListContext::typeSpecifier(size_t i) {
  return getRuleContext<CParser::TypeSpecifierContext>(i);
}


size_t CParser::SpecifierQualifierListContext::getRuleIndex() const {
  return CParser::RuleSpecifierQualifierList;
}


antlrcpp::Any CParser::SpecifierQualifierListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitSpecifierQualifierList(this);
  else
    return visitor->visitChildren(this);
}

CParser::SpecifierQualifierListContext* CParser::specifierQualifierList() {
  SpecifierQualifierListContext *_localctx = _tracker.createInstance<SpecifierQualifierListContext>(_ctx, getState());
  enterRule(_localctx, 70, CParser::RuleSpecifierQualifierList);
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
    setState(409); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(408);
      typeSpecifier();
      setState(411); 
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
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StructDeclaratorListContext ------------------------------------------------------------------

CParser::StructDeclaratorListContext::StructDeclaratorListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CParser::StructDeclaratorContext *> CParser::StructDeclaratorListContext::structDeclarator() {
  return getRuleContexts<CParser::StructDeclaratorContext>();
}

CParser::StructDeclaratorContext* CParser::StructDeclaratorListContext::structDeclarator(size_t i) {
  return getRuleContext<CParser::StructDeclaratorContext>(i);
}

std::vector<tree::TerminalNode *> CParser::StructDeclaratorListContext::Comma() {
  return getTokens(CParser::Comma);
}

tree::TerminalNode* CParser::StructDeclaratorListContext::Comma(size_t i) {
  return getToken(CParser::Comma, i);
}


size_t CParser::StructDeclaratorListContext::getRuleIndex() const {
  return CParser::RuleStructDeclaratorList;
}


antlrcpp::Any CParser::StructDeclaratorListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitStructDeclaratorList(this);
  else
    return visitor->visitChildren(this);
}

CParser::StructDeclaratorListContext* CParser::structDeclaratorList() {
  StructDeclaratorListContext *_localctx = _tracker.createInstance<StructDeclaratorListContext>(_ctx, getState());
  enterRule(_localctx, 72, CParser::RuleStructDeclaratorList);
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
    setState(413);
    structDeclarator();
    setState(418);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CParser::Comma) {
      setState(414);
      match(CParser::Comma);
      setState(415);
      structDeclarator();
      setState(420);
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

//----------------- StructDeclaratorContext ------------------------------------------------------------------

CParser::StructDeclaratorContext::StructDeclaratorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::DeclaratorContext* CParser::StructDeclaratorContext::declarator() {
  return getRuleContext<CParser::DeclaratorContext>(0);
}

tree::TerminalNode* CParser::StructDeclaratorContext::Colon() {
  return getToken(CParser::Colon, 0);
}

CParser::ConstantExpressionContext* CParser::StructDeclaratorContext::constantExpression() {
  return getRuleContext<CParser::ConstantExpressionContext>(0);
}


size_t CParser::StructDeclaratorContext::getRuleIndex() const {
  return CParser::RuleStructDeclarator;
}


antlrcpp::Any CParser::StructDeclaratorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitStructDeclarator(this);
  else
    return visitor->visitChildren(this);
}

CParser::StructDeclaratorContext* CParser::structDeclarator() {
  StructDeclaratorContext *_localctx = _tracker.createInstance<StructDeclaratorContext>(_ctx, getState());
  enterRule(_localctx, 74, CParser::RuleStructDeclarator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(427);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(421);
      declarator();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(423);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CParser::LeftParen

      || _la == CParser::Identifier) {
        setState(422);
        declarator();
      }
      setState(425);
      match(CParser::Colon);
      setState(426);
      constantExpression();
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

//----------------- EnumSpecifierContext ------------------------------------------------------------------

CParser::EnumSpecifierContext::EnumSpecifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::EnumSpecifierContext::Enum() {
  return getToken(CParser::Enum, 0);
}

tree::TerminalNode* CParser::EnumSpecifierContext::LeftBrace() {
  return getToken(CParser::LeftBrace, 0);
}

CParser::EnumeratorListContext* CParser::EnumSpecifierContext::enumeratorList() {
  return getRuleContext<CParser::EnumeratorListContext>(0);
}

tree::TerminalNode* CParser::EnumSpecifierContext::RightBrace() {
  return getToken(CParser::RightBrace, 0);
}

tree::TerminalNode* CParser::EnumSpecifierContext::Identifier() {
  return getToken(CParser::Identifier, 0);
}

tree::TerminalNode* CParser::EnumSpecifierContext::Comma() {
  return getToken(CParser::Comma, 0);
}


size_t CParser::EnumSpecifierContext::getRuleIndex() const {
  return CParser::RuleEnumSpecifier;
}


antlrcpp::Any CParser::EnumSpecifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitEnumSpecifier(this);
  else
    return visitor->visitChildren(this);
}

CParser::EnumSpecifierContext* CParser::enumSpecifier() {
  EnumSpecifierContext *_localctx = _tracker.createInstance<EnumSpecifierContext>(_ctx, getState());
  enterRule(_localctx, 76, CParser::RuleEnumSpecifier);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(442);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(429);
      match(CParser::Enum);
      setState(431);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CParser::Identifier) {
        setState(430);
        match(CParser::Identifier);
      }
      setState(433);
      match(CParser::LeftBrace);
      setState(434);
      enumeratorList();
      setState(436);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CParser::Comma) {
        setState(435);
        match(CParser::Comma);
      }
      setState(438);
      match(CParser::RightBrace);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(440);
      match(CParser::Enum);
      setState(441);
      match(CParser::Identifier);
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

//----------------- EnumeratorListContext ------------------------------------------------------------------

CParser::EnumeratorListContext::EnumeratorListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CParser::EnumeratorContext *> CParser::EnumeratorListContext::enumerator() {
  return getRuleContexts<CParser::EnumeratorContext>();
}

CParser::EnumeratorContext* CParser::EnumeratorListContext::enumerator(size_t i) {
  return getRuleContext<CParser::EnumeratorContext>(i);
}

std::vector<tree::TerminalNode *> CParser::EnumeratorListContext::Comma() {
  return getTokens(CParser::Comma);
}

tree::TerminalNode* CParser::EnumeratorListContext::Comma(size_t i) {
  return getToken(CParser::Comma, i);
}


size_t CParser::EnumeratorListContext::getRuleIndex() const {
  return CParser::RuleEnumeratorList;
}


antlrcpp::Any CParser::EnumeratorListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitEnumeratorList(this);
  else
    return visitor->visitChildren(this);
}

CParser::EnumeratorListContext* CParser::enumeratorList() {
  EnumeratorListContext *_localctx = _tracker.createInstance<EnumeratorListContext>(_ctx, getState());
  enterRule(_localctx, 78, CParser::RuleEnumeratorList);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(444);
    enumerator();
    setState(449);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(445);
        match(CParser::Comma);
        setState(446);
        enumerator(); 
      }
      setState(451);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EnumeratorContext ------------------------------------------------------------------

CParser::EnumeratorContext::EnumeratorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::EnumerationConstantContext* CParser::EnumeratorContext::enumerationConstant() {
  return getRuleContext<CParser::EnumerationConstantContext>(0);
}

tree::TerminalNode* CParser::EnumeratorContext::Assign() {
  return getToken(CParser::Assign, 0);
}

CParser::ConstantExpressionContext* CParser::EnumeratorContext::constantExpression() {
  return getRuleContext<CParser::ConstantExpressionContext>(0);
}


size_t CParser::EnumeratorContext::getRuleIndex() const {
  return CParser::RuleEnumerator;
}


antlrcpp::Any CParser::EnumeratorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitEnumerator(this);
  else
    return visitor->visitChildren(this);
}

CParser::EnumeratorContext* CParser::enumerator() {
  EnumeratorContext *_localctx = _tracker.createInstance<EnumeratorContext>(_ctx, getState());
  enterRule(_localctx, 80, CParser::RuleEnumerator);
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
    enumerationConstant();
    setState(455);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CParser::Assign) {
      setState(453);
      match(CParser::Assign);
      setState(454);
      constantExpression();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EnumerationConstantContext ------------------------------------------------------------------

CParser::EnumerationConstantContext::EnumerationConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::EnumerationConstantContext::Identifier() {
  return getToken(CParser::Identifier, 0);
}


size_t CParser::EnumerationConstantContext::getRuleIndex() const {
  return CParser::RuleEnumerationConstant;
}


antlrcpp::Any CParser::EnumerationConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitEnumerationConstant(this);
  else
    return visitor->visitChildren(this);
}

CParser::EnumerationConstantContext* CParser::enumerationConstant() {
  EnumerationConstantContext *_localctx = _tracker.createInstance<EnumerationConstantContext>(_ctx, getState());
  enterRule(_localctx, 82, CParser::RuleEnumerationConstant);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(457);
    match(CParser::Identifier);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionSpecifierContext ------------------------------------------------------------------

CParser::FunctionSpecifierContext::FunctionSpecifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::FunctionSpecifierContext::Inline() {
  return getToken(CParser::Inline, 0);
}

tree::TerminalNode* CParser::FunctionSpecifierContext::Noreturn() {
  return getToken(CParser::Noreturn, 0);
}


size_t CParser::FunctionSpecifierContext::getRuleIndex() const {
  return CParser::RuleFunctionSpecifier;
}


antlrcpp::Any CParser::FunctionSpecifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitFunctionSpecifier(this);
  else
    return visitor->visitChildren(this);
}

CParser::FunctionSpecifierContext* CParser::functionSpecifier() {
  FunctionSpecifierContext *_localctx = _tracker.createInstance<FunctionSpecifierContext>(_ctx, getState());
  enterRule(_localctx, 84, CParser::RuleFunctionSpecifier);
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
    setState(459);
    _la = _input->LA(1);
    if (!(_la == CParser::Inline

    || _la == CParser::Noreturn)) {
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
  enterRule(_localctx, 86, CParser::RuleDeclarator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(461);
    directDeclarator(0);
   
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

tree::TerminalNode* CParser::DirectDeclaratorContext::Identifier() {
  return getToken(CParser::Identifier, 0);
}

tree::TerminalNode* CParser::DirectDeclaratorContext::LeftParen() {
  return getToken(CParser::LeftParen, 0);
}

CParser::DeclaratorContext* CParser::DirectDeclaratorContext::declarator() {
  return getRuleContext<CParser::DeclaratorContext>(0);
}

tree::TerminalNode* CParser::DirectDeclaratorContext::RightParen() {
  return getToken(CParser::RightParen, 0);
}

CParser::DirectDeclaratorContext* CParser::DirectDeclaratorContext::directDeclarator() {
  return getRuleContext<CParser::DirectDeclaratorContext>(0);
}

CParser::ParameterTypeListContext* CParser::DirectDeclaratorContext::parameterTypeList() {
  return getRuleContext<CParser::ParameterTypeListContext>(0);
}

CParser::IdentifierListContext* CParser::DirectDeclaratorContext::identifierList() {
  return getRuleContext<CParser::IdentifierListContext>(0);
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
   return directDeclarator(0);
}

CParser::DirectDeclaratorContext* CParser::directDeclarator(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CParser::DirectDeclaratorContext *_localctx = _tracker.createInstance<DirectDeclaratorContext>(_ctx, parentState);
  CParser::DirectDeclaratorContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 88;
  enterRecursionRule(_localctx, 88, CParser::RuleDirectDeclarator, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(469);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::Identifier: {
        setState(464);
        match(CParser::Identifier);
        break;
      }

      case CParser::LeftParen: {
        setState(465);
        match(CParser::LeftParen);
        setState(466);
        declarator();
        setState(467);
        match(CParser::RightParen);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(484);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 47, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(482);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 46, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<DirectDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectDeclarator);
          setState(471);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(472);
          match(CParser::LeftParen);
          setState(473);
          parameterTypeList();
          setState(474);
          match(CParser::RightParen);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<DirectDeclaratorContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleDirectDeclarator);
          setState(476);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(477);
          match(CParser::LeftParen);
          setState(479);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == CParser::Identifier) {
            setState(478);
            identifierList();
          }
          setState(481);
          match(CParser::RightParen);
          break;
        }

        default:
          break;
        } 
      }
      setState(486);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 47, _ctx);
    }
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

tree::TerminalNode* CParser::ParameterTypeListContext::Comma() {
  return getToken(CParser::Comma, 0);
}

tree::TerminalNode* CParser::ParameterTypeListContext::Ellipsis() {
  return getToken(CParser::Ellipsis, 0);
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
  enterRule(_localctx, 90, CParser::RuleParameterTypeList);
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
    setState(487);
    parameterList();
    setState(490);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CParser::Comma) {
      setState(488);
      match(CParser::Comma);
      setState(489);
      match(CParser::Ellipsis);
    }
   
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
  enterRule(_localctx, 92, CParser::RuleParameterList);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(492);
    parameterDeclaration();
    setState(497);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 49, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(493);
        match(CParser::Comma);
        setState(494);
        parameterDeclaration(); 
      }
      setState(499);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 49, _ctx);
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

CParser::DeclarationSpecifiersContext* CParser::ParameterDeclarationContext::declarationSpecifiers() {
  return getRuleContext<CParser::DeclarationSpecifiersContext>(0);
}

CParser::DeclaratorContext* CParser::ParameterDeclarationContext::declarator() {
  return getRuleContext<CParser::DeclaratorContext>(0);
}

CParser::AbstractDeclaratorContext* CParser::ParameterDeclarationContext::abstractDeclarator() {
  return getRuleContext<CParser::AbstractDeclaratorContext>(0);
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
  enterRule(_localctx, 94, CParser::RuleParameterDeclaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(507);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 51, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(500);
      declarationSpecifiers();
      setState(501);
      declarator();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(503);
      declarationSpecifiers();
      setState(505);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CParser::LeftParen

      || _la == CParser::LeftBracket) {
        setState(504);
        abstractDeclarator();
      }
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

//----------------- IdentifierListContext ------------------------------------------------------------------

CParser::IdentifierListContext::IdentifierListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> CParser::IdentifierListContext::Identifier() {
  return getTokens(CParser::Identifier);
}

tree::TerminalNode* CParser::IdentifierListContext::Identifier(size_t i) {
  return getToken(CParser::Identifier, i);
}

std::vector<tree::TerminalNode *> CParser::IdentifierListContext::Comma() {
  return getTokens(CParser::Comma);
}

tree::TerminalNode* CParser::IdentifierListContext::Comma(size_t i) {
  return getToken(CParser::Comma, i);
}


size_t CParser::IdentifierListContext::getRuleIndex() const {
  return CParser::RuleIdentifierList;
}


antlrcpp::Any CParser::IdentifierListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitIdentifierList(this);
  else
    return visitor->visitChildren(this);
}

CParser::IdentifierListContext* CParser::identifierList() {
  IdentifierListContext *_localctx = _tracker.createInstance<IdentifierListContext>(_ctx, getState());
  enterRule(_localctx, 96, CParser::RuleIdentifierList);
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
    setState(509);
    match(CParser::Identifier);
    setState(514);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CParser::Comma) {
      setState(510);
      match(CParser::Comma);
      setState(511);
      match(CParser::Identifier);
      setState(516);
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

//----------------- TypeNameContext ------------------------------------------------------------------

CParser::TypeNameContext::TypeNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::SpecifierQualifierListContext* CParser::TypeNameContext::specifierQualifierList() {
  return getRuleContext<CParser::SpecifierQualifierListContext>(0);
}

CParser::AbstractDeclaratorContext* CParser::TypeNameContext::abstractDeclarator() {
  return getRuleContext<CParser::AbstractDeclaratorContext>(0);
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
  enterRule(_localctx, 98, CParser::RuleTypeName);
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
    setState(517);
    specifierQualifierList();
    setState(519);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CParser::LeftParen

    || _la == CParser::LeftBracket) {
      setState(518);
      abstractDeclarator();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AbstractDeclaratorContext ------------------------------------------------------------------

CParser::AbstractDeclaratorContext::AbstractDeclaratorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::DirectAbstractDeclaratorsContext* CParser::AbstractDeclaratorContext::directAbstractDeclarators() {
  return getRuleContext<CParser::DirectAbstractDeclaratorsContext>(0);
}


size_t CParser::AbstractDeclaratorContext::getRuleIndex() const {
  return CParser::RuleAbstractDeclarator;
}


antlrcpp::Any CParser::AbstractDeclaratorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitAbstractDeclarator(this);
  else
    return visitor->visitChildren(this);
}

CParser::AbstractDeclaratorContext* CParser::abstractDeclarator() {
  AbstractDeclaratorContext *_localctx = _tracker.createInstance<AbstractDeclaratorContext>(_ctx, getState());
  enterRule(_localctx, 100, CParser::RuleAbstractDeclarator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(521);
    directAbstractDeclarators();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DirectAbstractDeclaratorsContext ------------------------------------------------------------------

CParser::DirectAbstractDeclaratorsContext::DirectAbstractDeclaratorsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CParser::DirectAbstractDeclaratorContext *> CParser::DirectAbstractDeclaratorsContext::directAbstractDeclarator() {
  return getRuleContexts<CParser::DirectAbstractDeclaratorContext>();
}

CParser::DirectAbstractDeclaratorContext* CParser::DirectAbstractDeclaratorsContext::directAbstractDeclarator(size_t i) {
  return getRuleContext<CParser::DirectAbstractDeclaratorContext>(i);
}


size_t CParser::DirectAbstractDeclaratorsContext::getRuleIndex() const {
  return CParser::RuleDirectAbstractDeclarators;
}


antlrcpp::Any CParser::DirectAbstractDeclaratorsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitDirectAbstractDeclarators(this);
  else
    return visitor->visitChildren(this);
}

CParser::DirectAbstractDeclaratorsContext* CParser::directAbstractDeclarators() {
  DirectAbstractDeclaratorsContext *_localctx = _tracker.createInstance<DirectAbstractDeclaratorsContext>(_ctx, getState());
  enterRule(_localctx, 102, CParser::RuleDirectAbstractDeclarators);
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
    setState(524); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(523);
      directAbstractDeclarator();
      setState(526); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == CParser::LeftParen

    || _la == CParser::LeftBracket);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DirectAbstractDeclaratorContext ------------------------------------------------------------------

CParser::DirectAbstractDeclaratorContext::DirectAbstractDeclaratorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::DirectAbstractDeclaratorContext::LeftParen() {
  return getToken(CParser::LeftParen, 0);
}

CParser::AbstractDeclaratorContext* CParser::DirectAbstractDeclaratorContext::abstractDeclarator() {
  return getRuleContext<CParser::AbstractDeclaratorContext>(0);
}

tree::TerminalNode* CParser::DirectAbstractDeclaratorContext::RightParen() {
  return getToken(CParser::RightParen, 0);
}

tree::TerminalNode* CParser::DirectAbstractDeclaratorContext::LeftBracket() {
  return getToken(CParser::LeftBracket, 0);
}

tree::TerminalNode* CParser::DirectAbstractDeclaratorContext::Star() {
  return getToken(CParser::Star, 0);
}

tree::TerminalNode* CParser::DirectAbstractDeclaratorContext::RightBracket() {
  return getToken(CParser::RightBracket, 0);
}

CParser::ParameterTypeListContext* CParser::DirectAbstractDeclaratorContext::parameterTypeList() {
  return getRuleContext<CParser::ParameterTypeListContext>(0);
}


size_t CParser::DirectAbstractDeclaratorContext::getRuleIndex() const {
  return CParser::RuleDirectAbstractDeclarator;
}


antlrcpp::Any CParser::DirectAbstractDeclaratorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitDirectAbstractDeclarator(this);
  else
    return visitor->visitChildren(this);
}

CParser::DirectAbstractDeclaratorContext* CParser::directAbstractDeclarator() {
  DirectAbstractDeclaratorContext *_localctx = _tracker.createInstance<DirectAbstractDeclaratorContext>(_ctx, getState());
  enterRule(_localctx, 104, CParser::RuleDirectAbstractDeclarator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(540);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 56, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(528);
      match(CParser::LeftParen);
      setState(529);
      abstractDeclarator();
      setState(530);
      match(CParser::RightParen);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(532);
      match(CParser::LeftBracket);
      setState(533);
      match(CParser::Star);
      setState(534);
      match(CParser::RightBracket);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(535);
      match(CParser::LeftParen);
      setState(537);
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
        | (1ULL << CParser::Bool))) != 0)) {
        setState(536);
        parameterTypeList();
      }
      setState(539);
      match(CParser::RightParen);
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

//----------------- TypedefNameContext ------------------------------------------------------------------

CParser::TypedefNameContext::TypedefNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::TypedefNameContext::Identifier() {
  return getToken(CParser::Identifier, 0);
}


size_t CParser::TypedefNameContext::getRuleIndex() const {
  return CParser::RuleTypedefName;
}


antlrcpp::Any CParser::TypedefNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitTypedefName(this);
  else
    return visitor->visitChildren(this);
}

CParser::TypedefNameContext* CParser::typedefName() {
  TypedefNameContext *_localctx = _tracker.createInstance<TypedefNameContext>(_ctx, getState());
  enterRule(_localctx, 106, CParser::RuleTypedefName);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(542);
    match(CParser::Identifier);
   
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

tree::TerminalNode* CParser::InitializerContext::LeftBrace() {
  return getToken(CParser::LeftBrace, 0);
}

CParser::InitializerListContext* CParser::InitializerContext::initializerList() {
  return getRuleContext<CParser::InitializerListContext>(0);
}

tree::TerminalNode* CParser::InitializerContext::RightBrace() {
  return getToken(CParser::RightBrace, 0);
}

tree::TerminalNode* CParser::InitializerContext::Comma() {
  return getToken(CParser::Comma, 0);
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
  enterRule(_localctx, 108, CParser::RuleInitializer);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(552);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
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
      case CParser::Identifier:
      case CParser::Constant:
      case CParser::DigitSequence:
      case CParser::StringLiteral: {
        enterOuterAlt(_localctx, 1);
        setState(544);
        assignmentExpression();
        break;
      }

      case CParser::LeftBrace: {
        enterOuterAlt(_localctx, 2);
        setState(545);
        match(CParser::LeftBrace);
        setState(546);
        initializerList();
        setState(548);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == CParser::Comma) {
          setState(547);
          match(CParser::Comma);
        }
        setState(550);
        match(CParser::RightBrace);
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

//----------------- InitializerListContext ------------------------------------------------------------------

CParser::InitializerListContext::InitializerListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CParser::InitializerContext *> CParser::InitializerListContext::initializer() {
  return getRuleContexts<CParser::InitializerContext>();
}

CParser::InitializerContext* CParser::InitializerListContext::initializer(size_t i) {
  return getRuleContext<CParser::InitializerContext>(i);
}

std::vector<CParser::DesignationContext *> CParser::InitializerListContext::designation() {
  return getRuleContexts<CParser::DesignationContext>();
}

CParser::DesignationContext* CParser::InitializerListContext::designation(size_t i) {
  return getRuleContext<CParser::DesignationContext>(i);
}

std::vector<tree::TerminalNode *> CParser::InitializerListContext::Comma() {
  return getTokens(CParser::Comma);
}

tree::TerminalNode* CParser::InitializerListContext::Comma(size_t i) {
  return getToken(CParser::Comma, i);
}


size_t CParser::InitializerListContext::getRuleIndex() const {
  return CParser::RuleInitializerList;
}


antlrcpp::Any CParser::InitializerListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitInitializerList(this);
  else
    return visitor->visitChildren(this);
}

CParser::InitializerListContext* CParser::initializerList() {
  InitializerListContext *_localctx = _tracker.createInstance<InitializerListContext>(_ctx, getState());
  enterRule(_localctx, 110, CParser::RuleInitializerList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(555);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CParser::LeftBracket

    || _la == CParser::Dot) {
      setState(554);
      designation();
    }
    setState(557);
    initializer();
    setState(565);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 61, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(558);
        match(CParser::Comma);
        setState(560);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == CParser::LeftBracket

        || _la == CParser::Dot) {
          setState(559);
          designation();
        }
        setState(562);
        initializer(); 
      }
      setState(567);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 61, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DesignationContext ------------------------------------------------------------------

CParser::DesignationContext::DesignationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::DesignatorListContext* CParser::DesignationContext::designatorList() {
  return getRuleContext<CParser::DesignatorListContext>(0);
}

tree::TerminalNode* CParser::DesignationContext::Assign() {
  return getToken(CParser::Assign, 0);
}


size_t CParser::DesignationContext::getRuleIndex() const {
  return CParser::RuleDesignation;
}


antlrcpp::Any CParser::DesignationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitDesignation(this);
  else
    return visitor->visitChildren(this);
}

CParser::DesignationContext* CParser::designation() {
  DesignationContext *_localctx = _tracker.createInstance<DesignationContext>(_ctx, getState());
  enterRule(_localctx, 112, CParser::RuleDesignation);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(568);
    designatorList();
    setState(569);
    match(CParser::Assign);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DesignatorListContext ------------------------------------------------------------------

CParser::DesignatorListContext::DesignatorListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CParser::DesignatorContext *> CParser::DesignatorListContext::designator() {
  return getRuleContexts<CParser::DesignatorContext>();
}

CParser::DesignatorContext* CParser::DesignatorListContext::designator(size_t i) {
  return getRuleContext<CParser::DesignatorContext>(i);
}


size_t CParser::DesignatorListContext::getRuleIndex() const {
  return CParser::RuleDesignatorList;
}


antlrcpp::Any CParser::DesignatorListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitDesignatorList(this);
  else
    return visitor->visitChildren(this);
}

CParser::DesignatorListContext* CParser::designatorList() {
  DesignatorListContext *_localctx = _tracker.createInstance<DesignatorListContext>(_ctx, getState());
  enterRule(_localctx, 114, CParser::RuleDesignatorList);
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
    setState(572); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(571);
      designator();
      setState(574); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == CParser::LeftBracket

    || _la == CParser::Dot);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DesignatorContext ------------------------------------------------------------------

CParser::DesignatorContext::DesignatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::DesignatorContext::LeftBracket() {
  return getToken(CParser::LeftBracket, 0);
}

CParser::ConstantExpressionContext* CParser::DesignatorContext::constantExpression() {
  return getRuleContext<CParser::ConstantExpressionContext>(0);
}

tree::TerminalNode* CParser::DesignatorContext::RightBracket() {
  return getToken(CParser::RightBracket, 0);
}

tree::TerminalNode* CParser::DesignatorContext::Dot() {
  return getToken(CParser::Dot, 0);
}

tree::TerminalNode* CParser::DesignatorContext::Identifier() {
  return getToken(CParser::Identifier, 0);
}


size_t CParser::DesignatorContext::getRuleIndex() const {
  return CParser::RuleDesignator;
}


antlrcpp::Any CParser::DesignatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitDesignator(this);
  else
    return visitor->visitChildren(this);
}

CParser::DesignatorContext* CParser::designator() {
  DesignatorContext *_localctx = _tracker.createInstance<DesignatorContext>(_ctx, getState());
  enterRule(_localctx, 116, CParser::RuleDesignator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(582);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::LeftBracket: {
        enterOuterAlt(_localctx, 1);
        setState(576);
        match(CParser::LeftBracket);
        setState(577);
        constantExpression();
        setState(578);
        match(CParser::RightBracket);
        break;
      }

      case CParser::Dot: {
        enterOuterAlt(_localctx, 2);
        setState(580);
        match(CParser::Dot);
        setState(581);
        match(CParser::Identifier);
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

//----------------- StaticAssertDeclarationContext ------------------------------------------------------------------

CParser::StaticAssertDeclarationContext::StaticAssertDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::StaticAssertDeclarationContext::StaticAssert() {
  return getToken(CParser::StaticAssert, 0);
}

tree::TerminalNode* CParser::StaticAssertDeclarationContext::LeftParen() {
  return getToken(CParser::LeftParen, 0);
}

CParser::ConstantExpressionContext* CParser::StaticAssertDeclarationContext::constantExpression() {
  return getRuleContext<CParser::ConstantExpressionContext>(0);
}

tree::TerminalNode* CParser::StaticAssertDeclarationContext::Comma() {
  return getToken(CParser::Comma, 0);
}

tree::TerminalNode* CParser::StaticAssertDeclarationContext::RightParen() {
  return getToken(CParser::RightParen, 0);
}

tree::TerminalNode* CParser::StaticAssertDeclarationContext::Semi() {
  return getToken(CParser::Semi, 0);
}

std::vector<tree::TerminalNode *> CParser::StaticAssertDeclarationContext::StringLiteral() {
  return getTokens(CParser::StringLiteral);
}

tree::TerminalNode* CParser::StaticAssertDeclarationContext::StringLiteral(size_t i) {
  return getToken(CParser::StringLiteral, i);
}


size_t CParser::StaticAssertDeclarationContext::getRuleIndex() const {
  return CParser::RuleStaticAssertDeclaration;
}


antlrcpp::Any CParser::StaticAssertDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitStaticAssertDeclaration(this);
  else
    return visitor->visitChildren(this);
}

CParser::StaticAssertDeclarationContext* CParser::staticAssertDeclaration() {
  StaticAssertDeclarationContext *_localctx = _tracker.createInstance<StaticAssertDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 118, CParser::RuleStaticAssertDeclaration);
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
    setState(584);
    match(CParser::StaticAssert);
    setState(585);
    match(CParser::LeftParen);
    setState(586);
    constantExpression();
    setState(587);
    match(CParser::Comma);
    setState(589); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(588);
      match(CParser::StringLiteral);
      setState(591); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == CParser::StringLiteral);
    setState(593);
    match(CParser::RightParen);
    setState(594);
    match(CParser::Semi);
   
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

CParser::LabeledStatementContext* CParser::StatementContext::labeledStatement() {
  return getRuleContext<CParser::LabeledStatementContext>(0);
}

CParser::CompoundStatementContext* CParser::StatementContext::compoundStatement() {
  return getRuleContext<CParser::CompoundStatementContext>(0);
}

CParser::ExpressionStatementContext* CParser::StatementContext::expressionStatement() {
  return getRuleContext<CParser::ExpressionStatementContext>(0);
}

CParser::SelectionStatementContext* CParser::StatementContext::selectionStatement() {
  return getRuleContext<CParser::SelectionStatementContext>(0);
}

CParser::IterationStatementContext* CParser::StatementContext::iterationStatement() {
  return getRuleContext<CParser::IterationStatementContext>(0);
}

CParser::JumpStatementContext* CParser::StatementContext::jumpStatement() {
  return getRuleContext<CParser::JumpStatementContext>(0);
}


size_t CParser::StatementContext::getRuleIndex() const {
  return CParser::RuleStatement;
}


antlrcpp::Any CParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

CParser::StatementContext* CParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 120, CParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(602);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 65, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(596);
      labeledStatement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(597);
      compoundStatement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(598);
      expressionStatement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(599);
      selectionStatement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(600);
      iterationStatement();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(601);
      jumpStatement();
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

//----------------- LabeledStatementContext ------------------------------------------------------------------

CParser::LabeledStatementContext::LabeledStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::LabeledStatementContext::Identifier() {
  return getToken(CParser::Identifier, 0);
}

tree::TerminalNode* CParser::LabeledStatementContext::Colon() {
  return getToken(CParser::Colon, 0);
}

CParser::StatementContext* CParser::LabeledStatementContext::statement() {
  return getRuleContext<CParser::StatementContext>(0);
}

tree::TerminalNode* CParser::LabeledStatementContext::Case() {
  return getToken(CParser::Case, 0);
}

CParser::ConstantExpressionContext* CParser::LabeledStatementContext::constantExpression() {
  return getRuleContext<CParser::ConstantExpressionContext>(0);
}

tree::TerminalNode* CParser::LabeledStatementContext::Default() {
  return getToken(CParser::Default, 0);
}


size_t CParser::LabeledStatementContext::getRuleIndex() const {
  return CParser::RuleLabeledStatement;
}


antlrcpp::Any CParser::LabeledStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitLabeledStatement(this);
  else
    return visitor->visitChildren(this);
}

CParser::LabeledStatementContext* CParser::labeledStatement() {
  LabeledStatementContext *_localctx = _tracker.createInstance<LabeledStatementContext>(_ctx, getState());
  enterRule(_localctx, 122, CParser::RuleLabeledStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(615);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(604);
        match(CParser::Identifier);
        setState(605);
        match(CParser::Colon);
        setState(606);
        statement();
        break;
      }

      case CParser::Case: {
        enterOuterAlt(_localctx, 2);
        setState(607);
        match(CParser::Case);
        setState(608);
        constantExpression();
        setState(609);
        match(CParser::Colon);
        setState(610);
        statement();
        break;
      }

      case CParser::Default: {
        enterOuterAlt(_localctx, 3);
        setState(612);
        match(CParser::Default);
        setState(613);
        match(CParser::Colon);
        setState(614);
        statement();
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
  enterRule(_localctx, 124, CParser::RuleCompoundStatement);
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
    setState(617);
    match(CParser::LeftBrace);
    setState(621);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CParser::Break)
      | (1ULL << CParser::Case)
      | (1ULL << CParser::Char)
      | (1ULL << CParser::Continue)
      | (1ULL << CParser::Default)
      | (1ULL << CParser::Do)
      | (1ULL << CParser::Double)
      | (1ULL << CParser::Float)
      | (1ULL << CParser::For)
      | (1ULL << CParser::Goto)
      | (1ULL << CParser::If)
      | (1ULL << CParser::Int)
      | (1ULL << CParser::Long)
      | (1ULL << CParser::Return)
      | (1ULL << CParser::Short)
      | (1ULL << CParser::Signed)
      | (1ULL << CParser::Sizeof)
      | (1ULL << CParser::Switch)
      | (1ULL << CParser::Typedef)
      | (1ULL << CParser::Unsigned)
      | (1ULL << CParser::Void)
      | (1ULL << CParser::While)
      | (1ULL << CParser::Bool)
      | (1ULL << CParser::StaticAssert)
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
      | (1ULL << (CParser::Constant - 64))
      | (1ULL << (CParser::DigitSequence - 64))
      | (1ULL << (CParser::StringLiteral - 64)))) != 0)) {
      setState(618);
      blockItem();
      setState(623);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(624);
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
  enterRule(_localctx, 126, CParser::RuleBlockItem);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(628);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::Break:
      case CParser::Case:
      case CParser::Continue:
      case CParser::Default:
      case CParser::Do:
      case CParser::For:
      case CParser::Goto:
      case CParser::If:
      case CParser::Return:
      case CParser::Sizeof:
      case CParser::Switch:
      case CParser::While:
      case CParser::LeftParen:
      case CParser::LeftBrace:
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
      case CParser::Constant:
      case CParser::DigitSequence:
      case CParser::StringLiteral: {
        enterOuterAlt(_localctx, 1);
        setState(626);
        statement();
        break;
      }

      case CParser::Char:
      case CParser::Double:
      case CParser::Float:
      case CParser::Int:
      case CParser::Long:
      case CParser::Short:
      case CParser::Signed:
      case CParser::Typedef:
      case CParser::Unsigned:
      case CParser::Void:
      case CParser::Bool:
      case CParser::StaticAssert: {
        enterOuterAlt(_localctx, 2);
        setState(627);
        declaration();
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

//----------------- ExpressionStatementContext ------------------------------------------------------------------

CParser::ExpressionStatementContext::ExpressionStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::ExpressionStatementContext::Semi() {
  return getToken(CParser::Semi, 0);
}

CParser::ExpressionContext* CParser::ExpressionStatementContext::expression() {
  return getRuleContext<CParser::ExpressionContext>(0);
}


size_t CParser::ExpressionStatementContext::getRuleIndex() const {
  return CParser::RuleExpressionStatement;
}


antlrcpp::Any CParser::ExpressionStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitExpressionStatement(this);
  else
    return visitor->visitChildren(this);
}

CParser::ExpressionStatementContext* CParser::expressionStatement() {
  ExpressionStatementContext *_localctx = _tracker.createInstance<ExpressionStatementContext>(_ctx, getState());
  enterRule(_localctx, 128, CParser::RuleExpressionStatement);
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
    setState(631);
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
      | (1ULL << (CParser::Constant - 64))
      | (1ULL << (CParser::DigitSequence - 64))
      | (1ULL << (CParser::StringLiteral - 64)))) != 0)) {
      setState(630);
      expression();
    }
    setState(633);
    match(CParser::Semi);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SelectionStatementContext ------------------------------------------------------------------

CParser::SelectionStatementContext::SelectionStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::SelectionStatementContext::If() {
  return getToken(CParser::If, 0);
}

tree::TerminalNode* CParser::SelectionStatementContext::LeftParen() {
  return getToken(CParser::LeftParen, 0);
}

CParser::ExpressionContext* CParser::SelectionStatementContext::expression() {
  return getRuleContext<CParser::ExpressionContext>(0);
}

tree::TerminalNode* CParser::SelectionStatementContext::RightParen() {
  return getToken(CParser::RightParen, 0);
}

std::vector<CParser::StatementContext *> CParser::SelectionStatementContext::statement() {
  return getRuleContexts<CParser::StatementContext>();
}

CParser::StatementContext* CParser::SelectionStatementContext::statement(size_t i) {
  return getRuleContext<CParser::StatementContext>(i);
}

tree::TerminalNode* CParser::SelectionStatementContext::Else() {
  return getToken(CParser::Else, 0);
}

tree::TerminalNode* CParser::SelectionStatementContext::Switch() {
  return getToken(CParser::Switch, 0);
}


size_t CParser::SelectionStatementContext::getRuleIndex() const {
  return CParser::RuleSelectionStatement;
}


antlrcpp::Any CParser::SelectionStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitSelectionStatement(this);
  else
    return visitor->visitChildren(this);
}

CParser::SelectionStatementContext* CParser::selectionStatement() {
  SelectionStatementContext *_localctx = _tracker.createInstance<SelectionStatementContext>(_ctx, getState());
  enterRule(_localctx, 130, CParser::RuleSelectionStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(650);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::If: {
        enterOuterAlt(_localctx, 1);
        setState(635);
        match(CParser::If);
        setState(636);
        match(CParser::LeftParen);
        setState(637);
        expression();
        setState(638);
        match(CParser::RightParen);
        setState(639);
        statement();
        setState(642);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 70, _ctx)) {
        case 1: {
          setState(640);
          match(CParser::Else);
          setState(641);
          statement();
          break;
        }

        default:
          break;
        }
        break;
      }

      case CParser::Switch: {
        enterOuterAlt(_localctx, 2);
        setState(644);
        match(CParser::Switch);
        setState(645);
        match(CParser::LeftParen);
        setState(646);
        expression();
        setState(647);
        match(CParser::RightParen);
        setState(648);
        statement();
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

//----------------- IterationStatementContext ------------------------------------------------------------------

CParser::IterationStatementContext::IterationStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::IterationStatementContext::While() {
  return getToken(CParser::While, 0);
}

tree::TerminalNode* CParser::IterationStatementContext::LeftParen() {
  return getToken(CParser::LeftParen, 0);
}

CParser::ExpressionContext* CParser::IterationStatementContext::expression() {
  return getRuleContext<CParser::ExpressionContext>(0);
}

tree::TerminalNode* CParser::IterationStatementContext::RightParen() {
  return getToken(CParser::RightParen, 0);
}

CParser::StatementContext* CParser::IterationStatementContext::statement() {
  return getRuleContext<CParser::StatementContext>(0);
}

tree::TerminalNode* CParser::IterationStatementContext::Do() {
  return getToken(CParser::Do, 0);
}

tree::TerminalNode* CParser::IterationStatementContext::Semi() {
  return getToken(CParser::Semi, 0);
}

tree::TerminalNode* CParser::IterationStatementContext::For() {
  return getToken(CParser::For, 0);
}

CParser::ForConditionContext* CParser::IterationStatementContext::forCondition() {
  return getRuleContext<CParser::ForConditionContext>(0);
}


size_t CParser::IterationStatementContext::getRuleIndex() const {
  return CParser::RuleIterationStatement;
}


antlrcpp::Any CParser::IterationStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitIterationStatement(this);
  else
    return visitor->visitChildren(this);
}

CParser::IterationStatementContext* CParser::iterationStatement() {
  IterationStatementContext *_localctx = _tracker.createInstance<IterationStatementContext>(_ctx, getState());
  enterRule(_localctx, 132, CParser::RuleIterationStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(672);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::While: {
        enterOuterAlt(_localctx, 1);
        setState(652);
        match(CParser::While);
        setState(653);
        match(CParser::LeftParen);
        setState(654);
        expression();
        setState(655);
        match(CParser::RightParen);
        setState(656);
        statement();
        break;
      }

      case CParser::Do: {
        enterOuterAlt(_localctx, 2);
        setState(658);
        match(CParser::Do);
        setState(659);
        statement();
        setState(660);
        match(CParser::While);
        setState(661);
        match(CParser::LeftParen);
        setState(662);
        expression();
        setState(663);
        match(CParser::RightParen);
        setState(664);
        match(CParser::Semi);
        break;
      }

      case CParser::For: {
        enterOuterAlt(_localctx, 3);
        setState(666);
        match(CParser::For);
        setState(667);
        match(CParser::LeftParen);
        setState(668);
        forCondition();
        setState(669);
        match(CParser::RightParen);
        setState(670);
        statement();
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

//----------------- ForConditionContext ------------------------------------------------------------------

CParser::ForConditionContext::ForConditionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> CParser::ForConditionContext::Semi() {
  return getTokens(CParser::Semi);
}

tree::TerminalNode* CParser::ForConditionContext::Semi(size_t i) {
  return getToken(CParser::Semi, i);
}

CParser::DeclarationContext* CParser::ForConditionContext::declaration() {
  return getRuleContext<CParser::DeclarationContext>(0);
}

std::vector<CParser::ForExpressionContext *> CParser::ForConditionContext::forExpression() {
  return getRuleContexts<CParser::ForExpressionContext>();
}

CParser::ForExpressionContext* CParser::ForConditionContext::forExpression(size_t i) {
  return getRuleContext<CParser::ForExpressionContext>(i);
}

CParser::ExpressionContext* CParser::ForConditionContext::expression() {
  return getRuleContext<CParser::ExpressionContext>(0);
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
  enterRule(_localctx, 134, CParser::RuleForCondition);
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
    setState(679);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::Char:
      case CParser::Double:
      case CParser::Float:
      case CParser::Int:
      case CParser::Long:
      case CParser::Short:
      case CParser::Signed:
      case CParser::Typedef:
      case CParser::Unsigned:
      case CParser::Void:
      case CParser::Bool:
      case CParser::StaticAssert: {
        setState(674);
        declaration();
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
      case CParser::Constant:
      case CParser::DigitSequence:
      case CParser::StringLiteral: {
        setState(676);
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
          | (1ULL << (CParser::Constant - 64))
          | (1ULL << (CParser::DigitSequence - 64))
          | (1ULL << (CParser::StringLiteral - 64)))) != 0)) {
          setState(675);
          expression();
        }
        setState(678);
        match(CParser::Semi);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(682);
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
      | (1ULL << (CParser::Constant - 64))
      | (1ULL << (CParser::DigitSequence - 64))
      | (1ULL << (CParser::StringLiteral - 64)))) != 0)) {
      setState(681);
      forExpression();
    }
    setState(684);
    match(CParser::Semi);
    setState(686);
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
      | (1ULL << (CParser::Constant - 64))
      | (1ULL << (CParser::DigitSequence - 64))
      | (1ULL << (CParser::StringLiteral - 64)))) != 0)) {
      setState(685);
      forExpression();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForExpressionContext ------------------------------------------------------------------

CParser::ForExpressionContext::ForExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CParser::AssignmentExpressionContext *> CParser::ForExpressionContext::assignmentExpression() {
  return getRuleContexts<CParser::AssignmentExpressionContext>();
}

CParser::AssignmentExpressionContext* CParser::ForExpressionContext::assignmentExpression(size_t i) {
  return getRuleContext<CParser::AssignmentExpressionContext>(i);
}

std::vector<tree::TerminalNode *> CParser::ForExpressionContext::Comma() {
  return getTokens(CParser::Comma);
}

tree::TerminalNode* CParser::ForExpressionContext::Comma(size_t i) {
  return getToken(CParser::Comma, i);
}


size_t CParser::ForExpressionContext::getRuleIndex() const {
  return CParser::RuleForExpression;
}


antlrcpp::Any CParser::ForExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitForExpression(this);
  else
    return visitor->visitChildren(this);
}

CParser::ForExpressionContext* CParser::forExpression() {
  ForExpressionContext *_localctx = _tracker.createInstance<ForExpressionContext>(_ctx, getState());
  enterRule(_localctx, 136, CParser::RuleForExpression);
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
    setState(688);
    assignmentExpression();
    setState(693);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CParser::Comma) {
      setState(689);
      match(CParser::Comma);
      setState(690);
      assignmentExpression();
      setState(695);
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

//----------------- JumpStatementContext ------------------------------------------------------------------

CParser::JumpStatementContext::JumpStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::JumpStatementContext::Semi() {
  return getToken(CParser::Semi, 0);
}

tree::TerminalNode* CParser::JumpStatementContext::Goto() {
  return getToken(CParser::Goto, 0);
}

tree::TerminalNode* CParser::JumpStatementContext::Identifier() {
  return getToken(CParser::Identifier, 0);
}

tree::TerminalNode* CParser::JumpStatementContext::Continue() {
  return getToken(CParser::Continue, 0);
}

tree::TerminalNode* CParser::JumpStatementContext::Break() {
  return getToken(CParser::Break, 0);
}

tree::TerminalNode* CParser::JumpStatementContext::Return() {
  return getToken(CParser::Return, 0);
}

CParser::ExpressionContext* CParser::JumpStatementContext::expression() {
  return getRuleContext<CParser::ExpressionContext>(0);
}


size_t CParser::JumpStatementContext::getRuleIndex() const {
  return CParser::RuleJumpStatement;
}


antlrcpp::Any CParser::JumpStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitJumpStatement(this);
  else
    return visitor->visitChildren(this);
}

CParser::JumpStatementContext* CParser::jumpStatement() {
  JumpStatementContext *_localctx = _tracker.createInstance<JumpStatementContext>(_ctx, getState());
  enterRule(_localctx, 138, CParser::RuleJumpStatement);
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
    setState(704);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::Goto: {
        setState(696);
        match(CParser::Goto);
        setState(697);
        match(CParser::Identifier);
        break;
      }

      case CParser::Continue: {
        setState(698);
        match(CParser::Continue);
        break;
      }

      case CParser::Break: {
        setState(699);
        match(CParser::Break);
        break;
      }

      case CParser::Return: {
        setState(700);
        match(CParser::Return);
        setState(702);
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
          | (1ULL << (CParser::Constant - 64))
          | (1ULL << (CParser::DigitSequence - 64))
          | (1ULL << (CParser::StringLiteral - 64)))) != 0)) {
          setState(701);
          expression();
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(706);
    match(CParser::Semi);
   
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
  enterRule(_localctx, 140, CParser::RuleCompilationUnit);
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
    setState(709);
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
      | (1ULL << CParser::StaticAssert)
      | (1ULL << CParser::LeftParen))) != 0) || _la == CParser::Semi

    || _la == CParser::Identifier) {
      setState(708);
      translationUnit();
    }
    setState(711);
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
  enterRule(_localctx, 142, CParser::RuleTranslationUnit);
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
    setState(714); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(713);
      externalDeclaration();
      setState(716); 
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
      | (1ULL << CParser::StaticAssert)
      | (1ULL << CParser::LeftParen))) != 0) || _la == CParser::Semi

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

CParser::DeclarationContext* CParser::ExternalDeclarationContext::declaration() {
  return getRuleContext<CParser::DeclarationContext>(0);
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
  enterRule(_localctx, 144, CParser::RuleExternalDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(721);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 82, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(718);
      functionDefinition();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(719);
      declaration();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(720);
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

//----------------- FunctionDefinitionContext ------------------------------------------------------------------

CParser::FunctionDefinitionContext::FunctionDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::DeclaratorContext* CParser::FunctionDefinitionContext::declarator() {
  return getRuleContext<CParser::DeclaratorContext>(0);
}

CParser::CompoundStatementContext* CParser::FunctionDefinitionContext::compoundStatement() {
  return getRuleContext<CParser::CompoundStatementContext>(0);
}

CParser::DeclarationSpecifiersContext* CParser::FunctionDefinitionContext::declarationSpecifiers() {
  return getRuleContext<CParser::DeclarationSpecifiersContext>(0);
}

CParser::DeclarationListContext* CParser::FunctionDefinitionContext::declarationList() {
  return getRuleContext<CParser::DeclarationListContext>(0);
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
  enterRule(_localctx, 146, CParser::RuleFunctionDefinition);
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
    setState(724);
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
      | (1ULL << CParser::Bool))) != 0)) {
      setState(723);
      declarationSpecifiers();
    }
    setState(726);
    declarator();
    setState(728);
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
      | (1ULL << CParser::StaticAssert))) != 0)) {
      setState(727);
      declarationList();
    }
    setState(730);
    compoundStatement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationListContext ------------------------------------------------------------------

CParser::DeclarationListContext::DeclarationListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CParser::DeclarationContext *> CParser::DeclarationListContext::declaration() {
  return getRuleContexts<CParser::DeclarationContext>();
}

CParser::DeclarationContext* CParser::DeclarationListContext::declaration(size_t i) {
  return getRuleContext<CParser::DeclarationContext>(i);
}


size_t CParser::DeclarationListContext::getRuleIndex() const {
  return CParser::RuleDeclarationList;
}


antlrcpp::Any CParser::DeclarationListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitDeclarationList(this);
  else
    return visitor->visitChildren(this);
}

CParser::DeclarationListContext* CParser::declarationList() {
  DeclarationListContext *_localctx = _tracker.createInstance<DeclarationListContext>(_ctx, getState());
  enterRule(_localctx, 148, CParser::RuleDeclarationList);
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
    setState(733); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(732);
      declaration();
      setState(735); 
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
      | (1ULL << CParser::StaticAssert))) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool CParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 44: return directDeclaratorSempred(dynamic_cast<DirectDeclaratorContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool CParser::directDeclaratorSempred(DirectDeclaratorContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 2);
    case 1: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> CParser::_decisionToDFA;
atn::PredictionContextCache CParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN CParser::_atn;
std::vector<uint16_t> CParser::_serializedATN;

std::vector<std::string> CParser::_ruleNames = {
  "primaryExpression", "postfixExpression", "argumentExpressionList", "unaryExpression", 
  "unaryOperator", "castExpression", "multiplicativeExpression", "additiveExpression", 
  "shiftExpression", "relationalExpression", "equalityExpression", "andExpression", 
  "exclusiveOrExpression", "inclusiveOrExpression", "logicalAndExpression", 
  "logicalOrExpression", "conditionalExpression", "assignmentExpression", 
  "assignmentOperator", "expression", "constantExpression", "declaration", 
  "declarationSpecifiers", "declarationSpecifierList", "declarationSpecifier", 
  "initDeclaratorList", "initDeclarator", "typedefSpecifier", "storageClassSpecifier", 
  "typeSpecifier", "simpleTypeSpecifier", "structOrUnionSpecifier", "structOrUnion", 
  "structDeclarationList", "structDeclaration", "specifierQualifierList", 
  "structDeclaratorList", "structDeclarator", "enumSpecifier", "enumeratorList", 
  "enumerator", "enumerationConstant", "functionSpecifier", "declarator", 
  "directDeclarator", "parameterTypeList", "parameterList", "parameterDeclaration", 
  "identifierList", "typeName", "abstractDeclarator", "directAbstractDeclarators", 
  "directAbstractDeclarator", "typedefName", "initializer", "initializerList", 
  "designation", "designatorList", "designator", "staticAssertDeclaration", 
  "statement", "labeledStatement", "compoundStatement", "blockItem", "expressionStatement", 
  "selectionStatement", "iterationStatement", "forCondition", "forExpression", 
  "jumpStatement", "compilationUnit", "translationUnit", "externalDeclaration", 
  "functionDefinition", "declarationList"
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
  "Constant", "DigitSequence", "StringLiteral", "ComplexDefine", "IncludeDirective", 
  "AsmBlock", "LineAfterPreprocessing", "LineDirective", "PragmaDirective", 
  "Whitespace", "Newline", "BlockComment", "LineComment"
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
       0x3, 0x6a, 0x2e4, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
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
       0x9, 0x3e, 0x4, 0x3f, 0x9, 0x3f, 0x4, 0x40, 0x9, 0x40, 0x4, 0x41, 
       0x9, 0x41, 0x4, 0x42, 0x9, 0x42, 0x4, 0x43, 0x9, 0x43, 0x4, 0x44, 
       0x9, 0x44, 0x4, 0x45, 0x9, 0x45, 0x4, 0x46, 0x9, 0x46, 0x4, 0x47, 
       0x9, 0x47, 0x4, 0x48, 0x9, 0x48, 0x4, 0x49, 0x9, 0x49, 0x4, 0x4a, 
       0x9, 0x4a, 0x4, 0x4b, 0x9, 0x4b, 0x4, 0x4c, 0x9, 0x4c, 0x3, 0x2, 
       0x3, 0x2, 0x3, 0x2, 0x6, 0x2, 0x9c, 0xa, 0x2, 0xd, 0x2, 0xe, 0x2, 
       0x9d, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x5, 0x2, 0xa4, 0xa, 
       0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
       0x3, 0x3, 0x5, 0x3, 0xad, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 
       0xb1, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
       0x3, 0x3, 0x5, 0x3, 0xb9, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
       0x3, 0x3, 0x7, 0x3, 0xbf, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0xc2, 0xb, 
       0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0xc7, 0xa, 0x4, 0xc, 
       0x4, 0xe, 0x4, 0xca, 0xb, 0x4, 0x3, 0x5, 0x7, 0x5, 0xcd, 0xa, 0x5, 
       0xc, 0x5, 0xe, 0x5, 0xd0, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
       0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 
       0x5, 0xdb, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 
       0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0xe6, 0xa, 
       0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x7, 0x8, 0xeb, 0xa, 0x8, 0xc, 
       0x8, 0xe, 0x8, 0xee, 0xb, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x7, 
       0x9, 0xf3, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0xf6, 0xb, 0x9, 0x3, 0xa, 
       0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0xfb, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 
       0xfe, 0xb, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0x103, 0xa, 
       0xb, 0xc, 0xb, 0xe, 0xb, 0x106, 0xb, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 
       0xc, 0x7, 0xc, 0x10b, 0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 0x10e, 0xb, 0xc, 
       0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 0x113, 0xa, 0xd, 0xc, 0xd, 
       0xe, 0xd, 0x116, 0xb, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x7, 0xe, 
       0x11b, 0xa, 0xe, 0xc, 0xe, 0xe, 0xe, 0x11e, 0xb, 0xe, 0x3, 0xf, 0x3, 
       0xf, 0x3, 0xf, 0x7, 0xf, 0x123, 0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0x126, 
       0xb, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x7, 0x10, 0x12b, 0xa, 
       0x10, 0xc, 0x10, 0xe, 0x10, 0x12e, 0xb, 0x10, 0x3, 0x11, 0x3, 0x11, 
       0x3, 0x11, 0x7, 0x11, 0x133, 0xa, 0x11, 0xc, 0x11, 0xe, 0x11, 0x136, 
       0xb, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
       0x3, 0x12, 0x5, 0x12, 0x13e, 0xa, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 
       0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x5, 0x13, 0x146, 0xa, 0x13, 
       0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x7, 0x15, 
       0x14d, 0xa, 0x15, 0xc, 0x15, 0xe, 0x15, 0x150, 0xb, 0x15, 0x3, 0x16, 
       0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0x156, 0xa, 0x17, 0x3, 
       0x17, 0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0x15b, 0xa, 0x17, 0x3, 0x18, 
       0x5, 0x18, 0x15e, 0xa, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 0x6, 
       0x19, 0x163, 0xa, 0x19, 0xd, 0x19, 0xe, 0x19, 0x164, 0x3, 0x1a, 0x3, 
       0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x7, 0x1b, 0x16c, 0xa, 0x1b, 
       0xc, 0x1b, 0xe, 0x1b, 0x16f, 0xb, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 
       0x1c, 0x5, 0x1c, 0x174, 0xa, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1e, 
       0x3, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x21, 
       0x3, 0x21, 0x5, 0x21, 0x180, 0xa, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 
       0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x5, 0x21, 0x189, 
       0xa, 0x21, 0x3, 0x22, 0x3, 0x22, 0x3, 0x23, 0x6, 0x23, 0x18e, 0xa, 
       0x23, 0xd, 0x23, 0xe, 0x23, 0x18f, 0x3, 0x24, 0x3, 0x24, 0x5, 0x24, 
       0x194, 0xa, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x5, 0x24, 0x199, 
       0xa, 0x24, 0x3, 0x25, 0x6, 0x25, 0x19c, 0xa, 0x25, 0xd, 0x25, 0xe, 
       0x25, 0x19d, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x7, 0x26, 0x1a3, 0xa, 
       0x26, 0xc, 0x26, 0xe, 0x26, 0x1a6, 0xb, 0x26, 0x3, 0x27, 0x3, 0x27, 
       0x5, 0x27, 0x1aa, 0xa, 0x27, 0x3, 0x27, 0x3, 0x27, 0x5, 0x27, 0x1ae, 
       0xa, 0x27, 0x3, 0x28, 0x3, 0x28, 0x5, 0x28, 0x1b2, 0xa, 0x28, 0x3, 
       0x28, 0x3, 0x28, 0x3, 0x28, 0x5, 0x28, 0x1b7, 0xa, 0x28, 0x3, 0x28, 
       0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x5, 0x28, 0x1bd, 0xa, 0x28, 0x3, 
       0x29, 0x3, 0x29, 0x3, 0x29, 0x7, 0x29, 0x1c2, 0xa, 0x29, 0xc, 0x29, 
       0xe, 0x29, 0x1c5, 0xb, 0x29, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x5, 
       0x2a, 0x1ca, 0xa, 0x2a, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 
       0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 
       0x3, 0x2e, 0x3, 0x2e, 0x5, 0x2e, 0x1d8, 0xa, 0x2e, 0x3, 0x2e, 0x3, 
       0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 
       0x2e, 0x5, 0x2e, 0x1e2, 0xa, 0x2e, 0x3, 0x2e, 0x7, 0x2e, 0x1e5, 0xa, 
       0x2e, 0xc, 0x2e, 0xe, 0x2e, 0x1e8, 0xb, 0x2e, 0x3, 0x2f, 0x3, 0x2f, 
       0x3, 0x2f, 0x5, 0x2f, 0x1ed, 0xa, 0x2f, 0x3, 0x30, 0x3, 0x30, 0x3, 
       0x30, 0x7, 0x30, 0x1f2, 0xa, 0x30, 0xc, 0x30, 0xe, 0x30, 0x1f5, 0xb, 
       0x30, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x5, 
       0x31, 0x1fc, 0xa, 0x31, 0x5, 0x31, 0x1fe, 0xa, 0x31, 0x3, 0x32, 0x3, 
       0x32, 0x3, 0x32, 0x7, 0x32, 0x203, 0xa, 0x32, 0xc, 0x32, 0xe, 0x32, 
       0x206, 0xb, 0x32, 0x3, 0x33, 0x3, 0x33, 0x5, 0x33, 0x20a, 0xa, 0x33, 
       0x3, 0x34, 0x3, 0x34, 0x3, 0x35, 0x6, 0x35, 0x20f, 0xa, 0x35, 0xd, 
       0x35, 0xe, 0x35, 0x210, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 
       0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x5, 0x36, 
       0x21c, 0xa, 0x36, 0x3, 0x36, 0x5, 0x36, 0x21f, 0xa, 0x36, 0x3, 0x37, 
       0x3, 0x37, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x5, 0x38, 
       0x227, 0xa, 0x38, 0x3, 0x38, 0x3, 0x38, 0x5, 0x38, 0x22b, 0xa, 0x38, 
       0x3, 0x39, 0x5, 0x39, 0x22e, 0xa, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 
       0x39, 0x5, 0x39, 0x233, 0xa, 0x39, 0x3, 0x39, 0x7, 0x39, 0x236, 0xa, 
       0x39, 0xc, 0x39, 0xe, 0x39, 0x239, 0xb, 0x39, 0x3, 0x3a, 0x3, 0x3a, 
       0x3, 0x3a, 0x3, 0x3b, 0x6, 0x3b, 0x23f, 0xa, 0x3b, 0xd, 0x3b, 0xe, 
       0x3b, 0x240, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 
       0x3, 0x3c, 0x5, 0x3c, 0x249, 0xa, 0x3c, 0x3, 0x3d, 0x3, 0x3d, 0x3, 
       0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x6, 0x3d, 0x250, 0xa, 0x3d, 0xd, 0x3d, 
       0xe, 0x3d, 0x251, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3e, 0x3, 
       0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x5, 0x3e, 0x25d, 
       0xa, 0x3e, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 
       0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 
       0x5, 0x3f, 0x26a, 0xa, 0x3f, 0x3, 0x40, 0x3, 0x40, 0x7, 0x40, 0x26e, 
       0xa, 0x40, 0xc, 0x40, 0xe, 0x40, 0x271, 0xb, 0x40, 0x3, 0x40, 0x3, 
       0x40, 0x3, 0x41, 0x3, 0x41, 0x5, 0x41, 0x277, 0xa, 0x41, 0x3, 0x42, 
       0x5, 0x42, 0x27a, 0xa, 0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 0x43, 0x3, 
       0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x5, 
       0x43, 0x285, 0xa, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 
       0x3, 0x43, 0x3, 0x43, 0x5, 0x43, 0x28d, 0xa, 0x43, 0x3, 0x44, 0x3, 
       0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 
       0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 
       0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 
       0x44, 0x5, 0x44, 0x2a3, 0xa, 0x44, 0x3, 0x45, 0x3, 0x45, 0x5, 0x45, 
       0x2a7, 0xa, 0x45, 0x3, 0x45, 0x5, 0x45, 0x2aa, 0xa, 0x45, 0x3, 0x45, 
       0x5, 0x45, 0x2ad, 0xa, 0x45, 0x3, 0x45, 0x3, 0x45, 0x5, 0x45, 0x2b1, 
       0xa, 0x45, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 0x7, 0x46, 0x2b6, 0xa, 
       0x46, 0xc, 0x46, 0xe, 0x46, 0x2b9, 0xb, 0x46, 0x3, 0x47, 0x3, 0x47, 
       0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 0x5, 0x47, 0x2c1, 0xa, 
       0x47, 0x5, 0x47, 0x2c3, 0xa, 0x47, 0x3, 0x47, 0x3, 0x47, 0x3, 0x48, 
       0x5, 0x48, 0x2c8, 0xa, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x49, 0x6, 
       0x49, 0x2cd, 0xa, 0x49, 0xd, 0x49, 0xe, 0x49, 0x2ce, 0x3, 0x4a, 0x3, 
       0x4a, 0x3, 0x4a, 0x5, 0x4a, 0x2d4, 0xa, 0x4a, 0x3, 0x4b, 0x5, 0x4b, 
       0x2d7, 0xa, 0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x5, 0x4b, 0x2db, 0xa, 0x4b, 
       0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4c, 0x6, 0x4c, 0x2e0, 0xa, 0x4c, 0xd, 
       0x4c, 0xe, 0x4c, 0x2e1, 0x3, 0x4c, 0x2, 0x3, 0x5a, 0x4d, 0x2, 0x4, 
       0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 
       0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 
       0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 
       0x4a, 0x4c, 0x4e, 0x50, 0x52, 0x54, 0x56, 0x58, 0x5a, 0x5c, 0x5e, 
       0x60, 0x62, 0x64, 0x66, 0x68, 0x6a, 0x6c, 0x6e, 0x70, 0x72, 0x74, 
       0x76, 0x78, 0x7a, 0x7c, 0x7e, 0x80, 0x82, 0x84, 0x86, 0x88, 0x8a, 
       0x8c, 0x8e, 0x90, 0x92, 0x94, 0x96, 0x2, 0x10, 0x3, 0x2, 0x5a, 0x5b, 
       0x4, 0x2, 0x3c, 0x3c, 0x3e, 0x3e, 0x5, 0x2, 0x1b, 0x1b, 0x3c, 0x3c, 
       0x3e, 0x3e, 0x7, 0x2, 0x3b, 0x3b, 0x3d, 0x3d, 0x3f, 0x3f, 0x42, 0x42, 
       0x47, 0x48, 0x3, 0x2, 0x3f, 0x41, 0x4, 0x2, 0x3b, 0x3b, 0x3d, 0x3d, 
       0x3, 0x2, 0x39, 0x3a, 0x3, 0x2, 0x35, 0x38, 0x3, 0x2, 0x58, 0x59, 
       0x3, 0x2, 0x4d, 0x57, 0x6, 0x2, 0x3, 0x3, 0xe, 0xe, 0x16, 0x16, 0x1c, 
       0x1c, 0x9, 0x2, 0x6, 0x6, 0xb, 0xb, 0xf, 0xf, 0x14, 0x15, 0x19, 0x1a, 
       0x21, 0x22, 0x28, 0x28, 0x4, 0x2, 0x1d, 0x1d, 0x20, 0x20, 0x4, 0x2, 
       0x13, 0x13, 0x2c, 0x2c, 0x2, 0x2ff, 0x2, 0xa3, 0x3, 0x2, 0x2, 0x2, 
       0x4, 0xb0, 0x3, 0x2, 0x2, 0x2, 0x6, 0xc3, 0x3, 0x2, 0x2, 0x2, 0x8, 
       0xce, 0x3, 0x2, 0x2, 0x2, 0xa, 0xdc, 0x3, 0x2, 0x2, 0x2, 0xc, 0xe5, 
       0x3, 0x2, 0x2, 0x2, 0xe, 0xe7, 0x3, 0x2, 0x2, 0x2, 0x10, 0xef, 0x3, 
       0x2, 0x2, 0x2, 0x12, 0xf7, 0x3, 0x2, 0x2, 0x2, 0x14, 0xff, 0x3, 0x2, 
       0x2, 0x2, 0x16, 0x107, 0x3, 0x2, 0x2, 0x2, 0x18, 0x10f, 0x3, 0x2, 
       0x2, 0x2, 0x1a, 0x117, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x11f, 0x3, 0x2, 
       0x2, 0x2, 0x1e, 0x127, 0x3, 0x2, 0x2, 0x2, 0x20, 0x12f, 0x3, 0x2, 
       0x2, 0x2, 0x22, 0x137, 0x3, 0x2, 0x2, 0x2, 0x24, 0x145, 0x3, 0x2, 
       0x2, 0x2, 0x26, 0x147, 0x3, 0x2, 0x2, 0x2, 0x28, 0x149, 0x3, 0x2, 
       0x2, 0x2, 0x2a, 0x151, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x15a, 0x3, 0x2, 
       0x2, 0x2, 0x2e, 0x15d, 0x3, 0x2, 0x2, 0x2, 0x30, 0x162, 0x3, 0x2, 
       0x2, 0x2, 0x32, 0x166, 0x3, 0x2, 0x2, 0x2, 0x34, 0x168, 0x3, 0x2, 
       0x2, 0x2, 0x36, 0x170, 0x3, 0x2, 0x2, 0x2, 0x38, 0x175, 0x3, 0x2, 
       0x2, 0x2, 0x3a, 0x177, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x179, 0x3, 0x2, 
       0x2, 0x2, 0x3e, 0x17b, 0x3, 0x2, 0x2, 0x2, 0x40, 0x188, 0x3, 0x2, 
       0x2, 0x2, 0x42, 0x18a, 0x3, 0x2, 0x2, 0x2, 0x44, 0x18d, 0x3, 0x2, 
       0x2, 0x2, 0x46, 0x198, 0x3, 0x2, 0x2, 0x2, 0x48, 0x19b, 0x3, 0x2, 
       0x2, 0x2, 0x4a, 0x19f, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x1ad, 0x3, 0x2, 
       0x2, 0x2, 0x4e, 0x1bc, 0x3, 0x2, 0x2, 0x2, 0x50, 0x1be, 0x3, 0x2, 
       0x2, 0x2, 0x52, 0x1c6, 0x3, 0x2, 0x2, 0x2, 0x54, 0x1cb, 0x3, 0x2, 
       0x2, 0x2, 0x56, 0x1cd, 0x3, 0x2, 0x2, 0x2, 0x58, 0x1cf, 0x3, 0x2, 
       0x2, 0x2, 0x5a, 0x1d7, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x1e9, 0x3, 0x2, 
       0x2, 0x2, 0x5e, 0x1ee, 0x3, 0x2, 0x2, 0x2, 0x60, 0x1fd, 0x3, 0x2, 
       0x2, 0x2, 0x62, 0x1ff, 0x3, 0x2, 0x2, 0x2, 0x64, 0x207, 0x3, 0x2, 
       0x2, 0x2, 0x66, 0x20b, 0x3, 0x2, 0x2, 0x2, 0x68, 0x20e, 0x3, 0x2, 
       0x2, 0x2, 0x6a, 0x21e, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x220, 0x3, 0x2, 
       0x2, 0x2, 0x6e, 0x22a, 0x3, 0x2, 0x2, 0x2, 0x70, 0x22d, 0x3, 0x2, 
       0x2, 0x2, 0x72, 0x23a, 0x3, 0x2, 0x2, 0x2, 0x74, 0x23e, 0x3, 0x2, 
       0x2, 0x2, 0x76, 0x248, 0x3, 0x2, 0x2, 0x2, 0x78, 0x24a, 0x3, 0x2, 
       0x2, 0x2, 0x7a, 0x25c, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x269, 0x3, 0x2, 
       0x2, 0x2, 0x7e, 0x26b, 0x3, 0x2, 0x2, 0x2, 0x80, 0x276, 0x3, 0x2, 
       0x2, 0x2, 0x82, 0x279, 0x3, 0x2, 0x2, 0x2, 0x84, 0x28c, 0x3, 0x2, 
       0x2, 0x2, 0x86, 0x2a2, 0x3, 0x2, 0x2, 0x2, 0x88, 0x2a9, 0x3, 0x2, 
       0x2, 0x2, 0x8a, 0x2b2, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x2c2, 0x3, 0x2, 
       0x2, 0x2, 0x8e, 0x2c7, 0x3, 0x2, 0x2, 0x2, 0x90, 0x2cc, 0x3, 0x2, 
       0x2, 0x2, 0x92, 0x2d3, 0x3, 0x2, 0x2, 0x2, 0x94, 0x2d6, 0x3, 0x2, 
       0x2, 0x2, 0x96, 0x2df, 0x3, 0x2, 0x2, 0x2, 0x98, 0xa4, 0x7, 0x5d, 
       0x2, 0x2, 0x99, 0xa4, 0x7, 0x5e, 0x2, 0x2, 0x9a, 0x9c, 0x7, 0x60, 
       0x2, 0x2, 0x9b, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x9d, 0x3, 0x2, 0x2, 
       0x2, 0x9d, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x9d, 0x9e, 0x3, 0x2, 0x2, 0x2, 
       0x9e, 0xa4, 0x3, 0x2, 0x2, 0x2, 0x9f, 0xa0, 0x7, 0x2f, 0x2, 0x2, 
       0xa0, 0xa1, 0x5, 0x28, 0x15, 0x2, 0xa1, 0xa2, 0x7, 0x30, 0x2, 0x2, 
       0xa2, 0xa4, 0x3, 0x2, 0x2, 0x2, 0xa3, 0x98, 0x3, 0x2, 0x2, 0x2, 0xa3, 
       0x99, 0x3, 0x2, 0x2, 0x2, 0xa3, 0x9b, 0x3, 0x2, 0x2, 0x2, 0xa3, 0x9f, 
       0x3, 0x2, 0x2, 0x2, 0xa4, 0x3, 0x3, 0x2, 0x2, 0x2, 0xa5, 0xb1, 0x5, 
       0x2, 0x2, 0x2, 0xa6, 0xa7, 0x7, 0x2f, 0x2, 0x2, 0xa7, 0xa8, 0x5, 
       0x64, 0x33, 0x2, 0xa8, 0xa9, 0x7, 0x30, 0x2, 0x2, 0xa9, 0xaa, 0x7, 
       0x33, 0x2, 0x2, 0xaa, 0xac, 0x5, 0x70, 0x39, 0x2, 0xab, 0xad, 0x7, 
       0x4c, 0x2, 0x2, 0xac, 0xab, 0x3, 0x2, 0x2, 0x2, 0xac, 0xad, 0x3, 
       0x2, 0x2, 0x2, 0xad, 0xae, 0x3, 0x2, 0x2, 0x2, 0xae, 0xaf, 0x7, 0x34, 
       0x2, 0x2, 0xaf, 0xb1, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xa5, 0x3, 0x2, 0x2, 
       0x2, 0xb0, 0xa6, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xc0, 0x3, 0x2, 0x2, 0x2, 
       0xb2, 0xb3, 0x7, 0x31, 0x2, 0x2, 0xb3, 0xb4, 0x5, 0x28, 0x15, 0x2, 
       0xb4, 0xb5, 0x7, 0x32, 0x2, 0x2, 0xb5, 0xbf, 0x3, 0x2, 0x2, 0x2, 
       0xb6, 0xb8, 0x7, 0x2f, 0x2, 0x2, 0xb7, 0xb9, 0x5, 0x6, 0x4, 0x2, 
       0xb8, 0xb7, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xb9, 
       0xba, 0x3, 0x2, 0x2, 0x2, 0xba, 0xbf, 0x7, 0x30, 0x2, 0x2, 0xbb, 
       0xbc, 0x9, 0x2, 0x2, 0x2, 0xbc, 0xbf, 0x7, 0x5d, 0x2, 0x2, 0xbd, 
       0xbf, 0x9, 0x3, 0x2, 0x2, 0xbe, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xb6, 
       0x3, 0x2, 0x2, 0x2, 0xbe, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xbd, 0x3, 
       0x2, 0x2, 0x2, 0xbf, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xbe, 0x3, 0x2, 
       0x2, 0x2, 0xc0, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xc1, 0x5, 0x3, 0x2, 0x2, 
       0x2, 0xc2, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xc3, 0xc8, 0x5, 0x24, 0x13, 
       0x2, 0xc4, 0xc5, 0x7, 0x4c, 0x2, 0x2, 0xc5, 0xc7, 0x5, 0x24, 0x13, 
       0x2, 0xc6, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xca, 0x3, 0x2, 0x2, 0x2, 
       0xc8, 0xc6, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xc9, 
       0x7, 0x3, 0x2, 0x2, 0x2, 0xca, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xcd, 
       0x9, 0x4, 0x2, 0x2, 0xcc, 0xcb, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xd0, 0x3, 
       0x2, 0x2, 0x2, 0xce, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xce, 0xcf, 0x3, 0x2, 
       0x2, 0x2, 0xcf, 0xda, 0x3, 0x2, 0x2, 0x2, 0xd0, 0xce, 0x3, 0x2, 0x2, 
       0x2, 0xd1, 0xdb, 0x5, 0x4, 0x3, 0x2, 0xd2, 0xd3, 0x5, 0xa, 0x6, 0x2, 
       0xd3, 0xd4, 0x5, 0xc, 0x7, 0x2, 0xd4, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xd5, 
       0xd6, 0x7, 0x1b, 0x2, 0x2, 0xd6, 0xd7, 0x7, 0x2f, 0x2, 0x2, 0xd7, 
       0xd8, 0x5, 0x64, 0x33, 0x2, 0xd8, 0xd9, 0x7, 0x30, 0x2, 0x2, 0xd9, 
       0xdb, 0x3, 0x2, 0x2, 0x2, 0xda, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xda, 0xd2, 
       0x3, 0x2, 0x2, 0x2, 0xda, 0xd5, 0x3, 0x2, 0x2, 0x2, 0xdb, 0x9, 0x3, 
       0x2, 0x2, 0x2, 0xdc, 0xdd, 0x9, 0x5, 0x2, 0x2, 0xdd, 0xb, 0x3, 0x2, 
       0x2, 0x2, 0xde, 0xdf, 0x7, 0x2f, 0x2, 0x2, 0xdf, 0xe0, 0x5, 0x64, 
       0x33, 0x2, 0xe0, 0xe1, 0x7, 0x30, 0x2, 0x2, 0xe1, 0xe2, 0x5, 0xc, 
       0x7, 0x2, 0xe2, 0xe6, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xe6, 0x5, 0x8, 0x5, 
       0x2, 0xe4, 0xe6, 0x7, 0x5f, 0x2, 0x2, 0xe5, 0xde, 0x3, 0x2, 0x2, 
       0x2, 0xe5, 0xe3, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xe4, 0x3, 0x2, 0x2, 0x2, 
       0xe6, 0xd, 0x3, 0x2, 0x2, 0x2, 0xe7, 0xec, 0x5, 0xc, 0x7, 0x2, 0xe8, 
       0xe9, 0x9, 0x6, 0x2, 0x2, 0xe9, 0xeb, 0x5, 0xc, 0x7, 0x2, 0xea, 0xe8, 
       0x3, 0x2, 0x2, 0x2, 0xeb, 0xee, 0x3, 0x2, 0x2, 0x2, 0xec, 0xea, 0x3, 
       0x2, 0x2, 0x2, 0xec, 0xed, 0x3, 0x2, 0x2, 0x2, 0xed, 0xf, 0x3, 0x2, 
       0x2, 0x2, 0xee, 0xec, 0x3, 0x2, 0x2, 0x2, 0xef, 0xf4, 0x5, 0xe, 0x8, 
       0x2, 0xf0, 0xf1, 0x9, 0x7, 0x2, 0x2, 0xf1, 0xf3, 0x5, 0xe, 0x8, 0x2, 
       0xf2, 0xf0, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xf6, 0x3, 0x2, 0x2, 0x2, 0xf4, 
       0xf2, 0x3, 0x2, 0x2, 0x2, 0xf4, 0xf5, 0x3, 0x2, 0x2, 0x2, 0xf5, 0x11, 
       0x3, 0x2, 0x2, 0x2, 0xf6, 0xf4, 0x3, 0x2, 0x2, 0x2, 0xf7, 0xfc, 0x5, 
       0x10, 0x9, 0x2, 0xf8, 0xf9, 0x9, 0x8, 0x2, 0x2, 0xf9, 0xfb, 0x5, 
       0x10, 0x9, 0x2, 0xfa, 0xf8, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xfe, 0x3, 
       0x2, 0x2, 0x2, 0xfc, 0xfa, 0x3, 0x2, 0x2, 0x2, 0xfc, 0xfd, 0x3, 0x2, 
       0x2, 0x2, 0xfd, 0x13, 0x3, 0x2, 0x2, 0x2, 0xfe, 0xfc, 0x3, 0x2, 0x2, 
       0x2, 0xff, 0x104, 0x5, 0x12, 0xa, 0x2, 0x100, 0x101, 0x9, 0x9, 0x2, 
       0x2, 0x101, 0x103, 0x5, 0x12, 0xa, 0x2, 0x102, 0x100, 0x3, 0x2, 0x2, 
       0x2, 0x103, 0x106, 0x3, 0x2, 0x2, 0x2, 0x104, 0x102, 0x3, 0x2, 0x2, 
       0x2, 0x104, 0x105, 0x3, 0x2, 0x2, 0x2, 0x105, 0x15, 0x3, 0x2, 0x2, 
       0x2, 0x106, 0x104, 0x3, 0x2, 0x2, 0x2, 0x107, 0x10c, 0x5, 0x14, 0xb, 
       0x2, 0x108, 0x109, 0x9, 0xa, 0x2, 0x2, 0x109, 0x10b, 0x5, 0x14, 0xb, 
       0x2, 0x10a, 0x108, 0x3, 0x2, 0x2, 0x2, 0x10b, 0x10e, 0x3, 0x2, 0x2, 
       0x2, 0x10c, 0x10a, 0x3, 0x2, 0x2, 0x2, 0x10c, 0x10d, 0x3, 0x2, 0x2, 
       0x2, 0x10d, 0x17, 0x3, 0x2, 0x2, 0x2, 0x10e, 0x10c, 0x3, 0x2, 0x2, 
       0x2, 0x10f, 0x114, 0x5, 0x16, 0xc, 0x2, 0x110, 0x111, 0x7, 0x42, 
       0x2, 0x2, 0x111, 0x113, 0x5, 0x16, 0xc, 0x2, 0x112, 0x110, 0x3, 0x2, 
       0x2, 0x2, 0x113, 0x116, 0x3, 0x2, 0x2, 0x2, 0x114, 0x112, 0x3, 0x2, 
       0x2, 0x2, 0x114, 0x115, 0x3, 0x2, 0x2, 0x2, 0x115, 0x19, 0x3, 0x2, 
       0x2, 0x2, 0x116, 0x114, 0x3, 0x2, 0x2, 0x2, 0x117, 0x11c, 0x5, 0x18, 
       0xd, 0x2, 0x118, 0x119, 0x7, 0x46, 0x2, 0x2, 0x119, 0x11b, 0x5, 0x18, 
       0xd, 0x2, 0x11a, 0x118, 0x3, 0x2, 0x2, 0x2, 0x11b, 0x11e, 0x3, 0x2, 
       0x2, 0x2, 0x11c, 0x11a, 0x3, 0x2, 0x2, 0x2, 0x11c, 0x11d, 0x3, 0x2, 
       0x2, 0x2, 0x11d, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x11e, 0x11c, 0x3, 0x2, 
       0x2, 0x2, 0x11f, 0x124, 0x5, 0x1a, 0xe, 0x2, 0x120, 0x121, 0x7, 0x43, 
       0x2, 0x2, 0x121, 0x123, 0x5, 0x1a, 0xe, 0x2, 0x122, 0x120, 0x3, 0x2, 
       0x2, 0x2, 0x123, 0x126, 0x3, 0x2, 0x2, 0x2, 0x124, 0x122, 0x3, 0x2, 
       0x2, 0x2, 0x124, 0x125, 0x3, 0x2, 0x2, 0x2, 0x125, 0x1d, 0x3, 0x2, 
       0x2, 0x2, 0x126, 0x124, 0x3, 0x2, 0x2, 0x2, 0x127, 0x12c, 0x5, 0x1c, 
       0xf, 0x2, 0x128, 0x129, 0x7, 0x44, 0x2, 0x2, 0x129, 0x12b, 0x5, 0x1c, 
       0xf, 0x2, 0x12a, 0x128, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x12e, 0x3, 0x2, 
       0x2, 0x2, 0x12c, 0x12a, 0x3, 0x2, 0x2, 0x2, 0x12c, 0x12d, 0x3, 0x2, 
       0x2, 0x2, 0x12d, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x12c, 0x3, 0x2, 
       0x2, 0x2, 0x12f, 0x134, 0x5, 0x1e, 0x10, 0x2, 0x130, 0x131, 0x7, 
       0x45, 0x2, 0x2, 0x131, 0x133, 0x5, 0x1e, 0x10, 0x2, 0x132, 0x130, 
       0x3, 0x2, 0x2, 0x2, 0x133, 0x136, 0x3, 0x2, 0x2, 0x2, 0x134, 0x132, 
       0x3, 0x2, 0x2, 0x2, 0x134, 0x135, 0x3, 0x2, 0x2, 0x2, 0x135, 0x21, 
       0x3, 0x2, 0x2, 0x2, 0x136, 0x134, 0x3, 0x2, 0x2, 0x2, 0x137, 0x13d, 
       0x5, 0x20, 0x11, 0x2, 0x138, 0x139, 0x7, 0x49, 0x2, 0x2, 0x139, 0x13a, 
       0x5, 0x28, 0x15, 0x2, 0x13a, 0x13b, 0x7, 0x4a, 0x2, 0x2, 0x13b, 0x13c, 
       0x5, 0x22, 0x12, 0x2, 0x13c, 0x13e, 0x3, 0x2, 0x2, 0x2, 0x13d, 0x138, 
       0x3, 0x2, 0x2, 0x2, 0x13d, 0x13e, 0x3, 0x2, 0x2, 0x2, 0x13e, 0x23, 
       0x3, 0x2, 0x2, 0x2, 0x13f, 0x146, 0x5, 0x22, 0x12, 0x2, 0x140, 0x141, 
       0x5, 0x8, 0x5, 0x2, 0x141, 0x142, 0x5, 0x26, 0x14, 0x2, 0x142, 0x143, 
       0x5, 0x24, 0x13, 0x2, 0x143, 0x146, 0x3, 0x2, 0x2, 0x2, 0x144, 0x146, 
       0x7, 0x5f, 0x2, 0x2, 0x145, 0x13f, 0x3, 0x2, 0x2, 0x2, 0x145, 0x140, 
       0x3, 0x2, 0x2, 0x2, 0x145, 0x144, 0x3, 0x2, 0x2, 0x2, 0x146, 0x25, 
       0x3, 0x2, 0x2, 0x2, 0x147, 0x148, 0x9, 0xb, 0x2, 0x2, 0x148, 0x27, 
       0x3, 0x2, 0x2, 0x2, 0x149, 0x14e, 0x5, 0x24, 0x13, 0x2, 0x14a, 0x14b, 
       0x7, 0x4c, 0x2, 0x2, 0x14b, 0x14d, 0x5, 0x24, 0x13, 0x2, 0x14c, 0x14a, 
       0x3, 0x2, 0x2, 0x2, 0x14d, 0x150, 0x3, 0x2, 0x2, 0x2, 0x14e, 0x14c, 
       0x3, 0x2, 0x2, 0x2, 0x14e, 0x14f, 0x3, 0x2, 0x2, 0x2, 0x14f, 0x29, 
       0x3, 0x2, 0x2, 0x2, 0x150, 0x14e, 0x3, 0x2, 0x2, 0x2, 0x151, 0x152, 
       0x5, 0x22, 0x12, 0x2, 0x152, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x153, 0x155, 
       0x5, 0x2e, 0x18, 0x2, 0x154, 0x156, 0x5, 0x34, 0x1b, 0x2, 0x155, 
       0x154, 0x3, 0x2, 0x2, 0x2, 0x155, 0x156, 0x3, 0x2, 0x2, 0x2, 0x156, 
       0x157, 0x3, 0x2, 0x2, 0x2, 0x157, 0x158, 0x7, 0x4b, 0x2, 0x2, 0x158, 
       0x15b, 0x3, 0x2, 0x2, 0x2, 0x159, 0x15b, 0x5, 0x78, 0x3d, 0x2, 0x15a, 
       0x153, 0x3, 0x2, 0x2, 0x2, 0x15a, 0x159, 0x3, 0x2, 0x2, 0x2, 0x15b, 
       0x2d, 0x3, 0x2, 0x2, 0x2, 0x15c, 0x15e, 0x5, 0x38, 0x1d, 0x2, 0x15d, 
       0x15c, 0x3, 0x2, 0x2, 0x2, 0x15d, 0x15e, 0x3, 0x2, 0x2, 0x2, 0x15e, 
       0x15f, 0x3, 0x2, 0x2, 0x2, 0x15f, 0x160, 0x5, 0x30, 0x19, 0x2, 0x160, 
       0x2f, 0x3, 0x2, 0x2, 0x2, 0x161, 0x163, 0x5, 0x32, 0x1a, 0x2, 0x162, 
       0x161, 0x3, 0x2, 0x2, 0x2, 0x163, 0x164, 0x3, 0x2, 0x2, 0x2, 0x164, 
       0x162, 0x3, 0x2, 0x2, 0x2, 0x164, 0x165, 0x3, 0x2, 0x2, 0x2, 0x165, 
       0x31, 0x3, 0x2, 0x2, 0x2, 0x166, 0x167, 0x5, 0x3c, 0x1f, 0x2, 0x167, 
       0x33, 0x3, 0x2, 0x2, 0x2, 0x168, 0x16d, 0x5, 0x36, 0x1c, 0x2, 0x169, 
       0x16a, 0x7, 0x4c, 0x2, 0x2, 0x16a, 0x16c, 0x5, 0x36, 0x1c, 0x2, 0x16b, 
       0x169, 0x3, 0x2, 0x2, 0x2, 0x16c, 0x16f, 0x3, 0x2, 0x2, 0x2, 0x16d, 
       0x16b, 0x3, 0x2, 0x2, 0x2, 0x16d, 0x16e, 0x3, 0x2, 0x2, 0x2, 0x16e, 
       0x35, 0x3, 0x2, 0x2, 0x2, 0x16f, 0x16d, 0x3, 0x2, 0x2, 0x2, 0x170, 
       0x173, 0x5, 0x58, 0x2d, 0x2, 0x171, 0x172, 0x7, 0x4d, 0x2, 0x2, 0x172, 
       0x174, 0x5, 0x6e, 0x38, 0x2, 0x173, 0x171, 0x3, 0x2, 0x2, 0x2, 0x173, 
       0x174, 0x3, 0x2, 0x2, 0x2, 0x174, 0x37, 0x3, 0x2, 0x2, 0x2, 0x175, 
       0x176, 0x7, 0x1f, 0x2, 0x2, 0x176, 0x39, 0x3, 0x2, 0x2, 0x2, 0x177, 
       0x178, 0x9, 0xc, 0x2, 0x2, 0x178, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x179, 
       0x17a, 0x5, 0x3e, 0x20, 0x2, 0x17a, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x17b, 
       0x17c, 0x9, 0xd, 0x2, 0x2, 0x17c, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x17d, 
       0x17f, 0x5, 0x42, 0x22, 0x2, 0x17e, 0x180, 0x7, 0x5d, 0x2, 0x2, 0x17f, 
       0x17e, 0x3, 0x2, 0x2, 0x2, 0x17f, 0x180, 0x3, 0x2, 0x2, 0x2, 0x180, 
       0x181, 0x3, 0x2, 0x2, 0x2, 0x181, 0x182, 0x7, 0x33, 0x2, 0x2, 0x182, 
       0x183, 0x5, 0x44, 0x23, 0x2, 0x183, 0x184, 0x7, 0x34, 0x2, 0x2, 0x184, 
       0x189, 0x3, 0x2, 0x2, 0x2, 0x185, 0x186, 0x5, 0x42, 0x22, 0x2, 0x186, 
       0x187, 0x7, 0x5d, 0x2, 0x2, 0x187, 0x189, 0x3, 0x2, 0x2, 0x2, 0x188, 
       0x17d, 0x3, 0x2, 0x2, 0x2, 0x188, 0x185, 0x3, 0x2, 0x2, 0x2, 0x189, 
       0x41, 0x3, 0x2, 0x2, 0x2, 0x18a, 0x18b, 0x9, 0xe, 0x2, 0x2, 0x18b, 
       0x43, 0x3, 0x2, 0x2, 0x2, 0x18c, 0x18e, 0x5, 0x46, 0x24, 0x2, 0x18d, 
       0x18c, 0x3, 0x2, 0x2, 0x2, 0x18e, 0x18f, 0x3, 0x2, 0x2, 0x2, 0x18f, 
       0x18d, 0x3, 0x2, 0x2, 0x2, 0x18f, 0x190, 0x3, 0x2, 0x2, 0x2, 0x190, 
       0x45, 0x3, 0x2, 0x2, 0x2, 0x191, 0x193, 0x5, 0x48, 0x25, 0x2, 0x192, 
       0x194, 0x5, 0x4a, 0x26, 0x2, 0x193, 0x192, 0x3, 0x2, 0x2, 0x2, 0x193, 
       0x194, 0x3, 0x2, 0x2, 0x2, 0x194, 0x195, 0x3, 0x2, 0x2, 0x2, 0x195, 
       0x196, 0x7, 0x4b, 0x2, 0x2, 0x196, 0x199, 0x3, 0x2, 0x2, 0x2, 0x197, 
       0x199, 0x5, 0x78, 0x3d, 0x2, 0x198, 0x191, 0x3, 0x2, 0x2, 0x2, 0x198, 
       0x197, 0x3, 0x2, 0x2, 0x2, 0x199, 0x47, 0x3, 0x2, 0x2, 0x2, 0x19a, 
       0x19c, 0x5, 0x3c, 0x1f, 0x2, 0x19b, 0x19a, 0x3, 0x2, 0x2, 0x2, 0x19c, 
       0x19d, 0x3, 0x2, 0x2, 0x2, 0x19d, 0x19b, 0x3, 0x2, 0x2, 0x2, 0x19d, 
       0x19e, 0x3, 0x2, 0x2, 0x2, 0x19e, 0x49, 0x3, 0x2, 0x2, 0x2, 0x19f, 
       0x1a4, 0x5, 0x4c, 0x27, 0x2, 0x1a0, 0x1a1, 0x7, 0x4c, 0x2, 0x2, 0x1a1, 
       0x1a3, 0x5, 0x4c, 0x27, 0x2, 0x1a2, 0x1a0, 0x3, 0x2, 0x2, 0x2, 0x1a3, 
       0x1a6, 0x3, 0x2, 0x2, 0x2, 0x1a4, 0x1a2, 0x3, 0x2, 0x2, 0x2, 0x1a4, 
       0x1a5, 0x3, 0x2, 0x2, 0x2, 0x1a5, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x1a6, 
       0x1a4, 0x3, 0x2, 0x2, 0x2, 0x1a7, 0x1ae, 0x5, 0x58, 0x2d, 0x2, 0x1a8, 
       0x1aa, 0x5, 0x58, 0x2d, 0x2, 0x1a9, 0x1a8, 0x3, 0x2, 0x2, 0x2, 0x1a9, 
       0x1aa, 0x3, 0x2, 0x2, 0x2, 0x1aa, 0x1ab, 0x3, 0x2, 0x2, 0x2, 0x1ab, 
       0x1ac, 0x7, 0x4a, 0x2, 0x2, 0x1ac, 0x1ae, 0x5, 0x2a, 0x16, 0x2, 0x1ad, 
       0x1a7, 0x3, 0x2, 0x2, 0x2, 0x1ad, 0x1a9, 0x3, 0x2, 0x2, 0x2, 0x1ae, 
       0x4d, 0x3, 0x2, 0x2, 0x2, 0x1af, 0x1b1, 0x7, 0xd, 0x2, 0x2, 0x1b0, 
       0x1b2, 0x7, 0x5d, 0x2, 0x2, 0x1b1, 0x1b0, 0x3, 0x2, 0x2, 0x2, 0x1b1, 
       0x1b2, 0x3, 0x2, 0x2, 0x2, 0x1b2, 0x1b3, 0x3, 0x2, 0x2, 0x2, 0x1b3, 
       0x1b4, 0x7, 0x33, 0x2, 0x2, 0x1b4, 0x1b6, 0x5, 0x50, 0x29, 0x2, 0x1b5, 
       0x1b7, 0x7, 0x4c, 0x2, 0x2, 0x1b6, 0x1b5, 0x3, 0x2, 0x2, 0x2, 0x1b6, 
       0x1b7, 0x3, 0x2, 0x2, 0x2, 0x1b7, 0x1b8, 0x3, 0x2, 0x2, 0x2, 0x1b8, 
       0x1b9, 0x7, 0x34, 0x2, 0x2, 0x1b9, 0x1bd, 0x3, 0x2, 0x2, 0x2, 0x1ba, 
       0x1bb, 0x7, 0xd, 0x2, 0x2, 0x1bb, 0x1bd, 0x7, 0x5d, 0x2, 0x2, 0x1bc, 
       0x1af, 0x3, 0x2, 0x2, 0x2, 0x1bc, 0x1ba, 0x3, 0x2, 0x2, 0x2, 0x1bd, 
       0x4f, 0x3, 0x2, 0x2, 0x2, 0x1be, 0x1c3, 0x5, 0x52, 0x2a, 0x2, 0x1bf, 
       0x1c0, 0x7, 0x4c, 0x2, 0x2, 0x1c0, 0x1c2, 0x5, 0x52, 0x2a, 0x2, 0x1c1, 
       0x1bf, 0x3, 0x2, 0x2, 0x2, 0x1c2, 0x1c5, 0x3, 0x2, 0x2, 0x2, 0x1c3, 
       0x1c1, 0x3, 0x2, 0x2, 0x2, 0x1c3, 0x1c4, 0x3, 0x2, 0x2, 0x2, 0x1c4, 
       0x51, 0x3, 0x2, 0x2, 0x2, 0x1c5, 0x1c3, 0x3, 0x2, 0x2, 0x2, 0x1c6, 
       0x1c9, 0x5, 0x54, 0x2b, 0x2, 0x1c7, 0x1c8, 0x7, 0x4d, 0x2, 0x2, 0x1c8, 
       0x1ca, 0x5, 0x2a, 0x16, 0x2, 0x1c9, 0x1c7, 0x3, 0x2, 0x2, 0x2, 0x1c9, 
       0x1ca, 0x3, 0x2, 0x2, 0x2, 0x1ca, 0x53, 0x3, 0x2, 0x2, 0x2, 0x1cb, 
       0x1cc, 0x7, 0x5d, 0x2, 0x2, 0x1cc, 0x55, 0x3, 0x2, 0x2, 0x2, 0x1cd, 
       0x1ce, 0x9, 0xf, 0x2, 0x2, 0x1ce, 0x57, 0x3, 0x2, 0x2, 0x2, 0x1cf, 
       0x1d0, 0x5, 0x5a, 0x2e, 0x2, 0x1d0, 0x59, 0x3, 0x2, 0x2, 0x2, 0x1d1, 
       0x1d2, 0x8, 0x2e, 0x1, 0x2, 0x1d2, 0x1d8, 0x7, 0x5d, 0x2, 0x2, 0x1d3, 
       0x1d4, 0x7, 0x2f, 0x2, 0x2, 0x1d4, 0x1d5, 0x5, 0x58, 0x2d, 0x2, 0x1d5, 
       0x1d6, 0x7, 0x30, 0x2, 0x2, 0x1d6, 0x1d8, 0x3, 0x2, 0x2, 0x2, 0x1d7, 
       0x1d1, 0x3, 0x2, 0x2, 0x2, 0x1d7, 0x1d3, 0x3, 0x2, 0x2, 0x2, 0x1d8, 
       0x1e6, 0x3, 0x2, 0x2, 0x2, 0x1d9, 0x1da, 0xc, 0x4, 0x2, 0x2, 0x1da, 
       0x1db, 0x7, 0x2f, 0x2, 0x2, 0x1db, 0x1dc, 0x5, 0x5c, 0x2f, 0x2, 0x1dc, 
       0x1dd, 0x7, 0x30, 0x2, 0x2, 0x1dd, 0x1e5, 0x3, 0x2, 0x2, 0x2, 0x1de, 
       0x1df, 0xc, 0x3, 0x2, 0x2, 0x1df, 0x1e1, 0x7, 0x2f, 0x2, 0x2, 0x1e0, 
       0x1e2, 0x5, 0x62, 0x32, 0x2, 0x1e1, 0x1e0, 0x3, 0x2, 0x2, 0x2, 0x1e1, 
       0x1e2, 0x3, 0x2, 0x2, 0x2, 0x1e2, 0x1e3, 0x3, 0x2, 0x2, 0x2, 0x1e3, 
       0x1e5, 0x7, 0x30, 0x2, 0x2, 0x1e4, 0x1d9, 0x3, 0x2, 0x2, 0x2, 0x1e4, 
       0x1de, 0x3, 0x2, 0x2, 0x2, 0x1e5, 0x1e8, 0x3, 0x2, 0x2, 0x2, 0x1e6, 
       0x1e4, 0x3, 0x2, 0x2, 0x2, 0x1e6, 0x1e7, 0x3, 0x2, 0x2, 0x2, 0x1e7, 
       0x5b, 0x3, 0x2, 0x2, 0x2, 0x1e8, 0x1e6, 0x3, 0x2, 0x2, 0x2, 0x1e9, 
       0x1ec, 0x5, 0x5e, 0x30, 0x2, 0x1ea, 0x1eb, 0x7, 0x4c, 0x2, 0x2, 0x1eb, 
       0x1ed, 0x7, 0x5c, 0x2, 0x2, 0x1ec, 0x1ea, 0x3, 0x2, 0x2, 0x2, 0x1ec, 
       0x1ed, 0x3, 0x2, 0x2, 0x2, 0x1ed, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x1ee, 
       0x1f3, 0x5, 0x60, 0x31, 0x2, 0x1ef, 0x1f0, 0x7, 0x4c, 0x2, 0x2, 0x1f0, 
       0x1f2, 0x5, 0x60, 0x31, 0x2, 0x1f1, 0x1ef, 0x3, 0x2, 0x2, 0x2, 0x1f2, 
       0x1f5, 0x3, 0x2, 0x2, 0x2, 0x1f3, 0x1f1, 0x3, 0x2, 0x2, 0x2, 0x1f3, 
       0x1f4, 0x3, 0x2, 0x2, 0x2, 0x1f4, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x1f5, 
       0x1f3, 0x3, 0x2, 0x2, 0x2, 0x1f6, 0x1f7, 0x5, 0x2e, 0x18, 0x2, 0x1f7, 
       0x1f8, 0x5, 0x58, 0x2d, 0x2, 0x1f8, 0x1fe, 0x3, 0x2, 0x2, 0x2, 0x1f9, 
       0x1fb, 0x5, 0x2e, 0x18, 0x2, 0x1fa, 0x1fc, 0x5, 0x66, 0x34, 0x2, 
       0x1fb, 0x1fa, 0x3, 0x2, 0x2, 0x2, 0x1fb, 0x1fc, 0x3, 0x2, 0x2, 0x2, 
       0x1fc, 0x1fe, 0x3, 0x2, 0x2, 0x2, 0x1fd, 0x1f6, 0x3, 0x2, 0x2, 0x2, 
       0x1fd, 0x1f9, 0x3, 0x2, 0x2, 0x2, 0x1fe, 0x61, 0x3, 0x2, 0x2, 0x2, 
       0x1ff, 0x204, 0x7, 0x5d, 0x2, 0x2, 0x200, 0x201, 0x7, 0x4c, 0x2, 
       0x2, 0x201, 0x203, 0x7, 0x5d, 0x2, 0x2, 0x202, 0x200, 0x3, 0x2, 0x2, 
       0x2, 0x203, 0x206, 0x3, 0x2, 0x2, 0x2, 0x204, 0x202, 0x3, 0x2, 0x2, 
       0x2, 0x204, 0x205, 0x3, 0x2, 0x2, 0x2, 0x205, 0x63, 0x3, 0x2, 0x2, 
       0x2, 0x206, 0x204, 0x3, 0x2, 0x2, 0x2, 0x207, 0x209, 0x5, 0x48, 0x25, 
       0x2, 0x208, 0x20a, 0x5, 0x66, 0x34, 0x2, 0x209, 0x208, 0x3, 0x2, 
       0x2, 0x2, 0x209, 0x20a, 0x3, 0x2, 0x2, 0x2, 0x20a, 0x65, 0x3, 0x2, 
       0x2, 0x2, 0x20b, 0x20c, 0x5, 0x68, 0x35, 0x2, 0x20c, 0x67, 0x3, 0x2, 
       0x2, 0x2, 0x20d, 0x20f, 0x5, 0x6a, 0x36, 0x2, 0x20e, 0x20d, 0x3, 
       0x2, 0x2, 0x2, 0x20f, 0x210, 0x3, 0x2, 0x2, 0x2, 0x210, 0x20e, 0x3, 
       0x2, 0x2, 0x2, 0x210, 0x211, 0x3, 0x2, 0x2, 0x2, 0x211, 0x69, 0x3, 
       0x2, 0x2, 0x2, 0x212, 0x213, 0x7, 0x2f, 0x2, 0x2, 0x213, 0x214, 0x5, 
       0x66, 0x34, 0x2, 0x214, 0x215, 0x7, 0x30, 0x2, 0x2, 0x215, 0x21f, 
       0x3, 0x2, 0x2, 0x2, 0x216, 0x217, 0x7, 0x31, 0x2, 0x2, 0x217, 0x218, 
       0x7, 0x3f, 0x2, 0x2, 0x218, 0x21f, 0x7, 0x32, 0x2, 0x2, 0x219, 0x21b, 
       0x7, 0x2f, 0x2, 0x2, 0x21a, 0x21c, 0x5, 0x5c, 0x2f, 0x2, 0x21b, 0x21a, 
       0x3, 0x2, 0x2, 0x2, 0x21b, 0x21c, 0x3, 0x2, 0x2, 0x2, 0x21c, 0x21d, 
       0x3, 0x2, 0x2, 0x2, 0x21d, 0x21f, 0x7, 0x30, 0x2, 0x2, 0x21e, 0x212, 
       0x3, 0x2, 0x2, 0x2, 0x21e, 0x216, 0x3, 0x2, 0x2, 0x2, 0x21e, 0x219, 
       0x3, 0x2, 0x2, 0x2, 0x21f, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x220, 0x221, 
       0x7, 0x5d, 0x2, 0x2, 0x221, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x222, 0x22b, 
       0x5, 0x24, 0x13, 0x2, 0x223, 0x224, 0x7, 0x33, 0x2, 0x2, 0x224, 0x226, 
       0x5, 0x70, 0x39, 0x2, 0x225, 0x227, 0x7, 0x4c, 0x2, 0x2, 0x226, 0x225, 
       0x3, 0x2, 0x2, 0x2, 0x226, 0x227, 0x3, 0x2, 0x2, 0x2, 0x227, 0x228, 
       0x3, 0x2, 0x2, 0x2, 0x228, 0x229, 0x7, 0x34, 0x2, 0x2, 0x229, 0x22b, 
       0x3, 0x2, 0x2, 0x2, 0x22a, 0x222, 0x3, 0x2, 0x2, 0x2, 0x22a, 0x223, 
       0x3, 0x2, 0x2, 0x2, 0x22b, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x22c, 0x22e, 
       0x5, 0x72, 0x3a, 0x2, 0x22d, 0x22c, 0x3, 0x2, 0x2, 0x2, 0x22d, 0x22e, 
       0x3, 0x2, 0x2, 0x2, 0x22e, 0x22f, 0x3, 0x2, 0x2, 0x2, 0x22f, 0x237, 
       0x5, 0x6e, 0x38, 0x2, 0x230, 0x232, 0x7, 0x4c, 0x2, 0x2, 0x231, 0x233, 
       0x5, 0x72, 0x3a, 0x2, 0x232, 0x231, 0x3, 0x2, 0x2, 0x2, 0x232, 0x233, 
       0x3, 0x2, 0x2, 0x2, 0x233, 0x234, 0x3, 0x2, 0x2, 0x2, 0x234, 0x236, 
       0x5, 0x6e, 0x38, 0x2, 0x235, 0x230, 0x3, 0x2, 0x2, 0x2, 0x236, 0x239, 
       0x3, 0x2, 0x2, 0x2, 0x237, 0x235, 0x3, 0x2, 0x2, 0x2, 0x237, 0x238, 
       0x3, 0x2, 0x2, 0x2, 0x238, 0x71, 0x3, 0x2, 0x2, 0x2, 0x239, 0x237, 
       0x3, 0x2, 0x2, 0x2, 0x23a, 0x23b, 0x5, 0x74, 0x3b, 0x2, 0x23b, 0x23c, 
       0x7, 0x4d, 0x2, 0x2, 0x23c, 0x73, 0x3, 0x2, 0x2, 0x2, 0x23d, 0x23f, 
       0x5, 0x76, 0x3c, 0x2, 0x23e, 0x23d, 0x3, 0x2, 0x2, 0x2, 0x23f, 0x240, 
       0x3, 0x2, 0x2, 0x2, 0x240, 0x23e, 0x3, 0x2, 0x2, 0x2, 0x240, 0x241, 
       0x3, 0x2, 0x2, 0x2, 0x241, 0x75, 0x3, 0x2, 0x2, 0x2, 0x242, 0x243, 
       0x7, 0x31, 0x2, 0x2, 0x243, 0x244, 0x5, 0x2a, 0x16, 0x2, 0x244, 0x245, 
       0x7, 0x32, 0x2, 0x2, 0x245, 0x249, 0x3, 0x2, 0x2, 0x2, 0x246, 0x247, 
       0x7, 0x5b, 0x2, 0x2, 0x247, 0x249, 0x7, 0x5d, 0x2, 0x2, 0x248, 0x242, 
       0x3, 0x2, 0x2, 0x2, 0x248, 0x246, 0x3, 0x2, 0x2, 0x2, 0x249, 0x77, 
       0x3, 0x2, 0x2, 0x2, 0x24a, 0x24b, 0x7, 0x2d, 0x2, 0x2, 0x24b, 0x24c, 
       0x7, 0x2f, 0x2, 0x2, 0x24c, 0x24d, 0x5, 0x2a, 0x16, 0x2, 0x24d, 0x24f, 
       0x7, 0x4c, 0x2, 0x2, 0x24e, 0x250, 0x7, 0x60, 0x2, 0x2, 0x24f, 0x24e, 
       0x3, 0x2, 0x2, 0x2, 0x250, 0x251, 0x3, 0x2, 0x2, 0x2, 0x251, 0x24f, 
       0x3, 0x2, 0x2, 0x2, 0x251, 0x252, 0x3, 0x2, 0x2, 0x2, 0x252, 0x253, 
       0x3, 0x2, 0x2, 0x2, 0x253, 0x254, 0x7, 0x30, 0x2, 0x2, 0x254, 0x255, 
       0x7, 0x4b, 0x2, 0x2, 0x255, 0x79, 0x3, 0x2, 0x2, 0x2, 0x256, 0x25d, 
       0x5, 0x7c, 0x3f, 0x2, 0x257, 0x25d, 0x5, 0x7e, 0x40, 0x2, 0x258, 
       0x25d, 0x5, 0x82, 0x42, 0x2, 0x259, 0x25d, 0x5, 0x84, 0x43, 0x2, 
       0x25a, 0x25d, 0x5, 0x86, 0x44, 0x2, 0x25b, 0x25d, 0x5, 0x8c, 0x47, 
       0x2, 0x25c, 0x256, 0x3, 0x2, 0x2, 0x2, 0x25c, 0x257, 0x3, 0x2, 0x2, 
       0x2, 0x25c, 0x258, 0x3, 0x2, 0x2, 0x2, 0x25c, 0x259, 0x3, 0x2, 0x2, 
       0x2, 0x25c, 0x25a, 0x3, 0x2, 0x2, 0x2, 0x25c, 0x25b, 0x3, 0x2, 0x2, 
       0x2, 0x25d, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x25e, 0x25f, 0x7, 0x5d, 0x2, 
       0x2, 0x25f, 0x260, 0x7, 0x4a, 0x2, 0x2, 0x260, 0x26a, 0x5, 0x7a, 
       0x3e, 0x2, 0x261, 0x262, 0x7, 0x5, 0x2, 0x2, 0x262, 0x263, 0x5, 0x2a, 
       0x16, 0x2, 0x263, 0x264, 0x7, 0x4a, 0x2, 0x2, 0x264, 0x265, 0x5, 
       0x7a, 0x3e, 0x2, 0x265, 0x26a, 0x3, 0x2, 0x2, 0x2, 0x266, 0x267, 
       0x7, 0x9, 0x2, 0x2, 0x267, 0x268, 0x7, 0x4a, 0x2, 0x2, 0x268, 0x26a, 
       0x5, 0x7a, 0x3e, 0x2, 0x269, 0x25e, 0x3, 0x2, 0x2, 0x2, 0x269, 0x261, 
       0x3, 0x2, 0x2, 0x2, 0x269, 0x266, 0x3, 0x2, 0x2, 0x2, 0x26a, 0x7d, 
       0x3, 0x2, 0x2, 0x2, 0x26b, 0x26f, 0x7, 0x33, 0x2, 0x2, 0x26c, 0x26e, 
       0x5, 0x80, 0x41, 0x2, 0x26d, 0x26c, 0x3, 0x2, 0x2, 0x2, 0x26e, 0x271, 
       0x3, 0x2, 0x2, 0x2, 0x26f, 0x26d, 0x3, 0x2, 0x2, 0x2, 0x26f, 0x270, 
       0x3, 0x2, 0x2, 0x2, 0x270, 0x272, 0x3, 0x2, 0x2, 0x2, 0x271, 0x26f, 
       0x3, 0x2, 0x2, 0x2, 0x272, 0x273, 0x7, 0x34, 0x2, 0x2, 0x273, 0x7f, 
       0x3, 0x2, 0x2, 0x2, 0x274, 0x277, 0x5, 0x7a, 0x3e, 0x2, 0x275, 0x277, 
       0x5, 0x2c, 0x17, 0x2, 0x276, 0x274, 0x3, 0x2, 0x2, 0x2, 0x276, 0x275, 
       0x3, 0x2, 0x2, 0x2, 0x277, 0x81, 0x3, 0x2, 0x2, 0x2, 0x278, 0x27a, 
       0x5, 0x28, 0x15, 0x2, 0x279, 0x278, 0x3, 0x2, 0x2, 0x2, 0x279, 0x27a, 
       0x3, 0x2, 0x2, 0x2, 0x27a, 0x27b, 0x3, 0x2, 0x2, 0x2, 0x27b, 0x27c, 
       0x7, 0x4b, 0x2, 0x2, 0x27c, 0x83, 0x3, 0x2, 0x2, 0x2, 0x27d, 0x27e, 
       0x7, 0x12, 0x2, 0x2, 0x27e, 0x27f, 0x7, 0x2f, 0x2, 0x2, 0x27f, 0x280, 
       0x5, 0x28, 0x15, 0x2, 0x280, 0x281, 0x7, 0x30, 0x2, 0x2, 0x281, 0x284, 
       0x5, 0x7a, 0x3e, 0x2, 0x282, 0x283, 0x7, 0xc, 0x2, 0x2, 0x283, 0x285, 
       0x5, 0x7a, 0x3e, 0x2, 0x284, 0x282, 0x3, 0x2, 0x2, 0x2, 0x284, 0x285, 
       0x3, 0x2, 0x2, 0x2, 0x285, 0x28d, 0x3, 0x2, 0x2, 0x2, 0x286, 0x287, 
       0x7, 0x1e, 0x2, 0x2, 0x287, 0x288, 0x7, 0x2f, 0x2, 0x2, 0x288, 0x289, 
       0x5, 0x28, 0x15, 0x2, 0x289, 0x28a, 0x7, 0x30, 0x2, 0x2, 0x28a, 0x28b, 
       0x5, 0x7a, 0x3e, 0x2, 0x28b, 0x28d, 0x3, 0x2, 0x2, 0x2, 0x28c, 0x27d, 
       0x3, 0x2, 0x2, 0x2, 0x28c, 0x286, 0x3, 0x2, 0x2, 0x2, 0x28d, 0x85, 
       0x3, 0x2, 0x2, 0x2, 0x28e, 0x28f, 0x7, 0x24, 0x2, 0x2, 0x28f, 0x290, 
       0x7, 0x2f, 0x2, 0x2, 0x290, 0x291, 0x5, 0x28, 0x15, 0x2, 0x291, 0x292, 
       0x7, 0x30, 0x2, 0x2, 0x292, 0x293, 0x5, 0x7a, 0x3e, 0x2, 0x293, 0x2a3, 
       0x3, 0x2, 0x2, 0x2, 0x294, 0x295, 0x7, 0xa, 0x2, 0x2, 0x295, 0x296, 
       0x5, 0x7a, 0x3e, 0x2, 0x296, 0x297, 0x7, 0x24, 0x2, 0x2, 0x297, 0x298, 
       0x7, 0x2f, 0x2, 0x2, 0x298, 0x299, 0x5, 0x28, 0x15, 0x2, 0x299, 0x29a, 
       0x7, 0x30, 0x2, 0x2, 0x29a, 0x29b, 0x7, 0x4b, 0x2, 0x2, 0x29b, 0x2a3, 
       0x3, 0x2, 0x2, 0x2, 0x29c, 0x29d, 0x7, 0x10, 0x2, 0x2, 0x29d, 0x29e, 
       0x7, 0x2f, 0x2, 0x2, 0x29e, 0x29f, 0x5, 0x88, 0x45, 0x2, 0x29f, 0x2a0, 
       0x7, 0x30, 0x2, 0x2, 0x2a0, 0x2a1, 0x5, 0x7a, 0x3e, 0x2, 0x2a1, 0x2a3, 
       0x3, 0x2, 0x2, 0x2, 0x2a2, 0x28e, 0x3, 0x2, 0x2, 0x2, 0x2a2, 0x294, 
       0x3, 0x2, 0x2, 0x2, 0x2a2, 0x29c, 0x3, 0x2, 0x2, 0x2, 0x2a3, 0x87, 
       0x3, 0x2, 0x2, 0x2, 0x2a4, 0x2aa, 0x5, 0x2c, 0x17, 0x2, 0x2a5, 0x2a7, 
       0x5, 0x28, 0x15, 0x2, 0x2a6, 0x2a5, 0x3, 0x2, 0x2, 0x2, 0x2a6, 0x2a7, 
       0x3, 0x2, 0x2, 0x2, 0x2a7, 0x2a8, 0x3, 0x2, 0x2, 0x2, 0x2a8, 0x2aa, 
       0x7, 0x4b, 0x2, 0x2, 0x2a9, 0x2a4, 0x3, 0x2, 0x2, 0x2, 0x2a9, 0x2a6, 
       0x3, 0x2, 0x2, 0x2, 0x2aa, 0x2ac, 0x3, 0x2, 0x2, 0x2, 0x2ab, 0x2ad, 
       0x5, 0x8a, 0x46, 0x2, 0x2ac, 0x2ab, 0x3, 0x2, 0x2, 0x2, 0x2ac, 0x2ad, 
       0x3, 0x2, 0x2, 0x2, 0x2ad, 0x2ae, 0x3, 0x2, 0x2, 0x2, 0x2ae, 0x2b0, 
       0x7, 0x4b, 0x2, 0x2, 0x2af, 0x2b1, 0x5, 0x8a, 0x46, 0x2, 0x2b0, 0x2af, 
       0x3, 0x2, 0x2, 0x2, 0x2b0, 0x2b1, 0x3, 0x2, 0x2, 0x2, 0x2b1, 0x89, 
       0x3, 0x2, 0x2, 0x2, 0x2b2, 0x2b7, 0x5, 0x24, 0x13, 0x2, 0x2b3, 0x2b4, 
       0x7, 0x4c, 0x2, 0x2, 0x2b4, 0x2b6, 0x5, 0x24, 0x13, 0x2, 0x2b5, 0x2b3, 
       0x3, 0x2, 0x2, 0x2, 0x2b6, 0x2b9, 0x3, 0x2, 0x2, 0x2, 0x2b7, 0x2b5, 
       0x3, 0x2, 0x2, 0x2, 0x2b7, 0x2b8, 0x3, 0x2, 0x2, 0x2, 0x2b8, 0x8b, 
       0x3, 0x2, 0x2, 0x2, 0x2b9, 0x2b7, 0x3, 0x2, 0x2, 0x2, 0x2ba, 0x2bb, 
       0x7, 0x11, 0x2, 0x2, 0x2bb, 0x2c3, 0x7, 0x5d, 0x2, 0x2, 0x2bc, 0x2c3, 
       0x7, 0x8, 0x2, 0x2, 0x2bd, 0x2c3, 0x7, 0x4, 0x2, 0x2, 0x2be, 0x2c0, 
       0x7, 0x18, 0x2, 0x2, 0x2bf, 0x2c1, 0x5, 0x28, 0x15, 0x2, 0x2c0, 0x2bf, 
       0x3, 0x2, 0x2, 0x2, 0x2c0, 0x2c1, 0x3, 0x2, 0x2, 0x2, 0x2c1, 0x2c3, 
       0x3, 0x2, 0x2, 0x2, 0x2c2, 0x2ba, 0x3, 0x2, 0x2, 0x2, 0x2c2, 0x2bc, 
       0x3, 0x2, 0x2, 0x2, 0x2c2, 0x2bd, 0x3, 0x2, 0x2, 0x2, 0x2c2, 0x2be, 
       0x3, 0x2, 0x2, 0x2, 0x2c3, 0x2c4, 0x3, 0x2, 0x2, 0x2, 0x2c4, 0x2c5, 
       0x7, 0x4b, 0x2, 0x2, 0x2c5, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x2c6, 0x2c8, 
       0x5, 0x90, 0x49, 0x2, 0x2c7, 0x2c6, 0x3, 0x2, 0x2, 0x2, 0x2c7, 0x2c8, 
       0x3, 0x2, 0x2, 0x2, 0x2c8, 0x2c9, 0x3, 0x2, 0x2, 0x2, 0x2c9, 0x2ca, 
       0x7, 0x2, 0x2, 0x3, 0x2ca, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x2cb, 0x2cd, 
       0x5, 0x92, 0x4a, 0x2, 0x2cc, 0x2cb, 0x3, 0x2, 0x2, 0x2, 0x2cd, 0x2ce, 
       0x3, 0x2, 0x2, 0x2, 0x2ce, 0x2cc, 0x3, 0x2, 0x2, 0x2, 0x2ce, 0x2cf, 
       0x3, 0x2, 0x2, 0x2, 0x2cf, 0x91, 0x3, 0x2, 0x2, 0x2, 0x2d0, 0x2d4, 
       0x5, 0x94, 0x4b, 0x2, 0x2d1, 0x2d4, 0x5, 0x2c, 0x17, 0x2, 0x2d2, 
       0x2d4, 0x7, 0x4b, 0x2, 0x2, 0x2d3, 0x2d0, 0x3, 0x2, 0x2, 0x2, 0x2d3, 
       0x2d1, 0x3, 0x2, 0x2, 0x2, 0x2d3, 0x2d2, 0x3, 0x2, 0x2, 0x2, 0x2d4, 
       0x93, 0x3, 0x2, 0x2, 0x2, 0x2d5, 0x2d7, 0x5, 0x2e, 0x18, 0x2, 0x2d6, 
       0x2d5, 0x3, 0x2, 0x2, 0x2, 0x2d6, 0x2d7, 0x3, 0x2, 0x2, 0x2, 0x2d7, 
       0x2d8, 0x3, 0x2, 0x2, 0x2, 0x2d8, 0x2da, 0x5, 0x58, 0x2d, 0x2, 0x2d9, 
       0x2db, 0x5, 0x96, 0x4c, 0x2, 0x2da, 0x2d9, 0x3, 0x2, 0x2, 0x2, 0x2da, 
       0x2db, 0x3, 0x2, 0x2, 0x2, 0x2db, 0x2dc, 0x3, 0x2, 0x2, 0x2, 0x2dc, 
       0x2dd, 0x5, 0x7e, 0x40, 0x2, 0x2dd, 0x95, 0x3, 0x2, 0x2, 0x2, 0x2de, 
       0x2e0, 0x5, 0x2c, 0x17, 0x2, 0x2df, 0x2de, 0x3, 0x2, 0x2, 0x2, 0x2e0, 
       0x2e1, 0x3, 0x2, 0x2, 0x2, 0x2e1, 0x2df, 0x3, 0x2, 0x2, 0x2, 0x2e1, 
       0x2e2, 0x3, 0x2, 0x2, 0x2, 0x2e2, 0x97, 0x3, 0x2, 0x2, 0x2, 0x58, 
       0x9d, 0xa3, 0xac, 0xb0, 0xb8, 0xbe, 0xc0, 0xc8, 0xce, 0xda, 0xe5, 
       0xec, 0xf4, 0xfc, 0x104, 0x10c, 0x114, 0x11c, 0x124, 0x12c, 0x134, 
       0x13d, 0x145, 0x14e, 0x155, 0x15a, 0x15d, 0x164, 0x16d, 0x173, 0x17f, 
       0x188, 0x18f, 0x193, 0x198, 0x19d, 0x1a4, 0x1a9, 0x1ad, 0x1b1, 0x1b6, 
       0x1bc, 0x1c3, 0x1c9, 0x1d7, 0x1e1, 0x1e4, 0x1e6, 0x1ec, 0x1f3, 0x1fb, 
       0x1fd, 0x204, 0x209, 0x210, 0x21b, 0x21e, 0x226, 0x22a, 0x22d, 0x232, 
       0x237, 0x240, 0x248, 0x251, 0x25c, 0x269, 0x26f, 0x276, 0x279, 0x284, 
       0x28c, 0x2a2, 0x2a6, 0x2a9, 0x2ac, 0x2b0, 0x2b7, 0x2c0, 0x2c2, 0x2c7, 
       0x2ce, 0x2d3, 0x2d6, 0x2da, 0x2e1, 
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
