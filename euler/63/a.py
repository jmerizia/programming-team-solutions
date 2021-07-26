# n = 2
# p = [len(str(i ** n)) for i in range(1, 11)]
# print(p)

# ans = []
# for n in range(10000):
#     c = 0
#     larger = 0
#     for i in range(1, 11):
#         k = len(str(i ** n))
#         if k == n:
#             c += 1
#         if k > n:
#             larger += 1
#     assert larger > 0
#     if c > 0:
#         ans.append(n)
#     if n % 100 == 0:
#         print(n, larger, ans)
# print(ans, len(ans))


nth_powers = set()
for i in range(int(1e6)):
    for n in range(10):
        nth_powers.add(i ** n)
