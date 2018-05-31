#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "triangulation.h"
#include "interface.h"
#include "morphing.h"
#include <MLV/MLV_all.h>


listTransfo* transformation(int t_frames, listPoints* lp){
	int current_frames;
	listPoints* lptmp = lp;
	listTransfo* lt = NULL;
	for(current_frames = 0; current_frames < t_frames ; current_frames++){
		int t = ((float)current_frames) / t_frames;
		int i = 0;
		while(lptmp != NULL){
			float x = ((1-t)*(lptmp->left.coordX)) + (t*(lptmp->right.coordX));
			float y = ((1-t)*(lptmp->left.coordY)) + (t*(lptmp->right.coordY));
			point p = createPoint(x,y);
			lt = addPointTransfo(lt, p);
			lptmp = lptmp->next;
			i++;
		}
	}
	return lt;
}


listTransfo* createListTransfo(point p1){
	listTransfo* lt = (listTransfo*)malloc(sizeof(listTransfo));
	lt->transfo = p1;
	lt->next = NULL;
	return lt;
}

listTransfo* addPointTransfo(listTransfo* lt, point p1){
	listTransfo* lttmp = createListTransfo(p1);
	lttmp->next = lt;
	return lttmp;
}

void printLt(listTransfo* lt){
	listTransfo* tmp = lt;
	int i = 0;
	while(tmp != NULL){
		printf("PointTransfo nb %d :",i);
		printf("(%.2f : %.2f) \n",tmp->transfo.coordX, tmp->transfo.coordY);
		tmp = tmp->next;
		i++;
	}
}