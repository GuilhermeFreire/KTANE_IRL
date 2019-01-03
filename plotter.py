import sys
import numpy as np
import matplotlib.pyplot as plt

if len(sys.argv) == 1:
    print("Please pass a file as input.")
    exit(-1)

with open(sys.argv[1]) as f:
    raw_text = f.read()
    if "," not in raw_text:
        data = [int(value) for value in raw_text.strip().split("\n")]
    else:
        data = [[int(value) for value in row.split(", ")] for row in raw_text.strip().split("\n")]

if "," not in raw_text:
    plt.plot(data)
else:
    for wire in zip(*data):
        plt.plot(wire)
plt.show()