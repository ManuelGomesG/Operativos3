 #03/05/2016
 #Autor: Manuel Gomes 11-10375
 #Descripción: Makefile del proyecto, make compila y make clean 
 #borra los objatos y ejecutables relacionados.


CC=gcc
CFLAGS= -Wall

all: main.c commands.c
	$(CC) $(CFLAGS) $^ -o dshell

#main.o: main.c
#	$(CC) $(CFLAGS) -c main.c

#funciones.o:
#	$(CC) $(CFLAGS) -c funciones.c

clean:
	rm -rf *.o dshell