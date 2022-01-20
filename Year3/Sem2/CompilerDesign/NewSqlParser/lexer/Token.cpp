

#include "Token.h"
#include <string>

Token::Token(const Token &other) {
    type = other.type;
    value = other.value;
}

Token::~Token() {

}

int Token::getNumber() const {
    return 0;
}

std::string Token::getId() const {
    return nullptr;
}

