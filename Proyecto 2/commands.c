/*03/05/2016
 *Autores: 
 *	Manuel Gomes 11-10375
 *Descripción: Archivo con los comandos implementados en la resolución del problema
 */
#include "commands.h"
#define SEPARATOR "/"

void ls(const char *path){
    DIR *directory = opendir(path);

    if (directory != NULL){
        struct dirent *filei;

        while ((filei = readdir(directory)) != NULL){
            if (strcmp(filei->d_name, ".") == 0 || strcmp(filei->d_name, "..") == 0){
                continue;
            }

            char *buffer = malloc(strlen(path) + strlen(filei->d_name) + strlen(SEPARATOR) + 1);
            strcat(strcat(strcpy(buffer, path), SEPARATOR), filei->d_name);

            struct stat stat_buffer;

            if (stat(buffer, &stat_buffer) == 0){   
                printf("%s\n", buffer); 

                if (S_ISDIR(stat_buffer.st_mode)){
                    ls(buffer);
                }
                if (S_ISREG(stat_buffer.st_mode)){
                	printf("Se le pasa al proceso/hijo p\n");
                }
            }
            else{
                perror(NULL);
            }

            free(buffer);
        }

        closedir(directory);
    }
    else{
        perror(NULL);     
    }
}