//
// Created by 44190 on 5/26/2021.
//

#ifndef MYCC_DECLARATIONVISITOR_H
#define MYCC_DECLARATIONVISITOR_H

#include "antlr4-runtime.h"
#include "CLexer.h"
#include "CParser.h"

#include "CBaseVisitor.h"
#include "SymTab.h"
#include "utilities.h"

using namespace antlrcpp;
using namespace antlr4;
using strings = vector<string>;
using InitDeclarator = pair<string, InitValueType *>;
using InitDeclarators = vector<InitDeclarator>;

class DeclarationVisitor : public CBaseVisitor {
    string curFunc;
    vector<size_t> blockOrderStack;
    size_t blockOrder = 0;
public:

    string getCompoundContext() {
        string compound_names;
        // TODO: make sure '@' not in any name
        for (const auto &order : blockOrderStack) {
            compound_names += to_string(order) + '@';
        }
        return curFunc + '@' + compound_names;
    }

    antlrcpp::Any visitIdentifier(CParser::IdentifierContext *ctx) override;

    antlrcpp::Any visitDeclaration(CParser::DeclarationContext *ctx) override;

    antlrcpp::Any visitDeclarationSpecifiers(CParser::DeclarationSpecifiersContext *ctx) override;

    antlrcpp::Any visitDeclarationSpecifierList(CParser::DeclarationSpecifierListContext *ctx) override;

    antlrcpp::Any visitSimpleTypeSpecifier(CParser::SimpleTypeSpecifierContext *ctx) override;

    antlrcpp::Any visitInitDeclaratorList(CParser::InitDeclaratorListContext *ctx) override;

    antlrcpp::Any visitInitDeclarator(CParser::InitDeclaratorContext *ctx) override;

    antlrcpp::Any visitInitializer(CParser::InitializerContext *ctx) override;

    antlrcpp::Any visitTypeSpecifier(CParser::TypeSpecifierContext *ctx) override;

    antlrcpp::Any visitFunctionDefinition(CParser::FunctionDefinitionContext *ctx) override;

    antlrcpp::Any visitParameterList(CParser::ParameterListContext *ctx) override;

    antlrcpp::Any visitParameterDeclaration(CParser::ParameterDeclarationContext *ctx) override;

    antlrcpp::Any visitDirectDeclarator(CParser::DirectDeclaratorContext *ctx) override;

    antlrcpp::Any visitDeclarator(CParser::DeclaratorContext *ctx) override;

    antlrcpp::Any visitCompoundStatement(CParser::CompoundStatementContext *ctx) override;

    antlrcpp::Any visitWhileLoop(CParser::WhileLoopContext *ctx) override;

    antlrcpp::Any visitDoWhile(CParser::DoWhileContext *ctx) override;

    antlrcpp::Any visitForLoop(CParser::ForLoopContext *ctx) override;

    antlrcpp::Any visitBlockItem(CParser::BlockItemContext *ctx) override;

    antlrcpp::Any visitGeneralizedCompoundStatement(CParser::BlockContext::ParseTree *ctx);
};


#endif //MYCC_DECLARATIONVISITOR_H
