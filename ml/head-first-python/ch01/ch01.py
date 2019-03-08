'''
    Head First Python
    ch01/ch01.py
    2017/11/21
'''


movies = ["The Holy Grail", 1975, "Terry Jones & Terry Gilliam", 91,
          ["Graham Chapman", ["Michael Palin", "John Cleese",
                              "Terry Gilliam", "Eric Idle", "Terry Jones"]]]

for item1 in movies:
    if isinstance(item1, list):
        for item2 in item1:
            if isinstance(item2, list):
                for item3 in item2:
                    print(item3)
            else:
                print(item2)
    else:
        print(item1)


def print_lol(the_list):
    for each_item in the_list:
        if isinstance(each_item, list):
            print_lol(each_item)
        else:
            print(each_item)

print_lol(movies)
