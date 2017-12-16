#ifndef EDITORDETEXTOCONTROLLER_H
#define EDITORDETEXTOCONTROLLER_H

#include <QMainWindow>
#include <QStatusBar>

namespace controladores
{

class EditorDeTextoController
{
public:
    EditorDeTextoController();

    void setBarraDeStatus(QStatusBar *barraDeStatus);
    void mostreMensagemNaBarraDeStatus(const QString mensagem, int timeOut);
    void carregueArquivo(const QString &nomeDoArquivo);

private:
    QStatusBar* barraDeStatus;
};

}

#endif // EDITORDETEXTOCONTROLLER_H
