"""
    binary_op.py
    2019/5/16
"""

import numpy as np


a = 35
print(bin(a))

b1 = 15
b2 = 25
print(np.bitwise_and(b1,b2))
print(np.bitwise_or(b1,b2))

c = 12
print(np.invert(c))
print(np.binary_repr(c))
print(np.left_shift(c, 3))
print(np.right_shift(c, 2))
