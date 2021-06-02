#ifndef __KDTREE__
#define __KDTREE__ 
#endif /* ifndef __KDTREE__ */
typedef void* Tree;
typedef void* Info;

Tree create_kdnode(float point[2], Info info);
Tree insert_kd(Tree tree, float point[2], Info info, int depth);
Tree insert_kd_init(Tree tree, float point[2], Info info);
Tree search_key(Tree tree, float point[2], int depth);
Info get_info(Tree tree);
void* get_point(Tree tree);
void print_info(Tree tree);
Tree get_right(Tree tree);
Tree get_left(Tree tree);
//Tree delete_node(Tree tree, float point[2], int depth);
