//Fibonacci Series using Recursion
#include<stdio.h>
unsigned long long int fib(int n)
{
    if (n <= 1)
        return n;
    return fib(n-1) + fib(n-2);
}

int main ()
{
    int n;
    printf("Enter the term you want : \n");
    scanf("%d",&n);
    printf("Terms calculated using recursion %llu", fib(n-1));
    return 0;
}

