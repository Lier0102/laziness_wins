#include <stdio.h>
#include <stdlib.h>

typedef struct __tree_node {
    int data;
    struct __tree_node *left, *right;
} Node;

Node *a = {1, NULL, NULL};
Node *b = {4, &a, NULL};
Node *c = {16, NULL, NULL};
Node *d = {25, NULL, NULL};
Node *e = {20, &c, &d};
Node *f = {15, &b, &e};

int main() {

    /*
                10
              /    \ 
            20      30
    
    */

    return 0;
}