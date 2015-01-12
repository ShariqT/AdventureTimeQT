#-------------------------------------------------
#
# Project created by QtCreator 2014-12-30T19:20:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AdventureTime
TEMPLATE = app


SOURCES += main.cpp\
        adventuretimeprogram.cpp \
    startwindow.cpp \
    setupwindow.cpp \
    player.cpp \
    errordialog.cpp

HEADERS  += adventuretimeprogram.h \
    startwindow.h \
    setupwindow.h \
    player.h \
    errordialog.h

FORMS    += \
    mainwindow.ui \
    startwindow.ui \
    setupwindow.ui \
    errordialog.ui

RESOURCES += \
    adventure_resources.qrc

CONFIG += c++11
