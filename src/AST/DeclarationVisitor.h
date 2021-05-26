//
// Created by 44190 on 5/26/2021.
//

#ifndef MYCC_DECLARATIONVISITOR_H
#define MYCC_DECLARATIONVISITOR_H

#include "antlr4-runtime.h"
#include "CLexer.h"
#include "CParser.h"

#include "CBaseVisitor.h"
#include "utilities/type.h"
#include "AST/DeclarationVisitor.h"
#include <vector>
#include <stdexcept>

using namespace antlrcpp;
using namespace antlr4;
using std::vector;
using std::string;
using strings = vector<string>;

using std::map;
using std::string;


class TypeError : std::exception {
    string content;

    const char *what() const noexcept override {
        return content.c_str();
    }

public:
    explicit TypeError(const char *content) : content(content) {}
};


class DeclarationVisitor : public CBaseVisitor {
public:
    map<string, CType> declarations;

    antlrcpp::Any visitDeclaration(CParser::DeclarationContext *ctx) override;

    antlrcpp::Any visitDeclarationSpecifiers(CParser::DeclarationSpecifiersContext *ctx) override;

    antlrcpp::Any visitDeclarationSpecifierList(CParser::DeclarationSpecifierListContext *ctx) override;

    antlrcpp::Any visitSimpleTypeSpecifier(CParser::SimpleTypeSpecifierContext *ctx) override;

    antlrcpp::Any visitInitDeclaratorList(CParser::InitDeclaratorListContext *ctx) override;

    antlrcpp::Any visitInitDeclarator(CParser::InitDeclaratorContext *ctx) override;

    antlrcpp::Any visitTypeSpecifier(CParser::TypeSpecifierContext *ctx) override;
};


#endif //MYCC_DECLARATIONVISITOR_H
