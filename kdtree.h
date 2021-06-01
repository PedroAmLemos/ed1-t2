#ifndef __KDTREE__
#define __KDTREE__ 
#endif /* ifndef __KDTREE__ */
typedef void* Tree;
typedef void* Info;

Tree create_kdnode(float point[2], Info info);
Tree insert_kd(Tree tree, float point[2], Info info, int depth);
Tree insert_kd_init(Tree tree, float point[2], Info info);
void print(Tree tree);
