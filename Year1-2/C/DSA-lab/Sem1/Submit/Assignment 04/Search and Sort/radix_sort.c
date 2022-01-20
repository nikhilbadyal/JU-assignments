#include<stdio.h>
#define newSize 10
void radix_sort(int *, int);
int noOfDigits(int *,int );
int noOfDigits(int *arr,int size)
{
    int i;
    int largest = arr[0];
    for(i =0 ; i<size ; ++i)
    {
        if(arr[i]>largest)
        {
            largest = arr[i];
        }
    }
    int nod = 0;
    while(largest>0)
    {
        nod++;
        largest /= 10;
    }
    return nod;
}
void radix_sort(int *arr , int size)
{
    int nod = noOfDigits(arr,size);
    int i,k,j ;
    int bucket[newSize][newSize];
    int bucket_count[newSize];
    int reminder , divisor = 1;
    int pass;
    for(pass=0 ;pass <nod ;++pass)
    {
        for(k = 0 ; k< newSize; ++k){
            bucket_count[k] = 0;
        }
        for(k= 0 ; k< size ;++k)
        {
            reminder = (arr[k]/divisor)%newSize;
            bucket[reminder][bucket_count[reminder]] = arr[k];
            bucket_count[reminder] += 1;
        }
        for(k = 0 ; k< newSize; ++k){
        }
        i =0;
        for(k = 0; k<newSize;++k)
        {
            for(j=0 ;j <bucket_count[k];++j)
            {
                arr[i] = bucket[k][j];
                i++;
            }
        }
        divisor *= size;
    }
}
int main()
{
    int arr[10];
	int i = 0;
	int size;
	int k = 11;
	while(k!= 1)
	{
		arr[i] = k;
		i++;
		--k;
	}
	arr[3]=87663;
	arr[1]=104;
	arr[7]=300;
	for(i = 0;i<10;++i)
    {
        printf("%d ",arr[i]);
    }
	size = sizeof(arr)/sizeof(arr[0]);
    radix_sort(arr,size);
    printf("Sorted.\n");
	for(i = 0;i<10;++i)
    {
      printf("%d ",arr[i]);
    }
    return 0;
}

