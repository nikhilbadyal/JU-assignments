#include<stdlib.h>
#include<stdio.h>
#define size 50

typedef struct {
    int stack[size];
    int TOP ;
}Stack ;

void push(Stack * , int );
void  pop(Stack * );
int  peek( Stack * );
void  display( Stack * );
bool  is_empty( Stack * );
void displayRev(Stack * );


void push(Stack* s  , int value)
{
    if(s->TOP == size - 1)
    {
        printf("Stack already full\n");
        return ;
    }
    ++s->TOP;
    s->stack[s->TOP] = value ;
 //   printf("%d",s->stack[s->TOP]);
    return ;
}
void pop(Stack *s )
{
    if(s->TOP == -1)
    {
        printf("Underflow\n");
        return ;
    }
 //   int val = s[s->TOP];
    s->TOP--;
   // return val;
}
int peek(Stack *s )
{
    if(s->TOP == -1)
    {
        printf("Stack empty\n");
        return -1;
    }
    return (s->stack[s->TOP]);
}
void display(Stack *s )
{
    int i ;
    if(s->TOP == -1)
    {
        printf("Stack empty\n");
        return ;
    }
    for(i = s->TOP ;i>= 0 ; --i)
    {
        printf("%d ",s->stack[i]);

    }
    return ;
}
void displayRev(Stack *s )
{
    int i ;
    if(s->TOP == -1){  return ;}
    for(i =  0 ;i <= s->TOP ; ++i)
    {
        printf("%d ",s->stack[i]);

    }
}
void displayRevDelete(Stack *s )
{
    int i ;
    if(s->TOP == -1){  return ;}
    for(i =  0 ;i <= s->TOP ; ++i)
    {
        printf("%d ",s->stack[i]);

    }
}
bool is_empty(Stack *s )
{
    if(s->TOP == -1 )
        return true;
    return false;
}
bool is_equal(Stack *s1, Stack *s2 )
{
    if(s1->TOP != s2->TOP ) return false;
    int i ;
    for(i =  0 ;i <= s1->TOP ; ++i)
    {
        if(s1->stack[i] != s2->stack[i] )
            return false;
    }
    return true;
}
