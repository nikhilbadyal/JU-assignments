

#include <stdexcept>
#include <algorithm>
#include <iostream>
#include "Lexer.h"


class LexerException : public std::exception {
    std::string errorMsg;
public:
    explicit LexerException(std::string errorMsg) : errorMsg(std::move(errorMsg)) {}

    [[nodiscard]] const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
        return errorMsg.c_str();
    }
};

Token Lexer::advance() {
    while (isspace(*curToken)) { //Space
        columnNumber++;
        curToken++;
    }
    if (isalpha(*curToken) || *curToken == '_') {  // Keyword or ID
        return Keyword();
    } else if (singleOperator.find(*curToken) != singleOperator.end()) {
        return Token(singleOperator[*curToken++]);
    }else if (isdigit(*curToken)) { //Number
        return Digit();
    } else if (isOperator()) { //Operator
        return Operator();
    } else {
        throw LexerException("Invalid input query");
    }
}


Token Lexer::Keyword() {
    int i;
    for (i = 0; isalnum(*curToken) || *curToken == '_'; ++curToken) {
        columnNumber++;
        temp[i++] = *curToken;
    }
    temp[i] = '\0';
    std::string s = std::string(temp);
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    if (auto itr = keywords.find(s);itr != keywords.end()) {
        return Token(itr->second, itr->first);
    } else {
        return Token(ID, s);
    }
}

Token Lexer::Digit() {
    int i;
    int flag = 1;
    for (i = 0; isdigit(*curToken) || *curToken == '.'; ++curToken) {
        columnNumber++;

        if (*curToken == '.') {
            if (flag) {
                flag = 0;
            } else {
                break;
                //TODO Error digit has 2 decimals
            }
        }
        temp[i++] = *curToken;

    }
    temp[i] = '\0';
    return Token(NUM, temp);
}

Token Lexer::Operator() {
    int i = 0;
    do {
        columnNumber++;

        temp[i++] = *curToken;
        curToken++;
    } while (isOperator() && i != 2);
    std::string str(temp);
    return Token(operators[str]);
}

void Lexer::initReserve() {
    keywords["num"]= NUM;
    keywords["create"] = CREATE;
    keywords["table"] = TABLE;
    keywords["default"] = DEFAULT;
    keywords["primary"] = PRIMARY;
    keywords["key"] = KEY;
    keywords["insert"] = INSERT;
    keywords["into"] = INTO;
    keywords["values"] = VALUES;
    keywords["select"] = SELECT;
    keywords["assign"] = ASSIGN;
    keywords["lt"] = LT;
    keywords["gt"] = GT;
    keywords["neq"] = NEQ;
    keywords["eq"] = EQ;
    keywords["geq"] = GEQ;
    keywords["leq"] = LEQ;
    keywords["plus"] = PLUS;
    keywords["minus"] = MINUS;
    keywords["mul"] = MUL;
    keywords["div"] = DIV;
    keywords["and"] = AND;
    keywords["or"] = OR;
    keywords["not"] = NOT;
    keywords["l_paren"] = L_PAREN;
    keywords["r_paren"] =R_PAREN;
    keywords["comma"] = COMMA;
    keywords["semicolon"] = SEMICOLON;
    keywords["database"] = DATABASE;
    keywords["schema"] = SCHEMA;
    keywords["temporary"] = TEMPORARY;
    keywords["if"] = IF;
    keywords["exists"] = EXISTS;
    keywords["foreign"] = FOREIGN;
    keywords["collate"] = COLLATE;
    keywords["encryption"] = ENCRYPTION;
    keywords["y"] = Y;
    keywords["n"] = N;
    keywords["unique"] = UNIQUE;
    keywords["auto_increment"] = AUTO_INCREMENT;
    keywords["comment"] = COMMENT;
    keywords["star"] = STAR;
    keywords["from"] = FROM;
    keywords["where"] = WHERE;
    keywords["between"] = BETWEEN;
    keywords["in"] = IN;
    keywords["like"] = LIKE;

    /* keywords["table"] = TABLE;
     keywords["table"] = TABLE;
     keywords["table"] = TABLE;
     keywords["table"] = TABLE;
     keywords["table"] = TABLE;
     keywords["table"] = TABLE;*/



    singleOperator['+'] = PLUS;
    singleOperator['-'] = MINUS;
    singleOperator['*'] = MUL;
    singleOperator['/'] = DIV;
    singleOperator['('] = L_PAREN;
    singleOperator[')'] = R_PAREN;
    singleOperator[','] = COMMA;
    singleOperator[';'] = SEMICOLON;
    singleOperator['='] = EQ;
    singleOperator['<'] = LT;
    singleOperator['>'] = GT;
    singleOperator['\''] = SINGLE_QUOTE;
    singleOperator['%'] = PERCENT;
    singleOperator['_'] = UNDER_SCORE;

    operators["&&"] = AND;
    operators["||"] = OR;
    operators["!"] = NOT;
    operators["<"] = LT;
    operators[">"] = GT;
    operators["<>"] = NEQ;
    operators["="] = ASSIGN;
    operators["=="] = EQ;
    operators[">="] = GEQ;
    operators["<="] = LEQ;
    operators["+"] = PLUS;
    operators["-"] = MINUS;
    operators["*"] = MUL;
    operators["/"] = DIV;
    operators["("] = L_PAREN;
    operators[")"] = R_PAREN;
    operators[","] = COMMA;
    operators[";"] = SEMICOLON;

}

bool Lexer::isOperator() const {
    return *curToken == '&' || *curToken == '|' || *curToken == '!' || *curToken == '<'
           || *curToken == '>' || *curToken == '=' || *curToken == '+' || *curToken == '-'
           || *curToken == '*' || *curToken == '/' || *curToken == '(' || *curToken == ')'
           || *curToken == ',' || *curToken == ';';
}
