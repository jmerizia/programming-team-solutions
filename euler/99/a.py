from math import log10
with open('base_exp.txt', 'r') as f:
    v = [map(int, line.split(',')) for line in f]
    v = [(b*log10(a), idx+1) for idx, (a, b) in enumerate(v)]
    # print(v)
    print(list(sorted(v))[-1][1])