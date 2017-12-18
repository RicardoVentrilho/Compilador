#include "analisadorlexicoportugol.h"

negocio::AnalisadorLexicoPortugol::AnalisadorLexicoPortugol(TabelaDeSimbolosPortugol *tabelaDeSimbolos)
    : tabelaDeSimbolos(tabelaDeSimbolos)
{
}

vector<negocio::TokenPortugol*> negocio::AnalisadorLexicoPortugol::crieTokens(QString linha)
{
    vector<TokenPortugol*> tokens;
    QRegExp expressaoRegular("(\\ |\\n|\\t)");

    auto palavras = linha.split(expressaoRegular);

    for (auto palavra : palavras)
    {
        auto tipo = tabelaDeSimbolos->getTipo(palavra);

        tokens.push_back(new TokenPortugol(palavra, tipo));
    }

    return tokens;
}

