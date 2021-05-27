//
// Created by ybc on 2021/5/27.
//

#ifndef MYCC_SYMTAB_H
#define MYCC_SYMTAB_H

#include "type.h"
#include <vector>
#include <unordered_map>
#include <string>
#include "error.h"

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

    void add(const string &, const SymTabEntry &);

    const SymTabEntry &get(const string &);

    const unordered_map<string, SymTabEntry> getEntries();

private:
    SymTab() = default;

    unordered_map<string, SymTabEntry> entries;

public:
    SymTab(SymTab const &) = delete;

    void operator=(SymTab const &) = delete;
};


#endif //MYCC_SYMTAB_H
