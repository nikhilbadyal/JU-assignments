//
// Created by Nikhil on 01-05-2021.
//
#include <vector>
#include "Lex.h"
#include <algorithm>
#include <iostream>

Token Lex::analyze() {
    while (isspace(*curToken)) {
        curToken++;
    }
    if (isalpha(*curToken)) {
        return Keyword();
    } else if (isdigit(*curToken)) {
        return Digit();
    } else if (operators.find(*curToken) != std::string::npos) {
        return Operator();
    } else if (*curToken == '\'') {
        return String();
    } else if (symbols.find(*curToken) != std::string::npos) {
        return Symbol();
    } else {
        throw std::invalid_argument("Wrong input query");
    }
}

/*
std::vector<Token> Lex::analyze() {
    std::vector<Token> analyzed;
    while (*curToken != '\0') {
        while (isspace(*curToken)) {
            curToken++;
        }
        if (isalpha(*curToken)) {
            analyzed.push_back(Keyword());
        } else if (isdigit(*curToken)) {
            analyzed.push_back(Digit());
        } else if (operators.find(*curToken) != std::string::npos) {
            analyzed.push_back(Operator());
        } else if (*curToken == '\'') {
            analyzed.push_back(String());
        } else if (symbols.find(*curToken) != std::string::npos) {
            analyzed.push_back(Symbol());
        } else {
            throw std::invalid_argument("Wrong input query");
        }
    }
    return analyzed;
}*/

Token Lex::Keyword() {
    int i;
    for (i = 0; isalnum(*curToken); ++curToken) {
        temp[i++] = *curToken;
    }
    temp[i] = '\0';
    std::string s = std::string(temp);
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    if (auto itr = keywords.find(s); itr != keywords.end()) {
        return Token(itr->first, itr->first);
    } else {
        return Token("ID", s);
    }
}

Token Lex::Digit() {
    int i;
    int flag = 1;
    for (i = 0; isdigit(*curToken) || *curToken == '.'; ++curToken) {
        if (*curToken == '.') {
            if (flag) {
                flag = 0;
            } else {
                break;
                //Error digit has 2 decimals
            }
        }
        temp[i++] = *curToken;

    }
    temp[i] = '\0';
    return Token("NUM", temp);
}

Token Lex::Operator() {
    if (*curToken == '<' || *curToken == '>') {
        if (*(curToken + 1) == '=') {
            temp[0] = *curToken;
            temp[1] = *(++curToken);
            temp[2] = '\0';
        } else {
            temp[0] = *curToken;
            temp[1] = '\0';
        }
        curToken++;
        return Token("OP", temp);
    } else {
        temp[0] = *curToken;
        temp[1] = '\0';
        curToken++;
        return Token("OP", temp);
    }
}

Token Lex::String() {
    int i;
    curToken++;
    for (i = 0; *curToken != '\'' && *curToken != '\0'; ++curToken) {
        temp[i++] = *curToken;
    }
    curToken++;
    temp[i] = '\0';
    return Token("STRING", temp);
}

Token Lex::Symbol() {
    temp[0] = *(curToken++);
    temp[1] = '\0';
    return Token("SYMBOL", temp);
}

void Token::toString() const {
    std::cout << type << "  " << value << std::endl;
}
