cmake_minimum_required(VERSION 3.20)
project(NewSqlParser)

set(CMAKE_CXX_STANDARD 17)

add_executable(NewSqlParser main.cpp parser/Parser.cpp parser/Parser.h
        lexer/Lexer.cpp lexer/Lexer.h lexer/Token.cpp lexer/Token.h tryr.h)