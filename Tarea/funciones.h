/*03/05/2016
 *Autor: Manuel Gomes 11-10375
 *Descripción: Estructuras y firmas de las funciones utilizadas en
 * desarrollo de la actividad.
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Nodo de la lista llamado palabra

typedef struct palabra
{
	char nombre[50];
	int rep;
	struct palabra* sig;
} palabra;
// Lista
typedef struct lista
{
	palabra* primeraP;	//primero
} lista;

lista* crear();	//Función que crea una lista
int esVaciaLista(lista* l);//Función para verificar si una lista es vacía
void agregar(lista* l, char* pal, int n);// Función que agrega unelemento al 
											// final de una lista
void imprimir(lista* l,FILE*); //Escribe en un archivo la lista
void imprimirP(lista* l);	//Imprime en pantalla los elementos de la lista
int contarE(lista* l);		// Cuenta la cantidad de elementos de la lista
lista* ordenarR(lista* l);	// Ordena los elementos de la lista
void insertar(lista* l, char* pal, int repe, int pos); //Inserta un elemento
											//en una posición dada.
