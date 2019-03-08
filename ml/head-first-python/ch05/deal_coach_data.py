'''
    deal_coach_data.py
    2017-12-02
'''


with open('james.txt', 'r') as james_str:
    data = james_str.readline()
    james = data.strip().split(',')
    # print(sorted(james))

with open('julie.txt', 'r') as julie_str:
    data = julie_str.readline()
    julie = data.strip().split(',')
    # print(sorted(julie))

with open('mikey.txt', 'r') as mikey_str:
    data = mikey_str.readline()
    mikey = data.strip().split(',')
    # print(sorted(mikey))

with open('sarah.txt', 'r') as sarah_str:
    data = sarah_str.readline()
    sarah = data.strip().split(',')
    # print(sorted(sarah))


def sanitize(time_string):
    if '-' in time_string:
        splitter = '-'
    elif ':' in time_string:
        splitter = ':'
    else:
        return time_string

    (mins, secs) = time_string.split(splitter)

    return (mins + '.' + secs)


new_james = [sanitize(each_t) for each_t in james]
new_julie = [sanitize(each_t) for each_t in julie]
new_mikey = [sanitize(each_t) for each_t in mikey]
new_sarah = [sanitize(each_t) for each_t in sarah]

print(sorted(new_james))
print(sorted(new_julie))
print(sorted(new_mikey))
print(sorted(new_sarah))
