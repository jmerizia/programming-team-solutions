original_code = list(map(int, input().split(',')))

def run(inp):
    code = original_code[:]
    output = []

    i = 0
    j = 0
    while True:
        ins = code[i]%100
        A = (code[i]//100)%10
        B = (code[i]//1000)%10
        C = (code[i]//10000)%10
        if ins == 99:
            break
        if ins == 1:
            a = code[i+1]
            b = code[i+2]
            c = code[i+3]
            aa = a if A else code[a]
            bb = b if B else code[b]
            code[c] = aa + bb
            i += 4
        elif ins == 2:
            a = code[i+1]
            b = code[i+2]
            c = code[i+3]
            aa = a if A else code[a]
            bb = b if B else code[b]
            code[c] = aa * bb
            i += 4
        elif ins == 3:
            a = code[i+1] # not imm
            code[a] = inp[j]
            j += 1
            i += 2
        elif ins == 4:
            a = code[i+1]
            aa = a if A else code[a]
            output.append(aa)
            i += 2
        else:
            raise 'oops'

    return output

print(run([1]))
