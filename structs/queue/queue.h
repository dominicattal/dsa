#ifndef QUEUE_H
#define QUEUE_H

typedef struct QNode QNode;

typedef struct QNode {
    int val;
    QNode* next;
} QNode;

typedef struct Queue {
    QNode* head;
    QNode* tail;
} Queue;

Queue* queue_create(void);
void queue_enqueue(Queue* queue, int val);
int queue_dequeue(Queue* queue);
int queue_empty(Queue* queue);
void queue_destroy(Queue* queue);

void queue_test(void);

#endif