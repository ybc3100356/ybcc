//
// Created by 44190 on 5/26/2021.
//

#include "DeclarationVisitor.h"

#include <memory>

antlrcpp::Any DeclarationVisitor::visitIdentifier(CParser::IdentifierContext *ctx) {
    return SymTab::getInstance().get(getCompoundContext() + ctx->Identifier()->getText(),
                                     ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine());
}

antlrcpp::Any DeclarationVisitor::visitDeclaration(CParser::DeclarationContext *ctx) {
    auto line = ctx->getStart()->getLine();
    auto column = ctx->getStart()->getCharPositionInLine();
    auto type = visit(ctx->declarationSpecifiers()).as<CType>();
    auto declarators = visit(ctx->initDeclaratorList()).as<InitDeclarators>();
    for (auto &declarator : declarators) {
        auto symbol = getCompoundContext() + declarator.first;
        SymTab::getInstance().add(symbol, type, line, column, declarator.second);
        SymTab::getInstance().get(getCompoundContext() + declarator.first, line, column);
    }
    return nullptr;
}

antlrcpp::Any DeclarationVisitor::visitDeclarationSpecifiers(CParser::DeclarationSpecifiersContext *ctx) {
    auto typeNode = visit(ctx->declarationSpecifierList()).as<CTypeNodePtr>();
    CType type(typeNode, bool(ctx->typedefSpecifier()));
    return type;
}

antlrcpp::Any DeclarationVisitor::visitDeclarationSpecifierList(CParser::DeclarationSpecifierListContext *ctx) {
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
    auto type = CTypeNodePtr(new SimpleTypeNode(getBaseType(typeSpecifiers)));
    return type;
}

antlrcpp::Any DeclarationVisitor::visitSimpleTypeSpecifier(CParser::SimpleTypeSpecifierContext *ctx) {
    return static_cast<TypeSpecifier>(dynamic_cast<tree::TerminalNode *>(ctx->children.front())->getSymbol()->getType());
}

antlrcpp::Any DeclarationVisitor::visitInitDeclaratorList(CParser::InitDeclaratorListContext *ctx) {
    InitDeclarators s;
    for (auto &initD : ctx->initDeclarator()) {
        s.push_back(visit(initD).as<InitDeclarator>());
    }
    return s;
}

antlrcpp::Any DeclarationVisitor::visitInitDeclarator(CParser::InitDeclaratorContext *ctx) {

    if (auto i = ctx->initializer()) {
        return std::make_pair(ctx->declarator()->directDeclarator()->identifier()->getText(),
                              visit(i).as<InitValueType *>());
    } else {
        return std::make_pair(ctx->declarator()->directDeclarator()->identifier()->getText(),
                              (InitValueType *) nullptr);
    }
}

antlrcpp::Any DeclarationVisitor::visitInitializer(CParser::InitializerContext *ctx) {
    return ctx;
}

antlrcpp::Any DeclarationVisitor::visitTypeSpecifier(CParser::TypeSpecifierContext *ctx) {
    return static_cast<TypeSpecifier>(dynamic_cast<tree::TerminalNode *>(ctx->children.front())->getSymbol()->getType());
}

antlrcpp::Any DeclarationVisitor::visitFunctionDefinition(CParser::FunctionDefinitionContext *ctx) {
    auto returnType = visit(ctx->declarationSpecifiers()).as<CType>();
    auto name = visit(ctx->declarator()).as<string>();
//    auto paramList = visit(ctx->parameterTypeList());
    auto funcType = CType(static_cast<CTypeNodePtr>(new FunctionTypeNode(returnType)));
    SymTab::getInstance().add(name, funcType, ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine());
    curFunc = name;
    visit(ctx->compoundStatement());
    return nullptr;
}

antlrcpp::Any DeclarationVisitor::visitDeclarator(CParser::DeclaratorContext *ctx) {
    return ctx->directDeclarator()->identifier()->getText();
}

antlrcpp::Any DeclarationVisitor::visitDirectDeclarator(CParser::DirectDeclaratorContext *ctx) {
    return ctx->identifier()->getText();
}

antlrcpp::Any DeclarationVisitor::visitCompoundStatement(CParser::CompoundStatementContext *ctx) {
    blockOrderStack.push_back(blockOrder);
    blockOrder = 0;
    auto res = visitChildren(ctx);
    blockOrder = blockOrderStack.back() + 1;
    blockOrderStack.pop_back();
    return res;
}

antlrcpp::Any DeclarationVisitor::visitBlockItem(CParser::BlockItemContext *ctx) {
    return visitChildren(ctx);
}

