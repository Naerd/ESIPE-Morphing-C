CC=gcc
CFLAGS=-Wall -ansi
LDFLAGS=-lMLV
SRC=main.c interface.c triangulation.c
OBJ=$(SRC:%.c=%.o)

main: $(OBJ)
	$(CC) -o main $(OBJ) $(CFLAGS) $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS) $(LDLIBS) -lm

clean: 
	rm -f *.o
	rm -f *~
	rm -f main

