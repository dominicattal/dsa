def solve():
    f1, f2 = 1, 2
    res = 0
    while f2 < 4000000:
        if f2 % 2 == 0:
            res += f2
        f1, f2 = f2, f1 + f2
    print(res)

solve()