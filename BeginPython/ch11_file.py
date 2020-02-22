'''
    ch11_file.py
    
    2018/06/07
'''


f = open('somefile.txt', 'w')
f.write('Hello, ')
f.write('World!')
f.close()

f = open('somefile.txt', 'r')
print f.read(4)
print f.read()


import sys
text = sys.stdin.read()
words = text.split()
wordcount = len(words)
print 'Wordcount: ', wordcount


def process(string):
    print 'Processing: ',string

import fileinput
for line in fileinput.input(f):
    process(line)    
    


