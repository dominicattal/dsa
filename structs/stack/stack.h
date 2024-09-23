#ifndef STACK_H
#define STACK_H

typedef struct SNode SNode;

typedef struct SNode {
    int val;
    SNode* next;
} SNode;

typedef struct Stack {
    SNode* head;
    SNode* tail;
} Stack;

#endif