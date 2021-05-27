//
// Created by ybc on 2021/5/27.
//

#include "CodeGenVisitor.h"
// TODO: more value type
using ExpType = int;
using Word = uint32_t;

antlrcpp::Any CodeGenVisitor::visitAssignmentExpression(CParser::AssignmentExpressionContext *ctx) {
    if (auto condExp = ctx->conditionalExpression()) {
        return visit(condExp).as<ExpType>();
    } else if (auto ds = ctx->DigitSequence()) {
        auto num = atoi(ds->getText().c_str());
        std::cout << "num:" << num << std::endl;
        return num; // int
    } else // assignment
    {
        //TODO: more assignment operator

        // gen code for lhs = rhs
        // rhs: addr of value, should be register (or addr of memory, we assume unlimited register here)
        // sw val(rhs), addr(lhs)
        return ctx->assignmentExpression();
    }
}

antlrcpp::Any CodeGenVisitor::visitConditionalExpression(CParser::ConditionalExpressionContext *ctx) {
    auto logicOrExp = ctx->logicalOrExpression();
    if (visit(logicOrExp).as<ExpType>() == true) {
        return visit(ctx->expression());
    } else {
        return visit(ctx->conditionalExpression());
    }
}

antlrcpp::Any CodeGenVisitor::visitLogicalOrExpression(CParser::LogicalOrExpressionContext *ctx) {
    auto logicAndExps = ctx->logicalAndExpression();
    bool condTest = false;
    for (auto &logicAndExp : logicAndExps) {
        condTest = visit(logicAndExp).as<ExpType>();
        if (condTest) break;
    }
    return condTest;
}

antlrcpp::Any CodeGenVisitor::visitLogicalAndExpression(CParser::LogicalAndExpressionContext *ctx) {
    auto incOrExps = ctx->inclusiveOrExpression();
    bool condTest = false;
    for (auto &incOrExp : incOrExps) {
        condTest = visit(incOrExp).as<ExpType>();
        if (condTest) continue;
    }
    return condTest;
}

antlrcpp::Any CodeGenVisitor::visitInclusiveOrExpression(CParser::InclusiveOrExpressionContext *ctx) {
    auto excOrExps = ctx->exclusiveOrExpression();
    Word result = 0;
    for (auto &excOrExp : excOrExps) {
        result |= visit(excOrExp).as<Word>(); // should be unsigned int type
    }
    return result;
}

antlrcpp::Any CodeGenVisitor::visitExclusiveOrExpression(CParser::ExclusiveOrExpressionContext *ctx) {
    auto andExps = ctx->andExpression();
    Word result = 0;
    for (auto &andExp : andExps) {
        result ^= visit(andExp).as<Word>(); // should be unsigned int type
    }
    return result;
}

antlrcpp::Any CodeGenVisitor::visitAndExpression(CParser::AndExpressionContext *ctx) {
    auto equExps = ctx->equalityExpression();
    Word result = 0;
    for (auto &equExp : equExps) {
        result &= visit(equExp).as<Word>(); // should be unsigned int type
    }
    return result;
}

antlrcpp::Any CodeGenVisitor::visitEqualityExpression(CParser::EqualityExpressionContext *ctx) {
    auto relExps = ctx->relationalExpression();
    auto eqOps = ctx->equalityOperator();
    bool result = visit(relExps[0]).as<ExpType>();
    for (int i = 0; i < relExps.size(); i++) {
        if (eqOps[i]->Equal()) {
            result = (result == visit(relExps[i + 1]).as<ExpType>());
        } else if (eqOps[i]->NotEqual()) {
            result = (result != visit(relExps[i + 1]).as<ExpType>());
        } else {
            abort();
        }
    }
    return result;
}

antlrcpp::Any CodeGenVisitor::visitRelationalExpression(CParser::RelationalExpressionContext *ctx) {
    auto shiExps = ctx->shiftExpression();
    auto relOps = ctx->relationalOperator();
    bool result = visit(shiExps[0]).as<ExpType>();
    for (int i = 0; i < shiExps.size(); i++) {
        if (relOps[i]->Less()) {
            result = (result > visit(shiExps[i + 1]).as<ExpType>());
        } else if (relOps[i]->Greater()) {
            result = (result < visit(shiExps[i + 1]).as<ExpType>());
        } else if (relOps[i]->LessEqual()) {
            result = (result <= visit(shiExps[i + 1]).as<ExpType>());
        } else if (relOps[i]->GreaterEqual()) {
            result = (result >= visit(shiExps[i + 1]).as<ExpType>());
        } else {
            abort();
        }
    }
    return result;
}

antlrcpp::Any CodeGenVisitor::visitShiftExpression(CParser::ShiftExpressionContext *ctx) {
    auto addExps = ctx->additiveExpression();
    auto shiOps = ctx->shiftOperator();
    Word result = visit(addExps[0]).as<Word>();
    for (int i = 0; i < addExps.size(); i++) {
        if (shiOps[i]->LeftShift()) {
            result = (result << visit(addExps[i + 1]).as<Word>()); // should be unsigned int type
        } else if (shiOps[i]->RightShift()) {
            result = (result >> visit(addExps[i + 1]).as<Word>()); // should be unsigned int type
        } else {
            abort();
        }
    }
    return result;
}

antlrcpp::Any CodeGenVisitor::visitAdditiveExpression(CParser::AdditiveExpressionContext *ctx) {
    auto mulExps = ctx->multiplicativeExpression();
    auto addOps = ctx->additiveOperator();
    bool result = visit(mulExps[0]).as<ExpType>();
    for (int i = 0; i < mulExps.size(); i++) {
        if (addOps[i]->Plus()) {
            result = (result + visit(mulExps[i + 1]).as<ExpType>());
        } else if (addOps[i]->Minus()) {
            result = (result - visit(mulExps[i + 1]).as<ExpType>());
        } else {
            abort();
        }
    }
    return result;
}

antlrcpp::Any CodeGenVisitor::visitMultiplicativeExpression(CParser::MultiplicativeExpressionContext *ctx) {
    auto castExps = ctx->castExpression();
    auto mulOps = ctx->multiplicativeOperator();
    ExpType result = visit(castExps[0]).as<ExpType>();
    for (int i = 0; i < castExps.size(); i++) {
        if (mulOps[i]->Star()) {
            result = (result * visit(castExps[i + 1]).as<ExpType>());
        } else if (mulOps[i]->Div()) {
            result = (result / visit(castExps[i + 1]).as<ExpType>());
        } else if (mulOps[i]->Mod()) {
            result = (result % visit(castExps[i + 1]).as<Word>()); // should be unsigned int type
        } else {
            abort();
        }
    }
    return result;
}

antlrcpp::Any CodeGenVisitor::visitCastExpression(CParser::CastExpressionContext *ctx) {
    if (auto unaExp = ctx->unaryExpression()) {
        return visit(unaExp);
    } else if (auto digSeq = ctx->DigitSequence()) {
        auto num = atoi(digSeq->getText().c_str());
        return num; // int
    }
    abort();
}

antlrcpp::Any CodeGenVisitor::visitUnaryExpression(CParser::UnaryExpressionContext *ctx) {
    auto preOps = ctx->prefixOperator();
    ExpType result = 0;
    if (auto posExp = ctx->postfixExpression()) {
        result = visit(posExp).as<ExpType>();
    } else if (ctx->unaryOperator()->And()) {
        // get the address
//            result = &(visit(ctx->castExpression()).as<Word>());
    } else if (ctx->unaryOperator()->Star()) {
        // dereference
    } else if (ctx->unaryOperator()->Plus()) {
        result = +visit(ctx->castExpression()).as<ExpType>();
    } else if (ctx->unaryOperator()->Minus()) {
        result = -visit(ctx->castExpression()).as<ExpType>();
    } else if (ctx->unaryOperator()->Tilde()) {
        result = ~visit(ctx->castExpression()).as<Word>();
    } else if (ctx->unaryOperator()->Not()) {
        result = !visit(ctx->castExpression()).as<Word>();
    }

    //TODO: get prefix value
    return result;
}

antlrcpp::Any CodeGenVisitor::visitPostfixExpression(CParser::PostfixExpressionContext *ctx) {
    //TODO: postfix expression
    auto priExp = ctx->primaryExpression();
    return visit(priExp);
}

antlrcpp::Any CodeGenVisitor::visitPrimaryExpression(CParser::PrimaryExpressionContext *ctx) {
    if (auto exp = ctx->expression()) {
        return visit(exp);
    } else if (auto id = ctx->Identifier()) {
//        return value(id);
    } else if (auto c = ctx->constant()) {
        if (c->CharacterConstant()) {
            //TODO:encode
            return c->getText()[0];
        } else if (c->IntegerConstant()) {
            //TODO:encode
            return atoi(c->getText().c_str());
        } else if (c->FloatingConstant()) {
            return atoi(c->getText().c_str());
        }
    } else {
        auto s = ctx->StringLiteral();
    }
}

