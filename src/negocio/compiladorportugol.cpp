#include "compiladorportugol.h"

negocio::CompiladorPortugol::CompiladorPortugol()
{
    tabelaDeSimbolos = new TabelaDeSimbolosPortugol();
    analisadorLexico = new AnalisadorLexicoPortugol(tabelaDeSimbolos);
    analisadorSintatico = new AnalisadorSintaticoPortugol(tabelaDeSimbolos);
    tradutor = new TradutorPortugolParaC();
}

void negocio::CompiladorPortugol::compile(QString texto)
{
    auto tokens = analisadorLexico->crieTokens(texto);

    analisadorSintatico->valide(tokens);

    //tradutor->adicioneTokens(tokens);
    //tradutor->adicioneTokenFinalDeLinha();
}

QStringList negocio::CompiladorPortugol::separeLinhas(QString texto)
{
    QRegExp expressaoRegular("(\\;|\\n)");

    return texto.split(expressaoRegular);
}
