//
// Created by 44190 on 5/26/2021.
//

#include "DeclarationVisitor.h"

#include <memory>

antlrcpp::Any DeclarationVisitor::visitIdentifier(CParser::IdentifierContext *ctx) {
    auto symbol = getCompoundContext() + ctx->Identifier()->getText();
    auto line = ctx->getStart()->getLine();
    auto column = ctx->getStart()->getCharPositionInLine();
    return RetType(SymTab::getInstance().get(symbol, line, column).type.getTypeTree(), true);
}

antlrcpp::Any DeclarationVisitor::visitConstant(CParser::ConstantContext *ctx) {
    SimpleTypePtr type = make_shared<SimpleTypeNode>(SimpleTypeNode(BaseType::SInt));
    auto ptr = static_pointer_cast<CTypeNodeBase>(type);
    return RetType(ptr);
}

antlrcpp::Any DeclarationVisitor::visitDeclaration(CParser::DeclarationContext *ctx) {
    auto line = ctx->getStart()->getLine();
    auto column = ctx->getStart()->getCharPositionInLine();
    auto type = visit(ctx->declarationSpecifiers()).as<CType>();
    auto declarators = visit(ctx->initDeclaratorList()).as<InitDeclarators>();
    auto compoundCtx = getCompoundContext();
    for (auto &declarator : declarators) {
        auto symbol = compoundCtx + declarator.name;
        auto typeTree = type.getTypeTree();
        for (int i = (int) declarator.arraySizes.size() - 1; i >= 0; i--) {
            typeTree = static_pointer_cast<CTypeNodeBase>(getArrayType(typeTree, declarator.arraySizes[i]));
        }
        for (int i = 0; i < declarator.pointerNum; i++) {
            typeTree = static_pointer_cast<CTypeNodeBase>(getPointerType(typeTree));
        }
        SymTab::getInstance().add(symbol, CType(typeTree, bool(type.isTypedef())), line, column, declarator.initValue);
        SymTab::getInstance().get(compoundCtx + declarator.name, line, column);
    }
    return RetType(NoneTypePtr());
}

antlrcpp::Any DeclarationVisitor::visitDeclarationSpecifiers(CParser::DeclarationSpecifiersContext *ctx) {
    auto typeNode = visit(ctx->typeName()).as<CTypeBasePtr>();
    CType type(typeNode, bool(ctx->typedefSpecifier()));
    return type;
}

antlrcpp::Any DeclarationVisitor::visitInitDeclaratorList(CParser::InitDeclaratorListContext *ctx) {
    InitDeclarators s;
    for (auto &initDeclarator : ctx->initDeclarator()) {
        s.push_back(visit(initDeclarator).as<InitDeclarator>());
    }
    return s;
}

antlrcpp::Any DeclarationVisitor::visitInitDeclarator(CParser::InitDeclaratorContext *ctx) {
    auto initValue = InitValuePtr();
    if (auto i = ctx->initializer()) {
        initValue = visit(i).as<InitValuePtr>();
    }
    auto declarator = ctx->declarator();
    auto pointers = declarator->pointer();
    auto arrays = declarator->array();
    vector<size_t> arraySizes;
    arraySizes.reserve(arrays.size());
    for (auto array:arrays) {
        int size = atoi(array->IntegerConstant()->getText().c_str());
        if (size < 0) {
            throw InvalidArraySize(to_string(size));
        }
        arraySizes.push_back(size);
    }
    return InitDeclarator(declarator->directDeclarator()->identifier()->getText(),
                          pointers.size(), arraySizes, initValue);
}

antlrcpp::Any DeclarationVisitor::visitInitializer(CParser::InitializerContext *ctx) {
    return (InitValuePtr) ctx;
}

antlrcpp::Any DeclarationVisitor::visitTypeName(CParser::TypeNameContext *ctx) {
    TypeSpecifiers typeSpecifiers;
    for (auto &specifier  : ctx->declarationSpecifier()) {
        // TODO: another specifiers
        // type specifier
        auto typeSpecifier = specifier->typeSpecifier();
        if (auto s = typeSpecifier->simpleTypeSpecifier()) {
            // simple type specifier
            typeSpecifiers.push_back(visit(s).as<TypeSpecifier>());
        }
        // TODO: compound type
    }

    // simple type
    auto type = CTypeBasePtr(new SimpleTypeNode(getBaseType(typeSpecifiers)));
    return type;
}

antlrcpp::Any DeclarationVisitor::visitSimpleTypeSpecifier(CParser::SimpleTypeSpecifierContext *ctx) {
    return static_cast<TypeSpecifier>(dynamic_cast<tree::TerminalNode *>(ctx->children.front())->getSymbol()->getType());
}

antlrcpp::Any DeclarationVisitor::visitTypeSpecifier(CParser::TypeSpecifierContext *ctx) {
    return static_cast<TypeSpecifier>(dynamic_cast<tree::TerminalNode *>(ctx->children.front())->getSymbol()->getType());
}

antlrcpp::Any DeclarationVisitor::visitFunctionDefinition(CParser::FunctionDefinitionContext *ctx) {
    auto returnType = visit(ctx->declarationSpecifiers()).as<CType>();
    auto name = visit(ctx->declarator()).as<string>();
    curFunc = name;
    vector<CTypeBasePtr> paramTypes{};
    if (auto paramTypeList = ctx->parameterTypeList()) {
        if (auto paramList = paramTypeList->parameterList()) {
            paramTypes = visit(paramList).as<vector<CTypeBasePtr>>();
        }
    }
    auto funcType = CType(static_cast<CTypeBasePtr>(new FunctionTypeNode(returnType, paramTypes)));
    SymTab::getInstance().add(name, funcType, ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine());
    SymTab::getInstance().get(name, ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine());
    visit(ctx->compoundStatement());
    blockOrderStack.clear();
    blockOrder = 0;
    return RetType(NoneTypePtr());
}

antlrcpp::Any DeclarationVisitor::visitParameterList(CParser::ParameterListContext *ctx) {
    auto paramDeclarations = ctx->parameterDeclaration();
    vector<CTypeBasePtr> paramTypes{};
    for (auto paramDeclaration : paramDeclarations) {
        auto paramType = visit(paramDeclaration).as<CTypeBasePtr>();
        paramTypes.push_back(paramType);
    }
    return paramTypes;
}

antlrcpp::Any DeclarationVisitor::visitParameterDeclaration(CParser::ParameterDeclarationContext *ctx) {
    auto line = ctx->getStart()->getLine();
    auto column = ctx->getStart()->getCharPositionInLine();
    auto type = visit(ctx->typeName()).as<CTypeBasePtr>();
    auto name = visit(ctx->declarator()).as<string>();
    auto symbol = getCompoundContext() + "0@" + name; // params are in the same scope of func body
    SymTab::getInstance().add(symbol, CType(type), line, column, nullptr, true);
    SymTab::getInstance().get(symbol, line, column);
    return type;
}

antlrcpp::Any DeclarationVisitor::visitDeclarator(CParser::DeclaratorContext *ctx) {
    return ctx->directDeclarator()->identifier()->getText();
}

antlrcpp::Any DeclarationVisitor::visitDirectDeclarator(CParser::DirectDeclaratorContext *ctx) {
    return ctx->identifier()->getText();
}

antlrcpp::Any DeclarationVisitor::visitGeneralizedCompoundStatement(CParser::BlockContext::ParseTree *ctx) {
    blockOrderStack.push_back(blockOrder);
    blockOrder = 0;
    auto res = visitChildren(ctx);
    blockOrder = blockOrderStack.back() + 1;
    blockOrderStack.pop_back();
    return res;
}

antlrcpp::Any DeclarationVisitor::visitCompoundStatement(CParser::CompoundStatementContext *ctx) {
    return visitGeneralizedCompoundStatement(ctx);
}

antlrcpp::Any DeclarationVisitor::visitWhileLoop(CParser::WhileLoopContext *ctx) {
    return visitGeneralizedCompoundStatement(ctx);
}

antlrcpp::Any DeclarationVisitor::visitDoWhile(CParser::DoWhileContext *ctx) {
    return visitGeneralizedCompoundStatement(ctx);
}

antlrcpp::Any DeclarationVisitor::visitForLoop(CParser::ForLoopContext *ctx) {
    return visitGeneralizedCompoundStatement(ctx);
}

antlrcpp::Any DeclarationVisitor::visitBlockItem(CParser::BlockItemContext *ctx) {
    return visitChildren(ctx);
}

antlrcpp::Any DeclarationVisitor::visitAssignmentExpression(CParser::AssignmentExpressionContext *ctx) {
    if (auto condExp = ctx->conditionalExpression()) {
        return visit(condExp);
    } else {
        RetType lType = visit(ctx->unaryExpression()).as<RetType>();
        RetType rType = visit(ctx->assignmentExpression()).as<RetType>();
        if (!lType.type->typeCheck(rType.type)) {
            if (lType.type->getNodeType() == BaseType::Pointer && rType.type->getNodeType() == BaseType::Pointer) {
                throw IncompatibleType("different kind of pointer -- " + ctx->getText());
            } else
                throw IncompatibleType(getTypeStr(lType.type->getNodeType()) + " and "
                                       + getTypeStr(rType.type->getNodeType()) + " -- " + ctx->getText());
        }
        if (!lType.isLeftValue) {
            throw InvalidLvalue(ctx->unaryExpression()->getText());
        }
        return RetType(lType.type, true);
    }
}

antlrcpp::Any DeclarationVisitor::visitUnaryExpression(CParser::UnaryExpressionContext *ctx) {
    if (auto postExp = ctx->postfixExpression()) {
        return visit(postExp);
    } else {
        auto uExp = ctx->unaryExpression();
        auto op = ctx->unaryOperator();
        auto rType = visit(uExp).as<RetType>();
        if (op->Minus()) {      // -x
            if (rType.type->getNodeType() == BaseType::SInt) {
                // TODO: capable of arithmetic type
                return RetType(CTypeBasePtr(rType.type));
            }
        } else if (op->Not()) { // !x, 0->1, non-0 ->0
            if (rType.type->getNodeType() == BaseType::SInt) {
                // TODO: cast to bool
                return RetType(CTypeBasePtr(rType.type));
            }
        } else if (op->Tilde()) {// ~x, bit-wise not x
            if (rType.type->getNodeType() == BaseType::SInt) {
                // TODO: capable of int type
                return RetType(CTypeBasePtr(rType.type));
            }
        } else if (op->Plus()) {// +x, x
            if (rType.type->getNodeType() == BaseType::SInt) {
                // TODO: int promotion
                return RetType(CTypeBasePtr(rType.type));
            }
        } else if (op->Star()) {// *x, get value of a pointer
            if (rType.type->getNodeType() == BaseType::Pointer) {
                return RetType(CTypeBasePtr(rType.type->getChild()), true);
            } else
                throw InvalidDereference(uExp->getText());
        } else if (op->And()) {// &x, get address of a left value
            if (rType.isLeftValue) {
                auto valueType = static_pointer_cast<CTypeNodeBase>(getPointerType(rType.type));
                return RetType(valueType);
            } else
                throw InvalidLvalue(uExp->getText());
        }
        assert(false);
    }
}

antlrcpp::Any DeclarationVisitor::visitPostfixExpression(CParser::PostfixExpressionContext *ctx) {
    if (!ctx->LeftBracket().empty()) {  // array
        auto exps = ctx->expression();
        auto id = ctx->primaryExpression()->identifier();
        auto arrayEntry = SymTab::getInstance().get(getCompoundContext() + id->getText());
        auto resultType = arrayEntry.type.getTypeTree();
        for (auto exp : exps) {
            if (visit(exp).as<RetType>().type->getNodeType() != BaseType::SInt) {
                throw InvalidArraySize(exp->getText());
            }
            if (resultType->getNodeType() == BaseType::Array)
                resultType = resultType->getChild();
            else {
                throw InvalidArrayList(ctx->getText());
            }
        }
        if (resultType->getNodeType() != BaseType::Array)
            return RetType(resultType, true);
        else
            return RetType(resultType, false);
    } else if (!ctx->LeftParen().empty()) { // TODO: continuous postfix f()()[]
        auto argExpList = ctx->argumentExpressionList();
        if (auto id = ctx->primaryExpression()->identifier()) { // TODO: call func by func ptr
            auto funcName = id->getText();
            auto funcEntry = SymTab::getInstance().get(funcName);
            auto typeTree = funcEntry.type.getTypeTree();
            if (typeTree->getNodeType() != BaseType::Function) {
                throw InvalidFuncCall(funcName + " is not callable");
            }
            auto funcType = dynamic_pointer_cast<FunctionTypeNode>(typeTree);

            if (!argExpList.empty()) {
                auto exps = argExpList[0]->assignmentExpression();
                if (exps.size() != funcType->getParamList().size())
                    throw InvalidFuncCall("unmatched parameter number");

                for (int i = 0; i < exps.size(); i++) {
                    auto lType = funcType->getParamList()[i];
                    RetType rType = visit(exps[i]).as<RetType>();
                    if (!lType->typeCheck(rType.type)) {
                        if (lType->getNodeType() == BaseType::Pointer &&
                            rType.type->getNodeType() == BaseType::Pointer) {
                            throw IncompatibleType("different kind of pointer -- " + ctx->getText());
                        } else
                            throw IncompatibleType(getTypeStr(lType->getNodeType()) + " and "
                                                   + getTypeStr(rType.type->getNodeType()) + " -- " + ctx->getText());
                    }
                }
            } else if (!funcType->getParamList().empty())
                throw InvalidFuncCall("unmatched parameter number");

            return RetType(funcType->getChild());
        } else
            throw NotImplement("please call function by the name");
    } else { // not func call
        return visit(ctx->primaryExpression());
    }
}

antlrcpp::Any DeclarationVisitor::visitPrimaryExpression(CParser::PrimaryExpressionContext *ctx) {
    if (auto exp = ctx->expression())
        return visit(exp);
    else if (auto id = ctx->identifier())
        return visit(id);
    else if (auto constant = ctx->constant())
        return visit(constant);
    else
        throw NotImplement(ctx->getText());
}

antlrcpp::Any DeclarationVisitor::visitConditionalExpression(CParser::ConditionalExpressionContext *ctx) {
    if (ctx->Question()) {
        RetType lType = visit(ctx->expression()).as<RetType>();
        RetType rType = visit(ctx->conditionalExpression()).as<RetType>();
        if (!lType.type->typeCheck(rType.type)) { // should be the same
            throw IncompatibleType("subexpression of conditional expression is not the same: "
                                   + getTypeStr(lType.type->getNodeType()) + " and "
                                   + getTypeStr(rType.type->getNodeType()));
        }
        return RetType(lType.type, true);
    } else {
        return visit(ctx->logicalOrExpression());
    }
}