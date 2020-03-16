import random
random.seed(0)
n, m = int(1e5), int(2e5)
print(n, m)
V = list(range(1, n+1))
for i in range(m): print(random.choice(V), random.choice(V))
