from decimal import *
from math import sqrt
getcontext().prec = 200


def is_square(n):
    return sqrt(n) == int(sqrt(n))

s = 0
for n in range(2, 101):
    if not is_square(n):
        q = Decimal(n) ** (Decimal(1) / Decimal(2))
        o, d = str(q).split('.')
        s += sum(map(int, d[:99]), int(o))
print(s)
