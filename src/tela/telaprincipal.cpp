#include <QtWidgets>

#include "telaprincipal.h"

TelaPrincipal::TelaPrincipal()
    : editor_de_texto(new QPlainTextEdit)
{
    setCentralWidget(editor_de_texto);

    crie_acoes();
    crie_barra_de_status();

    leia_configuracoes();

    connect(editor_de_texto->document(), &QTextDocument::contentsChanged,
            this, &TelaPrincipal::documento_foi_modificado);

    set_arquivo_aberto(QString());
    setUnifiedTitleAndToolBarOnMac(true);
}

void TelaPrincipal::ao_fechar(QCloseEvent *event)
{
    if (talvez_salve()) {
        escreva_configuracoes();
        event->accept();
    } else {
        event->ignore();
    }
}

void TelaPrincipal::crie_arquivo()
{
    if (talvez_salve()) {
        editor_de_texto->clear();
        set_arquivo_aberto(QString());
    }
}

void TelaPrincipal::abra()
{
    if (talvez_salve()) {
        QString fileName = QFileDialog::getOpenFileName(this);
        if (!fileName.isEmpty())
            carregue_arquivo(fileName);
    }
}

bool TelaPrincipal::salve()
{
    if (arquivo_aberto.isEmpty()) {
        return salve_como();
    } else {
        return salve_arquivo(arquivo_aberto);
    }
}

bool TelaPrincipal::salve_como()
{
    QFileDialog dialog(this);
    dialog.setWindowModality(Qt::WindowModal);
    dialog.setAcceptMode(QFileDialog::AcceptSave);
    if (dialog.exec() != QDialog::Accepted)
        return false;
    return salve_arquivo(dialog.selectedFiles().first());
}

void TelaPrincipal::sobre()
{
   QMessageBox::about(this, tr("About Application"),
            tr("The <b>Application</b> example demonstrates how to "
               "write modern GUI applications using Qt, with a menu bar, "
               "toolbars, and a status bar."));
}

void TelaPrincipal::documento_foi_modificado()
{
    setWindowModified(editor_de_texto->document()->isModified());
}

void TelaPrincipal::crie_acoes()
{
    //Novo Arquivo
    QMenu *fileMenu = menuBar()->addMenu(tr("&Arquivo"));
    QToolBar *fileToolBar = addToolBar(tr("Arquivo"));
    const QIcon newIcon = QIcon::fromTheme("document-new", QIcon(":/imagens/novo.png"));
    QAction *newAct = new QAction(newIcon, tr("Novo"), this);
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(tr("Criar novo arquivo"));
    connect(newAct, &QAction::triggered, this, &TelaPrincipal::crie_arquivo);
    fileMenu->addAction(newAct);
    fileToolBar->addAction(newAct);

    //Abrir
    const QIcon openIcon = QIcon::fromTheme("document-open", QIcon(":/imagens/abrir.png"));
    QAction *openAct = new QAction(openIcon, tr("Abrir..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Abrir arquivo existente"));
    connect(openAct, &QAction::triggered, this, &TelaPrincipal::abra);
    fileMenu->addAction(openAct);
    fileToolBar->addAction(openAct);

    //Salvar
    const QIcon saveIcon = QIcon::fromTheme("document-save", QIcon(":/imagens/salvar.png"));
    QAction *saveAct = new QAction(saveIcon, tr("Salvar"), this);
    saveAct->setShortcuts(QKeySequence::Save);
    saveAct->setStatusTip(tr("Salvar documento"));
    connect(saveAct, &QAction::triggered, this, &TelaPrincipal::salve);
    fileMenu->addAction(saveAct);
    fileToolBar->addAction(saveAct);

    //Salvar Como
    const QIcon saveAsIcon = QIcon::fromTheme("document-save-as");
    QAction *saveAsAct = fileMenu->addAction(saveAsIcon, tr("Salvar Como..."), this, &TelaPrincipal::salve_como);
    saveAsAct->setShortcuts(QKeySequence::SaveAs);
    saveAsAct->setStatusTip(tr("Salvar documento em novo arquivo"));

    fileMenu->addSeparator();

    //Fechar
    const QIcon exitIcon = QIcon::fromTheme("application-exit");
    QAction *exitAct = fileMenu->addAction(exitIcon, tr("Fechar"), this, &QWidget::close);
    exitAct->setShortcuts(QKeySequence::Quit);
    exitAct->setStatusTip(tr("Fechar aplicacao"));

    //Editar
    QMenu *editMenu = menuBar()->addMenu(tr("Editar"));
    QToolBar *editToolBar = addToolBar(tr("Editar"));

#ifndef QT_NO_CLIPBOARD
    const QIcon cutIcon = QIcon::fromTheme("edit-cut", QIcon(":/imagens/recortar.png"));
    QAction *cutAct = new QAction(cutIcon, tr("Recortar"), this);

    ////TODO: Refatorar essa parte abaixo
    cutAct->setShortcuts(QKeySequence::Cut);
    cutAct->setStatusTip(tr("Cut the current selection's contents to the "
                            "clipboard"));
    connect(cutAct, &QAction::triggered, editor_de_texto, &QPlainTextEdit::cut);
    editMenu->addAction(cutAct);
    editToolBar->addAction(cutAct);

    const QIcon copyIcon = QIcon::fromTheme("edit-copy", QIcon(":/imagens/copiar.png"));
    QAction *copyAct = new QAction(copyIcon, tr("Copiar"), this);
    copyAct->setShortcuts(QKeySequence::Copy);
    ////TODO: Refatorar essa parte abaixo
    copyAct->setStatusTip(tr("Copy the current selection's contents to the "
                             "clipboard"));
    connect(copyAct, &QAction::triggered, editor_de_texto, &QPlainTextEdit::copy);
    editMenu->addAction(copyAct);
    editToolBar->addAction(copyAct);

    const QIcon pasteIcon = QIcon::fromTheme("edit-paste", QIcon(":/imagens/colar.png"));
    QAction *pasteAct = new QAction(pasteIcon, tr("Colar"), this);
    pasteAct->setShortcuts(QKeySequence::Paste);
    ////TODO: Refatorar essa parte abaixo
    pasteAct->setStatusTip(tr("Paste the clipboard's contents into the current "
                              "selection"));
    connect(pasteAct, &QAction::triggered, editor_de_texto, &QPlainTextEdit::paste);
    editMenu->addAction(pasteAct);
    editToolBar->addAction(pasteAct);

    menuBar()->addSeparator();

#endif // !QT_NO_CLIPBOARD

    QMenu *helpMenu = menuBar()->addMenu(tr("Ajuda"));
    QAction *aboutAct = helpMenu->addAction(tr("Sobre"), this, &TelaPrincipal::sobre);
    ////TODO: Refatorar essa parte abaixo
    aboutAct->setStatusTip(tr("Show the application's About box"));

#ifndef QT_NO_CLIPBOARD

    cutAct->setEnabled(false);
    copyAct->setEnabled(false);
    connect(editor_de_texto, &QPlainTextEdit::copyAvailable, cutAct, &QAction::setEnabled);
    connect(editor_de_texto, &QPlainTextEdit::copyAvailable, copyAct, &QAction::setEnabled);
#endif // !QT_NO_CLIPBOARD
}

void TelaPrincipal::crie_barra_de_status()
{
    statusBar()->showMessage(tr("Ready"));
}

void TelaPrincipal::leia_configuracoes()
{
    QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());
    const QByteArray geometry = settings.value("geometria", QByteArray()).toByteArray();
    if (geometry.isEmpty()) {
        const QRect availableGeometry = QApplication::desktop()->availableGeometry(this);
        resize(availableGeometry.width() / 3, availableGeometry.height() / 2);
        move((availableGeometry.width() - width()) / 2,
             (availableGeometry.height() - height()) / 2);
    } else {
        restoreGeometry(geometry);
    }
}

void TelaPrincipal::escreva_configuracoes()
{
    QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());
    settings.setValue("geometria", saveGeometry());
}

bool TelaPrincipal::talvez_salve()
{
    ////TODO: Refatorar essa parte abaixo
    if (!editor_de_texto->document()->isModified())
        return true;
    const QMessageBox::StandardButton ret
        = QMessageBox::warning(this, tr("Application"),
                               tr("The document has been modified.\n"
                                  "Do you want to save your changes?"),
                               QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    switch (ret) {
    case QMessageBox::Save:
        return salve();
    case QMessageBox::Cancel:
        return false;
    default:
        break;
    }
    return true;
}

void TelaPrincipal::carregue_arquivo(const QString &nome_do_arquivo)
{
    ////TODO: Refatorar essa parte abaixo
    QFile file(nome_do_arquivo);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Application"),
                             tr("Cannot read file %1:\n%2.")
                             .arg(QDir::toNativeSeparators(nome_do_arquivo), file.errorString()));
        return;
    }

    QTextStream in(&file);
#ifndef QT_NO_CURSOR
    QApplication::setOverrideCursor(Qt::WaitCursor);
#endif
    editor_de_texto->setPlainText(in.readAll());
#ifndef QT_NO_CURSOR
    QApplication::restoreOverrideCursor();
#endif

    set_arquivo_aberto(nome_do_arquivo);
    statusBar()->showMessage(tr("File loaded"), 2000);
}

bool TelaPrincipal::salve_arquivo(const QString &nome_do_arquivo)
{
    ////TODO: Refatorar essa parte abaixo
    QFile file(nome_do_arquivo);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Application"),
                             tr("Cannot write file %1:\n%2.")
                             .arg(QDir::toNativeSeparators(nome_do_arquivo),
                                  file.errorString()));
        return false;
    }

    QTextStream out(&file);
#ifndef QT_NO_CURSOR
    QApplication::setOverrideCursor(Qt::WaitCursor);
#endif
    out << editor_de_texto->toPlainText();
#ifndef QT_NO_CURSOR
    QApplication::restoreOverrideCursor();
#endif

    set_arquivo_aberto(nome_do_arquivo);
    statusBar()->showMessage(tr("File saved"), 2000);
    return true;
}

void TelaPrincipal::set_arquivo_aberto(const QString &nome_do_arquivo)
{
    arquivo_aberto = nome_do_arquivo;
    editor_de_texto->document()->setModified(false);
    setWindowModified(false);

    QString shownName = arquivo_aberto;
    if (arquivo_aberto.isEmpty())
        shownName = "sem-titulo.txt";
    setWindowFilePath(shownName);
}

QString TelaPrincipal::strippedName(const QString &nome_completo_do_arquivo)
{
    return QFileInfo(nome_completo_do_arquivo).fileName();
}
