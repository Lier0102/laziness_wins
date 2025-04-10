#include <stdio.h>

int main(void) {
    int a[10] = {10, 8, 6, 3, 9, 5, 4, 2, 1, 7};
    int tmp;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10 - (i+1); j++) {
            if (a[j] > a[j+1]) {
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}