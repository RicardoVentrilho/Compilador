#include "tabeladesimbolosportugol.h"

negocio::TabelaDeSimbolosPortugol::TabelaDeSimbolosPortugol()
{
    tabela =
    {
        TokenPortugol(QString("programa"), EnumToken::PALAVRA_RESERVADA),
        TokenPortugol(QString("var"), EnumToken::VARIAVEL),
        TokenPortugol(QString("="), EnumToken::OPERADOR_ATRIBUICAO),
        TokenPortugol(QString(","), EnumToken::OPERADOR_SEPARADOR),
        TokenPortugol(QString("[0-9]{0,30}"), EnumToken::NUMERO),
        TokenPortugol(QString("^([a-Z])([a-Z][0-9]$)*"), EnumToken::ID)
    };
}

enumeradores::EnumToken negocio::TabelaDeSimbolosPortugol::getTipo(QString palavra)
{
    for (auto regra : tabela)
    {
        QRegExp expressaoRegular(regra.getValor());

        auto ehValido = expressaoRegular.exactMatch(palavra);

        if (ehValido)
        {
            return regra.getTipo();
        }
    }

    throw new Excecao(QString("%1 incorreto.").arg(palavra).toStdString());
}
