# coding=utf-8
'''
    split.py

    2018/4/17
'''

import sys


# analyze arguments
if (len(sys.argv) != 4) and (sys.argv[1] != '-e' or sys.argv[1] != '-c'):
    print 'Argument error!\n','Usage: python-file -[e|c] input-file output-file'
    exit()


# split text
with open(sys.argv[2], 'r') as inf, open(sys.argv[3],'w') as ouf:
    """
        split sentence and store sub into list.
    """
    num_of_line = 1
    sub_phrase_list = []
    for line in inf:
        stat_line = []
        if sys.argv[1] == '-e':
            sub_phrase_list = line.strip().split(',')  # English text
        else:
            sub_phrase_list = line.strip().split('，')  # Chinese text
        total_length = len(sub_phrase_list)

        # outline = str(num_of_line) + ':' + str(total_length) + '\n'
        outline = ''

        stat_line.append(num_of_line)
        stat_line.append(total_length)

        # print line,'\n',total_length

        len_of_sub_phrase = []
        for i in range(total_length):
            len_of_sub_phrase.append(len(sub_phrase_list[i].strip().split()))
            # if i < total_length - 1:
            #     if sys.argv[1] == '-e':
            #         sub_phrase_list[i] += (',/' + str(i) + '\n')
            #     else:
            #         sub_phrase_list[i] += ('，/' + str(i) + '\n')
            # else:
            #     sub_phrase_list[i] += ('/' + str(i) + '\n')
            outline += sub_phrase_list[i] + '\n'
        # print ''
        ouf.write(outline)
        num_of_line += 1
        stat_line.append(len_of_sub_phrase)
        print stat_line


# str_list = ['I', 'love', 'you']
# print ','.join(str_list)