def solve():
    grid = []
    with open("grid.txt") as txtfile:
        grid = list(map(lambda x : list(map(int, x)), map(lambda x : x.split(" "), map(lambda x : x[:-1], txtfile.readlines()))))
    n = len(grid)
    dirs = [(1,1),(1,0),(0,1),(1,-1)]
    res = 0
    for i in range(n):
        for j in range(n):
            for d in dirs:
                s = 1
                if not 0 <= i + d[0]*3 < n or not 0 <= j + d[1]*3 < n:
                    continue
                for k in range(4):
                    s *= grid[i+d[0]*k][j+d[1]*k]
                res = max(res, s)
    print(res)

solve()