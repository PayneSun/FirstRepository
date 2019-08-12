# -*- coding:utf-8 -*-

"""
    综合工具库

    MyTools.py
"""

import os


class Utility(object):
    def __init__(self):
        # self.__input_file
        pass

    @staticmethod
    def tibetan_sentence_segment(para_str, delimiter={'།'}):
        """
        基于藏文标点符号切分段落到句子，返回句子列表
        """
        mono_sent = ''
        sent_list = []
        for i in range(len(para_str)):
            mono_sent += para_str[i]
            if para_str[i] in delimiter:
                if i == len(para_str) - 1:
                    sent_list.append(mono_sent)
                    mono_sent = ''
                else:
                    if para_str[i + 1] not in delimiter:
                        sent_list.append(mono_sent)
                        mono_sent = ''
            else:
                if i == len(para_str) - 1:
                    sent_list.append(mono_sent)
                    mono_sent = ''
        if len(mono_sent) > 0:
            sent_list.append(mono_sent)

        return sent_list


    @staticmethod
    def get_specified_columns(src_file, task_list, seg_tag=' '):
        '''
        从包含多列的文件中选择特定的列，生成新文件
        '''
        with open(src_file, 'r', encoding='utf-8') as fsrc,\
            open(src_file + '.new', 'w', encoding='utf-8') as fout:
            for line in fsrc:
                line = line.strip().split(seg_tag)
                if len(line) >= len(task_list):
                    new_line = []
                    for index in task_list:
                        new_line.append(line[index])
                    fout.write(seg_tag.join(new_line) + '\n')
                elif len(line) < 2:
                    fout.write(' '.join(line) + '\n')

    @staticmethod
    def count_word_frequency(src_file, seg_tag=' '):
        '''
        基于切分粒度，统计字/词/音节等频次并降序输出
        '''
        # step-1: 获取词表及排序（包含重复）
        words = []
        with open(src_file, 'r', encoding='utf-8') as fin:
            for line in fin:
                line = line.strip().split(seg_tag)
                words.append([word for word in line])
        words.sort()

        # step-2: 统计词频（不含重复）
        word_unit = []
        word_nums = []
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

        # step-3: 生成词-频次对
        word_cnts = []
        for unit,num in zip(word_unit, word_nums):
            word_cnts.append([unit, num])
        word_cnts.sort(key=lambda x: x[-1], reverse=True)

        # step-4: 写出到文件中
        with open(src_file + '.new', 'w', encoding='utf-8') as fout:
            for word_num in word_cnts:
                fout.write(word_num[0] + seg_tag + word_num[-1] + '\n')


class LabelNamedEntityFeature:
    __input_file = ''
    __output_file = ''

    def __init__(self, input, output):
        self.__input_file = input
        self.__output_file = output


    @staticmethod
    def read_feature_set(self, feature_file):
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

    @staticmethod
    def sent_2_sylls(self, word):
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
                    if word[i + 1] not in delimiter:
                        syllable_list.append(mono_syllable)
                        mono_syllable = ''
            else:
                if i == len(word) - 1:
                    syllable_list.append(mono_syllable)
                    mono_syllable = ''
        if len(mono_syllable) > 0:
            syllable_list.append(mono_syllable)

        return syllable_list


    @staticmethod
    def match_sylls(self, sent_syll_list, nf_syll_list):
        """"""
        nf_len = len(nf_syll_list)
        sent_len = len(sent_syll_list)

        pos_list = []
        nf_sylls = ''.join(nf_syll_list)
        for i in range(sent_len - nf_len):
            sent_sylls = ''.join(sent_syll_list[i:i + nf_len])
            if sent_sylls == nf_sylls:
                for j in range(nf_len):
                    pos_list.append([i + j, 1])

        return pos_list

    @staticmethod
    def match_sylls_m(self, sent_syll_list, nf_syll_list, id):
        """"""
        nf_len = len(nf_syll_list)
        sent_len = len(sent_syll_list)

        pos_list = []
        nf_sylls = ''.join(nf_syll_list)
        for i in range(sent_len - nf_len):
            sent_sylls = ''.join(sent_syll_list[i:i + nf_len])
            if sent_sylls == nf_sylls:
                for j in range(nf_len):
                    pos_list.append([i + j, id])

        return pos_list

    @staticmethod
    def locate_feature(self, sent_syll_list, nf_list):
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
            nf_syll_list = self.sent_2_sylls(nf)
            pos_list = self.match_sylls(sent_syll_list, nf_syll_list)
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


    @staticmethod
    def locate_feature_m(self, sent_syll_list, nfm_list):
        """
        :param sentence : 句子
        :param nf_list  : 特征列表
        :return         : 在句子中特征的位置及特征的长度
        """
        nf_list = []
        tag_list = []
        for line in nfm_list:
            line = [ele.strip() for ele in line.split('\t')]
            nf_list.append(line[0])
            tag_list.append(line[-1])

        pos_len_list = []
        for id, nf in enumerate(nf_list):
            nf_syll_list = self.sent_2_sylls(nf)
            pos_list = self.match_sylls_m(sent_syll_list, nf_syll_list, id)
            pos_len_list.extend(pos_list)
        pos_len_list.sort(key=lambda x: x[0])

        tag_schema = []
        pos_list = [pos_len[0] for pos_len in pos_len_list]
        ids_list = [pos_len[-1] for pos_len in pos_len_list]
        for i in range(len(sent_syll_list)):
            if i in pos_list:
                ps = pos_list.index(i)
                id = ids_list[ps]
                tag = tag_list[id]
                tag_schema.append([i, tag])
            else:
                tag_schema.append([i, '0'])

        return tag_schema


    def read_raw_file(self, input_file):
        """
            读取无特征的语料、抽取音节-标签列表
        :param input_file : 无特征音节级训练
        :return           : 音节-标签分离的句子列表
        """
        sent_list = []
        with open(input_file, "r", encoding="utf-8") as fin:
            sent_syll = []
            sent_tags = []
            for syll_tag in fin:
                syll_tag = syll_tag.strip().split()
                if len(syll_tag):
                    # syll_tag = syll_tag.split()
                    sent_syll.append(syll_tag[0])
                    sent_tags.append(syll_tag[-1])
                else:
                    sent_list.append([sent_syll, sent_tags])
                    sent_syll = [];
                    sent_tags = []
            sent_list.append([sent_syll, sent_tags])
        return sent_list


    def get_sent_fset_tag(self, sent_syll_list, fset_1, fset_2, fset_3, fset_4, fset_5, fset_6, fset_7):
        fset_1_tag = self.locate_feature(sent_syll_list, fset_1)
        fset_2_tag = self.locate_feature(sent_syll_list, fset_2)
        fset_3_tag = self.locate_feature(sent_syll_list, fset_3)
        fset_4_tag = self.locate_feature(sent_syll_list, fset_4)
        fset_5_tag = self.locate_feature(sent_syll_list, fset_5)
        fset_6_tag = self.locate_feature(sent_syll_list, fset_6)
        fset_7_tag = self.locate_feature(sent_syll_list, fset_7)

        # fset_x_tag = locate_feature_m(sent_syll_list, fset_x)
        # fset_y_tag = locate_feature_m(sent_syll_list, fset_y)
        # fset_z_tag = locate_feature_m(sent_syll_list, fset_z)

        fset_tag = []
        for i in range(len(fset_1_tag)):
            fset_tag.append([str(fset_1_tag[i][1]),
                             str(fset_2_tag[i][1]),
                             str(fset_3_tag[i][1]),
                             str(fset_4_tag[i][1]),
                             str(fset_5_tag[i][1]),
                             str(fset_6_tag[i][1]),
                             str(fset_7_tag[i][1])])
            # fset_x_tag[i][1],
            # fset_y_tag[i][1]])
        return fset_tag

    def label_ne(self):

        # 格助词特征
        f_set_1 = self.read_feature_set('.\\ne_feature\\tibetan_case_auxiliary_words.txt')
        # 藏族人名高频音节
        f_set_2 = self.read_feature_set('.\\ne_feature\\tibetan_person_name_high_frequency_syllables.txt')
        # 汉族人名高频音节
        f_set_3 = self.read_feature_set('.\\ne_feature\\tibetan_chinese_person_high_frequency_syllables.txt')
        # 汉族人名姓氏音节
        f_set_4 = self.read_feature_set('.\\ne_feature\\tibetan_chinese_surname_syllables.txt')
        # 人名称谓词
        f_set_5 = self.read_feature_set('.\\ne_feature\\tibetan_person_name_titles.txt')
        # 地名称谓词
        f_set_6 = self.read_feature_set('.\\ne_feature\\tibetan_location_name_titles.txt')
        # 组织机构名称谓词
        f_set_7 = self.read_feature_set('.\\ne_feature\\tibetan_organization_name_titles.txt')

        # 词向量聚类特征
        # f_set_x = read_feature_set(".\\ne_feature\\kmeans_feature.txt")
        # 词向量相似词特征
        # f_set_y = read_feature_set(".\\ne_feature\\simword_feature.txt")
        # 词向量二值化特征
        # f_set_z = read_feature_set(".\\ne_feature\\binary_feature.txt")

        sent_list = self.read_raw_file(self.__input_file)

        with open(self.__output_file, 'w', encoding='utf-8') as fout:
            for sent_tag in sent_list:
                # print(sent_tag)
                sent_syll_list = sent_tag[0]
                sent_tags_list = sent_tag[-1]
                fset_tag = self.get_sent_fset_tag(sent_syll_list, \
                                                  f_set_1, f_set_2, f_set_3, f_set_4, f_set_5, f_set_6, f_set_7)

                # print(len(sent_syll_list),end=" ")
                # print(sent_syll_list)
                # print(len(sent_tags_list), end=" ")
                # print(sent_tags_list)

                for index, syll in enumerate(sent_syll_list):
                    line = syll + " "
                    line += " ".join(fset_tag[index])
                    line += " " + sent_tags_list[index]
                    print('[Debug] ' + line)
                    fout.write(line + "\n")
                fout.write("\n")


if __name__ == '__main__':

    # 1
    # raw_file = '.\\data\\crf_input.tmp'
    # tag_file = '.\\data\\crf_input.tmp.ld.new'

    # 2
    raw_file = 'fwg_tibetan.txt.ld.sc'
    tag_file = 'fwg_tibetan.txt.ld.sc.new'

    # 标注特征：
    # lnef = LabelNamedEntityFeature(raw_file, tag_file)
    # lnef.label_ne()

    # 基于标注特征的结果抽取符合模型输入的列
    tool = Utility()
    # src_file = 'fwg-data2.txt.mf.final'
    # tool.get_specified_columns(src_file, list(range(6)))

    # 后处理：将标注结果提取出来
    src_file = 'fwg-data2-ret.txt'
    tool.get_specified_columns(src_file, [0,-1], '\t')

