#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define max(x, y) (((x) > (y)) ? (x) : (y))
#define min(x, y) (((x) < (y)) ? (x) : (y))
struct Point{
    float x;
    float y;
};
struct Line{
    struct Point p1,p2;
};

bool onLine(struct Line l1, struct Point p1){
    if(min(l1.p1.x,l1.p2.x)<=p1.x && max(l1.p1.x,l1.p2.x)>=p1.x && min(l1.p1.y,l1.p2.y)<=p1.y && max(l1.p1.y,l1.p2.y)>=p1.y )
        return true;
    return false;
}/*
float  crossProduct(const struct Point p1, const struct Point p2)
{
    return ((p1.x)*(p2.y)-(p1.y)*(p2.x));
}
float direction(struct Point p1,struct Point p2,struct Point p3)
{
    struct p11 = subtract(p2,p1);
    p21 = subtract(p3,p1);
    return crossProduct(p2-p1, p3-p1);
}*/
int direction(struct Point a, struct Point b, struct  Point c) {
   int val = (b.y-a.y)*(c.x-b.x)-(b.x-a.x)*(c.y-b.y);
   if (val == 0)
      return 0;     //colinear
   else if(val < 0)
      return 2;    //anti-clockwise direction
      return 1;    //clockwise direction
}
bool intersect(struct Line l1, struct Line l2 )
{
    float dir1 = direction(l1.p1,l1.p2,l2.p1);
    float dir2 = direction(l1.p1,l1.p2,l2.p2);
    float dir3 = direction(l2.p1,l2.p2,l1.p1);
    float dir4 = direction(l2.p1,l2.p2,l1.p2);


    if(dir1 != dir2 && dir3 != dir4)
      return true; //they are intersecting

   if(dir1==0 && onLine(l1, l2.p1)) //when p2 of line2 are on the line1
      return true;

   if(dir2==0 && onLine(l1, l2.p2)) //when p1 of line2 are on the line1
      return true;

   if(dir3==0 && onLine(l2, l1.p1)) //when p2 of line1 are on the line2
      return true;

   if(dir4==0 && onLine(l2, l1.p2)) //when p1 of line1 are on the line2
      return true;

   return false;
}
int main()
{
    struct Line l1 = {{0,5},{5,13}};
    struct Line l2 = {{1,5},{5,13}};
  //  struct Point p1 = {3,9};
  //  struct Point p2 = {6,3};


    //if(onLine(l1,p1))
    //    printf("Oh fuck");
  //  printf("%.2f",crossProduct(p1,p2));

   if(intersect(l1, l2))
   {

       printf("Lines are intersecting.\n");
   }
   else
   {

       printf("Lines are  not intersecting.\n");
   }
}
