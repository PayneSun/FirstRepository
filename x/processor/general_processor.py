"""
    process.py [2019/7/4]

    藏文数据集处理综合工具
"""

import matplotlib.pyplot as plt
import numpy as np
import os

def generate_case_aux_words(out_file):
    """
    生成藏文格助词词表
    """
    case_auxiliary_words = ["གིས", "གི", "གིས", "ཀྱིས", "གྱིས", "འིས", "ཡིས", "གི", "ཀྱི", "གྱི", "འི", "ཡི", "གིས", "ཀྱིས", "གྱིས", "འིས", "ཡིས", "གི", "ཀྱི", "གྱི", "འི", "ཡི", "གིས་", "ཀྱིས་", "གྱིས་", "འིས་", "ཡིས་", "གི་", "ཀྱི་", "གྱི་", "འི་", "ཡི་"]
    case_auxiliary_words = [word.strip('་') for word in case_auxiliary_words]
    caw = sorted(case_auxiliary_words)

    caw_new = []
    for index,word in enumerate(caw):
        if index != 0:
            if word == caw[index-1]:
                continue
            else:
                caw_new.append(word)
        else:
            caw_new.append(word)

    # out_file = "tibetan_case_auxiliary_words.txt"
    with open(out_file, 'w', encoding='utf-8') as fout:
        for word in caw_new:
            fout.write(word + '\n')
            print(word)


def generate_person_name_titles(out_file):
    """
    生成藏文人名称谓词词表
    """
    title = ["ཀྲུའུ་རིན་", "ཀྲུའུ་ཞི་", "ཀྲུའུ་ཞི་གཞོན་པ་",
             "དྲུང་ཡིག་པ་", "ཧྲུའུ་ཅི་", "རྩོམ་པ་པོ་",
             "སྐུ་ཞབས་", "ལས་རོགས་པ་", "ཆུས་ཀྲང་", "སྨན་པ་",
             "ཐིང་ཀྲང་", "རྫོང་དཔོན་", "ཨ་ཁུ་", "བློ་མཐུན་",
             "ཐོན་ཀྲང་", "རྒྱལ་བོ་", "ཁྲུའུ་ཀྲང་", "ཁུ་བོ་",
             "ཨ་ཇོ་", "མ་རྒན་", "ཨ་ཁུ་", "ལྷ་ལྕམ་", "མཁྱེན་ལྡན་མ་",
             "ཨུ་ཡོན་", "འཁྲབ་ཁྲིད་པ་", "སྲས་མོ་", "ཅུས་ཀྲང་",
             "ཧྲི་ཀྲང་", "ཙུངཐུང་", "སྤྱི་འདོམས་པ་", "སློབ་དཔོན་",
             "སློབ་གཙོ་", "ཞིང་ཆེན་གྱི་འགོ་འཛིན་", "ཁུ་ཀྲང་",
             "སྤྱ་གཉེར་བ་", "དགེ་རྒན་", "འཕྲིན་སྤེལ་བ་", "པུའུ་ཀྲང་",
             "ཨ་ཅེ་", "མགོ་ཁྲིད་", "འགོ་འཛིན་", "དབུ་བཞུགས་བློན་ཆེན་"]
    title = [word.strip('་') for word in title]
    title = sorted(title)

    title_new = []
    for index,word in enumerate(title):
        if index != 0:
            if word == title[index-1]:
                continue
            else:
                title_new.append(word)
        else:
            title_new.append(word)

    # out_file = "tibetan_person_name_titles.txt"
    with open(out_file, 'w', encoding='utf-8') as fout:
        for word in title_new:
            fout.write(word + '\n')
            print(word)


def generate_high_frequency_syllables(out_file):
    """
    生成藏文人名高频音节表
    """
    hfs = ["ཆོས་", "མ་", "མོ་" , "པ་","བསྟན་", "དབང་" , "སྒྲོན་","སྐྱིད་", "བཟང་" , "བུ་",
           "ཚེ་", "སྒྲོལ་", "པད་", "དཀར་", "མཚོ་", "བཀྲ་", "རྒྱལ་","ཤིས་", "སྒྲོ་", "སངས་",
           "ལི" , "ཝང",  "ཀྲང",  "ལིའུ", "ཁྲེན",  "དབྱང",  "ཧང",  "ཀྲོད",  "བོ",  "ཀྲོན",
           "ཞུས",  "སུན",  "མ",  "ཀྲོའུ",  "ཧུའུ",  "ཀོའོ",  "ཧོའུ",  "ཀའོ",  "ལིན",  "བློ",
           "ཀྲུན",  "ལུང",  "ཞེ",  "སོན",  "ཐང",  "ཞུས",  "ཧྲེན",  "ཧྥུན",  "ཏེང",  "ཚོ",
           "ཕུན",  "ཙུན",  "ཞོའུ",  "ཐན",  "ཏོན",  "ཡོན",  "ཕན",  "ཡུས",  "ཅང",  "ཚེ",
           "ཡུས",  "ཏོའུ",  "ཡད",  "ཁྲུན",  "སོད",  "ཝེ",  "ལུས",  "རྟེན",  "རིན",  "སྲུན",
           "ཡོད",  "ལོ",  "ཅུང",  "ཚེས",  "ཀྲོན",  "ཐན",  "ལོད",  "ཝང",  "ཧྥན",  "ཅུན", "སྲིད",
           "ལད",  "ལུང",  "ཅ",  "ཞ",  "ཝེ",  "ཧྥུ",  "ཧྥང",  "པེར",  "ཙོའི", "མུན",  "ཞོན",
           "ཆིན",  "ཆིང",  "ཅང",  "ཡེ",  "ཞོས",  "ཡན",  "དན", "ལེ", "ཧོ",  "ལོན",  "སྲིད",
           "ཐོའུ",  "ལི",  "ཧད",  "གོ",  "མའོ",  "ཧོ",  "ཀོན", "སྲང",  "བན",  "ཆན",  "ཡན",
           "ཐན",  "ཝུའུ",  "དད",  "མོད",  "ཁུང",  "ཞང", "ཐང", "ཞིས", "ཡུས", "ཕེང", "ཧྭ", "ཉིས"]

    hfs = [word.strip('་') for word in hfs]
    hfs = sorted(hfs)

    hfs_new = []
    for index,word in enumerate(hfs):
        if index != 0:
            if word == hfs[index-1]:
                continue
            else:
                hfs_new.append(word)
        else:
            hfs_new.append(word)

    # out_file = "tibetan_person_name_high_frequency_syllables.txt"
    with open(out_file, 'w', encoding='utf-8') as fout:
        for word in hfs_new:
            fout.write(word + '\n')
            print(word)


def merge_person_name_titles(person_name_titles_list):
    """
    合并多个藏文人名称谓词表
    person_name_titles_list = [
        ".\\ne_feature\\tibetan_person_titles.txt", "tibetan_person_name_titles.txt"
    ]
    """
    fpno = open(person_name_titles_list[0], 'r', encoding='utf-8').readlines()
    titles = []
    for line in fpno:
        titles.append(line.strip())
    titles = [word.strip('་') for word in titles]
    titles = sorted(titles)

    titles_new = []
    for index, word in enumerate(titles):
        if index != 0:
            if word == titles[index-1]:
                continue
            else:
                titles_new.append(word)
        else:
            titles_new.append(word)

    fpnn = person_name_titles_list[1]
    with open(fpnn, 'w', encoding='utf-8') as fout:
        for word in titles_new:
            fout.write(word + '\n')
            print(word)


def merge_organization(org_suffix_list):
    """
    合并组织机构名词缀表
    org_suffix_list = [
        ".\\ne_feature\\tibetan_orgnization_titles.txt", "tibetan_organization_name_titles.txt"
    ]
    """
    fpno = open(org_suffix_list[0], 'r', encoding='utf-8').readlines()
    titles = []
    for line in fpno:
        titles.append(line.strip())
    titles = [word.strip('་') for word in titles]
    titles = sorted(titles)

    titles_new = []
    for index, word in enumerate(titles):
        if index != 0:
            if word == titles[index-1]:
                continue
            else:
                titles_new.append(word)
        else:
            titles_new.append(word)

    fpnn = org_suffix_list[0]
    with open(fpnn, 'w', encoding='utf-8') as fout:
        for word in titles_new:
            fout.write(word + '\n')
            print(word)


def merge_location(loc_suffix_list):
    """
    合并地名词缀表
    loc_suffix_list = [
        ".\\ne_feature\\tibetan_chinese_location_titles.txt", "tibetan_location_name_titles.txt"
    ]
    """
    fpno = open(loc_suffix_list[0], 'r', encoding='utf-8').readlines()
    titles = []
    for line in fpno:
        titles.append(line.strip())
    titles = [word.strip('་') for word in titles]
    titles = sorted(titles)

    titles_new = []
    for index, word in enumerate(titles):
        if index != 0:
            if word == titles[index-1]:
                continue
            else:
                titles_new.append(word)
        else:
            titles_new.append(word)

    fpnn = loc_suffix_list[1]
    with open(fpnn, 'w', encoding='utf-8') as fout:
        for word in titles_new:
            fout.write(word + '\n')
            print(word)


def merge_hfs(person_name_hfs_list):
    """
    合并人名高频音节
    person_name_hfs_list = [
        ".\\ne_feature\\0.txt", "tibetan_person_high_frequency_syllables.txt"
    ]
    """
    fpno = open(person_name_hfs_list[0], 'r', encoding='utf-8').readlines()
    titles = []
    for line in fpno:
        titles.append(line.strip())
    titles = [word.strip('་') for word in titles]
    titles = sorted(titles)

    titles_new = []
    for index, word in enumerate(titles):
        if index != 0:
            if word == titles[index-1]:
                continue
            else:
                titles_new.append(word)
        else:
            titles_new.append(word)

    with open(person_name_hfs_list[1], 'w', encoding='utf-8') as fout:
        for word in titles_new:
            fout.write(word + '\n')
            print(word)


def merge(file_name):
    """
    合并文件
    """
    fpno = open(file_name, 'r', encoding='utf-8').readlines()
    titles = []
    for line in fpno:
        titles.append(line.strip())
    titles = [word.strip('་') for word in titles]
    titles = sorted(titles)

    titles_new = []
    for index, word in enumerate(titles):
        if index != 0:
            if word == titles[index-1]:
                continue
            else:
                titles_new.append(word)
        else:
            titles_new.append(word)

    fpnn = file_name + '-new'
    with open(fpnn, 'w', encoding='utf-8') as fout:
        for word in titles_new:
            fout.write(word + '\n')
            print(word)


def append_syllable(feature_file, flag='་'):
    """
    在藏文音节后追加音节分割符
    """
    with open(feature_file, 'r', encoding='utf-8') as fin,\
        open(feature_file + '.cp', 'w', encoding='utf-8') as fout:
        for line in fin:
            line = line.strip(flag) + flag
            fout.write(line + '\n')


def remove_duplicate(feature_file, flag='་'):
    """
    剔除文件中重复的内容（行）
    """
    units = []
    with open(feature_file, 'r', encoding='utf-8') as fin:
        for line in fin:
            if line.strip():
                units.append(line.strip())
    # units = sorted(units)
    # new_units = set(units)

    output_txt = feature_file + '.unique'
    with open(output_txt, 'w', encoding='utf-8') as fout:
        for word in set(units):
            fout.write(word + '\n')
            print(word)


def merge_file(file_name_list, output):
    """
    合并多个文件
    """
    total_units = []
    for file_name in file_name_list:
        fin = open(file_name, 'r', encoding='utf-8').readlines()
        fin = set([line.strip() for line in fin if line.strip()])
        total_units.extend(fin)
    total_units = set(total_units)

    with open(output, 'w+', encoding='utf-8') as fout:
        for line in total_units:
            line = line.strip('་') + '་'
            fout.write(line + '\n')
            print(line)


def generate_crf_template(template_file='template.mf'):
    """
    自动生成CRF特征模板（主要用于高维的无监督词向量特征）
    """
    feature_id = 10
    mon_window = [-1, 0, 1]
    com_window = [0, 1]
    column_list = list(range(1,112))

    with open(template_file, 'w', encoding='utf-8') as fmf:
        for col in column_list:
            # 一元特征
            mon_feature = ''
            for row in mon_window:
                mon_feature += 'U' + str(feature_id) + ':%x[' + str(row) + ',' + str(col) + ']\n'
                feature_id = feature_id + 1
            # 复合特征-单特征组合
            com_feature = ''
            for row in com_window:
                com_feature += 'U' + str(feature_id) + ':%x[' + str(row-1) + ',' + str(col) + ']/%x[' + str(row) + ',' + str(col) + ']\n'
                feature_id = feature_id + 1
            # 复合特征-音节/特征组合
            wfc_feature = 'U' + str(feature_id) + ':%x[0,0]/%x[0,' + str(col) + ']\n'
            feature_id = feature_id + 1
            # 复合特征-多特征组合
            # mfc_feature = 'U' + str(feature_id) + ':%x[-1,' + str(col) + ']/%x[0,' + str(col) + ']/%[1,' + str(col) + ']\n'
            # feature_id = feature_id + 1

            print(mon_feature + com_feature + wfc_feature)
            fmf.write(mon_feature + com_feature + wfc_feature+ '\n')


def replace(infile, separator_old=' ', separator_new='\t'):
    """
    替换文本中的分隔符，默认将空格（' '）替换成tab（'\t'）
    """
    outf = infile + '.new'
    with open(infile, 'r', encoding='utf-8') as fin, open(outf, 'w', encoding='utf-8') as fout:
        for line in fin:
            line = line.strip().split(separator_old)
            if line:
                fout.write(separator_new.join(line) + '\n')
                print('[Debug][function-replace]' + separator_new.join(line) + '\n')
            else:
                fout.write('\n')


def split_by_multicolumn(infile):
    """
    抽取多列文件的特定（多）列
    """
    outfile = infile + '.new'
    with open(infile, 'r', encoding='utf-8') as fin, open(outfile, 'w', encoding='utf-8') as fout:
        for line in fin:
            line = line.strip().split()
            if line:
                fout.write(' '.join(line[0:12]) + ' ' + line[-1] + '\n')
                print(' '.join(line[0:12]) + ' ' + line[-1] + '\n')
            else:
                fout.write('\n')


def extract_high_frequency_word(infile):
    """
    抽取词语、去重、生成词表
    """
    hfw = []
    with open(infile, 'r', encoding='utf-8') as frd, open(infile + '.new', 'w', encoding='utf-8') as fwt:
        for line in frd:
            line = line.strip().split()
            if line:
                hfw.append(line[-1])
        hfw = set(hfw)
        for word in hfw:
            print(word)
            fwt.write(word + '\n')


def extract_per_from_data(data_file):
    """
    抽取CRF格式数据中的实体（人名），输出实体出现在文件中的行号和实体，写到文件中
    """
    per_list = []
    idx_list = []
    out_file = data_file + '.ne.stat'
    with open(data_file, 'r', encoding='utf-8') as frd, open(out_file, 'w', encoding='utf-8') as fwt:
        per_str = ''
        for index,line in enumerate(frd):
            line = line.strip().split()
            if len(line):  # 非空行
                if 'B-PER' in line:
                    idx_list.append(index+1)  # 记录人名出现的行号
                    if per_str:
                        per_list.append(per_str)
                        if len(per_list) != len(idx_list)-1:
                            print(str(idx_list[-1]) + '------' + per_str)
                        per_str = ''
                    per_str += line[0]
                elif 'I-PER' in line:
                    per_str += line[0]
                else: # O
                    if per_str:
                        per_list.append(per_str)
                        if len(per_list) != len(idx_list):
                            print(str(idx_list[-1]) + '------' + per_str)
                        per_str = ''
            else:  # 空行
                if per_str:
                    per_list.append(per_str)
                    if len(per_list) != len(idx_list):
                        print(str(idx_list[-1]) + '------' + per_str)
                    per_str = ''

        assert len(idx_list) == len(per_list)

        # 写出到文件
        for idx,per in zip(idx_list, per_list):
            fwt.write(str(idx) + ':' + per + '\n')
            # only for debug
            # print(str(index) + ':' + person)

        # 返回人名行号和列表
        return idx_list,per_list


def extract_per_pos_info(data_file):
    """
    统计CRF格式数据中的实体的句子位置特征并输出到文件
    """
    idx_list = [] #人名在文件中的行数
    pos_list = [] #人名在句子中的音节位置
    max_list = [] #人名所在句子的音节长度
    out_file = data_file + '.ne.pos'
    with open(data_file, 'r', encoding='utf-8') as frd, open(out_file, 'w', encoding='utf-8') as fwt:
        last_pos = ''
        sent_pos_list = []
        for index,line in enumerate(frd):
            line = line.strip().split()
            if len(line):  # 非空行
                sent_len = line[1]
                if '.txt' not in line[0]:
                    last_pos = line[1]
                if 'B-PER' in line:
                    sent_pos_list.append(int(line[1].split('-')[-1])) #记录位置信息
                    idx_list.append(index)
            else:  # 句子间的分割空行
                if len(sent_pos_list):
                    sent_max_pos = int(last_pos.split('-')[-1])
                    pos_list.extend(sent_pos_list)
                    max_list.extend([sent_max_pos] * len(sent_pos_list))
                    sent_pos_list.clear()
                    last_pos = ''

        assert len(pos_list) == len(max_list)
        for index,pos in enumerate(pos_list):
            print(str(idx_list[index]) + ' ' + str(pos) + ' ' + str(max_list[index]))
            fwt.write(str(idx_list[index]) + ' ' + str(pos) + ' ' + str(max_list[index]) +'\n')

        # 返回人名行号和列表
        return pos_list,max_list


def count_word_frequency(vocab, outfile, prec=6):
    """
    统计词表中的词频和比例，写到文件中
    """
    # 统一追加音节分隔符以消除同一词
    words = [(word.strip('་') + '་') for word in vocab]
    words.sort()

    word_unit = []; word_nums = []
    for index,unit in enumerate(words):
        if index:
            if word_unit[-1] == unit:
                word_nums[-1] = word_nums[-1] + 1
            else:
                word_unit.append(unit)
                word_nums.append(1)
        else:
            word_unit.append(unit)
            word_nums.append(1)

    word_cnts = []
    for unit,num in zip(word_unit, word_nums):
        word_cnts.append([unit, num])
    word_cnts.sort(key=lambda x: x[-1], reverse=True)

    with open(outfile, 'w', encoding='utf-8') as fout:
        for word_num in word_cnts:
            percentage = str(round(word_num[-1] / len(words), prec))
            fout.write(word_num[0] + ' ' + str(word_num[-1]) + '/' + str(len(words)) + ' ' + percentage + '\n')

    return word_cnts


def analyze_experiment_data(train_file, test_file, prec=6):
    """
        分析训练和测试集数据，主要是检查测试集中的实体被训练集覆盖情况。
        输出包括整体覆盖率，去重覆盖率，整体覆盖中的实体及频次
    """
    # 抽取训练集和测试集中的实体
    _, train_per_table = extract_per_from_data(train_file)
    _, test_per_table = extract_per_from_data(test_file)

    # 统计训练集和测试集中的实体及频次
    train_per_wf = count_word_frequency(train_per_table, train_file + '.wf', prec)
    test_per_wf = count_word_frequency(test_per_table, test_file + '.wf', prec)

    # 抽取训练集和测试集中的实体表
    train_per_words = [wf[0] for wf in train_per_wf]
    test_per_words = [wf[0] for wf in test_per_wf]

    # 统计测试集中的实体被训练集覆盖的情况（整体，包含重复）
    exist_all_per = []
    no_exist_all_per = []
    for tw in test_per_table:
        if tw in train_per_table:
            exist_all_per.append(tw)
        else:
            no_exist_all_per.append(tw)

    # 统计测试集中的实体被训练集覆盖的情况（去除重复后）
    exist_ndp_cnt = 0
    exist_ndp_per = []
    no_exist_ndp_cnt = 0
    no_exist_ndp_per = []
    for tw in test_per_words:
        if tw in train_per_words:
            exist_ndp_cnt += 1
            exist_ndp_per.append(tw)
        else:
            no_exist_ndp_cnt += 1
            no_exist_ndp_per.append(tw)

    # 输出重复情况
    print('Duplication (all): ' + str(round(len(exist_all_per)/len(test_per_table), prec)) + \
          ' (' + str(len(exist_all_per)) + '/' + str(len(test_per_table)) + ')')
    print('Duplication (ndp): ' + str(round(len(exist_ndp_per)/len(test_per_words), prec)) + \
          ' (' + str(len(exist_ndp_per)) + '/' + str(len(test_per_words)) + ')')

    # 统计测试集中被覆盖的实体的频次
    count_word_frequency(exist_all_per, 'exist_in_train.wf')

    #debug
    return exist_all_per


def extract_filename_from_data(data_file):
    """
    抽取文本中的文件名（剔除了路径前缀）
    """
    idx_file_list = []
    with open(data_file, 'r', encoding='utf-8') as frd:
        for index,line in enumerate(frd):
            line = line.strip().split()
            if line and '.txt' in line[0]:
                pos = line[0].rfind('\\')
                if pos != -1:
                    idx_file_list.append([index+1, line[0][pos:]])
                else:
                    idx_file_list.append([index+1, line[0]])

    # 输出文件名列表
    with open(data_file + '.fn.stat', 'w', encoding='utf-8') as fwt:
        for idx_file in idx_file_list:
            fwt.write(str(idx_file[0]) + ':' + idx_file[-1] + '\n')

    return idx_file_list


def get_word_length_info(vocabs):
    """
    统计词表中词长度分布情况
    """
    word_lens = []
    for word in vocabs:
        syllables = word.strip('་').split('་')
        word_lens.append(len(syllables))

    len_num_map = {}
    for word_len in set(sorted(word_lens)):
        len_num_map[word_len] = word_lens.count(word_len)

    # 绘制词长-频次图
    x = np.array(list(len_num_map.keys()))
    y = np.array(list(len_num_map.values()))

    print('word number:', len(word_lens))
    print('min length : ', np.min(x))
    print('max length : ', np.max(x))

    for sx,sy in zip(x,y):
        print(sx, '\t-\t', sy, '\t', round(sy/np.sum(y), 6))
    plt.bar(x, y, color='b')
    plt.title("Length distribution of named entities")
    plt.xlabel("Named entity's length")
    plt.ylabel('Ratio')
    plt.show()


def count_sent_length(data_file):
    """"""
    index = -1
    begin = -1
    sent_lens = []
    with open(data_file, 'r', encoding='utf-8') as frd:
        for line in frd:
            index = index + 1
            line = line.strip()
            if line:
                if begin == -1: #句首
                    begin = index
            else: #句尾下一行
                if begin != -1:
                    end = index
                    sent_lens.append(end-begin)
                    begin = -1
    return sent_lens


def convert_ne_pos_feature(data_file, scale=3):
    # 加载位置特征文件
    sent_lens = count_sent_length(data_file)

    with open(data_file, 'r', encoding='utf-8') as frd, open(data_file + '.m' + str(scale), 'w', encoding='utf-8') as fwt:
        sent_n = 0
        for index,line in enumerate(frd):
            line = line.strip().split()
            if line:
                idx = int(line[1].split('-')[-1])
                if int(sent_lens[sent_n]) > scale and idx < scale:
                    # line[1] = str(idx // scale)
                    line[1] = 'P'
                else:
                    line[1] = 'N'
                fwt.write(' '.join(line) + '\n')
            else:
                sent_n = sent_n + 1
                fwt.write('\n')


def fold_func(pos_list_len, folder_val=10):
    if pos_list_len % folder_val:
        stage = pos_list_len // folder_val + 1
    else:
        stage = pos_list_len // folder_val

    print(stage)

    folder_list = []
    tag = 0; pos = 0; cnt = 0
    while cnt < pos_list_len:
        pos = pos + 1
        cnt = cnt + 1
        folder_list.append(tag)
        if pos < stage:
            continue
        else:
            tag = tag + 1
            pos = 0

    return folder_list


def syll_pos_feature(raw_format_file, is_fold=False):
    with open(raw_format_file, 'r', encoding='utf-8') as fin,\
        open(raw_format_file + '.pos', 'w', encoding='utf-8') as fout:
        sent = []
        for line in fin:
            line = line.strip().split()
            print(line)
            if line:
                sent.append(line)
            else:
                if is_fold:
                    tags = fold_func(len(sent))
                    for tag,syll in zip(tags,sent):
                        fout.write(syll[0] + ' POS-' + str(tag) + ' ' + ' '.join(syll[1:]) + '\n')
                else:
                    for index,syll in enumerate(sent):
                        fout.write(syll[0] + ' POS-' + str(index) + ' ' + ' '.join(syll[1:]) + '\n')
                fout.write('\n')
                sent = []


def count_xxx(pos_file):
    ne_num = 0
    pos_rel = []
    pos_map = {}
    with open(pos_file, 'r', encoding='utf-8') as frd:
        for line in frd:
            line = line.strip().split()
            if len(line):
            # if len(line) and int(line[-1]) < 100:
                ne_num += 1
                pos_map[int(line[1])] = pos_map.get(int(line[1]), 0) + 1

    pos_keys = list(pos_map.keys())
    pos_nums = []
    for key in pos_map.keys():
        pos_nums.append(pos_map[key])

    pos_keys = sorted(pos_keys)
    pos_nums = np.array(pos_nums)
    pos_nums = pos_nums[np.argsort(pos_keys)]
    for i in range(len(pos_keys)):
        print(str(list(pos_keys)[i]) + '\t' + str(pos_nums[i]))

    plt.bar(pos_keys, pos_nums)
    # plt.title('training data')
    plt.xlabel('position in sentence')
    plt.ylabel('number')
    plt.show()


if __name__ == '__main__':
    # case_aux_words()
    # person_name_titles()
    # high_frequency_syllables()
    # merge_person_name()
    # merge_organization()
    # merge_location()
    # merge_hfs()

    # file_name = r'.\ne_feature\tibetan_high_frequency_syllable.txt'
    # merge(file_name)

    # input_txt = 'high_frequency_charater.txt'
    # fpno = open(input_txt, 'r', encoding='utf-8').readlines()
    # titles = []
    # for line in fpno:
    #     line = [syllable.strip('།') + '་' for syllable in line.strip().split('་') if syllable]
    #     print('[Debug] ', end='')
    #     print(line)
    #     if len(line) == 1:
    #         titles.append(line[0])
    # # titles = [word.strip('་') for word in titles]
    # titles = sorted(titles)
    #
    # titles_new = []
    # for index, word in enumerate(titles):
    #     if index != 0:
    #         if word == titles[index - 1]:
    #             continue
    #         else:
    #             titles_new.append(word)
    #     else:
    #         titles_new.append(word)
    #
    # output_txt = input_txt + '.out'
    # with open(output_txt, 'w', encoding='utf-8') as fout:
    #     for word in titles_new:
    #         fout.write(word + '\n')
    #         print(word)


    # ===检查多特征语料列数是否一致===begin===#
    train_file = r".\data\data1125\tb.ne.data"

    idx_lens = []
    with open(train_file, 'r', encoding='utf-8') as frd, open(train_file + '.fx', 'w', encoding='utf-8') as fwt:
        for index,line in enumerate(frd):
            line = line.strip().split()
            if len(line) == 0:
                fwt.write("\n")
            elif len(line) == 12:
                fwt.write(" ".join(line[0:6]) + " " + line[-1] + "\n")
            else:
                fwt.write(' '.join(line[0:5]) + " CLS-X " + line[-1] + "\n")
                # print(str(index) + '\t' + str(len(line)))
    # ===检查多特征语料列数是否一致===end===#


    # infile = '.\\data\\tb-per\\tb-per-test.ld.final'
    # split_by_multiline(infile)

    #===分析训练集和测试集的实体情况===begin===#
    # train_file = r'.\data\data0919\per_train.txt'
    # test_file = r'.\data\data0919\per_test.txt'
    # exist_all_per = analyze_experiment_data(train_file, test_file)
    #===分析训练集和测试集的实体情况===end===#


    #===检查基线CRF识别结果和训练集的关系===begin===#
    # train_file = r'.\data\tb_per_data\tb_train_c.txt'
    # test_file = r'.\data\tb_per_data\tb_test_c.txt'
    # exist_all_per = analyze_experiment_data(train_file, test_file)
    #
    # inf_ans = 'result_ans.txt'
    # inf_crf = 'result_crf.txt'
    # crf_all_per = analyze_experiment_data(inf_ans, inf_ans)
    #
    # chk = 0
    # for crf_word in crf_all_per:
    #     if crf_word in exist_all_per:
    #         chk += 1
    # print('result:' + str(chk) + '/' + str(len(crf_all_per)))
    #===检查基线CRF识别结果和训练集的关系===end===#


    #===检查训练集和测试集是否有文件重叠===begin===#
    # train_file = r'.\data\data0919\per_train.txt'
    # test_file = r'.\data\data0919\per_test.txt'
    # train_file_list = extract_filename_from_data(train_file)
    # test_file_list = extract_filename_from_data(test_file)
    #
    # dup = 0
    # for test_file in test_file_list:
    #     print(test_file)
    #     if test_file in train_file_list:
    #         dup += 0
    # print('duplication: ' + str(dup))

    # train_file_list.sort()
    # test_file_list.sort()
    # if len(train_file_list) != len(set(train_file_list)):
    #     print('train file duplicated !!!')
    # if len(test_file_list) != len(set(test_file_list)):
    #     print('test file duplicated !!!')
    ###===检查训练集和测试集是否有文件重叠===end===###


    ###===统计词表中词长度分布===start===###
    # in_file = r'.\data\data0919\per_all.txt'
    # wt_file = r'.\data\data0919\per_all.txt.stat'

    # idx_list,per_list = extract_per_from_data(in_file)
    # get_word_length_info(per_list)

    # idx_file_names = extract_filename_from_data(in_file)
    # with open(in_file[0:in_file.rfind('.')]+'.fns', 'w', encoding='utf-8') as fwt:
    #     for idx_file in idx_file_names:
    #         fwt.write(str(idx_file[0]) + ':' + idx_file[-1] + '\n')
    ###===统计词表中词长度分布===end===###


    ###===剔除实体特征文件中的重复和等价拼写===start===###
    # feature_file_path = r'.\ToDoCheck\\'
    # feature_file_list = os.listdir(feature_file_path)
    # for feature_file in feature_file_list:
    #     feature_file = feature_file_path + feature_file
    #     with open(feature_file, 'r', encoding='utf-8') as frd, \
    #             open(feature_file + '.new', 'w', encoding='utf-8') as fwt:
    #         features = []
    #         for line in frd:
    #             features.append(line.strip())
    #
    #         process_features = set(sorted(features))
    #         for proc_ft in process_features:
    #             print(proc_ft)
    #             fwt.write(proc_ft + '\n')
    ###===剔除实体特征文件中的重复和等价拼写===end===###

    #===分析数据集的实体位置情况===begin===#
    # train_file = r'.\data\data0903\per_train.txt'
    # test_file = r'.\data\data0903\per_test.txt'
    # pos_list, max_list = extract_per_pos_info(test_file)
    #
    # #-----------------
    # y = [int(10*pos/max_list[idx]) for idx,pos in enumerate(pos_list)]
    # pos_map = {}
    # for ele in sorted(y):
    #     pos_map[ele] = pos_map.get(ele, 0) + 1
    # x1 = list(range(10))
    # y1 = []
    # for i in range(10):
    #     y1.append(pos_map.get(i,0)/len(pos_list))
    #
    # # -----------------
    # y = [int(20 * pos / max_list[idx]) for idx, pos in enumerate(pos_list)]
    # pos_map = {}
    # for ele in sorted(y):
    #     pos_map[ele] = pos_map.get(ele, 0) + 1
    # x2 = list(range(20))
    # y2 = []
    # for i in range(20):
    #     y2.append(pos_map.get(i, 0) / len(pos_list))
    #
    # # -----------------
    # y = [int(50 * pos / max_list[idx]) for idx, pos in enumerate(pos_list)]
    # pos_map = {}
    # for ele in sorted(y):
    #     pos_map[ele] = pos_map.get(ele, 0) + 1
    # x3 = list(range(50))
    # y3 = []
    # for i in range(50):
    #     y3.append(pos_map.get(i, 0) / len(pos_list))
    #
    # # -----------------
    # y = [int(100 * pos / max_list[idx]) for idx, pos in enumerate(pos_list)]
    # pos_map = {}
    # for ele in sorted(y):
    #     pos_map[ele] = pos_map.get(ele, 0) + 1
    # x4 = list(range(100))
    # y4 = []
    # for i in range(100):
    #     y4.append(pos_map.get(i, 0) / len(pos_list))
    #
    # plt.subplot(2,2,1)
    # plt.bar(x1,y1)
    # plt.text(5, 0.2, 'scale=10')
    # plt.xlabel("relative position")
    # plt.ylabel('percentage')
    # plt.subplot(2,2,2)
    # plt.bar(x2, y2)
    # plt.text(10, 0.15, 'scale=20')
    # plt.xlabel("relative position")
    # plt.ylabel('percentage')
    # plt.subplot(2,2,3)
    # plt.bar(x3, y3)
    # plt.text(25, 0.12, 'scale=50')
    # plt.xlabel("relative position")
    # plt.ylabel('percentage')
    # plt.subplot(2,2,4)
    # plt.bar(x4, y4)
    # plt.text(50, 0.12,'scale=100')
    # plt.xlabel("relative position")
    # plt.ylabel('percentage')
    #
    # plt.show()
    #===分析数据集的实体位置情况===end===#

    #===转换数据集的实体位置特征===start===#
    # train_file = r'.\data\data0926\per_train.txt'
    # test_file = r'.\data\data0926\per_test.txt'
    #
    # syll_pos_feature(test_file)
    # convert_ne_pos_feature(test_file + '.pos')

    # ret = count_sent_length(train_file)
    # print(len(ret))
    # print(ret)
    #===转换数据集的实体位置特征===end===#


    # infile = r'.\data\data0917\per_train.txt'
    # outfile = infile + '.new'
    # with open(infile, 'r', encoding='utf-8') as fin, open(outfile, 'w', encoding='utf-8') as fout:
    #     for line in fin:
    #         line = line.strip().split()
    #         if line:
    #             fout.write(line[0] + ' ' + ' '.join(line[2:]) + '\n')
    #             print(line[0] + ' ' + ' '.join(line[2:]) + '\n')
    #         else:
    #             fout.write('\n')
    # infile = r'.\data\data0917\per_train.txt.new'
    # syll_pos_feature(infile, 10)

    # infile = r'.\data\data0903\per_all.txt.ne.pos'
    # count_xxx(infile)

