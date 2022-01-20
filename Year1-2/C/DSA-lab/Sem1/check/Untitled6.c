#include<stdio.h>
#define MAX 20

void  bubble_sort(int arr[],int size)
{
     int i,j,temp;
	for (i = 0; i < size ; i++)
	{
		for (j = 0; j <size-1-i; j++)
		{
			if (arr[j] < arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;

			}/*End of if*/
		}/*End of inner for loop*/
	}//end of outer loop

}
void merge(int arr1[],int size1,int arr2[],int size2,int arr3[])
{
	/* Merging */
       int i=0;  	/*Index for first array*/
	int j=0;  	/*Index for second array*/
	int k=0;  	/*Index for merged array*/

	while( (i < size1) && (j < size2) )
	{
		if( arr1[i] < arr2[j] )
			arr3[k++]=arr1[i++];
		else
			arr3[k++]=arr2[j++];
	}/*End of while*/
	/*Put remaining elements of arr1 into arr3*/
	while( i < size1 )
		arr3[k++]=arr1[i++];
	/*Put remaining elements of arr2 into arr3*/
	while( j < size2 )
		arr3[k++]=arr2[j++];

	/*Merging completed*/




}




main()
{
	int arr1[MAX],arr2[MAX],arr3[40];
	int i,j,k;
	int size1,size2;

	printf("Enter the number of elements in list1 : ");
	scanf("%d",&size1);
	printf("Take the elements  :\n");
	for(i=0;i<size1;i++)
	{
		printf("Enter element %d : ",i+1);
		scanf("%d",&arr1[i]);
	}
	bubble_sort(arr1,size1);

	printf("Enter the number of elements in list2 : ");
	scanf("%d",&size2);
	printf("Take the elements  :\n");
	for(i=0;i<size2;i++)
	{
		printf("Enter element %d : ",i+1);
		scanf("%d",&arr2[i]);
	}

	bubble_sort(arr2,size2);

	merge(arr1,size1,arr2,size2,arr3);
	printf("\nMerged list : ");
	for(i=0;i<size1+size2;i++)
		printf("%d ",arr3[i]);
	printf("\n");
}/*End of main()*/
