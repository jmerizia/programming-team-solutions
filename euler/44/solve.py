n = 500

P = [i*(3*i-1)//2 for i in range(1, 10*n)]
Ps = set(P)

ans = 10000000
for i in range(len(P)):
    for j in range(i+1, len(P)):
        a = P[i]
        b = P[j]
        d = abs(a-b)
        s = a+b
        if d in Ps and s in Ps:
            if d < ans:
                ans = d
                print(ans)

print(ans)
