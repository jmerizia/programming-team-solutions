code = list(map(int, input().split(',')))
code[1] = 12
code[2] = 2

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
print(code[0])
