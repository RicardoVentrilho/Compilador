#include "analisadorsintaticoportugol.h"

negocio::AnalisadorSintaticoPortugol::AnalisadorSintaticoPortugol(TabelaDeSimbolosPortugol *tabelaDeSimbolos)
    : tabelaDeSimbolos(tabelaDeSimbolos)
{
    regras =
    {
        { EnumToken::PALAVRA_RESERVADA },
        { EnumToken::VARIAVEL,EnumToken::NOME_VARIAVEL, EnumToken::OPERADOR_ATRIBUICAO, EnumToken::NUMERO },
        { EnumToken::VARIAVEL, EnumToken::OPERADOR_ATRIBUICAO, EnumToken::NUMERO },
        { EnumToken::VARIAVEL,EnumToken::NOME_VARIAVEL}
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
