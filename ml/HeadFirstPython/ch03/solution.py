'''
    solution.py

    2017/11/29
'''


file = open('yuliao.txt', encoding='utf-8', errors='ignore')
outs = open('yuliao-format.txt', 'w+', encoding='utf-8')

cn_str = ''
zw_str = ''
ou_str = ''

list_cn = []
list_zw = []

for line in file:
    cn_str, zw_str = line.split('\t')
    for cn in cn_str:
        list_cn.append(cn)

    list_zw = list(zw_str.split('་'))
    list_zw.pop()

    if len(list_cn) == len(list_zw):
        for i in range(len(list_cn)):
            ou_str = ou_str + list_cn[i] + ' ' + list_zw[i] + '\n'

    ou_str = ou_str + '\n'
    outs.write(ou_str)

    list_cn.clear()
    list_zw.clear()
    cn_str = ''
    zw_str = ''
    ou_str = ''

file.close()
outs.close()
