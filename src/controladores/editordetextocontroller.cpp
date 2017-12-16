#include "editordetextocontroller.h"

controladores::EditorDeTextoController::EditorDeTextoController(QWidget* editorDeTextoView,
                                                                QPlainTextEdit* campoTexto,
                                                                QString arquivoAtual)
    : editorDeTextoView(editorDeTextoView),
      arquivoAtual(arquivoAtual),
      campoTexto(campoTexto)
{
}

void controladores::EditorDeTextoController::aoFechar(QCloseEvent *event)
{
    if (talvezSalve()) {
        definaConfiguracoes();
        event->accept();
    } else {
        event->ignore();
    }
}

void controladores::EditorDeTextoController::definaConfiguracoes()
{
    QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());
    settings.setValue("geometria", editorDeTextoView->saveGeometry());
}

void controladores::EditorDeTextoController::leiaConfiguracoes()
{
    QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());

    const QByteArray geometria = settings.value("geometria", QByteArray()).toByteArray();

    if (geometria.isEmpty())
    {
        auto geomotriaAplicacao = QApplication::desktop()->availableGeometry(editorDeTextoView);

        editorDeTextoView->resize(geomotriaAplicacao.width() / 3, geomotriaAplicacao.height() / 2);
        editorDeTextoView->move((geomotriaAplicacao.width() - editorDeTextoView->width()) / 2,
                                (geomotriaAplicacao.height() - editorDeTextoView->height()) / 2);
    } else
    {
        editorDeTextoView->restoreGeometry(geometria);
    }
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

void controladores::EditorDeTextoController::crieArquivo()
{
    if (talvezSalve())
    {
        campoTexto->clear();
        setArquivoAtual(QString());
    }
}

void controladores::EditorDeTextoController::abra()
{
    if (talvezSalve())
    {
        QString nomeDoArquivo = QFileDialog::getOpenFileName(editorDeTextoView);

        if (!nomeDoArquivo.isEmpty())
        {
            carregueArquivo(nomeDoArquivo);
        }
    }
}

QAction* controladores::EditorDeTextoController::crieMenuNovo(QMenu* menuArquivo, QToolBar* menuToolBar)
{
    auto iconeNovo = QIcon::fromTheme("novo-documento", QIcon(":/imagens/novo.png"));
    auto acaoNovo = new QAction(iconeNovo, QString("Novo"), editorDeTextoView);

    acaoNovo->setShortcuts(QKeySequence::New);
    acaoNovo->setStatusTip(QString("Criar novo arquivo"));

    menuArquivo->addAction(acaoNovo);
    menuToolBar->addAction(acaoNovo);

    return acaoNovo;
}

QAction* controladores::EditorDeTextoController::crieMenuAbrir(QMenu* menuArquivo, QToolBar* menuToolBar)
{
    auto iconeAbrir = QIcon::fromTheme("document-open", QIcon(":/imagens/abrir.png"));
    auto acaoAbrir = new QAction(iconeAbrir, QString("Abrir..."), editorDeTextoView);

    acaoAbrir->setShortcuts(QKeySequence::Open);
    acaoAbrir->setStatusTip(QString("Abrir arquivo existente"));

    menuArquivo->addAction(acaoAbrir);
    menuToolBar->addAction(acaoAbrir);

    return acaoAbrir;
}

QAction* controladores::EditorDeTextoController::crieMenuSalvar(QMenu* menuArquivo, QToolBar* menuToolBar)
{
    auto iconeSalvar = QIcon::fromTheme("document-save",
                                        QIcon(":/imagens/salvar.png"));

    auto acaoSalvar = new QAction(iconeSalvar,
                                  QString("Salvar"),
                                  editorDeTextoView);

    acaoSalvar->setShortcuts(QKeySequence::Save);
    acaoSalvar->setStatusTip(QString("Salvar documento"));

    menuArquivo->addAction(acaoSalvar);
    menuToolBar->addAction(acaoSalvar);

    return acaoSalvar;
}

QAction* controladores::EditorDeTextoController::crieMenuSalvarComo(QMenu* menuArquivo)
{
//    auto iconeSalvarComo = QIcon::fromTheme("document-save-as");

//    auto acaoSalvarComo = menuArquivo->addAction(iconeSalvarComo,
//                                                 QString("Salvar Como..."),
//                                                 editorDeTextoView,
//                                                 &controladores::EditorDeTextoController::salveComo);

//    acaoSalvarComo->setShortcuts(QKeySequence::SaveAs);
//    acaoSalvarComo->setStatusTip(QString("Salvar documento em novo arquivo"));

//    menuArquivo->addSeparator();

//    return acaoSalvarComo;
}

QAction* controladores::EditorDeTextoController::crieMenuFechar(QMenu* menuArquivo)
{
    auto iconeFechar = QIcon::fromTheme("application-exit");

    auto acaoFechar = menuArquivo->addAction(iconeFechar,
                                          QString("Fechar"),
                                          editorDeTextoView,
                                          &QWidget::close);

    acaoFechar->setShortcuts(QKeySequence::Quit);
    acaoFechar->setStatusTip(QString("Fechar aplicacao"));

    return acaoFechar;
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
