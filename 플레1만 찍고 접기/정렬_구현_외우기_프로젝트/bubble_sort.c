#include "fuckingImple.h"

int main() {
    int tmp;
    int* arr;
    int n;

    scanf("%d", &n);
    // init(arr, "int", n, 0);
    arr = (int *)malloc(sizeof(int) * n);
    memset(arr, 0, sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}