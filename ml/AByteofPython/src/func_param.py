# func_param.py
# 2017/09/12

def printMax(a, b):
    if a > b:
        print(a, 'is maximum')
    elif a == b:
        print(a, 'is equal to', b)
    else:
        print(b, 'is maximum')

printMax(3, 4)

x = 5
y = 7
printMax(x, y)
