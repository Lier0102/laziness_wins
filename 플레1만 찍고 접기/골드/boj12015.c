#include <stdio.h>
// #include "my_algorithm"

// int tmp;
// int tmp_cnt[1000001];
int n;
int dp[1000001];
int arr[1000001];
int len;

int f1();
int f_l();

int main() {
    // int arr[1000001] = {0,};
    // int n;
    // int cnt = 1;

    // scanf("%d", &n);
    
    // for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    // for (int i = 0; i < n; i++) {
    //     tmp = arr[i];
    //     for (int j = i+1; j < n; j++) {
    //         if (tmp < arr[j]) {
    //             tmp = arr[j];
    //             cnt++;
    //         }
    //     }
    //     tmp_cnt[i] = cnt;
    //     cnt = 1;
    // }
    // printf("%d", tmp_cnt[0]);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("%d\n", len);

    return 0;
}

int f1() {
    len = 0;
    for (int i = 1; i <= n; i++) {
        if (dp[len] < arr[i]) {
            dp[++len] = arr[i];
        } else {
            int lower = f_l();
            dp[lower] = arr[i];

        }
    }
}

int f_l(int start, int casted) {
    
}

// testcases
// 1 2 3 4
// 4 3 2 1
// 1 1 1 1
// 2 9 5 8
// 83 68 83
// 