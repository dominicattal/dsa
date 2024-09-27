def solve():
    # inclusion exclusion
    n = 999//3
    set3 = 3 * (n * (n + 1) // 2)
    n = 999//5
    set5 = 5 * (n * (n + 1) // 2)
    n = 999//15
    set15 = 15 * (n * (n + 1) // 2)
    print(set3 + set5 - set15)

solve()