#too slow!
squares = set(k*k for k in range(1000))

for p in range(1000):
    sols = 0
    for i in range(p):
        for j in range(p):
            k = i*i + j*j
            if k in squares and i + j + k == p:
                sols += 1
    print(p, sols)

