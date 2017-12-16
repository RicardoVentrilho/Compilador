#include <QtWidgets>

#include "editordetextoview.h"

EditorDeTextoView::EditorDeTextoView()
    : campoTexto(new QPlainTextEdit),
      resultadoDaCompilacao(new QPlainTextEdit())
{
    monteLayout();

    controlador = new EditorDeTextoController(this, campoTexto, arquivoAtual);

    crieAcoes();
    crieBarraDeStatus();

    leiaConfiguracoes();

    connect(campoTexto->document(),
            &QTextDocument::contentsChanged,
            this,
            &EditorDeTextoView::documento_foi_modificado);

    setArquivoAtual(QString());
    setUnifiedTitleAndToolBarOnMac(true);
}

void EditorDeTextoView::monteLayout()
{
    auto layout = new QVBoxLayout();
    layout->addWidget(campoTexto);

    resultadoDaCompilacao->setMinimumHeight(ALTURA_RESULTADO_DA_COMPILACAO);
    resultadoDaCompilacao->setMaximumHeight(ALTURA_RESULTADO_DA_COMPILACAO);

    resultadoDaCompilacao->setReadOnly(true);
    resultadoDaCompilacao->insertPlainText("COMPILADOR EM DESENVOLVIMENTO...");

    layout->addWidget(resultadoDaCompilacao);

    setCentralWidget(new QWidget);
    centralWidget()->setLayout(layout);
}

void EditorDeTextoView::ao_fechar(QCloseEvent *event)
{
    if (talvezSalve()) {
        escrevaConfiguracoes();
        event->accept();
    } else {
        event->ignore();
    }
}

void EditorDeTextoView::crie_arquivo()
{
    if (talvezSalve()) {
        campoTexto->clear();
        setArquivoAtual(QString());
    }
}

void EditorDeTextoView::abra()
{
    if (talvezSalve()) {
        QString fileName = QFileDialog::getOpenFileName(this);
        if (!fileName.isEmpty())
            carregueArquivo(fileName);
    }
}

bool EditorDeTextoView::salve()
{
    if (arquivoAtual.isEmpty()) {
        return salve_como();
    } else {
        return salveArquivo(arquivoAtual);
    }
}

bool EditorDeTextoView::salve_como()
{
    QFileDialog dialog(this);
    dialog.setWindowModality(Qt::WindowModal);
    dialog.setAcceptMode(QFileDialog::AcceptSave);
    if (dialog.exec() != QDialog::Accepted)
        return false;
    return salveArquivo(dialog.selectedFiles().first());
}

void EditorDeTextoView::sobre()
{
   QMessageBox::about(this, tr("Sobre este compilador!"),
            tr("<b>Compilador</b> que traduz Portugol para C."));
}

void EditorDeTextoView::documento_foi_modificado()
{
    setWindowModified(campoTexto->document()->isModified());
}

void EditorDeTextoView::crie_botao_novo(QMenu *menu_arquivo, QToolBar *toolbar_menu)
{
//    auto icone_novo = FabricaDeComponentes::crie_icone("novo-documento", ":/imagens/novo.png");
//    auto action_novo = FabricaDeComponentes::crie_action(icone_novo, "Novo", this);
//    connect(action_novo, &QAction::triggered, this, &TelaPrincipal::crie_arquivo);
//    adicione_acao_no_menu(menu_arquivo, action_novo);
//    adicione_acao_na_toolbar(toolbar_menu, action_novo);
}

void EditorDeTextoView::crieAcoes()
{
    //Novo Arquivo
    QMenu *menu_arquivo = menuBar()->addMenu(tr("&Arquivo"));
    QToolBar *toolbar_menu = addToolBar(tr("Arquivo"));

    const QIcon newIcon = QIcon::fromTheme("novo-documento", QIcon(":/imagens/novo.png"));
    QAction *newAct = new QAction(newIcon, tr("Novo"), this);
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(tr("Criar novo arquivo"));
    connect(newAct, &QAction::triggered, this, &EditorDeTextoView::crie_arquivo);
    menu_arquivo->addAction(newAct);
    toolbar_menu->addAction(newAct);

    crie_botao_novo(menu_arquivo, toolbar_menu);

    //Abrir
    const QIcon openIcon = QIcon::fromTheme("document-open", QIcon(":/imagens/abrir.png"));
    QAction *openAct = new QAction(openIcon, tr("Abrir..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Abrir arquivo existente"));
    connect(openAct, &QAction::triggered, this, &EditorDeTextoView::abra);
    menu_arquivo->addAction(openAct);
    toolbar_menu->addAction(openAct);

    //Salvar
    const QIcon saveIcon = QIcon::fromTheme("document-save", QIcon(":/imagens/salvar.png"));
    QAction *saveAct = new QAction(saveIcon, tr("Salvar"), this);
    saveAct->setShortcuts(QKeySequence::Save);
    saveAct->setStatusTip(tr("Salvar documento"));
    connect(saveAct, &QAction::triggered, this, &EditorDeTextoView::salve);
    menu_arquivo->addAction(saveAct);
    toolbar_menu->addAction(saveAct);

    //Salvar Como
    const QIcon saveAsIcon = QIcon::fromTheme("document-save-as");
    QAction *saveAsAct = menu_arquivo->addAction(saveAsIcon, tr("Salvar Como..."), this, &EditorDeTextoView::salve_como);
    saveAsAct->setShortcuts(QKeySequence::SaveAs);
    saveAsAct->setStatusTip(tr("Salvar documento em novo arquivo"));

    menu_arquivo->addSeparator();

    //Fechar
    const QIcon exitIcon = QIcon::fromTheme("application-exit");
    QAction *exitAct = menu_arquivo->addAction(exitIcon, tr("Fechar"), this, &QWidget::close);
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
    connect(cutAct, &QAction::triggered, campoTexto, &QPlainTextEdit::cut);
    editMenu->addAction(cutAct);
    editToolBar->addAction(cutAct);

    const QIcon copyIcon = QIcon::fromTheme("edit-copy", QIcon(":/imagens/copiar.png"));
    QAction *copyAct = new QAction(copyIcon, tr("Copiar"), this);
    copyAct->setShortcuts(QKeySequence::Copy);
    ////TODO: Refatorar essa parte abaixo
    copyAct->setStatusTip(tr("Copy the current selection's contents to the "
                             "clipboard"));
    connect(copyAct, &QAction::triggered, campoTexto, &QPlainTextEdit::copy);
    editMenu->addAction(copyAct);
    editToolBar->addAction(copyAct);

    const QIcon pasteIcon = QIcon::fromTheme("edit-paste", QIcon(":/imagens/colar.png"));
    QAction *pasteAct = new QAction(pasteIcon, tr("Colar"), this);
    pasteAct->setShortcuts(QKeySequence::Paste);
    ////TODO: Refatorar essa parte abaixo
    pasteAct->setStatusTip(tr("Paste the clipboard's contents into the current "
                              "selection"));
    connect(pasteAct, &QAction::triggered, campoTexto, &QPlainTextEdit::paste);
    editMenu->addAction(pasteAct);
    editToolBar->addAction(pasteAct);

    menuBar()->addSeparator();

    //Compilador
    QMenu *compilador_menu = menuBar()->addMenu(tr("Ferramentas"));
    QToolBar *tool_bar_compilador = addToolBar(tr("Compilar"));

    const QIcon icone_compilar = QIcon::fromTheme("document-save", QIcon(":/imagens/build.png"));
    QAction *acao_compilar = new QAction(icone_compilar, tr("Compilar"), this);
    //saveAct->setShortcuts(QKeySequence::Save);
    //saveAct->setStatusTip(tr("Salvar documento"));
    //connect(saveAct, &QAction::triggered, this, &TelaPrincipal::salve);
    compilador_menu->addAction(acao_compilar);
    tool_bar_compilador->addAction(acao_compilar);

#endif // !QT_NO_CLIPBOARD

    QMenu *helpMenu = menuBar()->addMenu(tr("Ajuda"));
    QAction *aboutAct = helpMenu->addAction(tr("Sobre"), this, &EditorDeTextoView::sobre);
    ////TODO: Refatorar essa parte abaixo
    aboutAct->setStatusTip(tr("Show the application's About box"));

#ifndef QT_NO_CLIPBOARD

    cutAct->setEnabled(false);
    copyAct->setEnabled(false);
    connect(campoTexto, &QPlainTextEdit::copyAvailable, cutAct, &QAction::setEnabled);
    connect(campoTexto, &QPlainTextEdit::copyAvailable, copyAct, &QAction::setEnabled);
#endif // !QT_NO_CLIPBOARD
}

void EditorDeTextoView::crieBarraDeStatus()
{
    QStatusBar* barraDeStatus = statusBar();

    controlador->setBarraDeStatus(barraDeStatus);
    controlador->mostreMensagemNaBarraDeStatus(tr("Aberto!"));
}

void EditorDeTextoView::leiaConfiguracoes()
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

void EditorDeTextoView::escrevaConfiguracoes()
{
    QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());
    settings.setValue("geometria", saveGeometry());
}

bool EditorDeTextoView::talvezSalve()
{
    ////TODO: Refatorar essa parte abaixo
    if (!campoTexto->document()->isModified())
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

void EditorDeTextoView::carregueArquivo(const QString &nomeDoArquivo)
{
    controlador->carregueArquivo(nomeDoArquivo);

}

bool EditorDeTextoView::salveArquivo(const QString &nome_do_arquivo)
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
    out << campoTexto->toPlainText();
#ifndef QT_NO_CURSOR
    QApplication::restoreOverrideCursor();
#endif

    setArquivoAtual(nome_do_arquivo);
    statusBar()->showMessage(tr("File saved"), 2000);
    return true;
}

void EditorDeTextoView::setArquivoAtual(const QString &nomeDoArquivo)
{
    controlador->setArquivoAtual(nomeDoArquivo);
}

QString EditorDeTextoView::strippedName(const QString &nome_completo_do_arquivo)
{
    return QFileInfo(nome_completo_do_arquivo).fileName();
}
