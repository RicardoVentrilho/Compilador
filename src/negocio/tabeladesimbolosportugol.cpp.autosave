#include "tabeladesimbolosportugol.h"

negocio::TabelaDeSimbolosPortugol::TabelaDeSimbolosPortugol()
{
    tabela =
    {
        TokenPortugol(QString("programa"), EnumToken::PALAVRA_RESERVADA, "#include<stdio.h>_int main()_{_cleanCode_return 0;_}"),
        TokenPortugol(QString("var"), EnumToken::VARIAVEL,"int"),
        TokenPortugol(QString("="), EnumToken::OPERADOR_ATRIBUICAO,"="),
        TokenPortugol(QString(","), EnumToken::OPERADOR_SEPARADOR,","),
        TokenPortugol(QString("[0-9]{0,30}"), EnumToken::NUMERO,"numero"),
        TokenPortugol(QString("^(_|[a-Z])([a-Z]|[0-9])*$"), EnumToken::NOME_VARIAVEL,"nome"),
        TokenPortugol(QString("se"), EnumToken::OPERADOR_SE_LOGICO,"if"),
        TokenPortugol(QString("senao"), EnumToken::OPERADOR_SENAO_LOGICO,"else"),
        TokenPortugol(QString("(>|<|>=|<=|!=)"), EnumToken::OPERADOR_RELACIONAL,"relacional"),
        TokenPortugol(QString("leia"), EnumToken::OPERADOR_ARITMETICO,""),
        TokenPortugol(QString("escreva"), EnumToken::ESCREVA,"printf"),
        TokenPortugol(QString("("), EnumToken::ABRE,"("),
        TokenPortugol(QString(")"), EnumToken::FECHA,")"),
        TokenPortugol(QString("(+|-|*)"), EnumToken::OPERADOR_ARITMETICO,"operador")
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
