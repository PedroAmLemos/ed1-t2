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
#include "circle.h"
#include "qry_treat_utility.h"

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
	if(rect_is_inside(x, y, 0, 0, point[0], point[1], rectW, rectH) == 1) {
		fprintf(txtFile, "%s\n", get_rect_id(rectangle));
		float *point_remove = malloc(sizeof(float)*2);
		point_remove[0] = point[0];
		point_remove[1] = point[1];
		insert_list(point_remove, dpi_remove);
	}
	return rect_tree;
}

_Tree dr_wrapper(_Tree rect_tree, char *id_to_search, FILE *txt_file){
	_List to_remove = create_list();
	float resultPointWH[4] = {0, 0, 0, 0};
	_Tree copy_root = rect_tree;
	find_point_search_key(copy_root, id_to_search, resultPointWH);
	rect_tree = dr_init(rect_tree, resultPointWH, to_remove, txt_file);
	rect_tree = remove_points_list(to_remove, rect_tree, swap_two_rect);
	delete_list(to_remove, 1);
	return rect_tree;
}

_Tree fg_wrapper(_Tree rect_tree, _Tree circle_tree, _List to_move, float x, float y, float r, FILE *txtFile, FILE *svgFile){
	_List to_remove = create_list(), carlos = create_list();
	float point[2] = {x, y};
	circle_tree    = fg_init(rect_tree, circle_tree, point, r, txtFile, svgFile, to_move, to_remove, carlos);
	for(_Node node = get_first(carlos); node != NULL; node = get_next(node)){
		for(_Node nodeNode = get_first(get_list_info(node)); nodeNode != NULL; nodeNode = get_next(nodeNode)){
			fprintf(txtFile, "%s\n", (char *)get_list_info(nodeNode));
		}
	}
	for(_Node node = get_first(carlos); node != NULL; node = get_next(node)){
		delete_list(get_list_info(node), 0);
	}
	circle_tree    = remove_points_list(to_remove, circle_tree, swap_two_circle);
	delete_list(to_remove, 0);
	delete_list(carlos, 0);	
	return circle_tree;
}

void main_qry(_Tree rect_tree, _Tree circle_tree, FILE *qryFile, FILE *txtFile, FILE *svgFile){
	open_SVG(svgFile);
	float x=0, y=0, r=0;
	char id[40], aux[40];
	_List dpi_remove_points = create_list(), to_move = create_list();
	fprintf(txtFile, "Pedro Antonio Messias Lemos\n");
	while(fscanf(qryFile, "%s", aux)!=EOF){
		if((strcmp(aux, "dpi"))==0){
			fprintf(txtFile, "dpi\n");
			fscanf(qryFile, "%f %f", &x, &y);
			rect_tree = dpi(rect_tree, x, y, txtFile, dpi_remove_points);
			rect_tree = remove_points_list(dpi_remove_points, rect_tree, swap_two_rect);
		}
		else if((strcmp(aux, "dr"))==0){
			fprintf(txtFile, "dr\n");
			fscanf(qryFile, "%s", id);
			rect_tree = dr_wrapper(rect_tree, id, txtFile);
		}
		else if((strcmp(aux, "fg"))==0){
			fprintf(txtFile, "fg\n");
			fscanf(qryFile, "%f %f %f", &x, &y, &r);
			circle_tree = fg_wrapper(rect_tree, circle_tree, to_move, x, y, r, txtFile, svgFile);
		}
	}
	circle_tree = insert_points_list(to_move, circle_tree);
	fill_svg(rect_tree, circle_tree, svgFile);
	delete_list(to_move, 0);
	delete_list(dpi_remove_points, 1);
	delete_tree(rect_tree);
	delete_tree(circle_tree);
}
