n = 6

m = int(5e6)
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

primes_set = set(primes)

print("done generating primes")

mem = {}

def num_divisors(n):
    if n in mem:
        return mem[n]
    ans = -1
    if n == 1:
        ans = 0
    elif n in primes_set:
        ans = 1
    else:
        for prime in primes:
            if n % prime == 0:
                ans = 1 + num_divisors(n // prime)
                break
    if ans == -1:
        print("not enough primes generated!")
    mem[n] = ans
    print(n, ans)
    return ans

print(num_divisors(8) + 2)
quit()

i = 1
t = 1
k = num_divisors(t) + 1
while k < n:
    i += 1
    t += i
    k = num_divisors(t) + 1
    print("triangle number:", t, "divisors:", k)

print(t)
