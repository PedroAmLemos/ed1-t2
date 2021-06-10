#include <stdio.h>
#include "void_pointers.h"
#ifndef __RECT__
#define __RECT__ 

_Rect create_rect(char id[40], char cc[40], char cp[40], float x, float y, float w, float h);

char *get_rect_id(_Rect rect);

float get_rect_w(_Rect rectangle);

float get_rect_h(_Rect rectangle);

float get_rect_x(_Rect rectangle);

float get_rect_y(_Rect rectangle);

float *get_rect_point(_Rect rectangle);

void add_n(_Rect rectangle);

void change_rect_x(_Rect rectangle, float new_x);

void change_rect_y(_Rect rectangle, float new_y);

void change_rect_point(_Rect rectangle, float new_x, float new_y);

void swap_two_rect(_Rect rectangle1, _Rect rectangle2);

void print_rect(FILE *svgFile, _Rect rectangle);

char *get_rect_cc(_Rect rectangle);

#endif /* ifndef __RECT__ */
