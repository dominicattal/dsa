def isprime(primes, x):
    for p in primes:
        if p * p > x:
            break
        if x % p == 0:
            return False
    return True

def solve():
    primes = []
    p = 2
    while len(primes) < 10001:
        if isprime(primes, p):
            primes.append(p)
        p += 1
    print(primes[-1])

solve()