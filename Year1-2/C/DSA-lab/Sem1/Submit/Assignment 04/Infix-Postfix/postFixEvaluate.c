#include <stdio.h>
#include <conio.h>
#include <string.h>
#include<stdbool.h>
#include"stackAdtArray.h"
int evaluate(const char *);
bool isDigit(char  );
bool isOp(char );
int perform(char c , int , int );
bool isOp(char c)
{
    if(c == '+' || c == '*' || c == '/' || c == '-')
        return true;
    return false;
}
bool isDigit(char c)
{
    if( c >= '0' && c<= '9')
        return true;
    return false;
}
int perform(char c , int op1, int op2)
{
    if(c == '-') return op1-op2;
    if(c == '+') return op1+op2;
    if(c == '*') return op1*op2;
    if(c == '/') return op1/op2;
    else return 0 ;
}
int evaluate( const char * exp)
{
    int i ,  stack[10];
    for(i=0;i<strlen(exp);i++)
    {
        if(isDigit(exp[i])){
            push(stack, (int)(exp[i]- '0')); }
        else if(isOp(exp[i])){
            int op2 = pop(stack);
            int op1 = pop(stack);
            int res = perform(exp[i], op1 , op2);
            if(res){
                push(stack , res); }

            else
                printf("Unexpected error\n");
        }
    }
    return peek(stack);
}
int main()
{
    char exp[10];
    printf("Enter expression to evaluate - \n");
    gets(exp);
    printf("%d ",evaluate(exp));
    return 0;
}
