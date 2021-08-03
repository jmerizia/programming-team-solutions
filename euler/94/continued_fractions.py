# ok, let's be smarter with continued fractions and the pell equation

from math import sqrt, gcd
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

def cf(q, u, v, n):
    if n == 0:
        return []
    a = int((sqrt(q) + u) / v)
    u2 = - (u - a * v)
    v2_top = q - (u - a * v) ** 2
    assert v2_top % v == 0
    v2 = v2_top // v
    return [a] + cf(q, u2, v2, n-1)

def convergent(A):
    if len(A) == 1:
        return (A[0], 1)
    return add((A[0], 1), divide((1, 1), convergent(A[1:])))

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

perimeters = []
solutions = []
f, l = cycle(3, n=1500)
r = l - 1
if r % 2 == 0:
    idx = 2 * r + 1
else:
    idx = r
reached_max = False
for i in range(300):
    c = f[:idx+l*i+1]
    r, s = convergent(c)
    p, q = 2, 0  # base solution
    m, t = p*r+3*q*s, p*s+q*r
    assert m*m-3*t*t == 4
    if (m + 1) % 3 == 0:
        n = (m + 1) // 3
        if n > 1:  # no zero volume triangles
            p = 3*n+1
            if p > int(1e9):
                reached_max = True
                break
            # print(n, p, '+')
            perimeters.append(p)
            solutions.append(n)
            s = p / 2
            a = sqrt(s*(s-n)*(s-n)*(s-(n+1)))
            assert abs(a - round(a)) < 1e-4, a
    if (m - 1) % 3 == 0:
        n = (m - 1) // 3
        if n > 1:  # no zero volume triangles
            p = 3*n-1
            if p > int(1e9):
                reached_max = True
                break
            # print(n, p, '-')
            perimeters.append(p)
            solutions.append(n)
            s = p / 2
            a = sqrt(s*(s-n)*(s-n)*(s-(n-1)))
            assert abs(a - round(a)) < 1e-4, a

assert reached_max

# print(solutions)
print('ans =', sum(perimeters))
