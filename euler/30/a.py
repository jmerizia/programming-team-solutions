
m = int(5e5)
s = set()
for n in range(2, m):
    if n == sum(i**5 for i in map(int, str(n))):
        s.add(n)

print(sum(s))
