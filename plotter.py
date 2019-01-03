import sys
import numpy as np
import matplotlib.pyplot as plt

if len(sys.argv) == 1:
    print("Please pass a file as input.")
    exit(-1)

with open(sys.argv[1]) as f:
    data = [int(value) for value in f.read().strip().split("\n")]

plt.plot(data)
plt.show()