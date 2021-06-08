#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rect.h"

typedef struct rect{
	char id[40], cc[40], cp[40];
	float point[2], w, h;
}structRect;

_Rect create_rect(char id[40], char cc[40], char cp[40], float x, float y, float w, float h){
	structRect *new_rect = malloc(sizeof(structRect));
	strcpy(new_rect->id, id);
	strcpy(new_rect->cc, cc);
	strcpy(new_rect->cp, cp);
	new_rect->point[0] = x;
	new_rect->point[1] = y;
	new_rect->w = w;
	new_rect->h = h;
	return new_rect;
}

char *get_rect_id(_Rect rectangle) {
	structRect *rect = (structRect*) rectangle;
	return rect->id;
}

float get_rect_w(_Rect rectangle){
	structRect *rect = (structRect*) rectangle;
	return rect->w;
}

float get_rect_h(_Rect rectangle){
	structRect *rect = (structRect*) rectangle;
	return rect->h;
}

float get_rect_x(_Rect rectangle){
	structRect *rect = (structRect*) rectangle;
	return rect->point[0];
}

float get_rect_y(_Rect rectangle) {
	structRect *rect = (structRect *)rectangle;
	return rect->point[1];
}

float *get_rect_point(_Rect rectangle) {
	structRect *rect = (structRect *)rectangle;
	return rect->point;
}

void change_rect_x(_Rect rectangle, float new_x) {
	structRect *rect = (structRect *)rectangle;
	rect->point[0] = new_x;
}

void change_rect_y(_Rect rectangle, float new_y) {
	structRect *rect = (structRect *)rectangle;
	rect->point[1] = new_y;
}

void change_rect_point(_Rect rectangle, float new_x, float new_y) {
	change_rect_x(rectangle, new_x);
	change_rect_y(rectangle, new_y);
}

void swap_two_rect(_Rect rectangle1, _Rect rectangle2){
	structRect *rect1 = (structRect *)rectangle1;
	structRect *rect2 = (structRect *)rectangle2;
	structRect aux = *rect1;
	*rect1 = *rect2;
	*rect2 = aux;
}

void print_rect(FILE *svgFile, _Rect rectangle){
	structRect *rect = (structRect *)rectangle;
    fprintf(svgFile,"\t<rect x=\"%f\" y=\"%f\" width=\"%f\" height=\"%f\" fill=\"%s\" opacity=\"0.5\" stroke=\"%s\"/>\n",get_rect_x(rect),get_rect_y(rect), rect->w, rect->h, rect->cc, rect->cp);
	fprintf(svgFile,"\t<text text-anchor=\"start\" x=\"%f\" y=\"%f\" font-size=\"0.05em\">%s</text>\n", get_rect_x(rect), get_rect_y(rect), get_rect_id(rect));
}
