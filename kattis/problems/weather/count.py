from math import factorial as f

def nck(n, k):
    return f(n)//f(k)//f(n-k)

n = 20
tot = 0
tim = 0
for i in range(0, n+1):
    for j in range(i, n+1):
        for k in range(j, n+1):
            a = i
            b = j-i
            c = k-j
            d = n-k
            tot += f(n)//f(a)//f(b)//f(c)//f(d)
            tim += 1

print(tot, '(total reports counted)')
print(4**20, '(total reports true)')
print(tim, '(loops)')
