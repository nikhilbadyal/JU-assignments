#include<stdlib.h>
#include<stdio.h>
const int size = 50;
int TOP = -1;
void push(char * , char);
char  pop(char * );
char  peek(char * );
void  display(char * );
bool  is_empty( );
void push(char *stack, char value)
{
    if(TOP == size - 1)
    {
      //  printf("Stack already full\n");
        return ;
    }
    ++TOP;
    stack[TOP] = value ;
    return ;
}
char pop(char *stack )
{
    char n = 'n';
    if(TOP == -1)
    {
        return n;
    }
    char val = stack[TOP];
    TOP--;
    return val;
}
char peek(char *stack )
{
    if(TOP == -1)
    {
        return -1;
    }
    return (stack[TOP]);
}
void display(char *stack )
{
    int i ;
    if(TOP == -1)
    {
        return ;
    }
    for(i = TOP ;i>= 0 ; --i)
    {
        printf("%c ",stack[i]);

    }
    return ;
}
bool is_empty(char *stack)
{
    if(TOP == -1 ){
        return true; }
    return false;
}
