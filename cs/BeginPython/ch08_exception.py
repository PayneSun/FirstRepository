'''
    ch08_exception.py
    
    2018/05/09
'''
from asn1crypto.x509 import NameType


# try:
#     x = input('Enter the first number: ')
#     y = input('Enter the second number: ')
#     print x / y
# except (ZeroDivisionError, TypeError),e:
#     print e
    

# class MuffledCalculator:
#     muffled = False
#     def calc(self, expr):
#         try:
#             return eval(expr)
#         except ZeroDivisionError:
#             if self.muffled:
#                 print 'Division by zero is illegal!'
#             else:
#                 raise
#             
# mc = MuffledCalculator()
# # mc.calc('10/0')
# mc.muffled = True
# mc.calc('10/0')


try:
    1/0
except NameType:
    print "Unknown variable"
else:
    print "That went well!"
finally:
    print "Cleaning up."
