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
# print(d)
# print(np.argsort(d))

e = np.floor(50 * np.random.random(9).reshape(3,3))
# print(e)
# print(np.argmax(e))
# print(np.argmin(e))
# print(np.argmax(e[0,...]))
# print(np.argmin(e[...,1]))
# print(np.nonzero(e))

f = np.arange(9).reshape(3,3)
cond = np.mod(f,2) == 0
print(np.extract(cond,f))