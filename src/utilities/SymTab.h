//
// Created by ybc on 2021/5/27.
//

#ifndef MYCC_SYMTAB_H
#define MYCC_SYMTAB_H

#include <utility>
#include "CParser.h"

#include "type.h"
#include "error.h"
#include "utilities.h"

using InitValueType = CParser::InitializerContext;

class SymTabEntry {
public:
    explicit SymTabEntry(CType type = CType(), size_t offset = 0, size_t line = 0, size_t column = 0,
                         InitValueType *initValue = nullptr)
            : type(std::move(type)), offset(offset), line(line), column(column), initValue(initValue) {}

    InitValueType *initValue;
    size_t offset;
    size_t line;    // line number of this symbol
    size_t column;  // column number of this symbol
    CType type;
};

class SymTab {
    unordered_map<string, SymTabEntry> entries;
    unordered_map<string, size_t> _offsets;
    unordered_map<string, vector<string>> _params;
public:

    static SymTab &getInstance() {
        static SymTab instance;
        return instance;
    }

    void show();

    void add(const string &symbol, const CType &type, size_t line, size_t column, InitValueType *initValue = nullptr,
             bool isParam = false);

    const SymTabEntry &get(const string &name, size_t line = -1, size_t column = -1);

    size_t getOffset(const string &symbol);

    // function
    size_t getTotalOffset(const string &funcName);

    vector<string> getParamNames(const string &funcName);

private:
    SymTab() = default;


public:
    SymTab(SymTab const &) = delete;

    void operator=(SymTab const &) = delete;
};


#endif //MYCC_SYMTAB_H
