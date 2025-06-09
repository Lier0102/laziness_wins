#include "fuckingImple.h" // You HAVE TO, NUH, MUST KNOW WHAT I MEANT TO SAY BELOW

int main() {
    int tmp;
    int *arr; // <--- the very, the most, the first fucking, YES. THE POINTER.
    int n;
    
    scanf("%d", &n); // So you have an input!

    init((void **)&arr, INT, n, 0);
    if (arr == NULL) { puts("Fucked up ! ! "); return 31337; } // ah, yes, 31337. the sexy number is here.

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            puts("[ + ] Well, We're fucked. We now, have to fucking know what the fuck is actually going on here!"); // A normal error message that came from my mind
            free(arr);
            return 31337;
        }
    }

    for (int i = 0; i < n - 1; i++) { // just the simple insertion sort. but I spent almost 44 mins just because I wANTED TO BUILD MY OWN HEADER???? IN FUCKING C LANG???
        int j = i;

        while (j >= 0 && arr[j] > arr[j + 1]) { // think i = 1 is the best, huh?
            // will be updated AS soon...nuh, I don't think so I DON T THINKG S OS GOTHI HGNKJASFID
            tmp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = tmp;
            j--;
        }
    }

    print_a(arr, INT, n);
    free(arr); // RAHHHHHHHH

    return 0; // finally, I, yes. YES. YEEEAAAASSSSS
}