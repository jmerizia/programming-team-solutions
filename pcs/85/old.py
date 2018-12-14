operation_strings = [" + ", " * ", " / ", " - "]
answers = {}

for o in operation_strings:
    for oo in operation_strings:
        for ooo in operation_strings:
            s = "4" + "4".join([o,oo,ooo]) + "4"
            ans = eval(s)
            s += " = %d" % ans
            answers[ans] = s

n = int(raw_input())
for _ in xrange(n):
    print(answers.get(int(raw_input()), "no solution"))
