#include<stdio.h>
#include"pre_check.h"
#include"linklist.h"
int main()
{
    int task,x=1,n;
    NODE *here;

while(x==1)
{
    printf("Enter 1 to create list.\nEnter 2 to delete.\nEnter 3 to check if last node.\nEnter 4 to check Emptiness.\nEnter 5 to insert after.\nEnter 6 to delete front.\nEnter 7 to delete after.\n");
    task = pre_check();
    switch(task)
    {
        case 1: here = create_list();
                break;
        case 2: here = delete_front(here);
                print(here);
                break;
        case 3: is_last(here);
                break;
        case 4: is_empty();
                break;
        case 5: insert_front(here,19);
                break;
        case 6: delete_front(here);
                break;
        default : "Enter correctly.\n";
    }
    printf("\nEnter 1 to continue.\n");
    scanf("%d",&x);
}
return 0;
}
