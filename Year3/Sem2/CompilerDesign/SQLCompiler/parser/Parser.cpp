//
// Created by Nikhil on 06-05-2021.
//

#include <utility>

#include "../lexicalAnalyzer/Lex.h"

class Parser {
    Lex lex;
    Token look;
public:
    explicit Parser(Lex lex) : lex(std::move(lex)) {
        advance();
    }

    void advance() {
        look = lex.analyze();
    }

    void createTableDefination() const {

    }

    void createTable() const {
        match("CREATE");
        match("TEMPERORY");
        match("TABLE");
        ifNotExist();
        std::string tableName = uid();
        createTableDefination();
    }

    void match(const char *string) const {

    }

    void dbFormat() const {

    }

    void ifNotExist() const {

    }

    std::string uid() const {


    }

    void createDboptions() const {

    }

    void createDatabase() const {
        match("CREATE");
        dbFormat();
        ifNotExist();
        std::string dbName = uid();
        createDboptions();
    }

    void ddlStatement() const {
        if (look.type == "DB") {
            createDatabase();

        } else if (look.type == "CT") {
            createTable();
        }
    }

    void selectElement() const {
        if (look.type == "COL_NAME") {

        } else {
            // throw error
        }
    }

    void selectElements() const {
        if (look.type == "STAR") {

        } else {
            selectElement();
        }
    }

    void whereClause() const {

    }

    void fromClause() const {
        match("FROM");
        std::string table_name = uid();
        whereClause();
    }

    void groupByItem() const {

    }

    void groupByClause() const {
        match("GROUP");
        match("BY");
        groupByItem();
    }

    void orderByExpression() const {

    }

    void orderByClause() const {
        match("ORDER");
        match("BY");
        orderByExpression();
    }

    void limitClause() const {
        match("LIMIT");
        match("INT");

    }

    void selectQuery() const {
        match("SELECT");
        selectElements();
        fromClause();
        groupByClause();
        orderByClause();
        limitClause();

    }

    void dmlStatement() const {
        if (look.type == "Select") {
            selectQuery();
        } else if (look.type == "INSERT") {
        }
    }

    void sqlStatement() const {
        if (look.type == "DDL") {
            ddlStatement();

        } else if (look.type == "DML") {
            dmlStatement();

        }
    }

    void emptyStatement() const {

    }

    void sqlStatements() const {
        if (look.type == "CREATE" || look.) {
            sqlStatement();
        } else {
            emptyStatement();
        }
    }

    void parse() const {
        sqlStatements();
    }


};

