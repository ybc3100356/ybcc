#include <iostream>

#include "antlr4-runtime.h"
#include "CLexer.h"
#include "CParser.h"

#include "SymTab.h"
#include "DeclarationVisitor.h"
#include "CodeGenVisitor.h"
#include "utilities.h"

using namespace antlrcpp;
using namespace antlr4;
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
    } else if (argc == 3) {
        std::ifstream src_file(argv[1]);
        input.load(src_file);
    } else {
        std::cout << "usage: mycc [c source file] [output] (std in/out by default)" << std::endl;
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
        if (argc == 3) {
            SymTab::getInstance().show();
            freopen(argv[2], "w", stdout);
        }
        CodeGenVisitor codeGenVisitor;
        string asm_file = codeGenVisitor.visit(tree).as<string>();
        std::cout << asm_file << std::endl;
    }
    catch (Error &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}