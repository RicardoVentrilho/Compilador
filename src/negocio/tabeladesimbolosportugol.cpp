#include "tabeladesimbolosportugol.h"

negocio::TabelaDeSimbolosPortugol::TabelaDeSimbolosPortugol()
{
    dicionario =
    {
        { QString("programa"), EnumToken::PALAVRA_RESERVADA },
        { QString("var"), EnumToken::VARIAVEL },
        { QString("="), EnumToken::OPERADOR_ATRIBUICAO },
        { QString(","), EnumToken::OPERADOR_SEPARADOR },
        { QString("[0-9]{0,30}"), EnumToken::NUMERO },
        { QString("^([a-Z])([a-Z][0-9]$)*"), EnumToken::ID }
    };
}

enumeradores::EnumToken negocio::TabelaDeSimbolosPortugol::getTipo(QString palavra)
{
    for (pair<QString, EnumToken> regra : dicionario)
    {
        QRegExp expressaoRegular(regra.first);

        auto ehValido = expressaoRegular.isValid();

        if (ehValido)
        {
            return regra.second;
        }
    }

    throw new Excecao(QString("%1 incorreto.").arg(palavra).toStdString());
}
