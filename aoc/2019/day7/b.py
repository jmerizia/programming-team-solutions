# 
original_code = list(map(int, input().split(',')))

def CPU(setting, thrust):
    code = original_code[:]
    i = 0
    j = 0

    while True:
        j = 0
        ins = code[i]%100
        A = (code[i]//100)%10
        B = (code[i]//1000)%10
        C = (code[i]//10000)%10
        if ins == 99:
            break
        if ins in [1, 2, 7, 8]:
            a = code[i+1]
            b = code[i+2]
            c = code[i+3] # not imm
            aa = a if A else code[a]
            bb = b if B else code[b]
            if ins == 1:
                code[c] = aa + bb
            if ins == 2:
                code[c] = aa * bb
            if ins == 7:
                code[c] = 1 if aa < bb else 0
            if ins == 8:
                code[c] = 1 if aa == bb else 0
            i += 4

        elif ins == 3:
            a = code[i+1] # not imm
            code[a] = setting if j == 0 else thrust
            j += 1
            i += 2

        elif ins == 4:
            a = code[i+1]
            aa = a if A else code[a]
            i += 2
            yield aa

        elif ins in [5, 6]:
            a = code[i+1]
            b = code[i+2]
            aa = a if A else code[a]
            bb = b if B else code[b]
            if ins == 5:
                if aa != 0:
                    i = bb
                else:
                    i += 3
            if ins == 6:
                if aa == 0:
                    i = bb
                else:
                    i += 3

        else:
            raise 'oops'

    yield None


def amps(seq):
    x = 0
    tot = 0
    idx = 0
    def thrust():
        while True:
            yield x
    cpus = [CPU(0, thrust)]*5
    while True:
        for idx, cpu in enumerate(cpus):
            t = seq[idx]
            idx += 1
            done, x = ([t, x])
            print(done, x)
        if done:
            break
        tot += x
    return tot

from itertools import permutations

ans = 0
for seqa in permutations(range(5)):
    for seqb in permutations(range(5, 10)):
        seq = seqa + seqb*3
        ans = max(ans, amps(seq))

print(ans)
