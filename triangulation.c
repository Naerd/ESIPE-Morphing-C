#include <stdio.h>
#include <stdlib.h>
#include "triangulation.h"
#include "interface.h"
#include <MLV/MLV_all.h>



triangle* createTriangle(float x1,float y1, float x2, float y2, float x3, float y3){

	triangle *tri = (triangle*)malloc(sizeof(triangle));
	point p1;
	point p2;
	point p3;

	p1.coordX=x1;
	p1.coordY=y1;
	tri->x=p1;

	p2.coordX=x2;
	p2.coordY=y2;
	tri->y=p2;

	p3.coordX=x3;
	p3.coordY=y3;
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