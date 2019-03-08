# -*- coding: utf-8 -*-
# 2018/9/25
#


def pre_process(file_name):
    '''
        Replace space line with specified string for
        ensuring tagger.py can deal with multiply sentences.
    '''
    fout = open(file_name + '.ftd', 'w')
    with open(file_name) as fin:
        for line in fin:
            line.replace("\r\n", "\n").strip()
            if "+++" in line:
                print(line)
            if line.isspace():
                line = "+++ +++ O O\n"
            fout.write(line)
    fout.close()


def pre_process2(file_name):
    '''
        Replace space line with specified string for
        ensuring tagger.py can deal with multiply sentences.
    '''
    fout = open(file_name + '.ftd', 'w')
    fcfg = open(file_name + '.cfg', 'w')
    with open(file_name) as fin:
        num = 0
        # bnum = 0
        for line in fin:
            line.replace("\r\n", "\n").strip()
            if line.isspace():
                fcfg.write(str(num) + '\n')
                # fcfg.write(str(anum) + ',' + str(bnum) + '\n')
            else:
                # bnum += 1
                fout.write(line)
            num += 1

    fcfg.close()
    fout.close()


def post_process(file_name):
    '''
        Format file labeled by tagger.py.
    '''
    fout = open(file_name + '.ftd', 'w')
    with open(file_name) as fin:
        for line in fin:
            if "+++" in line:  #delete invalid sentence tag
                line = '\n'
                fout.write(line)
            elif "-DOCSTART-" in line:  #delete file end tag
                continue
            else:  #catch word and its tag
                col_labeled = line.strip().split()
                # print col_labeled
                out_line = []
                for i in range(len(col_labeled)):
                    voc = col_labeled[i].split('__')[0]
                    out_line.append(voc)
                    if i == 0:
                        tag = col_labeled[i].split('__')[1] + '\n'
                out_line.append(tag)
                fout.write(' '.join(out_line))
    fout.close()


def post_process2(labeled_file_name, config_file_name):
    '''
        Format file labeled by tagger.py.
    '''
    # get number of blank line
    blank_line = []
    with open(config_file_name) as fcfg:
        for line in fcfg:
            if not line.isspace():
                blank_line.append(int(line.strip()))
    # print blank_line

    fout = open(labeled_file_name + '.ftd', 'w')
    with open(labeled_file_name) as fin:
        cnt = 0
        for line in fin:
            # insert blank line
            if cnt in blank_line:
                fout.write('\n')
                cnt += 1

            # parser labeled line and extract predicted tag
            col_labeled = line.strip().split()
            out_line = []
            for i in range(len(col_labeled)):
                voc = col_labeled[i].split('__')[0]
                out_line.append(voc)
                if i == 0:
                    tag = col_labeled[i].split('__')[1] + '\n'
            out_line.append(tag)
            fout.write(' '.join(out_line))

            cnt += 1
    fout.close()



'''----test ---------------'''

# pre_process2('testa.en')
post_process2('testa.cn.out', 'testa.cn.cfg')

# post_process('output.txt')

