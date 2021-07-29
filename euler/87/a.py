from math import sqrt

n = int(sqrt(5e7) + 99)
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


uniq = set()
for a in primes:
    for b in primes:
        for c in primes:
            t = a ** 2 + b ** 3 + c ** 4
            if t >= 50_000_000:
                break
            uniq.add(t)
print(len(uniq))
