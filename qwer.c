#include <stdio.h>
#include <string.h>

int main() {
    char s[100000] = {'\0'};
    char t[100000] = {'\0'};
    

    while (scanf("%s %s", s, t) != EOF) {
        int len = strlen(s);
        int len2 = strlen(t);
        int c = 0;
        for (int i = 0; i < len2; i++) {
            if (t[i] == s[c]) {
                len--;
                c++;
            }
        }
        if (!len) puts("Yes");
        else puts("No");
    }

    

    return 0;
}