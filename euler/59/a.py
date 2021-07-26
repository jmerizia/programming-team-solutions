import itertools

alph = 'abcdefghijklmnopqrstuvwxyz'

common_words = [
    'the', 'be', 'to', 'of', 'and', 'a', 'in',
    'that', 'have', 'it', 'for', 'not', 'on',
    'with', 'he', 'as', 'you', 'do', 'at', 'this',
    'but', 'his', 'by', 'from', 'they', 'we', 'say',
    'her', 'she', 'or', 'an', 'will', 'my', 'one', 'all',
    'would', 'there', 'their', 'what', 'so', 'up', 'out',
    'if', 'about', 'who', 'get',
]

def dec(ct, key):
    pt = ''
    for i in range(len(ct)):
        pt += chr(ct[i] ^ key[i % 3])
    return pt

def score(text):
    return len([word for word in common_words if word in text])


with open('cipher.txt', 'r') as f:
    ct = list(map(int, f.read().split(',')))

mx = -1
mx_key = None
for key in itertools.product(map(ord, alph), repeat=3):
    s = score(dec(ct, key))
    if s > mx:
        mx = s
        mx_key = key

pt = dec(ct, mx_key)
print(mx_key, pt)
print(sum(ord(c) for c in pt))
