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

void bst_inorder_helper(BNode* node) {
    if (node == NULL) return;
    bst_inorder_helper(node->left);
    printf("%d ", node->key);
    bst_inorder_helper(node->right);
}

void bst_inorder(BST* tree) {
    bst_inorder_helper(tree->root);
    puts("");
}

void bst_preorder_helper(BNode* node) {
    if (node == NULL) return;
    printf("%d ", node->key);
    bst_preorder_helper(node->left);
    bst_preorder_helper(node->right);
}

void bst_preorder(BST* tree) {
    bst_preorder_helper(tree->root);
    puts("");
}

void bst_postorder_helper(BNode* node) {
    if (node == NULL) return;
    bst_postorder_helper(node->left);
    bst_postorder_helper(node->right);
    printf("%d ", node->key);
}

void bst_postorder(BST* tree) {
    bst_postorder_helper(tree->root);
    puts("");
}

void bst_balance(BST* tree) {
    
}