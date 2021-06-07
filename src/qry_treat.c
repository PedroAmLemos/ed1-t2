#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "qry_treat.h"
#include "kdtree.h"
#include "rect.h"
#include "void_pointers.h"
#include "svg.h"

bool point_is_inside(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2) {
  return x1 >= x2 && y1 >= y2 && x1 + w1 <= x2 + w2 && y1 + h1 <= y2 + h2;
}

_Tree dpi(_Tree rect_tree, float x, float y, FILE *txtFile){
	if(is_null(rect_tree)){
		return NULL;
	}
	dpi(get_kd_right(rect_tree), x, y, txtFile);
	dpi(get_kd_left(rect_tree), x, y, txtFile);
	_Rect rectangle = get_info(rect_tree);
	float rectW, rectH;
	float *point = get_point(rect_tree);
	rectW = get_rect_w(rectangle);
	rectH = get_rect_h(rectangle);
	if (point_is_inside(x, y, 0, 0, point[0], point[1], rectW, rectH)) {
	  fprintf(txtFile, "%s", get_rect_id(rectangle));
	  return delete_node_init(rect_tree, point);
	}
	return rect_tree;
}

_Tree main_qry(_Tree rect_tree, _Tree circle_tree, FILE *qryFile, FILE *txtFile, FILE *svgFile){
	float x=0, y=0, w, h;
	int k;
	char id[40], aux[40];
	fprintf(txtFile, "Pedro Antonio Messias Lemos\n");
	while(fscanf(qryFile, "%s", aux)!=EOF){
		if((strcmp(aux, "dpi"))==0){
			fprintf(txtFile, "dpi\n");
			fscanf(qryFile, "%f %f", &x, &y);
			rect_tree = dpi(rect_tree, x, y, txtFile);
		}
	}
	fill_svg(rect_tree, circle_tree, svgFile);
	return rect_tree;
}
