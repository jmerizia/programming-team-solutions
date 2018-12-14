n = int(2e6)
m = int(2.2e6)

is_prime = [True for _ in range(m+1)]
is_prime[0] = False
is_prime[1] = False
k = 2

while k * k <= m:
    if is_prime[k]:
        for i in range(k*2, m+1, k):
            is_prime[i] = False
    k += 1

primes = [i for i, b in enumerate(is_prime) if b]

ans = sum(p for p in primes if p < n)
print(ans)
