#include "compiladorportugol.h"

negocio::CompiladorPortugol::CompiladorPortugol()
{
    tabelaDeSimbolos = new TabelaDeSimbolos();
    analisadorLexico = new AnalisadorLexico(tabelaDeSimbolos);
    analisadorSemantico = new AnalisadorSemantico();
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
