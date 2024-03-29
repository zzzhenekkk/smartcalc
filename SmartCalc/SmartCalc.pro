QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

QMAKE_CXXFLAGS += -Wa,-mbig-obj

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    creditform.cpp \
    main.cpp \
    mainwindow.cpp \ 
    qcustomplot.cpp \
    s21_credit_calc.c \
    s21_smartcalc.c \
    # "C:\Users\Андрей\Desktop\школа 21\base\smartcalc\s21_credit_calc.c" \
    # "C:\Users\Андрей\Desktop\школа 21\base\smartcalc\s21_smartcalc.c"

HEADERS += \
    creditform.h \
    mainwindow.h \
    qcustomplot.h \
    s21_smartcalc.h \
    # "C:/Users/Андрей/Desktop/школа 21/base/smartcalc/s21_smartcalc.h" \

FORMS += \
    creditform.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
