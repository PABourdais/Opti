#!/usr/bin/python

import sys, argparse, re
import math
import logging
import numpy as np
import matplotlib.pyplot as plt

x, y = np.loadtxt("tri-fusion-complexite.txt", delimiter='\t', unpack=True)
y1 = (x[0]*np.log(x[0])*1)/y[0]
plt.plot(x, (x*np.log(x))/y1, label="theorique")
plt.plot(x, y, label="experimental")

plt.xlabel("nombre d'octets (n)")
plt.ylabel("temps moyen (s)")
plt.legend()

plt.show()


