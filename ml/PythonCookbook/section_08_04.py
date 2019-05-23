"""
    创建大量对象时节省内存方法
    section_08_04.py
"""


class Date:
    __slots__ = ['year', 'month', 'day']
    def __init__(self, year, month, day):
        self.year = year
        self.month = month
        self.day = day

