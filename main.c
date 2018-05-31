#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <MLV/MLV_all.h>
#include "interface.h"
#include "triangulation.h"
#include "morphing.h"

void print_text_frames(int i, char* c); /* INTERFACE */

int main(int argc, char *argv[]){

	list* l = NULL;
	list* l2 = NULL;
	listPoints* lp = NULL;
	listTransfo* lt = NULL;
	
	init_window();
	init_Picture(&l,&l2);
	
	printList(l); /* graphic vesion*/
	printList(l2);
  
  printList(l);
	MLV_actualise_window();
  int x_clicked, y_clicked;
  int win=-1;
	int hide =-1;
  while(win != 1){
	MLV_wait_mouse(&x_clicked, &y_clicked);
  		
		/* Button Add */
  	if(x_clicked > 20 && x_clicked < 120 && y_clicked > 530 && y_clicked < 555){
      MLV_wait_mouse(&x_clicked, &y_clicked);
      if(x_clicked < 511 && y_clicked < 511){
				float x1 = x_clicked;
				float y1 = y_clicked;
				point p = createPoint(x1,y1);
				l = add_constraint_points( &p ,l,1);
				draw_image();
				printList(l);
				printList(l2);
				int ok = -1;
				while(ok == -1){
          MLV_wait_mouse(&x_clicked, &y_clicked);
          if(x_clicked > 512 && y_clicked < 511){
						float x2 = x_clicked;
						float y2 = y_clicked;
						point p2 = createPoint(x2,y2);
						l2 = add_constraint_points( &p2 ,l2,0);
						draw_image();
						printList(l);
						printList(l2);
						lp = addPoints(lp,p,p2);
						printLp(lp); /* Test pour liste paires de points */
						printf("\n");
						ok = 1;
          }
				}
      }
  	}
  		
		/* Button Hide */ 
  		else if(x_clicked > 140 && x_clicked < 240 && y_clicked > 530 && y_clicked < 555){

			if(hide == -1){
				draw_image();
				hide = 1;
			}
			else{
				printList(l);
				printList(l2);
				hide = -1;
			}
        	}  
 
  		/* Button Start */
  		else if(x_clicked > 260 && x_clicked < 360 && y_clicked > 530 && y_clicked < 555){
  			printf("START !\n");
  			int t_frames = 10;
  			lt = transformation(t_frames,lp);
  			printLt(lt);
  		}
  		
		/* Button <<< */
  		else if(x_clicked > 380 && x_clicked < 430 && y_clicked > 530 && y_clicked < 555){
  			printf("<<< LEFT !\n");
  		}
  	
		/* Button >>> */
  		else if(x_clicked > 570 && x_clicked < 620 && y_clicked > 530 && y_clicked < 555){
  			printf(">>> RIGHT !\n");
  		}
  
		/* Button Quit */
  		else if(x_clicked > 640 && x_clicked < 740 && y_clicked > 530 && y_clicked < 555){
			freeList(l);
			freeList(l2);
  			return 0;
  		}
  		
  		MLV_actualise_window();
  	}
  	return 0;
}

void print_text_frames(int i, char* c){
	char s[100]="";
	char str[10];
	sprintf(str, " %d", i);
	strcat(s, str);
	strcat(s, c);
}