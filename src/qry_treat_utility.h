#include <stdio.h>
#include "void_pointers.h"
#ifndef __QRYUTIL__
#define __QRYUTIL__ 

// Funcao que verifica se um retangulo esta inteiramente dentro de outro
int rect_is_inside(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2);

// Funcao que determina se um circulo esta dentro de outro
int circle_is_inside(float xc1, float yc1, float r1, float xc2, float yc2, float r2);

// Funcao que determina se dois retangulos sao iguais
int are_same(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);

// Funcao que retorna o maior float passado
float larger(float a, float b);

// Funcao que retorna o menor float passado
float smaller(float a, float b);

// Funcao que compara duas strings e retorna o resultado da comparacao
int compare_strings(const void* char1, const void* char2);

// Funcao que recebe uma arvore e uma lista de infos, e os insere na arvore passada
_Tree insert_points_list(_List to_insert, _Tree tree);

// Funcao que recebe uma arvore e uma lista de pontos, e os remove da arvore passada, recebe uma funcao para troca de infos
_Tree remove_points_list(_List remove_points_list, _Tree tree, void(*swap)(void*, void*));

// Funcao que recebe uma arvore e uma lista de retangulos que serao removidos, e o txt para printar os ids
_Tree remove_rect_list(_List remove_list, _Tree tree, FILE *txtFile);

// Realiza a funcao dpi do qry
_Tree dpi(_Tree rect_tree, float x, float y, FILE *txtFile, _List dpi_remove);

// Realiza a funcao dr do qry
_Tree dr(_Tree rect_tree, float *dr_point, _List dr_remove, int depth, FILE *txt_file);

// Inicializa a funcao dr
_Tree dr_init(_Tree rect_tree, float *dr_point, _List dr_remove, FILE *txt_file);

// Realiza a funcao fg do qry
_Tree fg(_Tree rect_tree, _Tree circle_tree, float point[2], float r, FILE *txtFile, FILE *svgFile, _List to_move, _List to_remove, _List carlos);

// Inicializa a funcao fg
_Tree fg_init(_Tree rect_tree, _Tree circle_tree, float point[2], float r, FILE *txtFile, FILE *svgFile, _List to_move, _List to_remove, _List carlos);
#endif /* ifndef __QRYUTIL__ */
