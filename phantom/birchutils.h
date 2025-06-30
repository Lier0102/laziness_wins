/* birchutils.h */
#ifndef Birchutils
#define Birchutils
// 커스텀 헤더(ip socket 구현할 때 사용할 예정)
#include <stdio.h>

typedef unsigned char int8;
typedef unsigned short int int16;
typedef unsigned int int32;

void zero(int8*, int16); // 메모리 지정 후 비우기

void copy(int8* dst, int8* src, int16 size) {
    int8* d, * s;
    int16 n;

    for (n = size, d = dst, s = src; n; n--, d++, s++)
        *d = *s;

    return;
}

void zero(int8* str, int16 size) {
    int8* p;
    int16 n;

    for (n = 0, p = str; n < size; n++, p++)
        *p = 0;

    return;
}

void printhex(int8* str, int16 size, int8 delim) { // 16진수 출력(네트워크 할 때 쓸거)
    int8* p;
    int16 n;

    for (p = str, n = size; n; n--, p++) {
        printf("%.02x", *p);
        if (delim)
            printf("%c", delim);
        fflush(stdout);
    }
    printf("\n");

    return;
}

#pragma GCC diagnostic pop

#endif /* Birchutils */