#-------------------------------------------------
#
# Project created by QtCreator 2016-05-12T05:48:49
#
#-------------------------------------------------

QT       += core gui \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Taiko11
TEMPLATE = app


SOURCES += main.cpp \
    myrect.cpp \
    game.cpp \
    score.cpp \
    red_drum.cpp \
    blue_drum.cpp \
    target.cpp \
    mytimer.cpp \
    button.cpp

HEADERS  += \
    myrect.h \
    game.h \
    score.h \
    red_drum.h \
    blue_drum.h \
    target.h \
    mytimer.h \
    button.h

FORMS    +=

RESOURCES += \
    res.qrc
