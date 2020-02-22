'''
    ch07_class.py
    
    2018/05/08
'''


from random import choice
from _pyio import __metaclass__

__metaclass__ = type

x = choice(['Hello, world!', [1, 2, 3, 'e', 'e']])
print x.count('e')
  
  
def length_message(x):
    print "The length of", repr(x), "is", len(x)

length_message('Fnord')


class Person:
    
    def setName(self, name):
        self.name = name
    
    def getName(self):
        return self.name
    
    def greet(self):
        print "Hello, world! I'm %s." % self.name
        
foo = Person()
bar = Person()
foo.setName("Sun")
bar.setName("Wang")


class Secretive:

    def __inaccessible(self):
        print "Bet you can't see me..."
        
    def accessible(self):
        print "The secrete message is:"
        self.__inaccessible()
        
# s = Secretive()
# s.accessible()


class Filter:
    def init(self):
        self.blocked = []
    def filter(self, sequence):
        return [x for x in sequence if x not in self.blocked]
    
class SPAMFilter(Filter):
    def init(self):
        self.blocked = ['SPAM']
        
sf = SPAMFilter()
sf.init()
print sf.filter(['SPAM', 'eggs', 'bacon'])

