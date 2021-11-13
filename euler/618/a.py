from functools import lru_cache, reduce
from itertools import product
from math import sqrt
import sys

sys.setrecursionlimit(60000)



n = int(2e6 + 99)
is_prime = [True] * (n+1)
primes = []
spf = list(range(n+1))
is_prime[1] = False
p = 2
while p*p <= n:
    if is_prime[p]:
        i = p*p
        while i <= n:
            is_prime[i] = False
            if spf[i] == i:
                spf[i] = p
            i += p
    p += 1
for p in range(2, n+1):
    if is_prime[p]:
        primes.append(p)
print('Done sieve')

def factor(n):
    fa = []
    p = spf[n]
    while p <= n and n > 1:
        m = 0
        while n % p == 0:
            m += 1
            n //= p
        fa.append((p, m))
        p = spf[n]
    return fa

MOD = 1000*1000*1000
tim = 0

@lru_cache(int(1e6))
def S(k, m=0):
    global tim
    tim += 1
    if k == 0:
        return [[]]
    poss = []
    for i in range(m, len(primes)):
        if k - primes[i] < 0:
            break
        for p in S(k - primes[i], i):
            poss.append(p + [primes[i]])
    return poss

for n in [4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14]:
    print('n =', n)
    results = []
    for poss in S(n, 0):
        results.append([ reduce(lambda a, b: a*b, poss, 1), poss ])

    ans = 0
    for result in sorted(results):
        print(' ', result[0], result[1])
        ans += result[0]
    print('  ans =', ans)

