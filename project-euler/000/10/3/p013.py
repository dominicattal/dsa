def solve():
    nums = []
    with open("numbers.txt") as txtfile:
        nums = list(map(lambda x : int(x[:11]), txtfile.readlines()))
    print(str(sum(nums))[:10])

solve()