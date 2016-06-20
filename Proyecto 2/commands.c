/*03/05/2016
 *Autores: 
 *	Manuel Gomes 11-10375
 *Descripción: Archivo con los comandos implementados en la resolución del problema
 */
#include "commands.h"

 void ls(char* path){
 	DIR *directory;
 	struct dirent *filei;
    struct stat stats;
 	directory = opendir(path);
 	if (directory != NULL)	
 	{
 		while ((filei=readdir(directory))!=NULL){
 			stat(filei->d_name, &stats);	
        	printf(" %s\n", filei->d_name);	
 			if (S_ISDIR(stats.st_mode)){
 				char *buf = malloc(strlen(path)+strlen(filei->d_name)+2);
 				strcpy(buf,path);
 				strcat(buf,"/");
 				strcat(buf,filei->d_name);
 				if (!strcmp(path,".") && (!strcmp(path,".."))) {
 					ls(buf);
 				}

 			}
 		}
 		closedir(directory);
 	}
 	else{
 		printf("Error.\n"); 	
 	}
}