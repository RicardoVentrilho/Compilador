#ifndef ANALISADORSEMANTICO_H
#define ANALISADORSEMANTICO_H

#include <vector>
#include <map>
#include "tokenportugol.h"
#include "infraestrutura/utilitarios/excecao.h"

using std::vector;
using std::map;
using infraestrutura::Excecao;

namespace negocio
{
class AnalisadorSintaticoPortugol
{
public:
    AnalisadorSintaticoPortugol();
    void valideSequenciaDeTokens(vector<TokenPortugol*> tokens);

private:
    bool valideRegraComSequenciaDeTokens(vector<EnumToken> regra, vector<EnumToken> tokens);
    vector<vector<EnumToken>> regras;
};
}

#endif // ANALISADORSEMANTICO_H
