#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arq_treat.h"
#include "kdtree.h"
#include "bstree.h"
#include "qry_treat.h"
#include "svg.h"
#include "circle.h"
#include "rect.h"

void main_treatment(FILE *geoFile, FILE *qryFile, FILE *geoSVG, FILE *qrySVG, FILE *qryTXT){
	char aux[5], id[40]="default", cc[40]="blue", cp[40]="blue", bc[40]="blue", pc[40]="blue";
	float x, y, w, h, r, point[2];
	_Circle circle;
	_Rect rect;
	_Tree circle_tree = NULL;
	_Tree rect_tree = NULL;

	while (fscanf(geoFile, "%s", aux)!=EOF){
		if((strcmp(aux,"cc"))==0){
			fscanf(geoFile,"%s",cc);
		}
		if((strcmp(aux, "cp"))==0){
			fscanf(geoFile,"%s",cp);
		}
		if((strcmp(aux, "bc"))==0){
			fscanf(geoFile,"%s",bc);
		}
		if((strcmp(aux, "pc"))==0){
			fscanf(geoFile,"%s",pc);
		}
		if((strcmp(aux, "r"))==0){
			fscanf(geoFile, "%s %f %f %f %f", id, &x, &y, &w, &h);
			rect = create_rect(id, cc, cp, x, y, w, h);
			point[0] = x;
			point[1] = y;
			rect_tree = insert_kd_init(rect_tree, point, rect);
		}
		if((strcmp(aux, "c"))==0){
			fscanf(geoFile, "%s %f %f %f", id, &x, &y, &r);
			circle = create_circle(id, bc, pc, x, y, r);
			point[0] = x;
			point[1] = y;
			circle_tree = insert_kd_init(circle_tree, point, circle);
		}
	}
	/*---Making the geo svg---*/
	/*printf("ID PRIMEIRO :::::: %f %f\n", get_rect_x(get_info(rect_tree)), get_rect_y(get_info(rect_tree)));*/
	/*printf("ID DO LEFT DO ROOT ::::::: %f %f\n", get_rect_x(get_info(get_kd_left(rect_tree))), get_rect_y(get_info(get_kd_left(rect_tree))));*/
	/*printf("ID DO RIGHT DO ROOT ::::::: %f %f\n", get_rect_x(get_info(get_kd_right(rect_tree))), get_rect_y(get_info(get_kd_right(rect_tree))));*/
	fill_svg(rect_tree, circle_tree, geoSVG);
	/*float test_point[2] = {220, 28.756443};*/
	/*rect_tree = delete_node_init(rect_tree, test_point, swap_two_rect);*/

	/*printf("%s\n", get_rect_id(get_info(rect_tree)));*/

	/*------------------------*/
	/*---Making the svg and txt qry--*/
	if(qryFile)
		main_qry(rect_tree, circle_tree, qryFile, qryTXT, qrySVG);

	delete_tree(circle_tree);
	/*delete_tree(rect_tree);*/
}
