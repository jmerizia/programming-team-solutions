s = ''

i = 1
while len(s) < 1_000_000:
    s += str(i)
    i += 1

print(len(s))
ans = 1
i = 1
while i < 10_000_000:
    print(i, int(s[i-1]))
    ans *= int(s[i-1])
    i *= 10
print(ans)

