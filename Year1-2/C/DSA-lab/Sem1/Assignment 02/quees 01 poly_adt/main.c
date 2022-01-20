// Polynomial adt to create ,add , subtract , multiply , evaluate , derivate polynomial.
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
#include"header.h"
#include"evaluate.h"
#include"derivate.h"
int main()
{
    int task,x=1;

while(x==1)
{
    printf("\nEnter 1 to create polynomial.\nEnter 2 to add polynomial.\nEnter 3 to subtract polynomial.\nEnter 4 to multiply polynomial.\nEnter 5 to evaluate."
           "\nEnter 6 to derivate polynomial  \nEnter 7 to exit \n");
    while(true)
    {
        scanf("%d",&task);
        switch(task)
        {
            case 1: create_poly();
                    printf("\n");
                    break;
            case 2: add_poly();
                    printf("\n");
                    break;
            case 3: subtract();
                    printf("\n");
                    break;
            case 4: multiply();
                    printf("\n");
                    break;
            case 5: evaluate();
                    printf("\n");
                    break;
            case 6: derivate();
                    printf("\n");
                    break;
            case 7 : exit(0);
            default : printf("Enter choose valid number.\n");

        }
    }
}
return 0;
}
