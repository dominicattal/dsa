# function from p21
def d(n):
    if n == 0: 
        return 0
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
    N = 28123
    abundant = []
    for n in range(N + 1):
        if d(n) > n:
            abundant.append(n)
    valid = [True] * (N+1)
    for i in range(len(abundant)):
        for j in range(i+1):
            s = abundant[i] + abundant[j]
            if s < N + 1:
                valid[s] = False
    res = 0
    for n, v in enumerate(valid):
        if v:
            res += n
    print(res)

solve()