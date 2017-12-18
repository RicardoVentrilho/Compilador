#ifndef ANALISADORSEMANTICO_H
#define ANALISADORSEMANTICO_H

#include <vector>
#include "tokenportugol.h"

using std::vector;

namespace negocio
{
class AnalisadorSintaticoPortugol
{
public:
    AnalisadorSintaticoPortugol();
    void valideSequenciaDeTokens(vector<TokenPortugol*> tokens);
};
}

#endif // ANALISADORSEMANTICO_H
