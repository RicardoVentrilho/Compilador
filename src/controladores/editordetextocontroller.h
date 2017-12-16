#ifndef EDITORDETEXTOCONTROLLER_H
#define EDITORDETEXTOCONTROLLER_H

#include <QMainWindow>
#include <QStatusBar>
#include <QFile>
#include <QMessageBox>
#include <QDir>
#include <QTextStream>
#include <QPlainTextEdit>
#include <QDesktopWidget>
#include <QFileDialog>
#include <QSettings>
#include <QRect>
#include <QMenuBar>
#include <QApplication>
#include <QToolBar>

namespace controladores
{

class EditorDeTextoController : public QObjectData
{
public:
    EditorDeTextoController(QWidget* editorDeTextoView, QPlainTextEdit* campoTexto, QString arquivoAtual = QString());

    void aoFechar(QCloseEvent *event);

    void abra();
    void definaConfiguracoes();
    void leiaConfiguracoes();
    void setBarraDeStatus(QStatusBar *barraDeStatus);
    void mostreMensagemNaBarraDeStatus(QString mensagem, int timeOut = 0);
    void carregueArquivo(const QString &nomeDoArquivo);
    void setArquivoAtual(const QString &nomeDoArquivo);
    void crieArquivo();

    bool salveArquivo(const QString &nomeDoArquivo);
    bool talvezSalve();
    bool salve();
    bool salveComo();

    void adicioneSeparador(QMenu* menu);
    QAction *crieMenuNovo(QMenu* menuArquivo, QToolBar* menuToolBar);
    QAction *crieMenuAbrir(QMenu* menuArquivo, QToolBar* menuToolBar);
    QAction *crieMenuSalvar(QMenu* menuArquivo, QToolBar* menuToolBar);
    QAction *crieMenuSalvarComo(QMenu* menuArquivo);
    QAction *crieMenuFechar(QMenu* menuArquivo);
    QAction *crieMenuRecortar(QMenu *menuEditar, QToolBar *menuToolBar);
    QAction *crieMenuCopiar(QMenu *menuEditar, QToolBar *menuToolBar);
    QAction *crieMenuColar(QMenu *menuEditar, QToolBar *menuToolBar);

private:
    QStatusBar* barraDeStatus;
    QWidget* editorDeTextoView;
    QString arquivoAtual;
    QPlainTextEdit* campoTexto;
};

}

#endif // EDITORDETEXTOCONTROLLER_H
