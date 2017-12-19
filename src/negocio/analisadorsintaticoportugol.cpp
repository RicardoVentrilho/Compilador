#include "analisadorsintaticoportugol.h"

negocio::AnalisadorSintaticoPortugol::AnalisadorSintaticoPortugol(TabelaDeSimbolosPortugol *tabelaDeSimbolos)
    : tabelaDeSimbolos(tabelaDeSimbolos)
{
    regras =
    {
        { EnumToken::PALAVRA_RESERVADA },
        { EnumToken::VARIAVEL,EnumToken::NOME_VARIAVEL, EnumToken::OPERADOR_ATRIBUICAO, EnumToken::NUMERO },
        { EnumToken::VARIAVEL,EnumToken::NOME_VARIAVEL, EnumToken::OPERADOR_SEPARADOR, EnumToken::NOME_VARIAVEL },
        { EnumToken::LEIA,EnumToken::NOME_VARIAVEL},
        { EnumToken::ESCREVA,EnumToken::ABRE,EnumToken::MENSAGEM,EnumToken::FECHA},
        { EnumToken::AT, EnumToken::NOME_VARIAVEL, EnumToken::OPERADOR_ATRIBUICAO, EnumToken::NOME_VARIAVEL},
        { EnumToken::AT, EnumToken::NOME_VARIAVEL, EnumToken::OPERADOR_ATRIBUICAO, EnumToken::NOME_VARIAVEL, EnumToken::OPERADOR_ARITMETICO_SOMA},
        { EnumToken::AT, EnumToken::NOME_VARIAVEL, EnumToken::OPERADOR_ATRIBUICAO, EnumToken::NOME_VARIAVEL},
        { EnumToken::OPERADOR_LOGICO_SE,EnumToken::VARIAVEL,EnumToken::OPERADOR_RELACIONAL_MAIOR,EnumToken::VARIAVEL,EnumToken::OPERADOR_LOGICO_ENTAO},
        { EnumToken::OPERADOR_LOGICO_SE,EnumToken::VARIAVEL,EnumToken::OPERADOR_RELACIONAL_MAIOR_IGUAL,EnumToken::VARIAVEL,EnumToken::OPERADOR_LOGICO_ENTAO},
        { EnumToken::OPERADOR_LOGICO_SE,EnumToken::VARIAVEL,EnumToken::OPERADOR_RELACIONAL_MENOR,EnumToken::VARIAVEL,EnumToken::OPERADOR_LOGICO_ENTAO},
        { EnumToken::OPERADOR_LOGICO_SE,EnumToken::VARIAVEL,EnumToken::OPERADOR_RELACIONAL_MENOR_IGUAL,EnumToken::VARIAVEL,EnumToken::OPERADOR_LOGICO_ENTAO},
        { EnumToken::OPERADOR_LOGICO_SE,EnumToken::VARIAVEL,EnumToken::OPERADOR_RELACIONAL_DIFERENTE,EnumToken::VARIAVEL,EnumToken::OPERADOR_LOGICO_ENTAO},
        { EnumToken::OPERADOR_LOGICO_SENAO},
    };

}

void negocio::AnalisadorSintaticoPortugol::valide(vector<negocio::TokenPortugol *> tokens)
{
    vector<EnumToken> sequenciaDeTokens;

    for (auto token : tokens)
    {
        sequenciaDeTokens.push_back(token->getTipo());
    }

    for (auto regra : regras)
    {
        if (valideRegraComSequenciaDeTokens(regra, sequenciaDeTokens))
        {
            return;
        }
    }

    throw new Excecao("Erro sintático!");
}

bool negocio::AnalisadorSintaticoPortugol::valideRegraComSequenciaDeTokens(vector<enumeradores::EnumToken> regra, vector<enumeradores::EnumToken> tokens)
{
    auto contador = 0;

    while ((contador < regra.size() &&
            contador < tokens.size()) &&
            regra[contador] == tokens[contador])
    {
        contador++;
    }

    return contador == regra.size() && contador == tokens.size();
}
