def f(n, m):
    return n*(n+1)//2*m*(m+1)//2

# def bs_m(goal, n):
#     # given n, return best m
#     l = 1
#     r = 2*goal
#     for _ in range(30):
#         m = (l + r) // 2
#         if f(n, m) <= goal:
#             l = m
#         else:
#             r = m
#     # return l
#     if abs(f(n,l)-goal) < abs(f(n,r)-goal):
#         return l
#     else:
#         return r

# def bs_n_m(goal):
#     l = 1
#     r = 2*goal
#     for _ in range(30):
#         n = (l + r) // 2
#         m = bs_m(goal, n)
#         print(n, m)
#         if f(n, m) <= goal:
#             l = n
#         else:
#             r = n
#     # return l, bs_m(goal, l)
#     if abs(f(l,bs_m(goal,l))-goal) < abs(f(r,bs_m(goal,r))-goal):
#         return (l,bs_m(goal,l))
#     else:
#         return (r,bs_m(goal,r))


# n, m = bs_n_m(2_000_000)
# print(n, m, f(n, m))
# quit()

goal = 2_000_000
best = None
best_d = 9999999
for n in range(1000):
    for m in range(1000):
        c = f(n, m)
        if c > goal:
            break
        d = abs(goal - c)
        if d < best_d:
            best_d = d
            best = (n, m, c)
n, m, c = best
print(n, m, c, 'ans =', n*m)
