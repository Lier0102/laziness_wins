#include <stdio.h>
// X666
// 666X

int main() {
    int n;
    int idx = 0;
    int i = 666;

    scanf("%d", &n);

    while(1) {
        int a = i;
        while (a >= 666) {
            if (a % 1000 == 666) {
                idx++;
                break;
            }
            a /= 10;
        }
        if (n == idx) {printf("%d", i); break;}
        i++;
    }

    return 0;
}