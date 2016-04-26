#include "funciones.h"

int main()
{
	char hola[]="holass";
	printf("%s\n", hola);
	lista* l=crear();
	agregar(l, hola);
	agregar(l, "darks");
	agregar(l, "kkk");
	agregar(l, "kkk");
	imprimir(l);
	if (esVaciaLista(l))
	{
		printf("sirvio\n");
	}
	return 0;
}