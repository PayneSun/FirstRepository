"""
    标注藏文命名实体的特征

    label_ne_feature.py
    2019/3/20
"""


def read_feature_set(feature_file):
    """
        从特征集文件中读入特征，返回特征集列表
    """

    ft_set_list = []
    with open(feature_file) as fin:
        for line in fin:
            line = line.strip()
            if line:
                ft_set_list.append(line)

    return ft_set_list


if __name__ == "__main__":
    # 定义原始文件
    raw_file = "raw.txt"
    # 定义输出文件
    out_file = "out.txt"

    # 加载X1特征集
    ft_set_ = read_feature_set("")
    # 加载X2特征集
    ft_set_ = read_feature_set("")
    # 加载X3特征集
    ft_set_ = read_feature_set("")
    # 加载X4特征集
    ft_set_ = read_feature_set("")

    with open(raw_file, "r") as fin, open(out_file, "w") as fout:
        for line in fin:
            line = line.strip()
            if line:
                out_line = line + " "
                if line in ft_set_:     # 特征1
                    out_line += " " + " "
                else:
                    out_line += " " + " "
                if line in ft_set_:     # 特征2
                    out_line += " " + " "
                else:
                    out_line += " " + " "
                if line in ft_set_:     # 特征3
                    out_line += " " + " "
                else:
                    out_line += " " + " "
                if line in ft_set_:     # 特征4
                    out_line += " " + " "
                else:
                    out_line += " " + " "
                if line in ft_set_:     # 特征5
                    out_line += " " + " "
                else:
                    out_line += " " + " "
            out_line += "\n"
            fout.write(out_line)
