#include <stdio.h>
#include "void_pointers.h"
#ifndef __RECT__
#define __RECT__ 

// Função recebe os aspectos do retangulo, e retorna um retangulo criado
_Rect create_rect(char id[40], char cc[40], char cp[40], float x, float y, float w, float h);

// Função que recebe um retangulo e retorna o id
char *get_rect_id(_Rect rect);

// Função que recebe um retangulo e retorna o w
float get_rect_w(_Rect rectangle);

// Função que recebe um retangulo e retorna o h
float get_rect_h(_Rect rectangle);

// Função que recebe um retangulo e retorna o x
float get_rect_x(_Rect rectangle);

// Função que recebe um retangulo e retorna o y
float get_rect_y(_Rect rectangle);

// Função que recebe um retangulo e retorna o ponto
float *get_rect_point(_Rect rectangle);

// Função que recebe um retangulo e adiciona um no numero de abrigados
void add_n(_Rect rectangle);

// Função que recebe um retangulo e muda seu x
void change_rect_x(_Rect rectangle, float new_x);

// Função que recebe um retangulo e muda seu y
void change_rect_y(_Rect rectangle, float new_y);

// Função que recebe um retangulo e muda seu ponto
void change_rect_point(_Rect rectangle, float new_x, float new_y);

// Função que recebe dois retangulos e os inverte
void swap_two_rect(_Rect rectangle1, _Rect rectangle2);

// Função que printa um retangulo em um svg
void print_rect(FILE *svgFile, _Rect rectangle);

// Função que recebe um retangulo e retorna seu cc
char *get_rect_cc(_Rect rectangle);

#endif /* ifndef __RECT__ */
