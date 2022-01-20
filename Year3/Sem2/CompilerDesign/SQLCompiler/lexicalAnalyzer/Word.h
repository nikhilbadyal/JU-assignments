//
// Created by Nikhil on 08-05-2021.
//

#ifndef SQLCOMPILER_WORD_H
#define SQLCOMPILER_WORD_H

//
// Created by Nikhil on 07-05-2021.
//

#include <utility>

#include "Lex.h"
#include "Tag.cpp"

class Word : public Token {
public:

    Word(std::string lexeme, int tag) : Token(tag, std::basic_string<char>()), lexeme(std::move(lexeme)) {}

    std::string lexeme;
    static Word CREATE, DATABASE, SCHEMA,
            IF, NOT, EXIST, COLLATE,
            ENCRYPTION, Y, N, TEMPERORY,
            TABLE, PRIMARY, KEY,
            UNIQUE, AUTO_INCREMENT, DEFAULT,
            COMMENT, FOREIGN, SELECT, FROM,
            WHERE, GROUP, BY, ASC, DSC,
            ORDER, LIMIT, INSERT, INTO,
            VALUES, LIKE, BETWEEN, AND, OR;


};

//TODO add null

#endif //SQLCOMPILER_WORD_H
