//
// Created by 44190 on 5/26/2021.
//

#include "DeclarationVisitor.h"

#include <memory>

antlrcpp::Any DeclarationVisitor::visitDeclaration(CParser::DeclarationContext *ctx) {
    auto type = visit(ctx->declarationSpecifiers()).as<CType>();
    strings namelist = visit(ctx->initDeclaratorList()).as<strings>();
    string compound_names;
    for (auto compound_name:compound_context) {
        compound_names += compound_name + '@';
        // TODO: make sure '@' not in any name
    }
    for (auto &name : namelist) {
        SymTab::getInstance().add(compound_names + name, SymTabEntry(type));
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
    strings s;
    for (auto &initD : ctx->initDeclarator()) {
        auto name = visit(initD->declarator()).as<string>();
        s.push_back(name);
        // TODO: initializer
    }
    return s;
}

antlrcpp::Any DeclarationVisitor::visitInitDeclarator(CParser::InitDeclaratorContext *ctx) {
    // TODO: initializer
    return ctx->declarator()->directDeclarator()->Identifier()->getText();
}

antlrcpp::Any DeclarationVisitor::visitTypeSpecifier(CParser::TypeSpecifierContext *ctx) {
    return static_cast<TypeSpecifier>(dynamic_cast<tree::TerminalNode *>(ctx->children.front())->getSymbol()->getType());
}

antlrcpp::Any DeclarationVisitor::visitFunctionDefinition(CParser::FunctionDefinitionContext *ctx) {
    auto returnType = visit(ctx->declarationSpecifiers()).as<CType>();
    auto name = visit(ctx->declarator()).as<string>();
//    auto paramList = visit(ctx->parameterTypeList());
    auto funcType = CType(static_cast<CTypeNodePtr>(new FunctionTypeNode(returnType)));
    SymTab::getInstance().add(name, SymTabEntry(funcType));
    compound_context.push_back(name);
    visit(ctx->compoundStatement());
    compound_context.pop_back();
    return nullptr;
}

antlrcpp::Any DeclarationVisitor::visitDeclarator(CParser::DeclaratorContext *ctx) {
    return ctx->directDeclarator()->Identifier()->getText();
}

antlrcpp::Any DeclarationVisitor::visitDirectDeclarator(CParser::DirectDeclaratorContext *ctx) {
    return ctx->Identifier()->getText();
}

//antlrcpp::Any DeclarationVisitor::visitCompoundStatement(CParser::CompoundStatementContext *ctx) {
//    visitChildren(ctx);
//}
//
//antlrcpp::Any DeclarationVisitor::visitBlockItem(CParser::BlockItemContext *ctx) {
//    visitChildren(ctx);
//}
//
