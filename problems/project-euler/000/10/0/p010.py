def solve():
    primes = []
    s = 0
    p = 2
    def isprime(x):
        for k in primes:
            if k * k > x: break
            if x % k == 0: return False
        return True
    while p < 2000000:
        if isprime(p):
            primes.append(p)
            s += p
        p += 1
    print(s)

solve()