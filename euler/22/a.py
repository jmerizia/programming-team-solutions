alph = ' ABCDEFGHIJKLMNOPQRSTUVWXYZ'

with open('names.txt', 'r') as f:
    names = f.readline().replace('"', '').split(',')
    names = [name.strip() for name in names]
    names = list(sorted(names))

def value(name):
    return sum(alph.index(c) for c in name) * (names.index(name) + 1)

print(sum(value(name) for name in names))
