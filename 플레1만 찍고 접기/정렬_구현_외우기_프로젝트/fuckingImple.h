#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// jst some bunch of macros

#define INT 0
#define CHAR 1
#define FLOAT 2
#define DOUBLE 3
#define ARR_1D "a1"
#define ARR_2D "a2"

// line---

typedef unsigned long long ull; // why Did i...?
typedef long long ll;

void print_a(const void *a, long long int opt, unsigned long long int size) {
    switch(opt) {
        case INT:
            int *arr = (int *)a;

            for (ull i = 0; i < size; i++) {
                printf("%d ", arr[i]);
            }

            puts("");
            break;

        default:
            puts("Usage: print_a(target, option, size)");
            break;
    }
}

void init(void **a, int opt, unsigned long long int size, int value) {
    if (a == NULL || !size) return;

    switch(opt) {
        case INT:
            int *a_t = (int *)malloc(sizeof(int) * size);
            if (a_t == NULL) return;

            for (ull i = 0; i < size; i++) {
                a_t[i] = value;
            }
            *a = a_t;
            break;
        
        case CHAR:
            break;

        case FLOAT:
            break;

        case DOUBLE:
            break;

        default:
            puts("Usage: init(target, option, size, value)\t<make sure not to use signed(that contains '-') integer as size!!>");
            break;
    }

}