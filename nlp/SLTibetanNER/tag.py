"""
    自学习藏文命名实体识别模型工程

    start: 2019/5/11
"""

import os
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
        model_name = self.__crf_path + "\\model\\model_" + str(Tagger._iter_num)
        train_text = self.__data_path + "\\train.data_" + str(Tagger._iter_num)
        train_cmd = self.__crf_path + "\\core\\crf_learn.exe" + " " + self.__template + \
                     " " + train_text + " " + model_name

        self.execute_cmd(train_cmd)


    def test(self):
        """
        使用训练好的模型标注开发以确定是否需要终止学习
        """
        model_name = self.__crf_path + r"\model\model_" + str(Tagger._iter_num)
        dev_text = self.__data_path + r"\dev.data"
        ret_text = self.__data_path + r"\ret.data_" + str(Tagger._iter_num)
        test_cmd = self.__crf_path + r"\core\crf_test.exe -m" + " " + model_name + \
                    " " + dev_text + " > " + ret_text

        self.execute_cmd(test_cmd)


    def label(self):
        """
        使用训练好的模型标注生数据以被选择策略筛选
        """
        model_name = self.__crf_path + r"\model\model_" + str(Tagger._iter_num)
        raw_text = self.__data_path + r"\raw.data_" + str(Tagger._iter_num)
        lbd_text = self.__data_path + r"\lbd.data_" + str(Tagger._iter_num)
        tag_cmd = self.__crf_path + r"\core\crf_test.exe -v1 -m " + model_name + \
                   " " + raw_text + " > " + lbd_text

        self.execute_cmd(tag_cmd)


    def evaluate(self):
        """
        使用测试数据评价模型用于控制训练过程
        """
        eval_file = self.__data_path + r"\ret.data_" + str(Tagger._iter_num)
        eval_ret =  self.__data_path + r"\eval.data_" + str(Tagger._iter_num)
        eval_cmd = self.__crf_path + "\core\conlleval.pl -d \"\\t\" < " + eval_file + " > " + eval_ret

        self.execute_cmd(eval_cmd)

        eval_ret_map = {}
        feval = open(eval_ret, 'r', encoding='utf-8').readlines()
        try:
            prf_line = feval[1].strip().split(';')
            for metric in prf_line:
                metric = [ele.strip() for ele in metric.split(':')]
                eval_ret_map[metric[0]] = metric[-1]
        except:
            print("[Debug] error(s) happened")

        print('\n[Debug] begin')
        for key in eval_ret_map:
            print('[Debug] ', key, ':', eval_ret_map[key], end="   ")
        print('\n[Debug] end')

        return eval_ret_map


    def parse_labeled_file(self, file_name):
        """
        解析模型标注的文件
        """
        score_sents = []
        with open(file_name, 'r', encoding='utf-8') as fin:
            sent = []
            for index, line in enumerate(fin):
                line = line.strip()
                if line == '': # 空行
                    score_sents.append(','.join(sent))
                    sent = []
                else:
                    sent.append(line)

        return score_sents


    def select_confidence(self, conf=0.9):
        """
        基于CRF置信度的样本选择策略
        """
        lbd_text = self.__data_path + r"\lbd.data_" + str(Tagger._iter_num)
        score_sents = self.parse_labeled_file(lbd_text)

        selected_lbd_text = []
        unselect_lbd_text = []
        for index, conts in enumerate(score_sents):
            conts = conts.split(',')
            score = float(conts[0].split()[-1])
            conts = [' '.join(ele.split('\t')[0:2]) for ele in conts[1:]]
            if score > conf:
                selected_lbd_text.append('\n'.join(conts) + '\n')
            else:
                unselect_lbd_text.append('\n'.join(conts) + '\n')

        return selected_lbd_text, unselect_lbd_text


    def select_feature_sim(self):
        """
        基于特征相似度的样本选择策略
        """
        pass


    def update_data(self, selected_lbd_text, unselect_lbd_text):
        """
        基于当前的选择策略、更新数据
            将被选择的数据加入到训练集
            从生数据中剔除被选择的数据
         """
        Tagger._iter_num = Tagger._iter_num + 1

        add_file = self.__data_path + r"\add.data_" + str(Tagger._iter_num)
        raw_file = self.__data_path + r"\raw.data_" + str(Tagger._iter_num)

        # 输出选择的数据保存成文件，以备调试使用
        with open(add_file, 'w', encoding='utf-8') as fadd:
            for word_line in selected_lbd_text:
                # word_line = word_line.strip().split('\t')
                # fadd.write('\t'.join(word_line[:-1]) + '\n')
                fadd.write(word_line + '\n')

        # 将未被选中的数据保存为新的生数据
        with open(raw_file, 'w', encoding='utf-8') as fraw:
            for word_line in unselect_lbd_text:
                # word_line = word_line.strip().split('\t')
                # fraw.write('\t'.join(word_line[:-1]) + '\n')
                fraw.write(word_line + '\n')

        # 将被选中的数据添加到训练集，扩大了训练集规模
        train_prev = self.__data_path + r"\train.data_" + str(Tagger._iter_num - 1)
        train_file = self.__data_path + r"\train.data_" + str(Tagger._iter_num)

        with open(train_prev, 'r', encoding='utf-8') as fprev, \
                open(train_file, 'w+', encoding='utf-8') as fnow:
            for line in fprev:  # 拷贝原训练集
                fnow.write(line)
            for word_line in selected_lbd_text: # 拷贝新增数据
                fnow.write(word_line + '\n')


    def diff(self, eval_list, standard):
        """
        基于开发集测试模型表现，返回两次性能差异
        """
        diff = 1.0
        try:
            if len(eval_list) == 1:
                diff = float(eval_list[-1][standard])
            else:
                diff = abs(float(eval_list[-1][standard]) - float(eval_list[-2][standard]))
        except:
            pass
        return diff


    def draw_learning_curve(self, eval_list):
        """
        绘制学习曲线
        """
        prc = []; rec = []; fb1 = []
        for eval_map in eval_list:
            prc.append(float(eval_map[standard[1]][:-1]))
            rec.append(float(eval_map[standard[2]][:-1]))
            fb1.append(float(eval_map[standard[3]]))
        prc = np.array(prc)
        rec = np.array(rec)
        fb1 = np.array(fb1)

        x = np.arange(len(eval_list))

        plt.subplot(131)
        plt.xlabel('Iteration')
        plt.ylabel('Precision(%)')
        # plt.ylim(50,100)
        plt.plot(x, prc, 'b')
        plt.subplot(132)
        plt.xlabel('Iteration')
        plt.ylabel('Recall(%)')
        # plt.ylim(50,100)
        plt.plot(x, rec, 'c')
        plt.subplot(133)
        plt.xlabel('Iteration')
        plt.ylabel('FB1')
        # plt.ylim(50,100)
        plt.plot(x, fb1, 'g')
        plt.show()

    
if __name__ == "__main__":

    crf_path = r".\crf"
    template = r".\crf\template"
    data_path = r".\data"

    stop_cnd = 0.005
    confidence = 0.95
    standard = ['accuracy', 'precision', 'recall', 'FB1']

    tagger = Tagger(crf_path, template, data_path)

    eval_list = []
    while True:
        print("[Debug]=========train=========")
        tagger.train()
        print("[Debug]=========test=========")
        tagger.test()
        print("[Debug]=========eval=========")
        eval_list.append(tagger.evaluate())
        if tagger.diff(eval_list, standard[-1]) > stop_cnd:
            print("[Debug]=========label=========")
            tagger.label()
            print("[Debug]=========select=========")
            selected_lbd_text, unselect_lbd_text = tagger.select_confidence(confidence)
            print("[Debug]=========update=========")
            tagger.update_data(selected_lbd_text, unselect_lbd_text)
        else:
            break

    # draw result
    tagger.draw_learning_curve(eval_list)
