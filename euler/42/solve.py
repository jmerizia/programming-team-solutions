with open('words.txt', 'r') as f:
    words = f.read().split(',')
    words = [word.strip('"') for word in words]

tris = set(i*(i+1)//2 for i in range(5000))

ans = 0
for word in words:
    val = 0
    for c in word.lower():
        val += ord(c)-97+1
    if val in tris:
        ans += 1


print(len(words), ans)
