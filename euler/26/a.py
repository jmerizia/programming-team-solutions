from decimal import *
getcontext().prec = 5000

m = 1000
is_prime = [True for _ in range(m+1)]
is_prime[0] = False
is_prime[1] = False
k = 2

while k * k <= m:
    if is_prime[k]:
        for i in range(k*k, m+1, k):
            is_prime[i] = False
    k += 1
primes = [p for p in range(1000) if is_prime[p]]

def max_cycle(f):
    for w in range(1, len(f)):
        k = f[0:w]
        strs = [f[o:o+w] for o in range(0, len(f), w)][:3]
        #print(strs)
        if len(set(strs)) == 1:
            return w
    return 0

ans = -1
l = -1
for d in primes:
    f = str(Decimal(1)/Decimal(d))[2:]
    k = max_cycle(f)
    if k > l:
        l = k
        ans = d

print(ans)
