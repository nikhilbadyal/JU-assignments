#include <iostream>
#include "parser/Parser.h"

int main() {

//    std::string query = "create database cp_project ;";
//    std::string query = "create database cp_project";
//    std::string query = "create schema cp_project;";
//    std::string query = "create database cp_project;";
//    std::string query = "create database IF NOT EXISTS cp_project;";
//    std::string query = "create schema IF NOT EXISTS cp_project;";
//    std::string query = "create schema cp_project ;";
      /* std::string query = "create table a ("
                          "a int,"
                          "PRIMARY KEY ( a )"
                          ");";*/

   /*   std::string query = "SELECT userid1, name2 ."
                          "FROM tableName where userid1 NOTO 20;";*/
    /* std::string query = "SELECT userid1, name2 "
                        "FROM tableName where userid1 LIKE 10 AND 20;";*/
   /* std::string query = "SELECT userid1, name2 "
                        "FROM tableName where userid1 BETWEEN 10 AND 20;";*/
    /* std::string query = "SELECT userid1, name2 "
                       "FROM tableName where userid1 BETWEEN 'Nikhil' AND 'Aikhil';";*/
    /* std::string query = "SELECT userid1, name2 "
                         "FROM tableName where userid1 BETWEENO 'Nikhil' AND 'Aikhil';";*/
    /* std::string query = "SELECT userid1, name2 "
                         "FROM tableName where userid1 "
                         "AND 23;";*/
    /*  std::string query = "SELECT userid1, name2 "
                          "FROM tableName where userid1 "
                          "AND 23;";*/
    /* std::string query = "SELECT userid1, name2 "
                         "FROM tableName where userid1 > 23;";*/
    /*  std::string query = "SELECT userid1, name2 "
                          "FROM tableName where userid1 >= 23;";*/
    /*std::string query = "SELECT userid1, name2 "
                        "FROM tableName where userid1 <= 23;";*/
   /* std::string query = "SELECT * from table_name;";*/
    /*std::string query = "SELECT userid1, name2 "
                        "FROM tableName where userid1 NOT 23;";*/
    /* std::string query = "SELECT userid1, name2 "
                         "FROM tableName where userid1 <= 23;";*/
     std::string query = "SELECT userid1, name2 "
                         "FROM tableName where userid1 between 23 and 24;";
    /* std::string query = "SELECT userid1, name2 "
                         "FROM tableName where userid1 in ('1','2','3');";*/
    /* std::string query = "SELECT userid1, name2 "
                         "FROM tableName where userid1 LIKE '%__nikhil%%___';";*/

    /*  std::string query = "INSERT INTO table_name (column1, column2, column3) "
                          "VALUES (value1, value2, value3);";*/

     /* std::string query = "INSERT INTO table_name "
                          "VALUES (value1, value2, value3);";*/

    std::cout<<"You query has error \n"+ query;
    auto lexer = Lexer(query);
    Parser parser = Parser(lexer);
    parser.parseQuery();
//    std::cout << "You ran a correct Query\n\n"+query;

    return 0;
}
