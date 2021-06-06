#ifndef __RECT__
#define __RECT__ 
typedef void* _Rect;

_Rect create_rect(char id[40], char cc[40], char cp[40], float x, float y, float w, float h);

char *get_rect_id(_Rect rect);

float get_x(_Rect rectangle);


#endif /* ifndef __RECT__ */
