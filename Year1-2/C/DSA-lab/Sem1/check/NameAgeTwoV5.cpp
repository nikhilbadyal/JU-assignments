//----------------------------------------------------------------------------
//----Write a program that reads in a list of people's names and ages,
//----and writes them out in alphabetical order by name.
//----------------------------------------------------------------------------
#include <iostream.h>
#include "mystrlib.h"

boolean ReadIntegerString(int& AnInt);
void ReadNameAge(string WhichPerson, string& FirstName, string& LastName,
int& Age);
void MakeName(string& FirstName, string LastName);
//----------------------------------------------------------------------------
int main(void) {

string FirstName1 = "",
    FirstName2 = "",
    LastName1 = "",
    LastName2 = "",
    TempString;
int Age1,
    Age2,
    TempInt;

//----Prompt user for names and ages, and read
ReadNameAge("first",FirstName1,LastName1,Age1);
ReadNameAge("second",FirstName2,LastName2,Age2);

//----If possible join names into one string, else copy last name to first
MakeName(FirstName1,LastName1);
MakeName(FirstName2,LastName2);

//----Compare last names and swap if out of order
if (StringGreater(LastName1,LastName2)) {
    strcpy(TempString,FirstName1);
    strcpy(FirstName1,FirstName2);
    strcpy(FirstName2,TempString);
    TempInt = Age1;
    Age1 = Age2;
    Age2 = TempInt;
    }

//----Output the names and ages
cout << "In nice alphabetical order by last name they are:" << endl;
cout << FirstName1 << " " << Age1 << endl;
cout << FirstName2 << " " << Age2 << endl;

//----End program
return(0);
}
//----------------------------------------------------------------------------
//----Reads an integer and returns TRUE if successful
boolean ReadIntegerString(int& AnInt) {

string AString;

if (!ReadString(AString) || !IsInteger(AString))
    return(FALSE);
else {
    AnInt = ToInteger(AString);
    return(TRUE);
    }
}
//----------------------------------------------------------------------------
//----Prompt user for names and ages, and read
void ReadNameAge(string WhichPerson, string& FirstName, string& LastName,
int& Age) {

cout << "Enter the first and last names and age for the " << WhichPerson
     << " person:" << endl;
ReadString(FirstName);
ReadString(LastName);
if (!ReadIntegerString(Age)) 
    Age = 0;
}
//----------------------------------------------------------------------------
//----If possible join names into one string, else copy last name to first
void MakeName(string& FirstName, string LastName) {

if (!Concatenate(FirstName," ") || !Concatenate(FirstName,LastName))
    strcpy(FirstName,LastName);
}
//----------------------------------------------------------------------------
