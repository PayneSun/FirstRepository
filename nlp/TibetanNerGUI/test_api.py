'''
    测试接口

    test_api.py  2019/4/19
'''

import _thread
import time
import threading
import crf_thread

exit_flag = 0
thread_lock = threading.Lock()

def print_time(thread_name, delay):
    count = 0
    while count < 5:
        time.sleep(delay)
        count += 1
        print("%s: %s" % (thread_name, time.ctime(time.time())))

def create_threads():
    _thread.start_new_thread(print_time, ("thread-1", 2))
    _thread.start_new_thread(print_time, ("thread-2", 4))


def print_time2(thread_name, delay, counter):
    while counter:
        if exit_flag:
            thread_name.exit()
        time.sleep(delay)
        print("%s: %s" % (thread_name, time.ctime(time.time())))
        counter -= 1


class myThread(threading.Thread):
    def __init__(self, thread_id, name, counter):
        threading.Thread.__init__(self)
        self.thread_id = thread_id
        self.name = name
        self.counter = counter
    def run(self):
        print("开始线程： " + self.name)
        thread_lock.acquire()
        print_time2(self.name, self.counter, 5)
        thread_lock.release()
        print("退出线程： " + self.name)


def test_thread():
    mt1 = myThread(1, "thread-1", 1)
    mt2 = myThread(2, "thread-2", 2)

    mt1.start()
    mt2.start()
    mt1.join()
    mt2.join()

    print("退出主线程")


def test_crf():
    test_str = "རྒྱལ་ཁབ་ཀྱི་མི་རིགས་གྲངས་ཉུང་གི་སྐད་ཡིག་སྐོར་གྱི་སྲིད་ཇུས་གཙོ་བོ།"

    test_text_str = ""
    with open("test.tmp", 'r', encoding="utf-8") as fin:
        for line in fin:
            test_text_str += line

    crf = crf_thread.CRF(test_text_str)

    crf.tagger()
    outstr = crf.output()

    print(outstr)



if __name__ == "__main__":

    test_crf()

    # test_thread()
