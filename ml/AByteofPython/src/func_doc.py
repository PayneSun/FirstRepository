# func_doc.py
# 2017/09/12

def printMax(x, y):
    '''Print the maximum of two numbers.
    The two values must be integers.
    :param x: x
    :param y: y
    :return: a message of maximum'''
    x = int(x)
    y = int(y)

    if x > y:
        print(x, 'is maximum')
    else:
        print(y, 'is maximum')

printMax(3, 5)
print(printMax.__doc__)
