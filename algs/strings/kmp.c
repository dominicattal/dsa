/*
https://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm
https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/

Given two strings txt and pat of size N and M, where N > M.
String txt and pat represent the text and pattern respectively.
Print all indexes of occurrences of pattern string in the text string.
*/

#include "strings.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* compute_lps_array(const char* pat, int M) {
    int* lps = malloc(M * sizeof(int));
    int len, i;
    len = lps[0] = 0;
    i = 1;
    while (i < M) {
        if (pat[len] == pat[i]) {
            lps[i++] = ++len;
        }
        else {
            if (len != 0)
                len = lps[len - 1];
            else
                lps[i++] = 0;
        }
    }
    return lps;
}

int* kmp(const char* txt, const char* pat, int* count) {
    int N, M, i, j;
    N = strlen(txt);
    M = strlen(pat);
    int* lps = compute_lps_array(pat, M);
    int* res = malloc(N * sizeof(int));
    *count = 0;
    i = j = 0;
    while ((N - i) >= (M - j)) {
        if (pat[j] == txt[i])
            i++, j++;
        if (j == M) {
            res[(*count)++] = i - j;
            j = lps[j - 1];
        } else if (i < N && pat[j] != txt[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    free(lps);
    return res;
}