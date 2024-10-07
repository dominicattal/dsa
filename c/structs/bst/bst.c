#include "bst.h"
#include <stdlib.h>
#include <stdio.h>

BNode* bnode_create(int key) {
    BNode* node = malloc(sizeof(BNode));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

void bnode_destroy(BNode* node) {
    free(node);
}

BST* bst_create(void) {
    BST* tree = malloc(sizeof(BST));
    tree->root = NULL;
    tree->size = 0;
    return tree;
}

BNode* bst_insert_helper(BNode* node, int key) {
    if (node == NULL)    return bnode_create(key);
    if (node->key < key) node->right = bst_insert_helper(node->right, key);
    if (node->key > key) node->left  = bst_insert_helper(node->left, key);
    return node;
}

void bst_insert(BST* tree, int key) {
    tree->root = bst_insert_helper(tree->root, key);
}

BNode* bst_remove_helper(BNode* node, int key) {
    if (node == NULL) return NULL;
    if (node->key < key) node->right = bst_remove_helper(node->right, key);
    if (node->key > key) node->left  = bst_remove_helper(node->left, key);
    if (node->key == key) {
        if (node->left == NULL) {
            BNode* tmp = node->right;
            free(node);
            return tmp;
        }
        else if (node->right == NULL) {
            BNode* tmp = node->left;
            free(node);
            return tmp;
        }
        BNode* succ = node->right;
        while (succ != NULL && succ->left != NULL)
            succ = succ->left;
        node->key = succ->key;
        node->right = bst_remove_helper(node->right, succ->key);
    }
    return node;
}

void bst_remove(BST* tree, int key) {
    tree->root = bst_remove_helper(tree->root, key);
}

int bst_find_helper(BNode* node, int key) {
    if (node == NULL)     return 0;
    if (node->key == key) return 1;
    return bst_find_helper(node->left, key) || bst_find_helper(node->right, key);
}

int bst_find(BST* tree, int key) {
    return bst_find_helper(tree->root, key);
}

void bst_destroy_helper(BNode* node) {
    if (node == NULL) return;
    bst_destroy_helper(node->left);
    bst_destroy_helper(node->right);
    free(node);
}

void bst_destroy(BST* tree) {
    bst_destroy_helper(tree->root);
}

void bst_print_inorder_helper(BNode* node) {
    if (node == NULL) return;
    bst_print_inorder_helper(node->left);
    printf("%d ", node->key);
    bst_print_inorder_helper(node->right);
}

void bst_print_inorder(BST* tree) {
    bst_print_inorder_helper(tree->root);
    puts("");
}

void bst_print_preorder_helper(BNode* node) {
    if (node == NULL) return;
    printf("%d ", node->key);
    bst_print_preorder_helper(node->left);
    bst_print_preorder_helper(node->right);
}

void bst_print_preorder(BST* tree) {
    bst_print_preorder_helper(tree->root);
    puts("");
}

void bst_print_postorder_helper(BNode* node) {
    if (node == NULL) return;
    bst_print_postorder_helper(node->left);
    bst_print_postorder_helper(node->right);
    printf("%d ", node->key);
}

void bst_print_postorder(BST* tree) {
    bst_print_postorder_helper(tree->root);
    puts("");
}

void bst_inorder_helper(BNode* node, int* arr, int* acc) {
    if (node == NULL) return;
    bst_inorder_helper(node->left, arr, acc);
    arr[(*acc)++] = node->key;
    bst_inorder_helper(node->right, arr, acc);
}

int* bst_inorder(BST* tree, int* count) {
    int* arr = malloc(bst_count(tree) * sizeof(int));
    int acc = 0;
    bst_inorder_helper(tree->root, arr, &acc);
    *count = acc;
    return arr;
}

BNode* bst_balance_helper(int* arr, int l, int r) {
    if (l > r) return NULL;
    int mid = l + (r - l) / 2;
    BNode* root = bnode_create(arr[mid]);
    root->left  = bst_balance_helper(arr, l, mid - 1);
    root->right = bst_balance_helper(arr, mid + 1, r);
    return root;
}

void bst_balance(BST* tree) {
    int count;
    int* arr = bst_inorder(tree, &count);
    bst_destroy(tree);
    tree->root = bst_balance_helper(arr, 0, count - 1);
    for (int i = 0; i < count; i++)
        printf("%d ", arr[i]);
    puts("");
    free(arr);
}

void bst_count_helper(BNode* node, int* count) {
    if (node == NULL) return;
    (*count)++;
    bst_count_helper(node->left, count);
    bst_count_helper(node->right, count);
}

int bst_count(BST* tree) {
    int count = 0;
    bst_count_helper(tree->root, &count);
    return count;
}