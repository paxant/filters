# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'c:\Users\dwfen\Documents\Фильтры\filters\mainwindow.ui'
#
# Created by: PyQt5 UI code generator 5.15.11
#
# WARNING: Any manual changes made to this file will be lost when pyuic5 is
# run again.  Do not edit this file unless you know what you are doing.


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(487, 783)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.gridLayout_13 = QtWidgets.QGridLayout(self.centralwidget)
        self.gridLayout_13.setObjectName("gridLayout_13")
        spacerItem = QtWidgets.QSpacerItem(20, 40, QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Expanding)
        self.gridLayout_13.addItem(spacerItem, 0, 2, 1, 1)
        self.gridLayout = QtWidgets.QGridLayout()
        self.gridLayout.setObjectName("gridLayout")
        self.label = QtWidgets.QLabel(self.centralwidget)
        self.label.setObjectName("label")
        self.gridLayout.addWidget(self.label, 1, 0, 1, 1)
        self.gridLayout_13.addLayout(self.gridLayout, 1, 1, 1, 1)
        self.gridLayout_2 = QtWidgets.QGridLayout()
        self.gridLayout_2.setObjectName("gridLayout_2")
        self.REG = QtWidgets.QPushButton(self.centralwidget)
        self.REG.setStyleSheet("background-color: rgba(255, 255, 255, 125);")
        self.REG.setText("")
        self.REG.setObjectName("REG")
        self.gridLayout_2.addWidget(self.REG, 0, 3, 1, 1)
        self.VHF = QtWidgets.QPushButton(self.centralwidget)
        self.VHF.setStyleSheet("background-color: rgba(255, 255, 255, 125);")
        self.VHF.setText("")
        self.VHF.setObjectName("VHF")
        self.gridLayout_2.addWidget(self.VHF, 0, 2, 1, 1)
        self.VLF = QtWidgets.QPushButton(self.centralwidget)
        self.VLF.setStyleSheet("background-color: rgba(255, 255, 255, 125);")
        self.VLF.setText("")
        self.VLF.setObjectName("VLF")
        self.gridLayout_2.addWidget(self.VLF, 0, 1, 1, 1)
        self.BPF = QtWidgets.QPushButton(self.centralwidget)
        self.BPF.setStyleSheet("background-color: rgba(255, 255, 255, 125);")
        self.BPF.setText("")
        self.BPF.setObjectName("BPF")
        self.gridLayout_2.addWidget(self.BPF, 0, 4, 1, 1)
        self.gridLayout_13.addLayout(self.gridLayout_2, 2, 1, 1, 3)
        self.gridLayout_3 = QtWidgets.QGridLayout()
        self.gridLayout_3.setObjectName("gridLayout_3")
        self.BPF_SV = QtWidgets.QPushButton(self.centralwidget)
        self.BPF_SV.setStyleSheet("background-color: rgba(255, 255, 255, 125);")
        self.BPF_SV.setText("")
        self.BPF_SV.setObjectName("BPF_SV")
        self.gridLayout_3.addWidget(self.BPF_SV, 0, 1, 1, 1)
        self.BPF_4_L = QtWidgets.QPushButton(self.centralwidget)
        self.BPF_4_L.setStyleSheet("background-color: rgba(255, 255, 255, 125);")
        self.BPF_4_L.setText("")
        self.BPF_4_L.setObjectName("BPF_4_L")
        self.gridLayout_3.addWidget(self.BPF_4_L, 0, 2, 1, 1)
        self.SVCH_VLF = QtWidgets.QPushButton(self.centralwidget)
        self.SVCH_VLF.setStyleSheet("background-color: rgba(255, 255, 255, 125);")
        self.SVCH_VLF.setText("")
        self.SVCH_VLF.setObjectName("SVCH_VLF")
        self.gridLayout_3.addWidget(self.SVCH_VLF, 0, 0, 1, 1)
        self.BPF_2_L = QtWidgets.QPushButton(self.centralwidget)
        self.BPF_2_L.setStyleSheet("background-color: rgba(255, 255, 255, 125);")
        self.BPF_2_L.setText("")
        self.BPF_2_L.setObjectName("BPF_2_L")
        self.gridLayout_3.addWidget(self.BPF_2_L, 0, 3, 1, 1)
        self.gridLayout_13.addLayout(self.gridLayout_3, 3, 1, 1, 3)
        self.gridLayout_10 = QtWidgets.QGridLayout()
        self.gridLayout_10.setObjectName("gridLayout_10")
        self.label_6 = QtWidgets.QLabel(self.centralwidget)
        self.label_6.setMaximumSize(QtCore.QSize(16777215, 32))
        self.label_6.setStyleSheet("")
        self.label_6.setObjectName("label_6")
        self.gridLayout_10.addWidget(self.label_6, 0, 4, 1, 1)
        self.GHz = QtWidgets.QRadioButton(self.centralwidget)
        self.GHz.setStyleSheet("")
        self.GHz.setObjectName("GHz")
        self.gridLayout_10.addWidget(self.GHz, 1, 3, 1, 1)
        self.kHz = QtWidgets.QRadioButton(self.centralwidget)
        self.kHz.setStyleSheet("")
        self.kHz.setObjectName("kHz")
        self.gridLayout_10.addWidget(self.kHz, 1, 1, 1, 1)
        self.Hz = QtWidgets.QRadioButton(self.centralwidget)
        self.Hz.setStyleSheet("")
        self.Hz.setChecked(True)
        self.Hz.setAutoRepeat(False)
        self.Hz.setObjectName("Hz")
        self.gridLayout_10.addWidget(self.Hz, 1, 0, 1, 1)
        self.MHz = QtWidgets.QRadioButton(self.centralwidget)
        self.MHz.setStyleSheet("")
        self.MHz.setObjectName("MHz")
        self.gridLayout_10.addWidget(self.MHz, 1, 2, 1, 1)
        self.label_10 = QtWidgets.QLabel(self.centralwidget)
        self.label_10.setMinimumSize(QtCore.QSize(40, 0))
        self.label_10.setStyleSheet("")
        self.label_10.setObjectName("label_10")
        self.gridLayout_10.addWidget(self.label_10, 1, 5, 1, 1)
        self.Zv = QtWidgets.QTextEdit(self.centralwidget)
        self.Zv.setMaximumSize(QtCore.QSize(16777215, 32))
        self.Zv.setTabletTracking(True)
        self.Zv.setFocusPolicy(QtCore.Qt.ClickFocus)
        self.Zv.setObjectName("Zv")
        self.gridLayout_10.addWidget(self.Zv, 1, 4, 1, 1)
        self.gridLayout_13.addLayout(self.gridLayout_10, 4, 1, 1, 3)
        spacerItem1 = QtWidgets.QSpacerItem(0, 20, QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Minimum)
        self.gridLayout_13.addItem(spacerItem1, 5, 0, 1, 1)
        self.gridLayout_9 = QtWidgets.QGridLayout()
        self.gridLayout_9.setObjectName("gridLayout_9")
        self.F_pr = QtWidgets.QTextEdit(self.centralwidget)
        self.F_pr.setMaximumSize(QtCore.QSize(16777215, 32))
        self.F_pr.setFocusPolicy(QtCore.Qt.ClickFocus)
        self.F_pr.setFrameShape(QtWidgets.QFrame.StyledPanel)
        self.F_pr.setOverwriteMode(False)
        self.F_pr.setObjectName("F_pr")
        self.gridLayout_9.addWidget(self.F_pr, 4, 0, 1, 1)
        self.label_15 = QtWidgets.QLabel(self.centralwidget)
        self.label_15.setAlignment(QtCore.Qt.AlignCenter)
        self.label_15.setObjectName("label_15")
        self.gridLayout_9.addWidget(self.label_15, 0, 0, 1, 1)
        self.label_11 = QtWidgets.QLabel(self.centralwidget)
        self.label_11.setStyleSheet("")
        self.label_11.setAlignment(QtCore.Qt.AlignCenter)
        self.label_11.setObjectName("label_11")
        self.gridLayout_9.addWidget(self.label_11, 2, 0, 1, 1)
        self.label_5 = QtWidgets.QLabel(self.centralwidget)
        self.label_5.setMinimumSize(QtCore.QSize(40, 0))
        self.label_5.setStyleSheet("")
        self.label_5.setAlignment(QtCore.Qt.AlignCenter)
        self.label_5.setObjectName("label_5")
        self.gridLayout_9.addWidget(self.label_5, 4, 1, 1, 1)
        self.label_4 = QtWidgets.QLabel(self.centralwidget)
        self.label_4.setMaximumSize(QtCore.QSize(16777215, 32))
        self.label_4.setStyleSheet("")
        self.label_4.setAlignment(QtCore.Qt.AlignCenter)
        self.label_4.setObjectName("label_4")
        self.gridLayout_9.addWidget(self.label_4, 1, 0, 1, 1)
        self.label_22 = QtWidgets.QLabel(self.centralwidget)
        self.label_22.setAlignment(QtCore.Qt.AlignCenter)
        self.label_22.setObjectName("label_22")
        self.gridLayout_9.addWidget(self.label_22, 3, 0, 1, 1)
        self.gridLayout_13.addLayout(self.gridLayout_9, 5, 1, 1, 3)
        self.gridLayout_8 = QtWidgets.QGridLayout()
        self.gridLayout_8.setObjectName("gridLayout_8")
        self.F_reg = QtWidgets.QTextEdit(self.centralwidget)
        self.F_reg.setMaximumSize(QtCore.QSize(16777215, 32))
        self.F_reg.setTabletTracking(True)
        self.F_reg.setFocusPolicy(QtCore.Qt.ClickFocus)
        self.F_reg.setObjectName("F_reg")
        self.gridLayout_8.addWidget(self.F_reg, 5, 0, 1, 1)
        self.label_13 = QtWidgets.QLabel(self.centralwidget)
        self.label_13.setStyleSheet("")
        self.label_13.setAlignment(QtCore.Qt.AlignCenter)
        self.label_13.setObjectName("label_13")
        self.gridLayout_8.addWidget(self.label_13, 2, 0, 1, 1)
        self.label_20 = QtWidgets.QLabel(self.centralwidget)
        self.label_20.setAlignment(QtCore.Qt.AlignCenter)
        self.label_20.setObjectName("label_20")
        self.gridLayout_8.addWidget(self.label_20, 0, 0, 1, 1)
        self.label_17 = QtWidgets.QLabel(self.centralwidget)
        self.label_17.setMinimumSize(QtCore.QSize(40, 0))
        self.label_17.setAlignment(QtCore.Qt.AlignCenter)
        self.label_17.setObjectName("label_17")
        self.gridLayout_8.addWidget(self.label_17, 5, 1, 1, 1)
        self.label_16 = QtWidgets.QLabel(self.centralwidget)
        self.label_16.setAlignment(QtCore.Qt.AlignCenter)
        self.label_16.setObjectName("label_16")
        self.gridLayout_8.addWidget(self.label_16, 1, 0, 1, 1)
        self.label_23 = QtWidgets.QLabel(self.centralwidget)
        self.label_23.setAlignment(QtCore.Qt.AlignCenter)
        self.label_23.setObjectName("label_23")
        self.gridLayout_8.addWidget(self.label_23, 3, 0, 1, 1)
        self.gridLayout_13.addLayout(self.gridLayout_8, 7, 1, 1, 3)
        spacerItem2 = QtWidgets.QSpacerItem(40, 20, QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Minimum)
        self.gridLayout_13.addItem(spacerItem2, 7, 4, 1, 1)
        self.gridLayout_11 = QtWidgets.QGridLayout()
        self.gridLayout_11.setObjectName("gridLayout_11")
        self.label_18 = QtWidgets.QLabel(self.centralwidget)
        self.label_18.setMinimumSize(QtCore.QSize(40, 0))
        self.label_18.setAlignment(QtCore.Qt.AlignCenter)
        self.label_18.setObjectName("label_18")
        self.gridLayout_11.addWidget(self.label_18, 1, 1, 1, 1)
        self.label_19 = QtWidgets.QLabel(self.centralwidget)
        self.label_19.setAlignment(QtCore.Qt.AlignCenter)
        self.label_19.setObjectName("label_19")
        self.gridLayout_11.addWidget(self.label_19, 0, 0, 1, 1)
        self.Centaral_freq = QtWidgets.QTextEdit(self.centralwidget)
        self.Centaral_freq.setMaximumSize(QtCore.QSize(16777215, 32))
        self.Centaral_freq.setTabletTracking(True)
        self.Centaral_freq.setFocusPolicy(QtCore.Qt.ClickFocus)
        self.Centaral_freq.setObjectName("Centaral_freq")
        self.gridLayout_11.addWidget(self.Centaral_freq, 1, 0, 1, 1)
        self.gridLayout_13.addLayout(self.gridLayout_11, 8, 1, 1, 3)
        self.gridLayout_7 = QtWidgets.QGridLayout()
        self.gridLayout_7.setObjectName("gridLayout_7")
        self.A_L_z = QtWidgets.QTextEdit(self.centralwidget)
        self.A_L_z.setMaximumSize(QtCore.QSize(16777215, 32))
        self.A_L_z.setTabletTracking(True)
        self.A_L_z.setFocusPolicy(QtCore.Qt.ClickFocus)
        self.A_L_z.setObjectName("A_L_z")
        self.gridLayout_7.addWidget(self.A_L_z, 1, 0, 1, 1)
        self.A_L_dB = QtWidgets.QCheckBox(self.centralwidget)
        self.A_L_dB.setStyleSheet("")
        self.A_L_dB.setObjectName("A_L_dB")
        self.gridLayout_7.addWidget(self.A_L_dB, 1, 2, 1, 1)
        self.label_3 = QtWidgets.QLabel(self.centralwidget)
        self.label_3.setMaximumSize(QtCore.QSize(16777215, 32))
        self.label_3.setStyleSheet("")
        self.label_3.setAlignment(QtCore.Qt.AlignCenter)
        self.label_3.setObjectName("label_3")
        self.gridLayout_7.addWidget(self.label_3, 0, 1, 1, 1)
        self.A_L_pr = QtWidgets.QTextEdit(self.centralwidget)
        self.A_L_pr.setMaximumSize(QtCore.QSize(16777215, 32))
        self.A_L_pr.setTabletTracking(True)
        self.A_L_pr.setFocusPolicy(QtCore.Qt.ClickFocus)
        self.A_L_pr.setObjectName("A_L_pr")
        self.gridLayout_7.addWidget(self.A_L_pr, 1, 1, 1, 1)
        self.label_2 = QtWidgets.QLabel(self.centralwidget)
        self.label_2.setMaximumSize(QtCore.QSize(16777215, 32))
        self.label_2.setFocusPolicy(QtCore.Qt.NoFocus)
        self.label_2.setStyleSheet("")
        self.label_2.setTextFormat(QtCore.Qt.AutoText)
        self.label_2.setScaledContents(False)
        self.label_2.setAlignment(QtCore.Qt.AlignCenter)
        self.label_2.setObjectName("label_2")
        self.gridLayout_7.addWidget(self.label_2, 0, 0, 1, 1)
        self.gridLayout_13.addLayout(self.gridLayout_7, 9, 1, 1, 3)
        self.gridLayout_12 = QtWidgets.QGridLayout()
        self.gridLayout_12.setObjectName("gridLayout_12")
        self.label_8 = QtWidgets.QLabel(self.centralwidget)
        self.label_8.setAlignment(QtCore.Qt.AlignCenter)
        self.label_8.setObjectName("label_8")
        self.gridLayout_12.addWidget(self.label_8, 0, 1, 1, 1)
        self.textEdit = QtWidgets.QTextEdit(self.centralwidget)
        self.textEdit.setMaximumSize(QtCore.QSize(16777215, 32))
        self.textEdit.setObjectName("textEdit")
        self.gridLayout_12.addWidget(self.textEdit, 1, 0, 1, 1)
        self.label_9 = QtWidgets.QLabel(self.centralwidget)
        self.label_9.setAlignment(QtCore.Qt.AlignCenter)
        self.label_9.setObjectName("label_9")
        self.gridLayout_12.addWidget(self.label_9, 0, 2, 1, 1)
        self.label_12 = QtWidgets.QLabel(self.centralwidget)
        self.label_12.setAlignment(QtCore.Qt.AlignCenter)
        self.label_12.setObjectName("label_12")
        self.gridLayout_12.addWidget(self.label_12, 0, 0, 1, 1)
        self.textEdit_3 = QtWidgets.QTextEdit(self.centralwidget)
        self.textEdit_3.setMaximumSize(QtCore.QSize(16777215, 32))
        self.textEdit_3.setObjectName("textEdit_3")
        self.gridLayout_12.addWidget(self.textEdit_3, 1, 2, 1, 1)
        self.textEdit_2 = QtWidgets.QTextEdit(self.centralwidget)
        self.textEdit_2.setMaximumSize(QtCore.QSize(16777215, 32))
        self.textEdit_2.setObjectName("textEdit_2")
        self.gridLayout_12.addWidget(self.textEdit_2, 1, 1, 1, 1)
        self.gridLayout_13.addLayout(self.gridLayout_12, 10, 1, 1, 3)
        self.gridLayout_4 = QtWidgets.QGridLayout()
        self.gridLayout_4.setObjectName("gridLayout_4")
        self.label_14 = QtWidgets.QLabel(self.centralwidget)
        self.label_14.setAlignment(QtCore.Qt.AlignCenter)
        self.label_14.setObjectName("label_14")
        self.gridLayout_4.addWidget(self.label_14, 1, 0, 1, 1)
        self.comboBox_2 = QtWidgets.QComboBox(self.centralwidget)
        self.comboBox_2.setObjectName("comboBox_2")
        self.comboBox_2.addItem("")
        self.comboBox_2.addItem("")
        self.gridLayout_4.addWidget(self.comboBox_2, 2, 0, 1, 1)
        self.gridLayout_5 = QtWidgets.QGridLayout()
        self.gridLayout_5.setObjectName("gridLayout_5")
        self.label_7 = QtWidgets.QLabel(self.centralwidget)
        self.label_7.setStyleSheet("")
        self.label_7.setAlignment(QtCore.Qt.AlignCenter)
        self.label_7.setObjectName("label_7")
        self.gridLayout_5.addWidget(self.label_7, 0, 1, 1, 1)
        self.comboBox = QtWidgets.QComboBox(self.centralwidget)
        self.comboBox.setLayoutDirection(QtCore.Qt.LeftToRight)
        self.comboBox.setObjectName("comboBox")
        self.comboBox.addItem("")
        self.comboBox.addItem("")
        self.gridLayout_5.addWidget(self.comboBox, 1, 1, 1, 1)
        self.pushButton = QtWidgets.QPushButton(self.centralwidget)
        self.pushButton.setObjectName("pushButton")
        self.gridLayout_5.addWidget(self.pushButton, 1, 0, 1, 1)
        self.gridLayout_6 = QtWidgets.QGridLayout()
        self.gridLayout_6.setObjectName("gridLayout_6")
        self.label_21 = QtWidgets.QLabel(self.centralwidget)
        self.label_21.setLayoutDirection(QtCore.Qt.LeftToRight)
        self.label_21.setAlignment(QtCore.Qt.AlignCenter)
        self.label_21.setObjectName("label_21")
        self.gridLayout_6.addWidget(self.label_21, 0, 0, 1, 1)
        self.Stockpile = QtWidgets.QTextEdit(self.centralwidget)
        self.Stockpile.setMaximumSize(QtCore.QSize(70, 32))
        self.Stockpile.setObjectName("Stockpile")
        self.gridLayout_6.addWidget(self.Stockpile, 0, 1, 1, 1)
        self.gridLayout_5.addLayout(self.gridLayout_6, 0, 0, 1, 1)
        self.gridLayout_4.addLayout(self.gridLayout_5, 3, 0, 1, 1)
        self.gridLayout_13.addLayout(self.gridLayout_4, 11, 1, 1, 3)
        spacerItem3 = QtWidgets.QSpacerItem(20, 40, QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Expanding)
        self.gridLayout_13.addItem(spacerItem3, 12, 3, 1, 1)
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 487, 22))
        self.menubar.setObjectName("menubar")
        self.menu = QtWidgets.QMenu(self.menubar)
        self.menu.setObjectName("menu")
        self.menu_2 = QtWidgets.QMenu(self.menubar)
        self.menu_2.setObjectName("menu_2")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)
        self.action = QtWidgets.QAction(MainWindow)
        self.action.setObjectName("action")
        self.action_2 = QtWidgets.QAction(MainWindow)
        self.action_2.setObjectName("action_2")
        self.action_3 = QtWidgets.QAction(MainWindow)
        self.action_3.setObjectName("action_3")
        self.menu.addAction(self.action)
        self.menu.addAction(self.action_2)
        self.menu_2.addAction(self.action_3)
        self.menubar.addAction(self.menu.menuAction())
        self.menubar.addAction(self.menu_2.menuAction())

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.label.setText(_translate("MainWindow", "Расчет полиномиальных фильтров"))
        self.label_6.setText(_translate("MainWindow", "Сопротивление тракта"))
        self.GHz.setText(_translate("MainWindow", "ГГц"))
        self.kHz.setText(_translate("MainWindow", "кГц"))
        self.Hz.setText(_translate("MainWindow", "Гц"))
        self.MHz.setText(_translate("MainWindow", "Мгц"))
        self.label_10.setText(_translate("MainWindow", "Ом"))
        self.label_15.setText(_translate("MainWindow", "Частота заграждения фильтра"))
        self.label_11.setText(_translate("MainWindow", "Полоса пропускания"))
        self.label_5.setText(_translate("MainWindow", "Гц"))
        self.label_4.setText(_translate("MainWindow", "Частота среза фильтра"))
        self.label_22.setText(_translate("MainWindow", "Верхняя полоса заграждения"))
        self.label_13.setText(_translate("MainWindow", "Пополоса заграждения"))
        self.label_20.setText(_translate("MainWindow", "Частота среза"))
        self.label_17.setText(_translate("MainWindow", "Гц"))
        self.label_16.setText(_translate("MainWindow", "Частота заграждения"))
        self.label_23.setText(_translate("MainWindow", "Нижняя полоса заграждения"))
        self.label_18.setText(_translate("MainWindow", "Гц"))
        self.label_19.setText(_translate("MainWindow", "Центральная частота"))
        self.A_L_dB.setText(_translate("MainWindow", "дБ"))
        self.label_3.setText(_translate("MainWindow", "Затухание в полосе пропускания"))
        self.label_2.setText(_translate("MainWindow", "Затухание в полосе заграждения"))
        self.label_8.setText(_translate("MainWindow", "b или h, мм"))
        self.label_9.setText(_translate("MainWindow", "t, мм"))
        self.label_12.setText(_translate("MainWindow", "Er"))
        self.label_14.setText(_translate("MainWindow", "Вид МПЛ"))
        self.comboBox_2.setItemText(0, _translate("MainWindow", "Симметричная МПЛ"))
        self.comboBox_2.setItemText(1, _translate("MainWindow", "Несимметричная МПЛ"))
        self.label_7.setText(_translate("MainWindow", "Выбор аппроксимации характеристики"))
        self.comboBox.setItemText(0, _translate("MainWindow", "Баттерворт"))
        self.comboBox.setItemText(1, _translate("MainWindow", "Чебышев"))
        self.pushButton.setText(_translate("MainWindow", "Расчет"))
        self.label_21.setText(_translate("MainWindow", "Запас по порядку фильтра:"))
        self.menu.setTitle(_translate("MainWindow", "Меню"))
        self.menu_2.setTitle(_translate("MainWindow", "Подпрограммы"))
        self.action.setText(_translate("MainWindow", "Вернуться на главную страницу"))
        self.action_2.setText(_translate("MainWindow", "Выход"))
        self.action_3.setText(_translate("MainWindow", "Расчет МПЛ передчи"))
