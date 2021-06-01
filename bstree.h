#ifndef __BSTREE__
#define __BSTREE__ 
typedef void* vRoot;
typedef void* vInfo;

vRoot create_node(vInfo info, int key);
vRoot insert(vInfo info, int key, vRoot node);
vRoot search(vRoot Tree, int key);


#endif 
