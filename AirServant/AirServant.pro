#-------------------------------------------------
#
# Project created by QtCreator 2017-05-23T23:07:42
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AirServant
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    login.cpp \
    logincontroller.cpp \
    servant.cpp \
    communication.cpp \
    pack.cpp

HEADERS  += mainwindow.h \
    login.h \
    logincontroller.h \
    servant.h \
    communication.h \
    headers.h \
    pack.h

FORMS    += mainwindow.ui \
    login.ui

DISTFILES += \
    serverAddr.dat