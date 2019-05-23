
import _thread
import time

import threading

exit_flag = 0

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


if __name__ == "__main__":
    # try:
    #     create_threads()
    # except:
    #     print("Error: 无法启动线程")
    #
    # while 1:
    #     pass

    thread_lock = threading.Lock()

    mt1 = myThread(1, "thread-1", 1)
    mt2 = myThread(2, "thread-2", 2)

    mt1.start()
    mt2.start()

    mt1.join()
    mt2.join()

    print("退出主线程")
