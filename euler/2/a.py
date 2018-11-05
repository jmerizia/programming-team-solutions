fib = [1, 2, 3]
s = 0
while fib[0] <= 4e6:
    fib[2] = fib[0] + fib[1]
    fib[0] = fib[1]
    fib[1] = fib[2]
    if fib[0] % 2 == 0:
        s += fib[0]
print(s)
