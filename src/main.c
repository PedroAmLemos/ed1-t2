#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kdtree.h"

int main(int argc, char *argv[])
{
	int i = 1;
	char *entryPath = NULL; // bed diretorio de entrada - opcional
	char *outPath	= NULL; // bsd diretorio de saida - obrigatorio 
	char *geoFile	= NULL; // arquivo de descricao, sob o diretorio bed - obrigatorio
	char *qryFile	= NULL; // arquivo de consultas, sob o diretorio bed - obrigatorio
	while(i<argc){
		if(strcmp("-e", argv[i])==0){
			i++;
			if(argv[i] == NULL){
				printf("Erro - Sem parametros em -e\n");
				exit(1);
			}
			entryPath = malloc((strlen(argv[i])+1)*sizeof(char));
			strcpy(entryPath, argv[i]);
		}
		else if(strcmp("-f",argv[i])==0){
			i++;
			if(argv[i] == NULL){
				printf("Erro - Sem Parametros em -f\n");
				exit(1);
			}
			geoFile = malloc((strlen(argv[i])+1)*sizeof(char));
			strcpy(geoFile, argv[i]);
		}
		else if(strcmp("-o",argv[i])==0){
			i++;
			if(argv[i] == NULL){
				printf("Erro - Sem Parametros em -o\n");
				exit(1);
			}
			outPath = malloc((strlen(argv[i])+1)*sizeof(char));
			strcpy(outPath, argv[i]);
		}
		else if(strcmp("-q",argv[i])==0){
			i++;
			if(argv[i] == NULL){
				printf("Erro - Sem Parametros em -q\n");
				exit(1);
			}
			qryFile = malloc((strlen(argv[i])+1)*sizeof(char));
			strcpy(qryFile, argv[i]);
		}
		i++;
	}
	_Tree tree = NULL;
	float points[][2] = {{30, 40}, {5, 25}, {70, 70}, {10, 12}, {50, 30}, {35, 45}};
	int *info1 = malloc(sizeof(int));
	int *info2 = malloc(sizeof(int));
	int *info3 = malloc(sizeof(int));
	int *info4 = malloc(sizeof(int));
	int *info5 = malloc(sizeof(int));
	int *info6 = malloc(sizeof(int));
	*info1 = 1;
	*info2 = 2;
	*info3 = 3;
	*info4 = 4;
	*info5 = 5;
	*info6 = 6;
	tree = insert_kd_init(tree, points[0], info1);
	tree = insert_kd_init(tree, points[1], info2);
	tree = insert_kd_init(tree, points[2], info3);
	tree = insert_kd_init(tree, points[3], info4);
	tree = insert_kd_init(tree, points[4], info5);
	tree = insert_kd_init(tree, points[5], info6);
	delete_tree(tree);
	return 0;
}
