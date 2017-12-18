#include "tabeladesimbolosportugol.h"

negocio::TabelaDeSimbolosPortugol::TabelaDeSimbolosPortugol()
{
    dicionario =
    {
        { QString("programa"), EnumToken::PALAVRA_RESERVADA },
        { QString("var"), EnumToken::VARIAVEL },
        { QString("="), EnumToken::OPERADOR_ATRIBUICAO },
        { QString(","), EnumToken::OPERADOR_SEPARADOR }
    };
}

enumeradores::EnumToken negocio::TabelaDeSimbolosPortugol::getTipo(QString palavra)
{
    if (dicionario.find(palavra) == dicionario.end())
    {
        if (ehId(palavra))
        {
            return EnumToken::ID;
        }

        throw new Excecao(QString("%1 incorreto.").arg(palavra).toStdString());
    }

    return dicionario.at(palavra);
}

bool negocio::TabelaDeSimbolosPortugol::ehId(QString palavra)
{
    ////TODO: Arrumar variavel aqui kkk
    QRegExp expressaoRegular("^([a-Z])([a-Z][0-9]$)*");

    return expressaoRegular.exactMatch(palavra);
}
