#-------------------------------------------------
#
# Project created by QtCreator 2017-12-01T19:59:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Compilador
TEMPLATE = app
#LIBS += -lfl -ly

FLEXSOURCES = negocio/lexico/lexico.l
BISONSOURCES = negocio/sintatico/sintatico.y

SOURCES += main.cpp \
    tela/editordetextoview.cpp \
    controladores/editordetextocontroller.cpp \
    negocio/Objeto.cpp \
    negocio/Estado.cpp \
    negocio/Tabela.cpp \
    negocio/Validacao.cpp \
    negocio/Objeto.cpp \
    negocio/Tabela.cpp \
    negocio/Validacao.cpp \
    negocio/Estado.cpp

HEADERS  += \
    tela/editordetextoview.h \
    controladores/editordetextocontroller.h \
    negocio/Objeto.h \
    negocio/Estado.h \
    negocio/Tabela.h \
    negocio/Validacao.h \
    negocio/Estado.h \
    negocio/Objeto.h \
    negocio/Tabela.h \
    negocio/Validacao.h

RESOURCES += \
    recursos.qrc
