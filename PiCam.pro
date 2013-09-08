#-------------------------------------------------
#
# Project created by QtCreator 2013-09-08T15:40:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PiCam
TEMPLATE = app


SOURCES += main.cpp\
        picam.cpp \
    camerawidget.cpp

HEADERS  += picam.h \
    camerawidget.h

FORMS    += picam.ui

INCLUDEPATH += /usr/local/include/opencv
LIBS += -lopencv_core \
        -lopencv_highgui
