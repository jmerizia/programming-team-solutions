from functools import lru_cache, reduce
from itertools import product
from collections import defaultdict
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

S = defaultdict(lambda: 0)
for n in range(800*1000):
    S[sum(p * m for p, m in factor(n))] += n

print(S[10])
quit()

fib = list(1 for _ in range(24))
for i in range(2, 24):
    fib[i] = fib[i-1] + fib[i-2]

ans = 0
for i in range(2, 24):
    ans += S[fib[i]]

print(ans)

