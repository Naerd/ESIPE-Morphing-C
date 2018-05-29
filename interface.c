#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>

#include "interface.h"
#include "triangulation.h"


void init_window(){
	MLV_create_window("Morphing","Morphing",1024,575);
	draw_image();
	draw_txtbox(20, 530, 100, 25, "Add Points");
	draw_txtbox(140, 530, 100, 25, "Hide Points");
	draw_txtbox(260, 530, 100, 25, "Start");
	draw_txtbox(380, 530, 50, 25, "<<<");
	draw_txtbox(450, 530, 100, 25, "? Frames");
	draw_txtbox(570, 530, 50, 25, ">>>");
	draw_txtbox(640, 530, 100, 25, "Quit");
	MLV_actualise_window();
}

void draw_image(){
	MLV_draw_image(IMG1,0,0);
	MLV_draw_image(IMG2,512,0);
	MLV_actualise_window();
}

void draw_txtbox(int x, int y, int width,int height,char* c){
	MLV_draw_text_box(x,y,width,height,c,9,
		MLV_COLOR_RED,MLV_COLOR_BLACK,MLV_COLOR_WHITE,MLV_TEXT_CENTER,
		MLV_HORIZONTAL_CENTER,MLV_VERTICAL_CENTER);
}

void printTriangle(triangle* tri){
	MLV_draw_filled_circle(tri->x.coordX,tri->x.coordY,2,colorTri);
	MLV_draw_filled_circle(tri->y.coordX,tri->y.coordY,2,colorTri);
	MLV_draw_filled_circle(tri->z.coordX,tri->z.coordY,2,colorTri);
	MLV_draw_line(tri->x.coordX,tri->x.coordY,tri->y.coordX,tri->y.coordY,colorTri);
	MLV_draw_line(tri->x.coordX,tri->x.coordY,tri->z.coordX,tri->z.coordY,colorTri);
	MLV_draw_line(tri->y.coordX,tri->y.coordY,tri->z.coordX,tri->z.coordY,colorTri);
}

void printList(list *l){
	list* lst= l;
	for(;lst;lst=lst->next){
		printTriangle(lst->current);
	}
	MLV_actualise_window();
}