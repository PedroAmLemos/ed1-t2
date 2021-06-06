#ifndef __RECT__
#define __RECT__ 
typedef void* _Rect;

_Rect create_rect(char id[40], char cc[40], char cp[40], float x, float y, float w, float h);

char *get_rect_id(_Rect rect);

float get_rect_x(_Rect rectangle);

float get_rect_y(_Rect rectangle);

float *get_rect_point(_Rect rectangle);

void change_rect_x(_Rect rectangle, float new_x);

void change_rect_y(_Rect rectangle, float new_y);

void change_rect_point(_Rect rectangle, float new_x, float new_y);

#endif /* ifndef __RECT__ */