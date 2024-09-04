#include<stdio.h>
#include "queue.h"
#include<stdlib.h>
#include<stdbool.h>
#define MAX 100
typedef struct{
    int y;
    int weight;
    struct point *next;
}point;
typedef struct{
    point *edgepoint[MAX-1];
    int  *degree[MAX-1];
    int directed;
    int pnum;
    int dege;
}graph;
void init_graph(graph *g,int pnum,int directed)
{
    int i;
    for(i=0;i<MAX;i++)
    {
        g->edgepoint[i]=NULL;
        g->degree[i]=0;
    }
    g->pnum=pnum;
    g->dege=0;
    g->directed=directed;
}
void insert(graph *g,int directed,int x,int y)
{
    point * p;
    p=malloc(sizeof(point));
    p->y=y;
    p->weight=0;
    p->next=g->edgepoint[x];
    g->edgepoint[x]=p;
    g->degree[x]++;
    if(directed==0)
    {
        insert(g,1,y,x);
    }
    else
    {
        g->dege++;
    }
}
void read_graph(graph * g,int m)
{
    int x,y;
    for(int i=0;i<m;i++)
    {
        scanf("%d %d",&x,&y);
        insert(g,g->directed,x,y);
    }
}
void print_graph(graph * g)
{       point * p;
    for(int i=0;i<MAX;i++)
    {   p=g->edgepoint[i];
        if(p!=NULL)
        {
            printf("point %d:",i);
            printf(" %d",p->y);
            while(p->next)
            {
               p=p->next;
               printf(" %d",p->y);
            }
             printf("\n");
        }
    }
}
// void path_point(graph * g,int start,int end)
// {
//     int s[MAX-1];
//     for(int i=0;i<MAX;i++)
//     {
//         s[i]=0;
//     }
//     int f(graph * g,int start,int end)
//     {   
//         point * p;
//         p=g->edgepoint[start];


//         if(p==NULL){
//             return answer;
//         }
//         while(p!=NULL)
//         {
//             int answer=-1;
//             if(s[p->y]==1)
//             {
//                 p=p->next;
//             }
//             else
//             {
//                 if(p->y==end)
//                 {
//                     answer=end;
//                 }
//                 else
//                 {
//                     s[p->y]=1;
//                     answer=f(g,p->y,end);
//                 }
//             }
//             if(answer!=-1)
//             {
//                 printf(" %d ",p->y);
//             }
//             p=p->next;
//         }
//         return answer;  
//     }

//     int a=f(g,start,end);
// }

void init_serach(graph * g,bool * process,bool * discover,int * parent)
{
    for(int i=0;i<MAX;i++)
    {
        if(g->edgepoint[i]!=NULL)
        {
            process[i]=discover[i]=false;
            parent[i]=-1;
        }
        else
        {
            parent[i]=-2;
        }
    }
}

void p_point(graph * g,int point)
{
    printf("point %d:\n",point);
}
void p_edge(graph * g,int u,int y)
{
    printf("edge (%d,%d)\n",u,y);
}

void bfs(graph *g,int start,bool * process,bool * discover,int * parent)
{   int u,v;
    Queue* q=malloc(sizeof(Queue));
    initQueue(q,MAX);
    discover[start]=true;
    enqueue(q,start);
    while(!isQueueEmpty(q))
    {
        u=dequeue(q);
        p_point(g,u);
        process[u]=true;
        point * p;
        p=g->edgepoint[u];
        while(p!=NULL)
        {   if(discover[p->y]==false)
            {
                enqueue(q,p->y);
                discover[p->y]=true;
                parent[p->y]=u;
                
            }
            if(process[p->y]==false||g->directed)
            {
                p_edge(g,u,p->y);
            }
            p=p->next;
        }
    }
}
void path(graph *g,int start,int end,bool * process,bool * discover,int * parent)
{
    if(start==end)
    {
        printf(" %d",start);
    }
    else
    {
        path(g,start,parent[end],process,discover,parent);
        printf(" %d",end);
    }
}
int main()
{
    graph * g;
    g=malloc(sizeof(graph));
    int pnum;
    int m;
    int directed;
    scanf("%d %d %d",&pnum,&m,&directed);
    init_graph(g,pnum,directed);
    read_graph(g,m);
    print_graph(g);

    bool process[MAX-1];
    bool discover[MAX-1];
    int parent[MAX-1];   
    init_serach(g,process,discover,parent);
    bfs(g,1,process,discover,parent);
    for(int i=0;i<MAX;i++)
    {
        if(parent[i]!=-2)
        {
            printf("%d:%d\n",i,parent[i]);
        }
    }
    path(g,1,4,process,discover,parent);
}