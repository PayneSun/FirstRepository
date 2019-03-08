# age = 25
# name = 'sunpeng'
# print('{0} is {1} years old'.format(name, age))
# print('Why is {0} playing with that python?'.format(name))

# i = 5
# print(i)
# i = i + 1
# print(i)
# s = '''This is a multi-line string.
# This is the second line.'''
# print(s)

# s = 'This is a string. \
# This continues the string.'
# print(s)

# length = 5
# breadth = 2
# area = length * breadth
# print('area is',area)
# print('perimeter is',2*(length+breadth))

# number = 32
# running = True
#
# while running:
#     guess = int(input('Enter an integer: '))
#
#     if guess == number:
#         print('Congratulations, you guessed it.')
#         print('(but you do not win any prizes!)')
#     elif guess < number:
#         print('No, it is a little higher than that')
#     else:
#         print('No, it is a little lower than that')
# else:
#     print('the while loop is over.')
# print('Done')

# for i in range(1,5):
#     print(i)
# else:
#     print('The for loop is over')

# while True:
#     s = input('Enter something: ')
#     if s == 'quit':
#         break
#     if len(s) < 3:
#         print('Too small')
#     else:
#         print('Tnput is of sufficient length')
#         continue

# def sayHello():
#     print('Hello World!')
#
# sayHello()

# def printMax(a, b):
#     if a > b:
#         print(a, 'is maximun')
#     elif a == b:
#         print(a, 'is equal to', b)
#     else:
#         print(b, 'is maximun')
# printMax(3, 5)
# x = 6
# y = 9
# printMax(y,x)

# x = 50
# def func():
#     global x
#     print('x is',x)
#     x = 2
#     print('Changed global x to',x)
# func()
# print('Value of x is',x)

# def func_outer():
#     x = 2
#     print('x is', x)
#
#     def func_iner():
#         nonlocal x
#         x = 5
#
#     func_iner()
#     print('Changed local x to',x)
#
# func_outer()


# def say(message, times = 2):
#     print(message * times)
#
# say('hello')
# say('World', 5)

# def total(initial = 5, *numbers, **keywords):
#     count = initial
#     for number in numbers:
#         count += number
#     for key in keywords:
#         count += keywords[key]
#     return count
#
# print(total(10, 1, 2, 3, vege = 50, frut = 100))

# def printMax(x, y):
#     '''Prints the maximum of two numbers.
#     The two values must be integers.'''
#     x = int(x)
#     y = int(y)
#
#     if x > y:
#         print(x, 'is maximum')
#     else:
#         print(y, 'is maximum')
#
# printMax(3, 5)
# print(printMax.__doc__)

# chapter 9

# import sys
#
# print('The command line arguments are:')
# for i in sys.argv:
#     print(i)
#
# print('\nThe PYTHONPATH is', sys.path, '\n')

# import os
# print(os.getcwd())

# import sys
# dir(sys)
# dir()

# ab = {'swaroop'   : 'swaroop@swarooph.com',
#       'larry'     : 'larry@wall.org',
#       'matsumoto' : 'mats@rubylang.org',
#       'spammer'   : 'spammer@hotmail.com'
#       }
# print("swaroop's address is", ab['swaroop'])
#
# del ab['spammer']
#
# print('\nThere are {0} contacts in the address-book\n'.format(len(ab)))
#
# for name, address in ab.items():
#     print('Contact {0} at {1}'.format(name, address))
#
# ab['guido'] = 'guido@python.org'
# if 'guido' in ab:
#     print("guido's address is", ab['guido'])


# shoplist = ['apple', 'mango', 'carrot', 'banana']
# name = 'swarrop'
#
# print('Item 0 is', shoplist[0])
# print('Item -1 is', shoplist[-1])
# print('Character 0 is', name[0])
#
# print('Item 1 to 3 is', shoplist[1:3])
# print('Item 2 to end is', shoplist[2:])
# print('Item start to end is', shoplist[:])
#
# print('Characters 1 to 3 is', name[1:3])
# print('Characters 2 to end is', name[2:])
# print('Characters start to end is', name[:])

# name = 'Swaroop'
#
# if name.startswith('Swa'):
#     print('Yes, the string starts with "Swa"')
#
# if 'a' in name:
#     print('Yes, it contains the string "a"')
#
# if name.find('war') != -1:
#     print('Yes, it contains the string "war"')
#
# delimiter = '_*_'
# mylist = ['Brazil', 'Russia', 'India', 'China']
# print(delimiter.join(mylist))

# chapter 12
# class Person:
#     def __init__(self, name):
#         self.name = name
#     def sayHi(self):
#         print('Hello, my name is', self.name)
#
# p = Person('Swaroop')
# p.sayHi()

# class Robot:
#     population = 0
#
#     def __init__(self, name):
#         self.name = name
#         print('(Initialize{0})'.format(self.name))
#         Robot.population += 1
#
#     def __del__(self):
#         print('{0} is being destroyed!'.format(self.name))
#         Robot.population -= 1
#         if Robot.population == 0:
#             print('{0} was the last one.'.format(self.name))
#         else:
#             print('There are still {0:d} robots working'.format(Robot.population))
#
#     def sayHi(self):
#         print('Greetings, my master call me {0}'.format(self.name))
#
#     def howMany():
#         print('We have {0:d} robots.'.format(Robot.population))
#     howMany = staticmethod(howMany)
#
# droid1 = Robot('R2-D2')
# droid1.sayHi()
# Robot.howMany()
#
# droid2 = Robot('C-3P0')
# droid2.sayHi()
# Robot.howMany()
#
# print('\nRobots can do some work here.\n')
# print("Robots have finished their work. So let's destroy them.")
#
# del droid1
# del droid2
#
# Robot.howMany()

# with open("poem.txt") as f:
#     for line in f:
#         print(line, end='')

flag = True
if flag: print('Yes')