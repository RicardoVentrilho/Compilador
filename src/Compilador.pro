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
    negocio/estado.cpp \
    negocio/objeto.cpp \
    negocio/tabela.cpp \
    negocio/validacao.cpp \
    negocio/compiladorportugolparac.cpp \
    infraestrutura/utilitarios/excecao.cpp

HEADERS  += \
    tela/editordetextoview.h \
    controladores/editordetextocontroller.h \
    negocio/estado.h \
    negocio/objeto.h \
    negocio/tabela.h \
    negocio/validacao.h \
    negocio/compiladorportugolparac.h \
    infraestrutura/utilitarios/excecao.h

RESOURCES += \
    recursos.qrc
