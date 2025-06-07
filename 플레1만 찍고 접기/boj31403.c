#include <stdio.h>

int main() {
    int a, b, c;

    scanf("%d%d%d", &a, &b, &c);

    if (b < 10) printf("%d\n%d", a+b-c, a*10+b-c);
    else if (b < 100) printf("%d\n%d", a+b-c, a*100+b-c);
    else if (b < 1000) printf("%d\n%d", a+b-c, a*1000+b-c);
    else printf("%d\n%d", a+b-c, a*10000+b-c);

    return 0;
}