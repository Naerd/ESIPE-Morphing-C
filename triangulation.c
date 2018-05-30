#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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
	int i = 0;
	while(tmp != NULL){
		printf("Tri n°%d : ",i);
		printf("p1(%.2f : %.2f) | ",tmp->current->x.coordX, tmp->current->x.coordY);
		printf("p2(%.2f : %.2f) | ",tmp->current->y.coordX, tmp->current->y.coordY);
		printf("p3(%.2f : %.2f) \n",tmp->current->z.coordX, tmp->current->z.coordY);
		tmp = tmp->next;
		i++;
	}
}

list* add_constraint_points(point* p2, list* l){

	point p = *p2;
	list* lst = l;

	if(isInside(lst->current,p)==1){
		printf("du premier coup\n");
		triangle *t1 = createTriangle(p,lst->current->x, lst->current->y);
		triangle *t2 = createTriangle(p,lst->current->y, lst->current->z);;
		triangle *t3 = createTriangle(p,lst->current->z, lst->current->x);;
	
		lst->current = t1;
		l = addTriangle(l,t2);
		l = addTriangle(l,t3);
		return l;
	}
	while(isInside(lst->next->current,p)!=1 && lst){
		lst = lst->next;
	}
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

point createPoint(float x, float y){

	point p;
	p.coordX = x;
	p.coordY = y;
	return p;
}

void init_Picture(list** l, list** l2){
	point p1 = createPoint(0.0,0.0);
	point p2 = createPoint(511.0,0.0);
	point p3 = createPoint(0.0,511.0);
	point p4 = createPoint(511.0,511.0);
	

	triangle *triBase1 = createTriangle(p1,p2,p3); 
	triangle *triBase2 = createTriangle(p2,p3,p4);

	*l = addTriangle(*l, triBase1);
	*l = addTriangle(*l, triBase2);

	point p5 = createPoint(512.0,0.0);
	point p6 = createPoint(1023.0,0.0);
	point p7= createPoint(512.0,511.0);
	point p8 = createPoint(1023.0,511.0);
	

	triangle *triBase3 = createTriangle(p5,p6,p7); 
	triangle *triBase4 = createTriangle(p6,p7,p8);

	*l2 = addTriangle(*l2, triBase3);
	*l2 = addTriangle(*l2, triBase4);
} 

double distance(point p1, point p2){
	return sqrt(pow((p2.coordX-p1.coordX),2.0)+pow((p2.coordY-p1.coordY),2.0));
}


int isPointEqual(point p,point p2){
	if(p.coordX != p2.coordX)
		return 0;
	if(p.coordY != p2.coordY)
		return 0;
	return 1;

}


triangle* neighbour(list* l, triangle *t, point p){

	point p2, p3;
	list* lst = l;
	if(isPointEqual(t->x, p) == 1){
		p2 = t->y;
		p3 = t->z;
	}
	else if(isPointEqual(t->y, p) == 1){
		p2 = t->x;
		p3 = t->z;
	}
	else if(isPointEqual(t->z, p) == 1){
		p2 = t->x;
		p3 = t->y;
	}
	else{
		return NULL;
	}
	while(lst != NULL){
		if(lst->current != t){
			if(

				(
				isPointEqual(lst->current->x , p2)==1 ||
				isPointEqual(lst->current->y , p2)==1 ||
				isPointEqual(lst->current->z , p2)==1
				)

			){

				if(	
					(
					isPointEqual(lst->current->x , p3)==1 ||
					isPointEqual(lst->current->y , p3)==1 ||
					isPointEqual(lst->current->z , p3)==1
					) 

				){
					return lst->current;
				}
			}
		}
		lst = lst->next;
	}
	return NULL;
}


list* flip(list* l, point p){
	list* lst = l;
	


	while(lst->next != NULL){
		if(isInside(lst->current,p)==1){
			triangle* flop = neighbour(l,lst->current,p);
			if(flop){
				point oppos;
				point partage1,partage2;
	
	
				if(isPointEqual(lst->current->x , p)==1){
					partage1 = lst->current->y;
					partage2 = lst->current->z;
				}else if(isPointEqual(lst->current->y , p)==1){
					partage1 = lst->current->x;
					partage2 = lst->current->z;
				}else if(isPointEqual(lst->current->z , p)==1){
					partage1 = lst->current->x;
					partage2 = lst->current->y;
				}else{
					return NULL;
				}
	
				if(isPointEqual(flop->x , partage1)!=1 && isPointEqual(flop->x , partage2)!=1){
					oppos = flop->x;
				}else if(isPointEqual(flop->y , partage1)!=1 && isPointEqual(flop->y , partage2)!=1){
					oppos = flop->y;
				}else if(isPointEqual(flop->z , partage1)!=1 && isPointEqual(flop->z , partage2)!=1){
					oppos = flop->z;
				}else{
					return NULL;
				}
	
	
				float dist1 =distance(partage1, partage2);
				float dist2 = distance(p,oppos);
				if(dist1 > dist2){
					triangle* t1 = createTriangle(p,oppos,partage1);
					triangle* t2 = createTriangle(p,oppos,partage2);
					
					l= delTriangle(l, flop);
					l= delTriangle(l, lst->current);
					l= addTriangle(l, t1);
					l= addTriangle(l, t2);
					
				}
			}
		}
		lst = lst->next;
	}

	return l;
}

int isTriangleEqual(triangle* t, triangle* t2){
	if(isPointEqual(t->x,t2->x)==1 || isPointEqual(t->x,t2->y)==1 || isPointEqual(t->x,t2->z)==1){
		if(isPointEqual(t->y,t2->x)==1 || isPointEqual(t->y,t2->y)==1 || isPointEqual(t->y,t2->z)==1){
			if(isPointEqual(t->z,t2->x)==1 || isPointEqual(t->z,t2->y)==1 || isPointEqual(t->z,t2->z)==1){
				return 1;
			}
		}
	}
	return 0;
}
list* delTriangle(list* lst, triangle* t){
	list* l = lst;
	if(isTriangleEqual(l->current,t)==1){
		return l->next;
	}
	while(l->next){
		if(isTriangleEqual(l->next->current,t)==1){
			if(l->next->next){
				list* l2= l->next->next;
				l->next = l2;	
			}
			else{
				l->next = NULL;
			}
			return lst; 
		}
		l = l->next;
	}
	return lst;

}


