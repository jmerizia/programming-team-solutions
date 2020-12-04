original_code = list(map(int, input().split(',')))
goal = 19690720

def test(n, v):
    code = original_code[:]
    code[1] = n
    code[2] = v

    i = 0
    while True:
        ins = code[i]
        if ins == 99:
            break
        if ins == 1:
            a = code[i+1]
            b = code[i+2]
            d = code[i+3]
            code[d] = code[a]+code[b]
            i += 4
        if ins == 2:
            a = code[i+1]
            b = code[i+2]
            d = code[i+3]
            code[d] = code[a]*code[b]
            i += 4
    return code[0]

for n in range(100):
    for v in range(100):
        if goal == test(n, v):
            print(n, v)
            print(n*100+v)
