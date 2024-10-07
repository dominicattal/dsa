#https://codeforces.com/contest/2020/problem/A
t = int(input())
for i in range(t):
    n,k = map(int, input().split())
    res = 0
    if k == 1:
        print(n)
        continue
    h = 1
    while h * k <= n:
        h *= k
    while n > 0:
        res += n // h
        n = n - (n // h) * h
        h //= k
    print(res)