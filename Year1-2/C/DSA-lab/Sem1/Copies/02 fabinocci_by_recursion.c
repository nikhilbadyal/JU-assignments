//Fibonacci Series using Recursion 
#include<stdio.h> 
int fib(int n) 
{ 
if (n <= 1) 
	return n; 
return fib(n-1) + fib(n-2); 
} 

int main () 
{ 
int n;
printf("Enter the term you want : \n");
scanf("%d",&n); 
printf("%d", fib(n-1)); 
getchar(); 
return 0; 
} 

