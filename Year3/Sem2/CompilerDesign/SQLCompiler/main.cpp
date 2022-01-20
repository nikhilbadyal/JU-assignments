

#include <iostream>
#include <vector>
#include "lexicalAnalyzer/Lex.h"
#include "parser/Parser.cpp"

int main() {
    std::string query = "create database nikhil;";
    /* std::string query = "create table tableName ("
                         "userid int,"
                         "name string,"
                         "email string,"
                         "PRIMARY KEY (userid)"
                         ");";*/
    /*std::string query = "SELECT userid1, name2,"
                        "FROM tableName;";*/
    /* std::string query = "SELECT userid1, name2,"
                         "FROM tableName where userid1 = 23;";*/
    /*std::string query = "SELECT userid1, name2,"
                        "FROM tableName where userid1 > 23;";*/
    /* std::string query = "SELECT userid1, name2,"
                         "FROM tableName where userid1 >= 23;";*/
    /*std::string query = "SELECT userid1, name2,"
                        "FROM tableName where userid1 < 23;";*/
    /*std::string query = "SELECT userid1, name2,"
                        "FROM tableName where userid1 <= 23;";*/
    /* std::string query = "SELECT userid1, name2,"
                         "FROM tableName where userid1 between 23 and 24;";*/
    /*std::string query = "SELECT userid1, name2,"
                        "FROM tableName where userid1 in ('1','2','3');";*/
    /* std::string query = "INSERT INTO tableName "
                         "VALUES (value1, value2, value3);";*/
    /*  std::string query = "SELECT column1, column2"
                          "FROM tableName"
                          "WHERE column1 LIKE pattern;";*/

    auto lex = Lex(query);
//    auto table = lex.analyze();
    auto parser = Parser(lex);
    parser.parse();

    return 0;
}
