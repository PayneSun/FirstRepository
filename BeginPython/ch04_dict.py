'''
    ch04_dict.py
    
    2018/05/05
'''

from copy import deepcopy

phonebook = {'Alice': '2341', 'Beth': '9102', 'Cecil': '3258'}
# print "Cecil's phone number is %(Cecil)s." % phonebook
print phonebook.keys()
print phonebook.values()
print phonebook.items()

# d = dict(name='Gumby', age=42)
# print d

# code-4.1-start--------------------------------------
# people = {
#     'Alice': {'phone': '2341', 'addr': 'Foo drive 23'}, 
#     'Beth': {'phone': '9102', 'addr': 'Bar street 42'},
#     'Ceil': {'phone': '3158', 'addr': 'Baz avenue 90'}
#     }
# labels = {
#     'phone': 'phone number',
#     'addr': 'address'
#     }
#  
# name = raw_input('Name: ')
# request = raw_input('Phone number (p) or address (a)?')
# key = request
# if request == 'p':
#     key = 'phone'
# if request == 'a':
#     key = 'addr'
# 
# person = people.get(name, {})
# label = labels.get(key, key)     
# result = person.get(key, 'not available')
# print "%s's %s is %s." % (name, label, result)    
# code-4.1-end----------------------------------------

# d = {}
# d['name'] = ['Alfred', 'Bertrand']
# c = d.copy()
# dc = deepcopy(d)
# d['name'].append('Clive')
# print c
# print dc

# print dict.fromkeys(['name', 'age'], 'unkown')

