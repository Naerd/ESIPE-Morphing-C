#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>
#include "triangulation.h"
#include "interface.h"



void init_window(){
	MLV_create_window("Morphing","Morphing",1024,575);
	MLV_draw_image(IMG1,0,0);
	MLV_draw_image(IMG2,512,0);
	draw_txtbox(20, 530, 100, 25, "Add Points");
	draw_txtbox(140, 530, 100, 25, "Hide Points");
	draw_txtbox(260, 530, 100, 25, "Start");
	draw_txtbox(380, 530, 50, 25, "<<<");
	draw_txtbox(450, 530, 100, 25, "? Frames");
	draw_txtbox(570, 530, 50, 25, ">>>");
	draw_txtbox(640, 530, 100, 25, "Quit");
	MLV_actualise_window();
}

void draw_txtbox(int x, int y, int width,int height,char* c){
	MLV_draw_text_box(x,y,width,height,c,9,
		MLV_COLOR_RED,MLV_COLOR_BLACK,MLV_COLOR_WHITE,MLV_TEXT_CENTER,
		MLV_HORIZONTAL_CENTER,MLV_VERTICAL_CENTER);
}


/*


void draw_split(int x, int y) {
   MLV_draw_partial_image(IMG, SIZE_BLOCK*x, SIZE_BLOCK*y, 
   	SIZE_BLOCK-4, SIZE_BLOCK-4, SIZE_BLOCK*x, SIZE_BLOCK*y);
}


void draw_split_board(int x, int y, int displayX, int displayY){
	MLV_draw_partial_image(IMG,x*SIZE_BLOCK,y*SIZE_BLOCK,SIZE_BLOCK-4,
		SIZE_BLOCK-4,displayX*SIZE_BLOCK,displayY*SIZE_BLOCK);
}


void erase_block(int x, int y) {
   MLV_draw_filled_rectangle(SIZE_BLOCK*x, 
   	SIZE_BLOCK*y, SIZE_BLOCK, SIZE_BLOCK, MLV_COLOR_BLACK);
}
*/