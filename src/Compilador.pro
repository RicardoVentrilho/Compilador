#-------------------------------------------------
#
# Project created by QtCreator 2017-12-01T19:59:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Compilador
TEMPLATE = app
LIBS += -lfl -ly

FLEXSOURCES = negocio/lexico/lexico.l
BISONSOURCES = negocio/sintatico/sintatico.y

SOURCES += main.cpp \
    tela/editordetextoview.cpp \
    controladores/editordetextocontroller.cpp

HEADERS  += \
    tela/editordetextoview.h \
    controladores/editordetextocontroller.h

RESOURCES += \
    recursos.qrc
