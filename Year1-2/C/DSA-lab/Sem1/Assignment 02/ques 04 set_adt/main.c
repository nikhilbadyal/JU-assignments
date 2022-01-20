// Polynomial adt to create ,add , subtract , multiply , evaluate , derivate polynomial.
#include<stdio.h>
#include<math.h>
#include"header.c"
#include"pre_check.c"
#include"evaluate.c"
#include"derivate.c"
int main()
{
    int task,x=1;

while(x==1)
{
    printf("Enter 1 to create polynomial.\nEnter 2 to add polynomial.\nEnter 3 to subtract polynomial.\nEnter 4 to multiply polynomial.\nEnter 5 to evaluate.\nEnter 6 to derivate polynomial   ");
    task = pre_check();
    switch(task)
    {
        case 1: create_poly();
                break;
        case 2: add_poly();
                break;
        case 3: subtract();
                break;
        case 4: multiply();
                break;
        case 5: evaluate();
                break;
        case 6: derivate();
                break;

    }
    printf("\nEnter 1 to continue.\n");
    scanf("%d",&x);
}
return 0;
}
