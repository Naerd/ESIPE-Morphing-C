#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <MLV/MLV_all.h>
#include "interface.h"
#include "triangulation.h"





void print_text_frames(int i, char* c); /* INTERFACE */

int main(int argc, char *argv[]){

	

	list* l = NULL;
	
	
	init_window();
	point p1;
	p1.coordX = 0.0;
	p1.coordY = 0.0;
	point p2 ;
	p2.coordX = 511.0;
	p2.coordY = 0.0;
	point p3;
	p3.coordX = 0.0;
	p3.coordY = 511.0;
	point p4;
	p4.coordX = 511.0;
	p4.coordY = 511.0;

	triangle *triBase1 = createTriangle(p1,p2,p3); 
	triangle *triBase2 = createTriangle(p2,p3,p4);
	/*printTriangle(triBase1);
	printTriangle(triBase2);
*/

	l = addTriangle(l, triBase1);
	l = addTriangle(l, triBase2);
	

	printLst(l);

	l = add_constraint_points(26,80,l);
	printList(l); /* graphic vesion*/
	printLst(l); /* non graphic version*/
  printf("lol\n");
  l = add_constraint_points(298,362,l);
  printList(l); /* graphic vesion*/
  printLst(l); /* non graphic version*/
	

	/*int yolo = 2;
	char* s="frames";
	print_text_frames(5,s);*/

	MLV_actualise_window();
	
		

  	int x_clicked, y_clicked;
    int x_clicked2, y_clicked2;

    MLV_Event event2;
    MLV_Button_state state2;
    MLV_Mouse_button button2;

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
          /*event2 = MLV_get_event(
            NULL, NULL, NULL, NULL, NULL,
            &x_clicked, &y_clicked, &button2, &state2);
          int i = -1;
  				while(event2 != MLV_MOUSE_BUTTON){
            i++;
            printf("while %d\n",i);
            event2 = MLV_get_event(
            NULL, NULL, NULL, NULL, NULL,
            &x_clicked, &y_clicked, &button2, &state2);
            if(event2 == MLV_MOUSE_BUTTON && button2 == MLV_BUTTON_LEFT && state2 == MLV_PRESSED){
              MLV_get_mouse_position(&x_clicked2, &y_clicked2);
            if(x_clicked2 > 0 && x_clicked2 < 512 && y_clicked2 > 0 && y_clicked2 < 512){
              l = add_constraint_points(x_clicked2,y_clicked2,l);
              printList(l);
              printLst(l);
              MLV_actualise_window();
            }
            }
            }
          if(event2 == MLV_MOUSE_BUTTON && button2 == MLV_BUTTON_LEFT && state2 == MLV_PRESSED){
            MLV_get_mouse_position(&x_clicked2, &y_clicked2);
            if(x_clicked2 > 0 && x_clicked2 < 512 && y_clicked2 > 0 && y_clicked2 < 512){
              l = add_constraint_points(x_clicked2,y_clicked2,l);
              printList(l);
              printLst(l);
              MLV_actualise_window();
            }
          }*/
  			}
  			/* Button Hide */ 
  			if(x_clicked > 140 && x_clicked < 240 && y_clicked > 530 && y_clicked < 555){
  				printf("HIDE !\n");
          printList(l);
          printLst(l);
          MLV_actualise_window();
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


