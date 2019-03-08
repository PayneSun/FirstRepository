# -*- coding: utf-8 -*-


# sun.peng
# 2018/05/16~


#######################################################################
# 将列表按照拆分成两个子序列并返还所有组合
def subserialize(list_of_phrase, length=2):
    result = []
    if len(list_of_phrase) == 2:
        result.append([[list_of_phrase[0]], [list_of_phrase[1]]])
    else:
        for i in range(1, len(list_of_phrase)):
            result.append([list_of_phrase[0:i], list_of_phrase[i:]])
    return result

# for test -----------
# list_of_phrase = [1, 2, 3, 4, 5, 6, 7]
# list_of_phrase = [1, 2]
# print sum(list_of_phrase)
# print subserialize(list_of_phrase, 2)


#######################################################################
# 在两个子序列组合里选择最佳匹配
def select(list_of_phrase_src, list_of_phrase_tar):
    min_match_i = 0
    min_match_j = 0
    min_match_dist = 1000000  # 最短匹配距离
    min_match_ord = True      # 正序为真逆序为假
    for i in range(len(list_of_phrase_src)):
        for j in range(len(list_of_phrase_tar)):
            dist_p = abs(sum(list_of_phrase_src[i][0]) - sum(list_of_phrase_tar[j][0]))\
                         + abs(sum(list_of_phrase_src[i][1]) - sum(list_of_phrase_tar[j][1]))
            dist_n = abs(sum(list_of_phrase_src[i][0]) - sum(list_of_phrase_tar[j][1])) \
                         + abs(sum(list_of_phrase_src[i][1]) - sum(list_of_phrase_tar[j][0]))
            if dist_n < dist_p:
                if dist_n < min_match_dist:
                    min_match_ord = False
                    min_match_dist = dist_n
                    min_match_i, min_match_j = i, j
            else:
                if dist_p < min_match_dist:
                    min_match_ord = True
                    min_match_dist = dist_p
                    min_match_i, min_match_j = i, j

    return min_match_i,min_match_j,min_match_ord,min_match_dist

# for test -----------
# list_src = [3, 1, 4, 5]
# list_tar = [2, 4, 6, 3, 8]
#
# space_list_src = subserialize(list_src)
# space_list_tar = subserialize(list_tar)
# print space_list_src
# print space_list_tar
#
# print select(space_list_src, space_list_tar)


#######################################################################
def recovery(cfg_file_path, tar_file_path, comma):
    with open(cfg_file_path) as fcfg, open(tar_file_path) as ftar:
        ffof = open('data/output.final', 'w')

        # 从配置文件中获取对齐列表
        cfg_line_list = []
        cfg_line = fcfg.readline()
        while (cfg_line):
            cfg_line_list.append(int(cfg_line.strip()))
            cfg_line = fcfg.readline()
        print len(cfg_line_list),cfg_line_list

        # 根据对齐列表恢复目标文件
        line_num = 0
        tar_line = ftar.readline()
        while(tar_line):
            if line_num in cfg_line_list:
                ffof.write(tar_line.strip())
                tar_line = comma + ftar.readline()  # 中文comma='，'，英文comma=','
                ffof.write(tar_line)
                line_num += 2
            else:
                ffof.write(tar_line)
                line_num += 1
            tar_line = ftar.readline()

# for test -----------
# recovery('data/test.en.cfg', 'data/test.en.tmp', ',')


#######################################################################
with open('data/test.en') as inf_en, open('data/test.ch') as inf_ch:
    '''
        输入的源语言文件  ：data/test.en
        输入的目标语言文件：data/test.ch
    '''
    ftmp = open('data/test.en.tmp', 'w')  # 输入源语言文件经过预处理后的文件
    fcfg = open('data/test.en.cfg', 'w')  # 用于恢复目标语言的对齐的配置文件

    line_num = 0; line_tmp = 0
    src_line = inf_en.readline()
    tar_line = inf_ch.readline()
    while (src_line):
        print src_line.strip()
        print tar_line.strip()

        src_line_list = src_line.split(',')   # 按逗号切分英文句子
        tar_line_list = tar_line.split('，')  # 按逗号切分中文句子

        src_line_len_list = [len(src_line_list[i].strip().split()) for i in range(len(src_line_list))]
        tar_line_len_list = [len(tar_line_list[i].strip().split()) for i in range(len(tar_line_list))]

        # print src_line_list
        print src_line_len_list
        # print tar_line_list
        print tar_line_len_list

        if (len(src_line_list) > 1) and (len(tar_line_list) > 1):
            fcfg.write(str(line_tmp) + '\n')

            # 子句组合对齐
            src_reverse_space = subserialize(src_line_len_list)
            tar_reverse_space = subserialize(tar_line_len_list)
            min_i,min_j,min_order,min_dist = select(src_reverse_space, tar_reverse_space)

            # 被选中的子句组合
            src_min_group = src_reverse_space[min_i]
            tar_min_group = tar_reverse_space[min_j]

            # 将对齐的子句组合和对齐方式写到测试文件里
            if min_order:  #正序
                tmp_output_line = ','.join(src_line_list[0:len(src_min_group[0])])
                tmp_output_line += '\n'
                tmp_output_line += ','.join(src_line_list[len(src_min_group[0]):])
            else:          #逆序
                tmp_output_line = ','.join(src_line_list[len(src_min_group[0]):])
                tmp_output_line += '\n'
                tmp_output_line += ','.join(src_line_list[0:len(src_min_group[0])])
            line_tmp += 2
            ftmp.write(tmp_output_line)
        else:
            ftmp.write(src_line)
            line_tmp += 1
        line_num += 1
        print line_tmp
        print line_num

        src_line = inf_en.readline()
        tar_line = inf_ch.readline()
    ftmp.close()
    fcfg.close()
