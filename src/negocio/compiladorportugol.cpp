#include "compiladorportugol.h"

negocio::CompiladorPortugol::CompiladorPortugol()
{
    tabelaDeSimbolos = new TabelaDeSimbolosPortugol();
    analisadorLexico = new AnalisadorLexicoPortugol(tabelaDeSimbolos);
    analisadorSemantico = new AnalisadorSemanticoPortugol();
}

void negocio::CompiladorPortugol::compile(QString texto)
{
    auto linhas = separeLinhas(texto);

    for (auto linha : linhas)
    {
        auto tokens = analisadorLexico->crieTokens(linha);

        analisadorSemantico->valideSequenciaDeTokens(tokens);
    }
}

QStringList negocio::CompiladorPortugol::separeLinhas(QString texto)
{
    QRegExp expressaoRegular("*;");

    return texto.split(expressaoRegular);
}
