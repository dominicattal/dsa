def solve():
    n = 3
    t = n * (n + 1) // 2
    m = 0

    while m <= 500:
        t = n * (n + 1) // 2
        m = 0
        k = 1
        while k * k <= t:
            if t % k == 0:
                m += 2 if k * k != t else 1
            k += 1
        n += 1
    print(t)

solve()