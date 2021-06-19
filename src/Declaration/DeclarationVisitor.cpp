//
// Created by 44190 on 5/26/2021.
//

#include "DeclarationVisitor.h"

#include <memory>

antlrcpp::Any DeclarationVisitor::visitCompilationUnit(CParser::CompilationUnitContext *ctx) {
    auto result = visitChildren(ctx);
    SymTab::getInstance().align();
    return result;
}

antlrcpp::Any DeclarationVisitor::visitIdentifier(CParser::IdentifierContext *ctx) {
    auto symbol = getCompoundContext() + ctx->Identifier()->getText();
    auto entry = SymTab::getInstance().get(symbol, ctx->getStart()->getLine(),
                                           ctx->getStart()->getCharPositionInLine());
    auto isTypedef = entry.type.isTypedef();
    return RetType(entry.type.getTypeTree(), !isTypedef, isTypedef);
}

antlrcpp::Any DeclarationVisitor::visitIntConst(CParser::IntConstContext *ctx) {
    SimpleTypePtr type = make_shared<SimpleTypeNode>(SimpleTypeNode(BaseType::SInt));
    auto ptr = static_pointer_cast<CTypeNodeBase>(type);
    return RetType(ptr);
}

antlrcpp::Any DeclarationVisitor::visitCharConst(CParser::CharConstContext *ctx) {
    SimpleTypePtr type = make_shared<SimpleTypeNode>(SimpleTypeNode(BaseType::SChar));
    auto ptr = static_pointer_cast<CTypeNodeBase>(type);
    return RetType(ptr);
}

antlrcpp::Any DeclarationVisitor::visitStrConst(CParser::StrConstContext *ctx) {
    auto rawText = ctx->getText();
    ArrayTypePtr type = make_shared<ArrayTypeNode>(ArrayTypeNode(CTypeBasePtr(
            new SimpleTypeNode(BaseType::SChar)), 0));
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
        if (declarator.initValue) {
            RetType initValueType = visit(declarator.initValue).as<RetType>();
            if (initValueType.isTypeDef) {
                throw InvalidExpression(declarator.initValue->getText());
            }
            if (!typeTree->typeCheck(initValueType.type)) {
                if (typeTree->getNodeType() == BaseType::Pointer &&
                    initValueType.type->getNodeType() == BaseType::Pointer) {
                    throw IncompatibleType("different kind of pointer -- " + ctx->getText());
                } else
                    throw IncompatibleType(getTypeStr(typeTree->getNodeType()) + " and "
                                           + getTypeStr(initValueType.type->getNodeType()) + " -- " + ctx->getText());
            }
        }
        SymTab::getInstance().add(symbol, CType(typeTree, bool(type.isTypedef())), line, column, declarator.initValue,
                                  false, typeTree->getNodeType() == BaseType::Array);
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
        initValue = ctx->initializer();
    }
    auto declarator = ctx->declarator();
    auto pointers = declarator->pointer();
    auto arrays = declarator->array();
    vector<size_t> arraySizes;
    arraySizes.reserve(arrays.size());
    for (auto array:arrays) {
        int size = atoi(array->IntegerConstant()->getText().c_str());
        if (size <= 0) {
            throw InvalidArraySize(to_string(size));
        }
        arraySizes.push_back(size);
    }
    return InitDeclarator(declarator->directDeclarator()->identifier()->getText(),
                          pointers.size(), arraySizes, initValue);
}

antlrcpp::Any DeclarationVisitor::visitInitializer(CParser::InitializerContext *ctx) {
    return visit(ctx->assignmentExpression());
}

antlrcpp::Any DeclarationVisitor::visitTypeName(CParser::TypeNameContext *ctx) {
    TypeSpecifiers typeSpecifiers;
    if (auto id = ctx->identifier()) { //
        auto entry = SymTab::getInstance().get(id->getText());
        if (entry.type.isTypedef()) {
            return CTypeBasePtr(entry.type.getTypeTree());
        } else {
            throw UnknownTypeName(id->getText());
        }
    } else {
        for (auto &specifier  : ctx->declarationSpecifier()) {
            // type specifier
            auto typeSpecifier = specifier->typeSpecifier();
            if (auto s = typeSpecifier->simpleTypeSpecifier()) {
                // simple type specifier
                typeSpecifiers.push_back(visit(s).as<TypeSpecifier>());
            }
        }
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
    // collect parameters information
    vector<CTypeBasePtr> paramTypes{};
    if (auto paramTypeList = ctx->parameterTypeList()) {
        if (auto paramList = paramTypeList->parameterList()) {
            paramTypes = visit(paramList).as<vector<CTypeBasePtr>>();
        }
    }
    // create a function type, add it to the symbol table
    auto funcType = CType(static_cast<CTypeBasePtr>(new FunctionTypeNode(returnType.getTypeTree(), paramTypes)));
    SymTab::getInstance().add(name, funcType, ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine());
    SymTab::getInstance().get(name, ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine());
    // visit function body
    visit(ctx->compoundStatement());
    blockOrderStack.clear();
    blockOrder = 0;
    curFunc = "";
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
    auto declarator = ctx->declarator();
    auto name = visit(declarator).as<string>();
    auto symbol = getCompoundContext() + "0@" + name; // params are in the same scope of func body
    if (!declarator->array().empty())
        throw NotImplement("use array as function parameter");

    for (int i = 0; i < declarator->pointer().size(); i++) {
        type = static_pointer_cast<CTypeNodeBase>(getPointerType(type));
    }
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

        if (lType.isTypeDef || rType.isTypeDef)
            throw InvalidExpression(ctx->getText());

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
        if (rType.isTypeDef)
            throw InvalidExpression(ctx->getText());
        if (op->Minus() || op->Not() || op->Tilde() || op->Plus()) {
            return RetType(CTypeBasePtr(rType.type));
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
        if (arrayEntry.type.isTypedef())
            throw InvalidExpression(ctx->getText());
        auto resultType = arrayEntry.type.getTypeTree();
        for (auto exp : exps) {
            if (visit(exp).as<RetType>().type->getNodeType() != BaseType::SInt) { // index should be int
                throw InvalidArraySize(exp->getText());
            }
            if (resultType->getNodeType() == BaseType::Array || resultType->getNodeType() == BaseType::Pointer)
                resultType = resultType->getChild();
            else {// to many brackets
                throw InvalidArrayList(ctx->getText());
            }
        }
        if (resultType->getNodeType() != BaseType::Array) // it's left value only when it gets the base type of array
            return RetType(resultType, true);
        else
            return RetType(resultType, false);
    } else if (!ctx->LeftParen().empty()) {
        auto argExpList = ctx->argumentExpressionList();
        if (auto id = ctx->primaryExpression()->identifier()) {
            auto funcName = id->getText();
            auto funcEntry = SymTab::getInstance().get(funcName);
            if (funcEntry.type.isTypedef())
                throw InvalidExpression(ctx->getText());
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
                            throw IncompatibleType(
                                    "unmatched parameter list: different kind of pointer -- " + ctx->getText());
                        } else
                            throw IncompatibleType(
                                    "unmatched parameter list: " + getTypeStr(lType->getNodeType()) + " and "
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
        if (lType.isTypeDef)
            throw InvalidExpression(ctx->expression()->getText());
        else if (rType.isTypeDef)
            throw InvalidExpression(ctx->conditionalExpression()->getText());
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

antlrcpp::Any DeclarationVisitor::visitAdditiveExpression(CParser::AdditiveExpressionContext *ctx) {
    auto exps = ctx->multiplicativeExpression();
    auto ops = ctx->additiveOperator();
    auto retType = visit(exps[0]).as<RetType>();
    if (retType.isTypeDef) {
        throw InvalidExpression(ctx->getText());
    }
    CTypeBasePtr firstType = retType.type;
    CTypeBasePtr secondType{};
    if (!ops.empty()) {
        SymTab::getInstance().saveTypeToQueue(firstType);
        for (int i = 0; i < ops.size(); i++) {
            retType = visit(exps[i + 1]).as<RetType>();
            if (retType.isTypeDef) {
                throw InvalidExpression(ctx->getText());
            }
            secondType = retType.type;

            firstType = getRetType(firstType, secondType,
                                   dynamic_cast<tree::TerminalNode *>(ops[i]->children.front())->getSymbol()->getType());
            SymTab::getInstance().saveTypeToQueue(secondType);
        }
    }
    return RetType(firstType);
}

antlrcpp::Any DeclarationVisitor::visitCastExpression(CParser::CastExpressionContext *ctx) {
    if (auto uExp = ctx->unaryExpression())
        return visit(uExp);
    else {
        auto pointers = ctx->pointer();
        auto dst = visit(ctx->typeName()).as<CTypeBasePtr>();
        RetType src = visit(ctx->castExpression()).as<RetType>();
        if (src.isTypeDef)
            throw InvalidExpression(ctx->castExpression()->getText());
        for (int i = 0; i < pointers.size(); i++) {
            dst = static_pointer_cast<CTypeNodeBase>(getPointerType(dst));
        }
        return RetType(src.type->typeCast(dst));
    }
}

antlrcpp::Any DeclarationVisitor::visitReturnStmt(CParser::ReturnStmtContext *ctx) {
    auto returnType = SymTab::getInstance().get(curFunc).type.getTypeTree()->getChild();
    RetType lType = RetType(returnType);
    RetType rType = visit(ctx->expression()).as<RetType>();
    if (rType.isTypeDef)
        throw InvalidExpression(ctx->getText());
    if (!lType.type->typeCheck(rType.type)) {
        if (lType.type->getNodeType() == BaseType::Pointer && rType.type->getNodeType() == BaseType::Pointer) {
            throw IncompatibleType("different kind of pointer -- " + ctx->getText());
        } else
            throw IncompatibleType(getTypeStr(lType.type->getNodeType()) + " and "
                                   + getTypeStr(rType.type->getNodeType()) + " -- " + ctx->getText());
    }
    return RetType(NoneTypePtr());
}
