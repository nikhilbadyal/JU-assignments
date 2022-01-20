#include<stdio.h>
#define max(a,b) (a>b?a:b)
int main()
{
    char *p,*q;
    p = "23";
    q = "65";
    printf("Greater between two number is : %d ",max(p,q));
    return 0;
}
