#include<stdio.h>
#include<stdlib.h>
#include"ass3question3b_header.h"
int menu()
{
	int ch;
	printf("\nPress 1 to print the list in same order or reverse order : \n");
	printf("\nPress 2 to print total number of nodes  :\n");
	printf("\nPress 3 to check weather two lists are equal or not  :\n");
	printf("\nPress 4 to search a key : \n");
	printf("\nPress 5 to append the list at the end of another list : \n");
	printf("\nPress 6 to delete node from list : \n");
	printf("\nPress 7 to merge to sorted lists\n");
	printf("\nPress 3 to swap elements pairwise in double linked list : \n");
	printf("\nPress 4 to move the last element to first : \n");
	printf("\nPress 5 to rotate a list : \n");
	printf("\nPress 6 to delete the alternate nodes of the list  : \n");
	printf("\nPress 7 to remove duplicants : \n");
	printf("\nPress 8 to sort a doubly linked list through bubble sort : \n");
	printf("\nPress 10 to merge two sorted linked lists : \n");
	printf("\nPress 11 to sort a doubly linked list through bubble sort  : \n");
	printf("\nYOUR CHOICE : \n");
	scanf("%d",&ch);
	return(ch);
}
int main()
{
	Node  *temp;
	Node *HEAD1=NULL;
	Node *HEAD2=NULL;
	int n,i,ch2,count,m,x;
	HEAD=initalize(HEAD,1);
	HEAD=initalize(HEAD,2);
	HEAD=initalize(HEAD,4);
	HEAD=initalize(HEAD,4);
	HEAD=initalize(HEAD,5);
	HEAD=initalize(HEAD,5);

	
	
	/*	printf("Enter total number of nodes of linked list : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		HEAD=initalize(HEAD);
	}*/
	while(1)
	{
		switch(menu())
		{
			case 1: 
			        printf("\nEnter 1 or 2 to display the list in same order or  in reverse order : \n");
			        scanf("%d",&ch2);
			        switch(ch2)
			        {
			        	case 1: temp=HEAD;
			        	
                             	display(temp);
                             	break;
                             	
                        case 2: temp=HEAD;
                             	display_rev(temp);    
								 break; 	
					}
					break;
					
			case 2: temp=HEAD;
			        count=numberofnodes(temp);
					printf("%d",count);
					break;
					
			case 3:temp=HEAD;
			       HEAD=swap(temp);	
				   break;
				   
			case 4:temp=HEAD;
			       HEAD=move(temp);
			       break;
			       
			case 5:temp=HEAD;
			       HEAD=rotate(temp); 
				   break;
				   
			case 6:temp=HEAD;
			       HEAD=del_alternate(temp);
			       break;	
				   
			case 7:temp=HEAD;	
			       printf("Press 1 if the list is sorted else press 2 : ");
			       scanf("%d",&ch2);
				   switch(ch2)
				   {
				   	  case 1: 
				   	          printf("\nchalo\n");
			                  printf("\n%d\n",HEAD->next->next->next->data);
			                  HEAD=duplicant_sort(temp);
				   	          break;
				   	  case 2: HEAD=duplicant_unsort(temp);
				   	          break;
				   }
				   break;
				   
			case 8:temp=HEAD;
			       HEAD=delete_list(temp);
				   break;    
				   
			case 9:temp=HEAD;
			       HEAD=bubble_sort(temp);
				   break;
				   
			case 10: 
                	HEAD1=initalize(HEAD1,30);
	                
					
					HEAD2=initalize(HEAD2,10);
    
			        HEAD1=merge(HEAD1,HEAD2);
			        temp=HEAD1;
                    display(temp);
			         break;	   	     
					
			case 11: merge_sort(&HEAD);		
	    }
    }
}
