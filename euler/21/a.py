import math

def sd(n):
    ans = 0
    for i in range(1, int(math.sqrt(n))+1):
        if n % i == 0:
            if i == 1 or n // i == i:
                ans += i
            else:
                ans += i + n // i
    return ans

d = [sd(i) for i in range(30000)]
amicable = set()
for a in range(10000):
    b = d[a]
    if a != b and d[b] == a:
        amicable.add(a)

print(sum(amicable))
