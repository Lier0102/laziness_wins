#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node a = {1, NULL, NULL};
Node b = {4, &a, NULL};
Node c = {16, NULL, NULL};
Node d = {25, NULL, NULL};
Node e = {20, &c, &d};
Node f = {15, &b, &e};
Node *root = &f;

Node *inOrder(Node *root) {
    if (root) {
        inOrder(root->left);
        printf("%d - ", root->data);
        inOrder(root->right);
    }
}

Node *preOrder(Node *root) {
    if (root) {
        printf("%d - ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

Node *postOrder(Node *root) {
    if (root) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d - ", root->data);
    }
}

int main() {
    preOrder(root);

    /*
                10
              /    \ 
            20      30
    
    */

    return 0;
}