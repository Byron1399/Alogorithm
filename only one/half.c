#include<stdio.h>
#include<stdlib.h>
#include <string.h>


// #define MAX 100  // 定义队列的最大长度

// typedef struct {
//     int data[MAX];  // 用于存储队列元素的数组
//     int front;      // 队列的队首
//     int rear;       // 队列的队尾
// } Queue;

// // 初始化队列
// void initQueue(Queue *q) {
//     q->front = 0;
//     q->rear = 0;
// }

// // 判断队列是否为空
// int isEmpty(Queue *q) {
//     return q->front == q->rear;
// }

// // 判断队列是否已满
// int isFull(Queue *q) {
//     return (q->rear + 1) % MAX == q->front;
// }

// // 入队操作
// void enqueue(Queue *q, int value) {
//     if (isFull(q)) {
//         printf("Queue is full!\n");
//         return;
//     }
//     q->data[q->rear] = value;
//     q->rear = (q->rear + 1) % MAX;
// }

// // 出队操作
// int dequeue(Queue *q) {
//     if (isEmpty(q)) {
//         printf("Queue is empty!\n");
//         return -1;  // 返回 -1 表示队列为空
//     }
//     int value = q->data[q->front];
//     q->front = (q->front + 1) % MAX;
//     return value;
// }

// // 打印队列内容
// void printQueue(Queue *q) {
//     if (isEmpty(q)) {
//         printf("Queue is empty!\n");
//         return;
//     }
//     int i = q->front;
//     while (i != q->rear) {
//         printf("%d ", q->data[i]);
//         i = (i + 1) % MAX;
//     }
//     printf("\n");
// }

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
            printf("输入排序格式\n");
            break;
        }
        size++;

    }
    int paixu;
    scanf("%d",&paixu);
    int  sort(int *s,int paixu,int start,int end)
    {
        int p=end;
        int num=start;
        int temp;
        for(int i=start;i<end;i++)
        {
            if(s[i]<s[p]&&paixu==1)
            {
                temp=s[i];
                s[i]=s[num];
                s[num]=temp;
                num++;
            }
            if(s[i]>s[p]&&paixu==-1)
            {
                temp=s[i];
                s[i]=s[num];
                s[num]=temp;
                num++;
            }
        }
        temp=s[p];
        s[p]=s[num];
        s[num]=temp;
        return num;
    }
    void mergesort(int * s,int paixu,int start,int end)
    {   
        int p;
        if(end-start>0)
        {   
            p=sort(s,paixu,start,end);
            mergesort(s,paixu,start,p-1);
            mergesort(s,paixu,p,end);
        }
    }
    mergesort(s,paixu,0,size-1);
    for(int i=0;i<size;i++)
    {
        printf("%d ",s[i]);
    }
    // int * merge(int *s1,int*s2,int paixu,int start,int p,int end)
    // {   int * s;
    //     int size=0;
    //     s=malloc((end-start+1) * sizeof(int));
    //     Queue *q1,*q2;
    //     initQueue(q1);
    //     initQueue(q2);
    //     for(int i=start;i++;i<p)
    //     {
    //         enqueue(q1,s1[i]);
    //     }
    //     for(int i=p;i++;i<=end)
    //     {
    //         enqueue(q2,s2[i]);
    //     }
    //     while(isEmpty(q1))
    //     {
    //         s[size]=dequeue(q1);
    //         size++;
    //     }
    // }
}