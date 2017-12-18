#include "compiladorportugol.h"

negocio::CompiladorPortugol::CompiladorPortugol()
{
    tabelaDeSimbolos = new TabelaDeSimbolosPortugol();
    analisadorLexico = new AnalisadorLexicoPortugol(tabelaDeSimbolos);
    analisadorSintatico = new AnalisadorSintaticoPortugol();
    tradutor = new TradutorPortugolParaC();
}

void negocio::CompiladorPortugol::compile(QString texto)
{
    auto linhas = separeLinhas(texto);

    for (auto linha : linhas)
    {
        auto tokens = analisadorLexico->crieTokens(linha);

        analisadorSintatico->valideSequenciaDeTokens(tokens);

        tradutor->adicioneTokens(tokens);
        tradutor->adicioneTokenFinalDeLinha();
    }

    tradutor->imprima();
}

QStringList negocio::CompiladorPortugol::separeLinhas(QString texto)
{
    QRegExp expressaoRegular("(\\;)");

    return texto.split(expressaoRegular);
}
