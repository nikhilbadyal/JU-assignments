#include<stdio.h>
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
        printf("Please enter a positive number.  ");
    } else {
        break;
    }
    }
    //check2:
	if(task>5)
	{
		printf("OPS ! Invalid Entry.Please re-enter.  ");
		//printf("Enter Again\n");
		goto returned;
	}
	return task;
}
