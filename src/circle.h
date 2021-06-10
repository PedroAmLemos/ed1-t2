#include <stdio.h>
#include "void_pointers.h"
#ifndef __CIRCLE__
#define __CIRCLE__ 

_Circle create_circle(char id[40], char bc[40], char pc[40], float x, float y, float r);

char *get_circle_id(_Circle circle);

float get_circle_x(_Circle circle);

float get_circle_y(_Circle circle);

float get_circle_r(_Circle circle);

float *get_circle_point(_Circle circle);

int get_radiation(_Circle circle);

char *get_circle_bc(_Circle circle);

char *get_circle_pc(_Circle circle);

int get_circle_state(_Circle circle);

void change_circle_origin(_Circle circle, float *new_origin);

void change_circle_x(_Circle circle, float new_x);

void change_circle_bc(_Circle circle, char *new_bc);

void change_circle_pc(_Circle circle, char *new_pc);

void change_circle_y(_Circle circle, float new_y);

void change_circle_point(_Circle circle, float new_x, float new_y);

void change_circle_state(_Circle circle, int new_state);

void swap_two_circle(_Circle circle1, _Circle circle2);

void print_circle(FILE *svgFile, _Circle circle);
void print_circle_animated(FILE *svgFile, _Circle circle);

#endif /* ifndef __CIRCLE__ */
