import random
random.seed(0)
from itertools import combinations
m = int(1e3) # just barely maxes out 1e6 max Ai
primes = []
is_prime = [True]*(m+1)
p = 2
while p*p <= m:
    if is_prime[p]:
        for i in range(p*p, m+1, p):
            is_prime[i] = False
    p += 1
for p in range(2, m+1):
    if is_prime[p]:
        primes.append(p)
# bamboo w/ no solutions
#a = [x*y for x, y in zip(primes, [1]+primes)]
# everything directly connected to 2
#a = [2]+[2*x for x in primes[1:]]
# large random numbers
a = [random.randint(int(5e5), int(1e6)) for _ in range(int(1e5))]
# all densely connected
#a = [x*y for x, y in combinations(primes, r=2)]
print(len(a))
print(' '.join(map(str, a)))
