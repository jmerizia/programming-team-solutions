# largest possible number is 9!*6 = 2,177,280

from collections import defaultdict
from math import factorial

fact = [factorial(n) for n in range(10)]

def next_num(n):
    out = 0
    while n > 0:
        out += fact[n % 10]
        n //= 10
    return out

def chain(u):
    vis = set()
    cur = u
    l = 0
    while cur not in vis:
        l += 1
        vis.add(cur)
        cur = next_num(cur)
    return l

print([chain(u) for u in range(1, 1_000_000)].count(60))
