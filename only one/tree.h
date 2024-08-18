#ifndef tree_h
#define tree_h

typedef struct tree{
    int data;
    struct tree * father;
    struct tree * left;
    struct tree * right;
}tree;

tree * buildtree (tree *p,int start,int end,int arr[]);

#endif
