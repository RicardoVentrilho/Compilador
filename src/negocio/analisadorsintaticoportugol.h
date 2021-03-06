#ifndef ANALISADORSEMANTICO_H
#define ANALISADORSEMANTICO_H

#include <vector>
#include <map>
#include "tabeladesimbolosportugol.h"
#include "tokenportugol.h"
#include "regrasintatica.h"
#include "infraestrutura/utilitarios/excecao.h"


using std::vector;
using std::map;
using infraestrutura::Excecao;

namespace negocio
{
class AnalisadorSintaticoPortugol
{
public:
    AnalisadorSintaticoPortugol(TabelaDeSimbolosPortugol* tabelaDeSimbolos);
    void valide(vector<TokenPortugol*> tokens);

private:
    bool valideRegraComSequenciaDeTokens(vector<EnumToken> regra, vector<EnumToken> tokens);
    RegraSintatica* regraInicial;
    RegraSintatica* regraFinal;
    TabelaDeSimbolosPortugol* tabelaDeSimbolos;
};
}

#endif // ANALISADORSEMANTICO_H
