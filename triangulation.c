#include <stdio.h>
#include <stdlib.h>
#include "triangulation.h"
#include "interface.h"
#include <MLV/MLV_all.h>


list* createList(){

	list* lst= malloc(sizeof(list*));
	lst->left =NULL;
	lst->right = NULL;
	lst->next = NULL;
	return lst;

}

int addLeftTriangle(list* lst, triangle* t){
	if(!lst->left){
		lst->left = t;
		return 0;
	}
	else{
		if(!lst->right){
			return -1;
		}
		list* l = createList();
		l->left = t;
		l->next = lst;
		lst = l;
		return 0;
	}	
}

int addRightTriangle(list* lst, triangle* t){
	if(lst->left && !lst->right){
		lst->right = t;
		return 0;
	}
	return -1;
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

void printTriangle(triangle *tri){
	MLV_draw_filled_circle(tri->x.coordX,tri->x.coordY,2,colorTri);
	MLV_draw_filled_circle(tri->y.coordX,tri->y.coordY,2,colorTri);
	MLV_draw_filled_circle(tri->z.coordX,tri->z.coordY,2,colorTri);
	MLV_draw_line(tri->x.coordX,tri->x.coordY,tri->y.coordX,tri->y.coordY,colorTri);
	MLV_draw_line(tri->x.coordX,tri->x.coordY,tri->z.coordX,tri->z.coordY,colorTri);
	MLV_draw_line(tri->y.coordX,tri->y.coordY,tri->z.coordX,tri->z.coordY,colorTri);
}

/* for Test */ 
void printLst(list* l){
	if(l == NULL){
		printf("NULL");
	}
	list* tmp = l;
	while(tmp != NULL){
		printf("p1(%.2f ; %.2f)\n",tmp->left->x.coordX, tmp->left->y.coordY);
		tmp = tmp->next;
	}
}
/*
void add_constraint_points(int x, int y, list l){
	point p;
	p.coordX=x;
	p.coordY=y;
	list lst = l;
	while(isInside(lst->left,p)!=1){
		lst = lst->next;
	}
	lst->left
}*/