n = 50
print(n)
print(1, 1)
print(n, n)
for i in range(1, n+1):
    if i == 1 or i == n:
        print('1'*n)
    else:
        print('0'*n)
