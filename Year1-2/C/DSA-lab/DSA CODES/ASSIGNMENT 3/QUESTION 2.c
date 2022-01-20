#include <stdio.h>
#include <stdlib.h>
#include "DSA_3_1.h"

int main(){
    FILE* file;
    file = fopen("NUM_LIST","rb");
if(file == NULL){
perror("_ _Error in opening file_ _\n");
exit(1);
    }
else{
        float i;
        node* head_in_order = NULL;
        node* head_in_reverse = NULL;
        node* curr_in_order = NULL;
        node* curr_in_reverse = NULL;
init_l(head_in_order);
init_l(head_in_reverse);
        while(fread(&i,sizeof(float),1,file)){
printf("%f\n",i);
            node* temp_in_order = create(i);
            node* temp_in_reverse = create(i);
if(head_in_order == NULL) insert_front(temp_in_order,&head_in_order);
            else insert_after(temp_in_order,curr_in_order);
insert_front(temp_in_reverse,&head_in_reverse);
curr_in_order = temp_in_order;
curr_in_reverse = temp_in_reverse;
        }

print_l(head_in_order);
print_l(head_in_reverse);
    }

fclose(file);
    return 0;
}
