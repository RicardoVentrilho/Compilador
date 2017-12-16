#include <QtWidgets>

#include "editordetextoview.h"

EditorDeTextoView::EditorDeTextoView()
    : campoTexto(new QPlainTextEdit),
      resultadoDaCompilacao(new QPlainTextEdit())
{
    monteLayout();

    controlador = new EditorDeTextoController(this, campoTexto, arquivoAtual);

    crieMenuComAcoes();

    crieBarraDeStatus();

    leiaConfiguracoes();

    connect(campoTexto->document(),
            &QTextDocument::contentsChanged,
            this,
            &EditorDeTextoView::arquivoFoiModificado);

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

void EditorDeTextoView::aoFechar(QCloseEvent *event)
{
    controlador->aoFechar(event);
}

void EditorDeTextoView::crieArquivo()
{
    controlador->crieArquivo();
}

void EditorDeTextoView::abra()
{
    controlador->abra();
}

bool EditorDeTextoView::salve()
{
    auto arquivoSalvo = controlador->salve();

    return arquivoSalvo;
}

bool EditorDeTextoView::salveComo()
{
    auto arquivoSalvo = controlador->salveComo();

    return arquivoSalvo;
}

void EditorDeTextoView::sobre()
{
   QMessageBox::about(this, tr("Sobre este compilador!"),
                            tr("<b>Compilador</b> que traduz Portugol para C."));
}

void EditorDeTextoView::arquivoFoiModificado()
{
    setWindowModified(campoTexto->document()->isModified());
}

void EditorDeTextoView::criMenuComAcoesDeArquivo()
{
    QMenu *menuArquivo = menuBar()->addMenu(tr("&Arquivo"));
    QToolBar *menuArquivoToolBar = addToolBar(tr("Arquivo"));

    auto acaoNovo = controlador->crieMenuNovo(menuArquivo, menuArquivoToolBar);
    connect(acaoNovo, &QAction::triggered, this, &EditorDeTextoView::crieArquivo);

    auto acaoAbrir = controlador->crieMenuAbrir(menuArquivo, menuArquivoToolBar);
    connect(acaoAbrir, &QAction::triggered, this, &EditorDeTextoView::abra);

//    auto acaoFechar = controlador->crieMenuFechar(menuArquivo);
//    connect(acaoFechar, &QAction::triggered, this, &EditorDeTextoView::aoFechar);

    auto acaoSalvar = controlador->crieMenuSalvar(menuArquivo, menuArquivoToolBar);
    connect(acaoSalvar, &QAction::triggered, this, &EditorDeTextoView::salve);

//    auto acaoSalvarComo = controlador->crieMenuSalvarComo(menuArquivo);
//    connect(acaoSalvarComo, &QAction::triggered, this, &EditorDeTextoView::salve);
}

void EditorDeTextoView::crieMenuComAcoes()
{
    criMenuComAcoesDeArquivo();


    QMenu *menuEditar = menuBar()->addMenu(tr("Editar"));
    QToolBar *menuEditarToolBar = addToolBar(tr("Editar"));

#ifndef QT_NO_CLIPBOARD

    const QIcon cutIcon = QIcon::fromTheme("edit-cut", QIcon(":/imagens/recortar.png"));
    QAction *cutAct = new QAction(cutIcon, tr("Recortar"), this);

    ////TODO: Refatorar essa parte abaixo
    cutAct->setShortcuts(QKeySequence::Cut);
    cutAct->setStatusTip(tr("Cut the current selection's contents to the "
                            "clipboard"));
    connect(cutAct, &QAction::triggered, campoTexto, &QPlainTextEdit::cut);
    menuEditar->addAction(cutAct);
    menuEditarToolBar->addAction(cutAct);

    const QIcon copyIcon = QIcon::fromTheme("edit-copy", QIcon(":/imagens/copiar.png"));
    QAction *copyAct = new QAction(copyIcon, tr("Copiar"), this);
    copyAct->setShortcuts(QKeySequence::Copy);
    ////TODO: Refatorar essa parte abaixo
    copyAct->setStatusTip(tr("Copy the current selection's contents to the "
                             "clipboard"));
    connect(copyAct, &QAction::triggered, campoTexto, &QPlainTextEdit::copy);
    menuEditar->addAction(copyAct);
    menuEditarToolBar->addAction(copyAct);

    const QIcon pasteIcon = QIcon::fromTheme("edit-paste", QIcon(":/imagens/colar.png"));
    QAction *pasteAct = new QAction(pasteIcon, tr("Colar"), this);
    pasteAct->setShortcuts(QKeySequence::Paste);
    ////TODO: Refatorar essa parte abaixo
    pasteAct->setStatusTip(tr("Paste the clipboard's contents into the current "
                              "selection"));
    connect(pasteAct, &QAction::triggered, campoTexto, &QPlainTextEdit::paste);
    menuEditar->addAction(pasteAct);
    menuEditarToolBar->addAction(pasteAct);

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

    cutAct->setEnabled(false);
    copyAct->setEnabled(false);
    connect(campoTexto, &QPlainTextEdit::copyAvailable, cutAct, &QAction::setEnabled);
    connect(campoTexto, &QPlainTextEdit::copyAvailable, copyAct, &QAction::setEnabled);
}

void EditorDeTextoView::crieBarraDeStatus()
{
    QStatusBar* barraDeStatus = statusBar();

    controlador->setBarraDeStatus(barraDeStatus);
    controlador->mostreMensagemNaBarraDeStatus(tr("Aberto..."));
}

void EditorDeTextoView::leiaConfiguracoes()
{
    controlador->leiaConfiguracoes();
}

void EditorDeTextoView::definaConfiguracoes()
{
    controlador->definaConfiguracoes();
}

bool EditorDeTextoView::talvezSalve()
{
    auto arquivoSalvo = controlador->talvezSalve();

    return arquivoSalvo;
}

void EditorDeTextoView::carregueArquivo(const QString &nomeDoArquivo)
{
    controlador->carregueArquivo(nomeDoArquivo);
}

bool EditorDeTextoView::salveArquivo(const QString &nomeDoArquivo)
{
    auto arquivoSalvo = controlador->salveArquivo(nomeDoArquivo);

    return arquivoSalvo;
}

void EditorDeTextoView::setArquivoAtual(const QString &nomeDoArquivo)
{
    controlador->setArquivoAtual(nomeDoArquivo);
}

QString EditorDeTextoView::strippedName(const QString &nomeCompletoDoArquivo)
{
    return QFileInfo(nomeCompletoDoArquivo).fileName();
}
