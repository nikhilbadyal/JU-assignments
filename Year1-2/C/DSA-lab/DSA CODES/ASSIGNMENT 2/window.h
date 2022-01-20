#include<stdio.h>
#include<stdlib.h>
int arr[1000] = {0};
int op[101];
int temp[101];
void bubbleSort(int a[], int n)
{
	int temp;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}
void maximum(int a[], int n, int k)
{
	for(int i=0;i<n;i++)
	{
		int temp=a[i];
		for(int j=1;j<k;j++)
		{
			if(a[i+j]>temp)
				temp=a[i+j];
		}
		op[i]=temp;
	}
}
void minimum(int a[], int n, int k)
{
	for(int i=0;i<n;i++)
	{
		int temp=a[i];
		for(int j=1;j<k;j++)
		{
			if(a[i+j]<temp)
				temp=a[i+j];
		}
		op[i]=temp;
	}
}
void median(int a[], int n, int k)
{
	int c;
	for(int i=0;i<n;i++)
	{
		c=0;
		for(int j=i;j<i+k;j++)
			temp[c++]=a[j];
		bubbleSort(temp,c);
		op[i]=temp[c/2];
	}
}
void average(int a[], int n, int k)
{
	int sum;
	for(int i=0;i<n;i++)
	{
		sum=0;
		for(int j=i;j<i+k;j++)
		{
			sum+=a[j];
		}
		op[i]=sum/k;
	}
}
void display(int a[], int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}
