#include <stdio.h>

int arr[50000000];
int n;

int main() {
    for (int i = 2; i <= 25000000; i++) { // 체 구현(반만 탐색하면 끝)
        if (arr[i]) continue;
        for (int j = 2 * i; j <= 50000000; j += i) {
            arr[j] = 1;
        }
    }

    while(scanf("%d", &n) != EOF) {
        if (n < 8) {
            puts("Impossible.");
            continue;
        }
        if (!(n % 2)) {
            printf("2 2 ");
            n -= 4;
        } else {
            printf("2 3 ");
            n -= 5;
        }

        if (n == 4) { printf("2 2\n"); continue;}

        for (int i = 3; i <= n / 2; i += 2) {
            if (!arr[i] && !arr[n-i]) {
                printf("%d %d\n", i, n - i);
                break; // 마지막 수
            }
        }
    }

    return 0;
}