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

/*Initialise la liste*/
list* createList(triangle *t);

/*Ajoute un triangle a la liste*/
list* addTriangle(list* lst,triangle* t);

/*Crée un triangle*/
triangle* createTriangle(point p1, point p2, point p3);

/*Teste si un point appartient a un triangle*/
int isInside(triangle* t,point p);

/*Affiche la liste sur la console*/
void printLst(list* l); 

/*Ajoute un point de contrainte dans une liste*/
list* add_constraint_points(point* p, list* l);
 
point createPoint(float x, float y);
void init_Picture(list** l, list** l2);

/* Calcule la distance entre 2 points */
double distance(point *p1, point *p2);


int isPointEqual(point p,point p2);
triangle* neighbour(list* l, triangle *t, point p);

#endif
