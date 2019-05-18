# exception_class.py
# 2017/06/13


class ShortInputException(Exception):
    def __init__(self, length, at_least):
        Exception.__init__(self)
        self.length = length
        self.at_least = at_least


try:
    text = input('Enter something: ')
    if len(text) < 3:
        raise ShortInputException(len(text), 3)
except EOFError:
    print('Why did you do an EOF on me')
except ShortInputException as ex:
    print('ShortInputException The input was {0} long, '
          'excepted at least {1}'.format(ex.length, ex.at_least))
else:
    print('No exception was raised.')
