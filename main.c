#include <stdio.h>
#include <bst/bst.h>

int main(int argc, char **argv) {
    BST* tree = bst_create();
    for (int i = 1; i < 8; i++)
        bst_insert(tree, i);
    bst_print_preorder(tree);
    bst_balance(tree);
    bst_print_preorder(tree);
    return 0;
}