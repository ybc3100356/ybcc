//
// Created by 44190 on 5/26/2021.
//

#include "DeclarationVisitor.h"

#include <memory>

antlrcpp::Any DeclarationVisitor::visitDeclaration(CParser::DeclarationContext *ctx) {
    auto type = visit(ctx->declarationSpecifiers()).as<CType>();
    auto declarators = visit(ctx->initDeclaratorList()).as<InitDeclarators>();
    string compound_names;
    for (const auto &compound_name : compound_context) {
        compound_names += compound_name + '@';
        // TODO: make sure '@' not in any name
    }
    for (auto &declarator : declarators) {
        SymTab::getInstance().add(compound_names + declarator.first, type, declarator.second);
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
    // TODO: initializer
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
    SymTab::getInstance().add(name, funcType);
    compound_context.push_back(name);
    visit(ctx->compoundStatement());
    compound_context.pop_back();
    return nullptr;
}

antlrcpp::Any DeclarationVisitor::visitDeclarator(CParser::DeclaratorContext *ctx) {
    return ctx->directDeclarator()->identifier()->getText();
}

antlrcpp::Any DeclarationVisitor::visitDirectDeclarator(CParser::DirectDeclaratorContext *ctx) {
    return ctx->identifier()->getText();
}

antlrcpp::Any DeclarationVisitor::visitCompoundStatement(CParser::CompoundStatementContext *ctx) {
    ++blockDep;
    compound_context.push_back(to_string(blockDep));
    auto res = visitChildren(ctx);
    compound_context.pop_back();
    --blockDep;
    return res;
}

antlrcpp::Any DeclarationVisitor::visitBlockItem(CParser::BlockItemContext *ctx) {
    return visitChildren(ctx);
}
