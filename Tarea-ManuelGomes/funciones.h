/*03/05/2016
 *Autor: Manuel Gomes 11-10375
 *Descripción: Estructuras y firmas de las funciones utilizadas en
 * desarrollo de la actividad.
 */


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
	palabra* primeraP;	//primero
} lista;

lista* crear();
int esVaciaLista(lista* l);
void agregar(lista* l, char* pal, int n);
void imprimir(lista* l,FILE*);
void imprimirP(lista* l);
int contarE(lista* l);
lista* ordenarR(lista* l);
void insertar(lista* l, char* pal, int repe, int pos);
