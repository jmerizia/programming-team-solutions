#1:10:01
from itertools import combinations

a = map(int, input().split())
k = int(input())
b = [x for x in a if x != 0]
ans = 0
for c in combinations(b, k):
    prod = 1
    for x in c:
        prod *= x
    ans += prod
print(ans)
