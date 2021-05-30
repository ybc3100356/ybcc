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
    explicit SymTabEntry(CType type = CType(), size_t offset = 0,
                         InitValueType *initValue = nullptr)
            : type(std::move(type)), offset(offset), initValue(initValue) {}

    InitValueType *initValue;
    size_t offset;
    CType type;
};

class SymTab {
    size_t _offset{};
public:
    unordered_map<string, SymTabEntry> entries;

    static SymTab &getInstance() {
        static SymTab instance;
        return instance;
    }

    void add(const string &symbol, const CType &type, InitValueType *initValue = nullptr);

    const SymTabEntry &get(const string &);

    size_t getTotalOffset() const { return _offset; }

private:
    SymTab() = default;


public:
    SymTab(SymTab const &) = delete;

    void operator=(SymTab const &) = delete;
};


#endif //MYCC_SYMTAB_H
