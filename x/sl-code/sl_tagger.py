"""
    自学习藏文命名实体识别模型工程

    start: 2019/5/11
"""

import os
import re
import time
import numpy as np
import matplotlib.pyplot as plt
from subprocess import Popen, PIPE


class Tagger():
    _iter_num = 0

    def __init__(self, crf_path, template, data_path):
        self.__template = template
        self.__crf_path = crf_path
        self.__data_path = data_path


    def execute_cmd(self, cmd_str="ipconfig"):
        # 方法一
        # pstr = os.popen(cmd_str)
        # print(pstr.read())

        # 方法二
        os.system(cmd_str)

        # 方法三
        # p = Popen(cmd_str, shell=True, stdout=PIPE, stderr=PIPE)
        # p.wait()


    def train(self):
        """
            训练CRF模型
        """
        model_name = self.__data_path + r"\model_" + str(Tagger._iter_num)
        train_file = self.__data_path + r"\train.txt_" + str(Tagger._iter_num)
        train_cmd = self.__crf_path + r"\crf_learn.exe " + self.__template + " " + train_file + " " + model_name

        print("[Debug] " + train_cmd)
        self.execute_cmd(train_cmd)
        # time.sleep(2)


    def test(self):
        """
            使用训练好的模型预测测试集
        """
        model_name = self.__data_path + r"\model_" + str(Tagger._iter_num)
        test_file = self.__data_path + r"\test.txt"
        ret_file = self.__data_path + r"\test.ret_" + str(Tagger._iter_num)
        test_cmd = self.__crf_path + r"\crf_test.exe -m " + model_name + " " + test_file + " > " + ret_file
        self.execute_cmd(test_cmd)

        eval_file = self.__data_path + r"\test.eva_" + str(Tagger._iter_num)
        eval_cmd = self.__crf_path + "\conlleval.pl -d \"\\t\" < " + ret_file + " > " + eval_file
        self.execute_cmd(eval_cmd)

        # 提取评价指标
        fevl = open(eval_file, 'r', encoding='utf-8').readlines()
        eval_list = re.findall(re.compile(r'\d+.\d+'), fevl[1])

        return eval_list


    def label(self):
        """
        使用训练好的模型标注生数据以被选择策略筛选
        """
        model_name = self.__data_path + r"\model_" + str(Tagger._iter_num)
        dev_file = self.__data_path + r"\dev.txt_" + str(Tagger._iter_num)
        ret_file = self.__data_path + r"\dev.ret_" + str(Tagger._iter_num)
        test_cmd = self.__crf_path + r"\crf_test.exe -v1 -m " + model_name + " " + dev_file + " > " + ret_file

        self.execute_cmd(test_cmd)


    def evaluate_by_diff(self):
        """
            基于最近两次迭代得到的模型去预测开发集（未标注数据），
            评估两次模型在开发集上的预测结果以确定是否需要继续迭代。
        """
        dev_ret_pre = self.__data_path + r"\dev.ret_" + str(Tagger._iter_num-1)
        dev_ret_cur = self.__data_path + r"\dev.ret_" + str(Tagger._iter_num)

        with open(dev_ret_pre, 'r', encoding='utf-8') as fpre, open(dev_ret_cur, 'r', encoding='utf-8') as fcur:
            dif_cnt = 0
            sum_cnt = 0
            for line_pre, line_cur in zip(fpre, fcur):
                line_pre = line_pre.strip().split('\t')
                line_cur = line_cur.strip().split('\t')
                if len(line_pre) > 2:
                    sum_cnt += 1
                    if line_pre[-1].split('/')[0] != line_cur[-1].split('/')[0]:
                        dif_cnt += 1

        return dif_cnt / sum_cnt


    def parse_labeled_file(self, file_name):
        """
            解析模型标注的文件：抽取句子
        """
        sent_scores = []
        with open(file_name, 'r', encoding='utf-8') as fin:
            sent = []
            for index, line in enumerate(fin):
                line = line.strip()
                if line == '' and len(sent) > 0: # 空行
                    sent_scores.append('\n'.join(sent))  # 以'\n'字符分割句子
                    sent = []
                else:
                    sent.append(line)

        return sent_scores


    def select_sample_by_confidence(self, conf=0.9):
        """
        基于CRF句子置信度的样本选择策略
        """
        dev_ret_file = self.__data_path + r"\dev.ret_" + str(Tagger._iter_num)
        sent_scores = self.parse_labeled_file(dev_ret_file)

        selected_sents = []
        unselected_sents = []
        for index, conts in enumerate(sent_scores):
            conts = conts.split('\n')  # 分离句子列表
            score = float(conts[0].split()[-1])  # 抽取模型对句子的置信度评分

            if score > conf:
                sent = []
                for line in conts[1:]:
                    word_features = line.split('\t')  # 音节及音节对应的特征
                    tag = word_features[-1].split('/')[0]  # 抽取模型标注的结果（只含标签不含置信度分值）
                    word_features[-1] = tag
                    sent.append(' '.join(word_features))
                selected_sents.append('\n'.join(sent) + '\n')
            else:
                sent = []
                for line in conts[1:]:
                    word_features = line.split('\t')  # 音节及音节对应的特征
                    word_features = word_features[0:-1]  # 剔除模型标注的结果
                    sent.append(' '.join(word_features))
                unselected_sents.append('\n'.join(sent) + '\n')

        return selected_sents, unselected_sents


    def select_sample_by_topn(self, topn=50):
        """
        基于CRF句子置信度的固定样本选择策略
        """
        dev_ret_file = self.__data_path + r"\dev.ret_" + str(Tagger._iter_num)
        sent_scores = self.parse_labeled_file(dev_ret_file)

        sent_pools = []
        for index, conts in enumerate(sent_scores):
            conts = conts.split('\n')  # 分离句子列表
            score = float(conts[0].split()[-1])  # 抽取模型对句子的置信度评分
            sent_pools.append([score,conts[1:]])

        # 基于置信度对句子进行逆排序
        sent_pools.sort(key=lambda x:x[0],reverse=True)

        selected_sents = []
        unselected_sents = []
        for index,conts in enumerate(sent_pools):
            if index < topn:
                sent = []
                for line in conts[-1]:
                    word_features = line.split('\t')  # 音节及音节对应的特征
                    tag = word_features[-1].split('/')[0]  # 抽取模型标注的结果（只含标签不含置信度分值）
                    word_features[-1] = tag
                    sent.append(' '.join(word_features))
                selected_sents.append('\n'.join(sent) + '\n')
            else:
                sent = []
                for line in conts[-1]:
                    word_features = line.split('\t')  # 音节及音节对应的特征
                    word_features = word_features[0:-1]  # 剔除模型标注的结果
                    sent.append(' '.join(word_features))
                unselected_sents.append('\n'.join(sent) + '\n')

        return selected_sents, unselected_sents


    def select_sample_by_ftsim(self):
        """
        基于特征相似度的样本选择策略
        """
        pass


    def update_data(self, selected_sents, unselected_sents):
        """
        基于当前的选择策略、更新数据
            将被选择的数据加入到训练集
            从生数据中剔除被选择的数据
         """
        Tagger._iter_num = Tagger._iter_num + 1

        sel_file = self.__data_path + r"\sel.txt_" + str(Tagger._iter_num)
        # 未被选中的数据即为下一轮迭代的开发集
        usel_file = self.__data_path + r"\dev.txt_" + str(Tagger._iter_num)

        # 输出选择的数据保存成文件，以备调试使用
        with open(sel_file, 'w', encoding='utf-8') as fst:
            for word_line in selected_sents:
                fst.write(word_line + '\n')

        # 将未被选中的数据保存为新的生数据
        with open(usel_file, 'w', encoding='utf-8') as fust:
            for word_line in unselected_sents:
                fust.write(word_line + '\n')

        # 将被选中的数据添加到训练集，扩大了训练集规模
        train_prev = self.__data_path + r"\train.txt_" + str(Tagger._iter_num - 1)
        train_file = self.__data_path + r"\train.txt_" + str(Tagger._iter_num)

        with open(train_prev, 'r', encoding='utf-8') as fpre, open(train_file, 'w+', encoding='utf-8') as fcur:
            for line in fpre:  # 拷贝原训练集
                fcur.write(line)
            for word_line in selected_sents: # 拷贝新增数据
                fcur.write(word_line + '\n')


    def draw_learn_curve(self, eval_list):
        """
        绘制学习曲线
        """
        prc = []
        rec = []
        fb1 = []
        for eval in eval_list:
            prc.append(float(eval[1]))
            rec.append(float(eval[2]))
            fb1.append(float(eval[3]))

        x = np.arange(len(eval_list))

        plt.subplot(311)
        plt.xlabel('Iteration')
        plt.ylabel('Precision(%)')
        # plt.ylim(0,100)
        plt.plot(x, np.array(prc), 'b')
        plt.subplot(312)
        plt.xlabel('Iteration')
        plt.ylabel('Recall(%)')
        # plt.ylim(0,100)
        plt.plot(x, np.array(rec), 'c')
        plt.subplot(313)
        plt.xlabel('Iteration')
        plt.ylabel('F1')
        # plt.ylim(0,100)
        plt.plot(x, np.array(fb1), 'g')
        plt.show()


def count_column_len(in_file):
    """"""
    error_list = []
    with open(in_file, 'r', encoding='utf-8') as frd:
        for index,line in enumerate(frd):
            line = line.strip().split()
            # print(str(index+1) + '  ' + str(len(line)))
            if len(line) != 0 and len(line) != 8:
                error_list.append(str(index+1))
    print('\n'.join(error_list))


def extract_data(in_file):
    with open(in_file, 'r', encoding='utf-8') as frd, open(in_file+'.new', 'w', encoding='utf-8') as fwt:
        for line in frd:
            line = line.strip().split()
            if len(line):
                # fwt.write(' '.join(line[0:6]) + ' ' + ' '.join(line[-2:]) + '\n')
                fwt.write(' '.join(line) + ' ' + line[-1] + '\n')
            else:
                fwt.write('\n')


if __name__ == "__main__":
    """"""
    crf_path = r".\tool"
    template = r".\tool\template"
    data_path = r".\data\TbData"

    # count_column_len(data_path + r"\train.txt_1")
    # extract_data(data_path + r"\dev.txt_0")

    stop_cond = 0.0005
    confidence = 0.950
    topn = 100

    tagger = Tagger(crf_path, template, data_path)

    eval_list = []
    while True:
        # if tagger._iter_num >= 10:
        #     break

        # 基于当前的训练集训练模型
        tagger.train()

        # 使用当前的模型预测测试集数据
        eval_list.append(tagger.test())
        print('\n[Debug] iter:' + str(tagger._iter_num) + ', ' + ', '.join(eval_list[-1]) + '\n')

        # 使用当前的模型预测待标注数据
        tagger.label()

        # if tagger._iter_num != 0:  # 非初次迭代，须检测是否收敛
        #     if tagger.evaluate_by_diff() < stop_cond:  # 满足停止条件，停止迭代
        #         break

        # 策略一
        # selected_data, unselected_data = tagger.select_sample_by_confidence(confidence)
        # 策略二
        selected_data, unselected_data = tagger.select_sample_by_topn(topn)

        if len(selected_data):
            tagger.update_data(selected_data, unselected_data)
        else:
            break

    # 绘制学习曲线
    tagger.draw_learn_curve(eval_list)
