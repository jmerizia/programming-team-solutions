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

ab = list(sorted(n for n in range(1, 28123) if sd(n) > n))

s = set()
for a in ab:
    for b in ab:
        if a+b > 28123:
            break
        s.add(a+b)

ans = 0
for i in range(28123):
    if i not in s:
        ans += i

print(ans)
