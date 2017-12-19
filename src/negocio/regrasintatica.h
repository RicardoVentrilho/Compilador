#ifndef REGRASINTATICA_H
#define REGRASINTATICA_H

#include <vector>
#include "enumeradores/enumtoken.h"
#include "infraestrutura/utilitarios/excecao.h"
#include "tokenportugol.h"

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
    void valide(vector<TokenPortugol *> tokens);

private:
    vector<EnumToken> *regraBasica;
    RegraSintatica* proximaRegra;
};
}

#endif // REGRASINTATICA_H
