import numpy as np
import matplotlib.pyplot as plt

Bubble = np.genfromtxt("./Bubble.csv", delimiter=",", names=["x", "y"])
Insertion = np.genfromtxt("./Insertion.csv", delimiter=",", names=["x", "y"])
Selection = np.genfromtxt("./Selection.csv", delimiter=",", names=["x", "y"])
Quick = np.genfromtxt("./Quick.csv", delimiter=",", names=["x", "y"])

plt.title("Compare sorting algorithms")
plt.xlabel("Array size, items")
plt.ylabel("Time, microseconds")

plt.plot(Bubble['x'], Bubble['y'])
plt.legend("Bubble Sort")

plt.plot(Insertion['x'], Insertion['y'])
plt.legend("Insertion Sort")

plt.plot(Selection['x'], Selection['y'])
plt.legend("Selection Sort")

plt.plot(Quick['x'], Quick['y'])
plt.legend("Quick Sort")

plt.savefig("./chart.png", dpi=200)
