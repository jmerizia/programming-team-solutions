def check(a, b):
    return list(sorted(str(a))) == list(sorted(str(b)))


for i in range(1, int(1e6)):
    if check(i, 2*i) and check(i, 3*i) and check(i, 4*i) and check(i, 5*i) and check(i, 6*i):
        print(i)