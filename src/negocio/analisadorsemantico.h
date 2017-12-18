#ifndef ANALISADORSEMANTICO_H
#define ANALISADORSEMANTICO_H

#include <vector>
#include "token.h"

using std::vector;

namespace negocio
{
class AnalisadorSemantico
{
public:
    AnalisadorSemantico();
    void valideSequenciaDeTokens(vector<Token*> tokens);
};
}

#endif // ANALISADORSEMANTICO_H
