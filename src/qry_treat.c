#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "qry_treat.h"
#include "kdtree.h"
#include "rect.h"
#include "void_pointers.h"
#include "svg.h"
#include "d_list.h"

/*		---FUNCOES AUXILIARES--		*/
int point_is_inside(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2) {
  return x1 >= x2 && y1 >= y2 && x1 + w1 <= x2 + w2 && y1 + h1 <= y2 + h2;
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

int inter(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2){
    float x,y,w,h;
    x=smaller(x1,x2);
    w=larger(x1+w1,x2+w2)-x;
    y=smaller(y1,y2);
    h=larger(y1+h1,y2+h2)-y;    
    if(w<=w1+w2&&h<=h1+h2){
        return 1;
    }else{
        return 0;
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

_Tree dpi(_Tree rect_tree, float x, float y, FILE *txtFile, _List dpi_remove){
	if(is_null(rect_tree)){
		return NULL;
	}
	dpi(get_kd_right(rect_tree), x, y, txtFile, dpi_remove);
	dpi(get_kd_left(rect_tree), x, y, txtFile, dpi_remove);
	_Rect rectangle = get_info(rect_tree);
	float rectW, rectH;
	float *point = get_point(rect_tree);
	rectW = get_rect_w(rectangle);
	rectH = get_rect_h(rectangle);
	if(point_is_inside(x, y, 0, 0, point[0], point[1], rectW, rectH) == 1) {
		fprintf(txtFile, "%s\n", get_rect_id(rectangle));
		float *point_remove = malloc(sizeof(float)*2);
		point_remove[0] = point[0];
		point_remove[1] = point[1];
		insert_list(point_remove, dpi_remove);
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
	if((inter(dr_point[0], dr_point[1], dr_point[2], dr_point[3], intRectX, intRectY, intRectW, intRectH) == 1) && same==0){
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

_Tree dr_wrapper(_Tree rect_tree, char *id_to_search, FILE *txt_file){
	_List to_remove = create_list();
	float resultPointWH[4] = {0, 0, 0, 0};
	_Tree copy_root = rect_tree;
	find_point_search_key(copy_root, id_to_search, resultPointWH);
	rect_tree = dr_init(rect_tree, resultPointWH, to_remove, txt_file);
	rect_tree = remove_points_list(to_remove, rect_tree);
	delete_list(to_remove, 1);
	return rect_tree;
}


void main_qry(_Tree rect_tree, _Tree circle_tree, FILE *qryFile, FILE *txtFile, FILE *svgFile){
	float x=0, y=0, r=0;
	char id[40], aux[40];
	_List dpi_remove_points = create_list();
	fprintf(txtFile, "Pedro Antonio Messias Lemos\n");
	while(fscanf(qryFile, "%s", aux)!=EOF){
		if((strcmp(aux, "dpi"))==0){
			fprintf(txtFile, "dpi\n");
			fscanf(qryFile, "%f %f", &x, &y);
			rect_tree = dpi(rect_tree, x, y, txtFile, dpi_remove_points);
			rect_tree = remove_points_list(dpi_remove_points, rect_tree);
		}
		else if((strcmp(aux, "dr"))==0){
			fprintf(txtFile, "dr\n");
			fscanf(qryFile, "%s", id);
			rect_tree = dr_wrapper(rect_tree, id, txtFile);
		}
		else if((strcmp(aux, "fg"))==0){
			fprintf(txtFile, "fg\n");
			fscanf(txtFile, "%f %f %f", &x, &y, &r);
		}
	}
	fill_svg(rect_tree, circle_tree, svgFile);
	delete_list(dpi_remove_points, 1);
	delete_tree(rect_tree);
	delete_tree(circle_tree);
}
