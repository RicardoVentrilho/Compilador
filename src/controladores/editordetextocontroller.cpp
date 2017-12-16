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
    QFile arquivo(nomeDoArquivo);

    if (!arquivo.open(QFile::ReadOnly | QFile::Text))
    {

        auto mensagem = QString("Não pode ler o aquivo %1:\n%2.")
                        .arg(QDir::toNativeSeparators(nomeDoArquivo), arquivo.errorString());

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

bool controladores::EditorDeTextoController::salveArquivo(const QString &nomeDoArquivo)
{
    QFile arquivo(nomeDoArquivo);

    if (!arquivo.open(QFile::WriteOnly | QFile::Text))
    {

        auto mensagem = QString("Não pode escrever o aquivo %1:\n%2.")
                        .arg(QDir::toNativeSeparators(nomeDoArquivo), arquivo.errorString());

        QMessageBox::warning(editorDeTextoView, QString("Aplicação"), mensagem);

        return false;
    }

    QTextStream out(&arquivo);
#ifndef QT_NO_CURSOR
    QApplication::setOverrideCursor(Qt::WaitCursor);
#endif

    out << campoTexto->toPlainText();

#ifndef QT_NO_CURSOR
    QApplication::restoreOverrideCursor();
#endif

    setArquivoAtual(nomeDoArquivo);
    mostreMensagemNaBarraDeStatus(QString("%1 salvo...").arg(arquivoAtual), 2000);

    return true;
}

bool controladores::EditorDeTextoController::talvezSalve()
{
    if (!campoTexto->document()->isModified())
    {
        return true;
    }

    auto retorno = QMessageBox::warning(editorDeTextoView,
                                        QString("Aplicação"),
                                        QString("O arquivo foi modificado.\nDeseja salvar as alterações?"),
                                        QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    switch (retorno)
    {
        case QMessageBox::Save:
            return salve();
        case QMessageBox::Cancel:
            return false;
        default:
            break;
    }
    return true;
}

bool controladores::EditorDeTextoController::salve()
{
    if (arquivoAtual.isEmpty())
    {
        return salveComo();
    } else
    {
        return salveArquivo(arquivoAtual);
    }
}

bool controladores::EditorDeTextoController::salveComo()
{
    QFileDialog dialogo(editorDeTextoView);

    dialogo.setWindowModality(Qt::WindowModal);
    dialogo.setAcceptMode(QFileDialog::AcceptSave);

    if (dialogo.exec() != QDialog::Accepted)
    {
        return false;
    }

    return salveArquivo(dialogo.selectedFiles().first());
}
