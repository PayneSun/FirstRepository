

import os
import nltk
import nltk.stem
from nltk import SnowballStemmer



def list_dir(path):
    """"
        Parse specified file directory and get file name list

        path: file path
        list_name: returned file name list
    """
    list_name = []
    for file in os.listdir(path):
        file_path = os.path.join(path, file)
        if os.path.isdir(file_path):
            list_name.extend(list_dir(file_path))
        else:
            list_name.append(file_path)

    return list_name


def extract_voc(file_name, voc_map):
    """
    """
    stemmer = nltk.stem.SnowballStemmer('english')

    with open(file_name, 'r', encoding="utf-8") as fin:
        for line in fin:
            # line = line.strip().split()
            line = nltk.word_tokenize(line)
            for voc in line:
                voc = stemmer.stem(voc)
                voc_map[voc] = 1


def generate_voc(file_name_list):
    """
    """
    voc_map = {}
    for file_name in file_name_list:
        extract_voc(file_name, voc_map)

    return voc_map.keys()


if __name__ == "__main__":
    # nltk.download()

    path_to_directory = ".\eng-reading-dataset"
    file_name_list = list_dir(path_to_directory)
    list_voc = generate_voc(file_name_list)
    for index, element in enumerate(list_voc):
        print(index, " ", element)
