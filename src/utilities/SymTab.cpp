//
// Created by ybc on 2021/5/27.
//

#include "SymTab.h"

void SymTab::add(const string &symbol, const CType &type, size_t line, size_t column, InitValueType *initValue) {
    auto entry = entries.find(symbol);
    if (entry != entries.end()) {
        throw ReDef(symbol);
    } else {
        entries.insert({symbol, SymTabEntry(type, _offset, line, column, initValue)});
        _offset += type.getTypeTree()->getSize() / 4;
    }
}

const SymTabEntry &SymTab::get(const string &symbol, size_t line, size_t column) {
    // func
    auto pos = symbol.find_last_of('@');
    if (pos == string::npos) {
        auto entry = entries.find(symbol);
        if (entry != entries.end()) {
            return entry->second;
        }
    }

    // variable
    auto name = symbol.substr(pos + 1, symbol.size());
    auto prefix = symbol.substr(0, pos);
    auto entry = entries.end();
    while (true) {
        entry = entries.find(prefix + "@" + name);
        if (entry != entries.end() && entry->second.line <= line && entry->second.column <= column) {
//            std::cout << " found: " << prefix + "@" + name << std::endl;
            return entry->second;
        }
        if ((pos = prefix.find_last_of('@')) == string::npos) {
            throw UnDef(symbol);
        }
//        std::cout << prefix + "@" + name + " not found, try:";
        prefix = prefix.substr(0, pos);
//        std::cout << prefix + "@" + name << std::endl;
    }
}

void SymTab::show() {
    std::cout << "symbol table:" << std::endl;
    for (auto &entry : SymTab::getInstance().entries) {
        std::cout << "name:[" << entry.first << "]\t\t type:[";
        auto type = entry.second.type.getTypeTree()->getNodeType();
        std::cout << getTypeStr(type) << "]\t\t";

        // function
        if (type == BaseType::Function) {
            auto funcType = dynamic_cast<FunctionTypeNode *>(entry.second.type.getTypeTree().get());
            std::cout << " return type:[" << getTypeStr(funcType->getReturnType()) << "]\t\t";
        }
        std::cout << " offset:[" << entry.second.offset << "]\t\t";

        if (entry.second.initValue != nullptr) {
            std::cout << " init value:[" << entry.second.initValue->getText() << "]\t\t";
        }
        std::cout << std::endl;
    }
}

