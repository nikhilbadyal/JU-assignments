float deriv(float *, int, float);

void derivate();


void derivate()
{
	float x, a[10], dy1;
	int deg, i;

	printf("Enter the degree of polynomial equation: ");
	scanf("%d", &deg);

	printf("Enter the value of x for which the equation is to be evaluated: ");
	scanf("%f", &x);

	for(i=0;i<=deg;i++)
	{
		printf("Enter the coefficient of x to the power %d: ",i);
		scanf("%f",&a[i]);
	}

	dy1 = deriv(a, deg, x);

	printf("\nThe value of the derivative of the polynomial equation at x = %.2f is: %.2f",x,dy1);
}


/* function for finding the derivative at some value of x */
float deriv(float z[], int deg, float x)
{
	float o[10], pd = 0, ps;
	int i;

	for(i=0;i<=deg;i++)
	{
		ps = pow(x, deg-(i+1));
		o[i] = (deg-i)*z[deg-i]*ps;
		pd = pd + o[i];
	}

	return pd;
}
