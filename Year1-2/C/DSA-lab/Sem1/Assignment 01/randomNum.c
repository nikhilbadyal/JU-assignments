#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
int main(void)
{
	int i;
	bool arr[100000]={0};
	time_t t;
	srand((unsigned)time(&t));
	FILE *fr;
	fr = fopen("numbers.txt","w");
	for(i=0;i<100;i++)
	{
		//printf("%d\n",i);
		unsigned long long int r = rand()%100000;
		if(!arr[r])
		{	fprintf(fr,"%llu%c",r,'\n');
			arr[r]=1;
		}
		else
		i--;
	}
	fclose(fr);
	return 0;
}
