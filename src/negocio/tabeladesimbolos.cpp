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
    if (dicionario.find(palavra) == dicionario.end())
    {
        ////TODO: Validar id;
        return EnumToken::ID;
    }

    return dicionario.at(palavra);
}
