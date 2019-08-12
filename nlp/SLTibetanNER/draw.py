
import numpy as np
import matplotlib.pyplot as plt


x = np.arange(10)
y1 = 10 * np.random.random(10)
y2 = 100 * np.random.random(10)
y3 = 1000 * np.random.random(10)


plt.subplot(131)
plt.xlabel('iter')
plt.ylabel('A')
# plt.axis([0, 10, 0, 10])
plt.xlim(-5, 15)
plt.plot(x, np.sort(y1), 'b')

plt.subplot(132)
plt.xlabel('iter')
plt.ylabel('B')
plt.axis([0, 10, 0, 100])
plt.plot(x, np.sort(y2), 'c')

plt.subplot(133)
plt.xlabel('iter')
plt.ylabel('C')
plt.axis([0, 10, 0, 1000])
plt.plot(x, np.sort(y3), 'g')

plt.show()


# x = '95.88%'
# print(x[:-1])
