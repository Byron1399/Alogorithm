#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
int main()
{
    printf("完美");
   int *arr=NULL;
   int size=0;
   int capacity=5;
   int num;

   arr=malloc(capacity * sizeof(int));
   if(arr==NULL){
    printf("数组初始化失败");
    return 0;
   }

   while(scanf("%d",&num)==1){
    if(size>=capacity){
        capacity=capacity*2;
        arr=realloc(arr,capacity * sizeof(int));
        if(arr==NULL){
            printf("数组扩展失败");
            return 0;
        }
    }
    arr[size]=num;
    size++;
    if(getchar() == '\n'){
        break;
    }
   }

    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
        if(i==size-1){
            printf("\n");
        }
    }
//以上读取类似 1 2 3 4 5 的数组

// 数组生成链表
    // typedef struct list{
    //     int data;
    //     struct list * next;
    // }list;
    // list **n;
    // n=malloc(sizeof(list *));
    // list *head;
    // head=malloc(sizeof(list));
    // (*n)=head;
    // for(int i=0;i<size;i++){
    //     (*n)->data=arr[i];
    //     if(i!=size-1){
    //         list *x;
    //         x=malloc(sizeof(list));
    //         (*n)->next=x;
    //         (*n)=x;
    //     }
    //     else{
    //         (*n)->next=NULL;
    //     }
    //  }
    // list * p=head;
    // printf("输出:\n");
    // while(p!=NULL){
    //     printf("%d ",p->data);
    //     p=p->next;
    // }
    // list * temp;
    // while(head!=NULL){
    //     temp=head;
    //     head=head->next;
    //     free(temp);
    // }
    // free(temp);
    tree * root;
    tree * head;

    root=malloc(sizeof(tree));
    head=buildtree(root,0,size-1,arr);
    printf("二叉树完成\n");

    void printftree(tree * p){
        if(p==NULL)
        {
            printf("空树\n");
            return;
        }
        if(p->left==NULL&&p->right==NULL)
        {
            printf("%d ",p->data);
        }
        else
        {
            if(p->left!=NULL){
                printftree(p->left);
            }
            printf("%d ",p->data);
            if(p->right!=NULL)
            {
                printftree(p->right);
            }
        }
    }
    
    printftree(head);

    // void insert(tree ** l,int x,tree * parent)
    // {
    //     if(*l==NULL)
    //     {
    //         tree * p;
    //         p=malloc(sizeof(tree));
    //         p->data=x;
    //         p->left=NULL;
    //         p->right=NULL;
    //         p->father=parent;


    //         *l=p;
    //         return;
    //     }
    //     else{
    //         if((*l)->data > x)
    //         {
    //             insert(&(*l)->left,x,*l);
    //             return;
    //         }
    //         if((*l)->data==x)
    //         {
    //             printf("已经存在");
    //             return;
    //         }
    //         if((*l)->data < x)
    //         {
    //             insert(&(*l)->right,x,*l);
    //             return;
    //         }
    //     }
    // }
    // printf("\n插入数字\n");
    // int y;
    // scanf("%d",&y);
    // insert(&head,y,NULL);

    // printf("更新后的二叉树:\n");
    // printftree(head);

    tree * find(tree * p,int x){
        if(p==NULL)
        {
            printf("没找到");
            return NULL;
        }
        else
        {
            if(p->data > x)
            {
               return find(p->left,x);
            }
            if(p->data < x)
            {
                return find(p->right,x);
            }
            if(p->data ==x )
            {
                return p;
            }
        }
    }

    tree * min(tree * p)
    {
        if(p==NULL)
        {
            printf("空，无法寻找最小值");
            return NULL;
        }
        if(p->left!=NULL)
        {
            return min(p->left);
        }
        if (p->left==NULL)
        {
            return p;
        }
        
    }
    // printf("找数字：");
    // int findnum;
    // scanf("%d",&findnum);
    // tree * findout=find(head,findnum);
    // if (findout==NULL)
    // {
    //     printf("没找到\n");
    // }
    // else{
    //     printf("找到了");
    // }

    void delete(tree * p,int x)
    {
        tree * l=find(p,x);
        if(l==NULL)
        {
            printf("不存在，无法删除\n");
            return ;
        }
        if(l->right==NULL&&l->left==NULL)
        {
            if(l->data < l->father->data){
                l->father->left==NULL;
            }
           if(l->data > l->father->data){
                l->father->right==NULL;
               
            }
             free(l);
        }
        if(l->right==NULL&&l->left!=NULL)
        {
            l->left->father=l->father;
            free(l);
        }
        if(l->right!=NULL&&l->left==NULL)
        {
            l->right->father=l->father;
            free(l);
        }
        if(l->right!=NULL&&l->left!=NULL)
        {
            tree * minnum=min(l->left);
            l->data=minnum->data;
            minnum->father->left=NULL;
            free(minnum);
        }
    }
    printf("删除数字k：");
    int k;
    scanf("%d",&k);
    delete(head,k);
    printftree(head);
 }