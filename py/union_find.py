f = {}

def find(x):
    fx = f.get(x)
    if fx is None:
        f[x] = x
        return x
    
    if fx != x:
        f[x] = fx = find(fx)

    return fx

def merge(u, v):
    fu, fv = find(u), find(v)
    if fu != fv:
        f[fu] = fv

find(3)
find(4)
print(f)
merge(3, 4)
print(f)