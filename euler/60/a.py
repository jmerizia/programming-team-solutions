# try #2

from itertools import product
import itertools
from collections import defaultdict
import math
from functools import lru_cache, reduce
import time

print('this will be slow...')

# from 27
st = time.time()
m = int(5e6)
is_prime_l = [True for _ in range(m+1)]
is_prime_l[0] = False
is_prime_l[1] = False
k = 2

while k * k <= m:
    if is_prime_l[k]:
        for i in range(k*k, m+1, k):
            is_prime_l[i] = False
    k += 1
en = time.time()

print(f'sieve done {en-st:.2f}')

@lru_cache(int(1e7))
def is_prime(n):
    if n <= 1:
        return False
    if n < len(is_prime_l):
        return is_prime_l[n]
    for i in range(2, min(n, int(math.sqrt(n)) + 1)):
        if n % i == 0:
            return False
    return True

def cat(a, b):
    return int(str(a) + str(b))

def check(v):
    for p in v:
        for q in v:
            if p != q and not (is_prime(cat(p, q)) and is_prime(cat(q, p))):
                return False
    return True

# st = time.time()
N = 10000
primes = [p for p in range(N) if is_prime(p)]
adj = defaultdict(lambda: [])
for p in primes:
    for q in primes:
        if p != q and is_prime(cat(p, q)) and is_prime(cat(q, p)):
            adj[p].append(q)
            adj[q].append(p)
en = time.time()

print(f'graph done {en-st:.2f}')

def inter(*args):
    return list(reduce(lambda a, b: set(a) & set(b), args))

results = []
for p1 in primes:
    for p2 in adj[p1]:
        for p3 in inter(adj[p1], adj[p2]):
            for p4 in inter(adj[p1], adj[p2], adj[p3]):
                for p5 in inter(adj[p1], adj[p2], adj[p3], adj[p4]):
                    results.append((p1, p2, p3, p4, p5))

print(len(results))
if len(results) > 0:
    ans = list(sorted(results, key=lambda x: sum(x)))[0]
    assert check(ans)
    print(ans, 'sum:', sum(ans))
