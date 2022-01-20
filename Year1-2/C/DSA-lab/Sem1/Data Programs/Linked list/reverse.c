void  reverse(NODE* temp)
{

 //  NODE * temp=head3;
    if(temp->next==NULL) {
            head3 = temp;
            return  ;}
	reverse(temp->next);
	NODE *temp2 = temp->next;
	temp2->next = temp;
	temp->next = NULL;
//	return head3;

}
