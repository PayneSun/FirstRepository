"""
    创建大量对象时节省内存方法
    section_08_05.py
"""


class A:
    def __init__(self):
        self._internal = 0
        self.public = 1

    def public_method(self):
        '''
        A public method
        '''
        pass

    def _internal_method(self):
        pass


class B:
    def __init__(self):
        self.__private = 0

    def __private_method(self):
        pass

    def public_method(self):
        pass


class C(B):
    def __init__(self):
        super.__init__()
        self.__private = 1 # does not override B.__private

    # does not override B.__privatre_method()
    def __private_method(self):
        pass

