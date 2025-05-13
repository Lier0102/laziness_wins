#include <stdio.h>
#include <string.h>

int main() {
    char arr[100000] ={'\0'};

    scanf("%s", arr);

    int len = strlen(arr);

    for (int i = 0; i < len / 2; i++) {
        if (arr[i] != arr[len - i - 1]) {printf("no"); return 0;}
    }

    printf("yes");
    
    return 0;
}

// 방법 2. strlen 구현
// #include <stdio.h>

// int main() {
//     char str[100000] = {'\0'};
//     int v2=0;
//     int v1=0;

//     scanf("%s", str);

//     while(1) {
//         if (str[v2] == '\0') break;
//         v2++;
//     }

//     for (int i = 0; i < v2 / 2; i++) {
//         if (str[i] != str[v2 - i - 1]) {
//             puts("no");
//             goto end;
//         }
//     }
//     puts("yes");

//     end:
//         return 0;
// }