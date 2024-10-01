from math import log10, ceil

def solve():
    N = 1000
    M = ceil(N * log10(2))
    arr = [0] * M
    arr[0] = 1
    carry = 0
    for i in range(N):
        for j in range(M):
            arr[j] = arr[j] * 2 + carry
            carry = 0
            if arr[j] >= 10:
                arr[j] %= 10
                carry = 1
    print(sum(arr))
    
solve()