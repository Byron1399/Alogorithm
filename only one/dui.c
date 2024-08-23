#include<stdio.h>
#include<stdlib.h>
#include <string.h>
int main()
{   int * s;
    int * news;
    int n=5;
    s=malloc(5*sizeof(int));
    int size=0;
    int flag=1;
    char u;
    scanf("%d",&s[size]);
    size++;
    while(1)
    {  
        if(size>=n)
        {
            n=n*2;
            news=realloc(s,n*sizeof(int));
            if(!news)
            {
                printf("扩展内存失败\n");
            }
            s=news;
        }
        if(u=getchar()!='\n'){
            scanf("%d",&s[size]);
        }
        else{
            break;
        }
        size++;

    }
    int paixu;
    printf("排序顺序\n");
    scanf("%d",&paixu);
    typedef struct 
    {
        int p[size+1];
        int n;
    }dui;
    
    void dui_n(dui *q)
    {
        q->n=0;
    }
    int father(int x)
    {   if(x==1)
        {
            return-1;
        }
        return x/2;
    }
    int son(int x)
    {
        return 2*x;
    }
    void bull_up(dui * q,int son,int paixu)
    {
      
        if(paixu==1&&father(son)!=-1)
        {       
            if(q->p[father(son)]<q->p[son])
            {
                int temp;
                temp=q->p[father(son)];
                q->p[father(son)]=q->p[son];
                q->p[son]=temp;
                bull_up(q,father(son),paixu);
            }
            
        }
        if(paixu==-1&&father(son)!=-1)
        {  
            if(q->p[father(son)]>q->p[son])
            {
                int temp;
                temp=q->p[father(son)];
                q->p[father(son)]=q->p[son];
                q->p[son]=temp;
                bull_up(q,father(son),paixu);
            }
        }
        return;
    }
    void insert (dui * q,int x,int paixu)
    {
        if(q->n>=size)
        {
            printf("没空间\n");
            return;
        }
        q->n=q->n+1;
        q->p[q->n]=x;
        bull_up(q,q->n,paixu);
    }
    void make_dui(dui * q,int s[],int size,int paixu)
    {
        dui_n(q);
        for(int i=0;i<size;i++)
        {
            insert(q,s[i],paixu);
        }

    }
    
    void bull_down(dui * q,int father,int paixu)
    {
        if(son(father)>q->n)
        {
            return;
        }
        if(paixu==1)
        {   int pow=father;
            for(int i=0;i<2;i++)
            {   if(son(father)+i <=q->n)
                {
                        if(q->p[son(father)+i]>q->p[pow])
                    {
                        pow=son(father)+i;
                    }
                }
            
                
            }
            if(pow!=father)
           {
                int temp=q->p[pow];
                q->p[pow]=q->p[father];
                q->p[father]=temp;
                bull_down(q,pow,paixu);
           }
        }
         if(paixu==-1)
        {   int pow=father;
            for(int i=0;i<2;i++)
            {   if(son(father)+i <=q->n)
                {
                        if(q->p[son(father)+i]<q->p[pow])
                    {
                        pow=son(father)+i;
                    }
                }
            
                
            }
            if(pow!=father)
           {
                int temp=q->p[pow];
                q->p[pow]=q->p[father];
                q->p[father]=temp;
                bull_down(q,pow,paixu);
           }
        }
    }
    int e_pow(dui * q,int paixu)
    {   if(q->n<=0)
        {
            printf("空堆\n");
            return -1;
        }
        int pow=q->p[1];
        q->p[1]=q->p[q->n];
        q->n=q->n-1;
        bull_down(q,1,paixu);
        return pow;
    }
    void heapsort(int s[],int size,int paixu)
    {
        dui m;
        make_dui(&m,s,size,paixu);
        for(int i=1;i<=m.n;i++)
        {
            printf("%d ",m.p[i]);
        }
        printf("\n");
        for(int i=0;i<size;i++)
        {
            s[i]=e_pow(&m,paixu);
        }
    }
    heapsort(s,size,paixu);
    for(int i=0;i<size;i++)
    {
        printf("%d ",s[i]);
    }
}