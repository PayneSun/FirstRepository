"""
    trans_eval.py [2019/3/14]

    藏汉音译结果评价指标
"""


def acc(in_file):
    """
        Word Accuracy in Top-1 (ACC)
    """
    trans_ref = []  # references of transliteration
    trans_cad = []  # candidates of transliteration
    with open(in_file, "r") as fin:
        for line in fin:
            line = line.strip()
            trans_ref.append(line[0])
            trans_cad.append(line[1:])

    cnt = 0 # number of correct result
    for index, element in enumerate(trans_ref):
        if element == trans_cad[index][0]:
            cnt += 1
    return (cnt / len(trans_ref))


def mfs(in_file):
    pass


def mrr(in_file):
    """
        Mean Reciprocal Rank (MRR)
    """
    trans_ref = []  # references of transliteration
    trans_cad = []  # candidates of transliteration
    with open(in_file, "r") as fin:
        for line in fin:
            line = line.strip()
            trans_ref.append(line[0])
            trans_cad.append(line[1:])
    rr = 0      # reciprocal rank
    srr = 0.0   # sum of reciprocal rank
    for index, element in enumerate(trans_ref):
        if element in trans_cad[index]:
            rr = index
        if not rr:
            srr += 1 / rr

    # mean reciprocal rank
    return (srr / len(trans_ref))


def map(in_file):
    """
        Mean Average Precision (MAPref)
    """
    trans_ref = []  # references of transliteration
    trans_cad = []  # candidates of transliteration
    with open(in_file, "r") as fin:
        for line in fin:
            line = line.strip()
            trans_ref.append(line[0])
            trans_cad.append(line[1:])
    cnt = 0
    for index, element in enumerate(trans_ref):
        for ref in trans_cad[index]:    # num(i,k)
            if element == ref:
                cnt += 1
    return (cnt / len(trans_ref))


if __name__ == "__main__":

    in_file = ""

    print("acc: ", acc(in_file))
    # print("mfs: ", mfs(in_file))
    print("mrr: ", mrr(in_file))
    print("map: ", map(in_file))
