# coding:utf-8

"""
    从指定目录中获取文本，写到单个文件中

    2019/5/11
"""


import os


def list_dir(path, list_name):
    """"
        Parse specified file directory and get file name list
        path: file path
        list_name: returned file name list
    """
    for file in os.listdir(path):
        file_path = os.path.join(path, file)
        if os.path.isdir(file_path):
            list_dir(file_path, list_name)
        else:
            list_name.append(file_path)


def para_to_sents(para_str):
    """
        para_str : one line of text
        sent_list: list of sentences
    """
    delimiter = {'།'}

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

    return [sent.strip() for sent in sent_list if sent.strip()]


def word_to_syllables(word):
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


def delete_entity_label(sent):
    labels = ['/PER', '/LOC', '/ORG']

    sent = sent.strip("\r\n").split()
    for index,word in enumerate(sent):
        for label in labels:
            if label in word:
                sent[index] = word[0:-4]
            else:
                pass
    return " ".join(sent) + "\n"


def merge_mono_file(dir_path, out_file):
    file_list = []
    list_dir(dir_path, file_list)

    # 将多个文件归并到单个文件中
    with open(out_file, 'w', encoding='utf-16-le') as fout:
        for file_name in file_list:
            fin = open(file_name, 'r', encoding='utf-16-le')
            # 写入文件名
            fout.write(file_name + '\n')

            for para in fin:
                # 方案一：按句子段落写入
                # line = delete_entity_label(para)
                # print('[Debug]', line)
                # fout.write(line)

                # 方案二：按音节写入
                sent_list = para_to_sents(para)
                print('[Debug] ', '\t'.join(sent_list))
                for line in sent_list:
                    syllables = word_to_syllables(line)
                    # print('[Debug] ', ' '.join(syllables))
                    fout.write('\n'.join(syllables) + '\n')
                fout.write('\n')

            # 关闭文件
            fin.close()


if __name__ == "__main__":

    # dir_path = r"E:\tibetan-ner"
    # dir_path = ".\\data\\fwg-tibetan-rawdata"
    dir_path = ".\\data\\fwg-data2"

    # out_file = "tibetan_raw.txt"
    # out_file = "fwg-tibetan.txt"
    out_file = "fwg-data2.txt"

    # 获得指定目录下的文件名列表
    file_list = []
    list_dir(dir_path, file_list)

    print(len(file_list))
    print('\n'.join(file_list))


    nsent = 0
    # 将多个文件归并到单个文件中
    with open(out_file, 'w', encoding='utf-8') as fout:
        for file_name in file_list:
            fin = open(file_name, 'r', encoding='utf-16-le').readlines()
            fin = [para.strip() for para in fin if para.strip()]
            # 写入文件名
            fout.write(file_name + '\n')

            for para in fin:
                # 方案一：按句子段落写入
                # line = delete_entity_label(para)
                # print('[Debug]', line)
                # fout.write(line)

                # 方案二：按音节写入
                # sent_list = para_to_sents(para)
                sent_list = [sent.strip() for sent in para.split() if sent.strip()]
                nsent = nsent + len(sent_list)
                print('[DebugX] ', '\n'.join(sent_list))
                for line in sent_list:
                    syllables = word_to_syllables(line)
                    print('[DebugY] ', '\n'.join(syllables))
                    fout.write('\n'.join(syllables) + '\n')
                    fout.write('\n')

            # 关闭文件
            # fin.close()
    print(nsent)
