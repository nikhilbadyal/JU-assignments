#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	FILE *fp,*fp1;
	int i,n,j;
	char name[20];
	int roll,score[j];
	fp1 = fopen("student.txt","r");
    while(fscanf(fp1,"%d %s",&roll,name)!=EOF)
	{
		printf("%d  \t%s",roll,name);
		for(j=0;j<5;j++)
		{
	    	while(fscanf(fp1,"%d ",&score[j])!=EOF)
			{
				printf("\t\t");
				printf("%d",score[j]);
				break;
			}
		}
		printf("\n");
	} 
	fclose(fp1);
	return 0;
}
