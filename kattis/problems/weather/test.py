from itertools import product

p = [0.9, 0.049999, 0.05, 0.000001]
d = [1, 2, 3, 3]
tot = 0
for r in product(zip(p, d), repeat=2):
    a, b = r
    tot += a[0]*a[1]
    tot += b[0]*b[1]
print(tot/16)
