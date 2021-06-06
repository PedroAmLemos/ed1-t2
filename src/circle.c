#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "circle.h"
typedef struct circle{
	char id[40], bc[40], pc[40];
	float point[2], r;
}structCircle;

_Circle create_circle(char id[40], char bc[40], char pc[40], float x, float y, float r){
	structCircle *new_circle = malloc(sizeof(structCircle));
	strcpy(new_circle->id, id);
	strcpy(new_circle->bc, bc);
	strcpy(new_circle->pc, pc);
	new_circle->point[0] = x;
	new_circle->point[1] = y;
	new_circle->r = r;
	return new_circle;
}
