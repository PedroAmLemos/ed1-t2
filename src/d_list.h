#include "void_pointers.h"
#ifndef __LISTD__ 
#define __LISTD__

//inicia a lista -> retorna list
_List create_list();

//insere um novo node no final
void insert_list(_Info info, _List lis);

//insere um novo node depois de um parametros informado
void insert_after(_Info info, _List lis, _Node parameter);

//insere um novo node antes de um parametros informado
void insert_before(_Info info, _List lis, _Node parameter);

//remove o node informado
void remove_node(_List lis, _Node parameter);

//remove a lista, e recebe uma flag para remover a info ou nao  
int delete_list(_List lis, int flag);

//recebe a lista e retorna o tamanho
int get_size(_List lis);

//recebe a lista e retorna o primeiro no
_Node get_first(_List lis);

//recebe a lista e retorna o ultimo no
_Node get_last(_List lis);

//recebe um no e retorna o posterior
_Node get_next(_Node parameter);

//recebe um no e retorna o anterior
_Node get_prev(_Node parameter);

//recebe um no e retorna a info do no
_Info get_list_info(_Node parameter);

#endif
