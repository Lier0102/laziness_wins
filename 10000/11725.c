#include <stdio.h>
#include <stdlib.h> // malloc.h

typedef struct node {
    int v;
    struct node *next;
} Node;

int res[100001];

int Queue[100000] = { 1 };
int top = 1;

Node *arr1[100001];// = { 0, }; // 저장용
Node *arr2[100001];// = { 0, }; // 탐색용

Node v[100001];

void search(int n) {
    Node *cur;

    cur = arr2[n];

    while (cur->next != NULL) {
        cur = cur->next;
        if (res[cur->v] == 0) {
            res[cur->v] = n;
            Queue[top++] = cur->v;
        }
    }
    
    // 
    return;
}

int main() {
    int n;
    int x, y;
    Node *cur;

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) { // bss vars are 0
        arr1[i] = arr2[i] = v + i;
        arr2[i]->next = NULL;
    }

    //printf("이상없음\n");

    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d", &x, &y);
        //printf("이상없음\n");

        cur = arr1[x];
        arr1[x] = cur->next = (Node*)malloc(sizeof(Node));
        cur->next->v = y;
        cur->next->next = NULL;
        //printf("이상없음\n");

        cur = arr1[y];
        arr1[y] = cur->next = (Node*)malloc(sizeof(Node));
        cur->next->v = x;
        cur->next->next = NULL;
        //printf("이상없음\n");
    }

    for (int i = 0; i < n; i++) {
        // while cur->next is not null, update the top of queue
        search(Queue[i]);
    }

    for (int i = 2; i <= n; i++) {
        printf("%d\n", res[i]);
    }

    return 0;
}