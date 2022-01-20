

#include "Parser.h"

#include <utility>
#include <iostream>
#include <algorithm>

class ParserException : public std::exception {
    std::string errorMsg;
public:
    explicit ParserException(std::string errorMsg) : errorMsg(std::move(errorMsg)) {}

    [[nodiscard]] const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
        return errorMsg.c_str();
    }
};


void Parser::sqlStatement() {
    auto statementType = getStatementType();
    if (statementType == DDL) {
        ddlStatement();
    } else {
        dmlStatement();
    }
}

void Parser::ddlStatement() {
    if (match(CREATE)) {
        eat(CREATE);
        if (lookAhead.type == DATABASE || lookAhead.type == SCHEMA) {
            createDatabase();
        } else if (lookAhead.type == TABLE || lookAhead.type == TEMPORARY) {
            if (lookAhead.type == TEMPORARY) {
                eat(TEMPORARY);
            }
            createTable();
        } else {
            throw ParserException(
                    "Only CREATE TABLE AND CREATE DATABASE are valid DDL statements. Error  in line no " +
                    std::to_string(lineNumber) + " and column number " + std::to_string(columnNumber));
        }
    } else {
        throw ParserException("Only CREATE DDL Statement is supported. Error in line no " + std::to_string(lineNumber) +
                              " and column number " + std::to_string(columnNumber));
    }
}

void Parser::dmlStatement() {
    if (match(SELECT)) {
        selectQuery();
    } else if (match(INSERT)) {
        insertQuery();
    } else {
        throw ParserException(
                "Only SELECT & INSERT DML Statements are supported in line no " + std::to_string(lineNumber) +
                " and column number " + std::to_string(columnNumber));
    }

}

void Parser::createTable() {
    if (match(TABLE)) {
        eat(TABLE);
        ifNotExist();
        std::string tableName = uid();
        createTableDefinitions();
    } else {
        throw ParserException("Syntax Error in line no " + std::to_string(lineNumber) + " and column number " +
                              std::to_string(columnNumber));
    }
}

void Parser::createDatabase() {
    if (match(DATABASE)) {
        eat(DATABASE);
    } else if (match(SCHEMA)) {
        eat(SCHEMA);
    } else {
        throw ParserException("Syntax Error in line no " + std::to_string(lineNumber) + " and column number " +
                              std::to_string(columnNumber));
    }
    ifNotExist();
    std::string dbName = uid();
    createDbOptions();
    eat(SEMICOLON);
}

void Parser::selectQuery() {
    if (match(SELECT)) {
        eat(SELECT);
        selectElements();
        fromClause();
        groupByClause();
        orderByClause();
        limitClause();
        match(SEMICOLON);
    } else {
        throw ParserException("Syntax Error in line no " + std::to_string(lineNumber) + " and column number " +
                              std::to_string(columnNumber));

    }
}

void Parser::insertQuery() {
    if (match(INSERT)) {
        eat(INSERT);
        into();
        std::string tableName = uid();
        insertOptions();
    } else {
        throw ParserException("Syntax Error in line no " + std::to_string(lineNumber) + " and column number " +
                              std::to_string(columnNumber));
    }
}

void Parser::eat(Type type) {
    if (match(type)) {
        advance();
    } else {
        throw ParserException("Syntax Error in line no " + std::to_string(lineNumber) + " and column number " +
                              std::to_string(columnNumber));

    }

}

void Parser::ifNotExist() {
    if (match(IF)) {
        eat(IF);
        if (match(NOT)) {
            eat(NOT);
            if (match(EXISTS)) {
                eat(EXISTS);
            } else {
                throw ParserException("Syntax Error in line no " + std::to_string(lineNumber) + " and column number " +
                                      std::to_string(columnNumber));
            }
        } else {
            throw ParserException("Syntax Error in line no " + std::to_string(lineNumber) + " and column number " +
                                  std::to_string(columnNumber));
        }
    }
}

std::string Parser::uid() {
    auto flag = match(SINGLE_QUOTE);  // Nikhil 'Nikhil'  25
    if (flag) {
        eat(SINGLE_QUOTE);
    }
    if (match(ID) || match(NUM)) {
        auto str = lookAhead.value; //a

        eat(lookAhead.type);
        if (flag) {
            eat(SINGLE_QUOTE);
        }
        return str;
    } else {
        throw ParserException("Syntax Error in line no " + std::to_string(lineNumber) + " and column number " +
                              std::to_string(columnNumber));
    }
}

void Parser::createTableDefinitions() {
    eat(L_PAREN);
    createTableDefination();
    while (match(COMMA)) {
        eat(COMMA);
        createTableDefination();
    }
    eat(R_PAREN);

}

void Parser::createDbOptions() {
    if (match(COLLATE)) {
        eat(COLLATE);
        std::string col_name = uid();

    } else if (match(ENCRYPTION)) {
        eat(ENCRYPTION);
        choice();

    }
}


void Parser::selectElements() {
    if (match(MUL)) {
        eat(MUL);
    } else if (match(ID)) {
        selectElement();
        while (match(COMMA)) {
            eat(COMMA);
            selectElement();
        }

    } else {
        throw ParserException("Syntax Error in line no " + std::to_string(lineNumber) + " and column number " +
                              std::to_string(columnNumber));
    }

}

void Parser::fromClause() {
    if (match(FROM)) {
        eat(FROM);
        std::string tableName = uid();
        whereClause();
    } else {
        throw ParserException("Syntax Error in line no " + std::to_string(lineNumber) + " and column number " +
                              std::to_string(columnNumber));
    }

}

void Parser::groupByClause() const {
    // Implement this

}

void Parser::orderByClause() const {
    // Implement this

}

void Parser::limitClause() const {
    // Implement this
}

void Parser::insertOptions() {
    columnList();
    if (match(VALUES)) {
        eat(VALUES);
        insertList();
    } else {
        throw ParserException("Syntax Error in line no " + std::to_string(lineNumber) + " and column number " +
                              std::to_string(columnNumber));
    }

}

SqlType Parser::getStatementType() const {
    if (lookAhead.type == CREATE) {
        return DDL;
    } else if (lookAhead.type == INSERT || lookAhead.type == SELECT) {
        return DML;
    } else {
        throw ParserException(
                "Sql statement must be DDL or DML statements Error  in line no " + std::to_string(lineNumber) +
                " and column number " + std::to_string(columnNumber));
    }
}

void Parser::sqlStatements() {
    if (lexer.query.empty() || lexer.query.size() == 1) {
        throw ParserException("Enter Something");
    } else {
        sqlStatement();
    }
}

void Parser::parseQuery() {
    sqlStatements();
}

void Parser::createTableDefination() {
    if (match(ID)) {
        createTableColumnList.push_back(uid());
        columnDef(); //Data type
    } else if (match(PRIMARY) || match(FOREIGN)) {
        tableOptions();
    } else {
        // TODO throw error
    }

}

void Parser::columnDef() {
    if (auto itr = std::find(dataTypes.begin(), dataTypes.end(), lookAhead.value); itr != dataTypes.end()) {
        eat(lookAhead.type);
        auto it = std::find(columnConstrainsVal.begin(), columnConstrainsVal.end(), lookAhead.value);
        while (it != columnConstrainsVal.end()) {
            switch (lookAhead.type) {
                case NOT: {
                    eat(NOT);
//                eat(NULL); TODO handle not null cases
                    break;
                }
                case PRIMARY: {
                    eat(PRIMARY);
                    eat(KEY);
                    break;
                }
                case UNIQUE: {
                    eat(UNIQUE);
                    if (lookAhead.type == KEY) {
                        eat(KEY);
                    }
                    break;
                }
                case KEY: {
                    eat(KEY);
                    break;
                }
                case AUTO_INCREMENT: {
                    eat(AUTO_INCREMENT);
                    break;
                }
                case DEFAULT: {
                    eat(DEFAULT);
                    // TODO handle default value
                    break;
                }
                case COMMENT: {
                    eat(COMMENT);
                    std::string comment = uid();
                    break;
                }
                default :
                    throw ParserException(
                            "Syntax Error in line no " + std::to_string(lineNumber) + " and column number " +
                            std::to_string(columnNumber));

            }
            it = std::find(columnConstrainsVal.begin(), columnConstrainsVal.end(), lookAhead.value);

        }
    } else {
        throw ParserException("Syntax Error in line no " + std::to_string(lineNumber) + " and column number " +
                              std::to_string(columnNumber));
    }
}

void Parser::tableOptions() {
    if (match(PRIMARY)) {
        eat(PRIMARY);
        eat(KEY);
        eat(L_PAREN);
        std::string columnName = uid();
        if (auto itr = std::find(createTableColumnList.begin(), createTableColumnList.end(), columnName);
                itr == createTableColumnList.end()) {
            throw ParserException("Unknown variable  " + columnName);
        }
        eat(R_PAREN);

    } else if (match(FOREIGN)) {
        eat(FOREIGN);
        eat(KEY);
        eat(L_PAREN);
        std::string columnName = uid();

        eat(R_PAREN);

    } else {
        // TODO throw error
    }

}

void Parser::dataType() {

}

void Parser::columnConstrains() {

}

void Parser::into() {
    if (match(INTO)) {
        eat(INTO);
    }
}

void Parser::columnList() {
    if (match(VALUES)) {
        return;
    }
    eat(L_PAREN);
    std::vector<std::string> columnName;
    columnName.push_back(uid());
    while (match(COMMA)) {
        eat(COMMA);
        columnName.push_back(uid());
    }
    eat(R_PAREN);
}

void Parser::insertList() {
    eat(L_PAREN);

    std::vector<std::string> columnName;
    columnName.push_back(uid());
    while (match(COMMA)) {
        eat(COMMA);
        columnName.push_back(uid());
    }
    eat(R_PAREN);

}

bool Parser::match(Type type) const {
    return lookAhead.type == type;
}

void Parser::advance() {
    lookAhead = lexer.advance();
    columnNumber = lexer.getColumnNumber();
    lineNumber = lexer.getLineNumber();
}

void Parser::choice() {
    if (match(Y)) {
        eat(Y);

    } else if (match(N)) {
        eat(N);
    } else {
        //TODO throw error
    }

}

void Parser::selectElement() {
    if (match(ID)) {
        std::string columnName = uid();
    } else {
        throw ParserException("Syntax Error in line no " + std::to_string(lineNumber) + " and column number " +
                              std::to_string(columnNumber));
    }

}

void Parser::whereClause() {
    if (match(WHERE)) {
        eat(WHERE);
        expression();
    }

}

void Parser::expression() {
    if (match(NOT)) {
        eat(NOT);
        expression();
    } else if (match(ID) || match(SINGLE_QUOTE) || match(NUM)) {
        predicate();
    } else {
        throw ParserException("Syntax Error in line no " + std::to_string(lineNumber) + " and column number " +
                              std::to_string(columnNumber));
    }

}

void Parser::predicate() {
    if (match(ID) || match(NUM) || match(SINGLE_QUOTE)) {
        atomicVal();
    }
    if (lookAhead.type == IN) {
        eat(IN);
        eat(L_PAREN);
        if (match(SELECT)) {
            selectQuery();
        } else {
            selectList();
        }
        eat(R_PAREN);
    } else if (lookAhead.type == LIKE) {
        eat(LIKE);
        eat(SINGLE_QUOTE);
        std::string matchSTr = likeUid();
        eat(SINGLE_QUOTE);

    } else if (lookAhead.type == BETWEEN) {
        eat(BETWEEN);
        uid();
        eat(AND);
        uid();
    } else if (auto itr = std::find(comparisonOpr.begin(), comparisonOpr.end(), lookAhead.type); itr !=
                                                                                                 comparisonOpr.end()) {
        eat(lookAhead.type);
        predicate();
    } else if (match(SEMICOLON)) {
        return;
    } else {
        throw ParserException("Syntax Error in line no " + std::to_string(lineNumber) + " and column number " +
                              std::to_string(columnNumber));
    }
}

void Parser::atomicVal() {
    if (match(NUM)) {
        try {
            auto val = std::stoi(lookAhead.value);
            eat(lookAhead.type);
//            predicate();
        } catch (ParserException e) {
            throw ParserException("Syntax Error in line no " + std::to_string(lineNumber) + " and column number " +
                                  std::to_string(columnNumber));
        }
    } else if (match(ID) || match(SINGLE_QUOTE)) {
        std::string columnName = uid();
//        predicate();
    }
}

void Parser::selectList() {
    if (match(NUM) || match(SINGLE_QUOTE)) {
        std::string value = uid();
        while (match(COMMA)) {
            eat(COMMA);
            value = uid();
        }
    } else {
        throw ParserException("Parsing Error  in line no " + std::to_string(lineNumber) + " and column number " +
                              std::to_string(columnNumber));
    }

}

std::string Parser::likeUid() {
    while (match(PERCENT) || match(UNDER_SCORE)) {
        eat(lookAhead.type);
    }
    if (match(ID) || match(NUM)) {
        auto str = lookAhead.value;
        eat(lookAhead.type);
        if (match(SINGLE_QUOTE)) {
            return str;
        }
        likeUid();
        return str;
    } else {
        throw ParserException("Syntax Error in line no " + std::to_string(lineNumber) + " and column number " +
                              std::to_string(columnNumber));
    }
}