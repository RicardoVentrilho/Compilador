#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "controladores/editordetextocontroller.h"

using namespace controladores;

class QAction;
class crie_acao_novo_arquivo;
class QPlainTextEdit;

class EditorDeTextoView : public QMainWindow
{
    Q_OBJECT

public:
    EditorDeTextoView();
    void carregueArquivo(const QString &nomeDoArquivo);

    void crieMenuComAcoesDeEditar();

protected:
    void aoFechar(QCloseEvent *event);
    void criMenuComAcoesDeArquivo();

private slots:
    void crieArquivo();
    void abra();
    bool salve();
    bool salveComo();
    void sobre();
    void arquivoFoiModificado();

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

    ////TODO: Refatorar nome abaixo
    QString strippedName(const QString &nomeCompletoDoArquivo);

    QPlainTextEdit *campoTexto, *resultadoDaCompilacao;
    QString arquivoAtual;

    EditorDeTextoController* controlador;
};

#endif
