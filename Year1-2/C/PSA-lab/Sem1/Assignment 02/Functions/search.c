#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int i,x,j,res,f=0,score[j];
	char name[20],read[500];
	printf("Enter the roll of student whose data you want to search : \n");
	scanf("%d",&x);
	FILE *fp1;
	int roll;
	fp1 = fopen("student.txt","r");
    while(fscanf(fp1,"%d %s",&roll,name)!=EOF)
	{
		//printf("%d  \t%s",roll,name);
		for(j=0;j<5;j++)
		{
	    	while(fscanf(fp1,"%d ",&score[j])!=EOF)
			{
				
				//printf("\t\t");
				//printf("%d",score[j]);
				break;
			}
		}
		//printf("\n");
	    if(roll==x)
	    {
	    	printf("Record found.\n");
	    	printf("Name : %s\n",name);
	    	printf("Scores are : \n");
	    	for(j=0;j<5;j++)
	    	{
	    		printf("%d  ",score[j]);	
			}
	    	f=1;
		}
	} 
	if(f==0)
	{
		printf("Record not found. ");
	}
	fclose(fp1);
	return 0;
}
