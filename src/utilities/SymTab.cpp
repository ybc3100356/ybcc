//
// Created by ybc on 2021/5/27.
//

#include "SymTab.h"

void SymTab::add(const string &symbol, const SymTabEntry &newEntry) {
    auto entry = entries.find(symbol);
    if (entry != entries.end()) {
        throw ReDefError((string("redefinition symbol: ") + symbol).c_str());
    } else {
        entries.insert({symbol, newEntry});
    }
}

const SymTabEntry &SymTab::get(const string &symbol) {
    auto entry = entries.find(symbol);
    if (entry != entries.end()) {
        return entry->second;
    } else {
        throw UnDefError((string("undefined symbol: ") + symbol).c_str());
    }
}

const unordered_map<string, SymTabEntry> SymTab::getEntries() {
    return entries;
}
