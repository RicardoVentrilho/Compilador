#include "tabeladesimbolos.h"

negocio::TabelaDeSimbolos::TabelaDeSimbolos()
{
    dicionario =
    {
        { QString("programa"), EnumToken::PALAVRA_RESERVADA },
        { QString("var"), EnumToken::VARIAVEL },
        { QString("="), EnumToken::OPERADOR_ATRIBUICAO },
        { QString(","), EnumToken::OPERADOR_SEPARADOR }
    };
}

enumeradores::EnumToken negocio::TabelaDeSimbolos::getTipo(QString palavra)
{
    ////TODO: Validar se existe palavra no dicionario
    return dicionario.at(palavra);
}
