//
// Created by 44190 on 5/26/2021.
//

#ifndef MYCC_DECLARATIONVISITOR_H
#define MYCC_DECLARATIONVISITOR_H

#include "antlr4-runtime.h"
#include "CLexer.h"
#include "CParser.h"
#include "ParserRuleContext.h"

#include "CBaseVisitor.h"
#include "utilities/SymTab.h"
#include "AST/DeclarationVisitor.h"
#include <vector>

using namespace antlrcpp;
using namespace antlr4;
using std::vector;
using std::string;
using strings = vector<string>;


class DeclarationVisitor : public CBaseVisitor {
    strings compound_context;
public:

    antlrcpp::Any visitDeclaration(CParser::DeclarationContext *ctx) override;

    antlrcpp::Any visitDeclarationSpecifiers(CParser::DeclarationSpecifiersContext *ctx) override;

    antlrcpp::Any visitDeclarationSpecifierList(CParser::DeclarationSpecifierListContext *ctx) override;

    antlrcpp::Any visitSimpleTypeSpecifier(CParser::SimpleTypeSpecifierContext *ctx) override;

    antlrcpp::Any visitInitDeclaratorList(CParser::InitDeclaratorListContext *ctx) override;

    antlrcpp::Any visitInitDeclarator(CParser::InitDeclaratorContext *ctx) override;

    antlrcpp::Any visitTypeSpecifier(CParser::TypeSpecifierContext *ctx) override;

    antlrcpp::Any visitFunctionDefinition(CParser::FunctionDefinitionContext *ctx) override;

    antlrcpp::Any visitDirectDeclarator(CParser::DirectDeclaratorContext *ctx) override;

    antlrcpp::Any visitDeclarator(CParser::DeclaratorContext *ctx) override;

//    antlrcpp::Any visitCompoundStatement(CParser::CompoundStatementContext *ctx) override;
//
//     antlrcpp::Any visitBlockItem(CParser::BlockItemContext *ctx) override;
};


#endif //MYCC_DECLARATIONVISITOR_H
