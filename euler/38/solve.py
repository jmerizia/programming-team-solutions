
pds = []
for i in range(100_000):
    s = ''
    j = 1
    while len(s) < 9:
        s += str(i*j)
        j += 1
    if len(s) == 9 and ''.join(sorted(s)) == '123456789':
        pds.append(int(s))

print(len(pds))
print(max(pds))
