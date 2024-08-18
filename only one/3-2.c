#include <stdio.h>
#include <stdlib.h>

typedef struct list{
    int data;
    struct list *next;
}list;
 int  shuzu(int * arr,int capacity)
 {
   int size=0;
   int num;
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
   return size-1;
 }

list* fanzhuan(list *p,list * father,list * newhead)
{ 
    list * m;
    if(p->next!=NULL)
    {
        newhead=fanzhuan(p->next,p,newhead); 
    }
    else{
        newhead=p;
    }
    p->next=father;
    return newhead;
}
int main()
{   int * arr;
    int size;
    list *m;
    m=malloc(sizeof(list ));
    list *head;
    head=malloc(sizeof(list));
    m=head;
    int capacity=5;
    arr=malloc(capacity * sizeof(int));
    size=shuzu(arr,capacity);
    for(int i=0;i<=size;i++)
    {
        printf("%d ",arr[i]);
    }
    for(int i=0;i<=size;i++)
    {
       if(i!=size)
       {
        m->data=arr[i];
        list *x;
        x=malloc(sizeof(list));
        m->next=x;
        m=x;
       }
       else{
        
        m->data=arr[i];
        m->next=NULL;
       }
    }
    list * head2;
    head2=fanzhuan(head,NULL,head2);
    m=head2;
    while(m!=NULL)
    {
        printf("\n%d ",m->data);
        m=m->next;
    }
}