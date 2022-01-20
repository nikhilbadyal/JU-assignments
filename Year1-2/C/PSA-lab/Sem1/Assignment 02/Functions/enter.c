#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int j;
    FILE *fp;
    int i,n;
	int roll,score[j];
	char name[20];
	fp = fopen("student.txt","w");
	printf("Enter the number of students : \n");
	
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the Roll and name of the student : \n");
    	scanf("%d%s",&roll,name);
     	fprintf(fp,"%d %s  ",roll,name);
     	printf("Enter the marks of students in 5 subjects.\n");
		for(j=0;j<5;j++)
		{	
			scanf("%d",&score[j]);
			fprintf(fp,"%d  ",score[j]);
		}
		fprintf(fp,"\n");
	}
	printf("Record added.\n");
	fclose(fp);
	return 0;
}

