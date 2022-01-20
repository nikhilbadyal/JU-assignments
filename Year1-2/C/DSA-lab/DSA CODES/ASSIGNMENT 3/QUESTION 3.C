#include<stdio.h>
#include<stdlib.h>
#include"ass3question3header.h"
int menu()
{
	int ch;
	printf("\nPress 1 to print the list in same order or reverse order : \n");
	printf("\nPress 2 to print total number of nodes  :\n");
	printf("\nPress 3 to check weather two lists are equal or not  :\n");
	printf("\nPress 4 to search a key in unsorted linked list : \n");
	printf("\nPress 5 to append the list at the end of another list : \n");
	printf("\nPress 6 to delete node from list : \n");
	printf("\nPress 7 to merge to sorted lists\n");
	printf("\nPress 8 to search a key in sorted linked list : \n");
	printf("\nPress 9 to delete duplicants from the unsorted lists : \n");
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
					
					printf("\nTotal number of nodes are %d\n",count);
					break;		
					
			case 3: printf("Enter total number of nodes in first linked list : ");
			        scanf("%d",&m);
					HEAD1=initalize(HEAD1,1);
                	HEAD1=initalize(HEAD1,2);
	                HEAD1=initalize(HEAD1,3);
	                HEAD1=initalize(HEAD1,4);
                 	HEAD1=initalize(HEAD1,5);
                 	
                 	printf("Enter total number of nodes in first linked list : ");
			        scanf("%d",&m);
			        HEAD2=initalize(HEAD2,1);
                	HEAD2=initalize(HEAD2,2);
	                HEAD2=initalize(HEAD2,3);
	                HEAD2=initalize(HEAD2,4);
                 	HEAD2=initalize(HEAD2,5);
                 	
                 	equality_check(HEAD1,HEAD2);
                 	
            case 4 : 
			          printf("\nEnter the number that you want to search : \n");	
                      scanf("%d",&x);
                      temp=HEAD;
                      count=search(temp,x);
                      printf("%d",count);
					  break;
					  
            case 5 :HEAD1=initalize(HEAD1,1);
                	HEAD1=initalize(HEAD1,2);
	                HEAD1=initalize(HEAD1,3);
	                HEAD1=initalize(HEAD1,4);    
					HEAD1=initalize(HEAD1,5);
					
					HEAD2=initalize(HEAD2,6);
                	HEAD2=initalize(HEAD2,2);
	                HEAD2=initalize(HEAD2,3);
	                HEAD2=initalize(HEAD2,4);
                 	HEAD2=initalize(HEAD2,5);
                 	
                 	append(HEAD1,HEAD2);
                 	display(HEAD1);
                 	break;
					
			case 6:	temp=HEAD;
			        HEAD=delete_node(temp);	 
			        display(HEAD);
			        break;
			        
			case 7: HEAD1=initalize(HEAD1,10);
                	HEAD1=initalize(HEAD1,30);
	                HEAD1=initalize(HEAD1,50);
	                HEAD1=initalize(HEAD1,70);    
					HEAD1=initalize(HEAD1,80);
					
					HEAD2=initalize(HEAD2,20);
                	HEAD2=initalize(HEAD2,40);
	                HEAD2=initalize(HEAD2,60);
	                HEAD2=initalize(HEAD2,90);
                 	HEAD2=initalize(HEAD2,100);    
					
					HEAD1=merge(HEAD1,HEAD2);
					display(HEAD1);  
					break;
					
			case 8: count=0;
			        temp=HEAD;
			        printf("\nEnter the number that you want to search : \n");	
                    scanf("%d",&x);
			        count=search_sorted(temp,x);
			        printf("%d",count);
			        
			        printf("\npress 1 to delete that node : \n");
			        scanf("%d",&ch2);
			        if(ch2 == 1)
			        {
			        	HEAD=delete_search(temp,count);
					}
					display(HEAD);
					break;
					
			case 9: duplicant_unsorted(HEAD);
			        display(HEAD);
			       // removeDuplicates(HEAD);
					//display(HEAD);
					break;
					
			case 10:/*printf("\nHELLO\n");
			        HEAD1=initalize(HEAD1,10);
                	HEAD1=initalize(HEAD1,30);
	                HEAD1=initalize(HEAD1,50);
	                HEAD1=initalize(HEAD1,70);    
					HEAD1=initalize(HEAD1,90);
					
					HEAD2=initalize(HEAD2,20);
                	HEAD2=initalize(HEAD2,40);
	                HEAD2=initalize(HEAD2,60);
	                HEAD2=initalize(HEAD2,80);
                 	HEAD2=initalize(HEAD2,100);	
					HEAD2=initalize(HEAD2,10);
					HEAD1=alternate_merge(HEAD1,HEAD2);
					display(HEAD1);*/	
					break;	
					
			case 11:printf("\nHELLO\n");
			        HEAD1=initalize(HEAD1,10);
                	HEAD1=initalize(HEAD1,30);
	                HEAD1=initalize(HEAD1,50);
	                HEAD1=initalize(HEAD1,70);    
					HEAD1=initalize(HEAD1,1000);
					
					HEAD2=initalize(HEAD2,10);
                	HEAD2=initalize(HEAD2,30);
	                HEAD2=initalize(HEAD2,50);
	                HEAD2=initalize(HEAD2,70);
                 	HEAD2=initalize(HEAD2,10000);	
					print_common(HEAD1,HEAD2);
					break;		  
		}
	}
	
}

