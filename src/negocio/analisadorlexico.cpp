#include "analisadorlexico.h"

negocio::AnalisadorLexico::AnalisadorLexico(TabelaDeSimbolos *tabelaDeSimbolos)
    : tabelaDeSimbolos(tabelaDeSimbolos)
{
}

vector<negocio::Token*> negocio::AnalisadorLexico::crieTokens(QString linha)
{
    vector<Token*> tokens;
    QRegExp expressaoRegular("(\\ |\\n|\\t)");

    auto palavras = linha.split(expressaoRegular);

    for (auto palavra : palavras)
    {
        auto tipo = tabelaDeSimbolos->getTipo(palavra);

        tokens.push_back(new Token(palavra, tipo));
    }

    return tokens;
}

