#include <stdbool.h>
#include <stdio.h>
#include "void_pointers.h"
#ifndef __KDTREE__
#define __KDTREE__ 

double calc_distance(float x1, float y1, float x2, float y2);
_Tree create_kdnode(float point[2], _Info info);
_Tree insert_kd(_Tree tree, float point[2], _Info info, int depth);
_Tree insert_kd_init(_Tree tree, float point[2], _Info info);
void find_point_search_key(_Tree tree, char id[], float *result);
_Info get_info(_Tree tree);
void* get_point(_Tree tree);
void print_info(_Tree tree);
_Tree get_kd_right(_Tree tree);
_Tree get_kd_left(_Tree tree);
_Tree min_node(_Tree x, _Tree y, _Tree z, int d); // Acha o minimo de tres inteiros
_Tree find_min(_Tree tree, int d, int depth); // Acha o minimo da d esima dimensao 
_Tree find_min_init(_Tree tree, int d); // Inicializa com profundidade 0
int is_equal(float point1[2], float point2[2]); // Determina se dois pontos sao iguais
void copy_point(float point1[2], float point[2]);
_Tree delete_node_init(_Tree tree, float *point, void (*swap)(_Info, _Info));
void delete_tree(_Tree tree);
bool is_null(_Tree tree);

void find_nearest_neighbor_init(_Tree tree, float *point, _Rect *result);

_Tree print_all_rect(_Tree tree);

#endif /* ifndef __KDTREE__ */
