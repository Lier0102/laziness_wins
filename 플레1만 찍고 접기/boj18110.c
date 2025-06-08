#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int comp(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int main() {
    int n;
    int res = 0;
    int arr[1000001] = {0,};
    int numb = 0;
    
    scanf("%d", &n);

    if (!n) {printf("%d", res); return 0;}
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    qsort(arr, sizeof(arr) / sizeof(int), sizeof(int), comp);

    // for (int i = 0; i < n; i++) printf("%d ", arr[i]);

    numb = round(n * 0.15);
    double sum_large = 0;

    for (int i = numb; i < n - numb; i++) {
        sum_large += arr[i];
    }

    res = round(sum_large / (n - numb * 2));

    printf("%d\n", res);

    return 0;
}