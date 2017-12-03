#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QAction;
class crie_acao_novo_arquivo;
class QPlainTextEdit;

class TelaPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    TelaPrincipal();
    void carregue_arquivo(const QString &nome_do_arquivo);

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
    void crie_acoes();
    void crie_barra_de_status();
    void leia_configuracoes();
    void escreva_configuracoes();
    bool talvez_salve();
    bool salve_arquivo(const QString &nome_do_arquivo);
    void set_arquivo_aberto(const QString &nome_do_arquivo);
    ////TODO: Refatorar nome abaixo.
    QString strippedName(const QString &nome_completo_do_arquivo);

    QPlainTextEdit *editor_de_texto;
    QString arquivo_aberto;
};

#endif
