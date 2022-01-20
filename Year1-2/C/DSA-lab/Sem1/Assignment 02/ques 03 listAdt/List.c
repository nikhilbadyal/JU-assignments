#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include"list.h"


int main()
{
    int ch;
    int element;
    int pos;
    l.length = 0;
    while(1)
    {
        ch = menu();
        switch (ch)
        {
             case 1:   l.length = 0;
                       create();
                       break;
             case 2:
                     if (islistfull() != true)
                     {
                          printf("Enter New element: ");
                          scanf("%d", &element);
                          printf("Enter the Position : ");
                          scanf("%d", &pos);
                          insert(element, pos);
                     }
                     else
                     {
                          printf("List is Full. Cannot insert the element");
                          printf("\n Press any key to continue...");
                          getch();
                     }
                     break;
             case 3:
                     if (islistempty() != true)
                     {
                          printf("Enter the position of element to be deleted : ");
                          scanf("%d", &pos);
                          delet(pos);
                     }
                     else
                     {
                          printf("List is Empty.");
                          printf("\n Press any key to continue...");
                          getch();
                     }
                     break;
             case 4:
                     printf("No of elements in the list is %d", l.length);
                     printf("\n Press any key to continue...");
                     getch();
                     break;
             case 5:
                     printf("Enter the element to be searched : ");
                     scanf("%d", &element);
                     find(element);
                     break;
             case 6:
                     display();
                     break;
                     case 7:
                     printf("Exit");
                     exit(0);
                     break;
             default:  printf("Invalid Choice");
             printf("\n Press any key to continue...");
             getch();
        }
    }
}        //function to display the list of elements
int menu()
{
    int ch;
    printf("1. Create\n2. Insert\n3. Delete\n4. Count\n5. Find\n6. Display\n7.Exit\n\n Enter your choice : ");
    scanf("%d", &ch);
    printf("\n\n");
    return ch;
}
