#filename: total.py


def total(initial=5, *numbers, **keywords):
    '''
what the fuck? fuck python!
    '''
    count = initial
    for number in numbers:
        count += number
    for key in keywords:
        count += keywords[key]
    return count

print(total.__doc__)