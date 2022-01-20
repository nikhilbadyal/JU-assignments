#include<stdio.h>
long long int arr[100]={0};
int accept()
{
	int n;
	printf("Enter an integer n : ");
	scanf("%d",&n);
	if(n<=0)
	{
		printf("Number should be positive !!!\n");
		n = accept();
	}
	return n;
}
long long int fib_iter(int x)
{
	long long int a=0,b=1,c,i;
	arr[0] = 0; arr[1] = 1;
	for(i=2;i<=x;i++)
	{
		c = a + b;
		a = b;
		b = c;
		arr[i]=c;
	}
	return arr[x-1];
}
long long int fib_rec(int x)
{
	if(arr[x]!=0)
	return arr[x];
	if(x<=1)
	return x;
	arr[x] = fib_rec(x-1) + fib_rec(x-2);
	return arr[x];
}
int main(void)
{
	int n,i,ch;
	char dig;
	n = accept();
	printf("Press 1 for iteration & 2 for recursion\n");
	retry:
	printf("Enter your choice : ");
	scanf("%d",&ch);
	if(ch==1)
	for(i=1;i<=n;i++)
	printf("%d %lld\n",i,fib_iter(i));
	else if(ch==2)
	for(i=1;i<=n;i++)
	printf("%d %lld\n",i,fib_rec(i));
	else
	{
		printf("Wrong Choice !!!\nPlease enter again\n");
		goto retry;
	}
	return 0;
}
