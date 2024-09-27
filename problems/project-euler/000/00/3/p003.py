def solve():
    n = 600851475143
    p = 1
    primes = []

    def isprime(x):
        i = 0
        while i < len(primes) and primes[i]*primes[i] <= x:
            if x % primes[i] == 0:
                return False
            i += 1
        return True

    while n > 1:
        p += 1
        if not isprime(p):
            continue
        primes.append(p)
        while n % p == 0:
            n //= p
    print(p)

solve()