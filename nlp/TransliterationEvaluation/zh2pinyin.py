
import pypinyin


def zh2py(sent):
    sent_py = ''
    for word in pypinyin.pinyin(sent, style=pypinyin.NORMAL):
        sent_py += ''.join(word)

    sent_py += '\n'
    return sent_py


if __name__ == "__main__":

    # test
    sent = "中 华 人 民 共 和 国"
    print(zh2py(sent))

    in_file = "zh.test.txt"
    out_file = "zh.test.lt.txt"
    with open(in_file, 'r', encoding='utf-8') as fin, \
            open(out_file, 'w', encoding='utf-8') as fout:
        for line in fin:
            line = zh2py(line.strip())
            print(line)
            fout.write(line)
