#include <stdio.h>

// 1000000

typedef struct node {
    // struct node *prev;
    // struct node *next;
    int prev;
    int next;
} Node;

int main() {
    Node station[1000000] = {{0, 0}, };

    int stat;
    int oper;
    scanf("%d %d", &stat, &oper);

    int head = 0, last = 0;

    for (int i = 0; i < stat; i++) {
        int n;

        scanf("%d", &n);
        station[n].prev = last;
        station[n].next = 0;

        station[last].next = n;
        last = n;
    }

    int front = station[head].next;

    station[front].prev = last; // 원형, 어렵지 않다. 끝과 앞만 연결하면 됨
    station[last].next = front;

    for (int i = 0; i < oper; i++) {
        char ops[3];
        
        scanf("%s", ops);

        int v1;
        int v2 = -999;

        scanf("%d", &v1);

        Node station_v2 = station[v1];

        printf("%d\n", (ops[1] == 'N') ? station_v2.next : station_v2.prev); // 편법

        switch(ops[0]) {
            case 'B':
            {
                scanf("%d", &v2);

                int prev = (ops[1] == 'N') ? v1 : station_v2.prev;
                int next = (ops[1] == 'N') ? station_v2.next : v1;

                station[v2].next = next; // 설립
                station[v2].prev = prev;

                station[prev].next = v2;
                station[next].prev = v2;
                
                break;
            }
            
            case 'C':
            {
                int prev = (ops[1] == 'N') ? v1 : station[station_v2.prev].prev;
                int next = (ops[1] == 'N') ? station[station_v2.next].next : v1;
                int c = (ops[1] == 'N') ? station_v2.next : station_v2.prev;

                station[prev].next = next;
                station[next].prev = prev;
                station[c].next = 0;
                station[c].next = 0;

                break;
            }
        }
    }

    return 0;
}