"""
    标注藏文命名实体的特征

    label_ne_feature.py
    2019/3/20
"""


def read_feature_set(feature_file):
    """
        从特征集文件中读入特征，返回特征集列表
    """
    ft_set_list = []
    with open(feature_file, 'r', encoding="utf-8") as fin:
        for line in fin:
            line = line.strip()
            if line:
                ft_set_list.append(line)
    return ft_set_list


def sent_2_sylls(word):
    """
        split word by syllable
    """
    delimiter = {'་'}
    mono_syllable = ''
    syllable_list = []
    for i in range(len(word)):
        mono_syllable += word[i]
        if word[i] in delimiter:
            if i == len(word) - 1:
                syllable_list.append(mono_syllable)
                mono_syllable = ''
            else:
                if word[i+1] not in delimiter:
                    syllable_list.append(mono_syllable)
                    mono_syllable = ''
        else:
            if i == len(word) - 1:
                syllable_list.append(mono_syllable)
                mono_syllable = ''
    if len(mono_syllable) > 0:
        syllable_list.append(mono_syllable)

    return syllable_list


def query_ft_pos(sent_syllables, ft_syllables):
    """
    查询特征出现在句子中的位置
    :param:
        sent_syllables  : 句子音节列表
        ft_syllables    : 特征音节列表
    :return:
        特征出现在句子中的位置
    """
    ft_len = len(ft_syllables)
    ft_str = ''.join(ft_syllables)
    sent_len = len(sent_syllables)

    # pos_list = []
    # ft_str = ''.join(ft_syllables)
    # for i in range(sent_len-ft_len):
    #     sub_sent_str = ''.join(sent_syllables[i:i+ft_len])
    #     if sub_sent_str == ft_str:
    #         for j in range(ft_len):
    #             pos_list.append([i+j, 1])

    index = 0
    syllable_ft_pos = []
    while True:
        if index >= sent_len-ft_len:
            break
        sub_sent_str = ''.join(sent_syllables[index:index+ft_len])
        # if sub_sent_str == ft_str:
        if sub_sent_str.strip('་') == ft_str.strip('་'):  # 消除人名末尾音节分隔符的影响 2019-7-8
            for j in range(ft_len):
                syllable_ft_pos.append(index+j)
            index = index + ft_len
        else:
            index = index + 1

    return sorted(syllable_ft_pos)


# def match_sylls_m(sent_syll_list, nf_syll_list, id):
#     """"""
#     nf_len = len(nf_syll_list)
#     sent_len = len(sent_syll_list)
#
#     pos_list = []
#     nf_sylls = ''.join(nf_syll_list)
#     for i in range(sent_len - nf_len):
#         sent_sylls = ''.join(sent_syll_list[i:i+nf_len])
#         if sent_sylls == nf_sylls:
#             for j in range(nf_len):
#                 pos_list.append([i+j, id])
#
#     return pos_list


def locate_feature(sent_syllables, ft_set, ft_tag):
    """
    :param:
        sent_syllables  : 句子音节列表
        ft_set          : 特征集合
    :return:
        在句子中特征的位置及特征的长度
    """
    ft_pos_list = []
    for feature in ft_set:
        ft_syllables = sent_2_sylls(feature)
        syllable_ft_pos = query_ft_pos(sent_syllables, ft_syllables)
        ft_pos_list.extend(syllable_ft_pos)
    ft_pos_list.sort()

    tag_schema = []
    for i in range(len(sent_syllables)):
        if i in ft_pos_list:
            tag_schema.append([i, ft_tag[0]])
        else:
            tag_schema.append([i, ft_tag[1]])

    return tag_schema


def query_wvft_pos(sent_syllables, ft_syllables, feature):
    """
    查询特征出现在句子中的位置
    :param:
        sent_syllables  : 句子音节列表
        ft_syllables    : 特征音节列表
    :return:
        特征出现在句子中的位置
    """
    ft_len = len(ft_syllables)
    ft_str = ''.join(ft_syllables)
    sent_len = len(sent_syllables)

    index = 0
    syllable_pos_ft = []
    while True:
        if index >= sent_len-ft_len:
            break
        sub_sent_str = ''.join(sent_syllables[index:index+ft_len])
        # if sub_sent_str == ft_str:
        if sub_sent_str.strip('་') == ft_str.strip('་'):    # 消除人名末尾音节分隔符的影响 2019/7/8
            for j in range(ft_len):
                syllable_pos_ft.append([index+j, feature])
            index = index + ft_len
        else:
            index = index + 1

    return sorted(syllable_pos_ft, key=lambda x: x[0])


def locate_feature_wv(sent_syllables, word_features, ft_tag):
    pos_fts = []
    for word_feature in word_features:
        ft_syllables = sent_2_sylls(word_feature[0])
        syllable_pos_ft = query_wvft_pos(sent_syllables, ft_syllables, word_feature[-1])
        pos_fts.extend(syllable_pos_ft)
    pos_fts.sort(key=lambda x:x[0])

    syllables_pos = []
    syllables_fts = []
    for idx,pft in enumerate(pos_fts):
        if pft[0] in syllables_pos:
            continue
        else:
            syllables_pos.append(pft[0])
            syllables_fts.append(pft[-1])

    # 生成和无监督词向量数量相同的特征标签
    print('+++++++++++++++++++++')
    nft = len(word_features[0][-1].split())
    uc_feature = (ft_tag + ' ') * (nft-1) + ft_tag

    tag_schema = []
    for i in range(len(sent_syllables)):
        if i in syllables_pos:
            pos = syllables_pos.index(i)
            tag_schema.append([i, syllables_fts[pos]])
        else:
            tag_schema.append([i, uc_feature])

    return tag_schema


# def locate_feature_m(sent_syll_list, nfm_list):
#     """
#     :param sentence : 句子
#     :param nf_list  : 特征列表
#     :return         : 在句子中特征的位置及特征的长度
#     """
#     nf_list = []
#     tag_list = []
#     for line in nfm_list:
#         line = [ele.strip() for ele in line.split('\t')]
#         nf_list.append(line[0])
#         tag_list.append(line[-1])
#
#     pos_len_list = []
#     for id,nf in enumerate(nf_list):
#         nf_syll_list = sent_2_sylls(nf)
#         pos_list = match_sylls_m(sent_syll_list, nf_syll_list, id)
#         pos_len_list.extend(pos_list)
#     pos_len_list.sort(key=lambda x: x[0])
#
#     tag_schema = []
#     pos_list = [pos_len[0] for pos_len in pos_len_list]
#     ids_list = [pos_len[-1] for pos_len in pos_len_list]
#     for i in range(len(sent_syll_list)):
#         if i in pos_list:
#             ps = pos_list.index(i)
#             id = ids_list[ps]
#             tag = tag_list[id]
#             tag_schema.append([i, tag])
#         else:
#             tag_schema.append([i, 'X'])
#
#     return tag_schema


def read_raw_file(input_file):
    """
        读取无特征的语料、抽取音节-标签列表
    :param input_file : 无特征音节级训练
    :return           : 音节-标签分离的句子列表
    """
    sent_list = []
    with open(input_file, 'r', encoding='utf-8') as fin:
        sent_chars = []     # 句子的音节
        sent_tags = []      # 句子的音节对应的标签
        for char_tag in fin:
            char_tag = char_tag.strip().split()
            if len(char_tag):   # 非空行
                sent_chars.append(char_tag[0])
                sent_tags.append(char_tag[-1])
            else:               # 空行（指示句子结束）
                sent_list.append([sent_chars, sent_tags])
                sent_chars = []; sent_tags = []
        # 将剩余的部分追加到句子列表中
        sent_list.append([sent_chars, sent_tags])

    return sent_list


def get_sent_tag(sent_syllables, stat_ft_set, stat_ft_schema, wvec_ft_set, wvec_ft_schema):
    """
    句子的音节粒度特征标注
    :param:
        sent_syllables  : 句子音节列表
        ft_set_{2-5,x-z}: 特征集合
    :return:
        syllable_tag_schema: 标记方案（每个音节在每个特征列对应的标签）
    """
    # 监督特征（2~5），仅包含单列特征标签
    ft_2_tags = locate_feature(sent_syllables, stat_ft_set[0], stat_ft_schema[0])
    ft_3_tags = locate_feature(sent_syllables, stat_ft_set[1], stat_ft_schema[1])
    ft_4_tags = locate_feature(sent_syllables, stat_ft_set[2], stat_ft_schema[2])
    ft_5_tags = locate_feature(sent_syllables, stat_ft_set[3], stat_ft_schema[3])

    # 词向量特征（6~8/x~z），包含多列特征标签
    # ft_x_tags = locate_feature_wv(sent_syllables, wvec_ft_set[0], wvec_ft_schema[0])
    # ft_y_tags = locate_feature_wv(sent_syllables, wvec_ft_set[1], wvec_ft_schema[1])
    # ft_z_tags = locate_feature_wv(sent_syllables, wvec_ft_set[2], wvec_ft_schema[2])

    syllable_tag_schema = []
    for i in range(len(sent_syllables)):
        syllable_tag_schema.append([ft_2_tags[i][1], ft_3_tags[i][1], ft_4_tags[i][1], ft_5_tags[i][1]])
        # syllable_tag_schema.append([ft_2_tags[i][1], ft_3_tags[i][1], ft_4_tags[i][1], ft_5_tags[i][1],\
        #                  ft_x_tags[i][1], ft_y_tags[i][1], ft_z_tags[i][1]])
    return syllable_tag_schema


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
        open(raw_format_file + '.final', 'w', encoding='utf-8') as fout:
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


def split_wv_word_feature(wv_feature):
    word_features = []
    for line in wv_feature:
        line = line.strip().split()
        word_features.append([line[0], ' '.join(line[1:])])
    return word_features


if __name__ == "__main__":
    """ """
    ### 定义输入和输出文件名
    # just for test
    # raw_file = r'.\ner_data\tb_per_data\mini-test.txt'
    # tag_file = r'.\ner_data\tb_per_data\mini-test.lbd'
    raw_file = r'.\ner_data\tb_per_data\tb_per.data'
    tag_file = r'.\ner_data\tb_per_data\tb_per.lbd'

    ### 定义实体特征集路径及标签方案
    # column: 2, feature: 格助词特征, code: CAX-Y,CAX-N
    ft_set_2 = read_feature_set(r'.\ne_feature\tibetan_case_auxiliary_words.txt')
    ft_2_schema = ['CAX-Y', 'CAX-N']
    # column: 3, feature: 藏族人名高频音节, code: THF-Y,THF-N
    ft_set_3 = read_feature_set(r'.\ne_feature\tibetan_person_tibetan_hfw.txt')
    ft_3_schema = ['THF-Y', 'THF-N']
    # column: 4, feature: 汉族姓氏高频音节, code: CHF-Y,CHF-N
    ft_set_4 = read_feature_set(r'.\ne_feature\tibetan_person_chinese_surname.txt')
    ft_4_schema = ['CHF-Y', 'CHF-N']
    # column: 5, feature: 人名称谓词, code: TLT-Y,TLT-N
    ft_set_5 = read_feature_set(r'.\ne_feature\tibetan_person_titles.txt')
    ft_5_schema = ['TLT-Y', 'TLT-N']
    # column: 6, feature: 词向量聚类类别, code: [0,N),CLS-X
    ft_set_6 = read_feature_set(r'.\ne_feature\wv_kmeans_feature5.txt')
    ft_6_schema = 'CLS-X'
    # column: 7, feature: 词向量相似词, code: word,SMW-X
    ft_set_7 = read_feature_set(r'.\ne_feature\wv_simword_feature.txt')
    ft_7_schema = 'SMW-X'
    # column: 8, feature: 词向量二值化特征, code: P/N/O,BIN-X
    ft_set_8 = read_feature_set(r'.\ne_feature\wv_binary_feature.txt')
    ft_8_schema = 'BIN-X'

    ### 读取原始训练文本
    sent_list = read_raw_file(raw_file)

    ### 拼装统计特征集及标签方案
    stat_ft_set = [ft_set_2, ft_set_3, ft_set_4, ft_set_5]
    stat_ft_schema = [ft_2_schema, ft_3_schema, ft_4_schema, ft_5_schema]

    ### 拼装词向量特征集及标签方案
    wvec_feature_6 = split_wv_word_feature(ft_set_6)
    wvec_feature_7 = split_wv_word_feature(ft_set_7)
    wvec_feature_8 = split_wv_word_feature(ft_set_8)

    wvec_ft_set = [wvec_feature_6, wvec_feature_7, wvec_feature_8]
    wvec_ft_schema = [ft_6_schema, ft_7_schema, ft_8_schema]

    ### 进行特征标注
    with open(tag_file, 'w', encoding='utf-8') as fout:
        for sent_syllable_tag in sent_list:
            # 分离句子的音节和音节对应的实体标签
            sent_syllables = sent_syllable_tag[0]
            sent_tags = sent_syllable_tag[-1]
            # 获取实体特征标注方案（关键步骤）
            syllable_tag_schema = get_sent_tag(sent_syllables, stat_ft_set, stat_ft_schema, wvec_ft_set, wvec_ft_schema)
            # 进行特征标注拼接
            for index, syllable in enumerate(sent_syllables):
                # 将音节的特征标签拼接成一行
                line = syllable + ' ' + ' '.join(syllable_tag_schema[index])
                # 将音节的实体标签追加到最后一列
                line += ' ' + sent_tags[index] + '\n'
                # 输出到文件
                fout.write(line)
                # 输出调试信息
                print('[Debug]\t' + line)
            fout.write("\n")

    ### 追加实体位置特征，放置于紧跟实体之后
    # column: 1, feature: 位置特征, code: POS-(0-N)
    syll_pos_feature(tag_file)

    ### <<< 完成标注 <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<