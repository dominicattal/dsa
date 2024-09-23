#include "queue.h"
#include <stdlib.h>

QNode* qnode_create(int val) {
    QNode* node = malloc(sizeof(QNode));
    node->val = val;
    node->next = NULL;
    return node;
}

void qnode_destroy(QNode* node) {
    free(node);
}

Queue* queue_create(void) {
    Queue* queue = malloc(sizeof(Queue));
    queue->head = queue->tail = NULL;
    return queue;
}

void queue_enqueue(Queue* queue, int val) {
    QNode* node = qnode_create(val);
    if (queue->head == NULL)
        queue->head = queue->tail = node;
    else
        queue->tail = queue->tail->next = node;
}

int queue_dequeue(Queue* queue) {
    if (queue->tail == NULL)
        return -1;
    int val = queue->head->val;
    if (queue->head == queue->tail)
        queue->head = queue->tail = NULL;
    else
        queue->head = queue->head->next;
    return val;
}

int queue_empty(Queue* queue) {
    return queue->head == NULL;
}

void queue_destroy(Queue* queue) {
    QNode* cur = queue->head;
    while (cur != NULL) {
        QNode* next = cur->next;
        qnode_destroy(cur);
        cur = next;
    }
}