# same as problem 18
def solve():
    g = []
    with open("triangle.txt") as txtfile:
        g = list(map(lambda x : list(map(int, x.split())), txtfile.readlines()))
    g.reverse()
    for i in range(1, len(g)):
        for j in range(len(g[i])):
            g[i][j] += max(g[i-1][j], g[i-1][j+1])
    print(g[-1][-1])

solve()