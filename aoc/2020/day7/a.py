from collections import defaultdict
adj = defaultdict(lambda: [])
with open('in1', 'r') as f:
    for line in f:
        words = line.split()
        a = words[0] + ' ' + words[1]
        rest = words[4:]
        for i in range(0, len(rest), 4):
            idx = int(rest[i]) if rest[i] != 'no' else 0
            b = rest[i+1] + ' ' + rest[i+2]
            adj[a].append((b, idx))

vis = set()

def below(bag):
    tot = 1
    if bag not in vis:
        #vis.add(bag)
        for (v, idx) in adj[bag]:
            tot += idx * below(v)
    return tot

#print(len(vis)-1)
print(below('shiny gold')-1)
