# pickling.py
# 2017/06/12


import pickle

shop_list_file = 'shop_list.data'
shop_list = ['apple', 'mango', 'carrot']

f = open(shop_list_file, 'wb')
pickle.dump(shop_list, f)
f.close()

del shop_list

f = open(shop_list_file, 'rb')
stored_list = pickle.load(f)

print(stored_list)
