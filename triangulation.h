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
   triangle* current;
   struct list* next;
}list;


list* createList(triangle *t);
list* addTriangle(list* lst,triangle* t);

triangle* createTriangle(point p1, point p2, point p3);
int isInside(triangle* t,point p);

void printLst(list* l); 
list* add_constraint_points(int x, int y, list* l);
 
#endif
