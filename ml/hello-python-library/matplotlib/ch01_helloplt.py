#

import matplotlib.pyplot as plt

x = [1,2,3]
y = [5,7,4]

x2 = [1,2,3]
y2 = [10,14,12]

# plt.plot(x,y,label='first line')
# plt.plot(x2,y2,label='second line')
#
# plt.xlabel('Plot Number')
# plt.ylabel('Important Var')
# plt.title('Interesting Graph\nCheck it out')
#
# plt.legend()
# plt.show()


xdata = range(1,50)
ydata = [0.21, 0.32, 0.38, 0.45, 0.51, 0.52, 0.53, 0.61, 0.62, 0.66, 0.67, 0.71, 0.72, 0.73, 0.75, 0.76, 0.76, 0.78, 0.79, 0.81, 0.84, 0.87, 0.88, 0.89, 0.89, 0.91, 0.92, 0.92, 0.93, 0.93, 0.93, 0.93, 0.93, 0.93, 0.93, 0.93, 0.94, 0.94, 0.94, 0.94, 0.94, 0.94, 0.94, 0.94, 0.94, 0.94, 0.94, 0.94, 0.94]

plt.subplot(131)
plt.plot(xdata[0:10], ydata[0:10], 'r')
plt.axis([1, 10, 0, 1])
plt.xlabel('Top N')
plt.ylabel('Accuracy')
plt.title('Align Curve')
# plt.legend()
plt.grid(True)

plt.subplot(132)
plt.plot(xdata[0:20], ydata[0:20], 'r')
plt.axis([1, 20, 0, 1])
plt.xlabel('Top N')
plt.ylabel('Accuracy')
plt.title('Align Curve')
# plt.legend()
plt.grid(True)

plt.subplot(133)
plt.plot(xdata[0:50], ydata[0:50], 'r')
plt.axis([1, 50, 0, 1])
plt.xlabel('Top N')
plt.ylabel('Accuracy')
plt.title('Align Curve')
# plt.legend()
plt.grid(True)

plt.show()

