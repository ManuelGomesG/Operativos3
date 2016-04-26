#include "funciones.h"


lista* crear(){
	lista* l;
	l = (lista*)malloc(sizeof(lista));
	l->primeraP = NULL;
	return l;
}

int esVaciaLista(lista* l) {
	if ( l->primeraP == NULL ) {
		return 1;
	}
	return 0;
}


void agregar(lista* l, char* pal){
	palabra* aux;
	aux=l->primeraP;
	int esta=0;
	while(aux!=NULL){
		printf("pal: %s\n",pal );
		printf("comp: %s\n", aux->nombre);
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
		nuevaP->rep = 1;
		strcpy(nuevaP->nombre, pal);
		printf("Después del strcpy: %s\n", nuevaP->nombre);
		if (esVaciaLista(l))
		{
			l->primeraP=nuevaP;
			printf("Agregada (primera):%s\n", l->primeraP->nombre);
		}
		else{
			aux=l->primeraP;
			while (aux->sig != NULL){
				aux=aux->sig;
			}
			aux->sig=nuevaP;
			printf("Agregada (no primera):%s\n", aux->nombre);
		}
	}

		
}

void imprimir(lista* l){
	palabra* aux;
	aux=l->primeraP;
	while (aux != NULL){
		printf("%s %d\n",aux->nombre, aux->rep);
		aux=aux->sig;
	}
}

