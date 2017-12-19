#include "analisadorlexicoportugol.h"

negocio::AnalisadorLexicoPortugol::AnalisadorLexicoPortugol(TabelaDeSimbolosPortugol *tabelaDeSimbolos)
    : tabelaDeSimbolos(tabelaDeSimbolos)
{
}

vector<negocio::TokenPortugol*> negocio::AnalisadorLexicoPortugol::crieTokens(QString sequenciaDeTokens)
{
    vector<TokenPortugol*> tokens;
    QRegExp expressaoRegular("(\\ |\\n|\\t|\\;)");

    auto palavras = sequenciaDeTokens.split(expressaoRegular);

    palavras = removaDelimitadores(palavras);

    for (auto palavra : palavras)
    {
        auto token = tabelaDeSimbolos->getToken(palavra);
        tokens.push_back(new TokenPortugol(palavra, token.getTipo(),token.getTraducao()));
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

