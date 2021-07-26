ord = list('23456789TJQKA')

def cmp_num(a, b):
    assert a in ord and b in ord, (a, b)
    return ord.index(a) < ord.index(b)

def srt(h):
    return list(sorted(h, key=lambda x: ord.index(x[0])))

def consec(h):
    indices = list(sorted(ord.index(c[0]) for c in h))
    assert all(i != -1 for i in indices), (h, indices)
    for i in range(len(indices) - 1):
        if indices[i] + 1 != indices[i+1]:
            return False
    return max(indices) + 2

def same_suit(h):
    s = None
    for c in h:
        if s is None:
            s = c[1]
        else:
            if c[1] != s:
                return False
    return True

def four_kind(h):
    nums = [c[0] for c in h]
    u = set(nums)
    if len(u) > 2:
        return False
    for a in u:
        if nums.count(a) == 4:
            return ord.count(a) + 2
    return False

def three_kind(h):
    nums = [c[0] for c in h]
    u = set(nums)
    for a in u:
        if nums.count(a) == 3:
            return ord.index(a) + 2
    return False

def pairs(h):
    # get the pairs
    nums = [c[0] for c in h]
    u = set(nums)
    prs = []
    for a in u:
        if nums.count(a) == 2:
            prs.append(ord.index(a) + 2)
    return prs

def singles(h):
    # get all single cards
    nums = [c[0] for c in h]
    u = set(nums)
    sgs = []
    for a in u:
        if nums.count(a) == 1:
            sgs.append(ord.index(a) + 2)
    return sgs

def rank_of_hand(h):
    oooo = int(1e8)
    ooo = int(1e6)
    oo = int(1e4)
    o = int(1e2)
    h = srt(h)
    if h[0][0] == 'T' and consec(h) and same_suit(h): # royal flush
        return 10 * oooo
    elif consec(h) and same_suit(h): # straight flush
        return 9 * oooo + consec(h) * ooo
    elif four_kind(h): # four of kind
        return 8 * oooo + four_kind(h) * ooo
    elif three_kind(h) and len(pairs(h)) == 1: # full house
        return 7 * oooo + three_kind(h) * ooo + pairs(h)[0] * oo
    elif len(set(c[1] for c in h)) == 1: # flush
        return 6 * oooo
    elif consec(h): # straight
        return 5 * oooo + consec(h) * ooo
    elif three_kind(h): # three kind
        sgs = list(sorted(singles(h)))
        assert len(sgs) == 2
        return 4 * oooo + three_kind(h) * ooo + sgs[1] * oo + sgs[0] * o
    elif len(pairs(h)) == 2: # two pair
        sgs = singles(h)
        assert len(sgs) == 1
        return 3 * oooo + max(pairs(h)) * ooo + min(pairs(h)) * oo + sgs[0] * o
    elif len(pairs(h)): # pair
        sgs = list(sorted(singles(h)))
        assert len(sgs) == 3
        return 2 * oooo + pairs(h)[0] * ooo + sgs[2] * oo + sgs[1] * o + sgs[0]
    else:
        return max(ord.index(c[0]) + 2 for c in h)

def cmp_hands(a, b):
    # does a win?
    ra = rank_of_hand(a)
    rb = rank_of_hand(b)
    if ra == rb and ra != -1:
        print('ambiguous:', ra, rb)
    # print(ra, rb)
    return ra > rb

ans = 0
with open('poker.txt', 'r') as f:
    for line in f:
        hands = line.split()
        a = hands[:5]
        b = hands[5:]
        if cmp_hands(a, b):
            ans += 1
print(ans)

# examples = [
#     [ '5H 5C 6S 7S KD', '2C 3S 8S 8D TD' ],
#     [ '5D 8C 9S JS AC', '2C 5C 7D 8S QH' ],
#     [ '2D 9C AS AH AC', '3D 6D 7D TD QD' ],
#     [ '4D 6S 9H QH QC', '3D 6D 7H QD QS' ],
#     [ '2H 2D 4C 4D 4S', '3C 3D 3S 9S 9D' ],
# ]

# for a, b in examples:
#     print(cmp_hands(a.split(), b.split()))
