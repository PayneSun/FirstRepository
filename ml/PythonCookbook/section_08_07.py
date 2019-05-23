"""
    调用父类方法
    section_08_07.py
"""


class Base:
    def __init__(self):
        print('Base')


class A(Base):
    def __init__(self):
        super().__init__()
        print('A')


class B(Base):
    def __init__(self):
        super().__init__()
        print('B')


class C(A,B):
    def __init__(self):
        super().__init__()
        print('C')

c = C()
