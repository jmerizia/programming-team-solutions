from itertools import permutations
from sympy import isprime

ps = []
for perm in permutations('1234567'):
    i = int(''.join(perm))
    if isprime(i):
        ps.append(i)

print(len(ps))
print(max(ps))
