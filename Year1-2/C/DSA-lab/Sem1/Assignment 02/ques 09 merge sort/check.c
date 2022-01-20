#include<stdio.h>
#include<stdlib.h>
int ascend(int *arr,int n)
{
	int i,status=1;  //Ascend
	for(i=1;i<n;i++)
	{

		if(arr[i-1]>arr[i])
		{
            status=0;
            break;
        }
	}
    if(status==0)
	{
	    int y = descend(arr,5);
	    if(y==1)
        {
            printf("Array not sorted.\n");
        }
        if(y==0)
        {
            printf("Array is sorted in decreasing order.\n");
        }
    }
    else { printf("Array is in ascending order.\n");}

}
int descend(int *arr,int n)
{
	int i=1,status=1;
	for(i;i<n;i++)
	{
		if(arr[i-1]<arr[i])
		{
            status=0;
            break;
        }
    }
    if(status==1)
	{
        return 0;
    }
	else
	{
        return 1;
    }
}
int main()
{
	int i,y=3;
	int arr[5] = {1,5,2,5,7};//{9,8,7,6,5}; //{1,2,3,4,5}; ////
	ascend(arr,5);

	return 0;
}
