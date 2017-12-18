#ifndef TRADUTORPORTUGOLPARAC_H
#define TRADUTORPORTUGOLPARAC_H

#include <vector>
#include <iostream>
#include "tokenportugol.h"

using std::vector;
using std::cout;
using std::endl;

namespace negocio
{
class TradutorPortugolParaC
{
public:
    TradutorPortugolParaC();
    void adicioneTokens(vector<TokenPortugol*> tokens);
    void adicioneTokenFinalDeLinha();
    void imprima();

private:
    vector<TokenPortugol*> tokens;
};
}

#endif // TRADUTORPORTUGOLPARAC_H
