"""
    io.py
    2019/5/18
"""

import numpy as np


a = np.random.random(9)
# print(a)

np.save('outfile.npy', a)
b = np.load('outfile.npy')
# print(b)

c = np.random.random(4).reshape(2,2)
d = np.random.random(9).reshape(3,3)
e = np.random.random(16).reshape(4,4)
np.savez('multivar.npz', arr4=c, arr9=d, arr16=e)
f = np.load('multivar.npz')
# print(f.files)
# print(f['arr4'])

g = np.arange(0, 10, 0.5).reshape(4,-1)
np.savetxt('out.txt', g, fmt='%d', delimiter=',')
h = np.loadtxt('out.txt', delimiter=',')
print(h)
