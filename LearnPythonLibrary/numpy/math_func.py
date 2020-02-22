"""
    math_func.py
    2019/5/16
"""

import numpy as np


a = np.arange(0,100,10)
# print(a)
# print(np.sin(a * np.pi / 180))
# print(np.cos(a * np.pi / 180))
# print(np.tan(a * np.pi / 180))

b0 = np.pi / 6
# print(np.degrees(b0))

b1 = np.arctan(1)
# print(np.degrees(b1))

b2 = np.arcsin(0.5)
# print(np.degrees(b2))

b3 = np.arccos(0.5)
# print(np.degrees(b3))

c0 = 7 / 3
print(np.around(c0, 3))
print(np.floor(c0))
print(np.ceil(c0))
