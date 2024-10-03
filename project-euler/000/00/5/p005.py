def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

def solve():
    x = [i+1 for i in range(20)]
    lcm = x.pop()
    while x:
        m = x.pop()
        lcm = lcm * m // gcd(lcm, m)
    print(lcm)

solve()