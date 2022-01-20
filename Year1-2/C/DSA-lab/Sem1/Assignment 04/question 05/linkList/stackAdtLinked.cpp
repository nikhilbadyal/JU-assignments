#include<stdlib.h>
#include<stdexcept>
#include<stdio.h>
#include"stackAdtLinked.h"
int main()
{
    int i ;
    Stack *s = nullptr;
    Stack *s1 = nullptr;
    for( i = 0 ; i<5; ++i)
    {
        push(&s,3);
        push(&s1,3);
    }
     //push(&s,4);
   display(&s);
   displayRev(&s);
   displayRevDelete(&s);
   display(&s);
   // push(&s,3);
 //  printf("%d ",peek(&s));
 //   printf("%d ",equality(&s,&s1));
    return 0;
}
