from math import gcd


n = int(1e6 + 99)
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


def factor(n):
    fa = []
    p = spf[n]
    while p <= n and n > 1:
        m = 0
        while n % p == 0:
            m += 1
            n //= p
        fa.append((p, m))
        p = spf[n]
    return fa

def phi(n):
    ans = 1
    fa = factor(n)
    for p, m in fa:
        ans *= (p ** m - p ** (m - 1))
    return ans

mx = -1
v = None
for n in range(2, 1_000_000+1):
    ph = phi(n)
    r = n / ph
    if r > mx:
        mx = r
        v = n
print(mx, v)