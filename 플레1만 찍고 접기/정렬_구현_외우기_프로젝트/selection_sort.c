#include <stdio.h>
#include <stdlib.h> // 알고리즘 상으로 메모리 할당을 구현하려면 Ptmalloc2의 bin을 구현할 줄 알아야함.
#include <unistd.h>
#include <string.h>
// #include <Windows.h>
// #include <conio.h>
// 나는 못함.

int main() {
    int min, idx, tmp;
    int n;
    int *arr;

    scanf("%d", &n);

    arr = (int *)malloc(sizeof(int) * n);
    arr = memset(arr, 0, n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    for (int i = 0; i < n; i++) {
        min = 9999;
        for (int j = i; j < n; j++) {
            if (arr[j] < min) {
                min = arr[j];
                idx = j;
            }

            tmp = arr[idx];
            arr[idx] = arr[i];
            arr[i] = tmp;
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);

    return 0;
}