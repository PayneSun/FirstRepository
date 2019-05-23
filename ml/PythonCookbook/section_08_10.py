"""
    使用延迟计算属性
    section_08_10.py
"""

import math


class lazyproperty:
    def __init__(self, func):
        self.func = func

    def __get__(self, instance, cls):
        if instance is None:
            return self
        else:
            value = self.func(instance)
            setattr(instance, self.func.__name__, value)
            return value


class Circle:
    def __init__(self, radius):
        self.radius = radius

    @lazyproperty
    def area(self):
        print('Computing area')
        return math.pi * self.radius ** 2

    @lazyproperty
    def perimeter(self):
        print('Computing perimeter')
        return 2 * math.pi * self.radius

    def __delete__(self, instance):
        del instance.__dict__[self.name]


c = Circle(4.0)

print(c.radius)
print(c.area)
print(c.perimeter)

print(c.radius)
print(c.area)
print(c.perimeter)
