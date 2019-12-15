# -*- coding: utf-8 -*-

'''
    测试其他任务中用到的Python库的用法

    test_library.py  2019/7/7
'''

import pypinyin

import matplotlib.pyplot as plt

import gensim.downloader as api
from gensim.models import TfidfModel
from gensim.corpora import Dictionary


def test_matplotlib():
    x1 = [1,3,5,7,9]
    y1 = [5,2,7,8,2]
    x2 = [2,4,6,8,10]
    y2 = [8,6,2,5,6]

    plt.bar(x1, y1, label="Example one", color='r')
    plt.bar(x2, y2, label="Example two", color='g')

    plt.legend()
    plt.xlabel('bar number')
    plt.ylabel('bar height')

    plt.title('Epic Graph\nAnother Line! Whoa')
    plt.show()


def zh2py(sent):
    sent_py = ''
    for word in pypinyin.pinyin(sent, style=pypinyin.NORMAL):
        sent_py += ''.join(word)

    sent_py += '\n'
    return sent_py


def test_tfidf():
    dataset = api.load("text8")
    dct = Dictionary(dataset)  # fit dictionary
    corpus = [dct.doc2bow(line) for line in dataset]  # convert corpus to BoW format

    model = TfidfModel(corpus)  # fit model
    vector = model[corpus[0]]  # apply model to the first corpus document

    for vec in vector:
        print(vec)


if __name__ == "__main__":

    ###======使用matplotlib绘图======begin===###
    test_matplotlib()
    ###======使用matplotlib绘图======end=====###

    ###======使用pypinyin将中文拉丁化======begin===###
    # sent = "中 华 人 民 共 和 国"
    # print(zh2py(sent))
    #
    # in_file = "zh.test.txt"
    # out_file = "zh.test.lt.txt"
    # with open(in_file, 'r', encoding='utf-8') as fin, \
    #         open(out_file, 'w', encoding='utf-8') as fout:
    #     for line in fin:
    #         line = zh2py(line.strip())
    #         print(line)
    #         fout.write(line)
    ###======使用pypinyin将中文拉丁化======end=====###

