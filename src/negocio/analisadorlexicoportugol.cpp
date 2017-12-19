#include "analisadorlexicoportugol.h"

negocio::AnalisadorLexicoPortugol::AnalisadorLexicoPortugol(TabelaDeSimbolosPortugol *tabelaDeSimbolos)
    : tabelaDeSimbolos(tabelaDeSimbolos)
{
}

vector<negocio::TokenPortugol*> negocio::AnalisadorLexicoPortugol::crieTokens(QString linha)
{
    vector<TokenPortugol*> tokens;
    QRegExp expressaoRegular("(\\ |\\n|\\t|\\;)");

    auto palavras = linha.split(expressaoRegular);

    palavras = removaDelimitadores(palavras);

    for (auto palavra : palavras)
    {
        auto tipo = tabelaDeSimbolos->getTipo(palavra);
        tokens.push_back(new TokenPortugol(palavra, tipo));
    }

    return tokens;
}

QStringList negocio::AnalisadorLexicoPortugol::removaDelimitadores(QStringList palavras)
{
    QStringList resultado;

    for (auto palavra : palavras)
    {
        if (palavra == QString(""))
        {
           continue;
        }

        resultado.push_back(palavra);
    }

    return resultado;
}

