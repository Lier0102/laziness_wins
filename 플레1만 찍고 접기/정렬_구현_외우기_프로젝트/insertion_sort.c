#include "fuckingImple.h"

int main() {
    int tmp;
    int *arr;
    int n;
    
    scanf("%d", &n);

    arr = (int *)malloc(sizeof(int) * n);
    memset(arr, 0, sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    for (int i = 0; i < n - 1; i++) {
        int j = i;

        while (j >= 0 && arr[j] > arr[j + 1]) {
            tmp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = tmp;
            j--;
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}