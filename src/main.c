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
	Tree tree = NULL;
	float points[][2] = {{30, 40}, {5, 25}, {70, 70}, {10, 12}, {50, 30}, {35, 45}};
	int *info = malloc(sizeof(int));
	*info = 2;
	int n = sizeof(points)/sizeof(points[0]);
	for (int i = 0; i < n; ++i)
	{
		tree = insert_kd_init(tree, points[i], info);
	}
	//Delete 30, 40
	tree = delete_node_init(tree, points[0]);
	float *point = get_point(tree);
	printf("%f %f\n", point[0], point[1]);
	return 0;
}
