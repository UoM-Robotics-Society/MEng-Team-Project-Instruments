# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'orchestraGUIv3.ui'
#
# Created by: PyQt4 UI code generator 4.11.4
#
# WARNING! All changes made in this file will be lost!

from PyQt4 import QtCore, QtGui

try:
    _fromUtf8 = QtCore.QString.fromUtf8
except AttributeError:
    def _fromUtf8(s):
        return s

try:
    _encoding = QtGui.QApplication.UnicodeUTF8
    def _translate(context, text, disambig):
        return QtGui.QApplication.translate(context, text, disambig, _encoding)
except AttributeError:
    def _translate(context, text, disambig):
        return QtGui.QApplication.translate(context, text, disambig)

class Ui_Dialog(object):
    def setupUi(self, Dialog):
        Dialog.setObjectName(_fromUtf8("Dialog"))
        Dialog.setWindowModality(QtCore.Qt.WindowModal)
        Dialog.setEnabled(True)
        Dialog.resize(582, 471)
        Dialog.setMouseTracking(False)
        Dialog.setAcceptDrops(False)
        Dialog.setAutoFillBackground(False)
        self.selectFileType = QtGui.QTabWidget(Dialog)
        self.selectFileType.setGeometry(QtCore.QRect(13, 13, 550, 470))
        self.selectFileType.setAutoFillBackground(False)
        self.selectFileType.setObjectName(_fromUtf8("selectFileType"))
        self.tab = QtGui.QWidget()
        self.tab.setObjectName(_fromUtf8("tab"))
        self.verticalLayout = QtGui.QVBoxLayout(self.tab)
        self.verticalLayout.setObjectName(_fromUtf8("verticalLayout"))
        self.horizontalLayout_2 = QtGui.QHBoxLayout()
        self.horizontalLayout_2.setObjectName(_fromUtf8("horizontalLayout_2"))
        self.label = QtGui.QLabel(self.tab)
        font = QtGui.QFont()
        font.setPointSize(9)
        self.label.setFont(font)
        self.label.setObjectName(_fromUtf8("label"))
        self.horizontalLayout_2.addWidget(self.label)
        self.lineEdit = QtGui.QLineEdit(self.tab)
        font = QtGui.QFont()
        font.setItalic(True)
        self.lineEdit.setFont(font)
        self.lineEdit.setObjectName(_fromUtf8("lineEdit"))
        self.horizontalLayout_2.addWidget(self.lineEdit)
        self.btnCardLocation = QtGui.QToolButton(self.tab)
        self.btnCardLocation.setObjectName(_fromUtf8("btnCardLocation"))
        self.horizontalLayout_2.addWidget(self.btnCardLocation)
        self.verticalLayout.addLayout(self.horizontalLayout_2)
        self.horizontalLayout = QtGui.QHBoxLayout()
        self.horizontalLayout.setObjectName(_fromUtf8("horizontalLayout"))
        self.MIDILabel = QtGui.QLabel(self.tab)
        font = QtGui.QFont()
        font.setPointSize(9)
        font.setBold(False)
        font.setWeight(50)
        self.MIDILabel.setFont(font)
        self.MIDILabel.setObjectName(_fromUtf8("MIDILabel"))
        self.horizontalLayout.addWidget(self.MIDILabel)
        self.lineEdit_2 = QtGui.QLineEdit(self.tab)
        self.lineEdit_2.setObjectName(_fromUtf8("lineEdit_2"))
        self.horizontalLayout.addWidget(self.lineEdit_2)
        self.btnMIDILocation = QtGui.QToolButton(self.tab)
        self.btnMIDILocation.setObjectName(_fromUtf8("btnMIDILocation"))
        self.horizontalLayout.addWidget(self.btnMIDILocation)
        self.verticalLayout.addLayout(self.horizontalLayout)
        self.line = QtGui.QFrame(self.tab)
        self.line.setFrameShape(QtGui.QFrame.HLine)
        self.line.setFrameShadow(QtGui.QFrame.Sunken)
        self.line.setObjectName(_fromUtf8("line"))
        self.verticalLayout.addWidget(self.line)
        self.horizontalLayout_5 = QtGui.QHBoxLayout()
        self.horizontalLayout_5.setObjectName(_fromUtf8("horizontalLayout_5"))
        self.horizontalLayout_4 = QtGui.QHBoxLayout()
        self.horizontalLayout_4.setObjectName(_fromUtf8("horizontalLayout_4"))
        self.SelectInstrumentLabel = QtGui.QLabel(self.tab)
        self.SelectInstrumentLabel.setMaximumSize(QtCore.QSize(16777215, 100))
        font = QtGui.QFont()
        font.setPointSize(9)
        font.setBold(False)
        font.setWeight(50)
        self.SelectInstrumentLabel.setFont(font)
        self.SelectInstrumentLabel.setObjectName(_fromUtf8("SelectInstrumentLabel"))
        self.horizontalLayout_4.addWidget(self.SelectInstrumentLabel)
        spacerItem = QtGui.QSpacerItem(28, 20, QtGui.QSizePolicy.Expanding, QtGui.QSizePolicy.Minimum)
        self.horizontalLayout_4.addItem(spacerItem)
        self.horizontalLayout_5.addLayout(self.horizontalLayout_4)
        self.selectInstrument = QtGui.QComboBox(self.tab)
        self.selectInstrument.setObjectName(_fromUtf8("selectInstrument"))
        self.selectInstrument.addItem(_fromUtf8(""))
        self.selectInstrument.addItem(_fromUtf8(""))
        self.selectInstrument.addItem(_fromUtf8(""))
        self.selectInstrument.addItem(_fromUtf8(""))
        self.horizontalLayout_5.addWidget(self.selectInstrument)
        self.verticalLayout.addLayout(self.horizontalLayout_5)
        self.horizontalLayout_6 = QtGui.QHBoxLayout()
        self.horizontalLayout_6.setObjectName(_fromUtf8("horizontalLayout_6"))
        self.label_4 = QtGui.QLabel(self.tab)
        font = QtGui.QFont()
        font.setPointSize(9)
        font.setBold(False)
        font.setWeight(50)
        self.label_4.setFont(font)
        self.label_4.setObjectName(_fromUtf8("label_4"))
        self.horizontalLayout_6.addWidget(self.label_4)
        spacerItem1 = QtGui.QSpacerItem(128, 20, QtGui.QSizePolicy.Expanding, QtGui.QSizePolicy.Minimum)
        self.horizontalLayout_6.addItem(spacerItem1)
        self.tabFileType = QtGui.QComboBox(self.tab)
        self.tabFileType.setObjectName(_fromUtf8("tabFileType"))
        self.tabFileType.addItem(_fromUtf8(""))
        self.tabFileType.addItem(_fromUtf8(""))
        self.horizontalLayout_6.addWidget(self.tabFileType)
        self.verticalLayout.addLayout(self.horizontalLayout_6)
        self.checkMIDI = QtGui.QCheckBox(self.tab)
        font = QtGui.QFont()
        font.setBold(True)
        font.setWeight(75)
        self.checkMIDI.setFont(font)
        self.checkMIDI.setObjectName(_fromUtf8("checkMIDI"))
        self.verticalLayout.addWidget(self.checkMIDI)
        self.line_2 = QtGui.QFrame(self.tab)
        self.line_2.setFrameShape(QtGui.QFrame.HLine)
        self.line_2.setFrameShadow(QtGui.QFrame.Sunken)
        self.line_2.setObjectName(_fromUtf8("line_2"))
        self.verticalLayout.addWidget(self.line_2)
        self.horizontalLayout_7 = QtGui.QHBoxLayout()
        self.horizontalLayout_7.setObjectName(_fromUtf8("horizontalLayout_7"))
        spacerItem2 = QtGui.QSpacerItem(148, 17, QtGui.QSizePolicy.Expanding, QtGui.QSizePolicy.Minimum)
        self.horizontalLayout_7.addItem(spacerItem2)
        self.btnUpload = QtGui.QPushButton(self.tab)
        font = QtGui.QFont()
        font.setPointSize(10)
        font.setBold(True)
        font.setWeight(75)
        self.btnUpload.setFont(font)
        self.btnUpload.setObjectName(_fromUtf8("btnUpload"))
        self.horizontalLayout_7.addWidget(self.btnUpload)
        self.pushButton = QtGui.QPushButton(self.tab)
        self.pushButton.setObjectName(_fromUtf8("pushButton"))
        self.horizontalLayout_7.addWidget(self.pushButton)
        self.verticalLayout.addLayout(self.horizontalLayout_7)
        self.selectFileType.addTab(self.tab, _fromUtf8(""))
        self.tab_2 = QtGui.QWidget()
        self.tab_2.setObjectName(_fromUtf8("tab_2"))
        self.verticalLayout_2 = QtGui.QVBoxLayout(self.tab_2)
        self.verticalLayout_2.setObjectName(_fromUtf8("verticalLayout_2"))
        self.line_5 = QtGui.QFrame(self.tab_2)
        self.line_5.setFrameShape(QtGui.QFrame.HLine)
        self.line_5.setFrameShadow(QtGui.QFrame.Sunken)
        self.line_5.setObjectName(_fromUtf8("line_5"))
        self.verticalLayout_2.addWidget(self.line_5)
        self.label_5 = QtGui.QLabel(self.tab_2)
        font = QtGui.QFont()
        font.setPointSize(9)
        font.setBold(False)
        font.setWeight(50)
        self.label_5.setFont(font)
        self.label_5.setObjectName(_fromUtf8("label_5"))
        self.verticalLayout_2.addWidget(self.label_5)
        self.checKeyboard = QtGui.QCheckBox(self.tab_2)
        font = QtGui.QFont()
        font.setBold(True)
        font.setWeight(75)
        self.checKeyboard.setFont(font)
        self.checKeyboard.setObjectName(_fromUtf8("checKeyboard"))
        self.verticalLayout_2.addWidget(self.checKeyboard)
        self.checkStepper = QtGui.QCheckBox(self.tab_2)
        font = QtGui.QFont()
        font.setBold(True)
        font.setWeight(75)
        self.checkStepper.setFont(font)
        self.checkStepper.setObjectName(_fromUtf8("checkStepper"))
        self.verticalLayout_2.addWidget(self.checkStepper)
        self.checkXylophone = QtGui.QCheckBox(self.tab_2)
        font = QtGui.QFont()
        font.setBold(True)
        font.setWeight(75)
        self.checkXylophone.setFont(font)
        self.checkXylophone.setObjectName(_fromUtf8("checkXylophone"))
        self.verticalLayout_2.addWidget(self.checkXylophone)
        self.checkTesla = QtGui.QCheckBox(self.tab_2)
        font = QtGui.QFont()
        font.setBold(True)
        font.setWeight(75)
        self.checkTesla.setFont(font)
        self.checkTesla.setObjectName(_fromUtf8("checkTesla"))
        self.verticalLayout_2.addWidget(self.checkTesla)
        self.checkAll = QtGui.QCheckBox(self.tab_2)
        font = QtGui.QFont()
        font.setBold(True)
        font.setWeight(75)
        self.checkAll.setFont(font)
        self.checkAll.setObjectName(_fromUtf8("checkAll"))
        self.verticalLayout_2.addWidget(self.checkAll)
        spacerItem3 = QtGui.QSpacerItem(20, 21, QtGui.QSizePolicy.Minimum, QtGui.QSizePolicy.Expanding)
        self.verticalLayout_2.addItem(spacerItem3)
        self.label_6 = QtGui.QLabel(self.tab_2)
        font = QtGui.QFont()
        font.setPointSize(9)
        font.setBold(False)
        font.setWeight(50)
        self.label_6.setFont(font)
        self.label_6.setObjectName(_fromUtf8("label_6"))
        self.verticalLayout_2.addWidget(self.label_6)
        self.SelectSong = QtGui.QComboBox(self.tab_2)
        self.SelectSong.setObjectName(_fromUtf8("SelectSong"))
        self.SelectSong.addItem(_fromUtf8(""))
        self.SelectSong.addItem(_fromUtf8(""))
        self.SelectSong.addItem(_fromUtf8(""))
        self.verticalLayout_2.addWidget(self.SelectSong)
        spacerItem4 = QtGui.QSpacerItem(20, 15, QtGui.QSizePolicy.Minimum, QtGui.QSizePolicy.Expanding)
        self.verticalLayout_2.addItem(spacerItem4)
        self.line_3 = QtGui.QFrame(self.tab_2)
        self.line_3.setFrameShape(QtGui.QFrame.HLine)
        self.line_3.setFrameShadow(QtGui.QFrame.Sunken)
        self.line_3.setObjectName(_fromUtf8("line_3"))
        self.verticalLayout_2.addWidget(self.line_3)
        self.horizontalLayout_3 = QtGui.QHBoxLayout()
        self.horizontalLayout_3.setObjectName(_fromUtf8("horizontalLayout_3"))
        spacerItem5 = QtGui.QSpacerItem(88, 28, QtGui.QSizePolicy.Expanding, QtGui.QSizePolicy.Minimum)
        self.horizontalLayout_3.addItem(spacerItem5)
        self.btnPlay = QtGui.QPushButton(self.tab_2)
        font = QtGui.QFont()
        font.setPointSize(10)
        font.setBold(True)
        font.setWeight(75)
        self.btnPlay.setFont(font)
        self.btnPlay.setAutoFillBackground(False)
        self.btnPlay.setStyleSheet(_fromUtf8("QPushButton{ background-color: rgb(0, 255, 0); }\n"
""))
        self.btnPlay.setObjectName(_fromUtf8("btnPlay"))
        self.horizontalLayout_3.addWidget(self.btnPlay)
        spacerItem6 = QtGui.QSpacerItem(40, 28, QtGui.QSizePolicy.Expanding, QtGui.QSizePolicy.Minimum)
        self.horizontalLayout_3.addItem(spacerItem6)
        self.btnStop = QtGui.QPushButton(self.tab_2)
        font = QtGui.QFont()
        font.setPointSize(10)
        font.setBold(True)
        font.setWeight(75)
        self.btnStop.setFont(font)
        self.btnStop.setStyleSheet(_fromUtf8("QPushButton{ background-color: rgb(255, 0, 0)}"))
        self.btnStop.setObjectName(_fromUtf8("btnStop"))
        self.horizontalLayout_3.addWidget(self.btnStop)
        spacerItem7 = QtGui.QSpacerItem(128, 38, QtGui.QSizePolicy.Expanding, QtGui.QSizePolicy.Minimum)
        self.horizontalLayout_3.addItem(spacerItem7)
        self.verticalLayout_2.addLayout(self.horizontalLayout_3)
        self.line_4 = QtGui.QFrame(self.tab_2)
        self.line_4.setFrameShape(QtGui.QFrame.HLine)
        self.line_4.setFrameShadow(QtGui.QFrame.Sunken)
        self.line_4.setObjectName(_fromUtf8("line_4"))
        self.verticalLayout_2.addWidget(self.line_4)
        spacerItem8 = QtGui.QSpacerItem(20, 16, QtGui.QSizePolicy.Minimum, QtGui.QSizePolicy.Expanding)
        self.verticalLayout_2.addItem(spacerItem8)
        self.selectFileType.addTab(self.tab_2, _fromUtf8(""))

        self.retranslateUi(Dialog)
        self.selectFileType.setCurrentIndex(1)
        self.selectInstrument.setCurrentIndex(2)
        self.tabFileType.setCurrentIndex(0)
        QtCore.QObject.connect(self.checkAll, QtCore.SIGNAL(_fromUtf8("toggled(bool)")), self.checkTesla.click)
        QtCore.QObject.connect(self.checkAll, QtCore.SIGNAL(_fromUtf8("clicked()")), self.checkXylophone.click)
        QtCore.QObject.connect(self.checkAll, QtCore.SIGNAL(_fromUtf8("clicked()")), self.checkStepper.click)
        QtCore.QObject.connect(self.checkAll, QtCore.SIGNAL(_fromUtf8("clicked()")), self.checKeyboard.click)
        QtCore.QMetaObject.connectSlotsByName(Dialog)

    def retranslateUi(self, Dialog):
        Dialog.setWindowTitle(_translate("Dialog", "theSoundBytes - Conductor", None))
        self.label.setText(_translate("Dialog", "Save As:", None))
        self.lineEdit.setText(_translate("Dialog", "Untitled", None))
        self.btnCardLocation.setText(_translate("Dialog", "...", None))
        self.MIDILabel.setText(_translate("Dialog", "Select MIDI File:", None))
        self.btnMIDILocation.setText(_translate("Dialog", "...", None))
        self.SelectInstrumentLabel.setText(_translate("Dialog", "Select Instrument:", None))
        self.selectInstrument.setItemText(0, _translate("Dialog", "Keyboard", None))
        self.selectInstrument.setItemText(1, _translate("Dialog", "Xylophone", None))
        self.selectInstrument.setItemText(2, _translate("Dialog", "Stepper Motors", None))
        self.selectInstrument.setItemText(3, _translate("Dialog", "Tesla Coil", None))
        self.label_4.setText(_translate("Dialog", "File type:", None))
        self.tabFileType.setItemText(0, _translate("Dialog", "Binary ", None))
        self.tabFileType.setItemText(1, _translate("Dialog", "Text ", None))
        self.checkMIDI.setText(_translate("Dialog", "Copy  MIDI File ", None))
        self.btnUpload.setText(_translate("Dialog", "Convert", None))
        self.pushButton.setText(_translate("Dialog", "Cancel", None))
        self.selectFileType.setTabText(self.selectFileType.indexOf(self.tab), _translate("Dialog", "SD Card Management", None))
        self.label_5.setText(_translate("Dialog", "Select Instrument :", None))
        self.checKeyboard.setText(_translate("Dialog", "Keyboard", None))
        self.checkStepper.setText(_translate("Dialog", "Stepper Motors", None))
        self.checkXylophone.setText(_translate("Dialog", "Xylophone", None))
        self.checkTesla.setText(_translate("Dialog", "Tesla Coil", None))
        self.checkAll.setText(_translate("Dialog", "All", None))
        self.label_6.setText(_translate("Dialog", "Select Track:", None))
        self.SelectSong.setItemText(0, _translate("Dialog", "Californication (Red Hot Chilli Peppers)", None))
        self.SelectSong.setItemText(1, _translate("Dialog", "Game of Thrones Theme Song", None))
        self.SelectSong.setItemText(2, _translate("Dialog", "Eye of the Tiger (Survivor)", None))
        self.btnPlay.setText(_translate("Dialog", "Play", None))
        self.btnStop.setText(_translate("Dialog", "Stop", None))
        self.selectFileType.setTabText(self.selectFileType.indexOf(self.tab_2), _translate("Dialog", "Orchestra Settings", None))

