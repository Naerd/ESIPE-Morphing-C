#ifndef FUNCTIONS
#define FUNCTIONS

/**
 * The point structure
 */
typedef struct point{
	float coordX;
	float coordY;
}point;

/**
 * The triangle structure
 */
typedef struct triangle{
	point x;
	point y;
	point z;
}triangle;

/**
 * The list structure
 */
typedef struct list{
   triangle* current;
   struct list* next;
}list;

/**
 * The point List
 * This is still under developpment
 */
typedef struct listPoints{
	point left;
	point right;
	struct listPoints* next;
}listPoints;

/**
 * Create a listPoint with two points
 */
listPoints* createListPoints(point p1, point p2);

/**
 * Add points of each image to listPoints
 */
listPoints* addPoints(listPoints* lp, point p1, point p2);

/**
 * print the ListPoint
 */
void printLp(listPoints* lp);


/**
 * Create a triangle
 */
triangle* createTriangle(point p1, point p2, point p3);

/**
 * Add a constraint point
 * put a 1 in delauney for a delauney insertion
 */
list* add_constraint_points(point* p, list* l,int delauney);

/**
 * Create a point
 */ 
point createPoint(float x, float y);

/**
 * init the list for the two pictures
 */ 
void init_Picture(list** l, list** l2);

/**
 * Return distance from the two points 
 */ 
double distance(point p1, point p2);

/**
 * Test if two points are equals
 * Return 1 if yes otherwise 0
 */ 
int isPointEqual(point p,point p2);

/**
 * Return the neighbour of a triangle that don't have the given point
 * Return NULL if not find
 */ 
triangle* neighbour(list* l, triangle *t, point p);

/**
 * Flip the triangle to have a delaunay 
 */ 
list* flip(list* l, triangle* t, triangle* flop, point p);

/**
 * Return if two triangle are equals
 * 1 if they are, otherwise 0
 */ 
int isTriangleEqual(triangle* t, triangle* t2);

/**
 * delete a triangle
 */ 
list* delTriangle(list* lst, triangle* t);

/**
 * free a list
 */ 
void freeList(list* l);


#endif
