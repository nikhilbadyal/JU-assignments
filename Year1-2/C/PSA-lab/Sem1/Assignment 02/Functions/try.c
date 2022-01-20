#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdlib.h>
int pre_check()
{
	int task;
	char next;
	returned:
	while (1)
	{
	printf("\n\nEnter number as per as your task.\t ");
    if (scanf("%d", &task) < 0 ||  // 1
            task < 0 ||  // 2
            ((next = getchar()) != EOF && next != '\n')) {  // 3
        clearerr(stdin);
        do
            next = getchar();
        while (next != EOF && next != '\n');  // 4
        clearerr(stdin);
        printf("\nPlease enter a positive number.");
    } else {
        break;
    }
    }
	if(task>6 )
	{
		printf("OPS ! Invalid Entry.Please re-enter.\n\n");
		printf("    ENTER AGAIN    ");
		goto returned;
	}
	return(task);
}
int enter()
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
int main()
{
	int a;
	a=pre_check();
	if(a==1)
	{
		enter();
	}
	else
	{
		printf("Not allowed.");
	}
}
