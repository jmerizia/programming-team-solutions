words = []
with open('words.txt', 'r') as f:
    for word in f.read().split(','):
        word = word.strip("\"")
        words.append(word)

print('Generating squares')
squares_distinct_digits = []
for i in range(int(1e7)):
    s = i*i
    ss = str(s)
    if len(ss) == len(set(ss)):
        squares_distinct_digits.append(s)
squares_of_length = dict()
for l in range(1, 15):
    squares_of_length[l] = set(s for s in squares_distinct_digits if len(str(s)) == l)
print('Done generating squares')

def is_anagram(a, b):
    return ''.join(sorted(a)) == ''.join(sorted(b))

def check(a, b, assign):
    mp = dict()
    for c, k in zip(a, assign):
        if c in mp:
            if mp[c] != k:
                return False
        else:
            mp[c] = k
    num_b = ''
    for c in b:
        num_b += mp[c]
    if num_b[0] == '0':
        return False
    return int(num_b) in squares_of_length[len(a)]

answers = []
for i in range(len(words)):
    for j in range(len(words)):
        a = words[i]
        b = words[j]
        if a != b and is_anagram(a, b):
            l = len(str(a))
            for square in squares_of_length[l]:
                if check(a, b, str(square)):
                    answers.append((a, b, square))

print(answers)
print(max(square for a, b, square in answers))