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
    explicit ReDef(const string &symbol) : Error(("redefinition: " + symbol).c_str()) {}
};

class UnDef : public Error {
public:
    explicit UnDef(const string &symbol) : Error(("undefined: " + symbol).c_str()) {}
};

class InvalidLvalue : public Error {
public:
    explicit InvalidLvalue(const string &ctx) : Error(("not a left value: " + ctx).c_str()) {}
};

class InvalidBreak : public Error {
public:
    explicit InvalidBreak(const string &ctx = "") : Error(
            ("break statement not within loop or switch." + ctx).c_str()) {}
};

class InvalidContinue : public Error {
public:
    explicit InvalidContinue(const string &ctx = "") : Error(("continue statement not within a loop." + ctx).c_str()) {}
};

class InvalidFuncCall : public Error {
public:
    explicit InvalidFuncCall(const string &ctx = "") : Error(("invalid function call: " + ctx).c_str()) {}
};

class NonConstGlobalVar : public Error {
public:
    explicit NonConstGlobalVar(const string &symbol) : Error(
            ("initializer element of " + symbol + " is not constant").c_str()) {}
};

class IncompatibleType : public Error {
public:
    explicit IncompatibleType(const string &ctx = "") : Error(("Incompatible type: " + ctx).c_str()) {}
};

class NotImplement : public Error {
public:
    explicit NotImplement(const string &ctx = "") : Error(("not implement: " + ctx).c_str()) {}
};

class InvalidDereference : public Error {
public:
    explicit InvalidDereference(const string &ctx = "") : Error(("invalid dereference: " + ctx).c_str()) {}
};

#endif //MYCC_ERROR_H
