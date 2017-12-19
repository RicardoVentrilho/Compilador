#include "tabeladesimbolosportugol.h"

negocio::TabelaDeSimbolosPortugol::TabelaDeSimbolosPortugol()
{
    tabela =
    {
        TokenPortugol(QString("programa"), EnumToken::PALAVRA_RESERVADA, ""),
        TokenPortugol(QString("var"), EnumToken::VARIAVEL,"int "),
        TokenPortugol(QString(";"), EnumToken::FINAL_DE_LINHA,";"),
        TokenPortugol(QString("="), EnumToken::OPERADOR_ATRIBUICAO," = "),
        TokenPortugol(QString(","), EnumToken::OPERADOR_SEPARADOR,", "),
        TokenPortugol(QString("escreva"), EnumToken::ESCREVA,"printf("),
        TokenPortugol(QString("leia"), EnumToken::LEIA,"scanf("),
        TokenPortugol(QString("se"), EnumToken::OPERADOR_LOGICO_SE,"if("),
        TokenPortugol(QString("at"), EnumToken::AT,"at"),
        TokenPortugol(QString("entao"), EnumToken::OPERADOR_LOGICO_ENTAO,")"),
        TokenPortugol(QString("senao"), EnumToken::OPERADOR_LOGICO_SENAO,"else"),
        TokenPortugol(QString(">"), EnumToken::OPERADOR_RELACIONAL_MAIOR,">"),
        TokenPortugol(QString("[0-9]{0,30}"), EnumToken::NUMERO,"numero"),
        TokenPortugol(QString("^[a-zA-Z]([a-zA-Z]|[0-9])*\\$"), EnumToken::NOME_VARIAVEL,"nome"),
        TokenPortugol(QString("^[a-zA-Z]([a-zA-Z]|[0-9])*"), EnumToken::MENSAGEM,"mensagem"),
        TokenPortugol(QString("<"), EnumToken::OPERADOR_RELACIONAL_MENOR,"<"),
        TokenPortugol(QString(">="), EnumToken::OPERADOR_RELACIONAL_MAIOR_IGUAL,">="),
        TokenPortugol(QString("<="), EnumToken::OPERADOR_RELACIONAL_MENOR_IGUAL,"<="),
        TokenPortugol(QString("!="), EnumToken::OPERADOR_RELACIONAL_DIFERENTE,"!="),
        TokenPortugol(QString("("), EnumToken::ABRE,"("),
        TokenPortugol(QString(")"), EnumToken::FECHA,")"),
        TokenPortugol(QString("+"), EnumToken::OPERADOR_ARITMETICO_SOMA," + "),
        TokenPortugol(QString("-"), EnumToken::OPERADOR_ARITMETICO_SUBTRACAO," - "),
        TokenPortugol(QString("*"), EnumToken::OPERADOR_ARITMETICO_MULTIPLICACAO," * ")
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

negocio::TokenPortugol negocio::TabelaDeSimbolosPortugol::getToken(QString palavra)
{
    for (auto regra : tabela)
    {
        QRegExp expressaoRegular(regra.getValor());

        auto ehValido = expressaoRegular.exactMatch(palavra);

        if (ehValido)
        {
            return regra;
        }
    }

    throw new Excecao(QString("%1 incorreto.").arg(palavra).toStdString());
}
