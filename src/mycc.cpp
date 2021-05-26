#include <iostream>

#include "antlr4-runtime.h"
#include "CLexer.h"
#include "CParser.h"
#include "CBaseVisitor.h"
#include "ParserRuleContext.h"

#include "utilities/type.h"

#include <vector>
#include <map>
#include <stdexcept>
#include <memory>

using namespace antlrcpp;
using namespace antlr4;
using std::vector;
using std::string;
using std::map;
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
        // TODO: array type
//        strings namelist = visit(ctx->initDeclaratorList()).as<strings>();
//        for (auto &name : namelist) {
        declarations.insert(make_pair(ctx->getText(), type));
//        }
        return nullptr;
    }

    antlrcpp::Any visitDeclarationSpecifiers(CParser::DeclarationSpecifiersContext *ctx) override {
        auto typeNode = visit(ctx->declarationSpecifierList()).as<CTypeNodePtr>();
        CType type(typeNode, bool(ctx->typedefSpecifier()));
        return type;
    }

    antlrcpp::Any visitDeclarationSpecifierList(CParser::DeclarationSpecifierListContext *ctx) override {
        CTypeNodePtr typeNode(new SimpleTypeNode(nullptr));
        TypeSpecifiers typeSpecifiers;
        for (auto &specifier : ctx->declarationSpecifier()) {
            /*if (auto s = specifier->storageClassSpecifier()) {
                // TODO: another specifiers
                }
                if (typeNode->storageClass != StorageClassSpecifier::None) {
                    throw TypeError("multiple storage class specifier!");
                }
                typeNode->storageClass = visit(s).as<StorageClassSpecifier>();
            } else if (auto s = specifier->typeQualifier()) {
                typeNode->qualifier = visit(s).as<QualifierSpecifier>();
            } else if (auto s = specifier->functionSpecifier()) {
                typeNode->function = visit(s).as<FunctionSpecifier>();
            } else
            {*/
                // type specifier
                auto typeSpecifier = specifier->typeSpecifier();
                if (auto s = typeSpecifier->simpleTypeSpecifier()) {
                    // simple type specifier
                    typeSpecifiers.push_back(visit(s).as<TypeSpecifier>());

                }
                // TODO: compound type
                /*else if (auto s = typeSpecifier->structOrUnionSpecifier()) {
                    // struct
                    if (!typeSpecifiers.empty()) // wrong! something like "struct int" was defined!
                        throw TypeError("multiple base type specifier!");
                    StructTypeNodePtr structTypeNode(new StructTypeNode(typeNode));
                    structTypeNode->childNodes = visit(s->structDeclarationList()).as<CompoundTypesPtr>();
                    structTypeNode->baseType = visit(s->structOrUnion()).as<BaseType>();
                    typeNode = structTypeNode;

                } else if (auto s = typeSpecifier->enumSpecifier()) {
                    // enum

                } else if (auto s = typeSpecifier->typedefName()) {
                    // typedef
                    if (!typeSpecifiers.empty()) // wrong! something like "A int" was defined!
                        throw TypeError("multiple base type specifier!");

                    auto definedName = visit(s).as<string>();
                    auto definedType = declarations.find(definedName);

                    // check validity of typedef symbol
                    if (definedType == declarations.end()) {
                        throw TypeError((string("undefined symbol name:") + definedName).c_str());
                    } else if (!definedType->second.definedType) {
                        throw TypeError((string("this symbol is not a defined type:") + definedName).c_str());
                    }

                    typeNode = definedType->second.node;
                } else // pointer, array
                {

                }
            }*/
        }

        // simple type
        return CTypeNodePtr(new SimpleTypeNode(typeNode, getBaseType(typeSpecifiers)));
    }

    /*
     * antlrcpp::Any visitStructDeclarationList(CParser::StructDeclarationListContext *ctx) override {
        CompoundTypesPtr types(new CompoundTypes());
        for (auto specifier :ctx->structDeclaration()) {
            types.get()->push_back(visit(specifier).as<CTypeNodePtr>());
        }
        return types;
    }*/


    antlrcpp::Any visitInitDeclaratorList(CParser::InitDeclaratorListContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitInitDeclarator(CParser::InitDeclaratorContext *ctx) override {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitTypeSpecifier(CParser::TypeSpecifierContext *ctx) override {
//        try {
        return static_cast<TypeSpecifier>(dynamic_cast<tree::TerminalNode *>(ctx->children.front())->getSymbol()->getType());
//        }
//        catch (std::bad_cast &) {
//            return visitChildren(ctx);
//        }
    }

    /*antlrcpp::Any visitStorageClassSpecifier(CParser::StorageClassSpecifierContext *ctx) override {
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
    }*/



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
    std::ifstream src_file_stream("../test/test.c");
    ANTLRInputStream input(src_file_stream);
    CLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    CParser parser(&tokens);
    tree::ParseTree *tree = parser.compilationUnit();
    std::cout << tree->toStringTree() << std::endl;

    DeclarationVisitor visitor;
    visitor.visit(tree);
    for (auto &declaration:visitor.declarations) {
        std::cout <<
                  "name:[" << declaration.first <<
                  "] type:[" << (size_t) declaration.second.node.get()->getNodeType() << "]"
                  << std::endl;
    }
    return 0;
}