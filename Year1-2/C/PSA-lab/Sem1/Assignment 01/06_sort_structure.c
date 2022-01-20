#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct person
{
	int age;
	char name[20];
}per[100],temp;
int main()
{
	int i,n,j;
	printf("Enter the no of persons : \t");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("\nEnter the age and  name of the person.\n");
    	scanf("%d %s",&per[i].age,per[i].name);	
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<=n-1;j++)
		{
			if(per[j].age<per[j+1].age)
			{
				temp=per[j];
				per[j]=per[j+1];
				per[j+1]=temp;
			}
		}
	}
	printf("Structure Sorted.\n");
	for(i=0;i<n;i++)
	{
    	printf("%d %s\n",per[i].age,per[i].name);		
	}
	return 0;
}

