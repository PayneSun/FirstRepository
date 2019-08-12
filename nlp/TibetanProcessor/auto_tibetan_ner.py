'''
    auto_tibetan_ner.py

'''


import os
import MyTools


def list_dir(path, list_name):
    """
    从指定文件目录中生成文件名列表
    """
    for file in os.listdir(path):
        file_path = os.path.join(path, file)
        if os.path.isdir(file_path):
            list_dir(file_path, list_name)
        else:
            list_name.append(file_path)


def para_to_sents(para_str):
    """
    将藏文段落转换成句子列表
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


def word_to_iob2(word):
    """
        Convert a string into IOB format
    """
    char_list = []

    if '/' in word:
        tag_list = word.strip().split('/')
        prefix_list = word_to_sylls(tag_list[0])
        suffix_tag = tag_list[-1].strip()
        for i, ch in enumerate(prefix_list):
            if i == 0:
                char_list.append(ch + ' B-' + suffix_tag + '\n')
            else:
                char_list.append(ch + ' I-' + suffix_tag + '\n')
    else:
        char_list = word_to_sylls(word.strip())
        char_list = [ch + ' O\n' for ch in char_list if len(ch)]

    return ''.join(char_list)


def word_to_sylls(word):
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


def get_ner_from_file(raw_file_name, output_file):
    """
        Get ner from raw file.
    """
    with open(raw_file_name, 'r', encoding="utf-16-le") as fin, \
            open(output_file, 'a+', encoding="utf-16-le") as fout:
        fout.write(raw_file_name + ' O\n')  # debug
        for para in fin:
            if para.strip(): # 剔除空行
                print('[Debug:135]', end='\t')
                print(para)
                sent_list = para_to_sents(para.strip())
                print('[Debug:137]', end='\t')
                print(sent_list)
                for line in sent_list:
                    line = line.strip().split()
                    for word in line:
                        std_line = word_to_iob2(word)
                        fout.write(std_line)
                    fout.write('\n')


def auto_tag(dir_path, format_output='output.txt'):

    # step-1: 抽取文件名列表
    file_list = []
    list_dir(dir_path, file_list)

    # step-2: 将目录下的文件汇聚成单个文件
    single_file = 'singleton.txt'
    with open(single_file, 'w', encoding='utf-8') as fout:
        for file_name in file_list:
            fin = open(file_name, 'r', encoding='utf-8')
            fout.write(file_name + '\n')
            for line in fin:
                fout.write(line)
            fin.close()

    # step-3: 将文件格式化成CRF能识别的格式
    crf_type_file = 'crf_format.txt'
    get_ner_from_file(single_file, crf_type_file)

    # step-4: 对CRF格式文件标注特征

    # step-5: 利用CRF模型进行实体识别

    # step-6: 抽取CRF标注结果


if __name__ == "__main__":

    # dir_path = r"E:\tibetan-ner"
    dir_path = ".\\data\\fwg-tibetan"


    file_list = []
    list_dir(dir_path, file_list)
    print(file_list)

    # out_file = "tibetan_raw.txt"
    out_file = "fwg-tibetan.txt"
    fout = open(out_file, 'w', encoding='utf-16-le')

    for file_name in file_list:

        fin = open(file_name, 'r', encoding='utf-16-le')

        fout.write(file_name + '\n')
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