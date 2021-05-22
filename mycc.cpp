#include <iostream>

#include "antlr4-runtime.h"
#include "CLexer.h"
#include "CParser.h"
#include "CBaseVisitor.h"
#include "ParserRuleContext.h"

using namespace c_grammar;
using namespace antlr4;

class EvalVisitor : CBaseVisitor {
public:
    double visitId(CParser::ExpressionContext ctx) {
        return 0;
    }
};

int main(int argc, const char *argv[]) {
    std::ifstream src_file_stream("../test_src/hello.c");
    ANTLRInputStream input(src_file_stream);
    CLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    CParser parser(&tokens);

    tree::ParseTree *tree = parser.compilationUnit();
    std::wstring s = antlrcpp::s2ws(tree->toStringTree(&parser)) + L"\n";
    std::wcout << "Parse Tree: " << s << std::endl;
    return 0;
}