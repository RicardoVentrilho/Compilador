#include <QtWidgets>

#include "editordetextoview.h"

tela::EditorDeTextoView::EditorDeTextoView()
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
            &tela::EditorDeTextoView::arquivoFoiModificado);

    setArquivoAtual(QString());

    setUnifiedTitleAndToolBarOnMac(true);
}

void tela::EditorDeTextoView::monteLayout()
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

void tela::EditorDeTextoView::aoFechar(QCloseEvent *event)
{
    controlador->aoFechar(event);
}

void tela::EditorDeTextoView::crieArquivo()
{
    controlador->crieArquivo();
}

void tela::EditorDeTextoView::abra()
{
    controlador->abra();
}

bool tela::EditorDeTextoView::salve()
{
    auto arquivoSalvo = controlador->salve();

    return arquivoSalvo;
}

bool tela::EditorDeTextoView::salveComo()
{
    auto arquivoSalvo = controlador->salveComo();

    return arquivoSalvo;
}

void tela::EditorDeTextoView::sobre()
{
    controlador->sobre();
}

void tela::EditorDeTextoView::arquivoFoiModificado()
{
    setWindowModified(campoTexto->document()->isModified());
}

void tela::EditorDeTextoView::compile()
{
    auto texto = campoTexto->toPlainText();

    controlador->compile(texto);
}

void tela::EditorDeTextoView::criMenuComAcoesDeArquivo()
{
    QMenu *menuArquivo = menuBar()->addMenu(tr("&Arquivo"));
    QToolBar *menuArquivoToolBar = addToolBar(tr("Arquivo"));

    auto acaoNovo = controlador->crieMenuNovo(menuArquivo, menuArquivoToolBar);
    connect(acaoNovo, &QAction::triggered, this, &tela::EditorDeTextoView::crieArquivo);

    auto acaoAbrir = controlador->crieMenuAbrir(menuArquivo, menuArquivoToolBar);
    connect(acaoAbrir, &QAction::triggered, this, &tela::EditorDeTextoView::abra);

//    auto acaoFechar = controlador->crieMenuFechar(menuArquivo);
//    connect(acaoFechar, &QAction::triggered, this, &tela::EditorDeTextoView::aoFechar);

    auto acaoSalvar = controlador->crieMenuSalvar(menuArquivo, menuArquivoToolBar);
    connect(acaoSalvar, &QAction::triggered, this, &tela::EditorDeTextoView::salve);

//    auto acaoSalvarComo = controlador->crieMenuSalvarComo(menuArquivo);
//    connect(acaoSalvarComo, &QAction::triggered, this, &tela::EditorDeTextoView::salve);

    controlador->adicioneSeparador(menuArquivo);
}

void tela::EditorDeTextoView::crieMenuComAcoesDeEditar()
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

void tela::EditorDeTextoView::crieMenuComAcoesDeCompilar()
{
    QMenu *menuCompilar = menuBar()->addMenu(tr("Ferramentas"));
    QToolBar *menuCompilarToolBar = addToolBar(tr("Compilar"));

    auto acaoCompilar = controlador->crieMenuCompilar(menuCompilar, menuCompilarToolBar);

    connect(acaoCompilar, &QAction::triggered, this, &tela::EditorDeTextoView::compile);

    controlador->adicioneSeparador(menuCompilar);
}

void tela::EditorDeTextoView::crieMenuComAcoes()
{
    criMenuComAcoesDeArquivo();

    crieMenuComAcoesDeEditar();

    crieMenuComAcoesDeCompilar();

    QMenu *menuSobre = menuBar()->addMenu(tr("Ajuda"));

    controlador->crieMenuSobre(menuSobre);
}

void tela::EditorDeTextoView::crieBarraDeStatus()
{
    QStatusBar* barraDeStatus = statusBar();

    controlador->setBarraDeStatus(barraDeStatus);

    controlador->mostreMensagemNaBarraDeStatus(tr("Aberto..."));
}

void tela::EditorDeTextoView::leiaConfiguracoes()
{
    controlador->leiaConfiguracoes();
}

void tela::EditorDeTextoView::definaConfiguracoes()
{
    controlador->definaConfiguracoes();
}

bool tela::EditorDeTextoView::talvezSalve()
{
    auto arquivoSalvo = controlador->talvezSalve();

    return arquivoSalvo;
}

void tela::EditorDeTextoView::carregueArquivo(const QString &nomeDoArquivo)
{
    controlador->carregueArquivo(nomeDoArquivo);
}

bool tela::EditorDeTextoView::salveArquivo(const QString &nomeDoArquivo)
{
    auto arquivoSalvo = controlador->salveArquivo(nomeDoArquivo);

    return arquivoSalvo;
}

void tela::EditorDeTextoView::setArquivoAtual(const QString &nomeDoArquivo)
{
    controlador->setArquivoAtual(nomeDoArquivo);
}

QString tela::EditorDeTextoView::nomeSimplificado(const QString &nomeCompletoDoArquivo)
{
    auto nomeSimplificado = controlador->nomeSimplificado(nomeCompletoDoArquivo);

    return nomeSimplificado;
}
