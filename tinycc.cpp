#include <iostream>

#include "antlr4-runtime.h"
#include "TinyCLexer.h"
#include "TinyCParser.h"
#include "TinyCBaseVisitor.h"
#include "ParserRuleContext.h"
#include <unordered_map>

#pragma execution_character_set("utf-8")

using namespace tinyc_grammar;
using namespace antlr4;

class EvalVisitor : public TinyCBaseVisitor {
public:
    std::unordered_map<std::string, double> vars;

    antlrcpp::Any visitAssign(TinyCParser::AssignContext *ctx) override {
        std::string id = ctx->ID()->getText();
        double val = visit(ctx->expr()).as<double>();
        vars.insert(std::make_pair(id, val));
        return val;
    }

    antlrcpp::Any visitPrintExpr(TinyCParser::PrintExprContext *ctx) override {
        double val = visit(ctx->expr()).as<double>();
        std::cout << val << " ";
        return 0;
    }

    antlrcpp::Any visitLiteral(TinyCParser::LiteralContext *ctx) override {
        return std::strtod(ctx->NUMBER()->getText().c_str(), nullptr);
    }

    antlrcpp::Any visitId(TinyCParser::IdContext *ctx) override {
        std::string id = ctx->ID()->getText();
        auto it = vars.find(id);
        if (it != vars.end())
            return it->second;
        return .0;
    }

    antlrcpp::Any visitMulDiv(TinyCParser::MulDivContext *ctx) override {
        double lhs = visit(ctx->expr(0)).as<double>();
        double rhs = visit(ctx->expr(1)).as<double>();
        if (ctx->op->getType() == TinyCParser::MUL)
            return lhs * rhs;
        return lhs / rhs;
    }

    antlrcpp::Any visitAddSub(TinyCParser::AddSubContext *ctx) override {
        double lhs = visit(ctx->expr(0)).as<double>();
        double rhs = visit(ctx->expr(1)).as<double>();
        if (ctx->op->getType() == TinyCParser::ADD)
            return lhs + rhs;
        return lhs - rhs;
    }

    antlrcpp::Any visitParen(TinyCParser::ParenContext *ctx) override {
        return visit(ctx->expr()).as<double>();
    }
};

int main(int argc, const char *argv[]) {

    std::ifstream src_file_stream("../test_src/hello.tc");
    ANTLRInputStream input(src_file_stream);
    TinyCLexer lexer(&input);
    CommonTokenStream tokens(&lexer);

    TinyCParser parser(&tokens);
    tree::ParseTree *tree = parser.calc();
    std::wstring s = antlrcpp::s2ws(tree->toStringTree(&parser)) + L"\n";
    std::wcout << "Parse Tree: " << s << std::endl;

    EvalVisitor visitor;
    visitor.visit(tree);
    return 0;
}