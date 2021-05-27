#include <iostream>

#include "antlr4-runtime.h"
#include "CLexer.h"
#include "CParser.h"

#include "utilities/SymTab.h"
#include "AST/DeclarationVisitor.h"
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
    std::ifstream src_file_stream("../test/test.c");
//    string src_file_stream("#include \"stdio.h\"\n"
//                           "int main(){}"
//                           "int a(int x,...){}");
    ANTLRInputStream input(src_file_stream);
    CLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    CParser parser(&tokens);
    tree::ParseTree *tree = parser.compilationUnit();

    DeclarationVisitor visitor;
    try {
        visitor.visit(tree);
        std::cout << "symbol table:" << std::endl;
        for (auto &entry : SymTab::getInstance().getEntries()) {
            std::cout << "name:[" << entry.first << "] type:[";
            auto type = entry.second.type.getTypeTree()->getNodeType();
            std::cout << getTypeStr(type) << "] ";
            if (type == BaseType::Function) {
                auto funcType = dynamic_cast<FunctionTypeNode *>(entry.second.type.getTypeTree().get());
                std::cout << "return type:[" << getTypeStr(funcType->getReturnType()) << "]";
            }
            std::cout << std::endl;
        }
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}