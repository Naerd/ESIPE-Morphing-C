#ifndef INTERFACE
#define INTERFACE

#define colorTri MLV_COLOR_BLUE
#define IMG1 (MLV_load_image("mario.jpg"))
#define IMG2 (MLV_load_image("kratos.jpg"))

/*#define SIZE_BOARD 512
#define SIZE_BLOCK 128
#define IMG (MLV_load_image("koala.jpg"))

*/

void init_window();
void draw_txtbox(int x, int y, int width,int height,char* c);


#endif