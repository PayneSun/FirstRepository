'''
    ch14_network_programming.py
    
    2018/06/12
'''


import re
from urllib import urlopen


webpage = urlopen('http://www.python.org')
text = webpage.read()

m = re.search('<a href="([^"]+)" .*?>about</a>', text, re.IGNORECASE)

print m.group(1)