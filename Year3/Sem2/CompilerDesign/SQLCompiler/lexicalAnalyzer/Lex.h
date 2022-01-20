//
// Created by Nikhil on 01-05-2021.
//

#ifndef SQLCOMPILER_LEX_H
#define SQLCOMPILER_LEX_H

#include <string>
#include <map>
#include <cstring>
#include <iostream>
#include <utility>
#include "Token.cpp"


enum QuertType{
    DML
};


class Lex {

public:
    explicit Lex(const std::string &query) :
            curToken(const_cast<char *>( query.c_str())) {
    }

private:
//    std::string query;
    char *curToken;
    char temp[40]{};
    const std::string symbols = "(),;";
    const std::string operators = "<>=";

    std::map<std::string, int> keywords{
            {"insert",  1},
            {"select",  2},
            {"create",  3},
            {"table",   4},
            {"like",    5},
            {"between", 6},
            {"in",      7},
            {"into",    8},
            {"values",  9},

    };

public:
    Token analyze();


    Token Keyword();

    Token Digit();

    Token Operator();

    Token String();

    Token Symbol();


};

#endif //SQLCOMPILER_LEX_H
