#include<stdio.h>
#include<stdbool.h>
#include"stackAdtArray.h"

int main()
{
    Stack s = {.TOP = -1};
    push(&s,9);
    push(&s,8);
    push(&s,7);
    push(&s,6);
    display(&s);
    displayRev(&s);
    return 0;
}
