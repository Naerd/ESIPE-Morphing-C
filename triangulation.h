#ifndef FUNCTIONS
#define FUNCTIONS

typedef struct point{
	float coordX;
	float coordY;
}point;

typedef struct triangle{
	point x;
	point y;
	point z;
}triangle;


typedef struct list{
   triangle triLeft;
   triangle triRight;
   struct list *next;
}list;



triangle* createTriangle(float x1,float y1, float x2, float y2, float x3, float y3);
float signe(point p1, point p2, point p3);
int PointInTriangle (point p, point p1, point p2, point p3);
int isInside(triangle* t,point p);
void printTriangle(triangle *tri);
 
#endif