// main.c
#include "queue.h"
#include <stdio.h>

int main() {
    Queue q;
    initQueue(&q, 10);

    enqueue(&q, 5);
    enqueue(&q, 10);

    printf("Dequeue: %d\n", dequeue(&q));
    printf("Dequeue: %d\n", dequeue(&q));

    freeQueue(&q);
    return 0;
}
