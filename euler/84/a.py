# just simulate it (monte carlo)
# (MCTS is easier, but it's probably possible with something value iteration or something from the MDP/RL world)
import random


chest = ["go", "jail"] + [None] * 14
chance = ["go", "jail", "c1", "e3", "h2", "r1", "nextr", "nextr", "nextu", "back3"] + [None] * 6

board = ["go", "a1", "cc1", "a2", "t1", "r1", "b1", "ch1", "b2", "b3", "jail",
    "c1", "u1", "c2", "c3", "r2", "d1", "cc2", "d2", "d3", "fp", "e1",
    "ch2", "e2", "e3", "r3", "f1", "f2", "u2", "f3", "g2j",
    "g1", "g2", "cc3", "g3", "r4", "ch3", "h1", "t2", "h2"]

assert len(board) == 40

index_of = {name: board.index(name) for name in board}

def roll2(sides=6):
    return random.randint(1, sides), random.randint(1, sides)

def advance(cur, amt):
    return (cur + amt) % len(board)

def regress(cur, amt):
    cur -= amt
    if cur < 0:
        cur += len(board)
    return cur

def fmtpercent(x):
    return f'{x*100:0.2f}%'

def nextr(cur):
    cur = (cur + 1) % len(board)  # always move 1
    while board[cur] not in ['r1', 'r2', 'r3', 'r4']:
        cur = (cur + 1) % len(board)
    return cur

def nextu(cur):
    cur = (cur + 1) % len(board)  # always move 1
    while board[cur] not in ['u1', 'u2']:
        cur = (cur + 1) % len(board)
    return cur

print('This will take some time...')
rounds = 1
round_length = 20_000_000
start = 0
dice_sides = 4
count = {idx: 0 for idx in range(len(board))}
for _ in range(rounds):
    count[start] += 1
    cur = start
    doubles = 0
    for i in range(round_length):
        a, b = roll2(dice_sides)
        if a == b:
            doubles += 1
        else:
            doubles = 0
        if doubles == 3:
            doubles = 0
            cur = index_of['jail']
        else:
            cur = advance(cur, a + b)
            if board[cur] in ['cc1', 'cc2', 'cc3']:
                card = random.choice(chest)
                if card is not None:
                    cur = index_of[card]
                else:
                    assert card is None
            elif board[cur] in ['ch1', 'ch2', 'ch3']:
                card = random.choice(chance)
                if card in ['go', 'jail', 'c1', 'e3', 'h2', 'r1']:
                    cur = index_of[card]
                elif card == 'nextr':
                    cur = nextr(cur)
                    assert board[cur].startswith('r')
                elif card == 'nextu':
                    cur = nextu(cur)
                    assert board[cur].startswith('u')
                elif card == 'back3':
                    cur = regress(cur, 3)
                else:
                    assert card is None
            elif board[cur] == 'g2j':
                cur = index_of['jail']
            else:
                # just chill here until next round
                pass
        count[cur] += 1

total = sum(count.values())
results = list(sorted(count.items(), key=lambda x: x[1]))
ans = 0
for idx, freq in results:
    name = board[idx]
    print(f'{name} ({idx:02}):', fmtpercent(freq / total))

for idx, freq in list(reversed(results))[:3]:
    ans *= 100
    ans += idx

print('ans =', ans)