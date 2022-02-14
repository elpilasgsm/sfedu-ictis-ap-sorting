import numpy as np
import matplotlib.pyplot as plt

data = np.genfromtxt("./Selection.csv", delimiter=",", names=["x", "y"])
plt.plot(data['x'], data['y'])
plt.savefig("./chart.png")