"""
    stat_func.py
    2019/5/16
"""

import numpy as np


a = np.random.random(9).reshape(3,3)
# print(a)

print(np.amin(a, axis=0)) #每列中的最小值

print(np.amax(a, axis=1)) #每行中的最大值

tmp1 = np.ptp(a, axis=0)
tmp2 = np.amax(a, axis=0) - np.amin(a, axis=0)
print(np.subtract(tmp1,tmp2))

print(np.median(a, axis=0))