void enter_run()
{
	FILE *fp;
	int count=1;
	int task;
	int run;
	
	returned:
	enter_again:
	task =pre_check();
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
	fp = fopen("student.txt","r");
	if(fp==NULL)
	{
		printf("\nData doesn't exist.Please enter data atleast once.\n\n");
		printf("     ENTER NUMBER AGAIN    \n");
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
	
	run_again:
	printf("\nEnter 1 if you want to run program again.\n");
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
