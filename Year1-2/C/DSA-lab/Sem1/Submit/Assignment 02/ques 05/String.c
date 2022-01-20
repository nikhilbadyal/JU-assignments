#include<stdlib.h>
#include<stdio.h>
#include"String.h"
char lhs[15] = "Nikhil";
char rhs[15] = "Aikhil";
int main()
{
    printf("Strings are ");
    if(string_equal(lhs,rhs))
        printf("Equal\n");
    else{
        printf("UnEqual\n");
    }
    printf("Strings after concatenating is  ");
    concatinate(lhs,rhs);
    printf("\n");
    printf("String after conversion  ");
    printf("%d",to_integer("234"));
    printf("\n");
    printf("String size is  ");
    printf("%d",size(lhs));
    printf("\n");
    return 0;
}
