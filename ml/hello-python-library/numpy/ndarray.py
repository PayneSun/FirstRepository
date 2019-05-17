"""
    ndarray.py
    2019/5/16
"""

import numpy as np


# a = np.array([1,2,3])
# b = np.array([[1,2],[3,4]])
# c = np.array([1,2,3,4,5],ndmin=2)
# d = np.array([1,2,3], dtype=complex)
#
# print(a)
# print(b)
# print(c)
# print(d)

# print(a.shape)
# print(a.ndim)
# print(a.size)


# dt_int32 = np.dtype(np.int32)
# dt_i4 = np.dtype(np.int32)
#
# print(dt_int32)
# print(dt_i4)


# a = np.array([[1,2],[3,4]])
# b = np.arange(4).reshape((2,2))
# c = np.dot(a,b)
# print(c)
# print('np.sum(c,axis=0)',np.sum(c,axis=0))
# print('np.sum(c,axis=1)',np.sum(c,axis=1))
# print('np.min(c,axis=0)',np.min(c,axis=0))
# print('np.min(c,axis=1)',np.min(c,axis=1))
# print('np.max(c,axis=0)',np.max(c,axis=0))
# print('np.max(c,axis=1)',np.max(c,axis=1))
# print('np.argmin(c)',np.argmin(c))
# print('np.mean(c)',np.mean(c))

# A = np.arange(3,15).reshape((3,4))
# print(A)
# for ele in A.flat:
#     print(ele)
# for ele in A.T:
#     print(ele)


# A = np.array([1,1,1])
# B = np.array([2,2,2])
# C = np.vstack((A,B))
# D = np.hstack((A,B))
# print(C)
# print(D)


A = np.arange(12).reshape((3,4))
print(np.split(A,3,axis=0))
print(np.array_split(A,3,axis=1))
