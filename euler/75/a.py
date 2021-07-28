# using Euclid's theorem

from math import gcd
from collections import defaultdict

def one_even(n, m):
    return n % 2 != m % 2

# compute primitive triples
triples = set()
for n in range(1, 5000):
    tim = 0
    for m in range(n+1, 5000):
        if gcd(n, m) == 1 and one_even(n, m):
            tim += 1
            a = m*m-n*n
            b = 2*m*n
            c = m*m+n*n
            assert a > 0 and b > 0 and c > 0
            if a + b + c > 1_500_000:
                break
            triples.add(tuple(sorted((a, b, c))))

print(len(triples), 'primitive triples:')

# compute all triples
all_triples = triples.copy()
for idx, triple in enumerate(sorted(triples)):
    tim = 0
    for k in range(1, 1_500_000):
        tim += 1
        a, b, c = triple
        _a, _b, _c = k*a, k*b, k*c
        if _a + _b + _c > 1_500_000:
            break
        all_triples.add((_a, _b, _c))

print(len(all_triples), 'total triples')

Ls = defaultdict(lambda: 0)
for triple in all_triples:
    a, b, c = triple
    Ls[a+b+c] += 1
print(list(Ls.values()).count(1))
