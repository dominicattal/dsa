#include <stdio.h>
#include <stack/stack.h>

int main(int argc, char **argv) {
    Stack* stack = stack_create();
    puts("A");
    for (int i = 0; i < 10; i++)
        stack_push(stack, i);
    puts("B");
    stack_destroy(stack);
    puts("C");
    return 0;
}