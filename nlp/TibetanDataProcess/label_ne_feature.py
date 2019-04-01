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

    # 加载藏族人名高频音节表：TPHF
    ft_set_1 = read_feature_set("tibetan_high_frequency_syllable.txt")
    # 加载汉族人名高频音节表: CPHF
    ft_set_2 = read_feature_set("chinese_high_frequency_syllable.txt")
    # 加载汉族姓氏高频音节表: CSHF
    ft_set_3 = read_feature_set("chinese_surname_syllable.txt")
    # 加载人名称谓词表：
    ft_set_4 = read_feature_set("per_title.txt")
    # 加载地名称谓词表
    ft_set_5 = read_feature_set("loc_title.txt")
    # 加载组织机构名称谓词表
    ft_set_6 = read_feature_set("org_title.txt")

    with open(raw_file, "r") as fin, open(out_file, "w") as fout:
        for line in fin:
            line = line.strip()
            if line:
                out_line = line
                if line in ft_set_1:     # 特征1
                    out_line += " " + "1"
                else:
                    out_line += " " + "0"
                if line in ft_set_2:     # 特征2
                    out_line += " " + "1"
                else:
                    out_line += " " + "0"
                if line in ft_set_3:     # 特征3
                    out_line += " " + "1"
                else:
                    out_line += " " + "0"
                if line in ft_set_4:     # 特征4
                    out_line += " " + "1"
                else:
                    out_line += " " + "0"
                if line in ft_set_5:     # 特征5
                    out_line += " " + "1"
                else:
                    out_line += " " + "0"
                if line in ft_set_6:     # 特征6
                    out_line += " " + "1"
                else:
                    out_line += " " + "0"
            out_line += "\n"
            fout.write(out_line)
