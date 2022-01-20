#include <stdio.h>
#include<stdlib.h>
#define MAX  100000
int time;
void swap(int *x,int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
void BubbleSort(int arr[],int n)
{
	int i,j,temp;
	for(i=0;i<n;i++)
	{
		for(j = 0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				swap(&arr[j],&arr[j+1]);
			}
		}
	}
}
void SelectionSort(int arr[], int n)
{
	int i,j,temp;
    for(i = 0;i<n;i++ )
    {
    	for(j = i+1;j<n;j++)
    	{
    		if(arr[i]>arr[j])
    		{
				swap(&arr[i],&arr[j]);
		}
		}
	}
}
void InsertionSort(int arr[],int n)
{
	int i,pos,k;
	for(i=1;i<n;i++)
	{
		pos = i;
		k = arr[i];
		while(pos > 0 && k < arr[pos-1])
		{
			arr[pos] = arr[pos-1];
			pos--;
		}
		arr[pos] = k;
	}
}
void Merge(int arr[],int l,int r,int mid)
{
	int *t,i=l,j=mid+1,k=0;
	t = (int *)malloc(sizeof(int)*(r - l + 1));
	while(i<=mid && j<=r)
	{
		if(arr[i]<=arr[j])
			t[k++] = arr[i++];
		else
			t[k++] = arr[j++];
	}
	for(;i<=mid;i++)
		t[k++] = arr[i];
	for(;j<=r;j++)
		t[k++] = arr[j];
	for(i=l,k=0;i<=r;i++,k++)
		arr[i] = t[k];
}
void MergeSort(int v[],int l,int r)
{
	int mid;
	if(l<r)
	{
		int mid = (l+r)/2;
		MergeSort(v,l,mid);
		MergeSort(v,mid+1,r);
		Merge(v,l,r,mid);
	}
}
void QuickSort(int arr[],int l,int r)
{
	int p;
	if(l<r)
	{
		p = getPivot(arr,l,r);
		QuickSort(arr,l,p-1);
		QuickSort(arr,p+1,r);
	}
}
int getPivot(int arr[],int l,int r)
{
	int p = l,temp;
	while(l<r)
	{
		if(l<r && arr[p] < arr[r])
			r--;
		if(l<r && arr[p] > arr[r])
		{
			swap(&arr[p],&arr[r]);
			p = r;
			l++;
		}
		if(l<r && arr[p] > arr[l])
			l++;
		if(l<r && arr[p] < arr[l])
		{
			swap(&arr[p],&arr[l]);
			p = l;
			r--;
		}
	}
	return p;
}
void Heapify(int arr[],int n,int pos)
{
	int i = pos;
	int l = 2*i + 1;
	int r = 2*i + 2;
	int temp;
	if(l < n && arr[l] > arr[i])
		i = l;
	if(r < n && arr[r] > arr[i])
		i = r;
	if(pos != i)
	{
		swap(&arr[pos],&arr[i]);
		Heapify(arr,n,i);
	}
	
}
void HeapSort(int arr[],int n)
{
	int i;
	for(i = 0;i< n/2 - 1;i++)
		Heapify(arr,n,i);
	for(i = n-1;i>=0;i--)
	{
		swap(&arr[0],&arr[i]);
		Heapify(arr,i,0);
	}
}
void print(int numbers[],int n)
{
	int i;
	printf("The sorted array = \n");
	for(i=0;i<n;i++)
    {
        printf("%d --> %d\n", i, numbers[i]);
    }
}
int main()
{
    FILE *f;
    int numbers[MAX], num, i=0,choice,x;
    f=fopen("C:\\Users\\PC\\Documents\\Inteiros.txt", "r");
    if(f==NULL)
    {
        printf("Erro\n");
        return 0;
    }    
    while(fscanf(f, "%d", &num)>0)
    {
        numbers[i]=num;
        i++;    
    }
    fclose(f);
    printf("numbers were read\n");
    printf("1.Bubble Sort\n2.Insertion sort\n3.Selection sort\n4.Merge sort\n5.Quick Sort\n6.Heap sort\n7.Exit\n");
    do(1)
    {
    	printf("Enter your choice : ");
    	scanf("%d",&choice);
    	switch(choice)
    	{
    		case 1: BubbleSort(numbers,i);
    				print(numbers,i);
    				break;
    		case 2: InsertionSort(numbers,i);
    				print(numbers,i);
    				break;
    		case 3: SelectionSort(numbers,i);
    				print(numbers,i);
    				break;
    		case 4: MergeSort(numbers,0,i-1);
    				print(numbers,i);
    				break;
    		case 5: QuickSort(numbers,0,i-1);
    				print(numbers,i);
    				break;
    		case 6: HeapSort(numbers,i-1);
    				print(numbers,i);
    				break;
    		case 7: exit(0);
		}
		printf("Do you want to continue ?(1/0) ");
		scanf("%d",&x);
	}while(x == 1);
	return 0;
}
