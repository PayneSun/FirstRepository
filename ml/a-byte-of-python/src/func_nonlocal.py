# func_nonlocal.py
# 2017/09/12

def func_outer():
    x = 2
    print('x is', x)

    def func_inner():
        nonlocal x
        x = 5

    func_inner()
    print('Changed local x to', x)

func_outer()
