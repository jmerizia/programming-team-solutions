import random
n=int(2e5)
k=int(2e5)
print(n, k)
print(*[random.randint(1, int(k)) for _ in range(n)])
print(*reversed(range(1, k+1)))
