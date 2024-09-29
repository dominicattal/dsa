#https://en.wikipedia.org/wiki/Square_pyramidal_number

def A(n):
    return n*(n+1)*(2*n+1)//6

def B(n):
    return n*(n+1)//2

def solve():
    print(B(100)*B(100)-A(100))

solve()