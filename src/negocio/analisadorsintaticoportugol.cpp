#include "analisadorsintaticoportugol.h"

negocio::AnalisadorSintaticoPortugol::AnalisadorSintaticoPortugol(TabelaDeSimbolosPortugol *tabelaDeSimbolos)
    : tabelaDeSimbolos(tabelaDeSimbolos)
{
    regraInicial = new RegraSintatica(new vector<EnumToken>{ { EnumToken::PALAVRA_RESERVADA } });
    auto regra2 = new RegraSintatica(new vector<EnumToken>{ { EnumToken::VARIAVEL } });
    auto regra3 = new RegraSintatica(new vector<EnumToken>{ { EnumToken::NOME_VARIAVEL, EnumToken::OPERADOR_ATRIBUICAO, EnumToken::NUMERO } });

//    regras =
//    {
//        { EnumToken::PALAVRA_RESERVADA },
//        { EnumToken::VARIAVEL,EnumToken::NOME_VARIAVEL},
//        { EnumToken::VARIAVEL,EnumToken::NOME_VARIAVEL, EnumToken::OPERADOR_ATRIBUICAO, EnumToken::NUMERO },
//        { EnumToken::VARIAVEL,EnumToken::NOME_VARIAVEL, EnumToken::OPERADOR_SEPARADOR, EnumToken::NOME_VARIAVEL },
//        { EnumToken::LEIA,EnumToken::NOME_VARIAVEL},
//        { EnumToken::ESCREVA,EnumToken::ABRE,EnumToken::MENSAGEM,EnumToken::FECHA},
//        { EnumToken::AT, EnumToken::NOME_VARIAVEL, EnumToken::OPERADOR_ATRIBUICAO, EnumToken::NOME_VARIAVEL},
//        { EnumToken::AT, EnumToken::NOME_VARIAVEL, EnumToken::OPERADOR_ATRIBUICAO, EnumToken::NOME_VARIAVEL, EnumToken::OPERADOR_ARITMETICO_SOMA},
//        { EnumToken::AT, EnumToken::NOME_VARIAVEL, EnumToken::OPERADOR_ATRIBUICAO, EnumToken::NOME_VARIAVEL},
//        { EnumToken::OPERADOR_LOGICO_SE,EnumToken::VARIAVEL,EnumToken::OPERADOR_RELACIONAL_MAIOR,EnumToken::VARIAVEL,EnumToken::OPERADOR_LOGICO_ENTAO},
//        { EnumToken::OPERADOR_LOGICO_SE,EnumToken::VARIAVEL,EnumToken::OPERADOR_RELACIONAL_MAIOR_IGUAL,EnumToken::VARIAVEL,EnumToken::OPERADOR_LOGICO_ENTAO},
//        { EnumToken::OPERADOR_LOGICO_SE,EnumToken::VARIAVEL,EnumToken::OPERADOR_RELACIONAL_MENOR,EnumToken::VARIAVEL,EnumToken::OPERADOR_LOGICO_ENTAO},
//        { EnumToken::OPERADOR_LOGICO_SE,EnumToken::VARIAVEL,EnumToken::OPERADOR_RELACIONAL_MENOR_IGUAL,EnumToken::VARIAVEL,EnumToken::OPERADOR_LOGICO_ENTAO},
//        { EnumToken::OPERADOR_LOGICO_SE,EnumToken::VARIAVEL,EnumToken::OPERADOR_RELACIONAL_DIFERENTE,EnumToken::VARIAVEL,EnumToken::OPERADOR_LOGICO_ENTAO},
//        { EnumToken::OPERADOR_LOGICO_SENAO},
//    };

    regraFinal = new RegraSintatica(new vector<EnumToken>{ { EnumToken::FIM } });

    regraInicial->adicioneProximaRegra(regra2);
    regra2->adicioneProximaRegra(regra3);
    regra3->adicioneProximaRegra(regraFinal);

}

void negocio::AnalisadorSintaticoPortugol::valide(vector<negocio::TokenPortugol *> tokens)
{
    vector<EnumToken> sequenciaDeTokens;

    for (auto token : tokens)
    {
        sequenciaDeTokens.push_back(token->getTipo());
    }

    regraInicial->valide(tokens);
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
