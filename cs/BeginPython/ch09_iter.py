'''
    ch09_iter.py
    
    2018/05/09
'''
from __builtin__ import TypeError

__metaclass__ = type

class FooBar:
    def __init__(self):
        self.somevar = 42
        
# fb = FooBar()
# print fb.somevar


class Bird:
    def __init__(self):
        self.hungry = True
    def eat(self):
        if self.hungry:
            print 'Aaaah...'
            self.hungry = False
        else:
            print 'No, thanks!'
            
class SongBird(Bird):
    def __init__(self):
#         Bird.__init__(self)
        super(SongBird, self).__init__()
        self.sound = 'Squawk!'
    def sing(self):
        print self.sound

# sb = SongBird()
# sb.sing()
# sb.eat()
# sb.eat()


def checkIndex(key):
    if not isinstance(key, (int, long)):
        raise TypeError
    if key < 0:
        raise IndexError

    
class ArithmeticSequence:
    def __init__(self, start=0, step=1):
        self.start = start
        self.step = step
        self.changed = {}
        
    def __getitem(self,key):
        checkIndex(key)
        try:
            return self.changed[key]
        except KeyError:
            return self.start + key*self.step
        
    def __setitem__(self, key, value):
        checkIndex(key)
        self.changed[key] = value
        
        
class CounterList(list):
    def __init__(self, *args):
        super(CounterList,self).__init__(*args)
        self.counter = 0
    
    def __getitem__(self,index):
        self.counter += 1
        return super(CounterList, self).__getitem__(index)
    
    
class Rectangle:
    def __init__(self):
        self.width = 0
        self.height = 0
    def setSize(self, size):
        self.width, self.height = size
    def getSize(self):
        self.width, self.height    
    size = property(getSize, setSize)
    

class MyClass:
    @staticmethod
    def smeth():
        print 'This is a static method'
    
    @classmethod
    def cmeth(cls):
        print 'This is a class method of',cls
        
        
class Fibs:
    def __init__(self):
        self.a = 0
        self.b = 1
    def next(self):
        self.a, self.b = self.b, self.a + self.b
        return self.a
    def __iter__(self):
        return self
    
# fibs = Fibs()
# for f in fibs:
#     if f > 1000:
#         print f
#         break
        

class TestIterator:
    value = 0
    def next(self):
        self.value += 1
        if self.value > 10:
            raise StopIteration
        return self.value
    def __iter__(self):
        return self
    

def flatten(nested):
    try:
        try:
            nested + ''
        except TypeError:
            pass
        else:
            raise TypeError
        for sublist in nested:
            for element in flatten(sublist):
                yield element
    except TypeError:
        yield element            
nested = [[1, 2], [3, 4], [5]]


def conflict(state, nextX):
    nextY = len(state)
    for i in range(nextY):
        if abs(state[i]-nextX) in (0, nextY-i):
            return True
    return False


def queens(num=8, state=()):
    for pos in range(num):
        if not conflict(state, pos):
            if len(state) == num-1:
                yield (pos,)
            else:
                for result in queens(num, state+(pos,)):
                    yield (pos,) + result
                
print list(queens(4))
print len(list(queens(8)))                
    
    