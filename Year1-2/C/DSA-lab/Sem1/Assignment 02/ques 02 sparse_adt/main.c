// Polynomial adt to create,display ,add , subtract , transpose sparse matrix
#include<stdio.h>
#include"pre_check.h"
#include"create.h"
#include"add.h"
#include"subtract.h"
#include"transpose.h"
int main()
{
    int task,x=1;

while(x==1)
{
    printf("Enter 1 to create sparse.\nEnter 2 to add sparse.\nEnter 3 to subtract.\nEnter 4 to transpose.\n ");
    task = pre_check();
    switch(task)
    {
        case 1: create_sparse();
                break;
        case 2: add_sparse();
                break;
        case 3: subtract_sparse();
                break;
        case 4: transpose();
                break;
    }
    printf("\nEnter 1 to continue.\n");
    scanf("%d",&x);
}
return 0;
}
