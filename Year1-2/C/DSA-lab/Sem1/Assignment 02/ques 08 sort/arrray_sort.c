#include<stdio.h>
#include<stdlib.h>
int ascend(int *arr,int n)
{
	int i,status=1;
	for(i=1;i<n;i++)
	{

		if(arr[i-1]>arr[i])
		{
            status=0;
            break;
        }
	}
    if(status==1)
	{
    return 0;
    }
	else{
        return 1;
    }
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
	int arr[5] =  {1,2,3,4,5};
	int x = ascend(arr,5);
	if(x)
	{
		y = descend(arr,5);
	}
	else{

		printf("Array is sorted in ascending order.\n");
		if(y)
        {
            printf("Array not sorted.\n");
	    }
	    else{
            printf("Array is sorted in decreasing order.\n");
	    }
	}
	return 0;
}
