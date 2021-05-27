//
// Created by ybc on 2021/5/27.
//

#ifndef MYCC_SYMTAB_H
#define MYCC_SYMTAB_H

#include "type.h"
#include <vector>
#include <unordered_map>
#include <string>

class SymTabEntry {
public:
    explicit SymTabEntry(CType type) : type(type) {}

    CType type;
};

using std::unordered_map;
using std::shared_ptr;
using std::string;

class SymTab {
public:
    static SymTab &getInstance() {
        static SymTab instance;
        return instance;
    }

    unordered_map<string, SymTabEntry> entries;
private:
    SymTab() = default;

public:
    SymTab(SymTab const &) = delete;

    void operator=(SymTab const &) = delete;
};


#endif //MYCC_SYMTAB_H
