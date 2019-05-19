"""
    藏文命名实体识别算法（基于CRF）

    crf.py

    2019/4/9
"""

import os
import threading
from subprocess import Popen, PIPE


def tagger(raw_text):
    ret_list = []
    mt = MyThread(raw_text, ret_list)
    mt.start()
    mt.join()

    return ret_list[0]


def tagging_data(raw_text, ret_list):
    crf = CRF(raw_text)
    crf.tagger()
    out_str = crf.output()

    ret_list.append(out_str)


class MyThread(threading.Thread):
    def __init__(self, raw_text, ret_list):
        threading.Thread.__init__(self)
        self.raw_text = raw_text
        self.ret_list = ret_list

    def run(self):
        print("[Debug] 开始标注...")
        tagging_data(self.raw_text, self.ret_list)
        print("[Debug] 标注结束!!!")


class CRF():
    def __init__(self, raw_text):
        self.raw_text = raw_text

    def text_2_para(self):
        self.raw_text = self.raw_text.replace("\r\n", "\n")
        raw_text_list = self.raw_text.split("\n")
        para_list = [line for line in raw_text_list if not line.isspace()]
        return para_list

    def para_2_sent(self, para):
        delimiter = {'།'}

        mono_sent = ''
        sent_list = []
        for i in range(len(para)):
            mono_sent += para[i]
            if para[i] in delimiter:
                if i == len(para) - 1:
                    sent_list.append(mono_sent)
                    mono_sent = ''
                else:
                    if para[i + 1] not in delimiter:
                        sent_list.append(mono_sent)
                        mono_sent = ''
            else:
                if i == len(para) - 1:
                    sent_list.append(mono_sent)
                    mono_sent = ''
        if len(mono_sent) > 0:
            sent_list.append(mono_sent)

        return sent_list

    def sent_2_syllable(self, sent):
        syllable_list = sent.split('་')

        len_sl = len(syllable_list)
        for index in range(len_sl):
            if index != (len_sl - 1):
                syllable_list[index] += '་\n'
            else:
                syllable_list[index] += '\n\n'

        return syllable_list

    def doc_2_crf_input(self):
        print("[Debug]")
        print(self.raw_text)

        ftmp = open(r".\tempdata\crf_input.tmp", 'w', encoding="utf-8")
        para_list = self.text_2_para()
        for para in para_list:
            sent_list = self.para_2_sent(para)
            for sent in sent_list:
                syllable_list = self.sent_2_syllable(sent)
                ftmp.write(''.join(syllable_list))
        ftmp.close()

    def tagger(self):
        self.doc_2_crf_input()

        cmd_str = r".\model\crf_test.exe -m .\model\crf_model .\tempdata\crf_input.tmp > .\tempdata\crf_result.tmp"
        os.popen(cmd_str)

        # cmd_str_test = "ipconfig"
        # 方法一
        # pstr = os.popen(cmd_str_test)
        # return pstr.read()
        # 方法二
        # os.system(cmd_str_test)
        # p = Popen(cmd_str, shell=True, stdout=PIPE, stderr=PIPE)
        # p.wait()

    def output(self):
        ne_tag = [['B-PER', 'I-PER'],
                  ['B-LOC', 'I-LOC'],
                  ['B-ORG', 'I-ORG']]

        ne_list = [[], [], []]
        with open(r".\tempdata\crf_result.tmp", "r", encoding="utf-8") as fin:
            for syll_tag in fin:
                syll_tag = syll_tag.strip().split("\t")
                if len(syll_tag):
                    if syll_tag[-1] in ne_tag[0]:
                        ne_list[0].append(syll_tag)
                    elif syll_tag[-1] in ne_tag[1]:
                        ne_list[1].append(syll_tag)
                    elif syll_tag[-1] in ne_tag[2]:
                        ne_list[2].append(syll_tag)

        # print("[debug]", end=" ")
        # print(ne_list)

        ne_ret = [[], [], []]
        for ne_type in range(len(ne_list)):
            ne_sylls = ""
            for index, elem in enumerate(ne_list[ne_type]):
                if elem[-1] == ne_tag[1][0]:
                    if index != 0:
                        ne_ret[ne_type].append(ne_sylls)
                        ne_sylls = elem[0]
                    else:
                        ne_sylls += elem[0]
                else:
                    ne_sylls += elem[0]
            ne_ret[ne_type].append(ne_sylls)

        # print("[debug]", end=" ")
        # print(ne_ret)

        ne_dict = {}
        ne_dict["PER"] = ne_ret[0]
        ne_dict["LOC"] = ne_ret[1]
        ne_dict["ORG"] = ne_ret[2]

        ret_str = ""
        for ne in ne_dict.keys():
            ret_str += ne + "："
            for index, word in enumerate(ne_dict[ne]):
                if index != len(ne_dict[ne]) - 1:
                    ret_str += word + " / "
                else:
                    ret_str += word
            ret_str += "\n\n"

        return ret_str
