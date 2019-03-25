

import os
import nltk
import nltk.stem
from nltk.corpus import stopwords
from nltk import SnowballStemmer


def list_dir(path):
    """"
        获取目录下的文件名列表
    """
    list_name = []
    for file in os.listdir(path):
        file_path = os.path.join(path, file)
        if os.path.isdir(file_path):
            list_name.extend(list_dir(file_path))
        else:
            list_name.append(file_path)

    return list_name


def extract_voc(file_name, stop_list, voc_map):
    """
        从单文本生成词表
    """
    stemmer = nltk.stem.SnowballStemmer('english')
    stop_word = set(stopwords.words('english'))

    with open(file_name, 'r', encoding="utf-8") as fin:
        for line in fin:
            line = nltk.word_tokenize(line)
            for voc in line:
                voc = stemmer.stem(voc)
                if voc in stop_list or voc in stop_word:
                    pass
                else:
                    voc_map[voc] = 1


def generate_voc(file_name_list, stop_list):
    """
        从文本库生成词表
    """
    voc_map = {}
    for file_name in file_name_list:
        extract_voc(file_name, stop_list, voc_map)

    return voc_map.keys()


def doc_2_vec(file_name, list_voc, stop_list):
    """
        将文档转换为向量
    """
    voc_map_sub = {}
    extract_voc(file_name, stop_list, voc_map_sub)
    doc_voc = list(voc_map_sub.keys())
    print(doc_voc)

    doc_vec = [0 for i in range(len(list_voc))]
    for word in doc_voc:
        idx = list(list_voc).index(word)
        if idx != -1:
            doc_vec[idx] += 1

    return doc_vec


def get_stopword(stopword_file):
    """
        抽取停用词列表
    """
    stop_list = []
    with open(stopword_file, "r", encoding="utf-8") as fsl:
        for word in fsl:
            stop_list.append(word.strip())

    return stop_list


def doc_sim(doc_vec_1, doc_vec_2):
    """
        计算两个文档向量的相似性
    """
    ret = 0.0
    for i in doc_vec_1:
        for j in doc_vec_2:
            ret += i * j
    return ret


if __name__ == "__main__":
    # nltk.download()

    stopword_file = "large-stoplist.txt"
    stop_list = get_stopword(stopword_file)

    text_directory = "eng-reading-dataset"
    file_name_list = list_dir(text_directory)
    list_voc = generate_voc(file_name_list, stop_list)

    # for index, element in enumerate(file_name_list):
    #     print("[Debug]", index, ": ", element)

    doc_sim_list = []
    test_file_name = r"eng-reading-dataset\Tech\Tech_0357.txt"
    for index, element in enumerate(file_name_list):
        if element != test_file_name:
            doc_sim_map = {}
            doc_sim_map["file_name"] = element
            doc_vec_1 = doc_2_vec(test_file_name, list_voc, stop_list)
            doc_vec_2 = doc_2_vec(element, list_voc, stop_list)
            doc_sim_map["doc_sim"] = doc_sim(doc_vec_1, doc_vec_2)
            doc_sim_list.append(doc_sim_map)
    sorted(doc_sim_list, key=lambda keys:keys["doc_sim"], reverse=True)

    for idx, ele in enumerate(doc_sim_list):
        if (idx <= 4):
            print(ele)
        else:
            break


