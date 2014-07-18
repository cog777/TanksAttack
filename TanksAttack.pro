#-------------------------------------------------
#
# Project created by QtCreator 2014-06-29T20:33:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TanksAttack
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp\
        battlefield.cpp \
        tank.cpp \
    tankcontroller.cpp

HEADERS  += mainwindow.h\
         battlefield.h \
         tank.h \
    settings.h \
    tankcontroller.h

FORMS    += mainwindow.ui
