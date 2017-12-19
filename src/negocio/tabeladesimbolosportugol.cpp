#include "tabeladesimbolosportugol.h"

negocio::TabelaDeSimbolosPortugol::TabelaDeSimbolosPortugol()
{
    tabela =
    {
        TokenPortugol(QString("programa"), EnumToken::PALAVRA_RESERVADA, "#include<stdio.h>_int main()_{_cleanCode_return 0;_}"),
        TokenPortugol(QString("var"), EnumToken::VARIAVEL,"int"),
        TokenPortugol(QString("="), EnumToken::OPERADOR_ATRIBUICAO,"="),
        TokenPortugol(QString(","), EnumToken::OPERADOR_SEPARADOR,","),
        TokenPortugol(QString("[0-9]{0,30}"), EnumToken::NUMERO,""),
        TokenPortugol(QString("^[a-zA-Z]([a-zA-Z]|[0-9])*"), EnumToken::NOME_VARIAVEL,""),
        TokenPortugol(QString("se"), EnumToken::OPERADOR_SE_LOGICO,"if"),
        TokenPortugol(QString("senao"), EnumToken::OPERADOR_SENAO_LOGICO,"else"),
        TokenPortugol(QString(">"), EnumToken::OPERADOR_RELACIONAL_MAIOR,">"),
        TokenPortugol(QString("<"), EnumToken::OPERADOR_RELACIONAL_MENOR,"<"),
        TokenPortugol(QString(">="), EnumToken::OPERADOR_RELACIONAL_MAIOR_IGUAL,">="),
        TokenPortugol(QString("<="), EnumToken::OPERADOR_RELACIONAL_MENOR_IGUAL,"<="),
        TokenPortugol(QString("!="), EnumToken::OPERADOR_RELACIONAL_DIFERENTE,"!="),
        TokenPortugol(QString("leia"), EnumToken::LEIA,"scanf(\"%d,\""),
        TokenPortugol(QString("escreva"), EnumToken::ESCREVA,"printf("),
        TokenPortugol(QString("("), EnumToken::ABRE,"("),
        TokenPortugol(QString(")"), EnumToken::FECHA,")"),
        TokenPortugol(QString("+"), EnumToken::OPERADOR_ARITMETICO_SOMA,""),
        TokenPortugol(QString("-"), EnumToken::OPERADOR_ARITMETICO_SUBTRACAO,""),
        TokenPortugol(QString("*"), EnumToken::OPERADOR_ARITMETICO_MULTIPLICACAO,""),
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
