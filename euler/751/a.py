from decimal import *
import math

getcontext().prec = 100

def f(n):
    return Decimal(int(n)) * (n - Decimal(int(n)) + Decimal(1))

th = Decimal('2.2235610193135541061731771952804868081407232136055413866311')
x = th
t = str(int(x)) + '.'
for _ in range(30):
    x = f(x)
    t += str(int(x))
th = str(th)
print(th)
print(t)
for idx, (c1, c2) in enumerate(zip(th, t)):
    if c1 != c2:
        print((" "*idx) + "^")
        break

print(f'rounded: {th:.26}')
