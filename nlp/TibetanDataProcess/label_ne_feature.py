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


def match_sylls(sent_syll_list, nf_syll_list):
    """"""
    nf_len = len(nf_syll_list)
    sent_len = len(sent_syll_list)

    pos_list = []
    nf_sylls = ''.join(nf_syll_list)
    for i in range(sent_len - nf_len):
        sent_sylls = ''.join(sent_syll_list[i:i+nf_len])
        if sent_sylls == nf_sylls:
            for j in range(nf_len):
                pos_list.append([i+j, 1])

    return pos_list


def locate_feature(sent_syll_list, nf_list):
    """
    :param sentence : 句子
    :param nf_list  : 特征列表
    :return         : 在句子中特征的位置及特征的长度
    """
    pos_len_list = []
    # sent_syll_list = sent_2_sylls(sentence)

    # print(sent_syll_list)
    # print(nf_list)

    for nf in nf_list:
        nf_syll_list = sent_2_sylls(nf)
        pos_list = match_sylls(sent_syll_list, nf_syll_list)
        pos_len_list.extend(pos_list)

    pos_len_list.sort(key=lambda x: x[0])

    tag_schema = []
    pos_list = [pos_len[0] for pos_len in pos_len_list]
    for i in range(len(sent_syll_list)):
        if i in pos_list:
            tag_schema.append([i, 1])
        else:
            tag_schema.append([i, 0])

    return tag_schema


def read_raw_file(input_file):
    """
        读取无特征的语料、抽取音节-标签列表
    :param input_file : 无特征音节级训练
    :return           : 音节-标签分离的句子列表
    """
    sent_list = []
    with open(input_file, "r", encoding="utf-8") as fin:
        sent_syll = []; sent_tags = []
        for syll_tag in fin:
            syll_tag = syll_tag.strip().split()
            if len(syll_tag):
                # syll_tag = syll_tag.split()
                sent_syll.append(syll_tag[0])
                sent_tags.append(syll_tag[-1])
            else:
                sent_list.append([sent_syll, sent_tags])
                sent_syll = []; sent_tags = []
        sent_list.append([sent_syll, sent_tags])
    return sent_list


def get_sent_fset_tag(sent_syll_list, fset_1, fset_2, fset_3, fset_4, fset_5, fset_6):
    """
        句子的音节粒度特征标注
    :param sent_syll_list: 句子音节列表
    :param fset_1        : 特征1
    :param fset_2        : 特征1
    :param fset_3        : 特征1
    :param fset_4        : 特征1
    :param fset_5        : 特征1
    :param fset_6        : 特征1
    :return              : 句子的音节粒度特征标注
    """
    fset_1_tag = locate_feature(sent_syll_list, fset_1)
    fset_2_tag = locate_feature(sent_syll_list, fset_2)
    fset_3_tag = locate_feature(sent_syll_list, fset_3)
    fset_4_tag = locate_feature(sent_syll_list, fset_4)
    fset_5_tag = locate_feature(sent_syll_list, fset_5)
    fset_6_tag = locate_feature(sent_syll_list, fset_6)

    fset_tag = []
    for i in range(len(fset_1_tag)):
        fset_tag.append([str(fset_1_tag[i][1]),
                         str(fset_2_tag[i][1]),
                         str(fset_3_tag[i][1]),
                         str(fset_4_tag[i][1]),
                         str(fset_5_tag[i][1]),
                         str(fset_6_tag[i][1])])
    return fset_tag


if __name__ == "__main__":
    # 加载藏族人名高频音节表：TPHF
    fset_1 = read_feature_set(".\\ne_feature\\tibetan_high_frequency_syllable.txt")
    # 加载汉族人名高频音节表: CPHF
    fset_2 = read_feature_set(".\\ne_feature\\chinese_high_frequency_syllable.txt")
    # 加载汉族姓氏高频音节表: CSHF
    fset_3 = read_feature_set(".\\ne_feature\\chinese_surname_syllable.txt")
    # 加载人名称谓词表：
    fset_4 = read_feature_set(".\\ne_feature\\per_title.txt")
    # 加载地名称谓词表
    fset_5 = read_feature_set(".\\ne_feature\\loc_title.txt")
    # 加载组织机构名称谓词表
    fset_6 = read_feature_set(".\\ne_feature\\org_title.txt")

    # sentence = "ཁྲེན་ཆོན་གོས་ལྷ་སར་དུས་ཆེན་རིང་ལས་གནས་བརྟན་སྲུང་བྱེད་མཁན་འཐབ་ས་དང་པོའི་བཟོ་པ་དང་ལས་རིགས་ཁག་གི་མང་ཚོགས་ལ་གཟིགས་པ།"

    raw_file_list = ["raw_input.txt", "tibetan-train.data", "tibetan-test.data", "tibetan_dataset.ld.pure"]
    tag_file_list = ["tag_output.txt", "tibetan-train.data.ftag", "tibetan-test.data.ftag", "tibetan_dataset.ld.ftag"]

    #---------------#
    selectedIndex = 2
    # --------------#

    raw_file = raw_file_list[selectedIndex]
    tag_file = tag_file_list[selectedIndex]

    sent_list = read_raw_file(raw_file)

    with open(tag_file, "w", encoding="utf-8") as fout:
        for sent_tag in sent_list:
            sent_syll_list = sent_tag[0]
            sent_tags_list = sent_tag[-1]
            fset_tag = get_sent_fset_tag(sent_syll_list, fset_1, fset_2, fset_3, fset_4, fset_5, fset_6)

            print(len(sent_syll_list),end=" ")
            print(sent_syll_list)
            print(len(sent_tags_list), end=" ")
            print(sent_tags_list)

            for index, syll in enumerate(sent_syll_list):
                line = syll + " "
                line += " ".join(fset_tag[index])
                line += " " + sent_tags_list[index]
                fout.write(line + "\n")
            fout.write("\n")
