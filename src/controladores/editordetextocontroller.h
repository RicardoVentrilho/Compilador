#ifndef EDITORDETEXTOCONTROLLER_H
#define EDITORDETEXTOCONTROLLER_H

#include <QMainWindow>
#include <QStatusBar>
#include <QFile>
#include <QMessageBox>
#include <QDir>
#include <QTextStream>
#include <QPlainTextEdit>
#include <QApplication>

namespace controladores
{

class EditorDeTextoController
{
public:
    EditorDeTextoController(QWidget* editorDeTextoView, QPlainTextEdit* campoTexto, QString arquivoAtual = QString());

    void setBarraDeStatus(QStatusBar *barraDeStatus);
    void mostreMensagemNaBarraDeStatus(QString mensagem, int timeOut = 0);
    void carregueArquivo(const QString &nomeDoArquivo);
    void setArquivoAtual(const QString &nomeDoArquivo);

    bool salveArquivo(const QString &nomeDoArquivo);

private:
    QStatusBar* barraDeStatus;
    QWidget* editorDeTextoView;
    QString arquivoAtual;
    QPlainTextEdit* campoTexto;
};

}

#endif // EDITORDETEXTOCONTROLLER_H
