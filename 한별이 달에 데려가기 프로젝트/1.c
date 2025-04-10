#include <stdio.h>
#include <stdlib.h>

int v1(int n, int b) {
    int r=n%abs(b);
    if(r<0) r+=abs(b);
    // printf("%d", abs(b)/n);
    // printf("%d", n/abs(b))
    return r;
}
int v2(int n, int b, char r[]) {
    int na=b>0?abs(n) : n; // FUCKING abs mechanism
    int t; 
    int c=0;
    while(na) { t=v1(na,b); na=(na-t)/b; r[c++]=t+'0'; } 
    if(!c) r[c++]='0'; r[c]=0;
    return (b>0&&n<0);
}
void v3(char r[], int m) {
    int i;
    if(m) putchar('-');
    for(i=1;r[i];i++);
    for(i--;i>=0;i--) putchar(r[i]); putchar('\n'); 
}
int main() {
    int n, b, m; 
    char r[64];

    scanf("%d %d",&n,&b);

    m = v2(n, b, r);
    v3(r, m);

    return 0;
}