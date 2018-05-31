#ifndef MORPHING
#define MORPHING

typedef struct listTransfo{
	point transfo;
	struct listTransfo* next;
}listTransfo;

listTransfo* transformation(int t_frames, listPoints* lp);
listTransfo* createListTransfo(point p1);
listTransfo* addPointTransfo(listTransfo* lp, point p1);
void printLt(listTransfo* lt);

#endif
