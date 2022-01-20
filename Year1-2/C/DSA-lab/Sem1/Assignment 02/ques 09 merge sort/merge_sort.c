#include<stdio.h>
#include<stdlib.h>
void merge(int *merged,int *arr1,int s1,int *arr2,int s2)
{
    int i,j;
    for(i=0;i<s1;i++)
    {
        printf("%d\n",arr1[i]);

        merged[i]=arr1[i];
    }
    for(j=0;j<s2;j++)
    {
        merged[i]=arr2[j];
    }
    printf("%d\n",merged[6]);
}
int main()
{
    int i;
    int merged[15],s1=5,s2=5;
    int arr1[5] = {1,2,3,4,5}; ////{1,5,2,5,7};
    int arr2[5] = {2,5,6,8,11}; //
    merge(merged,arr1,s1,arr2,s2);
   /* for(i=0;i<10;i++)
    {
        printf("%d\n",merged[i]);
    }*/
    printf("%d\n",merged);
    return 0;
}
