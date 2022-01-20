#include <stdio.h>
#include<stdbool.h>
#define max(x, y) (((x) > (y)) ? (x) : (y))
#define min(x, y) (((x) < (y)) ? (x) : (y))
#define INF 10000
struct point
{
	int x;
	int y;
};
typedef struct point Point;
bool onSegment(Point p, Point q, Point r)
{
	if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
			q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
		return true;
	return false;
}
int orientation(Point p, Point q, Point r)
{
	int val = (q.y - p.y) * (r.x - q.x) -
			(q.x - p.x) * (r.y - q.y);

	if (val == 0) return 0;
	return (val > 0)? 1: 2;
}
bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
	int d1 = orientation(p1, q1, p2);
	int d2 = orientation(p1, q1, q2);
	int d3 = orientation(p2, q2, p1);
	int d4 = orientation(p2, q2, q1);
	if (d1 != o2 && o3 != o4)
		return true;
	if (d1 == 0 && onSegment(p1, p2, q1)) return true;
	if (d2 == 0 && onSegment(p1, q2, q1)) return true;
	if (d3 == 0 && onSegment(p2, p1, q2)) return true;
	if (d4 == 0 && onSegment(p2, q1, q2)) return true;

	return false;
}
bool isInside(Point polygon[], int n, Point p)
{
	if (n < 3) return false;
	Point extreme = {INF, p.y};
	int count = 0, i = 0;
	do
	{
		int next = (i+1)%n;
		if (doIntersect(polygon[i], polygon[next], p, extreme))
		{
			if (orientation(polygon[i], p, polygon[next]) == 0)
			return onSegment(polygon[i], p, polygon[next]);

			count++;
		}
		i = next;
	} while (i != 0);

	// Return true if count is odd, false otherwise
	return count&1; // Same as (count%2 == 1)
}

// Driver program to test above functions
int main()
{

	Point polygon1[] = {{0, 0}, {10, 0}, {10, 10}, {0, 10}};
	int n = sizeof(polygon1)/sizeof(polygon1[0]);
	Point p1 = {20, 20};
	Point p2 = {50, 50};
	Point p3 = {30, 16};
	Point p4 = {50, 50};

	if(isInside(polygon1, n, p1)==0)    // p1 not inside polygon
	{
	  //  printf("P1 is not inside polygon.\n");
	    if(isInside(polygon1, n, p2)==0)  // p2 not inside polygon
	    {
	       // printf("P2 is not inside polygon.\n");
	        if(isInside(polygon1, n, p3)==0)
	        {
	    //        printf("P3 is not inside polygon.\n");
	            if(isInside(polygon1, n, p4)==0)
	            {
	                printf("Polygons don't intersect.\n");

	            }
	            else{
                  //  printf("P4 inside polygon.\n");
                    printf("Polygons intersect.\n");

	            }
	        }
	        else{
	           // printf("P3 inside polygon.\n");
	           printf("Polygons intersect.\n");
	        }
	    }
	    else{
          //  printf("P2  inside polygon.\n");
          printf("Polygons intersect.\n");
	    }
	}
	else{
        printf("Polygons intersect.\n");
	}

	return 0;
}
