#ifndef TRADUTORPORTUGOLPARAC_H
#define TRADUTORPORTUGOLPARAC_H

#include <vector>
#include <map>
#include <iostream>
#include "tokenportugol.h"
#include "infraestrutura/utilitarios/excecao.h"

using std::vector;
using std::cout;
using std::endl;
using std::map;
using infraestrutura::Excecao;

namespace negocio
{
class TradutorPortugolParaC
{
public:
    TradutorPortugolParaC();
    void adicioneTokens(vector<TokenPortugol*> tokens);
    void adicioneTokenFinalDeLinha();
    void traduza();
    void imprima();

private:
    QString monteEstruturaEmC(TokenPortugol* token, QString algoritmo);

    vector<TokenPortugol*>* tokens;
    QString tokensTraduzido;
};
}

#endif // TRADUTORPORTUGOLPARAC_H
