# using_with.py
# 2017/09/16

with open('poem.txt') as f:
    for line in f:
        print(line, end='')
