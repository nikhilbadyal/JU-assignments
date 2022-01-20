#include<stdio.h>
int main()
{
	FILE *fp;
	fp=fopen("aman.txt","w");
	int n,min,max,i,j,temp,arr[10000];
	min=1;
	max=100000;
	srand();
	for(i=0;i<10000;i++)
	{
		temp=(rand()%max)+min;
		for(j=0;j<=i-1;j++)
		{
			if(temp==arr[j])
			{
				break;
			}
		}
		if(i==j)
		{
			arr[i]=temp;
		}
		else
		{
			i--;
		}
	}
	for(i=0;i<10000;i++)
	{
		
		printf("\n %d %d ",i+1,arr[i]);
		fprintf(fp,"%d \n",arr[i]);
	}
}

