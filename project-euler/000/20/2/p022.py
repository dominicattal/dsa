def solve():
    res = 0
    names = []
    with open("names.txt") as txtfile:
        names = list(map(lambda x : x[1:-1], txtfile.read().split(',')))
    names.sort()
    for i, name in enumerate(names):
        res += sum([ord(c)-ord('A')+1 for c in name]) * (i+1)
    print(res)

solve()