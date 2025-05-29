#include <stdio.h>
#include <stdlib.h>

// typedef struct this_is_linked_list
// {
//     int data;
//     LI *next;
// } LI;

// int main() {
//     LI a, b, c, d;

//     a.data = 1;
//     a.next = &b;
//     b.data = 2;
//     b.next = &c;
//     c.data = 3;
//     c.next = &d;
//     d.data = 4;
//     d.next = NULL;

//     return 0;
// }

typedef struct node_ {
    int data;
    struct node_ *next;
} Node;

Node *head = NULL;
Node *tail = NULL;

int main() {
    while(1) {
        int input;

        printf("input>> ");
        scanf("%d", &input);

        if (input <= 0) break;
        
        Node *new = (Node*)malloc(sizeof(Node));
        
        new->data = input;
        new->next = NULL;

        if (head == NULL) head = new;
        else tail->next = new;

        tail = new;
    } 

    printf("current state>> ");
    
    Node *cur = head;
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    puts("");

    while (1) {
        int k;
        
        printf("data to remove>> ");
        scanf("%d", &k);

        if (k <= 0) break;

        int search = 0;
        Node *cur_prev = NULL;

        cur = head;

        while (cur != NULL) {
            if (cur->data == k) {
                search = 1;
                break;
            }
            cur_prev = cur;
            cur = cur->next;
        }
        
        if (search) {
            printf("deleted : %d\n", k);

            if (cur == head) head = cur->next;
            else cur_prev->next = cur->next;
            
            free(cur);
        } else {
            printf("cannot find : %d\n", k);
        }
    }

    printf("state after delete : ");
    cur = head;

    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    puts("");

    return 0;
}

/*

#include <unistd.h>

#define ReadInt(n) { \
    char c = *p++; \
    for (; ~c & 16; c = *p++); \
    for (; c & 16; c = *p++) n = 10 * n + (c & 15); }

#define WriteInt(n) { \
    int t = n, sz = t < 100 ? t < 10 ? 1 : 2 : t < 1000 ? 3 : 4; \
    for (int j = sz; j --> 0; t /= 10) w[i + j] = t % 10 | 48; \
    i += sz; }

short DB[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,111,123,135,147,159,210,222,234,246,258,321,333,345,357,369,420,432,444,456,468,531,543,555,567,579,630,642,654,666,678,741,753,765,777,789,840,852,864,876,888,951,963,975,987,999 };

__libc_start_main() {
    char r[2048], w[2048], *p = r; syscall(0, 0, r, 2048);
    int n = 0, cnt = 0, i = 0; ReadInt(n);
    for (int i = 0; i < sizeof DB >> 1; i++) cnt += DB[i] <= n;
    WriteInt(cnt); w[i++] = '\n';
    syscall(1, 1, w, i); _exit(0);
} main;

*/