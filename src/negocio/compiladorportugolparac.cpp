#include "compiladorportugolparac.h"

negocio::CompiladorPortugolParaC::CompiladorPortugolParaC()
{
    //estadoInicial = new Estado();
}

void negocio::CompiladorPortugolParaC::compile(QString texto)
{
    ////TODO: Adicionar para separar ";" na expressão abaixo
    QRegExp expressaoRegular("(\\ |\\n|\\t)");

    auto tokens = texto.split(expressaoRegular);

    estadoInicial->valide(tokens.first());

    ////TODO: Fazer como na linha abaixo, lançar exceção!
    //automato->valide(tokens);
}
