"""
    linear_algebra.py
    2019/5/17
"""

import numpy as np

a = np.array([[1,2],[3,4]])
b = np.array([[5,6],[7,8]])

# 对应元素相乘
print(a * b)

# 乘积
print(np.dot(a,b))

# 点积
# print(np.vdot(a,b))

# 内积
c = np.array(np.arange(5))
d = np.array(np.arange(5))
# print(np.inner(c, d))

# 矩阵相乘
print(np.matmul(a,b))
