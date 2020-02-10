from matplotlib import pyplot as plt
x = [0, 1, 2, 3, 4, 3, 2, 1]
y = [0, 0, 1, 3, 6, 6, 5, 3]
xx = x[:]
yy = y[:]
for p in x:
    for k in x:
        xx.append(p-k)

for p in y:
    for k in y:
        yy.append(p-k)

fig = plt.figure()
plt.xticks(range(-10, 11))
plt.yticks(range(-10, 11))
plt.xlim([-10, 10])
plt.ylim([-10, 10])
plt.scatter(xx, yy, c="red")
plt.scatter(x, y, c="green")
plt.grid()
plt.show()
