import math
from collections import defaultdict
from itertools import combinations


n = int(1e7 + 99)
is_prime = [True] * (n+1)
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
    if p % 1 == 0:
        print(p, '/', n)
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

MOD = 1000 * 1000 * 1009

def factor_factorial(n):
    fac = defaultdict(lambda: 0)
    for i in range(1, n+1):
        for p, m in factor(i):
            fac[p] += m
    return fac

print(factor_factorial(4))
#print(S(4))
#print(S(100 * 1000 * 1000))

