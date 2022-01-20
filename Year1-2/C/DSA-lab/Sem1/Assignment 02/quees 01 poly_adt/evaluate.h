float poly(float *, int, float);

void evaluate();

void evaluate()
{
	float x, a[10], y1;
	int deg, i;

	printf("Enter the degree of polynomial equation: ");
	scanf("%d", &deg);

	printf("Enter the value of x for which the equation is to be evaluated: ");
	scanf("%f", &x);

	for(i=0; i<=deg; i++)
	{
		printf("Enter the coefficient of x to the power %d: ",i);
		scanf("%f",&a[i]);
	}

	y1 = poly(a, deg, x);

	printf("The value of polynomial equation for the value of x = %.2f is: %.2f",x,y1);

}
float poly(float z[], int deg, float x)
{
	float p;
	int i;

	p = z[deg];

	for(i=deg;i>=1;i--)
	{
		p = (z[i-1] + x*p);
	}

	return p;
}
