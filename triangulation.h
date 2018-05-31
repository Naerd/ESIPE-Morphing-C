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

typedef struct listPoints{
	point left;
	point right;
	struct listPoints* next;
}listPoints;

listPoints* createListPoints(point p1, point p2);
listPoints* addPoints(listPoints* lp, point p1, point p2);
void printLp(listPoints* lp);


/*Crée un triangle*/
triangle* createTriangle(point p1, point p2, point p3);

/*Ajoute un point de contrainte dans une liste*/
list* add_constraint_points(point* p, list* l,int delawney);
 
point createPoint(float x, float y);
void init_Picture(list** l, list** l2);

/* Calcule la distance entre 2 points */
double distance(point p1, point p2);


int isPointEqual(point p,point p2);
triangle* neighbour(list* l, triangle *t, point p);
list* flip(list* l, triangle* t, triangle* flop, point p);

int isTriangleEqual(triangle* t, triangle* t2);
list* delTriangle(list* lst, triangle* t);
#endif
