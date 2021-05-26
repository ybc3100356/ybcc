//
// Created by 44190 on 5/26/2021.
//

#include "DeclarationVisitor.h"

antlrcpp::Any DeclarationVisitor::visitDeclaration(CParser::DeclarationContext *ctx) {
    auto type = visit(ctx->declarationSpecifiers()).as<CType>();
//    strings namelist = visit(ctx->initDeclaratorList()).as<strings>();
//    for (auto &name : namelist) {
    declarations.insert(make_pair(ctx->getText(), type));
//    }
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
    for (auto &specifier : ctx->initDeclarator()) {

    }
}

antlrcpp::Any DeclarationVisitor::visitInitDeclarator(CParser::InitDeclaratorContext *ctx) {
    return visitChildren(ctx);
}

antlrcpp::Any DeclarationVisitor::visitTypeSpecifier(CParser::TypeSpecifierContext *ctx) {
    return static_cast<TypeSpecifier>(dynamic_cast<tree::TerminalNode *>(ctx->children.front())->getSymbol()->getType());
}

antlrcpp::Any DeclarationVisitor::visitFunctionDefinition(CParser::FunctionDefinitionContext *ctx) {
    auto returnType = visit(ctx->declarationSpecifiers()).as<CType>();
    auto name = visit(ctx->declarator()).as<string>();
    std::cout <<
              "name:[" << name <<
              "] type:[" << (size_t) returnType.getType()->getNodeType() << "]"
              << std::endl;
    declarations.insert(make_pair(name, returnType));
    return nullptr;
}

antlrcpp::Any DeclarationVisitor::visitDeclarator(CParser::DeclaratorContext *ctx)  {
    return ctx->directDeclarator()->Identifier()->getText();
}

antlrcpp::Any DeclarationVisitor::visitDirectDeclarator(CParser::DirectDeclaratorContext *ctx) {
    return ctx->Identifier()->getText();
}
