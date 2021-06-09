#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "circle.h"
#include "rect.h"
typedef struct circle{
	char id[40], bc[40], pc[40], estado[40];
	float point[2], r;
	int radiation;
}structCircle;

_Circle create_circle(char id[40], char bc[40], char pc[40], float x, float y, float r){
	structCircle *new_circle = malloc(sizeof(structCircle));
	char estado[] = {"viva"};
	strcpy(new_circle->id, id);
	strcpy(new_circle->bc, bc);
	strcpy(new_circle->pc, pc);
	strcpy(new_circle->estado, estado);
	new_circle->point[0] = x;
	new_circle->point[1] = y;
	new_circle->r = r;
	new_circle->radiation = 0;
	return new_circle;
}

char *get_circle_id(_Circle circle){
	structCircle *circ = circle;
	return circ->id;
}

float get_circle_x(_Circle circle){
	structCircle *circ = circle;
	return circ->point[0];
}

float get_circle_y(_Circle circle){
	structCircle *circ = circle;
	return circ->point[1];
}

float get_circle_r(_Circle circle){
	structCircle *circ = circle;
	return circ->r;
}

float *get_circle_point(_Circle circle){
	structCircle *circ = circle;
	return circ->point;
}

int get_radiation(_Circle circle){
	structCircle *circ = circle;
	return circ->radiation;

}

void change_radiation(_Circle circle, int new_rad){
	structCircle *circ = circle;
	circ->radiation = new_rad;
}

void add_radiation(_Circle circle, int rad){
	structCircle *circ = circle;
	circ->radiation += rad;
}

void change_circle_x(_Circle circle, float new_x){
	structCircle *circ = circle;
	circ->point[0] = new_x;
}

void change_circle_y(_Circle circle, float new_y){
	structCircle *circ = circle;
	circ->point[1] = new_y;
}

void change_circle_point(_Circle circle, float new_x, float new_y){
	change_circle_x(circle, new_x);
	change_circle_y(circle, new_y);
}

void swap_two_circle(_Circle circle1, _Circle circle2){
	structCircle *circ1 = (structCircle *)circle1;
	structCircle *circ2 = (structCircle *)circle2;
	structCircle aux = *circ1;
	*circ1 = *circ2;
	*circ2 = aux;
}

void print_circle(FILE *svgFile, _Rect circle){
	structCircle *circ = (structCircle *) circle;
	fprintf(svgFile,"\t<circle cx=\"%f\" cy=\"%f\" r=\"%f\" fill=\"%s\" stroke=\"%s\"/>\n", get_circle_x(circ), get_circle_y(circ), circ->r, circ->pc, circ->bc);
	fprintf(svgFile,"\t<text text-anchor=\"middle\" x=\"%f\" y=\"%f\" font-size=\"0.05em\">%s</text>\n", get_circle_x(circ), get_circle_y(circ), get_circle_id(circ));
}
