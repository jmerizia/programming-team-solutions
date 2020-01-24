def is_prime(k):
    i = 2
    while i*i <= k:
        if k % i == 0:
            return False
        i += 1
    return True

def is_odd_comp(k):
    if k % 2 == 0 or is_prime(k):
        return False
    return True

primes = []
for k in range(2, int(1e4)):
    if is_prime(k):
        primes.append(k)

print('largest prime:', primes[-1])
print('total primes:', len(primes))

odd_comps = []
for k in range(33, int(1e4)):
    if is_odd_comp(k):
        odd_comps.append(k)

print('largest odd composite:', odd_comps[-1])
print('total odd composite:', len(odd_comps))

for odd_comp in odd_comps:
    worked = False
    for prime in primes:
        if odd_comp > prime:
            v = (odd_comp - prime) // 2
            if int(v**0.5) == v**0.5:
                worked = True
                break

    if not worked:
        print('Sorry Goldbach, {} does not work!'.format(odd_comp))
        break

