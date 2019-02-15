n = 100000
m = 100000
k = 100000

with open('4.in', 'w') as f:
    f.write('{} {} {}\n'.format(n, m, k))
    for i in range(1, k+1):
        f.write("{} ".format(i))
    f.write('\n')
    for i in range(1, n):
        f.write('{} {} {}\n'.format(i, i+1, i))
