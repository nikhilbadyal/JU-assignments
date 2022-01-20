#include<stdio.h>
#include<stdlib.h>
#include"array.h"
int main()
{
    int arr1[] = {2,42,75,242,42,2,9,12}; //9
    int arr2[] = {10,10,20,30,30,40,50,50}; //8
    int arr3[] = {10,30,50,70,90,110}; //6
    int arr4[] = {20,40,60,80,100,120}; //5
    int arr5[] = {20,40,60,80,100}; //5
    int arr6[] = {20,20,20,20,20}; //5




   int choice,n=2;
    while(1)
    {
        printf("\n1. Enter 1 to print in same order.\n2. Enter 2 to print in reverse order.\n3. Enter 3 to know size.\n4. Enter 4 to check Equality.\n5. Enter 5 to search.");
        printf("\nEnter choice.\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: Print(arr1,9);
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
            case 6 : search_sorted(head2,9)?printf("Found"):
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
            case 13 : insert_n(head1,5,2);
                       break;
            case 14: head1 = insert(head2,499); print_same(head1);
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
