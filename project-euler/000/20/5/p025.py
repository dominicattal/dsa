from math import log,sqrt,ceil

def solve():
    N = 1000
    print(ceil((log(sqrt(5)) + (N - 1) * log(10)) / log((1 + sqrt(5))/2)))

solve()