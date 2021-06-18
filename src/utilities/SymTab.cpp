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
        if (type.isTypedef()) {
            entries.insert({symbol, SymTabEntry(type, 0, line, column, initValue)});
        } else if (type.getTypeTree()->getNodeType() == BaseType::Function) {
            // function
            entries.insert({symbol, SymTabEntry(type, 0, line, column, initValue)});
            params[symbol];
            offsetMap[symbol];
        } else {
            auto pos = symbol.find_first_of('@');
            auto funcName = symbol.substr(0, pos);
            if (isArray) {
                size_t baseTypeSize = type.getTypeTree()->getBaseNodeSize();
                auto elements = type.getTypeTree()->getSize() / baseTypeSize;
                offsetMap[funcName].add(baseTypeSize, elements);
                entries.insert({symbol, SymTabEntry(type, offsetMap[funcName].get(), line, column, initValue)});
            } else {
                auto typeSize = type.getTypeTree()->getSize();
                offsetMap[funcName].add(typeSize, 1);
                entries.insert({symbol, SymTabEntry(type, offsetMap[funcName].get(), line, column, initValue)});
            }
            if (isParam)
                params[funcName].push_back(symbol);
        }
        entries[symbol].name = symbol;
    }
}

void SymTab::Offsets::add(size_t singleSize, size_t count) { // alignment = singleSize = 1,2,4,8,...
    auto align = offsetInWord % singleSize; // 0 -- has been aligned, others -- need to be aligned
    offsetInWord += align ? singleSize - align : 0;
    offsetInWord += singleSize * count;
    words += offsetInWord / WORD_BYTES;
    offsetInWord %= WORD_BYTES;
}

size_t SymTab::Offsets::get() const {
    return words * WORD_BYTES + offsetInWord;
}

void SymTab::Offsets::align() {
    offsetInWord = 0;
    words++;
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
            std::cout << " return type:[" << getTypeStr(funcType->getBaseType()) << "]\t\t";
        }
        std::cout << " offset:[" << entry.second.offset << "]\t\t";

        if (entry.second.initValue != nullptr) {
            std::cout << " init value:[" << entry.second.initValue->getText() << "]\t\t";
        }

        if (entry.second.type.isTypedef())
            std::cout << "(typedef)";
        std::cout << std::endl;
    }

    std::cout << "offset:" << std::endl;
    for (const auto&[key, value]:offsetMap) {
        std::cout << "func:" << key << ", offset:" << value.get() << std::endl;
    }
}

size_t SymTab::getTotalOffset(const string &funcName) {
    return offsetMap[funcName].get();
}

vector<string> SymTab::getParamNames(const string &funcName) {
    return params[funcName];
}

size_t SymTab::getSize(const string &symbol) {
    auto result = entries.find(symbol);
    if (result != entries.end())
        return result->second.type.getSize();
    else {
        throw UnDef(symbol);
    }
}

SymTab::SymTab() {
    add("printChar", CType(std::make_shared<FunctionTypeNode>(
            CTypeBasePtr(new SimpleTypeNode(BaseType::Void)),
            vector<CTypeBasePtr>{
                    CTypeBasePtr(new SimpleTypeNode(BaseType::SChar))
            })), 0, 0);

    add("printString", CType(std::make_shared<FunctionTypeNode>(
            CTypeBasePtr(new SimpleTypeNode(BaseType::Void)),
            vector<CTypeBasePtr>{
                    CTypeBasePtr(getPointerType(static_cast<CTypeBasePtr>(new SimpleTypeNode(BaseType::SChar))))
            })), 0, 0);

    add("printInt", CType(std::make_shared<FunctionTypeNode>(
            CTypeBasePtr(new SimpleTypeNode(BaseType::Void)),
            vector<CTypeBasePtr>{
                    CTypeBasePtr(new SimpleTypeNode(BaseType::SInt))
            })), 0, 0);
}

void SymTab::align() {
    for (auto&[key, value]:offsetMap) {
        if (value.get() % WORD_BYTES != 0) {
            value.align();
        }
    }
}

