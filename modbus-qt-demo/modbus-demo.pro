QT       += core gui serialbus serialport widgets

TARGET = a

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS HAVE_CONFIG_H

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/main.cpp \
    src/mainwindow.cpp \
    src/modbus.cc \
    src/serialsettingdialog.cc \
    src/device.cc \
    qrencode/bitstream.c \
    qrencode/mask.c \
    qrencode/mmask.c \
    qrencode/mqrspec.c \
    qrencode/qrencode.c \
    qrencode/qrinput.c \
    qrencode/qrspec.c \
    qrencode/rsecc.c \
    qrencode/split.c

HEADERS += \
    inc/mainwindow.h \
    inc/modbus.hpp \
    inc/serialsettingdialog.hpp \
    inc/serialinfo.hpp \
    inc/device.hpp \
    qrencode/bitstream.h \
    qrencode/mask.h \
    qrencode/mmask. h \
    qrencode/mqrspec.h \
    qrencode/qrencode.h \
    qrencode/qrencode_inner.h \
    qrencode/qrinput.h \
    qrencode/qrspec.h \
    qrencode/rsecc.h \
    qrencode/split.h

FORMS += \
    forms/mainwindow.ui \
    forms/deviceform.ui \
    forms/serialdialog.ui

TRANSLATIONS += \
    modbus-demo_zh_CN.ts

# Default rules for deployment.
qnx: target.path = build/
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    qrc/data.qrc
