#-------------------------------------------------
#
# Project created by QtCreator 2017-05-03T09:42:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Snake
TEMPLATE = app


SOURCES += main.cpp \
    mainWindow.cpp \
    movesnake.cpp \
    food.cpp \
    score.cpp \
    button.cpp \
    snakepart.cpp

HEADERS  += \
    mainWindow.h \
    movesnake.h \
    food.h \
    score.h \
    button.h \
    snakepart.h

FORMS    +=

RESOURCES += \
    resource.qrc
