struct poly
{
    float coeff;
    int exp;
};
struct poly a[50],b[50],c[50],d[50];
int deg1,deg2;

void subtract();
void multiply();
void create_poly();
void add_poly();

void subtract()
{
    int i,m=0;
    if(deg1>deg2)
   {
       for(i=0;i<=deg2;i++)
       {
           c[m].coeff = a[i].coeff - b[i].coeff;
           c[m].exp = a[i].exp;
           m++;
       }
       for(i=deg2+1;i<=deg1;i++)
       {
           c[m].coeff = a[i].coeff;
           c[m].exp = a[i].exp;
           m++;
       }
   }
   else
   {
       for(i=0;i<=deg1;i++)
       {
           c[m].coeff = a[i].coeff - b[i].coeff;
           c[m].exp = a[i].exp;
           m++;
       }
       for(i=deg1+1;i<=deg2;i++)
       {
           c[m].coeff = b[i].coeff;
           c[m].exp = b[i].exp;
            m++;
       }
   }
   //printing the sum of the two polynomials
   printf("\nExpression after absolute subtraction  = %.1f",c[0].coeff);
   for(i=1;i<m;i++)
   {
       printf("+ %.1fx^%d",c[i].coeff,c[i].exp);
   }
}
void multiply()
{
    int i,m=0;
    if(deg1>deg2)
    {
        for(i=0;i<=deg2;i++)
        {
            c[m].coeff = a[i].coeff * b[i].coeff;
            c[m].exp = a[i].exp;
            m++;
        }
        for(i=deg2+1;i<=deg1;i++)
        {
            c[m].coeff = a[i].coeff;
            c[m].exp = a[i].exp;
            m++;
        }
    }
    else
    {
        for(i=0;i<=deg1;i++)
        {
            c[m].coeff = a[i].coeff * b[i].coeff;
            c[m].exp = a[i].exp;
            m++;
        }
        for(i=deg1+1;i<=deg2;i++)
        {
            c[m].coeff = b[i].coeff;
            c[m].exp = b[i].exp;
            m++;
         }
     }
     //printing the product of the two polynomials
     printf("\nExpression after multiplication = %.1f",c[0].coeff);
     for(i=1;i<m;i++)
     {
         printf("+ %.1fx^%d",c[i].coeff,c[i].exp);
     }
}
void create_poly()
{
    int i;

   int k=0,l=0;
   printf("Enter the highest degree of polynomial1: ");
   scanf("%d",&deg1);        //taking polynomial terms from the user
   for(i=0;i<=deg1;i++)
   {
       //entering values in coefficient of the polynomial terms
       printf("Enter the coeff of x^%d : ",i);
       scanf("%f",&a[i].coeff);
       //entering values in exponent of the polynomial terms
       a[k++].exp = i;
   }
   //taking second polynomial from the user
   printf("Enter the highest degree of polynomial2: ");
   scanf("%d",&deg2);
   for(i=0;i<=deg2;i++)
   {
       printf("Enter the coeff of x^%d : ",i);
       scanf("%f",&b[i].coeff);
       b[l++].exp = i;
   }
   //printing first polynomial
   printf("Expression 1 = %.1f ",a[0].coeff);
   for(i=1;i<=deg1;i++)
   {
       printf("+ %.1fx^%d",a[i].coeff,a[i].exp);
   }
   //printing second polynomial
   printf("\nExpression 2 = %.1f",b[0].coeff);
   for(i=1;i<=deg2;i++)
   {
        printf("+ %.1fx^%d",b[i].coeff,b[i].exp);
   }

}
void add_poly()
{
    int i,m=0;
    if(deg1>deg2)
   {
       for(i=0;i<=deg2;i++)
       {
           c[m].coeff = a[i].coeff + b[i].coeff;
           c[m].exp = a[i].exp;
           m++;
       }
       for(i=deg2+1;i<=deg1;i++)
       {
           c[m].coeff = a[i].coeff;
           c[m].exp = a[i].exp;
           m++;
       }
   }
   else
   {
       for(i=0;i<=deg1;i++)
       {
           c[m].coeff = a[i].coeff + b[i].coeff;
           c[m].exp = a[i].exp;
           m++;
       }
       for(i=deg1+1;i<=deg2;i++)
       {
           c[m].coeff = b[i].coeff;
           c[m].exp = b[i].exp;
            m++;
       }
   }
   //printing the sum of the two polynomials
   printf("\nExpression after addition  = %.1f",c[0].coeff);
   for(i=1;i<m;i++)
   {
       printf("+ %.1fx^%d",c[i].coeff,c[i].exp);
   }

}


