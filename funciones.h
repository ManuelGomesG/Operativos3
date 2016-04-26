#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct palabra
{
	char nombre[50];
	int rep;
	struct palabra* sig;
} palabra;

typedef struct lista
{
	palabra* primeraP;
} lista;

lista* crear();
int esVaciaLista(lista* l);
void agregar(lista* l, char* pal);
void imprimir(lista* l);
