#ifndef __READINGUTIL__
#define __READINGUTIL__ 

// Funcao qeu concatena um nome de arquivo com um caminho
char *concat_path_file(char *path, char *fileName);

// Funcao que retorna o nome de um arquivo em um path 
char *get_file_name(char *path);

// Funcao que retorna uma copia do nome de um arquivo em um path
char *copy_file_name(char *origin);

// Funcao que copia um string e retorna a copia
char *copy(char *origin);

#endif /* ifndef __READINGUTIL__ */
