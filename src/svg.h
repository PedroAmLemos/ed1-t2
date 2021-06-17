#include <stdio.h>
#include "kdtree.h"
#ifndef __SVG__
#define __SVG__ 

// Funcao responsavel pro abrir o svg
void open_SVG(FILE *svgFile);

// Funcao responsavel por printar uma arvore de circulos em um svg
void print_circle_to_svg(FILE *svgFile, _Tree tree);

// Função responsavel por fechar o svg
void close_SVG(FILE *svgFile);

// Funcao responsavel por printar uma arvore de retangulos em um svg
void print_rect_to_svg(FILE *svgFile, _Tree tree);

// Funcao que preenche um svg com a arvore de circulos e retangulos
void fill_svg(_Tree rect_tree, _Tree circle_tree, FILE *svgFile);

#endif /* ifndef __SVG__ */
