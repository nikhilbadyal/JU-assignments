#include<stdio.h>
#include<string.h>
void swap(int *a, int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
}

int partition(int arr[],int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);
	for(int j = low; j<=high - 1;j++)
	{
		if(arr[j]<=pivot)
		{
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[high]);
	return i+1;
}

void quicksort(int arr[], int low, int high)
{
	if(low < high)
	{
		int pi = partition(arr,low,high);

		quicksort(arr,low,pi-1);
		quicksort(arr,pi+1,high);
	}
}

void LSearchInt(int search_key,int a[], int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i] == search_key)
		{
			printf("Search successful !!! Search_key found at index : %d\n", (i+1));
			return;
		}
	}
	printf("Search unsuccessful !!! :(");
}

void BSearchInt(int search_key,int a[], int n)
{
	quicksort(a,0,n-1);
	int lb=0;int ub=n-1;int p;int k=0;
	while(lb<=ub)
	{
		p=((lb+ub)/2);
		if(search_key == a[p])
		{
			printf("Search successful !!! Search_key found at index : %d\n", (p+1));
			k=1;
			break;	
		}
		if(search_key > a[p])
			lb = lb + 1;
		if(search_key < a[p])
			ub = ub - 1;
	}
	if(k==0)
	printf("Search unsuccessful !!! :(");
}

void LSearchFloat(float search_key,float a[], int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i] == search_key)
		{
			printf("Search successful !!! Search_key found at index : %d\n", (i+1));
			return;
		}
	}
	printf("Search unsuccessful !!! :(");
}

void BSearchFloat(float search_key,float a[], int n)
{
	//quicksort(a,0,n-1);
	int lb=0;int ub=n-1;int p;int k=0;
	while(lb<=ub)
	{
		p=((lb+ub)/2);
		if(search_key == a[p])
		{
			printf("Search successful !!! Search_key found at index : %d\n", (p+1));
			k=1;
			break;	
		}
		if(search_key > a[p])
			lb = lb + 1;
		if(search_key < a[p])
			ub = ub - 1;
	}
	if(k==0)
	printf("Search unsuccessful !!! :(");
}

void LSearchString(char search_key[],char a[][30], int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(stricmp(a[i],search_key)==0)
		{
			printf("Search successful !!! Search_key found at index : %d\n", (i+1));
			return;
		}
	}
	printf("Search unsuccessful !!! :(");
}

void BSearchString(char search_key[],char a[][30], int n)
{
	int lb=0;int ub=n-1;int p;int k=0;
	while(lb<=ub)
	{
		p=((lb+ub)/2);
		if(stricmp(a[p],search_key)==0)
		{
			printf("Search successful !!! Search_key found at index : %d\n", (p+1));
			k=1;
			break;	
		}
		if(search_key > a[p])
			lb = lb + 1;
		if(search_key < a[p])
			ub = ub - 1;
	}
	if(k==0)
	printf("Search unsuccessful !!! :(");
}
int main()
{
	int n;int c1; float c2;int ch1;int ch2;char s[30];
	printf("Enter 1 for LSearch, 2 for BSearch : \n");
	scanf("%d",&ch1);
	printf("Enter limit n : ");
	scanf("%d",&n);
	printf("Enter 1 for integers, 2 for floating point nos. & 3 for strings : \n");
	scanf("%d",&ch2);
	int a[100];float b[100];char x[100][30];
	printf("Enter array elements : \n");
	if(ch2==1)
	{
		for(int i = 0;i < n;i++)
		{
			scanf("%d",&a[i]);
		}
	}
	else if(ch2==2)
	{
		for(int i = 0;i < n;i++)
		{
			scanf("%f",&b[i]);
		}
	}
	else if(ch2==3)
	{
		for(int i = 0;i < n;i++)
		{
			scanf("%s", x[i]);
		}
	}
	printf("Enter search key : ");
	if(ch2==1)
	{
		scanf("%d",&c1);
	}
	else if(ch2==2)
	{
		scanf("%f",&c2);
	}
	else if(ch2==3)
	{
		scanf("%s",s);
	}
	if(ch1 == 1 && ch2==1)
		LSearchInt(c1,a,n);
	if(ch1 == 1 && ch2==2)
		LSearchFloat(c2,b,n);
	if(ch1 == 1 && ch2==3)
		LSearchString(s,x,n);
	if(ch1 == 2 && ch2==1)
		BSearchInt(c1,a,n);
	if(ch1 == 2 && ch2==2)
		BSearchFloat(c2,b,n);
	if(ch1 == 2 && ch2==3)
		BSearchString(s,x,n);
}
