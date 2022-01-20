#include<stdio.h>
int main()
{
    int n,arr[100],i;
    arr[0]=0,arr[1]=1;

    printf("Enter the term you want: \n");
    scanf("%d",&n);

    /*printf("The fibonacci series upto %d term is : \n",n); */
    for(i=0;i<n;i++)
    {
        arr[i+2]=arr[i]+arr[i+1];
    }
    printf("\nThe %dth elements is : %d ",n,arr[n-1]);
}
