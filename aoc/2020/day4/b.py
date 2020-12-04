with open('in2', 'r') as f:
    passports = f.read().split('\n\n')
    passports = [p.strip().split() for p in passports]

req = [
'byr',
'iyr',
'eyr',
'hgt',
'hcl',
'ecl',
'pid',
]

def check(p):
    fields = set()
    for line in p:
        field = line[:3]
        fields.add(field)
    for r in req:
        if r not in fields:
            return 0

    for line in p:
        k, v = line.split(':')
        if k == 'byr':
            if not (1920 <= int(v) <= 2002):
                return 0
        if k == 'iyr':
            if not (2010 <= int(v) <= 2020):
                return 0
        if k == 'eyr':
            if not (2020 <= int(v) <= 2030):
                return 0
        if k == 'hgt':
            num, unit = v[:-2], v[-2:]
            if unit == 'cm':
                if not (150 <= int(num) <= 193):
                    return 0
            elif unit == 'in':
                if not (59 <= int(num) <= 76):
                    return 0
            else:
                return 0
        if k == 'hcl':
            allow = '0123456789abcdef'
            if len(v) != 7:
                return 0
            if v[0] != '#':
                return 0
            for c in v[1:]:
                if c not in allow:
                    return 0
        if k == 'ecl':
            if v not in 'amb blu brn gry grn hzl oth'.split():
                return 0
        if k == 'pid':
            try:
                int(v)
            except:
                return 0
            if len(v) != 9:
                return 0
    return 1

print(len(passports))
print(sum(check(p) for p in passports))

