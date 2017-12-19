#include "analisadorsintaticoportugol.h"

negocio::AnalisadorSintaticoPortugol::AnalisadorSintaticoPortugol(TabelaDeSimbolosPortugol *tabelaDeSimbolos)
    : tabelaDeSimbolos(tabelaDeSimbolos)
{
    regraInicial = new RegraSintatica(new vector<EnumToken>{ { EnumToken::PALAVRA_RESERVADA } });

    auto regra2 = new RegraSintatica(new vector<EnumToken>{ { EnumToken::VARIAVEL } });
    regraInicial->adicioneProximaRegra(regra2);

    auto regra3 = new RegraSintatica(new vector<EnumToken>{ { EnumToken::NOME_VARIAVEL, EnumToken::NOME_VARIAVEL, EnumToken::FINAL_DE_LINHA } });
    regra2->adicioneProximaRegra(regra3);
    regra3->aoValidarTokenNomeVariavelAdicionarNaTabelaDeSimbolos();

    auto regra4 = new RegraSintatica(new vector<EnumToken>{ { EnumToken::LEIA } });
    regra3->adicioneProximaRegra(regra4);

    auto regra5 = new RegraSintatica(new vector<EnumToken>{ { EnumToken::ID } });
    regra4->adicioneProximaRegra(regra5);

    auto regra6 = new RegraSintatica(new vector<EnumToken>{ { EnumToken::ESCREVA } });
    regra5->adicioneProximaRegra(regra6);

    auto regra7 = new RegraSintatica(new vector<EnumToken>{ { EnumToken::ABRE } });
    regra6->adicioneProximaRegra(regra7);

    auto regra8 = new RegraSintatica(new vector<EnumToken>{ { EnumToken::MENSAGEM } });
    regra7->adicioneProximaRegra(regra8);

    auto regra9 = new RegraSintatica(new vector<EnumToken>{ { EnumToken::FECHA } });
    regra8->adicioneProximaRegra(regra9);

    auto regra10 = new RegraSintatica(new vector<EnumToken>{ { EnumToken::AT } });
    regra9->adicioneProximaRegra(regra10);

    auto regra11 = new RegraSintatica(new vector<EnumToken>{ { EnumToken::ID } });
    regra10->adicioneProximaRegra(regra11);

    auto regra12 = new RegraSintatica(new vector<EnumToken>{ { EnumToken::OPERADOR_ATRIBUICAO } });
    regra11->adicioneProximaRegra(regra12);

    auto regra13 = new RegraSintatica(new vector<EnumToken>{ { EnumToken::NUMERO } }); // OU ID -> PENDENTE
    regra12->adicioneProximaRegra(regra13);

//    auto regra14 = new RegraSintatica(new vector<EnumToken>{ { EnumToken::ID } });
//    regra13->adicioneProximaRegra(regra14);

    regraFinal = new RegraSintatica(new vector<EnumToken>{ { EnumToken::FIM } });
    regra13->adicioneProximaRegra(regraFinal);
}

void negocio::AnalisadorSintaticoPortugol::valide(vector<negocio::TokenPortugol *> tokens)
{
    vector<EnumToken> sequenciaDeTokens;

    for (auto token : tokens)
    {
        sequenciaDeTokens.push_back(token->getTipo());
    }

    regraInicial->valide(tokens, tabelaDeSimbolos);
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
