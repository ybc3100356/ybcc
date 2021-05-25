#include <iostream>

#include "antlr4-runtime.h"
#include "CLexer.h"
#include "CParser.h"
#include "CBaseVisitor.h"
#include "ParserRuleContext.h"
#include <vector>
#include <map>
#include "utilities/type.h"
#include <stdexcept>

using namespace c_grammar;
using namespace antlr4;
using std::vector;
using std::string;
using std::map;
using std::make_pair;
using strings = vector<string>;

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

    antlrcpp::Any visitDeclaration(CParser::DeclarationContext *ctx) override {
        auto type = visit(ctx->declarationSpecifiers()).as<CType>();
//        strings namelist = visit(ctx->initDeclaratorList()).as<strings>();
//        for (auto &name : namelist) {
        declarations.insert(make_pair(ctx->getText(), type));
//        }
        return nullptr;
    }

    antlrcpp::Any visitDeclarationSpecifiers(CParser::DeclarationSpecifiersContext *ctx) override {
        auto type = visit(ctx->declarationSpecifierList()).as<CType>();
        type.definedType = (ctx->typedefSpecifier());
        return type;
    }

    antlrcpp::Any visitDeclarationSpecifierList(CParser::DeclarationSpecifierListContext *ctx) override {
        CType type(StorageClassSpecifier::None);
        TypeSpecifiers typeSpecifiers;
        for (auto &specifier : ctx->declarationSpecifier()) {
            if (auto s = specifier->storageClassSpecifier()) {
                if (type.storageClass != StorageClassSpecifier::None) {
                    throw TypeError("multiple storage class specifier!");
                }
                type.storageClass = visit(s).as<StorageClassSpecifier>();
            } else if (auto s = specifier->typeQualifier()) {
                type.qualifier = visit(s).as<QualifierSpecifier>();
            } else if (auto s = specifier->functionSpecifier()) {
                type.function = visit(s).as<FunctionSpecifier>();
            } else {
                // type specifier
                auto typeSpecifier = specifier->typeSpecifier();
                if (auto s = typeSpecifier->simpleTypeSpecifier()) {
                    typeSpecifiers.push_back(visit(s).as<TypeSpecifier>());
                } else if (auto s = typeSpecifier->structOrUnionSpecifier()) {
                    type.compoundTypesPtr = visit(s->structDeclarationList()).as<CompoundTypesPtr>();
                    type.baseType = visit(s->structOrUnion()).as<BaseType>();
                } else if (auto s = typeSpecifier->enumSpecifier()) {

                } else if (auto s = typeSpecifier->typedefName()) {

                } else // pointer
                {

                }
            }
        }
        type.baseType = getBaseType(typeSpecifiers);
        return type;
    }

    antlrcpp::Any visitStructDeclarationList(CParser::StructDeclarationListContext *ctx) override {
        auto types = new CompoundTypes();
        for (auto specifier :ctx->structDeclaration()) {
            types->push_back(visit(specifier).as<CompoundType>());
        }
        return types;
    }

    antlrcpp::Any visitStructDeclaration(CParser::StructDeclarationContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitSpecifierQualifierList(CParser::SpecifierQualifierListContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitStructDeclaratorList(CParser::StructDeclaratorListContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitStructDeclarator(CParser::StructDeclaratorContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitEnumSpecifier(CParser::EnumSpecifierContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitEnumeratorList(CParser::EnumeratorListContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitEnumerator(CParser::EnumeratorContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitEnumerationConstant(CParser::EnumerationConstantContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitInitDeclaratorList(CParser::InitDeclaratorListContext *ctx) override {
        for (auto &declarator:ctx->initDeclarator()) {

        }
        return visitChildren(ctx);
    }

    antlrcpp::Any visitInitDeclarator(CParser::InitDeclaratorContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitTypeSpecifier(CParser::TypeSpecifierContext *ctx) override {
        try {
            return static_cast<TypeSpecifier>(dynamic_cast<tree::TerminalNode *>(ctx->children.front())->getSymbol()->getType());
        }
        catch (std::bad_cast &) {
            return visitChildren(ctx);
        }
    }

    antlrcpp::Any visitStorageClassSpecifier(CParser::StorageClassSpecifierContext *ctx) override {
        return static_cast<StorageClassSpecifier>(dynamic_cast<tree::TerminalNode *>(ctx->children.front())->getSymbol()->getType());
    }

    antlrcpp::Any visitTypeQualifier(CParser::TypeQualifierContext *ctx) override {
        return static_cast<QualifierSpecifier>(dynamic_cast<tree::TerminalNode *>(ctx->children.front())->getSymbol()->getType());
    }

    antlrcpp::Any visitFunctionSpecifier(CParser::FunctionSpecifierContext *ctx) override {
        return static_cast<FunctionSpecifier>(dynamic_cast<tree::TerminalNode *>(ctx->children.front())->getSymbol()->getType());
    }

    antlrcpp::Any visitStructOrUnion(CParser::StructOrUnionContext *ctx) override {
        return static_cast<BaseType>(dynamic_cast<tree::TerminalNode *>(ctx->children.front())->getSymbol()->getType());
    }

    antlrcpp::Any visitSimpleTypeSpecifier(CParser::SimpleTypeSpecifierContext *ctx) override {
        auto test = static_cast<TypeSpecifier>(dynamic_cast<tree::TerminalNode *>(ctx->children.front())->getSymbol()->getType());
        return test;
    }

    antlrcpp::Any visitDeclarator(CParser::DeclaratorContext *ctx) override {
        return visitChildren(ctx);
    }

};

class AST {
public:

};

class ASTNode : AST {
public:

};

class ExpressionNode : ASTNode {
public:


};

void preprocess() {
    std::cout << "not implemented" << std::endl;
}


int main(int argc, const char *argv[]) {
    std::ifstream src_file_stream("../test_src/test.c");
    ANTLRInputStream input(src_file_stream);
    CLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    CParser parser(&tokens);
    tree::ParseTree *tree = parser.compilationUnit();
//    std::wstring s = antlrcpp::s2ws(tree->toStringTree(&parser)) + L"\n";
//    std::wcout << "Parse Tree: " << s << std::endl;

    DeclarationVisitor visitor;
    visitor.visit(tree);
    for (auto &declaration:visitor.declarations) {
        std::cout <<
                  "name:[" << declaration.first <<
                  "] type:[" << (size_t) declaration.second.baseType << "]"
                  << std::endl;
    }
    return 0;
}