#include <stdio.h>

int main() {
    char str[3] = {'\0'};
    unsigned int max = 0;

    scanf("%s", str);

    for (int i = 0; i < 3; i++) {
        if (max < str[i] - '0') max = str[i] - '0';
    }

    printf("%d", max);

    return 0;
}