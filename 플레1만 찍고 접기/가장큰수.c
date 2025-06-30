// #include <stdio.h>

// int main() {
//     int arr[5];
//     int max = -1;
//     int idx = 1;
    
//     for (int i = 0; i < 5; i++) scanf("%d", &arr[i]);

//     for (int i = 0; i < 5; i++) {
//         if (max < arr[i]) { // 처음값만 기록하기 위해(동점무시)
//             max = arr[i];
//             idx = i + 1;
//         } 
//     }

//     printf("%d\n%d", max, idx);


//     return 0;
// }

// #include <stdio.h>

// int main() {
//     int n;
//     int arr[10000];

//     scanf("%d", &n);

//     for (int i = 0; i < n; i++) {  
//         scanf("%d", &arr[i]);
//     }   

//     for (int i = n - 1; i >= 0; i--) {
//         printf("%d ", arr[i]);
//     }

//     return 0;
// }

#include <stdio.h>

int main() {
    int n;
    int arr[10000];
    int max = __INT_MAX__;
    int min = __INT_MAX__;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (max < arr[i]) max = arr[i];
        if (min > arr[i]) min = arr[i];
    }

    printf("%d %d", min, max);

    return 0;
}