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
    void ao_fechar(QCloseEvent *event);

private slots:
    void crie_arquivo();
    void abra();
    bool salve();
    bool salve_como();
    void sobre();
    void documento_foi_modificado();

private:
    const int ALTURA_RESULTADO_DA_COMPILACAO = 100;

    void crieAcoes();
    void crieBarraDeStatus();
    void leiaConfiguracoes();
    void escrevaConfiguracoes();
    bool talvezSalve();
    bool salveArquivo(const QString &nome_do_arquivo);
    void setArquivoAberto(const QString &nome_do_arquivo);

    ////TODO: Refatorar nome abaixo.
    QString strippedName(const QString &nome_completo_do_arquivo);

    QPlainTextEdit *editorDeTexto, *resultadoDaCompilacao;
    QString arquivo_aberto;
    void monteLayout();
    void crie_botao_novo(QMenu *menu_arquivo, QToolBar *toolbar_menu);

    EditorDeTextoController* controlador;
};

#endif
