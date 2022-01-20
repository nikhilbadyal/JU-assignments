#include<stdio.h>
int _found(int *arr, int size , int);
int _found(int *arr, int size , int value)
{
	int pos = -1;

	int upper_bound = size-1;
	int lower_bound = 0;
	while(upper_bound>=lower_bound)
	{
		int mid = (upper_bound+lower_bound)/2;
		if(value == arr[mid])
		{
			pos = mid;
			break;
		}
		else if(value>arr[mid])
		{
			lower_bound = mid+1;
		}
		else{
			upper_bound = mid-1;
		}

	}
	if (pos == -1)
	{
		printf("Value not found.\n");
		return pos;
	}
	return pos;

}
int main()
{
	int arr[10];
	int i = 0;
	int size;
	int value= 9;
	scanf("%d",&size);
	while(i!= 10)
	{
		arr[i] = i;
		++i;
	}
	for(i = 0;i<10;++i)
    {
        printf("%d\n",arr[i]);
    }
	size = sizeof(arr)/sizeof(arr[0]);

	printf("%d\n",_found(arr,size,value) );
	return 0;
}
