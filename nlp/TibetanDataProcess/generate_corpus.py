#coding:utf-8

"""

    Parse file path and extract valid labeled data.

    generate_corpus.py

    2018/10/16
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


def word_to_syllable(word):
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


def para_to_sentence(para_str):
    """
        para_str : one line of text
        sent_list: list of sentences
    """
    print("[Debug]" + para_str)  # debug
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
                if para_str[i+1] not in delimiter:
                    sent_list.append(mono_sent)
                    mono_sent = ''
        else:
            if i == len(para_str) - 1:
                sent_list.append(mono_sent)
                mono_sent = ''
    if len(mono_sent) > 0:
        sent_list.append(mono_sent)

    return sent_list


def word_to_iob2(word, stat_info):
    """
        Convert a string into IOB format
    """
    char_list = []

    if '/' in word:
        tag_list = word.strip().split('/')
        prefix_list = word_to_syllable(tag_list[0])
        suffix_tag = tag_list[-1].strip()
        # suffix_tag = ''.join([ch for ch in suffix_tag if ch in 'PERGLC'])
        for i, ch in enumerate(prefix_list):
            if i == 0:
                char_list.append(ch + ' B-' + suffix_tag + '\n')
                if suffix_tag in {'PER', 'ORG', 'LOC'}:
                    stat_info['n_' + suffix_tag] += 1
            else:
                char_list.append(ch + ' I-' + suffix_tag + '\n')
    else:
        char_list = word_to_syllable(word.strip())
        char_list = [ch + ' O\n' for ch in char_list if len(ch)]

    return ''.join(char_list)


def get_ner_from_file(raw_file_name, output_file, stat_info):
    """
        Get ner from raw file.
    """
    with open(raw_file_name, 'r', encoding="utf-8") as fin, \
            open(output_file, 'a+', encoding="utf-8") as fout:
        fout.write(raw_file_name + ' O\n')  # debug
        for para in fin:
            sent_list = para_to_sentence(para.strip())
            for line in sent_list:
                line = line.strip().split()
                for word in line:
                    std_line = word_to_iob2(word, stat_info)
                    fout.write(std_line)
                fout.write('\n')
                stat_info['n_sent'] += 1


def get_ner_in_patch(ner_file_dir, output_file):
    """
        Get formatted labeled file in patch.
    """
    file_list = []
    list_dir(ner_file_dir, file_list)

    stat_info = {'n_text': 0, 'n_sent': 0, 'n_PER': 0, 'n_LOC': 0, 'n_ORG': 0}

    for file_name in file_list:
        stat_info['n_text'] += 1
        get_ner_from_file(file_name, output_file, stat_info)

    print("<----------------------->")
    for key in stat_info:
        print("\t" + key + ":" + str(stat_info[key]))
    print("<----------------------->")


def delete_filename_in_data(data_with_filename):
    """
        删除文件中的文件名
    """
    with open(data_with_filename, 'r', encoding="utf-8") as fin, \
        open(data_with_filename + '.ftd', 'w', encoding="utf-8") as fout:
        for line in fin:
            if '.txt' not in line:
                print(line)
                fout.write(line)
    print("Finish task!!")




#++++++++++++++++++++++++++++

# 生成语料
# get_ner_in_patch("E:\\tibetan-ner", 'tibetan-data-ld.out')

# 剔除文件名
delete_filename_in_data('tibetan-data-ld.out')
