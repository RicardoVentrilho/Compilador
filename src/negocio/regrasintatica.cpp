#include "regrasintatica.h"

negocio::RegraSintatica::RegraSintatica(vector<EnumToken>* regra)
    : regraBasica(regra)
{
    ehParaAdicionarNaTabelaDeSimbolos = false;
}

void negocio::RegraSintatica::adicioneProximaRegra(RegraSintatica *regra)
{
    proximaRegra = regra;
}

void negocio::RegraSintatica::aoValidarTokenNomeVariavelAdicionarNaTabelaDeSimbolos()
{
    ehParaAdicionarNaTabelaDeSimbolos = true;
}

void negocio::RegraSintatica::valide(vector<TokenPortugol*> tokens, TabelaDeSimbolosPortugol *tabelaDeSimbolos)
{
    auto contador = 0;

    while ((contador < regraBasica->size() &&
            contador < tokens.size()) &&
            (*regraBasica)[contador] == tokens[contador]->getTipo())
    {
        auto token = tokens[contador];

        if(token->getTipo() == EnumToken::NOME_VARIAVEL && ehParaAdicionarNaTabelaDeSimbolos)
        {
            tabelaDeSimbolos->adicioneTokenId(token->getValor());
        }

        if(token->getTipo() == EnumToken::NOME_VARIAVEL)
        {
            ////Se token estiver na tabela de simbolos, se tornará a ser ID
            *token = tabelaDeSimbolos->getToken(token->getValor());
        }

        contador++;
    }

    if (contador == regraBasica->size())
    {
        auto inicio = tokens.begin() + contador;
        auto fim = tokens.end();

        tokens = vector<TokenPortugol*>(inicio, fim);

        proximaRegra->valide(tokens, tabelaDeSimbolos);

        return;
    }

    if (regraBasica->front() == EnumToken::FIM)
    {
        return;
    }

    auto mensagem = QString("Erro sintático: Esperado Id = %1").arg((*regraBasica)[contador]);

    throw new Excecao(mensagem.toStdString());
}
