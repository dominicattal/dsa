from functools import cache

@cache
def collatz(n):
    if n == 1: return 0
    return 1 + (collatz(n//2) if n % 2 == 0 else collatz(3*n+1))

def solve():
    res = (0, 0)
    for num in range(1, 1000000):
        res = max(res, (collatz(num), num))
    print(res[1])

solve()