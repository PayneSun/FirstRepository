# -*- coding: utf-8 -*-

import json
import requests


def seg(sent):
    url = 'http://10.10.130.152:5000/seg_ti'
    inputs = sent
    data = {
        "seg_string" : inputs
    }
    res = requests.post(url=url, json=data)
    # if res.json():
    #     print(res.json()['result'])
    return res.json()['result']


if __name__ == '__main__':
    s = 'མཚོ་སྔོན་ཞིང་ཆེན་གྱི་ཧྲིན་ཀྲང་གཞོན་པ། ཞིང་ཆེན་བཟོ་ཚོང་མཉམ་འབྲེལ་ལྷན་ཚོགས་ཀྱི་ཀྲུའུ་ཞི་ཁོང་ཡུང་ཚོགས་འདུར་ཞུགས།'

    print(len(s))
    print(len(seg(s).split()))