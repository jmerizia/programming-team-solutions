import math
n = 600851475143
m = math.ceil(math.sqrt(n)) + 10
is_prime = [True for _ in range(m)]
is_prime[0] = False
is_prime[1] = False
k = 2
while k * k <= m: # O(m log m log log m)
    if is_prime[k]:
        for i in range(k*2, m, k):
            is_prime[i] = False
    k += 1

primes = [idx for idx, x in enumerate(is_prime) if x]

prime_factors = []
while n > 1:
    for prime in primes: # O(m log n log k)
        if n % prime == 0:
            prime_factors.append(prime)
            n /= prime

print(prime_factors)
