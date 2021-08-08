from math import sqrt
from decimal import Decimal, getcontext
from functools import lru_cache

getcontext().prec = 200

r5 = Decimal(5) ** (Decimal(1) / Decimal(2))
phi = (Decimal(1) + r5) / Decimal(2)
psi = (Decimal(1) - r5) / Decimal(2)

def fib_approx(n):
    # https://en.wikipedia.org/wiki/Fibonacci_number#Closed-form_expression
    # This is approx because of floating point precision
    n = Decimal(n)
    return (phi ** n - psi ** n) / r5

fib = [0] * 1_000_000
fib[1] = 1
fib[2] = 1
for i in range(3, 1_000_000):
    fib[i] = (fib[i-1] + fib[i-2]) % int(1e9)

def is_pandigital(k):
    return ''.join(sorted(k[-9:])) == '123456789'

for n in range(int(1e6)):
    # use the pre-computed starts to prune the search
    k = str(fib[n])
    if is_pandigital(k[-9:]):
        # only compute the approximation here, because it's slow
        k_full = str(round(fib_approx(n)))
        if is_pandigital(k_full[:9]):
            print(n, k)
            break
    if n % 100_000 == 0:
        print(n)