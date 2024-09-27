#ifndef STACK_H
#define STACK_H

typedef struct SNode SNode;

typedef struct SNode {
    int val;
    SNode* next;
} SNode;

typedef struct Stack {
    SNode* head;
} Stack;

Stack* stack_create(void);
void stack_push(Stack* stack, int val);
int  stack_pop(Stack* stack);
int  stack_peek(Stack* stack);
int  stack_empty(Stack* stack);
void stack_destroy(Stack* stack);

#endif