/*03/05/2016
 *Autor: Manuel Gomes 11-10375
 *Descripción: Archivo con las funciones empeadas en la resolución del problema
 */

#include "funciones.h"

/*
Función que crea una lista, reservando su espacio en memoria.
*/


lista* crear(){
	lista* l;
	l = (lista*)malloc(sizeof(lista));
	l->primeraP = NULL;
	return l;
}




/*
Función que, dada una lista revisa si esta es vacía.
Una lista es vacía si no tiene primer elemento, es decir,
el apuntador al primer elemento es NULL.
*/
int esVaciaLista(lista* l) {
	if ( l->primeraP == NULL ) {
		return 1;
	}
	return 0;
}



/*
Función que agrega un elemento al final de la lista.
En este caso agrega un elemento de tipo palabra.
*/

void agregar(lista* l, char* pal, int n){
	palabra* aux;
	aux=l->primeraP;
	int esta=0;
	while(aux!=NULL){
		if (!strcmp(aux->nombre,pal))
		{
			aux->rep++;
			esta++;
		}
		aux=aux->sig;

	}
	if (esta==0)
	{
		palabra* nuevaP;
		nuevaP = (palabra*)malloc(sizeof(palabra));
		nuevaP->sig = NULL;
		nuevaP->rep = n;
		strcpy(nuevaP->nombre, pal);
		if (esVaciaLista(l))
		{
			l->primeraP=nuevaP;
		}
		else{
			aux=l->primeraP;
			while (aux->sig != NULL){
				aux=aux->sig;
			}
			aux->sig=nuevaP;
		}
	}

		
}

/*
Función que imprime en pantalla el contenido de una lista.

*/
void imprimirP(lista* l){
	palabra* aux;
	aux=l->primeraP;
	printf("-------- Inicio ----------\n");
	while (aux != NULL){
		printf("%s %d\n",aux->nombre, aux->rep);
		aux=aux->sig;
	}
	printf("--------- Fin     ----------\n");
}

/*
Función que imprime en un archivo dado el contenido de la lista
(palabras y repeticiones).
*/

void imprimir(lista* l,FILE* fp){
	palabra* aux;
	aux=l->primeraP;
	while (aux != NULL){
		fprintf(fp,"%s %d\n",aux->nombre, aux->rep);
		aux=aux->sig;
	}
}
/*

Función que cuenta la cantidad de elementos de una lista.
*/
int contarE(lista* l){
	int Ele = 0;
	palabra* aux;
	aux=l->primeraP;
	while (aux!=NULL) {
		Ele++;
		aux=aux->sig;
	}
	return Ele;
}

/*
Función que inserta un elemento en unalista en la posición dada.
*/

void insertar(lista* l, char* pal, int repe, int pos){
	palabra* aux;
	palabra* aux2;
	int i;
	aux2 = (palabra*)malloc(sizeof(palabra));
	aux2->rep=repe;
	strcpy(aux2->nombre,pal);
	aux=l->primeraP;
	if (pos==1)
	{
		aux2->sig=l->primeraP;
		l->primeraP=aux2;
	}
	else{
		for ( i = 2; i < pos; ++i)
		{
			aux=aux->sig;
		}
		aux2->sig=aux->sig;
		aux->sig=aux2;
	}
	
}
/*Función que dada una lista de palabras, genera una lista con
los mismos elementos pero estos apareceran de manera ordenada 
con respencto a los parámetros requeridos para la asignación
(número de apariciones y lyuego orden alfabetico)
*/
lista* ordenarR(lista* l){
	int ele = contarE(l);
	int i;		//Entero para iterar sobre la lista dada.
	int n;		//Entero para iterar sobre la lista creada.
	palabra* aux;
	palabra* aux2;
	lista* nuevaL;
	nuevaL = crear();
	aux2=l->primeraP;
	agregar(nuevaL,aux2->nombre,aux2->rep);
	aux2= aux2->sig;
	aux=nuevaL->primeraP;
	printf("LA PRIMERA LISTA TIENE %d\n", ele );

	/*Segundo elemento*/
	
	if (aux->rep < aux2->rep 
		|| (aux->rep == aux2->rep && strcmp(aux->nombre,aux2->nombre)))
	{
		insertar(nuevaL,aux2->nombre,aux2->rep,1);
		aux2= aux2->sig;
	}
	else 
	{
		agregar(nuevaL,aux2->nombre,aux2->rep);
		aux2= aux2->sig;
	}
	aux=nuevaL->primeraP;
	for (i = 1; i < ele-1; ++i)
	{
		n=1;
		aux=nuevaL->primeraP;
		
		printf("PALABRA: %s POS: %d\n",aux2->nombre,n );
		if (aux2->rep == aux->sig->rep)
		{
			while (aux2->rep < aux->sig->rep){
			aux=aux->sig;
			n++;
			}

			/*Cuando la palabra a insertar es viene antes.(Es mayor)*/
			if (strcmp(aux->sig->nombre,aux2->nombre) > 0)
			{
				insertar(nuevaL,aux2->nombre,aux2->rep,n);
			}
			/*El otro caso*/
			else{
				while(aux->sig!=NULL 
					&& !(strcmp(aux->sig->nombre,aux2->nombre) > 0) ){
					n++;
					aux=aux->sig;	
				}
				if (aux->sig==NULL)
				{
					agregar(nuevaL,aux2->nombre,aux2->rep);
				}
				else{
					insertar(nuevaL,aux2->nombre,aux2->rep,n);
				}
					
			}
		}
		else if (aux2->rep > aux->sig->rep)
		{
			insertar(nuevaL,aux2->nombre,aux2->rep,n);
		}
		aux2=aux2->sig;

	}
	return nuevaL;
}

