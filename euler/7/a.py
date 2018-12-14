n = 10001
m = int(1e6)
is_prime = [True for _ in range(m+1)]
is_prime[0] = False
is_prime[1] = False
k = 2
while k * k <= m:
    if is_prime[k]:
        for i in range(2 * k, m+1, k):
            is_prime[i] = False
    k += 1

primes = [idx for idx, x in enumerate(is_prime) if x]
print(primes[n-1])
