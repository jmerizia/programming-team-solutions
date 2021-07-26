from math import gcd
import sys
sys.setrecursionlimit(2000)

def reduce(f):
    a, b = f
    g = gcd(a, b)
    return a // g, b // g

def add(f1, f2):
    a1, b1 = f1
    a2, b2 = f2
    num = a1 * b2 + a2 * b1
    den = b1 * b2
    return reduce((num, den))

def divide(f1, f2):
    a1, b1 = f1
    a2, b2 = f2
    num = a1 * b2
    den = a2 * b1
    return reduce((num, den))

def cf(n):
    if n == 0:
        return (2, 1)
    return add((2, 1), divide((1, 1), cf(n-1)))

ans = 0
for n in range(1000):
    a, b = add(cf(n), (-1, 1))
    if len(str(a)) > len(str(b)):
        ans += 1
print(ans)
