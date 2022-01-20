int sort_check(int *a,int n)
{
	int res=0,i=0,count=0;
	for(i=0;i<n-1;i++)
	{
		if(count == i)
		{
			if(a[i+1]>=a[i])
	     	{
	    		count++;
		    }
		}
		else
		break;
	}
	if(count == n-1)
	{
		res=1;
		return(res);
	}
	count=0;
	for(i=0;i<n-1;i++)
	{
		if(count == i)
		{
			if(a[i+1]<=a[i])
	     	{
	    		count++;
		    }
		}
		else
		break;
		
	}
	if(count == n-1)
	{
		res = -1;
		return(res);
	}
	return(res);
}
