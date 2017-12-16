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

protected:
    void aoFechar(QCloseEvent *event);

private slots:
    void crieArquivo();
    void abra();
    bool salve();
    bool salveComo();
    void sobre();
    void arquivoFoiModificado();

private:
    const int ALTURA_RESULTADO_DA_COMPILACAO = 100;

    void crieAcoes();
    void crieBarraDeStatus();
    void leiaConfiguracoes();
    void escrevaConfiguracoes();
    bool talvezSalve();
    bool salveArquivo(const QString &nomeDoArquivo);
    void setArquivoAtual(const QString &nomeDoArquivo);

    ////TODO: Refatorar nome abaixo.
    QString strippedName(const QString &nomeCompletoDoArquivo);

    QPlainTextEdit *campoTexto, *resultadoDaCompilacao;
    QString arquivoAtual;
    void monteLayout();
    void crie_botao_novo(QMenu *menu_arquivo, QToolBar *toolbar_menu);

    EditorDeTextoController* controlador;
};

#endif
