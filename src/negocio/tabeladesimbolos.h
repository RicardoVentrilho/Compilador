#ifndef TABELADESIMBOLOS_H
#define TABELADESIMBOLOS_H

#include <map>
#include <QString>
#include "enumeradores/enumtoken.h"

using enumeradores::EnumToken;
using std::map;

namespace negocio
{
class TabelaDeSimbolos
{
public:
    TabelaDeSimbolos();
    EnumToken getTipo(QString palavra);

private:
    map<QString, EnumToken> dicionario;
};
}

#endif // TABELADESIMBOLOS_H
