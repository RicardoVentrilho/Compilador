#include "editordetextocontroller.h"

controladores::EditorDeTextoController::EditorDeTextoController()
{
}

void controladores::EditorDeTextoController::setBarraDeStatus(QStatusBar* barraDeStatus)
{
    this->barraDeStatus = barraDeStatus;
}

void controladores::EditorDeTextoController::mostreMensagemNaBarraDeStatus(const QString mensagem, int timeOut = 0)
{
    barraDeStatus->showMessage(mensagem, timeOut);
}

void controladores::EditorDeTextoController::carregueArquivo(const QString &nomeDoArquivo)
{

    ////TODO: Refatorar essa parte abaixo
    QFile file(nomeDoArquivo);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Application"),
                             tr("Cannot read file %1:\n%2.")
                             .arg(QDir::toNativeSeparators(nomeDoArquivo), file.errorString()));
        return;
    }

    QTextStream in(&file);
#ifndef QT_NO_CURSOR
    QApplication::setOverrideCursor(Qt::WaitCursor);
#endif
    editorDeTexto->setPlainText(in.readAll());
#ifndef QT_NO_CURSOR
    QApplication::restoreOverrideCursor();
#endif

    setArquivoAberto(nomeDoArquivo);

    mostreMensagemNaBarraDeStatus(QString("File loaded"), 2000);
}
