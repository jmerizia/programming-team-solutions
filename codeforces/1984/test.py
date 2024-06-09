def is_large(k):
    for d in str(k):
        d = int(d)
        if d < 5:
            return False
    return True

large = [i for i in range(100) if is_large(i) and len(str(i)) == 2]
possible = set()
for i in large:
    for j in large:
        possible.add(i + j)

for i in range(55 + 55, 99 + 99 + 1):
    if i not in possible:
        print(i)

print(420 in possible)
