#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int search(int new_roll)
{
	int i,x,j,res,f=0,score[j];
	char name[20],read[500];
	x=new_roll;
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
	    	f=1;
	    	return 0;
		}
	} 
	if(f==0)
	{
		return 1;
	}
	fclose(fp1);
}
int main()
{
	FILE *fp;
	int j,temp,new_roll;
	char name[20],read[500];
	int roll,score[j];
	printf("Enter the roll no. of new student : \n");
	scanf("%d",&new_roll);
	temp = search(new_roll);
	if(temp==1)
	{
		fp = fopen("student.txt","a");
        printf("Enter the name of the student : \n");
    	scanf("%s",name);
    	fprintf(fp,"%d %s  ",new_roll,name);
    	printf("Enter the marks of students in 5 subjects.\n");
    	for(j=0;j<5;j++)
    	{	
    		scanf("%d",&score[j]);
    		fprintf(fp,"%d  ",score[j]);
        }
    	printf("Record added.\n");
        fclose(fp);
    }
	else
	{
		printf("Ops ! Roll already allocated.");
	}
	return 0;
	
}
