#include<stdio.h>
long long int factorial(long long int n,int x)
{
	long long int i,p=1;
	if(x==1)
	{
		if(n==1)
			return 1;
		else
			return(n*factorial(n-1,x));
	}
	else
	{
		for(i=1;i<=n;i++)
			p*=i;
		return p;
	}
	
}
int main()
{
	long long int n,i;
	int x;
	printf("Enter Number = ");
	scanf("%lld",&n);
	printf("Enter 1 for recrusive calculation and 0 for iterative ");
	scanf("%d",&x);
	i=factorial(n,x);
	printf("%lld factorial is %lld\n",n,i);
	return 0;
}
