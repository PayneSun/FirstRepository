# using_file.py
# 2017/6/12


file = open('D:\\test.txt', 'r')
while True:
    line = file.readline()
    if len(line) == 0:
        break
    output = line + ' NewBee'
    print(output, end='')
file.close()
