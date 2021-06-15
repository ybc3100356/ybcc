//
// Created by ybc on 2021/5/27.
//

#include "SymTab.h"

void SymTab::add(const string &symbol, const CType &type, size_t line, size_t column, InitValuePtr initValue,
                 bool isParam, bool isArray) {
    auto entry = entries.find(symbol);
    if (entry != entries.end()) {
        throw ReDef(symbol);
    } else {
        if (type.getTypeTree()->getNodeType() == BaseType::Function) {
            // function
            entries.insert({symbol, SymTabEntry(type, 0, line, column, initValue)});
            _params[symbol];
        } else {
            auto pos = symbol.find_first_of('@');
            auto funcName = symbol.substr(0, pos);
            if (isArray) {
                _offsets[funcName] += type.getTypeTree()->getSize() / 4;
                size_t baseTypeSize = type.getTypeTree()->getBaseNodeSize() / 4;
                entries.insert({symbol, SymTabEntry(type, _offsets[funcName] - baseTypeSize, line, column, initValue)});
            } else {
                entries.insert({symbol, SymTabEntry(type, _offsets[funcName], line, column, initValue)});
                _offsets[funcName] += type.getTypeTree()->getSize() / 4;
            }
            if (isParam)
                _params[funcName].push_back(symbol);
        }
        entries[symbol].name = symbol;
    }
}

const SymTabEntry &SymTab::get(const string &symbol, size_t line, size_t column) {
    // func or globalVar var
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
        if (entry != entries.end() &&
            (entry->second.line < line ||
             (entry->second.line == line && entry->second.column <= column))) {
            return entry->second;
        }
        if ((pos = prefix.find_last_of('@')) == string::npos) {
            entry = entries.find(name);
            if (entry != entries.end() &&
                (entry->second.line < line ||
                 (entry->second.line == line && entry->second.column <= column))) {
                return entry->second;
            }
            throw UnDef(symbol);
        } else {
            prefix = prefix.substr(0, pos);
        }
    }
}

void SymTab::show() {
    std::cout << "symbol table:" << std::endl;
    for (auto &entry : entries) {
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

    std::cout << "offset:" << std::endl;
    for (const auto&[key, value]:_offsets) {
        std::cout << "func:" << key << ", offset:" << value << std::endl;
    }
}

size_t SymTab::getTotalOffset(const string &funcName) {
    return _offsets[funcName];
}

vector<string> SymTab::getParamNames(const string &funcName) {
    return _params[funcName];
}

size_t SymTab::getOffset(const string &symbol) {
    auto result = entries.find(symbol);
    if (result != entries.end())
        return result->second.offset;
    else {
        throw UnDef(symbol);
    }
}

