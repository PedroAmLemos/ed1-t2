#include <stdbool.h>
#include <stdio.h>
#ifndef __KDTREE__
#define __KDTREE__ 
typedef void* _Tree;
typedef void* _Info;

_Tree create_kdnode(float point[2], _Info info);
_Tree insert_kd(_Tree tree, float point[2], _Info info, int depth);
_Tree insert_kd_init(_Tree tree, float point[2], _Info info);
_Tree search_key(_Tree tree, float point[2], int depth);
_Info get_info(_Tree tree);
void* get_point(_Tree tree);
void print_info(_Tree tree);
_Tree get_kd_right(_Tree tree);
_Tree get_kd_left(_Tree tree);
_Tree min_node(_Tree x, _Tree y, _Tree z, int d); // Acha o minimo de tres inteiros
_Tree find_min(_Tree tree, int d, int depth); // Acha o minimo da d esima dimensao 
_Tree find_min_init(_Tree tree, int d); // Inicializa com profundidade 0
bool is_equal(float point1[2], float point2[2]); // Determina se dois pontos sao iguais
void copy_point(float point1[2], float point[2]);
_Tree delete_node(_Tree tree, float point[2], int depth);
_Tree delete_node_init(_Tree tree, float point[2]);
void delete_tree(_Tree tree);
//void print_circle_to_svg(FILE *svgFile, _Tree tree);
//void print_rect_to_svg(FILE *svgFile, _Tree tree);
bool is_null(_Tree tree);

#endif /* ifndef __KDTREE__ */
