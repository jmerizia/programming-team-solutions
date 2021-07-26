ans = -1
for a in range(100):
    for b in range(100):
        ans = max(ans, sum(map(int, list(str(a**b)))))
print(ans)