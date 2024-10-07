from math import factorial as F

def solve():
    N = 1000000
    perm = ""
    cur = 1
    used = [False] * 10
    for i in range(10):
        f = F(9-i)
        j = 0
        while cur + f <= N:
            cur += f
            j += 1
        for k in range(10):
            if used[k]: 
                continue
            elif j == 0:
                perm += str(k)
                used[k] = True
                break
            else:
                j -= 1
    print(perm)

solve()