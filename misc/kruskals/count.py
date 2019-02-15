freqs = {}
for i in range(1, 127):
    freqs[chr(i)] = 0

with open('Kruskals.cpp', 'r') as f:
    for line in f:
        for char in line:
            freqs[char] += 1

for char, freq in sorted(freqs.items(), key=lambda x: x[1]):
    if char == '\n':
        print('\\n', freq)
    else:
        print(char, freq)
