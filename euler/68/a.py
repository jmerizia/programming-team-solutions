gon = 5

board = [-1] * (gon * 3)
used = set()
if gon == 3:
    same = {
        1: 8, 8: 1,
        2: 4, 4: 2,
        5: 7, 7: 5
    }
elif gon == 5:
    same = {
        1: 14, 14: 1,
        2: 4, 4: 2,
        5: 7, 7: 5,
        8: 10, 10: 8,
        11: 13, 13: 11
    }
tim = 0

def place(n, i):
    board[i] = n
    if i in same:
        board[same[i]] = n

def check():
    s = set()
    for o in range(0, 3 * gon, 3):
        if board[o] != -1 and board[o+1] != -1 and board[o+2] != -1:
            s.add(board[o]+board[o+1]+board[o+2])
    return len(s) in [0, 1]

def find_next_spots(n):
    spots = []
    for i in range(len(board)):
        # can we place n here?
        if board[i] == -1:
            place(n, i)
            ok = check()
            place(-1, i)
            if ok:
                spots.append(i)
    return spots

def uniq(board):
    s = ''
    first = list(sorted(range(0, 3 * gon, 3), key=lambda x: board[x]))[0]
    for o in range(0, 3 * gon, 3):
        s += str(board[(first + o) % (gon * 3)]) + str(board[(first + o + 1) % (gon * 3)]) + str(board[(first + o + 2) % (gon * 3)])
    return s

def bt(n):
    global tim
    tim += 1
    if tim % 100_000 == 0:
        print(tim)

    if n == 0:
        # we know it's valid
        for e in board:
            assert e != -1
        assert check()
        # return {uniq(board.copy())}
        print(tim)
        print(uniq(board))
        quit()

    # ensure inner board cells are synced
    for i in range(len(board)):
        if i in same:
            assert board[i] == board[same[i]]

    poss = set()
    for i in find_next_spots(n):
        place(n, i)
        poss |= bt(n-1)
        place(-1, i)
    return poss

poss = bt(gon * 2)
print(tim)
for b in reversed(sorted(poss)):
    print(b)
