'''
    algin.py

    2018/5/1
'''

list_of_src = []
list_of_tar = []

fsrc = open('data/out.en')
ftar = open('data/out.ch')

is_count = False
line = fsrc.readlines()
for i in range(len(line)):
    if (':' in line[i]) and (len(line[i].strip().split(':')) == 2):
        if line[i].strip().split(':')[0].isdigit() and line[i].strip().split(':')[-1].isdigit():
            (nums, lens) = line[i].strip().split(':')
            nums = int(nums)
            lens = int(lens)
            is_count = True
            print nums,'-',lens,'-',list_of_src
            list_of_src = []
    else:
        list_of_src.append(len(line[i].strip().split()))



