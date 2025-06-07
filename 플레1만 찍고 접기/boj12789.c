#include <stdio.h>

int stack[1001];
int top = - 1;
int order = 1;

int main() {
    int n;

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        int v;
        
        scanf("%d", &v);
        
        if (order == v) order++;
        else stack[++top] = v;
        
        while (top >= 0 && stack[top] == order) {
            order++;
            top--;
        }
    }

    if (order-1 == n) {
        puts("Nice");
    } else {
        puts("Sad");
    }


    return 0;
}