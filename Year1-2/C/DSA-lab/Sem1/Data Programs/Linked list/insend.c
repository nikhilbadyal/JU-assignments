
void insertAtEnd(int newData){
    Node* temp1 = new Node();
    temp1->data = newData; 
    temp1->next = NULL;

    if (head == NULL){ // empty list
        head = temp1;
        return;
    }

    Node* temp2 = new Node();
    temp2 = head;
    while(temp2->next != NULL){
        temp2 = temp2->next;
    }

    temp2->next = temp1;
} 
