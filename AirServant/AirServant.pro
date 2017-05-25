#-------------------------------------------------
#
# Project created by QtCreator 2017-05-23T23:07:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AirServant
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    login.cpp \
    logincontroller.cpp

HEADERS  += mainwindow.h \
    login.h \
    logincontroller.h

FORMS    += mainwindow.ui \
    login.ui
