# -*- coding: utf-8 -*-

import sys

import time
from PyQt5.QtCore import Qt
from PyQt5.QtGui import QFont, QIcon
from PyQt5.QtWidgets import *

# import xml.sax
# from xml.dom.minidom import parse
# import xml.dom.minidom
#
# import xml.sax
# from xml.dom.minidom import parse
# import xml.dom.minidom
# import jieba

from MnCnAlign import main


class Center(QWidget):
    def __init__(self):
        super().__init__()
        self.initUI()

    def initUI(self):
        self.QMainUI = QGridLayout()

        self.title1 = QLabel("中文文件路径：",self)
        self.title1.setFont(QFont("Roman times",10,QFont.Bold))
        self.title1.setFixedHeight(30)
        self.title2 = QLabel("蒙文文件路径：", self)
        self.title2.setFont(QFont("Roman times", 10, QFont.Bold))
        self.title2.setFixedHeight(30)
        self.title3 = QLabel("输出文件：", self)
        self.title3.setFont(QFont("Roman times", 10, QFont.Bold))
        self.title3.setFixedHeight(30)

        self.inputCh = QLineEdit()
        self.inputMeng = QLineEdit()
        self.output = QTextEdit()

        self.align = QPushButton("对齐")
        self.align.clicked.connect(self.alignMethord)

        self.cn_import = QPushButton("导入-中文")
        self.cn_import.clicked.connect(self.import_cn)
        self.meng_import = QPushButton("导入-蒙文")
        self.meng_import.clicked.connect(self.import_meng)


        self.QMainUI.addWidget(self.title1,1,0)
        self.QMainUI.addWidget(self.inputCh, 1,1,1,4)
        self.QMainUI.addWidget(self.title2,2,0)
        self.QMainUI.addWidget(self.inputMeng, 2, 1,1,4)
        self.QMainUI.addWidget(self.title3,3,0)
        self.QMainUI.addWidget(self.output, 3, 1,3,5)
        self.QMainUI.addWidget(self.align,6,2,1,4)

        self.QMainUI.addWidget(self.cn_import,1,5)
        self.QMainUI.addWidget(self.meng_import,2,5)

        self.setLayout(self.QMainUI)
        self.setGeometry(300, 300, 500, 400)

    def import_cn(self):
        fname = QFileDialog.getOpenFileName(self, 'Open file', '/home')
        self.inputCh.setText(fname[0])

    def import_meng(self):
        fname = QFileDialog.getOpenFileName(self, 'Open file', '/home')
        self.inputMeng.setText(fname[0])

    def alignMethord(self):
        print("123")
        cn = self.inputCh.text()
        mn = self.inputMeng.text()
        if cn is not "" and mn is not "":
            main(mn,cn)

        out = open("output.txt","r",encoding="utf-8")
        result  = ""
        for line in out.readlines():
            result = result + line

        self.output.setText(result)

class MT(QMainWindow):
    def __init__(self):
        super().__init__()
        self.initUI()

    def initUI(self):

        self.center = Center()

        self.setCentralWidget(self.center)
        #设置菜单栏
        exitAction = QAction('&Exit', self)
        exitAction.setShortcut('Ctrl+Q')
        exitAction.setStatusTip('Exit application')
        exitAction.triggered.connect(qApp.quit)

        # 创建一个菜单栏
        menubar = self.menuBar()
        # 添加菜单
        fileMenu = menubar.addMenu('文件')
        fileMenu.addAction(exitAction)


        #设置底边栏
        statusTime = time.strftime("%Y-%m-%d",time.localtime())
        self.statusBar().showMessage(statusTime)
        #设置标题栏
        self.setGeometry(300, 300, 500, 400)
        self.setWindowTitle('蒙汉平行语料库自动对齐系统')

        self.show()


if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = MT()
    sys.exit(app.exec_())