t = int(input())
m = {0b000: 0, 0b100: -1, 0b010: 0, 0b110: 1, 0b001: 1, 0b101: 1, 0b011: -1, 0b111: 0}
for _ in range(t):
    b,c,d = map(int, input().split())
    res = i = 0
    while b > 0 or c > 0 or d > 0:
        r = ((b&1)<<2)+((c&1)<<1)+(d&1)
        if m[r] == -1:
            res = -1
            break
        res |= m[r] << i
        i += 1
        b,c,d = b>>1, c>>1, d>>1
    print(res)