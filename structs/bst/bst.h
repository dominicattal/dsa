#ifndef BST_H
#define BST_H

typedef struct BNode BNode;

typedef struct BNode {
    int key;
    BNode* left;
    BNode* right;
} BNode;

typedef struct {
    BNode* root;
    int size;
} BST;

BST* bst_create(void);
void bst_insert(BST* tree, int key);
void bst_remove(BST* tree, int key);
int  bst_find(BST* tree, int key);
void bst_destroy(BST* tree);

void bst_inorder(BST* tree);
void bst_preorder(BST* tree);
void bst_postorder(BST* tree);

#endif