#https://en.wikipedia.org/wiki/Pythagorean_triple
def solve():
    """
    a = m*m - n*n, b = 2*m*n, c = m*m+n*n
    a + b + c = 1000
    2*m*m + 2*m*n = 1000
    m*(m+n) = 500
    m > n
    """
    m = 1
    while m * m < 500:
        for n in range(m):
            if m * (m + n) == 500:
                a = m*m - n*n
                b = 2*m*n
                c = m*m + n*n
                print(a*b*c)
                return
        m += 1
    print(-1)

solve()
    