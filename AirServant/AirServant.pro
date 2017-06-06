#-------------------------------------------------
#
# Project created by QtCreator 2017-05-23T23:07:42
#
#-------------------------------------------------

QT       += core gui network testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AirServant
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    login.cpp \
    logincontroller.cpp \
    servant.cpp \
    communication.cpp \
    aircommon.cpp \
    airpacket.cpp \
    handler.cpp \
    startup.cpp \
    log.cpp \
    beatcontroller.cpp \
    refreshuicontroller.cpp \
    requestcontroller.cpp

HEADERS  += mainwindow.h \
    login.h \
    logincontroller.h \
    servant.h \
    communication.h \
    headers.h \
    aircommon.h \
    airpacket.h \
    handler.h \
    startup.h \
    log.h \
    beatcontroller.h \
    refreshuicontroller.h \
    requestcontroller.h

FORMS    += mainwindow.ui \
    login.ui

DISTFILES += \
    serverAddr.dat
