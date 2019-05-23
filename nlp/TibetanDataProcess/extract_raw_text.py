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

    return [sent.strip() for sent in sent_list if len(sent.strip())]


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


if __name__ == "__main__":

    dir_path = r"E:\tibetan-ner"

    file_list = []
    list_dir(dir_path, file_list)
    # print(file_list)

    out_file = "tibetan_raw.txt"
    fout = open(out_file, 'w', encoding='utf-8')

    for file_name in file_list:
        fin = open(file_name, 'r', encoding='utf-8')
        for para in fin:
            line = delete_entity_label(para)
            print('[Debug]', line)
            fout.write(line)

            # sent_list = para_to_sents(para)
            # for line in sent_list:
            #     line = delete_entity_label(line)
            #     print('[Debug]', line)
            #     fout.write(line)
    fout.close()