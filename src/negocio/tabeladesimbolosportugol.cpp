#include "tabeladesimbolosportugol.h"

negocio::TabelaDeSimbolosPortugol::TabelaDeSimbolosPortugol()
{
    dicionario =
    {
        { QString("programa"), EnumToken::PALAVRA_RESERVADA },
        { QString("var"), EnumToken::VARIAVEL },
        { QString("="), EnumToken::OPERADOR_ATRIBUICAO },
        { QString(","), EnumToken::OPERADOR_SEPARADOR },
        { QString("[0-9]{0,30}"), EnumToken::NUMERO }
    };
}

enumeradores::EnumToken negocio::TabelaDeSimbolosPortugol::getTipo(QString palavra)
{
    if (dicionario.find(palavra) == dicionario.end())
    {
        ////TODO: Fazer um facade ou comparable para procurar (dicionario.find())
        ////Solução do if(s) temporária
        if (ehId(palavra))
        {
            return EnumToken::ID;
        }

        if(ehNumero(palavra))
        {
            return EnumToken::NUMERO;
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

bool negocio::TabelaDeSimbolosPortugol::ehNumero(QString palavra)
{
    QRegExp expressaoRegular("[0-9]{0,30}");

    return expressaoRegular.exactMatch(palavra);
}
