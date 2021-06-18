//
// Created by ybc on 2021/5/27.
//

#ifndef MYCC_SYMTAB_H
#define MYCC_SYMTAB_H

#include <utility>
#include <queue>

#include "CParser.h"

#include "type.h"
#include "error.h"
#include "utilities.h"

using InitValuePtr = CParser::InitializerContext *;
using std::queue;

class SymTabEntry {
public:
    explicit SymTabEntry(CType type = CType(), size_t offset = 0, size_t line = 0, size_t column = 0,
                         InitValuePtr initValue = InitValuePtr())
            : type(std::move(type)), offset(offset), line(line), column(column), initValue(initValue) {}

    InitValuePtr initValue;   // init value ctx
    size_t offset;  // offset in the local var area of stack
    size_t line;    // line number of this symbol
    size_t column;  // column number of this symbol
    string name;
    CType type;
};

class SymTab {
    unordered_map<string, SymTabEntry> entries;
    unordered_map<string, vector<string>> params;
    queue<CTypeBasePtr> typeQueue;

    class Offsets {
        size_t words;           // counter
        size_t offsetInWord;    // counter
    public:
        // add a symbol, singleSize: bytes
        void add(size_t singleSize, size_t count);

        size_t get() const;

        void align();
    };

    unordered_map<string, Offsets> offsetMap; // func <-> offset

public:
    CTypeBasePtr getTypeFromQueue() {
        auto result = typeQueue.front();
        typeQueue.pop();
        return result;
    }

    void saveTypeToQueue(const CTypeBasePtr &type) {
        typeQueue.push(type);
    }

    static SymTab &getInstance() {
        static SymTab instance;
        return instance;
    }

    void show();

    void add(const string &symbol, const CType &type, size_t line, size_t column,
             InitValuePtr initValue = InitValuePtr(), bool isParam = false, bool isArray = false);

    void align();

    const SymTabEntry &get(const string &name, size_t line = -1, size_t column = -1);

    size_t getSize(const string &symbol);

    // function
    size_t getTotalOffset(const string &funcName);

    vector<string> getParamNames(const string &funcName);

private:
    SymTab();

public:
    SymTab(SymTab const &) = delete;

    void operator=(SymTab const &) = delete;
};


#endif //MYCC_SYMTAB_H
