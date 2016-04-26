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

void imprimir(lista* l,FILE* fp){
	palabra* aux;
	aux=l->primeraP;
	while (aux != NULL){
		fprintf(fp,"%s %d\n",aux->nombre, aux->rep);
		aux=aux->sig;
	}
}

