# I found a better way
from functools import lru_cache, reduce


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

def prod(v):
    return reduce(lambda a, b: a * b, v)

@lru_cache(int(1e7))
def sumdiv(n):
    return sum(i for i in range(1, n+1) if n % i == 0)

@lru_cache(int(1e7))
def P(n):
    # more efficient recurrence relation
    if n == 0:
        return 1
    else:
        s = 0
        for k in range(n):
            s += sumdiv(n - k) * P(k)
        s //= n
        return s

def sizes(k):
    fa = factor(n)
    prod(P(m) for p, m in fa)
    ss = set()
    for es in product(*[P(m, m) for p, m in fa]):
        s = 0
        for (p, m), e in zip(fa, es):
            s += sum(p ** k for k in e)
        ss.add(s)
    return ss