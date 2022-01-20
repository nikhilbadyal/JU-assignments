//
// Created by Nikhil on 08-05-2021.
//

#include <string>
#include <map>
#include <iostream>
#include <utility>

class Token {
public:
    friend std::ostream &operator<<(std::ostream &os, const Token &token) {
        os << "type: " << token.type;
        return os;
    }

    int type;

    explicit Token(int type, const std::basic_string<char> string) : type(type) {}

    void toString() const;

};

