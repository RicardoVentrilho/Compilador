#ifndef ANALISADORLEXICO_H
#define ANALISADORLEXICO_H

#include <vector>
#include <QString>
#include <QRegExp>
#include <QStringList>
#include "tokenportugol.h"
#include "tabeladesimbolosportugol.h"

using std::vector;

namespace negocio
{
class AnalisadorLexicoPortugol
{
public:
    AnalisadorLexicoPortugol(TabelaDeSimbolosPortugol* tabelaDeSimbolos);
    vector<TokenPortugol *> crieTokens(QString linha);

private:
    TabelaDeSimbolosPortugol* tabelaDeSimbolos;
};
}

#endif // ANALISADORLEXICO_H
