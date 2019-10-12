from itertools import permutations

cubes = set(i**3 for i in range(10000))

for perm_s in permutations('1728'):
    perm = int(''.join(perm_s))
    if perm in cubes:
        print(perm)
