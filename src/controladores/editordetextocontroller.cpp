#include "editordetextocontroller.h"

controladores::EditorDeTextoController::EditorDeTextoController(QWidget* editorDeTextoView,
                                                                QPlainTextEdit* campoTexto,
                                                                QString arquivoAtual)
    : editorDeTextoView(editorDeTextoView),
      arquivoAtual(arquivoAtual),
      campoTexto(campoTexto)
{
}

void controladores::EditorDeTextoController::setBarraDeStatus(QStatusBar* barraDeStatus)
{
    this->barraDeStatus = barraDeStatus;
}

void controladores::EditorDeTextoController::mostreMensagemNaBarraDeStatus(QString mensagem, int timeOut)
{
    barraDeStatus->showMessage(mensagem, timeOut);
}

void controladores::EditorDeTextoController::carregueArquivo(const QString &nomeDoArquivo)
{
    ////TODO: Refatorar essa parte abaixo
    QFile arquivo(nomeDoArquivo);
    if (!arquivo.open(QFile::ReadOnly | QFile::Text))
    {

        auto mensagem = QString("Não pode ler o aquivo " +
                                QDir::toNativeSeparators(nomeDoArquivo) +
                                ":\n" + arquivo.errorString() + ".");

        QMessageBox::warning(editorDeTextoView, QString("Aplicação"), mensagem);
        return;
    }

    QTextStream in(&arquivo);

#ifndef QT_NO_CURSOR
    QApplication::setOverrideCursor(Qt::WaitCursor);
#endif
    campoTexto->setPlainText(in.readAll());
#ifndef QT_NO_CURSOR
    QApplication::restoreOverrideCursor();
#endif

    setArquivoAtual(nomeDoArquivo);

    mostreMensagemNaBarraDeStatus(QString("File loaded"), 2000);
}

void controladores::EditorDeTextoController::setArquivoAtual(const QString &nomeDoArquivo)
{
    arquivoAtual = nomeDoArquivo;
    campoTexto->document()->setModified(false);

    editorDeTextoView->setWindowModified(false);

    QString titulo = arquivoAtual;

    if (arquivoAtual.isEmpty())
    {
        titulo = "sem-titulo.txt";
    }

    editorDeTextoView->setWindowFilePath(titulo);
}
