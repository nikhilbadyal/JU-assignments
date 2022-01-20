// Library file: strlib.h

#ifndef STRINGLIB_H
#define STRINGLIB_H

#include "boolean.h"
#include "boolean.h"

const int MAX_STRING_SIZE = 21;
typedef char string[MAX_STRING_SIZE];

// Function: string_less
// Tests two strings to see if they the first is less
//
// Inputs: two strings
// Output: Boolean value TRUE, if the first is less, FALSE otherwise
 
boolean string_less(string str1, string str2);

// Function: string_equal
// Tests two strings to see if they are equal
//
// Inputs: two strings
// Output: Boolean value TRUE, if the strings are equal, FALSE otherwise
 
boolean string_equal(string str1, string str2);
// Function: is_integer
// Tests for a valid decimal representation of an integer
//
// Input: a string
// Output: a Boolean value (TRUE if valid, FALSE otherwise)

boolean is_integer(string str);

// Function: to_integer
// Converts a decimal string representation to an integer
//
// Input: a string representing an integer in decimal digits
// Output: the corresponding integer value

int to_integer(string str);

// Function: make_uppercase
// Converts the letters in a string to uppercase
//
// Input: a string
// Output: the input string with the letters converted to uppercase

void make_uppercase(string str);

// Function: string_swap
// Exchanges the values of two strings
//
// Inputs: two string variables
// Outputs:  the two string variables, with their values exchanged

void string_swap(string str1, string str2);

// Function: nth_char
// Returns the character at a specified position in the string
//
// Inputs: a string and an integer >= 1 and <= length of string
// Output: the character at the specified position

char nth_char(string str, int n);

// Function: append_char
// Adds character to current end of string
//
// Inputs: a string whose length is 1 less than MAX_STRING_SIZE and a character
// Output: the string with the character added

void append_char(string str, char ch);

#endif


