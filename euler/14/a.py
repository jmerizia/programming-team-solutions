mem = {}

def col(n):
    if n in mem:
        return mem[n]
    if n == 1:
        ans = 1
    elif n % 2 == 0:
        ans = col(n/2) + 1
    else:
        ans = col(3 * n + 1) + 1
    mem[n] = ans
    return ans

ans = -1
l = -1
for i in range(1, int(1e6)+1):
    t = col(i)
    if t > l:
        l = t
        ans = i

print(ans)
