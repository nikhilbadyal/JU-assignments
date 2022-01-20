//----------------------------------------------------------------------------
//----A decent library of string functions for NameAge programs
//----------------------------------------------------------------------------
#ifndef MYSTRLIB_H
#define MYSTRLIB_H
//----------------------------------------------------------------------------
#include "boolean.h"

//----Define string data type
const int MAX_STRING_SIZE = 80;
typedef char string[MAX_STRING_SIZE];
//----------------------------------------------------------------------------
//----Check if a string is an integer
boolean IsInteger(string AString);

//----Convert a string to an integer
int ToInteger(string AString);

//----Reads a string and returns TRUE if successful
boolean ReadString(string& AString);

//----Concatenate two strings if not too long
boolean Concatenate(string& AString1,string AString2);

//----Checks if first string is lexicographically greater than the second
boolean StringGreater(string AString1,string AString2);

//----Checks if first string is the same as the second
boolean StringEqual(string AString1,string AString2);

//----Checks if first string is lexicographically smaller than the second
boolean StringSmaller(string AString1,string AString2);
//----------------------------------------------------------------------------
#endif
//----------------------------------------------------------------------------
