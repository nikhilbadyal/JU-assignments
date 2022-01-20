#include<stdio.h>
#include<stdlib.h>
#include"CircularLinkedlist.h"
int main()
{
    //?? delete list
    // sort
    int n=3;
	struct Node *head1 = NULL;

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




	head3 = insert_front(head3,90);
	head3 = insert_front(head3,90);
	head3 = insert_front(head3,70);
	head3 = insert_front(head3,70);
	head3 = insert_front(head3,30);
	head3 = insert_front(head3,10);



	head4 = insert_front(head4,100);
	head4 = insert_front(head4,60);
	head4 = insert_front(head4,40);
	//head4 = insert_front(head4,20);
	/*head4 = insert_front(head4,20);
	head4 = insert_front(head4,30);
	head4 = insert_front(head4,40);
	head4 = insert_front(head4,50);
	head4 = insert_front(head4,600);*/

   print_same(head2);
   recursion(head2);
  //  print_same(head2);
  //  head2 = moveFtoL(head2);
  // print_same(head2);
	return 0;
}
