#include "fuckingImple.h"

// I know, yes, I know that I can fucking use qsort(), but, just hear me out.
// using a fucking pre-built qsort(), is really helpful for me? nuh uh

void sort(int *data, int start, int end) {
    if (start >= end) return; // if just a single element exists,

    int pivot = start; // (start + end) / 2? nuh uh

    int s = start + 1; // left -> right
    int e = end; // left <- right

    int tmp;

    while (s <= e) {
        while (s <= end && data[s] >= data[pivot]) {
            s++;
        }

        while (e > start && data[e] <= data[pivot]) {
            e--;
        }

        if (s > e) {
            tmp = data[pivot];
            data[pivot] = data[e];
            data[e] = tmp;
        } else {
            tmp = data[e];
            data[e] = data[s];
            data[s] = tmp;
        }
    }

    sort(data, start, e - 1);
    sort(data, e + 1, end);
}

int main() {
    int n;
    int *arr;

    scanf("%d", &n);
    init((void **)&arr, INT, n, 0);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    puts("<< BEFORE >>");
    print_a(arr, INT, n);

    // some quick sort
    sort(arr, 0, n);

    puts("<< AFTER >>");
    print_a(arr, INT, n);

    return 0;
}