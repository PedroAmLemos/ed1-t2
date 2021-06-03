#ifndef __KDTREE__
#define __KDTREE__ 
#include <stdbool.h>
typedef void* Tree;
typedef void* Info;

Tree create_kdnode(float point[2], Info info);
Tree insert_kd(Tree tree, float point[2], Info info, int depth);
Tree insert_kd_init(Tree tree, float point[2], Info info);
Tree search_key(Tree tree, float point[2], int depth);
Info get_info(Tree tree);
void* get_point(Tree tree);
void print_info(Tree tree);
Tree get_right(Tree tree);
Tree get_left(Tree tree);
Tree min_node(Tree x, Tree y, Tree z, int d); // Acha o minimo de tres inteiros
Tree find_min(Tree tree, int d, int depth); // Acha o minimo da d esima dimensao 
Tree find_min_init(Tree tree, int d); // Inicializa com profundidade 0
bool is_equal(float point1[2], float point2[2]); // Determina se dois pontos sao iguais
void copy_point(float point1[2], float point[2]);
Tree delete_node(Tree tree, float point[2], int depth);
Tree delete_node_init(Tree tree, float point[2]);
#endif /* ifndef __KDTREE__ */
