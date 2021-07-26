# try 2

from math import sqrt, gcd
import sys
sys.setrecursionlimit(2000)

# https://mathworld.wolfram.com/PellEquation.html

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

def eea(a, b):
    if a == 0 :  
        return b,0,1
    g, p, q = eea(b % a, a) 
    x = q - (b // a) * p
    y = p
    return g, x, y

def cf(q, u, v, n):
    # print(u, v)
    if n == 0:
        return []
    a = int((sqrt(q) + u) / v)
    u2 = - (u - a * v)
    v2_top = q - (u - a * v) ** 2
    assert v2_top % v == 0
    v2 = v2_top // v
    return [a] + cf(q, u2, v2, n-1)

def eq(v):
    return len(set(v)) == 1

def cycle(q, n=1000):
    f = cf(q, 0, 1, n)
    # print(f)
    for l in range(1, len(f) // 2):
        is_cycle = True
        for o in range(1, 1+l):
            if not eq(f[o::l]):
                is_cycle = False
                break
        if is_cycle:
            return f, l
    return None

def convergent(A):
    if len(A) == 1:
        return (A[0], 1)
    return add((A[0], 1), divide((1, 1), convergent(A[1:])))

def is_square(n):
    return sqrt(n) == int(sqrt(n))


# 3^2 – 2×2^2 = 1
# 2^2 – 3×1^2 = 1
# 9^2 – 5×4^2 = 1
# 5^2 – 6×2^2 = 1
# 8^2 – 7×3^2 = 1

mx_x = -1
mx_x_D = None
for D in range(2, 1000+1):
    if not is_square(D):
        f, l = cycle(D)
        r = l - 1
        if r % 2 == 0:
            idx = 2 * r + 1
        else:
            idx = r
        c = f[:idx+1]
        x, y = convergent(c)
        print(f'D = {D}, idx = {idx} : {x}/{y}')
        assert x ** 2 - D * y ** 2 == 1
        if x > mx_x:
            mx_x = x
            mx_x_D = D

print(mx_x_D)
