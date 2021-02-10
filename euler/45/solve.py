n = 100000

T = [i*(i+1)//2 for i in range(1, n)]
Ps = set(i*(3*i-1)//2 for i in range(1, n))
Hs = set(i*(2*i-1) for i in range(1, n))

for i, k in enumerate(T):
    if k in Ps and k in Hs:
        print(i+1, k)
