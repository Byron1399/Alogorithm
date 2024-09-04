// queue.h
#ifndef QUEUE_H
#define QUEUE_H
#include<stdbool.h>

typedef struct {
    // 队列的成员，例如：
    int *data;
    int front;
    int rear;
    int capacity;
} Queue;

// 队列的函数声明
void initQueue(Queue *q, int capacity);
void enqueue(Queue *q, int value);
int dequeue(Queue *q);
bool isQueueEmpty(Queue *q);
void freeQueue(Queue *q);

#endif // QUEUE_H
