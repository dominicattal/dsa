from heapq import heapify, heappop, heappush

def solve():
    q = [(-999*999, 999, 999)]
    seen = set()
    heapify(q)
    while q:
        a, b, c = heappop(q)
        if str(-a) == str(-a)[::-1]:
            print(-a)
            return
        if (b, c) not in seen:
            seen.add((b, c))
            heappush(q, (-b*(c-1), b, c-1))
            if b > c:
                heappush(q, (-(b-1)*c, b-1, c))
    print(-1)

def solve2():
    """
    11(9091a + 910b + 100c) = mn
    9091 * 11 = 100001
    910 * 11 = 010010
    100 * 11 = 001100
    11 * 10 <= m <= 11 * 90
    """
    for a in range(9, 0, -1):
        for b in range(9, -1, -1):
            for c in range(9, -1, -1):
                num = 9091 * a + 910 * b + 100 * c
                for m in range(90, 10, -1):
                    if num % m == 0:
                        if num // m > 999: 
                            break
                        else:
                            print(num * 11)
                            return

solve2()