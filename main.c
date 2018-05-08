#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <MLV/MLV_all.h>
#include "interface.h"
#include "triangulation.h"





void print_text_frames(int i, char* c); /* INTERFACE */

int main(int argc, char *argv[]){

	
	printf("test list\n");
	list* l = createList();
	int test;
	
	
	init_window();
	point p1;
	p1.coordX = 0.;
	p1.coordY = 0.;
	point p2 ;
	p2.coordX = 511.0;
	p2.coordY = 0.;
	point p3;
	p3.coordX = 0.;
	p3.coordY = 511.0;
	point p4;
	p4.coordX = 511.0;
	p4.coordY = 511.0;

	triangle *triBase1 = createTriangle(p1,p2,p3); 
	triangle *triBase2 = createTriangle(p2,p3,p4);
	printTriangle(triBase1);
	printTriangle(triBase2);

	test=addLeftTriangle(l, triBase1);
	test=addLeftTriangle(l, triBase2);
	printLst(l);

	/*int yolo = 2;
	char* s="frames";
	print_text_frames(5,s);*/

	MLV_actualise_window();
	

  	int x_clicked, y_clicked;
  	MLV_Event event;
  	MLV_Button_state state;
  	MLV_Mouse_button button;
  	int win=-1;

  	while(win != 1){
  	event = MLV_get_event(
  		NULL, NULL, NULL, NULL, NULL,
  		&x_clicked, &y_clicked, &button, &state);
  	

  		if(event == MLV_MOUSE_BUTTON && button == MLV_BUTTON_LEFT && state == MLV_PRESSED){
  			MLV_get_mouse_position(&x_clicked, &y_clicked);
  			/* Button Add */
  			if(x_clicked > 20 && x_clicked < 120 && y_clicked > 530 && y_clicked < 555){
  				printf("ADD !\n");
  			}
  			/* Button Hide */ 
  			if(x_clicked > 140 && x_clicked < 240 && y_clicked > 530 && y_clicked < 555){
  				printf("HIDE !\n");
  			}
  			/* Button Start */
  			if(x_clicked > 260 && x_clicked < 360 && y_clicked > 530 && y_clicked < 555){
  				printf("START !\n");
  			}
  			/* Button <<< */
  			if(x_clicked > 380 && x_clicked < 430 && y_clicked > 530 && y_clicked < 555){
  				printf("<<< LEFT !\n");
  			}
  			/* Button >>> */
  			if(x_clicked > 570 && x_clicked < 620 && y_clicked > 530 && y_clicked < 555){
  				printf(">>> RIGHT !\n");
  			}
  			/* Button Quit */
  			if(x_clicked > 640 && x_clicked < 740 && y_clicked > 530 && y_clicked < 555){
  				return 0;
  			}
  		}

  		MLV_actualise_window();
  	}
  	return 0;


  	/*triangle* tri = createTriangle(0.0,0.0,2.0,2.0,2.0,0.0);
    printTriangle(tri);
    point p;
    p.coordX = 1.0;
    p.coordY = 1.0;
    point p2;
    p2.coordX = 7.0;
    p2.coordY = 1.0;
    printf("is inside p ? %d\n",isInside(tri,p));
    printf("is inside p2 ? %d\n",isInside(tri,p2));*/

}




void print_text_frames(int i, char* c){
	char s[100]="";
	char str[10];
	sprintf(str, " %d", i);
	strcat(s, str);
	strcat(s, c);
}

/*

Fonction du bouton --> TODO;
Fonction récuperer coordonnée cliquer et séparer en triangle --> TODO;

*/


