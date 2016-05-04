/*03/05/2016
 *Autor: Manuel Gomes 11-10375
 *Descripción: Programa que lee palabras de un archivo que cumple con ciertas 
 *condiciones, cuenta las repeticiones y luego imprime todas las palabras en 
 *otro archivo junto con sus repeticiones.
 */
#include "funciones.h"

int main(int argc, char const *argv[])
{
	FILE* fp1;	//File pointer del archivo de entrada.
	FILE* fp2;	//File pointer del archivo de salida.
	char buffer[50];	
	fp1 = fopen(argv[1],"r");	
	fp2 = fopen(argv[2],"w");	

	if (fp1==NULL){
		printf("Error en abriendo el archivo de entrada.\n");
	}
	
	lista* l;	//Lista que guarda las palabras y sus repeticiones.
	l = crear();
	lista* l2;	//Lista que va a ser ordenada según el número de repeticiones.
	
	while((fscanf(fp1,"%s",buffer)!= EOF)){ //Ciclo que lee palabra por palabra
											// del archivo.
		agregar(l, buffer,1);
	}
	fclose(fp1);
	l2=ordenarR(l);
	imprimir(l2,fp2);	//Imprime en el archivo de salida.
	imprimirP(l);
	int n =contarE(l2);
	printf("LA LISTA TIENE %d\n", n);	
	fclose(fp2);
	return 0;
};
