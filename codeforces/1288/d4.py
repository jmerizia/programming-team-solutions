import random
N = int(3e5)
M = 8
print(N, M)
for i in range(N):
    print(' '.join([str(random.randint(0, 1000)) for _ in range(8)]))
