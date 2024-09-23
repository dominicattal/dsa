#include <stdio.h>
#include <bst/bst.h>

int main(int argc, char **argv) {
    BST* tree = bst_create();
    for (int i = 0; i < 20; i++)
        bst_insert(tree, i);
    bst_preorder(tree);
    bst_balance(tree);
    bst_preorder(tree);
    return 0;
}