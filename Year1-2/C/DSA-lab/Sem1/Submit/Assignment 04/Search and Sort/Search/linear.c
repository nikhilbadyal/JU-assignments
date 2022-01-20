#include <stdio.h>
int _found(int *, int  , int );
int _found(int *arr,int size,int search)
{
	int pos = -1;
	int i;
	for(i=1 ;i<=size;++i)
	{
		if(arr[i-1]==search){
			pos = i;
		    break;
		}

	}
	if (pos == -1)
	{
		printf("Value not present in array.\n");
		return 0;
	}
	return pos;


}
int main()
{
	int arr[10];
	int i;
	int value = 9;
	for(i = 0 ;i<10;++i)
	{
		arr[i] = i;
	}
	for(i = 0;i<10;++i)
    {
        printf("%d\n",arr[i]);
    }
	int size = sizeof(arr)/sizeof(arr[0]);
	printf("%d\n",_found(arr,size,value) );
	return 0;
}
