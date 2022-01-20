#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
    int x,i,j,a[100],loc=1,loc1=1,max,min;
    char name[100][100],temp[100];
    FILE *fp,*fp1;
    printf("Enter the number of classmates : \n");
    scanf("%d",&x);
    fp = fopen("classmates.txt","w");
    for(i=0;i<x;i++)
    {
        printf("Enter name : \t");
        scanf("%s",&name[i]);
        fprintf(fp,"%s\n",name[i]);
        a[i] = strlen(name[i]);
        printf("Size of Entered name : %d\n",a[i]);
    }
    fclose(fp);


    max = a[0];
	
	for(i=1;i<x;i++)
	{
		if (a[i] > max)
		{
			max = a[i];
            loc = i+1;
		}
	}

	printf("Maximum number of characters are present in  %s located at  %d and no. of characters are : %d.\n",name[loc-1],loc,max);
    min = a[0];
	
	for(i=1;i<x;i++)
	{
		if (a[i] < min)
		{
			min = a[i];
            loc1 = i+1;
		}
	}
	printf("Minimum number of characters are present in  %s located at  %d and no. of characters are : %d.\n",name[loc1-1],loc1,min);
	
	
    for(i=0;i<x-1;i++)
    {
    	for(j=i+1;j<x;j++)
    	{
    		if(strcmp(name[i],name[j])>0)
    		{
    			strcpy(temp,name[i]);
    			strcpy(name[i],name[j]);
    			strcpy(name[j],temp);
			}
		}
   	
    }
    fp1 = fopen("sorted_names.txt","w");

    for(i=0;i<x;i++)
    {
    	fprintf(fp,"%s\n",name[i]);
	}
}
    
