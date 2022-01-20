int pre_check(int n)
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
    if(n==1)
    {
        if(task>5)
	    {
	     	printf("OPS ! Invalid Entry.Please re-enter.  ");
	    	//printf("Enter Again\n");
	    	goto returned;
	    }
        return task;
    }
    if(n==2)
    {
        if(task>12)
	    {
	     	printf("OPS ! Invalid Entry.Please re-enter.  ");
	    	//printf("Enter Again\n");
	    	goto returned;
	    }
        return task;
    }
    if(n==3)
    {
        if(task>60)
	    {
	     	printf("OPS ! Invalid Entry.Please re-enter.  ");
	    	//printf("Enter Again\n");
	    	goto returned;
	    }
        return task;
    }
    if(n==4)
    {
        if(task>60)
	    {
	     	printf("OPS ! Invalid Entry.Please re-enter.  ");
	    	//printf("Enter Again\n");
	    	goto returned;
	    }
        return task;
    }
    if(n==5)
    {
        if(task>24)
	    {
	     	printf("OPS ! Invalid Entry.Please re-enter.  ");
	    	//printf("Enter Again\n");
	    	goto returned;
	    }
        return task;

    }

}
