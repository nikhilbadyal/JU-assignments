#include <stdio.h>
#include <conio.h>
#include <string.h>
#include<stdbool.h>
#include<ctype.h>
#include"infixToPostFix.h"
int main()
{
    char Infixexp[20];
    printf("Enter expression for conversion - \n");
    scanf("%s",Infixexp);
   printf("%s " , convert(Infixexp));
    return 0;
}
//a-(b/c+(d%e*f)/g)*h
// a+b*c+(d*e+f)*g
