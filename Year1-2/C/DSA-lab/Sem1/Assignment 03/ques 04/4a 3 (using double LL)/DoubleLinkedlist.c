#include<stdio.h>
#include<stdlib.h>
#include"DoubleLinkedlist.h"
node *head1,*head2,*head3,*head4;
int main()
{
    head1 = InsertAtHead(head1,110);
	head1 = InsertAtHead(head1,90);
	head1 = InsertAtHead(head1,70);
	head1 = InsertAtHead(head1,70);
	head1 = InsertAtHead(head1,30);
	head1 = InsertAtHead(head1,10);


	head2 = InsertAtHead(head2,100);
	head2 = InsertAtHead(head2,3);
	head2 = InsertAtHead(head2,56);
	head2 = InsertAtHead(head2,25);
	head2 = InsertAtHead(head2,5);
	head2 = InsertAtHead(head2,58);
	head2 = InsertAtHead(head2,173);
	head2 = InsertAtHead(head2,957);
	head2 = InsertAtHead(head2,463);



	head3 = InsertAtHead(head3,90);
	head3 = InsertAtHead(head3,90);
	head3 = InsertAtHead(head3,70);
	head3 = InsertAtHead(head3,70);
	head3 = InsertAtHead(head3,10);
	head3 = InsertAtHead(head3,10);


	head4 = InsertAtHead(head4,100);
	head4 = InsertAtHead(head4,60);
	head4 = InsertAtHead(head4,40);
	head4 = InsertAtHead(head4,20);
	Print(head3);
	head2 = remove_dup(head3);
	Print(head3);

    int choice,n=2;
    while(1)
    {
        printf("\n1. Enter 1 to print in same order.\n2. Enter 2 to print in reverse order.\n3. Enter 3 to know size.\n4. Enter 4 to check Equality.\n5. Enter 5 to search.");
        printf("\nEnter choice.\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: Print(head2);
                break;
            case 2: ReversePrint(head1);
                    break;
             case 3: size(head1);
                    break;
            case 4: equality(head1,head1)?printf("Same"):
                                           printf("Not same");
                    break;
            case 5 : search_unsorted(head2,300)?printf("Found"):
                                             printf("Not Found");
                     break;
            case 6 : search_sorted(head2,9)?printf("Found"):
                                            printf("Not Found");
                     break;
            case 7: append_list(head1,head2);
                    break;
            case 8: delete(head1,n);
                    break;
           case 9: delete_front(head1);
                    break;
             case 10: delete_last(head1);
                     break;
            case 11 : is_sorted(head1);
                      break;
            case 12 : head3 = merge_sorted(head3,head4);
                      break;
            case 13 : InsertAtN(head1,5);
                       break;
            case 14: head1 = InsertAtHead(head2,499); Print(head1);
                      break;
            case 15: InsertAtTail(head1,10);
                       break;  // add end
            case 16 : remove_dup(head1);
                      break;
            case 17: remove_dup(head1);
                       break;
            case 18 : moveLtoF(head1);
                      break;
            case 19 : del_alt(head1);
                      Print(head1);
                      break;
            case 20 : rotate(head1);
                      break;
            case 21:  del_list(head1);
                      break;
         //   case 22: head2  = recursion(head2);
	      //           Print(head2);
	     //            break;
            case 23 :head2 =  merge_sort(head2);
                     Print(head2);
                       break;
            case 24: exit(0);
        }
    }
   return 0;

}

