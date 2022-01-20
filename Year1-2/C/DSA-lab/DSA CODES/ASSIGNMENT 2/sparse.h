#define MAX 3

struct sparse_adt
{
	int arr[MAX][3];
	int row;
	int col;
};
void display(struct sparse_adt );
struct sparse_adt add_sparse(struct sparse_adt s1,struct sparse_adt s2)
{
	int i,j,k,m=0,o,cnt_i=0,cnt_j=0;
	struct sparse_adt sum;
	sum.arr[m][0]=s1.row;
	sum.arr[m][1]=s1.col;
	
	sum.arr[m][2]=0;
	
    for(i=1,j=1;(i <= s1.arr[0][2]) && (j <= s2.arr[0][2]);i++,j++)
    {
    	
    	
    	if((s1.arr[i][0] == s2.arr[j][0])  && (s1.arr[i][1] == s2.arr[j][1]))
    	{
    		m++;
    		
    		for(k=0;k<2;k++)
    		{
    			sum.arr[m][k]=s1.arr[i][k];
			}
			sum.arr[m][2]=s1.arr[i][2]+s2.arr[j][2];
        	sum.arr[0][2]++;
        	
    		
		}
		
		else if(s1.arr[i][0] == s2.arr[j][0])
		{
			m++;
			if(s1.arr[i][1] > s2.arr[j][1])
			{
			
				sum.arr[m][0]=s2.arr[j][0];
				sum.arr[m][1]=s2.arr[j][1];
				sum.arr[m][2]=s2.arr[j][2];
				i--;
				
				sum.arr[0][2]++;
			}
			else
			{
				
				sum.arr[m][0]=s1.arr[i][0];
				sum.arr[m][1]=s1.arr[i][1];
				sum.arr[m][2]=s1.arr[i][2];
				j--;
		
				sum.arr[0][2]++;
			}
		}
		
		else if(s1.arr[i][0] != s2.arr[j][0])
		{
			m++;
			if(s1.arr[i][0] > s2.arr[j][0])
			{
			
				sum.arr[m][0]=s2.arr[j][0];
				sum.arr[m][1]=s2.arr[j][1];
				sum.arr[m][2]=s2.arr[j][2];
				i--;
				
				sum.arr[0][2]++;
			}
			else
			{	
				sum.arr[m][0]=s1.arr[i][0];
				sum.arr[m][1]=s1.arr[i][1];
				sum.arr[m][2]=s1.arr[i][2];
				j--;
			
				
				
				sum.arr[0][2]++;
			}
		}
		
	    cnt_i=i;
    	cnt_j=j;
    	
    }
    
    if(cnt_j != s2.arr[0][2])
    {
    	
    	for(o=j;o<=s2.arr[0][2];o++)
    	{
    		m++;
    		
    		sum.arr[m][0]=s2.arr[o][0];
    		sum.arr[m][1]=s2.arr[o][1];
    		sum.arr[m][2]=s2.arr[o][2];
    		sum.arr[0][2]++;
		}
	}
	else if(cnt_i != s1.arr[0][2])
	{
		
		
		for(o=i;o<=s1.arr[0][2];o++)
    	{
    		m++;
    	
    		sum.arr[m][0]=s1.arr[o][0];
    		sum.arr[m][1]=s1.arr[o][1];
    		sum.arr[m][2]=s1.arr[o][2];
    		sum.arr[0][2]++;
		}
	}
	
	return(sum);
}

struct sparse_adt sub_sparse(struct sparse_adt s1,struct sparse_adt s2)
{
	int i,j,k,m=0,o,cnt_i=0,cnt_j=0;
	struct sparse_adt sub;
	sub.arr[m][0]=s1.row;
	sub.arr[m][1]=s1.col;
	
	sub.arr[m][2]=0;
	
    for(i=1,j=1;(i <= s1.arr[0][2]) && (j <= s2.arr[0][2]);i++,j++)
    {
    	
    	
    	if((s1.arr[i][0] == s2.arr[j][0])  && (s1.arr[i][1] == s2.arr[j][1]))
    	{
    		m++;
    		
    		for(k=0;k<2;k++)
    		{
    			sub.arr[m][k]=s1.arr[i][k];
			}
			sub.arr[m][2]=s1.arr[i][2]-s2.arr[j][2];
			if(sub.arr[m][2] == 0)
			{
				m--;
			}
			else if(sub.arr[m][2] != 0)
			{
				sub.arr[0][2]++;
		    }	
		}
		
		else if(s1.arr[i][0] == s2.arr[j][0])
		{
			m++;
			if(s1.arr[i][1] > s2.arr[j][1])
			{
			
				sub.arr[m][0]=s2.arr[j][0];
				sub.arr[m][1]=s2.arr[j][1];
				sub.arr[m][2]=s2.arr[j][2];
				i--;
				
				sub.arr[0][2]++;
			}
			else
			{
				
				sub.arr[m][0]=s1.arr[i][0];
				sub.arr[m][1]=s1.arr[i][1];
				sub.arr[m][2]=s1.arr[i][2];
				j--;
		
				sub.arr[0][2]++;
			}
		}
		
		else if(s1.arr[i][0] != s2.arr[j][0])
		{
			m++;
			if(s1.arr[i][0] > s2.arr[j][0])
			{
			
				sub.arr[m][0]=s2.arr[j][0];
				sub.arr[m][1]=s2.arr[j][1];
				sub.arr[m][2]=s2.arr[j][2];
				i--;
				
				sub.arr[0][2]++;
			}
			else
			{	
				sub.arr[m][0]=s1.arr[i][0];
				sub.arr[m][1]=s1.arr[i][1];
				sub.arr[m][2]=s1.arr[i][2];
				j--;
			
				
				
				sub.arr[0][2]++;
			}
		}
		
	    cnt_i=i;
    	cnt_j=j;
    	
    	
    }
    
    if(cnt_j != s2.arr[0][2])
    {
    	
    	for(o=j;o<=s2.arr[0][2];o++)
    	{
    		m++;
    		
    		sub.arr[m][0]=s2.arr[o][0];
    		sub.arr[m][1]=s2.arr[o][1];
    		sub.arr[m][2]=s2.arr[o][2];
    		sub.arr[0][2]++;
		}
	}
	else if(cnt_i != s1.arr[0][2])
	{
		
		
		for(o=i;o<=s1.arr[0][2];o++)
    	{
    		m++;
    	
    		sub.arr[m][0]=s1.arr[o][0];
    		sub.arr[m][1]=s1.arr[o][1];
    		sub.arr[m][2]=s1.arr[o][2];
    		sub.arr[0][2]++;
		}
	}
	
	return(sub);
}}

struct sparse_adt transpose(struct sparse_adt s)
{
	int i,j,round,temp,temp1,temp2,temp3;
	struct sparse_adt trans;
	temp=s.arr[0][1];
	s.arr[0][0]=s.arr[0][1];
	s.arr[0][1]=temp;
	
	for(i=1;i<=s.arr[0][2];i++)
	{
		temp=s.arr[i][0];
		s.arr[i][0]=s.arr[i][1];
		s.arr[i][1]=temp;
	}
	for(round=1; round < (s.arr[0][2]-1) ;round++)
	{
		for(i=round;i<=(s.arr[0][2]-round);i++)
		{
			if(s.arr[i][0] > s.arr[i+1][0])
			{
				temp1=s.arr[i][0];
	         	s.arr[i][0]=s.arr[i+1][0];
	     	    s.arr[i+1][0]=temp1;
	       	
	        	temp2=s.arr[i][1];
		        s.arr[i][1]=s.arr[i+1][1];
    		    s.arr[i+1][1]=temp2;
		    
	    	    temp3=s.arr[i][2];
		        s.arr[i][2]=s.arr[i+1][2];
     		    s.arr[i+1][2]=temp3;
			}
			
		}
	}
	return(s);
}
struct sparse_adt get_matrix()
{
	int i,j;
	struct sparse_adt s;
	printf("Enter sparse matrix : \n");
	printf("Enter total number of rows : \n");
	scanf("%d",&s.row);
	printf("Enter total number of columns  : \n");
	scanf("%d",&s.col);
	printf("Enter the total number of elements : \n");
	scanf("%d",&s.arr[0][2]);
	s.arr[0][0]=s.row;
	s.arr[0][1]=s.col;
	for(i=1;i<=s.arr[0][2];i++)
	{
		printf("Enter row, column and value of %d element respectively : ",i);
		for(j=0;j<3;j++)
		{
			scanf("%d",&s.arr[i][j]);
		}
	}
	return(s);
	
}

void display(struct sparse_adt s)
{
	int  i,j;

	for(i=0;i<=s.arr[0][2];i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d  ",s.arr[i][j]);
		}
		printf("\n");
		
    }
}
