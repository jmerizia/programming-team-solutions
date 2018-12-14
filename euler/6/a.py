n = 100
a = sum(range(1, n+1)) ** 2
b = sum(x*x for x in range(1, n+1))
print(a - b)
