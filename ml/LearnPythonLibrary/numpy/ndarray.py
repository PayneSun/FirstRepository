

import numpy as np


a = np.array([1,2,3])
# print(a)

b = np.array([[1,2],[3,4]])
# print(b)

c = np.array([1,2,3,4,5],ndmin=2)
# print(c)

d = np.array([1,2,3], dtype=complex)
# print(d)

e = np.arange(24).reshape(2, 3, 4)
# print(e)
# print(e.shape)
# print(e.ndim)
# print(e.size)

f = np.empty([3, 3], dtype=int)
# print(f)

g = np.zeros(10, dtype=np.int)
# print(g)

h = np.ones([2, 5], dtype=np.float)
# print(h)

i1 = [1, 2, 3]
i2 = np.asarray(i1)
# print(i2)
i3 = (4, 5, 6)
i4 = np.asarray(i3)
# print(i4)

j1 = np.arange(1, 10, 2)
# print(j1)
j2 = np.linspace(1, 10, 5, dtype=int)
# print(j2)

k1 = np.logspace(1.0, 2.0, num=10)
# print(k1)
k2 = np.logspace(0, 9, 10, base=2)
# print(k2)

l1 = np.arange(10)
l2 = slice(2,7,2)
# print(l1[l2])

m = np.arange(9).reshape(3,3)
# print(m)
# print(m[...,1])
# print(m[...,1:])
# print(m[2,...])

n = np.arange(16).reshape(4,4)
# print(n)
# print(n[n > 10])

o = np.arange(32).reshape((8,4))
# print(o[[4,2,1,7]])

p = np.arange(6).reshape(2,3)
# for x in np.nditer(p):
#     print(x, end=', ')
# for x in np.nditer(p, order='F'):
#     print(x, end=', ')
# for x in np.nditer(p, order='C'):
#     print(x, end=', ')
# for x in np.nditer(p, op_flags=['readwrite']):
#     x[...] = 2 * x
# print(p)

q = np.arange(9).reshape(3,3)
# for ele in q.flat:
#     print(ele)
# print(q.flatten())
# print(q.flatten(order='F'))

r = np.arange(8).reshape(2,4)
# print(r.T)
# print(r.transpose())

s1 = np.arange(4).reshape(2,2)
s2 = np.arange(4).reshape(2,2)
# print(np.concatenate((s1,s2)))
# print(np.concatenate((s1,s2), axis=1))

t = np.arange(9)
# print(np.split(t, 3))

u1 = np.floor(10 * np.random.random((2,6)))
# print(np.hsplit(u1, 3))
u2 = np.arange(16).reshape(4,4)
# print(np.vsplit(u2,2))

v1 = np.arange(10).reshape(2,5)
# print(np.append(v1, np.arange(5)))
# print(np.append(v1, np.arange(10,15).reshape(1,5),axis=0))

w = np.arange(5).reshape(1,5)
# print(w)
w = np.append(w, w.reshape(1,5), axis=0)
# print(w)
# print(np.unique(w))


