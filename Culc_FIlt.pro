QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    analogue_filters.cpp \
    filter_table.cpp \
    main.cpp \
    mainwindow.cpp \
    mpl.cpp \
    mpl_calculation.cpp \
    push_action_activated_on_mainwindow.cpp

HEADERS += \
    analogue_filters.h \
    filter_table.h \
    mainwindow.h \
    mpl.h \
    mpl_calculation.h

FORMS += \
    filter_table.ui \
    mainwindow.ui \
    mpl.ui

win32:RC_FILE = icon/file.rc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    123.py \
    CMakeLists.txt.user \
    Culc_FIlt.pro.user \
    fon.png \
    icon/BPF_2L_icon.png \
    icon/BPF_4L_icon.png \
    icon/BPF_AFR.png \
    icon/BPF_SVL.png \
    icon/BPF_SVL_icon.png \
    icon/BPF_icon.png \
    icon/Global_icon.png \
    icon/LC_BPF_P.png \
    icon/LC_BPF_T.png \
    icon/LC_REJ_P.png \
    icon/LC_REJ_T.png \
    icon/LC_VHF_P.png \
    icon/LC_VHF_T.png \
    icon/LC_VLF_P.png \
    icon/LC_VLF_P_MPL.png \
    icon/LC_VLF_T.png \
    icon/Loop_L_2_BPF.png \
    icon/Loop_L_4_BPF.png \
    icon/MPL_NO_SIMM.png \
    icon/MPL_SIMM.png \
    icon/REjF_AFR.png \
    icon/Reg_icon.png \
    icon/S_MPL_NO_SIMM.png \
    icon/S_MPL_SIMM.png \
    icon/VHF_AFR.png \
    icon/VHF_icon.png \
    icon/VLF_AFR.png \
    icon/VLF_MPL_icon.png \
    icon/VLF_icon.png \
    icon/app.ico \
    icon/app.png \
    icon/file.rc \
    icon/icon.ico \
    icon/icon.jpg \
    icon/icon_.ico \
    ty.png \
    ty1.png
