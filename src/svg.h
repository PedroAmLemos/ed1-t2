#include <stdio.h>
#include "kdtree.h"
#ifndef __SVG__
#define __SVG__ 

void open_SVG(FILE *svgFile);

void print_circle_to_svg(FILE *svgFile, _Tree tree);

void close_SVG(FILE *svgFile);

#endif /* ifndef __SVG__ */
