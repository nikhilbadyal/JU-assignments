#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int i,roll1,x,j,res,f=0,score[j];
	char name[20],read[500];
	printf("Enter the roll of student whose data you want to update : \n");
	scanf("%d",&x);
	FILE *fp1,*fp2;
	int roll;
	fp1 = fopen("student.txt","r");
	fp2 = fopen("temp.txt","a");
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
	    	f=1;
	    	printf("Record found.\n");
	    	printf("Name : %s\n",name);
	    	printf("Scores are : \n");
	    	for(j=0;j<5;j++)
	    	{
	    		printf("%d  ",score[j]);	
			}
			printf("\nEnter New roll : \n");
			scanf("%d",&roll1);
			fprintf(fp2,"%d %s  ",roll1,name);
			for(j=0;j<5;j++)
	    	{	
		    	fprintf(fp2,"%d  ",score[j]);
	        }
	    	fprintf(fp2,"\n");
		}
		else
		{
			fprintf(fp2,"%d %s  ",roll,name);
			for(j=0;j<5;j++)
	    	{	
		    	fprintf(fp2,"%d  ",score[j]);
	        }
	    	fprintf(fp2,"\n");
		}
	}
	fclose(fp1);
	fclose(fp2);
	if(f==0)
	{
		printf("Record not found.");
	}
	fp1 = fopen("student.txt","w");
	fclose(fp1);
	fp1 = fopen("student.txt","a");
	fp2 = fopen("temp.txt","r");
	while(fscanf(fp2,"%d %s",&roll,name)!=EOF)
	{
		//printf("%d  \t%s",roll,name);
		for(j=0;j<5;j++)
		{
	    	while(fscanf(fp2,"%d ",&score[j])!=EOF)
			{
				//printf("\t\t");
				//printf("%d",score[j]);
				break;
			}
		}
		//printf("\n");
        fprintf(fp1,"%d %s  ",roll,name);
	    for(j=0;j<5;j++)
	    {	
	      	fprintf(fp1,"%d  ",score[j]);
	   	}
    	fprintf(fp1,"\n");	
	}
	fclose(fp1);
	fclose(fp2);
	remove("temp.txt");
	
	return 0;
}
