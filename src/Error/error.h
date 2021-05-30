//
// Created by ybc on 2021/5/27.
//

#ifndef MYCC_ERROR_H
#define MYCC_ERROR_H

#include <stdexcept>
#include "utilities.h"

class Error : public std::exception {
protected:
    string content;
public:
    const char *what() const noexcept override { return content.c_str(); }

    explicit Error(const char *content) : content(content) {}
};


class ReDef : public Error {
public:
    explicit ReDef(const string &symbol) : Error(("redefinition :" + symbol).c_str()) {}
};

class UnDef : public Error {
public:
    explicit UnDef(const string &symbol) : Error(("undefined :" + symbol).c_str()) {}
};

class InvalidLvalue : public Error {
public:
    explicit InvalidLvalue(const string &ctx) : Error(("not a left value:" + ctx).c_str()) {}
};

#endif //MYCC_ERROR_H
