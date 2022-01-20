#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct student
{
	int roll,score[5];
	char name[20];
};
int main()
{
	int j,i;
	struct student s;
	printf("Size of structure :%d %d",sizeof(s),sizeof(struct student));
	printf("\nEnter the roll and  name of the student.\n");
	scanf("%d %s",&s.roll,s.name);
	printf("Enter the subject of student:\n");
	for(i=0;j<5;j++)
	{
		scanf("%d",&s.score[i]);
    }
    
	return 0;
}
