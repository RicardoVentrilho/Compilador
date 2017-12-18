#include "analisadorsintaticoportugol.h"

negocio::AnalisadorSintaticoPortugol::AnalisadorSintaticoPortugol()
{
    regras =
    {
        { EnumToken::VARIAVEL, EnumToken::OPERADOR_ATRIBUICAO, EnumToken::NUMERO }
    };
}

void negocio::AnalisadorSintaticoPortugol::valideSequenciaDeTokens(vector<negocio::TokenPortugol *> tokens)
{
    vector<EnumToken> sequenciaDeTokens;

    for (auto token : tokens)
    {
        sequenciaDeTokens.push_back(token->getTipo());
    }

    for (auto regra : regras)
    {
        ////Validar token a token
        if (regra == sequenciaDeTokens)
        {
            return;
        }
    }

    throw new Excecao("Erro sintático!");
}

bool negocio::AnalisadorSintaticoPortugol::valideRegraComSequenciaDeTokens(vector<enumeradores::EnumToken> regra, vector<enumeradores::EnumToken> tokens)
{
    return false;
}
