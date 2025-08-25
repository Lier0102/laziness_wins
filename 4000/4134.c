#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int t;

    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        long long n;

        scanf("%lld", &n);

        if (n == 0 || n == 1 || n == 2) {
            printf("2\n");
            continue;
        }

        while (1) {
            int res = 0;

            for (long long j = 2; j <= sqrt(n) + 1; j++) {
                if (n % j == 0) {
                    res = 1;
                    break;
                }
            }
            if (!res) { printf("%lld\n", n); break; }

            n++;
        }
    }
}