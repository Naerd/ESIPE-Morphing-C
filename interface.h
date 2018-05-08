#ifndef INTERFACE
#define INTERFACE

#define colorTri MLV_COLOR_GREEN
#define IMG1 (MLV_load_image("mario.jpg"))
#define IMG2 (MLV_load_image("kratos.jpg"))

void init_window();
void draw_txtbox(int x, int y, int width,int height,char* c);


#endif