
import crf_thread


if __name__ == "__main__":

    test_str = "རྒྱལ་ཁབ་ཀྱི་མི་རིགས་གྲངས་ཉུང་གི་སྐད་ཡིག་སྐོར་གྱི་སྲིད་ཇུས་གཙོ་བོ།"

    test_text_str = ""
    with open("test.tmp", 'r', encoding="utf-8") as fin:
        for line in fin:
            test_text_str += line

    crf = crf_thread.CRF(test_text_str)

    crf.tagger()
    outstr = crf.output()

    print(outstr)

