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
	/*float point[2] = {1, 1};*/
	/*int *info_int= malloc(sizeof(int));*/
	/**info_int = 10;*/
	/*Tree tree = create_kdnode(point, info_int);*/
	/*float* point_1_return = get_point(tree);*/
	/*printf("%f %f\n", point_1_return[0], point_1_return[1]);*/
	/*printf("%d\n", *((int*)(get_info(tree))));*/
	/*float point2[2] = {2, 2};*/
	/*int *info_int2 = malloc(sizeof(int));*/
	/**info_int2 = 11;*/
	/*tree = insert_kd_init(tree, point2, info_int2);*/
	/*float *float_2_return = get_point(get_right(tree));*/
	/*printf("%f %f\n", float_2_return[0], float_2_return[1]);*/
	/*printf("%d\n", *((int*)(get_info(get_right(tree)))));*/
	/*tree = delete_node(tree, point, 0);*/
	/*float *after = get_point(tree);*/
	/*printf("%f %f\n", after[0], after[1]);*/
	/*printf("%d\n", *((int*)(get_info(tree))));*/
	/*if(!get_right(tree)){printf("RIGHT == NULL\n");}*/
	/*if(!get_left(tree)){printf("LEFT == NULL\n");}*/
	return 0;
}
