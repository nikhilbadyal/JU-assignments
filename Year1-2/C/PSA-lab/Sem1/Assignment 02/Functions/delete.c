#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	FILE *fp1,*fp2;
	int del_roll,line_no;
	char student[200];
	printf("Enter the roll of student whom data you want to delete :");
	scanf("%d",&del_roll);
	fp1 = fopen("student.txt","r");
	fp2 = fopen("replica.txt","w");
	while(fgets(student,199,fp1)!=NULL)
	{
		line_no++;
		if(line_no!=del_roll)
		{
			fputs(student,fp2);
		}
	}
	fclose(fp1);
	fclose(fp2);
	remove("a.txt");
	rename("replica.txt","student.txt");
	return 0;
}
