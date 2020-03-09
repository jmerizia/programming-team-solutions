# 5 5: (5 slots, use 4 distinct #s)
#  i=0:
#   4 _ _ _ _
#   (none)
#  i=1:
#   _ 4 _ _ _
#   1 4 3 2 1
#   2 4 3 2 1
#   3 4 3 2 1
#   (3)
#  i=2:
#   _ _ 4 _ _
#   1 2 4 3 2
#   1 2 4 3 1
#   1 3 4 2 1
#   1 3 4 3 2
#   2 3 4 3 1
#   2 3 4 2 1
#
# Note: cannot reuse the largest #

# 6 6: (6 slots, use 5 distinct #s)
#  i=0:
#   5 _ _ _ _ _
#   (none)
#  i=1:
#   _ 5 _ _ _ _
#   4 5 4 3 2 1
#   3 5 4 3 2 1
#   2 5 4 3 2 1
#   1 5 4 3 2 1
#  i=2:
#   _ _ 5 _ _ _
#   1 2 5 4 3 2
#   1 2 5 4 3 1
#   1 3 5 4 2 1
#   1 3 5 4 3 2
#   1 4 5 4 3 2
#   1 4 5 3 2 1
#   2 3 5 4 3 1
#   2 3 5 4 2 1
#   2 4 5 4 3 1
#   2 4 5 3 2 1
#   3 4 5 4 2 1
#   3 4 5 3 2 1

# 7 7: (7 slots, use 6 distinct #s)
#  i=0:
#   6 _ _ _ _ _ _
#   (none)
#  i=1:
#   _ 6 _ _ _ _ _
#   5 6 5 4 3 2 1
#   4 6 5 4 3 2 1
#   3 6 5 4 3 2 1
#   2 6 5 4 3 2 1
#   1 6 5 4 3 2 1
#   (5 choose 1) = 5
#  i=2:
#   _ _ 6 _ _ _ _
#   1 2 6 5 4 3 2 (repeat first)
#   1 2 6 5 4 3 1 (repeat second)
#   1 3 6 _ _ _ _
#   1 4 6 _ _ _ _
#   1 5 6 _ _ _ _
#   2 3 6 _ _ _ _
#   2 4 6 _ _ _ _
#   2 5 6 _ _ _ _
#   3 4 6 _ _ _ _
#   3 5 6 _ _ _ _
#   4 5 6 _ _ _ _
#   (5 choose 2)*2 = 20
#  i=3:
#   _ _ _ 6 _ _ _
#   1 2 3 6 5 4 3 (repeat first)
#   1 2 3 6 5 4 2 (repeat second)
#   1 2 3 6 5 4 1 (repeat third)
#   1 2 4 6 5 4 3
#   1 2 4 6 5 3 2
#   1 2 4 6 5 3 1
#   1 2 5 6 _ _ _
#   1 3 4 6 _ _ _
#   1 3 5 6 _ _ _
#   1 4 5 6 _ _ _
#   2 3 4 6 _ _ _
#   2 3 5 6 _ _ _
#   2 4 5 6 _ _ _
#   3 4 5 6 _ _ _
#   (5 choose 3)*3 = 30
#  i=4:
#   _ _ _ _ 6 _ _
#   (5 choose 4)*4 = 20
#  i=5:
#   _ _ _ _ _ 6 _
#   (5 choose 5)*5 = 5
#  i=6:
#   _ _ _ _ _ + 6
#   (none)
# ans = (0 + 5 + 20 + 30 + 20 + 5 + 0)*(7 choose 6)

from itertools import product

ans = []
for p in product([1, 2, 3, 4, 5, 6, 7], repeat=7):
    a, b, c, d, e, f, g = p
    if (a < b < c < d < e < f < g) or \
            (a < b < c < d < e < f and f > g) or \
            (a < b < c < d < e and e > f > g) or \
            (a < b < c < d and d > e > f > g) or \
            (a < b < c and c > d > e > f > g) or \
            (a < b and b > c > d > e > f > g) or \
            (a > b > c > d > e > f > g):
        if len(set(p)) == len(p) - 1:
            ans.append(p)

print(len(ans))
