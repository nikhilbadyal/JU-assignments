#include<stdio.h>
unsigned long long int fibLoop(int );
unsigned long long int fibRec(int );

unsigned long long int fibLoop(int n)
{
    int i;
    unsigned long long int arr[100];
    arr[0]=0,arr[1]=1;
    for(i=0;i<n;i++)
    {
        arr[i+2]=arr[i]+arr[i+1];
    }
    return arr[n-1];
}
unsigned long long int fibRec(int n)
{
    if (n <= 1)
        return n;
    return fibRec(n-1) + fibRec(n-2);
}

int main ()
{
    int n;
    printf("Enter the term you want : \n");
    scanf("%d",&n);
    printf("Terms calculated using recursion %llu\n", fibRec(n-1));
    printf("Terms calculated using Loop %llu\n", fibLoop(n));
    return 0;
}
