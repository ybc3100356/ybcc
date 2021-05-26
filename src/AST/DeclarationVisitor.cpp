//
// Created by 44190 on 5/26/2021.
//

#include "DeclarationVisitor.h"

antlrcpp::Any DeclarationVisitor::visitDeclaration(CParser::DeclarationContext *ctx) {
    auto type = visit(ctx->declarationSpecifiers()).as<CType>();
// TODO: array type
//        strings namelist = visit(ctx->initDeclaratorList()).as<strings>();
//        for (auto &name : namelist) {
    declarations.insert(make_pair(ctx->getText(), type));
//        }
    return nullptr;
}

antlrcpp::Any DeclarationVisitor::visitDeclarationSpecifiers(CParser::DeclarationSpecifiersContext *ctx) {
    auto typeNode = visit(ctx->declarationSpecifierList()).as<CTypeNodePtr>();
    CType type(typeNode, bool(ctx->typedefSpecifier()));
    return
            type;
}

antlrcpp::Any DeclarationVisitor::visitDeclarationSpecifierList(CParser::DeclarationSpecifierListContext *ctx) {
    CTypeNodePtr typeNode(new SimpleTypeNode(nullptr));
    TypeSpecifiers typeSpecifiers;
    for (auto &specifier            : ctx->declarationSpecifier()) {
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
    return CTypeNodePtr(new SimpleTypeNode(typeNode, getBaseType(typeSpecifiers)));
}

antlrcpp::Any DeclarationVisitor::visitSimpleTypeSpecifier(CParser::SimpleTypeSpecifierContext *ctx) {
    return static_cast<TypeSpecifier>(dynamic_cast<tree::TerminalNode *>(ctx->children.front())->getSymbol()->getType());
}

antlrcpp::Any DeclarationVisitor::visitInitDeclaratorList(CParser::InitDeclaratorListContext *ctx) {
    return visitChildren(ctx);
}

antlrcpp::Any DeclarationVisitor::visitInitDeclarator(CParser::InitDeclaratorContext *ctx) {
    return visitChildren(ctx);
}

antlrcpp::Any DeclarationVisitor::visitTypeSpecifier(CParser::TypeSpecifierContext *ctx) {
    return static_cast<TypeSpecifier>(dynamic_cast<tree::TerminalNode *>(ctx->children.front())->getSymbol()->getType());
}
