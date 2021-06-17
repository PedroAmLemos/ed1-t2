#include <stdio.h>
#include "void_pointers.h"
#ifndef __CIRCLE__
#define __CIRCLE__ 

// Função recebe os aspectos do círculo, e retorna um círculo criado
_Circle create_circle(char id[40], char bc[40], char pc[40], float x, float y, float r);

// Função que recebe um círculo e retorna o id
char *get_circle_id(_Circle circle);

// Função que recebe um círculo e retorna o x
float get_circle_x(_Circle circle);

// Função que recebe um círculo e retorna o y
float get_circle_y(_Circle circle);

// Função que recebe um círculo e retorna o r
float get_circle_r(_Circle circle);

// Função que recebe um círculo e retorna o ponto
float *get_circle_point(_Circle circle);

// Função que recebe um círculo e retorna a radiação
int get_radiation(_Circle circle);

// Função que recebe um círculo e retorna o bc
char *get_circle_bc(_Circle circle);

// Função que recebe um círculo e retorna o pc
char *get_circle_pc(_Circle circle);

// Função que recebe um círculo e retorna o estado do círculo, sendo 0 = estático, 1 = movido, 2 = morto
int get_circle_state(_Circle circle);

// Função que recebe um círculo e  muda a sua origem
void change_circle_origin(_Circle circle, float *new_origin);

// Função que recebe um círculo e altera seu x
void change_circle_x(_Circle circle, float new_x);

// Função que recebe um círculo e altera seu bc
void change_circle_bc(_Circle circle, char *new_bc);

// Função que recebe um círculo e altera seu pc
void change_circle_pc(_Circle circle, char *new_pc);

// Função que recebe um círculo e altera seu y
void change_circle_y(_Circle circle, float new_y);

// Função que recebe um círculo e altera seu ponto
void change_circle_point(_Circle circle, float new_x, float new_y);

// Função que recebe um círculo e altera seu estado
void change_circle_state(_Circle circle, int new_state);

// Função que recebe dois círculos, e os troca de lugar
void swap_two_circle(_Circle circle1, _Circle circle2);

// Função que recebe um círculo e o arquivo svg, e printa o circulo no svg
void print_circle(FILE *svgFile, _Circle circle);

// Função que recebe um círculo e o arquivo svg, e printa o circulo animado no svg usando o ponto de origem e o ponto atual
void print_circle_animated(FILE *svgFile, _Circle circle);

#endif /* ifndef __CIRCLE__ */
