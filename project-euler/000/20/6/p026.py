from math import floor
# https://en.wikipedia.org/wiki/Repeating_decimal

def repetend(p, q):
    s = f"{p // q}."
    memo = {}
    pos = len(s)
    length = 0
    p = (p % q) * 10
    while q != 0:
        idx = (p // q, p % q)
        if idx in memo:
            length = pos - memo[idx]
            s += ')'
            s = s[:memo[idx]] + '(' + s[memo[idx]:]
            break
        memo[idx] = pos
        s += str(p // q)
        p = (p % q) * 10
        pos += 1
    return length

def solve():
    N = 1000
    res = (0, 0)
    for d in range(1, N):
        res = max(res, (repetend(1, d), d))
    print(res[1])

solve()