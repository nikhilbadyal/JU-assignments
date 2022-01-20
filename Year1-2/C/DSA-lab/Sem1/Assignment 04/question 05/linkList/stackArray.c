#include<stdio.h>
#include<stdbool.h>
#include"stackAdtLinked.h"

int main()
{
    Stack *s ;
    s = push(s,9);
    s = push(s,8);
    s = push(s,7);

    display(s);
//    displayRev(&s);
    return 0;
}
