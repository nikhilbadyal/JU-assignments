#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-nodiscard"


#ifndef NEWSQLPARSER_LEXER_H
#define NEWSQLPARSER_LEXER_H

#include <string>
#include <utility>
#include <map>
#include "Token.h"

constexpr int BUF_SIZE = 256;

class Lexer {
    int lineNumber = 1; // To tell the number line while error
    int columnNumber = 1; //To tell the column number while error
    char temp[BUF_SIZE]{}; // To analyze token/ID/Identifier
    char *curToken;
    std::map<std::string, Type> keywords;
    std::map<char, Type> singleOperator;
    std::map<std::string, Type> operators;


public:
    std::string query;

    void initReserve();

    explicit Lexer(const std::string &query) :
    curToken(const_cast<char *>( query.c_str())), query(query) {
        initReserve();
    }

    int getLineNumber() const {
        return lineNumber;
    }

    int getColumnNumber() const {
        return columnNumber;
    }

    Token advance();


    Token Keyword();

    Token Digit();

    Token Operator();

    bool isOperator() const;

};

#endif //NEWSQLPARSER_LEXER_H