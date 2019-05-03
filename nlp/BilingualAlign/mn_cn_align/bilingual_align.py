"""
    bilingual_align.py

    2019/1/22
    By Sun-Peng

"""

import copy


def text_2_paragraph(file_name):
    """
        将文本转化为段落列表
    """
    para_list = []
    with open(file_name, encoding='utf-8') as fin:
        for line in fin:
            line.replace("\r\n", "\n").strip()

            if not line.isspace():
                para_list.append(line.strip())
    # print("段落长度：", len(para_list))  # debug
    return para_list


def para_2_sents_en(para_str):
    """
        para_str : one line of text
        sent_list: list of sentences
    """
    print("[Debug]" + para_str)  # debug
    delimiter = {'!', '.', '?'}

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


def para_2_sents_tb(para_str):
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


def para_2_sents_mn(para):
    """
        将蒙文段落转化为句子列表
    """
    delimiter = {'᠃', '!', '?', '᠁'}

    sent_list = []
    mono_sent = ''
    for i in range(len(para)):
        mono_sent += para[i]
        if para[i] in delimiter:
            if i == len(para) - 1:
                sent_list.append(mono_sent)
                mono_sent = ''
            else:
                if para[i+1] not in delimiter:
                    sent_list.append(mono_sent)
                    mono_sent = ''
        else:
            if i == len(para) - 1:
                sent_list.append(mono_sent)
                mono_sent = ''
    if len(mono_sent) > 0:
        sent_list.append(mono_sent)

    # print("句子长度：", len(sent_list))  #debug
    return sent_list


def para_2_sents_cn(para):
    """
        将中文段落转化为句子列表
    """
    delimiter = {'。', '！', '？', '……'}

    sent_list = []
    mono_sent = ''
    for i in range(len(para)):
        mono_sent += para[i]
        if para[i] in delimiter:
            if i == len(para) - 1:
                sent_list.append(mono_sent)
                mono_sent = ''
            else:
                if para[i+1] not in delimiter:
                    sent_list.append(mono_sent)
                    mono_sent = ''
        else:
            if i == len(para) - 1:
                sent_list.append(mono_sent)
                mono_sent = ''
    if len(mono_sent) > 0:
        sent_list.append(mono_sent)

    # print("句子长度：", len(sent_list))  #debug
    return sent_list


def margin_align_sents(sent_lista, sent_listb):
    """
        检查两个段落句子数量是否一致，不一致时将句子数量较多的文本进行合并，使句子数量一致。
    """
    lena = len(sent_lista)
    lenb = len(sent_listb)
    if lena > lenb:
        margin_by_n(sent_lista, lena - lenb)
    if lena < lenb:
        margin_by_n(sent_listb, lenb - lena)


def margin_by_n(sent_list, n):
    """
        将段落进行n次合并（假设段落中的句子数量大于n）
    """
    # print("[Debug][Start] sent_list ", sent_list)
    # print("[Debug][Start] sent_list ", n)

    while True:
        bl = len(sent_list) // 2
        if n <= bl:
            temp_list = copy.deepcopy(sent_list)
            sent_list.clear()
            for i in range(0, 2 * n, 2):
                sent_list.append(temp_list[i] + temp_list[i + 1])
            sent_list.extend(temp_list[2 * n:])
            return sent_list
        else:
            temp_list = copy.deepcopy(sent_list)
            sent_list.clear()
            for i in range(0, 2 * bl, 2):
                sent_list.append(temp_list[i] + temp_list[i + 1])
            sent_list.extend(temp_list[2 * bl:])
            n = n - bl


def analysis_sentence(sent_list):
    """
        获得句子在段落中的位置和长度信息
    """
    sent_info_list = list()
    for i, line in enumerate(sent_list):
        sent_info_list.append(list([i, len(line)]))
    return sent_info_list


def align_in_paragraph(lista, listb):
    """
        在段落内进行句对齐
        lista = [[0,5],[1,3],[2,8]]
        listb = [[0,6],[1,9],[2,5]]
    """
    lista = sorted(lista, key=lambda elem: elem[-1])
    listb = sorted(listb, key=lambda elem: elem[-1])

    comb_list = []
    for i in range(len(lista)):
        comb_list.append(list([lista[i][0], listb[i][0]]))

    return sorted(comb_list, key=lambda elem: elem[0])


def bilingual_align_encn(src_file, tar_file, out_file):
    """
        English-Chinese
    """
    src_para_list = text_2_paragraph(src_file)
    tar_para_list = text_2_paragraph(tar_file)

    min_para_len = min(len(src_para_list), len(tar_para_list))

    fout = open(out_file, 'w+', encoding='utf-8')
    for i in range(min_para_len):
        src_sent_list = para_2_sents_en(src_para_list[i])
        tar_sent_list = para_2_sents_cn(tar_para_list[i])

        margin_align_sents(src_sent_list, tar_sent_list)

        src_sent_info = analysis_sentence(src_sent_list)
        tar_sent_info = analysis_sentence(tar_sent_list)

        align_info_list = align_in_paragraph(src_sent_info, tar_sent_info)
        for j in range(len(align_info_list)):
            fout.write(src_sent_list[align_info_list[j][0]] + "\n")
            fout.write(tar_sent_list[align_info_list[j][-1]] + "\n")
        fout.write("\n")

    if len(src_para_list) != len(tar_para_list):
        fout.write("\n\n---------------------------------------------------------------")
        fout.write("\n---The following content is redundant and cannot be aligned!---\n")
        fout.write("---------------------------------------------------------------\n\n")
    for i in range(len(src_para_list) - min_para_len):
        fout.write(src_para_list[i + min_para_len] + "\n")

    for i in range(len(tar_para_list) - min_para_len):
        fout.write(tar_para_list[i + min_para_len] + "\n")
    fout.close()


def bilingual_align_mncn(src_file, tar_file, out_file):
    """
        Mongolian-Chinese
    """
    src_para_list = text_2_paragraph(src_file)
    tar_para_list = text_2_paragraph(tar_file)

    min_para_len = min(len(src_para_list), len(tar_para_list))

    fout = open(out_file, 'w+', encoding='utf-8')
    for i in range(min_para_len):
        src_sent_list = para_2_sents_mn(src_para_list[i])
        tar_sent_list = para_2_sents_cn(tar_para_list[i])

        margin_align_sents(src_sent_list, tar_sent_list)

        src_sent_info = analysis_sentence(src_sent_list)
        tar_sent_info = analysis_sentence(tar_sent_list)

        align_info_list = align_in_paragraph(src_sent_info, tar_sent_info)
        for j in range(len(align_info_list)):
            fout.write(src_sent_list[align_info_list[j][0]] + "\n")
            fout.write(tar_sent_list[align_info_list[j][-1]] + "\n")
        fout.write("\n")

    if len(src_para_list) != len(tar_para_list):
        fout.write("\n\n---------------------------------------------------------------")
        fout.write("\n---The following content is redundant and cannot be aligned!---\n")
        fout.write("---------------------------------------------------------------\n\n")
    for i in range(len(src_para_list) - min_para_len):
        fout.write(src_para_list[i + min_para_len] + "\n")

    for i in range(len(tar_para_list) - min_para_len):
        fout.write(tar_para_list[i + min_para_len] + "\n")
    fout.close()


def bilingual_align_tbcn(src_file, tar_file, out_file):
    """
        Tibetan-Chinese
    """
    src_para_list = text_2_paragraph(src_file)
    tar_para_list = text_2_paragraph(tar_file)

    min_para_len = min(len(src_para_list), len(tar_para_list))

    fout = open(out_file, 'w+', encoding='utf-8')
    for i in range(min_para_len):
        src_sent_list = para_2_sents_tb(src_para_list[i])
        tar_sent_list = para_2_sents_cn(tar_para_list[i])

        margin_align_sents(src_sent_list, tar_sent_list)

        src_sent_info = analysis_sentence(src_sent_list)
        tar_sent_info = analysis_sentence(tar_sent_list)

        align_info_list = align_in_paragraph(src_sent_info, tar_sent_info)
        for j in range(len(align_info_list)):
            fout.write(src_sent_list[align_info_list[j][0]] + "\n")
            fout.write(tar_sent_list[align_info_list[j][-1]] + "\n")
        fout.write("\n")

    if len(src_para_list) != len(tar_para_list):
        fout.write("\n\n---------------------------------------------------------------")
        fout.write("\n---The following content is redundant and cannot be aligned!---\n")
        fout.write("---------------------------------------------------------------\n\n")
    for i in range(len(src_para_list) - min_para_len):
        fout.write(src_para_list[i + min_para_len] + "\n")

    for i in range(len(tar_para_list) - min_para_len):
        fout.write(tar_para_list[i + min_para_len] + "\n")
    fout.close()


def bilingual_align(src_lang, src_text, tar_text):
    """
        English-Chinese
        Mongolian-Chinese
        Tibetan-Chinese
    """
    lang_set = {'en', 'mn', 'tb'}

    if src_lang in lang_set:
        if src_lang == 'en':
            bilingual_align_encn(src_text, tar_text, 'en-cn-out.txt')
        if src_lang == 'mn':
            bilingual_align_mncn(src_text, tar_text, 'mn-cn-out.txt')
        if src_lang == 'tb':
            bilingual_align_tbcn(src_text, tar_text, 'tb-cn-out.txt')
    else:
        print("Current language pairs are not supported!!")
        exit()

if __name__ == "__main__":
    # English-Chinese
    bilingual_align('en', 'text_encn_en.txt', 'text_encn_cn.txt')

    # Mongolian-Chinese
    # bilingual_align('mn', 'text_mncn_mn.txt', 'text_mncn_cn.txt')

    # Tibetan-Chinese
    # bilingual_align('tb', 'text_tbcn_tb.txt', 'text_tbcn_cn.txt')
