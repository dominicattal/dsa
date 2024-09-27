#include "dp.h"

/*
Find maximum sum of subarray
https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
*/

int kadane(int* arr, int N) {
    if (N == 0) return 0;
    int res, cur, test, i;
    res = cur = arr[0];
    for (i = 1; i < N; i++) {
        cur = arr[i] + ((cur > 0) ? cur : 0);
        res = (res > cur) ? res : cur;
    }
    return res;
}

int kadane2D(int** arr, int N, int M) {

}

int kadane3D(int*** arr, int P, int Q, int R) {

}