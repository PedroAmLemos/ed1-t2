#ifndef __KDTREE__
#define __KDTREE__ 
#endif /* ifndef __KDTREE__ */
typedef void* Tree;
typedef void* Info;

Tree create_kdnode(int point[2], Info info);
Tree insert_kd(Tree tree, int point[2], Info info, int depth);
Tree insert_kd_init(Tree tree, int point[2], Info info);
void print(Tree tree);
