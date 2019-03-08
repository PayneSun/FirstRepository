# -*- coding: utf-8 -*-


# sun.peng
# 2018/05/16~


#######################################################################
# 将列表按照逗号拆分成两个子序列并返还所有组合
def subserialize(list_of_phrase, length=2):
    result = []
    if len(list_of_phrase) == 2:
        result.append([[list_of_phrase[0]], [list_of_phrase[1]]])
    else:
        for i in range(1, len(list_of_phrase)):
            result.append([list_of_phrase[0:i], list_of_phrase[i:]])
    return result

### for-test ###
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
    min_match_order = True    # 正序为真逆序为假
    for i in range(len(list_of_phrase_src)):
        for j in range(len(list_of_phrase_tar)):
            # 正向距离
            dist_p = abs(sum(list_of_phrase_src[i][0]) - sum(list_of_phrase_tar[j][0]))\
                         + abs(sum(list_of_phrase_src[i][1]) - sum(list_of_phrase_tar[j][1]))
            # 逆向距离
            dist_n = abs(sum(list_of_phrase_src[i][0]) - sum(list_of_phrase_tar[j][1])) \
                         + abs(sum(list_of_phrase_src[i][1]) - sum(list_of_phrase_tar[j][0]))
            if dist_n < dist_p:
                if dist_n < min_match_dist:
                    min_match_order = False
                    min_match_dist = dist_n
                    min_match_i, min_match_j = i, j
            else:
                if dist_p < min_match_dist:
                    min_match_order = True
                    min_match_dist = dist_p
                    min_match_i, min_match_j = i, j

    return min_match_i,min_match_j,min_match_order,min_match_dist

### for-test ###
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
def ssrr(src_lang_file, tar_lang_file):
    '''
        输入的源语言文件  ：test/Test.en
        输入的目标语言文件：test/Test.ch
    '''
    with open(src_lang_file) as inf_en, open(tar_lang_file) as inf_ch:
    # with open('test/Test.en') as inf_en, open('test/Test.ch') as inf_ch:

        fcfg = open(src_lang_file + '.cfg', 'w')      # 用于恢复目标语言的对齐的配置文件
        fsrc_tmp = open(src_lang_file + '.tmp', 'w')  # 输入源语言文件经过预处理后的文件
        ftar_tmp = open(tar_lang_file + '.tmp', 'w')  # 输入目标语言文件经预处理后的文件

        line_num = 0; line_sub = 0
        # line_num = 1; line_sub = 1  # debug
        src_line = inf_en.readline()
        tar_line = inf_ch.readline()
        while (src_line):
            # print src_line.strip()  # debug
            # print tar_line.strip()  # debug

            src_line_list = src_line.strip().split(',')   # 按逗号切分英文句子
            tar_line_list = tar_line.strip().split('，')  # 按逗号切分中文句子

            src_line_len_list = [len(src_line_list[i].strip().split()) for i in range(len(src_line_list))]
            tar_line_len_list = [len(tar_line_list[i].strip().split()) for i in range(len(tar_line_list))]

            if (len(src_line_list) > 1) and (len(tar_line_list) > 1):
                # 子句组合对齐
                src_reverse_space = subserialize(src_line_len_list)
                tar_reverse_space = subserialize(tar_line_len_list)
                min_i,min_j,min_order,min_dist = select(src_reverse_space, tar_reverse_space)

                # 将子句组合方式写到配置文件中用于临时文件的恢复
                fcfg.write(str(min_order) + '\t' + str(line_num) + '\t' + str(line_sub) + '\n')

                # 被选中的子句组合
                src_min_group = src_reverse_space[min_i]
                tar_min_group = tar_reverse_space[min_j]

                # 将源语言拆分后的子句组合写入临时源文件中
                if min_order:  #正序
                    # print 'pos--\n',','.join(src_line_list[0:len(src_min_group[0])]),'\n',','.join(src_line_list[len(src_min_group[0]):])
                    src_output_line = ','.join(src_line_list[0:len(src_min_group[0])])
                    src_output_line += '\n'
                    src_output_line += ','.join(src_line_list[len(src_min_group[0]):])
                    src_output_line += '\n'
                else:          #逆序
                    # print 'neg--\n',','.join(src_line_list[len(src_min_group[0]):]),'\n',','.join(src_line_list[0:len(src_min_group[0])])
                    src_output_line = ','.join(src_line_list[len(src_min_group[0]):])
                    src_output_line += '\n'
                    src_output_line += ','.join(src_line_list[0:len(src_min_group[0])])
                    src_output_line += '\n'
                line_sub += 2
                fsrc_tmp.write(src_output_line)

                # 将目标语言拆分后的子句组合写入临时目标文件中
                tar_output_line = '，'.join(tar_line_list[0:len(tar_min_group[0])])
                tar_output_line += '\n'
                tar_output_line += '，'.join(tar_line_list[len(tar_min_group[0]):])
                tar_output_line += '\n'
                ftar_tmp.write(tar_output_line)
            else:
                fsrc_tmp.write(src_line)
                ftar_tmp.write(tar_line)
                line_sub += 1
            line_num += 1
            # print 'Debug-cfg:',line_num,line_sub  # debug

            src_line = inf_en.readline()
            tar_line = inf_ch.readline()
        fcfg.close()
        fsrc_tmp.close()
        ftar_tmp.close()


#######################################################################
def recovery(cfg_file, tar_file, comma):
    with open(cfg_file) as fcfg, open(tar_file) as ftar:
        # 最终输出的文件
        ffof = open('test/output.final', 'w')

        # 从配置文件中获取对齐列表
        cfg_line_list = []
        cfg_line = fcfg.readline()
        while (cfg_line):
            # 取配置文件行的最后一列
            cfg_line_list.append(int(cfg_line.strip().split('\t')[-1]))
            cfg_line = fcfg.readline()

        # print len(cfg_line_list),cfg_line_list  # debug

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


### for-test ###
# ssrr('test/Test.en', 'test/Test.ch')
recovery('test/Test.en.cfg', 'test/Test.ch.tmp', '，')
