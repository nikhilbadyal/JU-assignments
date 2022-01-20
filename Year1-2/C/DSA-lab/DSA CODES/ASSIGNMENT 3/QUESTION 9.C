#include<stdio.h>
#include<stdlib.h>
struct poly
{
	int x,y;
};
int max(int a,int b)
{
	return (a>b)?a:b;
}
int min(int a,int b)
{
	return (a<b)?a:b;
}
int collinear(struct poly p1,struct poly r,struct poly p2)
{
	if(r.x <= max(p1.x,p2.x)  &&  r.x >= min(p1.x,p2.x)  &&  r.y <= max(p1.y,p2.y)  &&  r.y >= min(p1.y,p2.y))
	{
		return(1);
	}
		return(-1);
}
int orientation_check(struct poly p1,struct poly p2,struct poly r)
{
	int check,book=-1;
	check=((p2.y - p1.y)*(r.x - p2.x) - (r.y - p2.y)*(p2.x - p1.x));      //  (y2 - y1)*(x3 - x2) - (y3 - y2)*(x2 - x1)
	printf("check==========%d\n",check);
	if(check == 0   &&  collinear(p1,r,p2)==1)
	{
		printf("chal 0\n");
		return(1);
	}	
	if(check == 0   &&  collinear(p1,r,p2)==-1)
	{
		return(-1);
	}
    if(check > 0)
    {
    	printf("chal 1\n");
    	return(1);
	}
        
    if(check < 0)
    {
    	printf("chal 2\n");
		return(-1);
	}
    
}

int check_inside(int n,int *o,int m)
{
	int j,c_count=0,on_count=0;
	for(j=0;j<n;j++)
	{
		if(o[j] == 1)
		{
			c_count++;
		}
	
	}
	if(j == c_count )     //|| o[0]==0 || o[1]==0 || o[2]==0 || o[3]==0)
	{
		return(1);           //if all are 1 means the point is clocckwise according to all the lines 
	}
     
	else
	return(-1);
}
int poly_intersect(struct poly *p1,struct poly *p2,int m,int n)
{
	int i,j,p,k=1,check[m],o[100][n],c_count=0,a_count=0;
	
	for(i=0;i<n;i++)
	{
		
		for(j=1;j<=m;j++)
		{
			p=j;
			if(j==4)
			{
				p=0;
			}
			printf("\n%d.%d\n",i,j);
			printf("poly1(%d,%d) poly2(%d,%d)  point(%d,%d)\n",p1[j-1].x,p1[j-1].y,p1[p].x,p1[p].y,p2[i].x,p2[i].y);
			o[i][j]=orientation_check(p1[j-1],p1[p],p2[i]);
			printf("store=%d\n\n",o[i][j]);
			
		}
	}
	for(i=0;i<m;i++)
	check[i]=check_inside(n,o[i],m);
	printf("\nlast array: \n");
	for(i=0;i<m;i++)
	{
		printf("%d ",check[i]);
		if(check[i] == 1)
		{
			c_count++;
		}
		if(check[i] == -1)
		{
			a_count++;
		}
	}
	printf("\n%d\n",i);
	printf("\nc_count-%d\n",c_count);
	if(i == c_count)
	{
        printf("\nTHE GIVEN POLYGONS DO NOT INTERSECTS EACH OTHER BUT CONTAIN EACH OTHER: \n");
	}
	if(i == a_count )
	{
		printf("\nTHE GIVEN POLYGONS DO NOT INTERSECTS EACH OTHER : \n");
	}
	else
	{
		printf("\nTHE GIVEN POLYGONS INTERSECTS EACH OTHER : \n");
	}
}




int main()
{
	struct poly  p1[] = {{0, 0}, {0, 10}, {10, 10},{10, 0}};
	struct poly  p2[] = {{0, -5}, {10, -5}, {10, -10}, {0, -10}};
	int m,n,i;
/*	printf("\nEnter the number of coordinates of first polygon\n");
	scanf("%d",&m);
	printf("\nEnter the coordinates of first polynomial in clockwise manner : \n");
	for(i=0;i<m;i++)
	{
		printf("\n%d.coordinate : ",i+1);
		scanf("%d%d",&p1[i].x,&p1[i].y);
	}
	printf("\nEnter the number of coordinates of second polygon\n");
	scanf("%d",&n);
	printf("\nEnter the coordinates of second polynomial in clockwise manner : \n");
	for(i=0;i<n;i++)
	{
		printf("\n%d.coordinate : ",i+1);
		scanf("%d%d",&p2[i].x,&p2[i].y);
	}
	
   */
	poly_intersect(p1,p2,4,4);
	printf("\nHELLO  :\n");
	
}
