def solve():
    num = ""
    with open("num.txt") as txtfile:
        num = "".join(txtfile.read().split("\n"))
    res = 0
    for i in range(len(num) - 13):
        prod = 1
        for j in range(13):
            prod *= int(num[i+j])
        res = max(res, prod)
    print(res)
    
solve()