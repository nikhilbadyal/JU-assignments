struct set_adt
{
	int set[MAX];
	int size;
};

struct set_adt unin(struct set_adt s1,struct set_adt s2)
{
	struct set_adt s3;
	s3.size=s1.size+s2.size;
	int i,j,m,k;
	
	/*MERGING TWO SETS*/
	for(i=0;i< s1.size;i++)
	{
		s3.set[i]=s1.set[i];
	}
	for(i=0;i< s2.size;i++)
	{
		s3.set[s1.size+i]=s2.set[i];
	}
	
	/* MAKING COMMON TERM ELEMINATE    USING BINARY SEARCH BEACAUSE ITS USES LOG2N ITERATIONS ONLY */
	int l,u,item,done=0;
	l=0;
	u=s3.size;
	for(i=0;i<s3.size;i++)
	{
		done=0;

		item=s3.set[i+1];
        while(l<=m)
        {

        	m=(l+u)/2;
        	if(s3.set[m] == item)
        	{
        		for(k=m;k<s3.size;k++)
        		{
        			s3.set[k]=s3.set[k+1];
        			done=1;
				}
				s3.size--;
			}
			if(s3.set[m] > item)
			{
				u=m-1;
			}
			else
			{
				l=m+1;
			}
			if(done == 1)
			break;
		}
	}

	return(s3);
}

struct set_adt intersection(struct set_adt s1,struct set_adt s2)
{
	struct set_adt s3;
	s3.size=s1.size+s2.size;
	int i,j,m=0;
	/*MERGING TWO ARRAYS*/
	for(i=0;i< s1.size;i++)
	{
		s3.set[i]=s1.set[i];
	}
	for(i=0;i< s2.size;i++)
	{
		s3.set[s1.size+i]=s2.set[i];
	}
	
	/*FINDING INTERSECTION*/
	for(i=0;i< s3.size;i++)
	{
		for(j=0;j<i;j++)
		{
			if(s3.set[i] == s3.set[j])
			{
				s1.set[m]=s3.set[j];
				m++;
			}
			
		}
	}
	s1.size=m;
	return(s1);
	
} 

int subset(struct set_adt big,struct set_adt small)
{
	int i,j,count=0;
	for(i=0;i< big.size;i++)
	{
		for(j=0 ;j< small.size;j++)
		{
			if(big.set[i] == small.set[j])
			{
				count++;
			}
		}
	}
	if(count == small.size)
	{
		return(1);
	}
	else
	{
		return(0);
	}
}
struct set_adt get_data()
{
    struct set_adt s;
    int i,j,ele;
    printf("Enter total number of elements in set : ");
    scanf("%d",&s.size);
    printf("Enter the elements of set : \n");
    for(i=0;i< s.size;i++)
    {
        back: scanf("%d",&ele);
    	for(j=0;j<i;j++)
    	{
    		if(ele == s.set[j])
    		{
    			printf("This element is already present enter anothher one : \n");
    			goto back;
			}
		}
		s.set[i]=ele;
	}
	return(s);
}

void display(struct set_adt s,int a)
{
	int i;
	printf("------------------%d set is---------------------\n",a);
        for(i=0;i<s.size;i++)
     	{
	    	printf("%d\n",s.set[i]);
    	}
    	printf("\n\n");
}
