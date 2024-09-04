// queue.c
#include "queue.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void initQueue(Queue *q, int capacity) {
    q->data = (int *)malloc(capacity * sizeof(int));
    q->front = 0;
    q->rear = -1;
    q->capacity = capacity;
}

void enqueue(Queue *q, int value) {
    if (q->rear < q->capacity - 1) {
        q->data[++q->rear] = value;
    } else {
        printf("Queue is full!\n");
    }
}

int dequeue(Queue *q) {
    if (q->front <= q->rear) {
        return q->data[q->front++];
    } else {
        printf("Queue is empty!\n");
        return -1; // 错误值
    }
}

bool isQueueEmpty(Queue *q) {
    if(q->front<=q->rear)
    {
        return false;
    }
    return true;
}

void freeQueue(Queue *q) {
    free(q->data);
}
