import matplotlib.pyplot as plt
import numpy as np


M = [0, 1, 6, 35, 204, 1189, 6930, 40391, 235416, 1372105, 7997214, 46611179]
X = list(range(1, len(M)+1))
plt.plot(X, np.log(M))
plt.show()