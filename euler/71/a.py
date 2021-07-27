# attempt 1

from math import gcd, sqrt
from decimal import *
getcontext().prec = 1000

# q = Decimal(2) ** (Decimal(1) / Decimal(2))


# more generic implementation
def cf(q, n):
    if n == 0:
        return []
    a = int(q)
    r = q - a
    return [a] + cf(Decimal(1)/r, n-1)

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

def convergent(A):
    if len(A) == 1:
        return (A[0], 1)
    return add((A[0], 1), divide((1, 1), convergent(A[1:])))

gold = abs((300_000-1) / (700_000) - 3 / 7)
print(f'gold standard: {gold}')


# q = Decimal(3) / Decimal(7) * (Decimal(1_000_000_000 - 1) / Decimal(1_000_000_000))
# n, d = convergent(cf(q, 5))
# print(Decimal(3) / Decimal(7) - n / d)
# quit()


best_value = 9999
best = (None, None)
for i in range(1, 100_000):
    # choose something slightly smaller than 3 / 7
    q = Decimal(3) / Decimal(7) * (Decimal(1_000_000 - i) / Decimal(1_000_000))
    for j in range(1, 1000):
        n, d = convergent(cf(q, j))
        if d > 1_000_000:
            break
        if d < 1_000_000 and abs(n / d - 3 / 7) < best_value:
            best = (n, d)
            best_value = n / d
            print(f'New best: {n} / {d} error = {3 / 7 - n / d:0.09f}')
