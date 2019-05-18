# lambda.py
# 3.1.2017


def make_repeater(n):
    return lambda s: s*n


twice = make_repeater(2)

print(twice('word'))
print(twice(5))
