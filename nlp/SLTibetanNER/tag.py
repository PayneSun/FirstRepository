"""
    自学习藏文命名实体识别模型工程
"""

import os
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
        train_text = self.__data_path + "\\train.data"
        # train_cmd = self.__crf_path + "\\a.exe"
        train_cmd = self.__crf_path + "\\core\\crf_learn.exe" + " " + self.__template + \
                     " " + train_text + " " + model_name

        self.execute_cmd(train_cmd)

    def test(self):
        """
        使用训练好的模型标注开发以确定是否需要终止学习
        """
        model_name = self.__crf_path + r"\model\model_" + str(Tagger._iter_num)
        dev_text = self.__data_path + r"\dev.data"
        ret_text = self.__data_path + r"\tmpdir\ret.data_" + str(Tagger._iter_num)
        test_cmd = self.__crf_path + r"\core\crf_test.exe -m" + " " + model_name + \
                    " " + dev_text + " > " + ret_text

        self.execute_cmd(test_cmd)

    def label(self):
        """
        使用训练好的模型标注生数据以被选择策略筛选
        """
        model_name = self.__crf_path + r"\model\model_" + str(Tagger._iter_num)
        raw_text = self.__data_path + r"\raw.data"
        lbd_text = self.__data_path + r"\tmpdir\ret.data_" + str(Tagger._iter_num)
        tag_cmd = self.__crf_path + r"\core\crf_test.exe -m" + " " + model_name + \
                   " " + raw_text + " > " + lbd_text
        self.execute_cmd(tag_cmd)

    def evaluate(self):
        """
        使用测试数据评价模型用于控制训练过程
        """
        eval_file = self.__data_path + r"\tmpdir\ret.data_" + str(Tagger._iter_num)
        eval_ret = ret_text = self.__data_path + r"\tmpdir\eval.data_" + str(Tagger._iter_num)
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

        print("+++Debug-begin++++++++++++++++++++++++++++++++++++++++++++++++++++++++")
        for key in eval_ret_map:
            print(key, ":", eval_ret_map[key], end="   ")
        print("\n+++Debug-end++++++++++++++++++++++++++++++++++++++++++++++++++++++++++")

        return eval_ret_map


    def select(self):
        """
        挑选数据加入到训练集
        """
        pass

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


    



if __name__ == "__main__":

    crf_path = r".\crf"
    template = r".\crf\template"
    data_path = r".\data"

    tagger = Tagger(crf_path, template, data_path)

    # test Tagger.execute_cmd()
    # tagger.execute_cmd()

    # test Tagger.train()
    # tagger.train()

    # test Tagger.test()
    # tagger.test()

    # test Tagger.evaluate()
    # tagger.evaluate()

    stop_cnd = 0.005
    standard = ['accuracy', 'precision', 'recall', 'FB1']

    eval_list = []
    while True:
         tagger.train()
         tagger.test()
         eval_list.append(tagger.evaluate())
         if tagger.diff(eval_list, eval_list, standard[-1]) > stop_cnd:
            tagger.label()
            tagger.select()
         else:
             break
