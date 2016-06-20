#include "funciones.h"



int main(int argc, char const *argv[])
{
	char buffer[2048];
	char* root=argv[1];
	printf("%s\n",root );
	char delimiter[] = " ";
	ls("pruebas");
	while (1){
		printf("prompt> ");
		scanf("%s",buffer);
		commandDet(buffer);
	}
	return 0;
}