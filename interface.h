#ifndef INTERFACE
#define INTERFACE

#include "triangulation.h"

#define colorTri MLV_COLOR_GREEN
#define IMG1 (MLV_load_image("mario.jpg"))
#define IMG2 (MLV_load_image("kratos.jpg"))

/**
 * Init the window
 */
void init_window();

/**
 * draw images
 */
void draw_image();

/**
 * Draw a textbox
 */
void draw_txtbox(int x, int y, int width,int height,char* c);

/**
 * print a triangle
 */
void printTriangle(triangle *tri);

/**
 * print the list
 */
void printList(list* l);
#endif