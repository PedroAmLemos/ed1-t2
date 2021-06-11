#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "circle.h"
#include "rect.h"
#include "kdtree.h"
typedef struct circle{
	char id[40], bc[40], pc[40];
	float point[2], r, origin[2];
	int radiation, state;
}structCircle;

_Circle create_circle(char id[40], char bc[40], char pc[40], float x, float y, float r){
	structCircle *new_circle = malloc(sizeof(structCircle));
	strcpy(new_circle->id, id);
	strcpy(new_circle->bc, bc);
	strcpy(new_circle->pc, pc);
	new_circle->state = 0;
	new_circle->radiation = 0;
	new_circle->point[0] = x;
	new_circle->point[1] = y;
	new_circle->origin[0] = x;
	new_circle->origin[1] = y;
	new_circle->r = r;
	return new_circle;
}

char *get_circle_id(_Circle circle){
	structCircle *circ = circle;
	return circ->id;
}

float *get_circle_origin(_Circle circle){
	structCircle *circ = circle;
	return circ->origin;

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

char *get_circle_bc(_Circle circle){
	structCircle *circ = circle;
	return circ->bc;
}

char *get_circle_pc(_Circle circle){
	structCircle *circ = circle;
	return circ->pc;
}

int get_radiation(_Circle circle){
	structCircle *circ = circle;
	return circ->radiation;

}

int get_circle_state(_Circle circle){
	structCircle *circ = circle;
	return circ->state;
}
void change_circle_bc(_Circle circle, char *new_bc){
	structCircle *circ = circle;
	strcpy(circ->bc, new_bc);
}

void change_circle_pc(_Circle circle, char *new_pc){
	structCircle *circ = circle;
	strcpy(circ->pc, new_pc);
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

void change_circle_origin(_Circle circle, float *new_origin){
	structCircle *circ = circle;
	circ->origin[0] = new_origin[0];
	circ->origin[1] = new_origin[1];
}

void change_circle_state(_Circle circle, int new_state){
	// states ----> 0 == static normal :::::: 1 == moved :::::: 2 == eminent death :::::: 3 == dead
	structCircle *circ = circle;
	circ->state = new_state;
}

void swap_two_circle(_Circle circle1, _Circle circle2){
	structCircle *circ1 = (structCircle *)circle1;
	structCircle *circ2 = (structCircle *)circle2;
	structCircle aux = *circ1;
	*circ1 = *circ2;
	*circ2 = aux;
}


void print_circle(FILE *svgFile, _Circle circle){
	structCircle *circ = (structCircle *) circle;
	fprintf(svgFile,"\t<circle cx=\"%f\" cy=\"%f\" r=\"%f\" fill=\"%s\" opacity=\"0.7\" stroke=\"%s\" stroke-width=\"0.2\"/>\n", get_circle_x(circ), get_circle_y(circ), circ->r, circ->pc, circ->bc);
}

void print_circle_animated(FILE *svgFile, _Circle circle){
	structCircle *circ = (structCircle *) circle;
	float *circle_origin, *circle_point;
	circle_origin = get_circle_origin(circle);
	fprintf(svgFile,"\t<circle cx=\"%f\" cy=\"%f\" r=\"%f\" fill=\"lightgray\" opacity=\"0.7\" stroke=\"gray\" stroke-width=\"0.2\"/>\n", circle_origin[0], circle_origin[1], circ->r);
	circle_point = get_circle_point(circle);
	float distance = calc_distance(circle_origin[0], circle_origin[1], circle_point[0], circle_point[1]);
	fprintf(svgFile,"\t<circle cx=\"%f\" cy=\"%f\" r=\"%f\" fill=\"%s\" opacity=\"0.7\" stroke=\"%s\" stroke-width=\"0.2\">\n", (get_circle_x(circ)+0.01*distance), (get_circle_y(circ)+0.02*distance), circ->r, circ->pc, circ->bc);
	fprintf(svgFile, "\t\t<animate attributeName=\"cx\" from=\"%lf\" to=\"%lf\" dur=\"2s\" fill=\"none\" stroke=\"black\" stroke-width=\"2\"/>\n", circle_origin[0], get_circle_x(circ));
    fprintf(svgFile, "\t\t<animate attributeName=\"cy\" from=\"%lf\" to=\"%lf\" dur=\"2s\" fill=\"none\" stroke=\"black\" stroke-width=\"2\"/>\n", circle_origin[1], get_circle_y(circ));
	fprintf(svgFile, "\t</circle>\n");
	fprintf(svgFile, "\t<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" style=\"stroke:black;stroke-width:0.5;stroke-dasharray:0.5\"/>\n", get_circle_x(circle), get_circle_y(circle), circle_origin[0], circle_origin[1]);
}
