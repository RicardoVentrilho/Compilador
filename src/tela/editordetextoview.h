#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "controladores/editordetextocontroller.h"

using namespace controladores;

class QAction;
class QPlainTextEdit;

class EditorDeTextoView : public QMainWindow
{
    Q_OBJECT

public:
    EditorDeTextoView();
    void carregueArquivo(const QString &nomeDoArquivo);

protected:
    void aoFechar(QCloseEvent *event);
    void criMenuComAcoesDeArquivo();
    void crieMenuComAcoesDeEditar();
    void crieMenuComAcoesDeCompilar();

private slots:
    void crieArquivo();
    void abra();
    bool salve();
    bool salveComo();
    void sobre();
    void arquivoFoiModificado();
    void compile();

private:
    const int ALTURA_RESULTADO_DA_COMPILACAO = 100;

    void crieMenuComAcoes();
    void crieBarraDeStatus();
    void leiaConfiguracoes();
    void definaConfiguracoes();
    bool talvezSalve();
    bool salveArquivo(const QString &nomeDoArquivo);
    void setArquivoAtual(const QString &nomeDoArquivo);
    void monteLayout();

    QString nomeSimplificado(const QString &nomeCompletoDoArquivo);

    QPlainTextEdit *campoTexto, *resultadoDaCompilacao;
    QString arquivoAtual;

    EditorDeTextoController* controlador;
};

#endif
