#include <stdio.h>
#include <conio.h>
#include <string.h>
#include<stdbool.h>
#include<ctype.h>
#include"charStack.h"
bool isOperator(char );
bool morepriority(char );
char * convert(char *);
bool isOperator(char c)
{
    if(c == '+' || c == '*' || c == '/' || c == '-' || c == '%')
        return true;
    return false;
}
bool morepriority(char c )
{
    if(c == '/'|| c == '*'|| c == '%'){
        return true; }
    return false;
}
bool equalpriority(char c1 , char c2 )
{
    if(c1 == c2){
        return true; }
    return false;
}
char* convert(char * expression)
{
	char stack[50];
	char *Postfixexp = (char *)malloc(sizeof(strlen(expression)));
    int k;
    for(k = 0 ;k< (int)strlen(Postfixexp);++k)
    {
        Postfixexp[k]= 'x';
    }
    int i , j = 0;
    for( i = 0 ; i < (int)strlen(expression); ++i)
    {
    	if(isalpha(expression[i]))
    	{
    		Postfixexp[j] = expression[i];
    		++j;
		}
		if(isOperator(expression[i]))
		{
			if(TOP == -1)
			{
				push(stack,expression[i]);
				continue;
			}
			if(morepriority(expression[i]))
			{
				push(stack,expression[i]);
			}
			else{
			    while(morepriority(peek(stack)) || equalpriority(peek(stack),expression[i]))
				{
					Postfixexp[j] = pop(stack);
		     	    ++j;
				}
				push(stack,expression[i]);
			}

		}
		if(expression[i] == '(')
		{

			push(stack,expression[i]);
		}
		if(expression[i] == ')')
		{
			while(peek(stack) != '(')
			{
				Postfixexp[j] = pop(stack);
			    ++j;
			}
			pop(stack);
		}
	}
	while(!is_empty(stack))
	{
		Postfixexp[j] = pop(stack);
		++j;
	}
	return Postfixexp;
}
