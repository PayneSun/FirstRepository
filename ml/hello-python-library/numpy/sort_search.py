"""
    sort_search.py
    2019/5/17
"""

import numpy as np

a = np.floor(100 * np.random.random(9).reshape(3,3))
# print(a)
# print(np.sort(a, axis=0))

b = np.dtype([('name', 'S10'), ('age', int)])
c = np.array([('raju', 21),('anil', 25),('ravi', 17)], dtype=b)
# print(np.sort(c, order='name'))

d = np.floor(100 * np.random.random(9))
print(d)
print(np.argsort(d))
