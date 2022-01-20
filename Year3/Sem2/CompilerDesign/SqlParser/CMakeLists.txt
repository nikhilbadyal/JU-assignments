cmake_minimum_required(VERSION 3.20)
project(SqlParser)

set(CMAKE_CXX_STANDARD 17)

add_executable(SqlParser main.cpp lexer/Lexer.cpp lexer/Word.cpp lexer/Token.cpp lexer/Tags.cpp)