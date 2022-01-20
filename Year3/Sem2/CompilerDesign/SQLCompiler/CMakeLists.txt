cmake_minimum_required(VERSION 3.20)
project(SQLCompiler)

set(CMAKE_CXX_STANDARD 17)

add_executable(SQLCompiler main.cpp lexicalAnalyzer/Lex.cpp parser/Parser.cpp lexicalAnalyzer/Tag.cpp lexicalAnalyzer/Token.cpp lexicalAnalyzer/Word.cpp lexicalAnalyzer/Word.h)