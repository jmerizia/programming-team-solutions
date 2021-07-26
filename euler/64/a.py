from math import sqrt
from functools import reduce
import sys
sys.setrecursionlimit(2000)


def cf(q, u, v, n):
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
            return f[1:1+l]
    return None

def is_square(n):
    return sqrt(n) == int(sqrt(n))

odd = 0
for q in range(2, 10_001):
    if not is_square(q):
        per = len(cycle(q))
        assert per != 0
        if per % 2 == 1:
            odd += 1
        if q % 1000 == 0:
            print(q, '/', 10_000)

print(odd)