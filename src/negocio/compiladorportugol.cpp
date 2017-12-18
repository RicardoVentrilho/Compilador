#include "compiladorportugol.h"

negocio::CompiladorPortugol::CompiladorPortugol()
{
    //estadoInicial = new Estado();
    analisadorLexico = new AnalisadorLexico();
}

void negocio::CompiladorPortugol::compile(QString texto)
{
    auto linhas = separeLinhas(texto);

    for (auto linha : linhas)
    {
        //auto tokens = separeTokens(linha);

        auto tokens = analisadorLexico->crieTokens(linha);

        //analisadorSemantico->valideSequenciaDeTokens(tokens);
    }
}

QStringList negocio::CompiladorPortugol::separeLinhas(QString texto)
{
    QRegExp expressaoRegular("*;");

    return texto.split(expressaoRegular);
}

QStringList negocio::CompiladorPortugol::separeTokens(QString texto)
{
    QRegExp expressaoRegular("(\\ |\\n|\\t)");

    return texto.split(expressaoRegular);
}
