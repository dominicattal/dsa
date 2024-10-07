#include <stdio.h>
#include <stack/stack.h>

int main(int argc, char **argv) {
    Stack* stack = stack_create();
    for (int i = 0; i < 10; i++) {
        stack_push(stack, i);
    }
    for (int i = 0; i < 5; i++) {
        printf("%d ", stack_pop(stack));
    }
    stack_destroy(stack);
    return 0;
}