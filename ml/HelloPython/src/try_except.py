# try_except.py
# 2017/06/13


try:
    text = input('Enter text: ')
except EOFError:
    print('Why did you do an EOF on me?')
except KeyboardInterrupt:
    print('You cancelled the operation.')
else:
    print('You entered {0}'.format(text))
