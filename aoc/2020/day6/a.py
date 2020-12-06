with open('in1', 'r') as f:
    lines = f.read().split('\n\n')

ans = 0
for l in lines:
    ress = l.split()
    u = set(list(''.join(ress)))
    for c in u:
        if all(c in res for res in ress):
            ans += 1

print(ans)
