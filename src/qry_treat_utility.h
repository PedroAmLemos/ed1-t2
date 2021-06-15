#include <stdio.h>
#include "void_pointers.h"
#ifndef __QRYUTIL__
#define __QRYUTIL__ 

int rect_is_inside(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2);

int circle_is_inside(float xc1, float yc1, float r1, float xc2, float yc2, float r2);

int are_same(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);

float larger(float a, float b);

float smaller(float a, float b);

int inter(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2);

int compare_strings(const void* char1, const void* char2);

_Tree insert_points_list(_List to_insert, _Tree tree);

_Tree remove_points_list(_List remove_points_list, _Tree tree, void(*swap)(void*, void*));

_Tree remove_rect_list(_List remove_list, _Tree tree, FILE *txtFile);

_Tree dpi(_Tree rect_tree, float x, float y, FILE *txtFile, _List dpi_remove);

_Tree dr(_Tree rect_tree, float *dr_point, _List dr_remove, int depth, FILE *txt_file);

_Tree dr_init(_Tree rect_tree, float *dr_point, _List dr_remove, FILE *txt_file);

_Tree fg(_Tree rect_tree, _Tree circle_tree, float point[2], float r, FILE *txtFile, FILE *svgFile, _List to_move, _List to_remove, _List carlos);

_Tree fg_init(_Tree rect_tree, _Tree circle_tree, float point[2], float r, FILE *txtFile, FILE *svgFile, _List to_move, _List to_remove, _List carlos);
#endif /* ifndef __QRYUTIL__ */
