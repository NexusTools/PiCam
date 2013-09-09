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
    camerawidget.cpp \
    cameraworker.cpp

HEADERS  += picam.h \
    camerawidget.h \
    cameraworker.h

FORMS    += picam.ui

LIBS += -lopencv_core \
    -lopencv_highgui
