from functools import cache

@cache
def d(n):
    res = 1
    k = 2
    while k * k <= n:
        if n % k == 0:
            res += k
            if k * k != n:
                res += n // k
        k += 1
    return res

def solve():
    N = 10000
    res = 0
    amicable = [False] * (N+1)
    for n in range(1, N):
        if n != d(n) and n == d(d(n)):
            res += n
    print(res)

solve()