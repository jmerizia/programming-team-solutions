a = 4
b = 6
for x in range(100):
    print(x, 'y' if (x%a)%b == (x%b)%a else '')
