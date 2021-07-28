# using generating functions

def expand(a, b):
    assert len(a) == len(b)
    vals = []
    for i in range(len(a)):
        for j in range(len(b)):
            vals.append((i+j, a[i]*b[j]))
    vals = list(sorted(vals))
    out = [vals[0][1]]
    for i in range(1, len(vals)):
        if vals[i-1][0] == vals[i][0]:
            out[-1] += vals[i][1]
        else:
            out.append(vals[i][1])
    return tuple(out)

print(expand( (3, 4), (1, 2) ))