 #03/05/2016
 #Autor: Manuel Gomes 11-10375
 #Descripción: Makefile de la tarea, make compila y make clean 
 #borra los objatos y ejecutables relacionados.
 #



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