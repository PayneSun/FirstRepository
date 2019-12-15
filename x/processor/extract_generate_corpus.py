# coding:utf-8

"""

    Parse file path and extract valid labeled data.

    generate_corpus.py

    2018/10/16
"""


import os
import re


def batch_rename(file_path):
    # file_path = r'.\130'
    for i,f in enumerate(os.listdir(file_path)):
        print(f)
        # num = int(re.findall(re.compile(r'\d+'), f)[0])
        if i+1 < 10:
            new_file = 'NW_ABA_2016_' + '_00' + str(i+1) + '.txt'
        elif i+1 < 100:
            new_file = 'NW_ABA_2016_' + '_0' + str(i+1) + '.txt'
        else:
            new_file = 'NW_ABA_2016_' + '_' + str(i+1) + '.txt'
        os.rename(os.path.join(file_path, f), os.path.join(file_path, new_file))


def get_content(file_name, mode='all'):
    """
    获取指定文件名的文件内容
    """
    text = []
    with open(file_name, 'r', encoding='utf-8') as frd:
        for line in frd:
            line = line.strip()
            if line:
                text.append(line)
    # return ''.join(text)
    return text[0]


def duplicate(file_path):
    """
    删除内容重复的文件
    """
    file_list = []
    for file in os.listdir(file_path):
        file_list.append([file,get_content(file_path + '\\' + file)])

    file_list.sort(key=lambda x:x[-1])

    deleted_list = []
    for index,file in enumerate(file_list):
        print(file[0],end='\n\t')
        print(file[1])

        if index != 0 and file_list[index-1][-1] == file[-1]:
            deleted_list.append(file[0])

    for file in deleted_list:
        print(file)
        os.remove(file_path + '\\' + file)

    # batch_rename(file_path)


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


def para_to_sentence(para_str):
    """
        para_str : one line of text
        sent_list: list of sentences
    """
    # print("[Debug]" + para_str)  # debug
    delimiter = {"།།", "།"}

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

    # 剔除不含命名实体的句子
    # new_sent_list = []
    # tags = ['PER', 'LOC', 'ORG']
    # for sent in sent_list:
    #     status = False
    #     for tag in tags:
    #         if sent.find(tag) != -1:
    #             status = True
    #     if status:
    #         new_sent_list.append(sent)
    #     else:
    #         continue
    # return new_sent_list


def word_to_iob2(word, stat_info):
    """
        Convert a string into IOB format
    """
    char_list = []

    if ("/PER" in word) or ("/LOC" in word) or ("/ORG" in word):
        tag_list = word.strip().split('/')
        prefix_list = word_to_syllable(tag_list[0])
        suffix_tag = tag_list[-1].strip()
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
    with open(raw_file_name, 'r', encoding="utf-8") as fin, open(output_file, 'a+', encoding="utf-8") as fout:
        fout.write(raw_file_name + " O\n\n")  # debug
        for para in fin:
            if para.strip(): # 剔除空行
                print('[Debug:135]', end='\t')
                print(para)
                sent_list = para_to_sentence(para.strip())
                print('[Debug:137]', end='\t')
                print(sent_list)
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
            open(data_with_filename + '.pure', 'w', encoding="utf-8") as fout:
        for line in fin:
            if '.txt' not in line:
                print(line)
                fout.write(line)
    print("Finish task!!")


def deleteSentPos(sent):
    """
    """
    sent = sent.strip().split()
    for index,word in enumerate(sent):
        word = word.strip().split('/')
        sent[index] = word[0]

    return ' '.join(sent)


def extract_raw_text(file_path):
    """
    """
    out_file = 'tibetan.seg.txt'

    file_names = []
    list_dir(file_path, file_names)

    sent_lists = []
    # with open(out_file + '.tmp', 'a+', encoding='utf-8') as fout:
    for file in file_names:
        with open(file, 'r', encoding='utf-8') as frd:
            for line in frd:
                line = line.strip()
                if line != '':
                    # line = [deleteSentPos(sent) for sent in para_to_sentence(line)]
                    line = [sent for sent in para_to_sentence(line)]
                    sent_lists.extend(line)
                        # fout.write('\n'.join(line) + '\n')
                    print('\n'.join(line))

    # 后处理：剔除单锤符和重复的行
    post_sent_lists = []
    for index,sent in enumerate(sent_lists):
        if index == 0:
            post_sent_lists.append(sent)
            continue
        if sent == '།':
            post_sent_lists[-1] = post_sent_lists[-1] + sent
        elif sent != post_sent_lists[-1]:
            post_sent_lists.append(sent)

    # 写出到文件中
    with open(out_file, 'w', encoding='utf-8') as fout:
        for index,line in enumerate(post_sent_lists):
            if line.strip():
                fout.write(line.strip() + '\n')


if __name__ == "__main__":

    # 生成纯文本
    # file_path = r".\TibetanNeDataSet"
    # extract_raw_text(file_path)

    # 生成NER语料
    file_path = r".\TibetanNeDataSet"
    get_ner_in_patch(file_path, "tibetan.ne.data")
