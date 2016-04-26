#include "funciones.h"


int main()
{
	FILE* fp1;
	FILE* fp2;
	char buffer[50];

	fp1 = fopen("prueba","r");
	fp2 = fopen("output","a");

	/*if(fp == NULL){
		perror("fopen:" );
	}*/
	lista* l;

	l = crear();
	printf("llego\n");
	while((fscanf(fp1,"%s",buffer)!= EOF)){
		printf("%s\n", buffer);
		agregar(l, buffer);

	}
	fclose(fp1);

	imprimir(l,fp2);

	return 0;
};