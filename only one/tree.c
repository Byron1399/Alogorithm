#include <stdlib.h>
#include "tree.h"

tree * buildtree (tree *p,int start,int end,int arr[]){
   if(start>end){
      return NULL;
   }
   tree * m;
   m=malloc(sizeof(tree));
   int x=(start+end)/2;
   m->data=arr[x];
   m->father=p;
   if(start==end){
    m->left=NULL;
    m->right=NULL;
   }
   else{
    m->left=buildtree(m,start,x-1,arr);
    m->right=buildtree(m,x+1,end,arr);
   }
   return m;
}