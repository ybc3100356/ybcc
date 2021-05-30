//
// Created by ybc on 2021/5/27.
//

#include "SymTab.h"

void SymTab::add(const string &symbol, const CType &type, InitValueType *initValue) {
    auto entry = entries.find(symbol);
    if (entry != entries.end()) {
        throw ReDef(symbol);
    } else {
        entries.insert({symbol, SymTabEntry(type, _offset, initValue)});
        _offset += type.getTypeTree()->getSize() / 4;
    }
}

const SymTabEntry &SymTab::get(const string &symbol) {
    auto entry = entries.find(symbol);
    if (entry != entries.end()) {
        return entry->second;
    } else {
        throw UnDef(symbol);
    }
}

