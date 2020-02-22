'''
    ch06_function.py
    
    2018/05/07
'''

 
def fibs(num):
    result = [0, 1]
    for i in range(num -2):
        result.append(result[-2] + result[-1])
    print result
    
    
def square(x):
    'Calculate the square of the number x.'
    return x*x

# print square.__doc__
# help(square)


def hello_4(name, greeting='Hello', punctuation='!'):
    print '%s, %s%s' % (greeting, name, punctuation)
    

def print_params(*params):
    print params
    
# print_params(1,2,3)


def print_params_4(x, y, z=3, *pospar, **keypar):
    print x,y,z
    print pospar
    print keypar
    
# print_params_4(1, 2, 3, 5, 6, 7, foo=1, bar=2)


def combine(parameter):
    print parameter + globals()['parameter']
# parameter = 'berry'
# combine('Shrub')


def multiplier(factor):
    def multiplyByFactor(number):
        print factor * number
    return multiplyByFactor


def search(sequence, number, lower, upper):
    if lower == upper:
        assert number == sequence[upper]
        return upper
    else:
        middle = (lower + upper) // 2
        if number > sequence[middle]:
            return search(sequence, number, middle + 1, upper)
        else:
            return search(sequence, number, lower, middle)
        

numbers = [72, 101, 108, 44, 32, 119, 111, 114, 100, 33]
# print reduce(lambda x,y: x+y, numbers)
print sum(numbers)