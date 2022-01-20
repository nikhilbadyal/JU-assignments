#include <stdio.h>
unsigned long long int factByRecursion(int );
unsigned long long int factByLoop(int );

int main()
{
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    printf("Factorial of %d by recursion = %llu\n", n, factByRecursion(n));
    printf("Factorial of %d by loop = %llu\n", n, factByLoop(n));
    return 0;
}
unsigned long long int factByRecursion(int n)
{
    if (n >= 1)
        return n*factByRecursion(n-1);
    else
        return 1;
}
unsigned long long int factByLoop(int n)
{
   if(n == 0 || n == 1) return 1;
   int i;
   unsigned long long int factorial =1 ;
    for(i=1; i<=n; ++i)
    {
        factorial *= i;
    }
    return factorial;
}
