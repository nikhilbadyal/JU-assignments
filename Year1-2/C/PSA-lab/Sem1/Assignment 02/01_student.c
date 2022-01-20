#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int enter()
{
//	int j;
	int i,n,j;
    FILE *fp;
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
void read()
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
}
void delete_data()
{
	int i,roll1,x,j,res,f=0,score[j];
	char name[20],read[500];
	printf("Enter the roll of student whose data you want to delete : \n");
	scanf("%d",&x);
	FILE *fp1,*fp2;
	int roll;
	fp1 = fopen("student.txt","r");
	fp2 = fopen("temp.txt","a");
    while(fscanf(fp1,"%d %s",&roll,name)!=EOF)
	{
		for(j=0;j<5;j++)
		{
	    	while(fscanf(fp1,"%d ",&score[j])!=EOF)
			{
				break;
			}
		}
	    if(roll==x)
	    {
	    	f=1;
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
		for(j=0;j<5;j++)
		{
	    	while(fscanf(fp2,"%d ",&score[j])!=EOF)
			{
				break;
			}
		}
        fprintf(fp1,"%d %s  ",roll,name);
	    for(j=0;j<5;j++)
	    {
	      	fprintf(fp1,"%d  ",score[j]);
	   	}
    	fprintf(fp1,"\n");
    	printf("Successfully removed.");
	}
	fclose(fp1);
	fclose(fp2);
	remove("temp.txt");


}
void search()
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
		for(j=0;j<5;j++)
		{
	    	while(fscanf(fp1,"%d ",&score[j])!=EOF)
			{
				break;
			}
		}
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
}
void update()
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
		for(j=0;j<5;j++)
		{
	    	while(fscanf(fp1,"%d ",&score[j])!=EOF)
			{
				break;
			}
		}
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
		for(j=0;j<5;j++)
		{
	    	while(fscanf(fp2,"%d ",&score[j])!=EOF)
			{
				break;
			}
		}
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
}
int search1(int new_roll)
{
	int i,x,j,res,f=0,score[j];
	char name[20],read[500];
	x=new_roll;
	FILE *fp1;
	int roll;
	fp1 = fopen("student.txt","r");
    while(fscanf(fp1,"%d %s",&roll,name)!=EOF)
	{
		for(j=0;j<5;j++)
		{
	    	while(fscanf(fp1,"%d ",&score[j])!=EOF)
			{
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
void append()
{
	FILE *fp;
	int j,temp,new_roll;
	char name[20],read[500];
	int roll,score[j];
	printf("Enter the roll no. of new student : \n");
	scanf("%d",&new_roll);
	temp = search1(new_roll);
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
}
int pre_check()
{
	int task;
	char next;
	returned:
	while (1)
	{
    if (scanf("%d", &task) < 0 ||  // 1
            task < 0 ||  // 2
            ((next = getchar()) != EOF && next != '\n')) {  // 3
        clearerr(stdin);
        do
            next = getchar();
        while (next != EOF && next != '\n');  // 4
        clearerr(stdin);
        printf("\n\t\tPlease enter a positive number.");
    } else {
        break;
    }
    }
    check2:
	if(task>7 )
	{
		printf("\n\t\tOPS ! Invalid Entry.Please re-enter.\n\n");
		printf("\n\t\tENTER AGAIN");
		goto returned;
	}
	return task;
}
void enter_run()
{
	long fsize = 0;
	FILE *fp;
	int count=1;
	int task;
	int run;

	returned:
	printf("\n\n\t\t\tSTUDENT RECORD MAINTAINING SYSTEM");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1.Enter new data\n\t\t2.Check the details of existing account\n\t\t3.Remove record of existing student\n\t\t4.Search for existing student record\n\t\t5.Update information of existing account\n\t\t6.Add new record to existing data\n\t\t7.Exit\n\n\n\n\n\t\t Enter your choice:  ");
	enter_again:
	task =pre_check();
	if(task==7)
	{
		exit(0);
	}
	if (task==1)
	{
		enter();
	}
	if (task==2)
	{
		goto file_check;
		task2:
		read();
		goto run_again;
		count++;
	}
	if (task==3)
	{
		goto file_check;
		task3:
		delete_data();
		goto run_again;
		count++;
	}
	if(task==4)
	{
		goto file_check;
		task4:
		search();
		goto run_again;
		count++;
	}
	if(task==5)
	{
		goto file_check;
		task5:
		update();
		goto run_again;
		count++;
	}
	if(task==6)
	{
		goto file_check;
		task6:
		append();
		goto run_again;
		count++;
	}
	if(count==2)
	{
		exit(0);
	}
	file_check:
	if(task!=1)
	{
		fp = fopen("student.txt","r");
		long long size = 0;
		if(fp!=NULL)
	    {
	    	fseek(fp, 0, SEEK_END);
        	fsize= ftell(fp);
        }
        if(fsize==0)
        {
        	printf("\n\t\tData doesn't exist.Please enter data atleast once.");
	     	printf("\n\t\tENTER NUMBER AGAIN\n\t\t");
	     	goto enter_again;
		}
        else
        {
    	if(task==2)
    	{
    		goto task2;
		}
		if(task==3)
    	{
    		goto task3;
		}
		if(task==4)
    	{
    		goto task4;
		}
		if(task==5)
    	{
    		goto task5;
		}
		if(task==6)
    	{
    		goto task6;
		}
    	fclose(fp);
      	}

	}
	run_again:
	printf("\nEnter 1 if you want to run program again,else press any key to exit .\n");

	scanf("%d",&run);
	if(run==1)
	{
		goto returned;
	}
	else
	{
		exit(0);
	}
}
int main()
{
	system("cls");
    system("color 9");
	enter_run();
    return 0;
}


