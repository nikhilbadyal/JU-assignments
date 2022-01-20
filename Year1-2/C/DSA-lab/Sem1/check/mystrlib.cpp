//----------------------------------------------------------------------------
//----A decent library of string functions for NameAge programs
//----------------------------------------------------------------------------
#include <iostream.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "mystrlib.h"
//----------------------------------------------------------------------------
//----Check if a string is an integer
boolean IsInteger(string AString) {

boolean NoBadDigits = TRUE;
int StringIndex,
    StringLength;

StringIndex = 0;
StringLength = strlen(AString);

while (NoBadDigits && (StringIndex < StringLength))
    if (! isdigit(AString[StringIndex]))
        NoBadDigits = FALSE;
    else ++StringIndex;

return(NoBadDigits);
}
//----------------------------------------------------------------------------
//----Convert a string to an integer
int ToInteger(string AString) {

return(atoi(AString));
}
//----------------------------------------------------------------------------
//----Reads a string and returns TRUE if successful
boolean ReadString(string& AString) {

//----Current reads and is always successful
cin >> AString;

return(TRUE);
}
//----------------------------------------------------------------------------
//----Concatenate two strings if not too long
boolean Concatenate(string& AString1,string AString2) {

if (strlen(AString1) + strlen(AString2) < MAX_STRING_SIZE) {
    strcat(AString1,AString2);
    return(TRUE);
    }
else return(FALSE);
}
//----------------------------------------------------------------------------
//----Checks if first string is lexicographically greater than the second
boolean StringGreater(string AString1,string AString2) {

return(strcmp(AString1,AString2) > 0);
}
//----------------------------------------------------------------------------
//----Checks if first string is the same as the second
boolean StringEqual(string AString1,string AString2) {

return(strcmp(AString1,AString2) == 0);
}
//----------------------------------------------------------------------------
//----Checks if first string is lexicographically smaller than the second
boolean StringSmaller(string AString1,string AString2) {

return(strcmp(AString1,AString2) < 0);
}
//----------------------------------------------------------------------------
