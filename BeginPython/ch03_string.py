'''
    ch03_string.py
    
    2018/05/04
'''


from math import pi
from string import Template
from string import maketrans
from boto.mws.response import Price


# print "Pi with three decimals: %.3f" % pi

# s = Template('$x, glorious $x!')
# print s.substitute(x='slum')

# print 'Price of eggs: $%d' % 42
# print 'Hexadecimal price of eggs: %x' % 42
# 
# print '%.*s' % (5, 'Guido van Rossum')


# code-3.1-start-------------------------
# width = input('Please enter width: ')
# 
# price_width = 10
# item_width = width - price_width
# 
# header_format = '%-*s%*s'
# format = '%-*s%*.2f'
# 
# print '=' * width
# print header_format % (item_width, 'Item', price_width, 'Price')
# print '-' * width
# 
# print format % (item_width, 'Apple', price_width, 0.4)
# print format % (item_width, 'Pears', price_width, 0.5)
# print format % (item_width, 'Cantaloupes', price_width, 1.92)
# print format % (item_width, 'Dried Apricots (16 oz.)', price_width, 8)
# print format % (item_width, 'Prunes (4 lbs).Apple', price_width, 12)
# print '=' * width
# code-3.1-end---------------------------

# dirs = '', 'usr', 'bin', 'env'
# print '/'.join(dirs)

table = maketrans('cs', 'kz')
print 'this is an incredible test'.translate(table)


