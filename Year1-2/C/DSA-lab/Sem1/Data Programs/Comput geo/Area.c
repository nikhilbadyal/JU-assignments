#include<stdio.h>
#include<stdlib.h>
int Area(double X[], double Y[] , int n)
{
    double area = 0.0;
    int i;
    int j=n-1;
    for(i =0; i<n;i++)
    {
        area += (X[j]+X[i]) * (Y[j]- Y[i]);
        j=i;
    }
    return abs(area/2.0);
}
int main()
{
    double area1;
    double poly1_x[] = {0,2,4};
    double poly2_x[] = {0,4,4,0};
    double poly1_y[] = {1,3,7};
    double poly2_y[] = {0,0,4,4};
    int n= sizeof(poly1_x) / sizeof(poly1_x[0]);
    int m= sizeof(poly2_x) / sizeof(poly2_x[0]);
  //  area1 = Area(poly1_x,poly1_y,n);

    //double poly2_x[] = {0,2,4};
    //double poly2_y[] = {1,3,7};

     printf("%d\n",Area(poly1_x,poly1_y,n));
     printf("%d",Area(poly2_x,poly2_y,m));

 //  printf("%d",Area(poly1_x,poly1_y,n));
}
