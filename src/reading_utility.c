#include "reading_utility.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *concat_path_file(char *path, char *fileName){
  char *concatenated = NULL;
  int pathSize = strlen(path), tamanho_nome = strlen(fileName);
  if (path[pathSize - 1] == '/') {
		concatenated = malloc(sizeof(char) * (pathSize + tamanho_nome) + 1);
		strcpy(concatenated, path);
		strcat(concatenated, fileName);
		return concatenated;
    } else {
			concatenated = malloc(sizeof(char) * (tamanho_nome + pathSize) + 2);
			strcpy(concatenated, path);
			concatenated[pathSize] = '/';
			concatenated[pathSize + 1] = '\0';
			strcat(concatenated, fileName);
			return concatenated;
    }
}

char *get_file_name(char *path){
    char *aux = strrchr(path,'/');
    if(aux == NULL){
        return strtok(path,".");
    }
	return strtok(&aux[1],".");
}

char *copy_file_name(char *origin){
	char *aux = (char *)malloc(sizeof(char) * (strlen(origin) + 1));
	char *name = NULL;
	strcpy(aux, origin);
	name = get_file_name(aux);
	return name;
}

char *copy(char *origin){
	char *copy = malloc(sizeof(char)*(strlen(origin)+1));
	strcpy(copy, origin);
	return copy;
}
