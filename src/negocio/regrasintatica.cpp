#include "regrasintatica.h"

negocio::RegraSintatica::RegraSintatica(vector<EnumToken>* regra)
    : regraBasica(regra)
{
}

void negocio::RegraSintatica::adicioneProximaRegra(RegraSintatica *regra)
{
    proximaRegra = regra;
}

void negocio::RegraSintatica::valide(vector<TokenPortugol*> tokens)
{
    auto contador = 0;

    while ((contador < regraBasica->size() &&
            contador < tokens.size()) &&
            (*regraBasica)[contador] == tokens[contador]->getTipo())
    {
        contador++;
    }

    if (contador == regraBasica->size())
    {
        auto inicio = tokens.begin() + contador;
        auto fim = tokens.end();

        tokens = vector<TokenPortugol*>(inicio, fim);

        proximaRegra->valide(tokens);

        return;
    }

    if (regraBasica->front() == EnumToken::FIM)
    {
        return;
    }

    throw new Excecao("Erro sintático!");
}
