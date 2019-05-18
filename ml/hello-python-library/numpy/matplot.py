"""
    matplotlib.py
    2019/5/18
"""

import numpy as np
import matplotlib.pyplot as plt

# x = np.arange(1,11)
# y = 2 * x + 5
x = np.arange(0, 4 * np.pi, 0.1)
y1 = np.sin(x)
y2 = np.cos(x)

# plt.subplot(2,1,1)
# plt.title('Sin')
plt.plot(x,y1, '-c')

# plt.subplot(2,1,2)
# plt.title('Cos')
plt.plot(x,y2, '-b')

plt.show()