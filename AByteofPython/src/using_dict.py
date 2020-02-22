# using_dict.py
# 2017/09/14

ab = {'Swaroop': 'swa@py.com',
      'Larry': 'lar@py.com',
      'Matsumoto': 'mat@py.com',
      'Spammer': 'spammer@py.com'
      }

print("Swaroop's address is", ab['Swaroop'])

del ab['Spammer']

print('\nThere are {0} contacts in the address-book\n'.format(len(ab)))
for name, address in ab.items():
    print('Contact {0} at {1}'.format(name, address))

ab['Guido'] = 'guido@py.org'
if 'Guido' in ab:
    print("\nGuido address is", ab['Guido'])
