import matplotlib.pyplot as plt
import seaborn as sns
import numpy as np

l = [[3, 0, 3, 3, 2, 3, 3, 2, 2, 3, 3, 2, 3, 0],
     [0, 0, 3, 0, 3, 0, 3, 3, 2, 2, 2, 2, 2, 3]]
a = np.array(l)

sns.heatmap(l, square=True, cmap='Blues', linewidths=0.5, linecolor='grey')
plt.show()
