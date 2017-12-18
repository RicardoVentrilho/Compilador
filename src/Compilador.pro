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
    infraestrutura/utilitarios/excecao.cpp \
    negocio/analisadorlexico.cpp \
    negocio/token.cpp \
    negocio/compiladorportugol.cpp \
    negocio/tabeladesimbolos.cpp \
    negocio/analisadorsemantico.cpp

HEADERS  += \
    tela/editordetextoview.h \
    controladores/editordetextocontroller.h \
    negocio/estado.h \
    negocio/objeto.h \
    negocio/tabela.h \
    negocio/validacao.h \
    infraestrutura/utilitarios/excecao.h \
    negocio/analisadorlexico.h \
    negocio/token.h \
    enumeradores/enumtoken.h \
    negocio/compiladorportugol.h \
    negocio/tabeladesimbolos.h \
    negocio/analisadorsemantico.h

RESOURCES += \
    recursos.qrc
