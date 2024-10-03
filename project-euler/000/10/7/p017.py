def solve():
    vals = {0:0, 1:3, 2:3, 3:5, 4:4, 5:4, 6:3, 7:5, 8:5, 9:4, 
            10:3, 11:6, 12:6, 13:8, 14:8, 15:7, 16:7, 17:9, 18:8, 19:8,
            20:6, 30:6, 40:5, 50:5, 60:5, 70:7, 80:6, 90:6}
    
    m = 3 + 3 + 5 + 4 + 4 + 3 + 5 + 5 + 4 + 3 + 6 + 6 + 8 + 8 + 7 + 7 + 9 + 8 + 8
    for num in range(20, 100):
        m += vals[num // 10 * 10] + vals[num % 10]
    res = 10 * m + 11
    for i in range(9):
        res += (vals[i+1] + 10) * 100 - 3
    print(res)
            
solve()