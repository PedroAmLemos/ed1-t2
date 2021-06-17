#include <stdbool.h>
#include <stdio.h>
#include "void_pointers.h"
#ifndef __KDTREE__
#define __KDTREE__ 

// Funcao que recebe dois pontos e retorna a distancia entre eles
float calc_distance(float x1, float y1, float x2, float y2);

// Funcao que recebe um ponto e uma informacao e cria um node da arvore
_Tree create_kdnode(float point[2], _Info info);

// Funcao recursiva que encontra o primeiro node == NULL que recebera um a info passada
_Tree insert_kd_init(_Tree tree, float point[2], _Info info);

// Funcao que recebe um id e, de forma recursiva, encontra o ponto ao qual esse id pertence
void find_point_search_key(_Tree tree, char id[], float *result);

// Funcao que recebe um node e retorna a info
_Info get_info(_Tree tree);

// Funcao que recebe um node e retorna o ponto do node
float *get_point(_Tree tree);

// Funcao que recebe uma arvore e retorna o node da direita
_Tree get_kd_right(_Tree tree);

// Funcao que recebe uma arvore e retorna o node da esquerda
_Tree get_kd_left(_Tree tree);

// Funcao que acha o minimo de pontos
_Tree min_node(_Tree x, _Tree y, _Tree z, int d); 

// Funcao que acha o minimo da d esima dimensao 
_Tree find_min(_Tree tree, int d, int depth); 

// Funcao que inicializa com profundidade 0
_Tree find_min_init(_Tree tree, int d); 

// Funcao que determina se dois pontos sao iguais
int is_equal(float point1[2], float point2[2]); 

// Funcao que copia um ponto para outro
void copy_point(float point1[2], float point[2]);

// Inicializa a funcao recursiva que deleta o node com o ponto passado, recebe uma funcao pra realizar a troca de infos 
_Tree delete_node_init(_Tree tree, float *point, void (*swap)(_Info, _Info));

// Funcao que deleta a arvore
void delete_tree(_Tree tree);

// Funcao que retorna true caso a arvore seja nula
bool is_null(_Tree tree);

// Funcao que acha o vizinho mais proximo de um ponto passado
void find_nearest_neighbor_init(_Tree tree, float *point, _Rect *result);


#endif /* ifndef __KDTREE__ */
