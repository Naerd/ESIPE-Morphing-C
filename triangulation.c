#include <stdio.h>
#include <stdlib.h>
#include "triangulation.h"
#include "interface.h"
#include <MLV/MLV_all.h>


list* createList(triangle* t){

	list* lst= malloc(sizeof(list*));
	lst->current = t;
	lst->next = NULL;
	return lst;

}

list* addTriangle(list* lst, triangle* t){
	list* l = createList(t);
	l->next = lst;
	return l;	
}


triangle* createTriangle(point p1, point p2, point p3){
	triangle *tri = (triangle*)malloc(sizeof(triangle));
	tri->x=p1;
	tri->y=p2;
	tri->z=p3;

	return tri;
}

float signe(point p1, point p2, point p3){
    return (p1.coordX - p3.coordX) * (p2.coordY- p3.coordY) - (p2.coordX - p3.coordX) * (p1.coordY - p3.coordY);
}

int PointInTriangle (point p, point p1, point p2, point p3){
    int s1;
    int s2;
    int s3;
    
    s1 = signe(p, p1, p2) < 0;
    s2 = signe(p, p2, p3) < 0;
    s3 = signe(p, p3, p1) < 0;
    
    return ((s1 == s2) && (s2 == s3));
}
int isInside(triangle* t,point p){
	return PointInTriangle(p,t->x,t->y,t->z);
}




void printLst(list* l){
	list* tmp = l;
	while(tmp != NULL){
		printf("p1(%.2f : %.2f) \n",tmp->current->x.coordX, tmp->current->x.coordY);
		tmp = tmp->next;
	}
}

list* add_constraint_points(int x, int y, list* l){
	


	point p;
	p.coordX=x;
	p.coordY=y;
	list* lst = l;

	if(isInside(lst->current,p)==1){
		printf("du premier coup\n");
		triangle *t1 = createTriangle(p,lst->current->x, lst->current->y);
		triangle *t2 = createTriangle(p,lst->current->y, lst->current->z);;
		triangle *t3 = createTriangle(p,lst->current->z, lst->current->x);;
	
		lst->current = t1;
		l =  addTriangle(l,t2);
		l = addTriangle(l,t3);
		return l;
	}
	while(isInside(lst->next->current,p)!=1 && lst){
		lst = lst->next;
	}
	if(isInside(lst->next->current,p)!=1)
		printf("it work\n");
	triangle* t = lst->next->current;
	if(!lst->next->next)
		lst->next =NULL;
	else
		lst->next = lst->next->next;

	
	triangle *t1 = createTriangle(p,t->x, t->y);
	triangle *t2 = createTriangle(p,t->y, t->z);;
	triangle *t3 = createTriangle(p,t->z, t->x);
	l =  addTriangle(l,t1);
	l =  addTriangle(l,t2);
	l =  addTriangle(l,t3);
	return l;
}