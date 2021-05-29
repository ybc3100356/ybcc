#include <iostream>

#include "antlr4-runtime.h"
#include "CLexer.h"
#include "CParser.h"

#include "utilities/SymTab.h"
#include "AST/DeclarationVisitor.h"
#include "CodeGen/CodeGenVisitor.h"
#include <vector>
#include <stdexcept>

using namespace antlrcpp;
using namespace antlr4;
using std::vector;
using std::string;
using strings = vector<string>;


void preprocess() {
    std::cout << "not implemented" << std::endl;
}

int main(int argc, const char *argv[]) {
    ANTLRInputStream input;
    if (argc == 1) {
        input.load(std::cin);
    } else if (argc == 2) {
        std::ifstream src_file(argv[1]);
        input.load(src_file);
    } else {
        std::cout << "usage: mycc [c source file] (std in by default)" << std::endl;
        return 0;
    }
    CLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    CParser parser(&tokens);
    tree::ParseTree *tree = parser.compilationUnit();

    try {
        // declarations
        DeclarationVisitor declarationVisitor;
        declarationVisitor.visit(tree);
//        std::cout << "symbol table:" << std::endl;
//        for (auto &entry : SymTab::getInstance().getEntries()) {
//            std::cout << "name:[" << entry.first << "] type:[";
//            auto type = entry.second.type.getTypeTree()->getNodeType();
//            std::cout << getTypeStr(type) << "] ";
//
//            // function
//            if (type == BaseType::Function) {
//                auto funcType = dynamic_cast<FunctionTypeNode *>(entry.second.type.getTypeTree().get());
//                std::cout << "return type:[" << getTypeStr(funcType->getReturnType()) << "]";
//            }
//            std::cout << std::endl;
//        }

        CodeGenVisitor codeGenVisitor;
        string asm_file = codeGenVisitor.visit(tree).as<string>();
        std::cout << asm_file << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}