#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "qry_treat_utility.h"
#include "kdtree.h"
#include "d_list.h"
#include "rect.h"
#include "circle.h"
int rect_is_inside(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2) {
	return x1 >= x2 && y1 >= y2 && x1 + w1 <= x2 + w2 && y1 + h1 <= y2 + h2;
}

float calc_distance(float x1, float y1, float x2, float y2){
    return sqrt(pow(x1 - x2,2) + pow(y1 - y2,2));
}

int circle_is_inside(float xc1, float yc1, float r1, float xc2, float yc2, float r2){
	float distance = calc_distance(xc1, yc1, xc2, yc2);
	return r1>=distance+r2;
}

int are_same(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4){
	return x1 == y1 && x2 == y2 && x3 == y3 && x4 == y4;
}

float larger(float a, float b){
    if(a>b){
        return a;
    }else{
        return b;
    }
}

float smaller(float a, float b){
    if(a<b){
        return a;
    }else{
        return b;
    }
} 

_Tree remove_points_list(_List remove_points_list, _Tree rect_tree){
	float *point;
	for(_Node node = get_first(remove_points_list); node!=NULL; node=get_next(node)){
		point = get_list_info(node);
		rect_tree = delete_node_init(rect_tree, point, swap_two_rect);
	}
	return rect_tree;
}

_Tree dr(_Tree rect_tree, float *dr_point, _List dr_remove, int depth, FILE *txt_file){
	if(is_null(rect_tree)){
		return NULL;
	}
	int cd = depth%2;
	_Rect rectangle = get_info(rect_tree);
	if(dr_point[cd] < get_rect_point(rectangle)[cd]){
		dr(get_kd_left(rect_tree), dr_point, dr_remove, depth+1, txt_file);
	}
	dr(get_kd_right(rect_tree), dr_point, dr_remove, depth+1, txt_file);
	float intRectX = get_rect_x(rectangle), intRectY = get_rect_y(rectangle), intRectW = get_rect_w(rectangle), intRectH = get_rect_h(rectangle);
	int same = are_same(dr_point[0], intRectX, dr_point[1], intRectY, dr_point[2], intRectW, dr_point[3], intRectH);
	if((rect_is_inside(intRectX, intRectY, intRectW, intRectH, dr_point[0], dr_point[1], dr_point[2], dr_point[3]) == 1) && same==0){
		fprintf(txt_file, "%s\n", get_rect_id(rectangle));
		float *point_remove = malloc(sizeof(float)*2);
		point_remove[0] = intRectX;
		point_remove[1] = intRectY;
		insert_list(point_remove, dr_remove);
	}
	return rect_tree;
}

_Tree dr_init(_Tree rect_tree, float *dr_point, _List dr_remove, FILE *txt_file){
	if(dr_point[0]==0 && dr_point[1]==0 && dr_point[2]==0 && dr_point[3]==0){
		printf("Nao foi encontrado retangulo com o id informado\n");
		return rect_tree;
	}
	return dr(rect_tree, dr_point, dr_remove, 0, txt_file);
}
