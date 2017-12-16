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
    controlador->sobre();
}

void EditorDeTextoView::arquivoFoiModificado()
{
    setWindowModified(campoTexto->document()->isModified());
}

void EditorDeTextoView::compile()
{
    controlador->compile();
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

    controlador->adicioneSeparador(menuArquivo);
}

void EditorDeTextoView::crieMenuComAcoesDeEditar()
{
    QMenu *menuEditar = menuBar()->addMenu(tr("Editar"));
    QToolBar *menuEditarToolBar = addToolBar(tr("Editar"));

    auto acaoRecortar = controlador->crieMenuRecortar(menuEditar, menuEditarToolBar);
    connect(acaoRecortar, &QAction::triggered, campoTexto, &QPlainTextEdit::cut);

    auto acaoColar = controlador->crieMenuColar(menuEditar, menuEditarToolBar);
    connect(acaoColar, &QAction::triggered, campoTexto, &QPlainTextEdit::paste);

    auto acaoCopiar = controlador->crieMenuCopiar(menuEditar, menuEditarToolBar);
    connect(acaoCopiar, &QAction::triggered, campoTexto, &QPlainTextEdit::copy);

    acaoRecortar->setEnabled(false);
    acaoCopiar->setEnabled(false);
    connect(campoTexto, &QPlainTextEdit::copyAvailable, acaoRecortar, &QAction::setEnabled);
    connect(campoTexto, &QPlainTextEdit::copyAvailable, acaoCopiar, &QAction::setEnabled);

    controlador->adicioneSeparador(menuEditar);
}

void EditorDeTextoView::crieMenuComAcoesDeCompilar()
{
    QMenu *menuCompilar = menuBar()->addMenu(tr("Ferramentas"));
    QToolBar *menuCompilarToolBar = addToolBar(tr("Compilar"));

    auto acaoCompilar = controlador->crieMenuCompilar(menuCompilar, menuCompilarToolBar);

    connect(acaoCompilar, &QAction::triggered, this, &EditorDeTextoView::compile);

    controlador->adicioneSeparador(menuCompilar);
}

void EditorDeTextoView::crieMenuComAcoes()
{
    criMenuComAcoesDeArquivo();

    crieMenuComAcoesDeEditar();

    crieMenuComAcoesDeCompilar();

    QMenu *menuSobre = menuBar()->addMenu(tr("Ajuda"));

    controlador->crieMenuSobre(menuSobre);
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

QString EditorDeTextoView::nomeSimplificado(const QString &nomeCompletoDoArquivo)
{
    auto nomeSimplificado = controlador->nomeSimplificado(nomeCompletoDoArquivo);

    return nomeSimplificado;
}
