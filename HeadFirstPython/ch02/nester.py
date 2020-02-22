'''
    Head First Python
    ch02/nester.py
    2017/11/22
'''


def print_lol(the_list, num_tab=0):
    for each_item in the_list:
        if isinstance(each_item, list):
            print_lol(each_item, num_tab+1)
        else:
            for num in range(num_tab):
                print("\t", end='')
            print(each_item)