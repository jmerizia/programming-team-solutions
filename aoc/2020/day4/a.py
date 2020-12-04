with open('in2', 'r') as f:
    passports = f.read().split('\n\n')
    passports = [p.split() for p in passports]

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
    for field in req:
        if field not in fields:
            return 0
    return 1

print(len(passports))
print(sum(check(p) for p in passports))

