#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "qry_treat_utility.h"
#include "kdtree.h"
#include "d_list.h"
#include "rect.h"
#include "circle.h"
int rect_is_inside(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2) {
	return x1 >= x2 && y1 >= y2 && x1 + w1 <= x2 + w2 && y1 + h1 <= y2 + h2;
}

int circle_is_inside(float xc1, float yc1, float r1, float xc2, float yc2, float r2){
	float distance = calc_distance(xc1, yc1, xc2, yc2);
	return r1>=distance+r2;
}

int point_is_inside_circle(float x1, float y1, float x2, float y2, float r){
	return calc_distance(x1, y1, x2, y2)>=r;
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

_Tree remove_points_list(_List remove_points_list, _Tree tree, void(*swap)(void*, void*)){
	float *point;
	for(_Node node = get_first(remove_points_list); node!=NULL; node=get_next(node)){
		point = get_list_info(node);
		tree = delete_node_init(tree, point, swap);

	}
	return tree;
}

_Tree insert_points_list(_List to_insert, _Tree tree){
	float *point;
	_Circle circle = NULL;
	for(_Node node = get_first(to_insert); node!=NULL; node=get_next(node)){
		circle = get_list_info(node);
		point = get_circle_point(circle);
		tree = insert_kd_init(tree, point, circle);
	}
	return tree;

}

_Tree dr(_Tree rect_tree, float *dr_point, _List dr_remove, int depth, FILE *txt_file){
	if(is_null(rect_tree)){
		return NULL;
	}
	int cd = depth%2;
	_Rect rectangle = get_info(rect_tree);
	if(dr_point[cd] < get_rect_point(rectangle)[cd])
		dr(get_kd_left(rect_tree), dr_point, dr_remove, depth+1, txt_file);
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

_Tree fg(_Tree rect_tree, _Tree circle_tree, float point[2], float r, FILE *txtFile, FILE *svgFile, _List to_move, _List to_remove, _List carlos){
	// lista para o print --> lprint
	if(is_null(circle_tree)){
		return NULL;
	}
	fg(rect_tree, get_kd_right(circle_tree), point, r, txtFile, svgFile, to_move, to_remove, carlos);
	fg(rect_tree, get_kd_left(circle_tree), point, r, txtFile, svgFile, to_move, to_remove, carlos);

	_Circle circle = get_info(circle_tree);
	_Circle copy_circle = NULL;
	_Rect near_rect = NULL;
	float *circlePoint = get_circle_point(circle);
	find_nearest_neighbor_init(rect_tree, circlePoint, &near_rect);
	float centerX = get_rect_x(near_rect) + get_rect_w(near_rect)/2;
	float centerY = get_rect_y(near_rect) + get_rect_h(near_rect)/2;
	float distance = calc_distance(centerX, centerY, circlePoint[0], circlePoint[1]);
	if(point_is_inside_circle(point[0], point[1], circlePoint[0], circlePoint[1], r)==0&&distance!=0){
		_List aux = NULL; 

		for(_Node node = get_first(carlos); node!=NULL; node=get_next(node)){
			if(strcmp(get_rect_id(near_rect), get_list_info(get_first(get_list_info(node))))==0){
				aux = get_list_info(node);
				break;
			}
		}

		if(aux == NULL){
			aux = create_list();
			insert_list(get_rect_id(near_rect), aux);
			insert_list(aux, carlos);
		}
		insert_list(get_circle_id(circle), aux);
		float destinyX = get_rect_x(near_rect)+(get_rect_w(near_rect))/2;
		float destinyY = get_rect_y(near_rect)+(get_rect_h(near_rect))/2;
		char copyId[40], copyBc[40], copyPc[40];
		strcpy(copyId, get_rect_id(circle)); 
		strcpy(copyBc, get_circle_bc(circle));
		strcpy(copyPc, get_circle_pc(circle));
		copy_circle = create_circle(copyId, copyBc, copyPc, destinyX, destinyY, get_circle_r(circle));
		change_circle_state(copy_circle, 1);
		change_circle_origin(copy_circle, get_circle_point(circle));
		_Circle test = NULL;
		bool flag = true;
		for(_Node node = get_first(to_move); node != NULL; node = get_next(node)){
			test = get_list_info(node);
			if(strcmp(get_circle_id(test), copyId)==0){
				flag = false;
				break;
			}
		}
		if(flag){
			insert_list(copy_circle, to_move);
			add_n(near_rect);
		}else{
			free(copy_circle);
		}
		bool flag2 = true;
		for(_Node node = get_first(to_remove); node != NULL; node = get_next(node)){
			test = get_list_info(node);
			if(get_list_info(node)==get_circle_point(circle)){
				flag = false;
				break;
			}
		}
		if(flag2){
			insert_list(get_circle_point(circle), to_remove);
		}
		return circle_tree;
	}
	return circle_tree;
}


_Tree fg_init(_Tree rect_tree, _Tree circle_tree, float point[2], float r, FILE *txtFile, FILE *svgFile, _List to_move, _List to_remove, _List carlos){
	return fg(rect_tree, circle_tree, point, r, txtFile, svgFile, to_move, to_remove, carlos);
}
