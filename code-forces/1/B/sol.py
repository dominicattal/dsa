#https://codeforces.com/contest/2020/problem/B

# idk why this doesnt work
def solve1():
    t = int(input())
    for _ in range(t):
        k = int(input())
        print(k + int(k**0.5 + 0.5))

def solve2():
    t = int(input())
    for _ in range(t):
        k = int(input())
        l,r = 1, 2*pow(10,18)
        while r - l > 1:
            m = (l + r) >> 1
            n = m - int(m**0.5)
            if n >= k: 
                r = m
            else: 
                l = m
        print(r)

solve2()