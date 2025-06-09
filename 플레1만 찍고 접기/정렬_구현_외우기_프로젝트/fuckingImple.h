#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void print_a(const void *a, long long int opt, unsigned long long int size) {
    if (opt > 3) {
        for (int i = 0; i < size; i++) {
            printf("%d ", *(int *)a + i); // haven't tried(just lil imple)
        }
        puts("");
    }
}