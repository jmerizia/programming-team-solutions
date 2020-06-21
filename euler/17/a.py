words = {
    1:  'one',
    2:  'two',
    3:  'three',
    4:  'four',
    5:  'five',
    6:  'six',
    7:  'seven',
    8:  'eight',
    9:  'nine',
    10: 'ten',
    11: 'eleven',
    12: 'twelve',
    13: 'thirteen',
    14: 'fourteen',
    15: 'fifteen',
    16: 'sixteen',
    17: 'seventeen',
    18: 'eighteen',
    19: 'nineteen',
    20: 'twenty',
    30: 'thirty',
    40: 'forty',
    50: 'fifty',
    60: 'sixty',
    70: 'seventy',
    80: 'eighty',
    90: 'ninety',
    1000: 'one thousand'
}

for n in range(20, 100):
    if n % 10 != 0:
        a = (n // 10) * 10
        b = n % 10
        words[n] = words[a] + '-' + words[b]

for n in range(100, 1000):
    a = n // 100
    b = n % 100
    words[n] = words[a] + ' hundred' + (' and ' + words[b] if b != 0 else '')

def clean(word):
    return ''.join(l for l in word if l.isalpha())

print(len(''.join(clean(word) for k, word in words.items())))

