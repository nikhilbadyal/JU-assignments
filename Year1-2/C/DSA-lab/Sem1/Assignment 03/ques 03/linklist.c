#include<stdio.h>
#include<stdlib.h>
#include"linklist.h"
NODE *head1,*head2,*head3,*head4;
int main()
{
    printf("Enter data to create list.\n");

    head1 = insert_front(head1,90);
	head1 = insert_front(head1,90);
	head1 = insert_front(head1,70);
	head1 = insert_front(head1,70);
	head1 = insert_front(head1,30);
	head1 = insert_front(head1,10);



	head2 = insert_front(head2,100);
	head2 = insert_front(head2,3);
	head2 = insert_front(head2,56);
	head2 = insert_front(head2,25);
	head2 = insert_front(head2,5);
	head2 = insert_front(head2,58);
	head2 = insert_front(head2,173);
	head2 = insert_front(head2,957);
	head2 = insert_front(head2,463);






	head3 = insert_front(head3,110);
	head3 = insert_front(head3,90);
	head3 = insert_front(head3,70);
	head3 = insert_front(head3,70);
	head3 = insert_front(head3,30);
	head3 = insert_front(head3,10);

	head4 = insert_front(head4,100);
	head4 = insert_front(head4,60);
	head4 = insert_front(head4,40);
	head4 = insert_front(head4,20);

   int choice,n=2;
    while(1)
    {
        printf("\n1. Enter 1 to print in same order.\n2."
               "Enter 2 to print in reverse order.\n3."
                "Enter 3 to know size.\n40."
                "Enter 4 to check Equality.\n5."
                "Enter 5 to search in unsorted.\n6."
                "Enter 6 to search in sorted.\n7."
                "Enter 6 to search in sorted.\n7."
                "Enter 7 to append lists.\n8."
                "Enter 8 to delete nth node.\n9."
                "Enter 9 to delete front.\n10."
                "Enter 10 to delete last.\n11."
                "Enter 11 to check sorted or not.\n12."
                "Enter 12 to sort .\n13."
                "Enter 13 to insert at n.\n14."
                "Enter 14 to insert front.\n15."
                "Enter 15 to insert at end.\n16."
                "Enter 16 to remove duplicate.\n17."
                "Enter 17 to remove duplicate.\n18."
                "Enter 18 to Move last node to front.\n19."
                "Enter 19 to delete alternative node.\n20."
                "Enter 20 to rotate.\n21."
                "Enter 21 to delete list.\n22."
                "Enter 22 to to do recursion.\n23."
                "Enter 23 to sort.\n24."
                "Enter 24 to exit.\n");


        printf("\nEnter choice.\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: print_same(head1);
                break;
            case 2: reverse_print(head1);
                    break;
             case 3: size(head1);
                    break;
            case 4: equality(head1,head1)?printf("Same"):
                                           printf("Not same");
                    break;
            case 5 : search_unsorted(head2,300)?printf("Found"):
                                             printf("Not Found");
                     break;
            case 6 : search_sorted(head4,20)?printf("Found"):
                                            printf("Not Found");
                     break;
            case 7: append_list(head1,head2);
                    break;
            case 8: delete_nth(head1,n);
                    break;
           case 9: delete_front(head1);
                    break;
             case 10: delete_last(head1);
                     break;
            case 11 : is_sorted(head1);
                      break;
            case 12 : head3 = merge_sorted(head3,head4);
                      break;
            case 13 : head1 = insert_n(head1,5,7); print_same(head1);
                       break;
            case 14: head1 = insert_front(head2,499); print_same(head1);
                      break;
            case 15: insertAtEnd(head1,10);
                       break;  // add end
            case 16 : remove_dup(head1);
                      break;
            case 17: remove_dup(head1);
                       break;
            case 18 : moveLtoF(head1);
                      break;
            case 19 : del_alt(head1);
                      print_same(head1);
                      break;
            case 20 : rotate(head1);
                      break;
            case 21:  del_list(head1);
                      break;
            case 22: head2  = recursion(head2);
	                 print_same(head2);
	                 break;
            case 23 :head2 =  merge_sort(head2);
                     print_same(head2);
                       break;
            case 24: exit(0);
        }
    }
   return 0;

}

