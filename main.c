#include <stdio.h>
#include "algs/algs.h"

int main(int argc, char **argv) {
    int N = 7;
    int arr[7] = {2, 3, -8, 7, -1, 2, 3};
    printf("%d\n", kadane(arr, N));
    return 0;
}