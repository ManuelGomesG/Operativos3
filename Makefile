CC=gcc
CFLAGS=-g -Wall

all: main.o funciones.o
	$(CC) $(CFLAGS) main.o funciones.o -o frecpal

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

funciones.o:
	$(CC) $(CFLAGS) -c funciones.c

clean:
	rm -rf *.o frecpal