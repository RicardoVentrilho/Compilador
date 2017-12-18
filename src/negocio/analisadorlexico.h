#ifndef ANALISADORLEXICO_H
#define ANALISADORLEXICO_H

#include <vector>
#include <QString>
#include <QRegExp>
#include <QStringList>
#include "token.h"
#include "tabeladesimbolos.h"

using std::vector;

namespace negocio
{
class AnalisadorLexico
{
public:
    AnalisadorLexico(TabelaDeSimbolos* tabelaDeSimbolos);
    vector<Token *> crieTokens(QString linha);

private:
    TabelaDeSimbolos* tabelaDeSimbolos;
};
}

#endif // ANALISADORLEXICO_H
