#include<stdio.h>
int main()
{
    int n,i;
    unsigned long long int arr[100];
    arr[0]=0,arr[1]=1;

    printf("Enter the nth number : \n");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        arr[i+2]=arr[i]+arr[i+1];
    }
    printf("Terms calculated using Loop : %d ",arr[n-1]);
}
