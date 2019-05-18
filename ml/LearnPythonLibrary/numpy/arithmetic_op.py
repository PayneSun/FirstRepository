"""
    arithmetic_op.py
    2019/5/16
"""

import numpy as np


a = np.arange(9, dtype=np.float).reshape(3,3)
b = np.random.random(9).reshape(3,3)

# print(np.add(a,b))

# print(np.subtract(a,b))

# print(np.multiply(a,b))

# print(np.divide(a,b))

# print(np.reciprocal(b))

# print(b)
# print(np.power(b,3))

c = np.arange(1,10)
d = np.arange(6,15)
print(np.mod(d,c))