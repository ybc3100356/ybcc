//
// Created by ybc on 2021/5/27.
//

#ifndef MYCC_ERROR_H
#define MYCC_ERROR_H

#include <stdexcept>
#include <string>

using std::string;

class ReDefError : public std::exception {
    string content;
public:
    const char *what() const noexcept override { return content.c_str(); }

    explicit ReDefError(const char *content) : content(content) {}
};

class UnDefError : public std::exception {
    string content;
public:
    const char *what() const noexcept override { return content.c_str(); }

    explicit UnDefError(const char *content) : content(content) {}
};

#endif //MYCC_ERROR_H
