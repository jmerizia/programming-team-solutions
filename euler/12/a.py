import math

def num_divisors(n):
    ans = 0
    for i in range(1, int(math.sqrt(n))+1):
        if n % i == 0:
            if n // i == i:
                ans += 1
            else:
                ans += 2
    return ans

i = 0
t = 0
for j in range(int(1e6)):
    i += 1
    t += i
    if num_divisors(t) >= 500:
        print(t)
        break
