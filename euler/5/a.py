import math
import functools as ft

n = 20

print(ft.reduce(lambda a, b: a * b // math.gcd(a, b), range(1, n)))
