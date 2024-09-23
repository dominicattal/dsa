#include <stdio.h>
#include <bst/bst.h>

int main(int argc, char **argv) {
    BST* tree = bst_create();
    bst_insert(tree, 50);
    bst_insert(tree, 30);
    bst_insert(tree, 70);
    bst_insert(tree, 20);
    bst_insert(tree, 40);
    bst_insert(tree, 60);
    bst_insert(tree, 80);
    bst_preorder(tree);
    bst_remove(tree, 50);
    bst_preorder(tree);
    return 0;
}