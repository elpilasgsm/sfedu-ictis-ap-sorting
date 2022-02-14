import numpy as np
import matplotlib.pyplot as plt

Bubble = np.genfromtxt("./Bubble.csv", delimiter=",", names=["x", "y"])
Insertion = np.genfromtxt("./Insertion.csv", delimiter=",", names=["x", "y"])
Selection = np.genfromtxt("./Selection.csv", delimiter=",", names=["x", "y"])
Quick = np.genfromtxt("./Quick.csv", delimiter=",", names=["x", "y"])

plt.title("Compare sorting algorithms")
plt.xlabel("Array size, items")
plt.ylabel("Time, microseconds")

plt.plot(Bubble['x'], Bubble['y'], label="Bubble Sort")
plt.plot(Insertion['x'], Insertion['y'], label="Insertion Sort")
plt.plot(Selection['x'], Selection['y'], label="Selection Sort")
plt.plot(Quick['x'], Quick['y'], label="Quick Sort")

plt.legend(loc="upper left")

plt.savefig("./chart.png", dpi=200)