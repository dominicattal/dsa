#include "stack.h"
#include <stdlib.h>

SNode* snode_create(int val) {
    SNode* node = malloc(sizeof(SNode));
    node->val = val;
    node->next = NULL;
    return node;
}

void snode_destroy(SNode* node) {
    free(node);
}

Stack* stack_create(void) {
    Stack* stack = malloc(sizeof(Stack));
    stack->head = NULL;
    return stack;
}

void stack_push(Stack* stack, int val) {
    SNode* node = snode_create(val);
    if (stack->head == NULL)
        stack->head = node;
    else {
        node->next = stack->head;
        stack->head = node;
    }
}

int stack_pop(Stack* stack) {
    SNode* prev = stack->head;
    int val = prev->val;
    stack->head = prev->next;
    snode_destroy(prev);
    return val;
}

int stack_peek(Stack* stack) {
    return stack->head->val;
}

int stack_empty(Stack* stack) {
    return stack->head == NULL;
}

void stack_destroy(Stack* stack) {
    while (stack->head != NULL) {
        SNode* next = stack->head->next;
        free(stack->head);
        stack->head = next;
    }
    free(stack);
}