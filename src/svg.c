#include <stdio.h>
#include <stdlib.h>
#include "kdtree.h"
#include "circle.h"
#include "rect.h"
#include "svg.h"

void open_SVG(FILE *svgFile){
	fprintf(svgFile, "<!-- Pedro Antonio Messias Lemos -->\n");
	fprintf(svgFile, "<svg version=\"1.1\" baseProfile=\"full\" width=\"10000\" height=\"10000\" xmlns=\"http://www.w3.org/2000/svg\">\n");
}

void print_circle_to_svg(FILE *svgFile, _Tree tree){
	if(is_null(tree)){
		return;
	}
	print_circle_to_svg(svgFile, get_kd_right(tree));
	print_circle_to_svg(svgFile, get_kd_left(tree));
	_Circle circle = get_info(tree);
	int state = get_circle_state(circle);
	switch (state)
	{
	case 0:
		print_circle(svgFile, get_info(tree));
		break;
	case 1:
		print_circle_animated(svgFile, get_info(tree));
		/*print_circle(svgFile, get_info(tree));*/
		break;
	}
}

void print_rect_to_svg(FILE *svgFile, _Tree tree){
	if(is_null(tree)){
		return;
	}
	print_rect_to_svg(svgFile, get_kd_right(tree));
	print_rect_to_svg(svgFile, get_kd_left(tree));
	print_rect(svgFile, get_info(tree));
}

void close_SVG(FILE *svgFile){
	fprintf(svgFile, "</svg>");
}

void fill_svg(_Tree rect_tree, _Tree circle_tree, FILE *svgFile){
	/*open_SVG(svgFile);*/
	print_circle_to_svg(svgFile, circle_tree);
	print_rect_to_svg(svgFile, rect_tree);
	close_SVG(svgFile);
}

