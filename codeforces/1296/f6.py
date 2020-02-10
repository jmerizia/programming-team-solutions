import random
random.seed(1)
N, M = 5000, 5000
print(N)
lines = ["{} {}".format(i, i+1) for i in range(1, N)]
random.shuffle(lines)
for line in lines:
    print(line)
print(M)
for i in range(M): print(1, N, 1)
