NODE * remove_dup(NODE * head1)
{
    NODE * head =NULL;
    while( head1->next!=NULL)
    {
        if(head1->data!= head1->next->data)
        {
            if(head==NULL)
            {
                head = (NODE *)malloc(sizeof(NODE));
                head->data = head1->data ;
                head->next = NULL; // links the address field to NULL
                temp = head;
                head1 = head1->next;
            }
            else{NODE* temp1 = (struct node *)malloc(sizeof(NODE));
            temp1->data = head1->data;      // links the num field of fnNode with num
            temp1->next = NULL; // links the address field of fnNode with NULL

            temp->next = temp1; // links previous node i.e. tmp to the fnNode
            temp = temp->next;
            head1 = head1->next;
            }
        }
        else{
            head1 = head1->next;
        }

    }
    print_same(head);
    return head;

}
