#ifndef REGRASINTATICA_H
#define REGRASINTATICA_H

#include <vector>
#include "enumeradores/enumtoken.h"
#include "infraestrutura/utilitarios/excecao.h"
#include "tokenportugol.h"
#include "tabeladesimbolosportugol.h"

using enumeradores::EnumToken;
using std::vector;
using infraestrutura::Excecao;

namespace negocio
{
class RegraSintatica
{
public:
    RegraSintatica(vector<enumeradores::EnumToken> *regra);
    void adicioneProximaRegra(RegraSintatica* regra);
    void aoValidarTokenNomeVariavelAdicionarNaTabelaDeSimbolos();
    void valide(vector<TokenPortugol *> tokens, TabelaDeSimbolosPortugol* tabelaDeSimbolos);

private:
    vector<EnumToken> *regraBasica;
    bool ehParaAdicionarNaTabelaDeSimbolos;
    RegraSintatica* proximaRegra;
};
}

#endif // REGRASINTATICA_H
