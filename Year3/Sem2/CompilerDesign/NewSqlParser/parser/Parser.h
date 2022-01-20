#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-nodiscard"


#ifndef NEWSQLPARSER_PARSER_H
#define NEWSQLPARSER_PARSER_H

#include <utility>

#include "../lexer/Lexer.h"
#include "../lexer/Token.h"

enum SqlType {
    DML,
    DDL
};

class Parser {

public:
    explicit Parser(Lexer &lexer) : lexer(lexer), lookAhead(lexer.advance()),
                                    columnNumber(lexer.getColumnNumber()), lineNumber(lexer.getLineNumber()) {
    }

    void parseQuery();
private:

    Lexer &lexer;
    Token lookAhead;
    int columnNumber;
    int lineNumber;

    std::vector<std::string> dataTypes{"int", "char", "varchar", "text", "default",
                                       " bool", "float", "double"," date","string"};


    std::vector<std::string> columnConstrainsVal{"null", "not", "primary", "unique", "auto_increment",
                                                 "default", "comments"};

    std::vector<Type> comparisonOpr {
            EQ,GT,LT,
    };

    std::vector<std::string> createTableColumnList ;

    bool match(Type) const;

    SqlType getStatementType() const;

    void sqlStatement();

    void eat(Type);


    void sqlStatements();

    void ddlStatement();

    void dmlStatement();

    void advance();

    void createTable();

    void createDatabase();

    void selectQuery();

    void insertQuery();

    void ifNotExist();

    std::string uid();

    void createTableDefinitions();

    void createDbOptions();

    void selectElements();

    void fromClause() ;

    void groupByClause() const ;

    void orderByClause() const ;

    void limitClause() const ;

    void insertOptions();

    void createTableDefination();

    void columnDef();

    void tableOptions();

    void dataType();

    void columnConstrains();

    void into();

    void columnList();

    void insertList();

    void choice();

    void selectElement();

    void whereClause();

    void expression();

    void predicate();

    void selectList();

    std::string likeUid();

    void atomicVal();
};

#endif //NEWSQLPARSER_PARSER_H
