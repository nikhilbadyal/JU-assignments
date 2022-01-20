

#ifndef NEWSQLPARSER_TOKEN_H
#define NEWSQLPARSER_TOKEN_H


#include <string>
#include <utility>
#include <vector>

enum Type {
    ID, NUM, CREATE, TABLE, INT, CHAR, VARCHAR, TEXT, DEFAULT,
    BOOL, FLOAT, DOUBLE, DATE, PRIMARY, KEY, INSERT,
    INTO, VALUES, DELETE, FROM, WHERE, SELECT, ASSIGN, LT, GT, NEQ, EQ,
    GEQ, LEQ, PLUS, MINUS, MUL, DIV, AND, OR, NOT, L_PAREN, R_PAREN,
    COMMA, SEMICOLON, END, NONE, DATABASE, SCHEMA, TEMPORARY, IF,
    EXISTS, FOREIGN, LIKE, BETWEEN, IN, COLLATE, ENCRYPTION, Y,
    N, UNIQUE, AUTO_INCREMENT, COMMENT, STAR, SINGLE_QUOTE,PERCENT,UNDER_SCORE
};


class Token {
public:
    virtual ~Token();

    explicit Token(Type type, std::string value = "") : type(type), value(std::move(value)) {}

    Token(const Token &other);

    Type type;
    std::string value;

    int getNumber() const ;

    std::string getId() const ;


};

#endif //NEWSQLPARSER_TOKEN_H
